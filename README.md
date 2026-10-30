# AoS VS SoA with benchmarking

* **AoS** — `struct ParticleAoS { float x, y, z, mass; }`
* **SoA** — `struct ParticlesSoA { vector<float> x, y, z, mass; }`


## building

```bash
cmake -S . --fresh -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j
./build/aos_vs_soa
```

## Results

```
Test 1:
N = 10000000, repeats = 20, warmup = 3

==============================================================
AoS full                 total     1315212499 cyc | avg       65760625 cyc | 6.576 cyc/elem.
SoA full                 total     1084593704 cyc | avg       54229685 cyc | 5.423 cyc/elem.
Boost SoA/AoS: 1.21x

==============================================================
AoS x-only               total      937791584 cyc | avg       46889579 cyc | 4.689 cyc/elem.
SoA x-only               total      748509880 cyc | avg       37425494 cyc | 3.743 cyc/elem.
Boost SoA/AoS: 1.25x


Test 2:
N = 10000000, repeats = 20, warmup = 3

==============================================================
AoS full                 total     1309919070 cyc | avg       65495954 cyc | 6.550 cyc/elem.
SoA full                 total     1157564839 cyc | avg       57878242 cyc | 5.788 cyc/elem.
Boost SoA/AoS: 1.13x

==============================================================
AoS x-only               total      966222076 cyc | avg       48311104 cyc | 4.831 cyc/elem.
SoA x-only               total      751535749 cyc | avg       37576787 cyc | 3.758 cyc/elem.
Boost SoA/AoS: 1.29x


Test 3:
N = 10000000, repeats = 20, warmup = 3

==============================================================
AoS full                 total     1302095974 cyc | avg       65104799 cyc | 6.510 cyc/elem.
SoA full                 total     1093774344 cyc | avg       54688717 cyc | 5.469 cyc/elem.
Boost SoA/AoS: 1.19x

==============================================================
AoS x-only               total      942982824 cyc | avg       47149141 cyc | 4.715 cyc/elem.
SoA x-only               total      753389038 cyc | avg       37669452 cyc | 3.767 cyc/elem.
Boost SoA/AoS: 1.25x


Test 4:
N = 10000000, repeats = 20, warmup = 3

==============================================================
AoS full                 total     1276722272 cyc | avg       63836114 cyc | 6.384 cyc/elem.
SoA full                 total     1109708564 cyc | avg       55485428 cyc | 5.549 cyc/elem.
Boost SoA/AoS: 1.15x

==============================================================
AoS x-only               total      954975576 cyc | avg       47748779 cyc | 4.775 cyc/elem.
SoA x-only               total      759961714 cyc | avg       37998086 cyc | 3.800 cyc/elem.
Boost SoA/AoS: 1.26x


Test 5:
N = 10000000, repeats = 20, warmup = 3

==============================================================
AoS full                 total     1312621110 cyc | avg       65631056 cyc | 6.563 cyc/elem.
SoA full                 total     1089729564 cyc | avg       54486478 cyc | 5.449 cyc/elem.
Boost SoA/AoS: 1.20x

==============================================================
AoS x-only               total      984857966 cyc | avg       49242898 cyc | 4.924 cyc/elem.
SoA x-only               total      761021958 cyc | avg       38051098 cyc | 3.805 cyc/elem.
Boost SoA/AoS: 1.29x
```

## WTF? Need to fix it
