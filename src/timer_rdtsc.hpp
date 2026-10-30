#pragma once

#include <cstdint>
#include <x86intrin.h>

namespace bench {
inline std::uint64_t rdtsc_begin() noexcept
{
	_mm_lfence();
	return __rdtsc();
}


inline std::uint64_t rdtsc_end() noexcept
{
	unsigned aux;
	const std::uint64_t t = __rdtscp(&aux);
	_mm_lfence();
	return t;
}
	
}
