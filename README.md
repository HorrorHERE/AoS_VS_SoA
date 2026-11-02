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
N = 10000000, repeats = 100, warmup = 3

==============================================================
AoS full total 62805006 cyc | avg 628050 cyc | 0.063 cyc/elem.
SoA full total 40442382 cyc | avg 404424 cyc | 0.040 cyc/elem.
Boost SoA/AoS: 1.55x

==============================================================
AoS x-only total 43938592 cyc | avg 439386 cyc | 0.044 cyc/elem.
SoA x-only total 7256468 cyc | avg 72565 cyc | 0.007 cyc/elem.
Boost SoA/AoS: 6.06x


Test 2:
N = 10000000, repeats = 100, warmup = 3

==============================================================
AoS full total 63510569 cyc | avg 635106 cyc | 0.064 cyc/elem.
SoA full total 41011104 cyc | avg 410111 cyc | 0.041 cyc/elem.
Boost SoA/AoS: 1.55x

==============================================================
AoS x-only total 44329522 cyc | avg 443295 cyc | 0.044 cyc/elem.
SoA x-only total 7056570 cyc | avg 70566 cyc | 0.007 cyc/elem.
Boost SoA/AoS: 6.28x


Test 3:
N = 10000000, repeats = 100, warmup = 3

==============================================================
AoS full total 63138738 cyc | avg 631387 cyc | 0.063 cyc/elem.
SoA full total 40911000 cyc | avg 409110 cyc | 0.041 cyc/elem.
Boost SoA/AoS: 1.54x

==============================================================
AoS x-only total 44121798 cyc | avg 441218 cyc | 0.044 cyc/elem.
SoA x-only total 7192306 cyc | avg 71923 cyc | 0.007 cyc/elem.
Boost SoA/AoS: 6.13x

```

## Results

###Speed
x-only: velocity SoA > velocity AoS  
full: velocity SoA = velocity AoS

###Effective:
x-only:
AoS: 24 byte read, 4 byte use => 16.7%
SoA: 4 byte read, 4 byte use => 100%


full:
AoS: 24 byte read, 24 byte use => 100%
SoA: 6 × 4 = 24 byte read, 24 byte use => 100%




