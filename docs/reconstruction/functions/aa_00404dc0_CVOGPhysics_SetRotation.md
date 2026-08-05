# Function record: CVOGPhysics_SetRotation

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404dc0` |
| **Canonical name** | `CVOGPhysics_SetRotation` (inferred) |
| **Ghidra symbol** | `FUN_00404dc0` |
| **Address** | `0x00404dc0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `physics` |
| **Completion status** | **partial** — dual A/B accept-with-gaps 2026-07-29; CF + dual gates + vtbl+0x44 sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_00404dc0`
- Prior scaffold: `Named_CalleeOf_Named_VOG_DEBUG_STOP_00404dc0` (discard; not role-accurate)
- Sibling: `FUN_0040d2a0` setPosition (vtbl+0x40, same gates)

## Purpose

Optional readiness prepare, then forward a rotation pointer to the bound rigid body via **body vtbl +0x44**, **only when physics is not fully ready** (`phys+0x40==0` OR `phys+0x08==0`). When fully ready, the function is a no-op after the optional prepare stage.

## Signature (decompiler-derived)

```c
void __thiscall CVOGPhysics_SetRotation(int phys /* ECX */, undefined4 rotPtr /* stack */);
// ret 4 (thiscall)
```

## Layout (this = CVOGPhysics)

| Off | Use |
|---:|---|
| `+0x08` | Nonzero contributes to “fully ready” (with `+0x40`) |
| `+0x3c` | Rigid body pointer (vtbl consumer) |
| `+0x40` | Byte; nonzero contributes to “fully ready” |
| `+0x44` | Ready-object pointer; `+0x29` flag via `FUN_005070b0` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00404dc0_FUN_00404dc0.md`
- Annotated: `docs/reconstruction/raw/aa_00404dc0_FUN_00404dc0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGPhysics_SetRotation.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00404dc0_CVOGPhysics_SetRotation.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00404dc0_CVOGPhysics_SetRotation.md`
- Prior scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00404dc0.cpp`
- Prior scaffold record: `docs/reconstruction/functions/aa_00404dc0_FUN_00404dc0.md`

## Callers / callees

**Callees:** `FUN_005070b0`, `FUN_005070d0`, body vtbl `+0x44`.

**Callers (live xrefs, 11 sites):** `FUN_0053eec0` (network soft), `VehicleAction_airStabilization`, `FUN_0091a5f0` (camera look), `ClientSpecialEvent_Respawn_Update`, `FUN_00917700`, `FUN_004c3d60`, `FUN_005911b0`, `FUN_005d0d60`, `FUN_005cd3b0`, `FUN_00812360`, site `0x009587d8`.

## Confidence

| Claim | Level |
|---|---|
| Control flow + dual gates + vtbl+0x44 | **High** |
| Semantic setRotation | **High** (behavioral) / **Probable** (Havok English) |
| Parameter type names | **Probable** / **Tentative** until type pass |
| Runtime / bit-exact | Open |
