# Function record: Heightfield_SampleY

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a58c0` |
| **Canonical name** | `Heightfield_SampleY` (**Probable**) |
| **Address** | `0x005a58c0` |
| **Body span** | `005a58c0` – `005a5956` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `world-terrain` |
| **Completion status** | **Dual A/B present** — accept-with-gaps (2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_005a58c0`
- Legacy scaffold: `Named_CalleeOf_CVOGMap_CastTerrainHeight_005a58c0`
- Role: heightfield bilinear sample Y (scale XZ → clamp cell → bilinear → ÷ height scale)

## Purpose

Pure heightfield **Y** sample at world **(X, Z)**. `this` = heightfield object (loaded from `CVOGMap+0xe4e0` by callers/gates). Not map null-gate, not collision cast, not wheel ray.

## Signature (body-sealed)

```c
float10 __thiscall Heightfield_SampleY(Heightfield *hf, float worldX, float worldZ);
// RET 8; return ST0
```

## Algorithm

1. `gx = *(hf+0x30) * worldX`; `gz = *(hf+0x38) * worldZ`
2. `cellX = clamp(trunc_toward_zero(gx), 0, *(int*)(hf+0x0C)-2)` (same for Z at `+0x10`)
3. `raw = FUN_005a5810(hf, cellX, cellZ, gx-cellX, gz-cellZ)`
4. `return raw / *(float*)(hf+0x34)`

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005a58c0_FUN_005a58c0.md`
- Annotated: `docs/reconstruction/raw/aa_005a58c0_FUN_005a58c0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Heightfield_SampleY.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_005a58c0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_005a58c0_Heightfield_SampleY.md`
- Dual B: `docs/reconstruction/reviews/B_aa_005a58c0_Heightfield_SampleY.md`

## Callers / callees

| Direction | Symbol | VA / notes |
|---|---|---|
| Callee | `FUN_005a5810` | `0x005a5810` bilinear (product dual open) |
| Caller | `CVOGMap_SampleHeightfieldY` | `0x004cd220` tail JMP |
| Caller | `CVOGMap_CastTerrainHeight` | `0x004cfe60` |
| Caller | MarchDir / terrain helpers | `FUN_004cff70`, `FUN_004a8fb0`, `FUN_004ac660`, `FUN_004cf560`, `FUN_004d0ed0`, `FUN_004d10d0`, `FUN_004d1280`, `FUN_004d1680`, `FUN_004d2440`, `FUN_004d2c60`, `FUN_004d9f00`, `FUN_0061e410` |

## Confidence

| Claim | Level |
|---|---|
| Control flow + ABI from decompile + body | **High** |
| HF layout offsets used by this unit | **High** |
| Parameter semantic names (world X/Z, scales) | **High** / **Probable** for product field names |
| Product C++ name | **Probable / open** |
| Callee bilinear bit-exact | **Out of scope** (structure only) |
