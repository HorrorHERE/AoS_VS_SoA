#include "bench_rules.hpp"
#include "timer_rdtsc.hpp"
#include <cstdio>
#include <cstdint>
#include <vector>

namespace {
template <typename Fn>
std::uint64_t time_cycles(Fn&& fn, volatile float* sink, int repeats) {
    std::uint64_t total = 0;
    for (int r = 0; r < repeats; ++r) {
        const std::uint64_t t0 = bench::rdtsc_begin();
        const float result = fn();
        const std::uint64_t t1 = bench::rdtsc_end();
        *sink = result;
        total += t1 - t0;
    }
    return total;
}

void report(const char* label, std::uint64_t cycles, int repeats, std::size_t n)
{
    const double avg = double(cycles) / repeats;
    std::printf("%-24s total %14llu cyc | avg %14.0f cyc | %.3f cyc/elem.\n", label, static_cast<unsigned long long>(cycles), avg, avg / double(n));
}

}

int main() {
    constexpr std::size_t N = 10'000'000;
    constexpr int REPEATS = 20;
    constexpr int WARMUP = 3;

    std::printf("N = %zu, repeats = %d, warmup = %d\n\n", N, REPEATS, WARMUP);

    std::vector<StructsForTest::ParticleAoS> aos(N);
    StructsForTest::ParticlesSoA soa(N);
    bench::fill(aos, soa, /*seed=*/42);

    volatile float sink = 0.f;
    for (int i = 0; i < WARMUP; ++i) {
        sink = bench::sum_aos(aos);
        sink = bench::sum_soa(soa);
        sink = bench::sum_aos_x_only(aos);
        sink = bench::sum_soa_x_only(soa);
    }

    std::printf("==============================================================\n");
    const auto aos_full = time_cycles([&]{ return bench::sum_aos(aos); }, &sink, REPEATS);
    const auto soa_full = time_cycles([&]{ return bench::sum_soa(soa); }, &sink, REPEATS);
    report("AoS full", aos_full, REPEATS, N);
    report("SoA full", soa_full, REPEATS, N);
    std::printf("Boost SoA/AoS: %.2fx\n\n", double(aos_full) / double(soa_full));

    std::printf("==============================================================\n");
    const auto aos_x = time_cycles([&]{ return bench::sum_aos_x_only(aos); }, &sink, REPEATS);
    const auto soa_x = time_cycles([&]{ return bench::sum_soa_x_only(soa); }, &sink, REPEATS);
    report("AoS x-only", aos_x, REPEATS, N);
    report("SoA x-only", soa_x, REPEATS, N);
    std::printf("Boost SoA/AoS: %.2fx\n", double(aos_x) / double(soa_x));

    return 0;
}