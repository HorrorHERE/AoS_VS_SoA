#include "bench_rules.hpp"
#include <random>

namespace bench {

float sum_aos(const std::vector<StructsForTest::ParticleAoS>& p) {
    float s = 0.f;
    for (const auto& q : p) {
        s += q.x + q.y + q.z + q.vx + q.vy + q.vz;
    }
    return s;
}

float sum_soa(const StructsForTest::ParticlesSoA& p) {
    float sx = 0.f, sy = 0.f, sz = 0.f, svx = 0.f, svy = 0.f, svz = 0.f;
    const std::size_t n = p.size();
    for (std::size_t i = 0; i < n; ++i) {
        sx += p.x[i];
        sy += p.y[i];
        sz += p.z[i];
        svx += p.vx[i];
        svy += p.vy[i];
        svz += p.vz[i];
    }
    return (sx + sy +sz) + (svx + svy + svz);
}

float sum_aos_x_only(const std::vector<StructsForTest::ParticleAoS>& p) {
    float s = 0.f;
    for (const auto& q : p) s += q.x;
    return s;
}

float sum_soa_x_only(const StructsForTest::ParticlesSoA& p) {
    float s = 0.f;
    const std::size_t n = p.size();
    for (std::size_t i = 0; i < n; ++i) s += p.x[i];
    return s;
}

void fill(std::vector<StructsForTest::ParticleAoS>& aos, StructsForTest::ParticlesSoA& soa, unsigned seed) {
    std::mt19937 rng(seed);
    std::uniform_real_distribution<float> dist(0.f, 1.f);

    const std::size_t n = aos.size();
    for (std::size_t i = 0; i < n; ++i) {
        const float x = dist(rng);
        const float y = dist(rng);
        const float z = dist(rng);
        const float vx = dist(rng);
        const float vy = dist(rng);
        const float vz = dist(rng);

        aos[i] = {x, y, z, vx, vy, vz};
        soa.x[i] = x;
        soa.y[i] = y;
        soa.z[i] = z;
        soa.vx[i] = vx;
        soa.vy[i] = vy;
        soa.vz[i] = vz;
    }
}

}
