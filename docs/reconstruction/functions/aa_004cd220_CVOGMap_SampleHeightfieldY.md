# Function record: CVOGMap_SampleHeightfieldY

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cd220` |
| **Canonical name** | `CVOGMap_SampleHeightfieldY` (**Probable**) |
| **Ghidra / scaffold** | `FUN_004cd220` |
| **Address** | `0x004cd220` |
| **Body span** | `004cd220` – `004cd237` (24 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `world-terrain` (DriveControlTick consumer under `input-drive-control`) |
| **Completion status** | **Partial** — three-rep + dual A/B sealed 2026-07-29; product name Probable; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual reviews** | `reviews/A_aa_004cd220_CVOGMap_SampleHeightfieldY.md`, `reviews/B_aa_004cd220_CVOGMap_SampleHeightfieldY.md` |

## Alias

- Scaffold: `FUN_004cd220`
- Parent-seed: `Named_CalleeOf_Client_Input_DriveControlTick_004cd220` (one of many callers; **not** exclusive)

## Purpose

Shared **CVOGMap** heightfield **Y** sample: if `map+0xe4e0` (heightfield*) is non-null, tail-call `FUN_005a58c0(hf, x, z)`; else return **0.0f**. Pure HF query — **no** collision cast (contrast `CVOGMap_CastTerrainHeight` @ `0x004cfe60`).

## Signature (body + callers; decompiler incomplete)

```c
/* MSVC __thiscall: this in ECX; float x, float z on stack; RET 8; result in ST0 */
float10 __thiscall CVOGMap_SampleHeightfieldY(int *map, float worldX, float worldZ);
```

Decompiler may show `__fastcall (int)` with zero-arg `FUN_005a58c0()` because of the **tail JMP** — **body bytes win**.

## Body (authoritative)

```
mov  ecx, [ecx+0xe4e0]     ; hf = map->heightfield
test ecx, ecx
jz   return_zero
jmp  FUN_005a58c0          ; this = hf; (x,z) stack preserved
fld  [g_flZero]            ; 0x00a0f518 = 0.0f
ret  8
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004cd220_FUN_004cd220.md`
- Annotated: `docs/reconstruction/raw/aa_004cd220_FUN_004cd220.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGMap_SampleHeightfieldY.cpp`
- Named alias clean: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_Input_DriveControlTick_004cd220.cpp`
- Prior scaffold record: `docs/reconstruction/functions/aa_004cd220_FUN_004cd220.md` (superseded by this file)

## Callers / callees

| Direction | Symbol / VA | Notes |
|---|---|---|
| Callee | `FUN_005a58c0` @ `0x005a58c0` | Heightfield sample (this = HF); scale/clamp/bilinear |
| Caller | `Client_Input_DriveControlTick` @ `0x009223b0` | Call site ~`0x009236d2` — camera/look ground Y |
| Caller | `CVOGCreature_FindTerrainHeight` @ `0x004c6100` | Initial HF sample before optional cast/ray |
| Caller | `Vehicle_ActivateEnterWorld` @ `0x00503f30` | Spawn / enter-world ground |
| Callers | ~30+ other FUN_* (AI, gfx, UI, physics helpers) | Shared map API; 57 xrefs |

## Layout

| Object | Offset | Role |
|---|---:|---|
| CVOGMap | `+0xe4e0` | Heightfield object* |
| Global | `0x00a0f518` (`g_flZero`) | 0.0f null-HF return |

## Confidence

| Claim | Level |
|---|---|
| Control flow + body bytes | **High** |
| ABI thiscall + (x,z) + RET 8 | **High** |
| `+0xe4e0` heightfield gate | **High** |
| Role = pure HF Y sample | **High** |
| Canonical product name | **Probable** |
| `FUN_005a58c0` product name / full dual | **Open** (out of OWN scope) |
| Runtime / differential | **Open** |
