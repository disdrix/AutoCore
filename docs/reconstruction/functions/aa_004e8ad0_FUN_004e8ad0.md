# Function record: Quat_ExtractRight_Inferred (`FUN_004e8ad0`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e8ad0` |
| **Canonical name** | `Quat_ExtractRight_Inferred` |
| **Ghidra name** | `FUN_004e8ad0` |
| **Address** | `0x004e8ad0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `physics` / shared math leaf (`input-drive-control` consumers) |
| **Completion status** | **Partial** — raw/annotated/clean + dual A/B sealed 2026-07-29; product name / runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_004e8ad0`
- Prior parent-seed: `Named_CalleeOf_CVOGHBAICreatureBase_DecideHeading_004e8ad0` (not exclusive — 22 xrefs)
- Role: unit quat XYZW → world **right (+X)** axis (rotation-matrix column 0)

## Purpose

Leaf helper: convert chassis/orientation quaternion to local **+X right** direction vector (homogeneous `float4` with W=0). Used for lateral dots (MoveToTarget steer), camera look frame, AI heading, turret aim, and other basis consumers.

Siblings (same family, **not** this unit):

| VA | Role |
|---|---|
| `0x004e8a40` | forward (+Z) |
| `0x004e8b60` | up (+Y) |

## Signature (decompiler-derived)

```c
// cdecl / stack args — not thiscall
// quat: float[4] XYZW; out: float[4] XYZ + W=0
void Quat_ExtractRight_Inferred(float *quat, float *outRight);
```

### Formula

```
out.x = 1 - 2*(y*y + z*z)   // g_flOne @ 0xa0f2a0, *2 @ 0xa10e74
out.y = 2*(x*y + z*w)
out.z = 2*(x*z - y*w)
out.w = 0
```

No normalize. Leaf (no calls, single basic block).

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004e8ad0_FUN_004e8ad0.md`
- Annotated: `docs/reconstruction/raw/aa_004e8ad0_FUN_004e8ad0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_004e8ad0.cpp`
- Named alias clean: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_CVOGHBAICreatureBase_DecideHeading_004e8ad0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_004e8ad0_Quat_ExtractRight_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004e8ad0_Quat_ExtractRight_Inferred.md`
- Residual: `docs/reconstruction/reviews/a_004e8ad0.md`
- Verified math: `docs/reconstruction/physics/verified/fn_004e8ad0_basisExtract.md`

## Callers / callees

**Callees:** none (leaf).

**Callers (Ghidra xrefs, 22 sites — sample High consumers):**

| Site | Function |
|---|---|
| `0x004fc7d2` | `MoveToTarget3DPoint` / `FUN_004fc650` |
| `0x0091a707` | `Client_Camera_ApplyLookOffset` / `FUN_0091a5f0` |
| `0x005d0af1` | `CVOGHBAICreatureBase_DecideHeading` |
| `0x004f9b7d` | `CVOGPlayerVehicle_UpdateTurretAiming` |
| (+18 more — see dual A §5) | net / creature / UI / client |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** |
| Right (+X) / column-0 identity | **High** |
| Constants 1.0 / 2.0 | **High** (`read_memory` 2026-07-29) |
| Parameter semantic names | **High** (quat / outRight) |
| Product English name | **Probable** (`_Inferred`) |
| Full caller English inventory | **Tentative** outside known drive/camera/AI/turret |
