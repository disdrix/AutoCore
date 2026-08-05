# Function record: CVOGObjectiveRequirement_Patrol_Eval

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060e0f0` |
| **Canonical name** | `CVOGObjectiveRequirement_Patrol_Eval` |
| **Address** | `0x0060e0f0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Completion status** | **Dual residual sealed 2026-07-29** — Laps/`+0x24`, absolute slot float, zero-product edge; runtime/diff/bit-exact open |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Patrol eval (vtable +0x8): complete when slot float ≥ **targetCount × Laps** (`+0xd0 * +0x24`). Slot holds absolute pad count (not 0..1).

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_0060e0f0_CVOGObjectiveRequirement_Patrol_Eval.md` |
| Annotated | `raw/aa_0060e0f0_CVOGObjectiveRequirement_Patrol_Eval.annotated.md` |
| Clean | `reconstructed-exact/CVOGObjectiveRequirement_Patrol_Eval.cpp` |
| Dual A | `reviews/A_aa_0060e0f0_CVOGObjectiveRequirement_Patrol_Eval.md` |
| Dual B | `reviews/B_aa_0060e0f0_CVOGObjectiveRequirement_Patrol_Eval.md` |
| Residual scratch | `reviews/a_0060e0f0.md` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + image | High (see dual A residual) |
| `+0x24` = Laps; `+0xd0` = targets | High (GetFlags XML/asm) |
| Absolute pad-count slot float | High |
| Parameter semantic names | High for layout; PDB original open |
| Runtime / bit-exact | Open |

## Open questions

- Runtime observation / differential equivalence
- Server `NeededCount` zero-edge normalize vs raw client product (port note only)
