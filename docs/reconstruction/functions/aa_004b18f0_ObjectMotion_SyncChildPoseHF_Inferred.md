# Function record: ObjectMotion_SyncChildPoseHF_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b18f0` |
| **Canonical name** | `ObjectMotion_SyncChildPoseHF_Inferred` |
| **Ghidra name** | `FUN_004b18f0` |
| **Address** | `0x004b18f0`–`0x004b1a56` (**358 B / `0x166`**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client object motion / reaction slot child pose |
| **Completion status** | **Dual-sealed 2026-07-29 W27-F** — raw append + annotated + clean + A/B |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Post-integrate optional child world-pose sync: when flag ≠ 0, copy transform fields slot→child (`*(slot+8)`), run matrix helpers, heightfield-snap/slope-scale XYZ, add ≈0.04 to Y.

## Signature (sealed)

```c
// thiscall; RET 4
void ObjectMotion_SyncChildPoseHF_Inferred(int slot, int flag);
```

## Control flow

See `aa_004b18f0_FUN_004b18f0.md` (same seal). Gate → matrix helpers → copy dwords → HF sample → basis scale → add slot pos → Y+=0.04.

## Callers / callees

| Dir | Symbol | Notes |
|---|---|---|
| Caller | `ObjectMotion_SlotTick_Inferred` | after `FUN_004b1100` when `slot[2]` |
| Caller | `FUN_005bc120` | emitter/reaction spawn path |
| Callee | `FUN_004cd220` | `CVOGMap_SampleHeightfieldY` |
| Callee | `FUN_00973820` / `FUN_00973690` / `FUN_006a3db0` | nested (OPEN English) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004b18f0_FUN_004b18f0.md`
- Annotated: `docs/reconstruction/raw/aa_004b18f0_FUN_004b18f0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/ObjectMotion_SyncChildPoseHF_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004b18f0.cpp`
- Function twin: `docs/reconstruction/functions/aa_004b18f0_FUN_004b18f0.md`
- Reviews: A/B `ObjectMotion_SyncChildPoseHF_Inferred`

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / constants 0.75 / ≈0.04 | **High** |
| Nested helper product names | **Open** |
| Runtime | **Open** |
