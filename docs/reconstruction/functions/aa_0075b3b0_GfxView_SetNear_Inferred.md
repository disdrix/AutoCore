# Function record: GfxView_SetNear_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075b3b0` |
| **Canonical name** | `GfxView_SetNear_Inferred` |
| **Address** | `0x0075b3b0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | graphics / client camera (GfxView) |
| **Completion status** | **Dual A/B present** — refined 2026-07-29 W31-O; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Verdict** | **accept** |

## Alias

| Name | Notes |
|---|---|
| `FUN_0075b3b0` | Ghidra default / scaffold |
| `Named_CalleeOf_…_0075b3b0` | Auto xref seed (discard for naming) |
| `GfxView_SetNear_Inferred` | **Canonical** — stores near + dirty flags |

## Purpose

Set the **GfxView near plane** at `+0xF0` and mark projection rebuild dirty at `+0x48` and `+0xCC`. Leaf setter; polarity twin of far-setter `FUN_0075b390` (`+0xF4`).

## Signature (sealed)

```c
// ECX = GfxView*; stack float near; RET 4
void __thiscall GfxView_SetNear_Inferred(GfxView *this, float nearPlane);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0075b3b0_FUN_0075b3b0.md`
- Annotated: `docs/reconstruction/raw/aa_0075b3b0_FUN_0075b3b0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/GfxView_SetNear_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0075b3b0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0075b3b0_GfxView_SetNear_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0075b3b0_GfxView_SetNear_Inferred.md`
- Prior scaffold record: `docs/reconstruction/functions/aa_0075b3b0_FUN_0075b3b0.md`
- Scratch: `docs/reconstruction/tmp/a_0075b3b0.md`

## Callers / callees

**Callers (4 xrefs):**

| Function | Site |
|---|---|
| `FUN_004cda90` (`Client_InitPalantirViewBundle_Inferred`) | `0x004cdae6` (0.5f) |
| `FUN_004c0a90` | `0x004c0b17` |
| `FUN_0055ca90` | `0x0055cb17` (~0.2f) |
| `FUN_005b3420` | `0x005b348b` |

**Callees:** none (leaf).

## Layout

| Off | Role |
|---:|---|
| `+0xF0` | Near plane (float) |
| `+0x48` | Proj dirty (uint8) |
| `+0xCC` | Aux dirty (uint8) |

## Confidence

| Claim | Level |
|---|---|
| Control flow / bytes | **High** (full 28 B hex) |
| Float ABI (MOVSS + RET 4) | **High** |
| Near @ +0xF0 / dirty pair | **High** |
| GfxView class | **High** (sibling path + EnsureProjection layout) |
| Product method English | **Inferred** |
| Runtime golden | **Open** |
