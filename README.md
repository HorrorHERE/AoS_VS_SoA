# AoS VS SoA with benchmarking

* **AoS** — `struct ParticleAoS { float x, y, z, mass; }`
* **SoA** — `struct ParticlesSoA { vector<float> x, y, z, mass; }`


## building

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j
./build/bench
```
