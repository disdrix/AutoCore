# Function record: CVOGObjectiveRequirement_UseItem_Eval

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060cfe0` |
| **Canonical name** | `CVOGObjectiveRequirement_UseItem_Eval` |
| **Address** | `0x0060cfe0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Completion status** | **Dual A/B present** + **residual sealed 2026-07-29** (absolute 0x2071 + shared slot); runtime/diff/bit-exact open |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

UseItem eval (vtable +0x8): complete when slot float ≥ RepeatCount (+0x50). Pure compare; does not consume items.

## Residual seal (2026-07-29)

| Residual | Status | Evidence |
|---|---|---|
| Absolute vs delta on S2C `0x2071` | **Sealed absolute** | RecvObjectiveState assigns packet dwords; Eval/SlotAction read-only |
| SlotAction / Recv / Eval same slot | **Sealed** | identical `state+4+slot*4`; Recv `state[1..4]` ← `pkt+0x18..+0x24` |
| Runtime / differential | Open | needs live capture / harness |

Scratch: `tmp/a_0060cfe0.md`. Residual duals: `reviews/A|B_aa_0060cfe0_*_residual.md`. **No** WORK_QUEUE/RESUME edit by residual owner.

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_0060cfe0_CVOGObjectiveRequirement_UseItem_Eval.md` |
| Annotated | `raw/aa_0060cfe0_CVOGObjectiveRequirement_UseItem_Eval.annotated.md` |
| Clean | `reconstructed-exact/CVOGObjectiveRequirement_UseItem_Eval.cpp` |
| Dual A | `reviews/A_aa_0060cfe0_CVOGObjectiveRequirement_UseItem_Eval.md` |
| Dual B | `reviews/B_aa_0060cfe0_CVOGObjectiveRequirement_UseItem_Eval.md` |
| Dual A residual | `reviews/A_aa_0060cfe0_CVOGObjectiveRequirement_UseItem_Eval_residual.md` |
| Dual B residual | `reviews/B_aa_0060cfe0_CVOGObjectiveRequirement_UseItem_Eval_residual.md` |
| Sibling write path | `Client_RecvObjectiveState` `aa_00809460` / `0x00809460` |
| Sibling display | `UseItem_SlotAction` `aa_0060d060` / `0x0060d060` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** (trivial body; dual A) |
| Threshold int@`req+0x50` / slot byte@`+0x08` | **High** |
| Absolute slot float (not delta) | **High** (residual 2026-07-29) |
| Shared slot with SlotAction + Recv | **High** (residual 2026-07-29) |
| Parameter semantic names | Probable (`param_2` unused) |
| Runtime / bit-exact | Open |

## Open questions

- Runtime multi-use (RepeatCount>1) 0x2071 capture
- Differential equivalence / bit-exact (project-deferred)
- Recv post-write EvaluatePending scheduling (Recv residual, not this body)
