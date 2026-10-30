#pragma once
#include <vector>
#include <cstddef>

namespace StructsForTest {

struct ParticlesAoS
{
	float x, y, z;
	float vx, xy, xz;
}

struct ParticlesSoA
{
	std::vector<float> x, y, z, vx, vy, vz;

	explicit ParticlesSoA(std::size_t m)
	: x(n), y(n), z(n), vx(n), vy(n), vz(n) {}

	std::size_t size() const noexcept { return x.size(); }
}


}