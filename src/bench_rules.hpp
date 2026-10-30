#pragma once
#include "structures.hpp"
#include <vector>

#if defined(__GNUC__) || defined(__clang__)
#  define BENCH_NOINLINE __attribute__((noinline))
#elif defined(_MSC_VER)
#  define BENCH_NOINLINE __declspec(noinline)
#else
#  define BENCH_NOINLINE
#endif

namespace bench {

BENCH_NOINLINE float sum_aos(const std::vector<StructsForTest::ParticleAoS>& p);
BENCH_NOINLINE float sum_soa(const StructsForTest::ParticlesSoA& p);

BENCH_NOINLINE float sum_aos_x_only(const std::vector<StructsForTest::ParticleAoS>& p);
BENCH_NOINLINE float sum_soa_x_only(const StructsForTest::ParticlesSoA& p);

void fill(std::vector<StructsForTest::ParticleAoS>& aos, StructsForTest::ParticlesSoA& soa, unsigned seed);

}
