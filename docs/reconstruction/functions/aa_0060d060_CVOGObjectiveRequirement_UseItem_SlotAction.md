# Function record: CVOGObjectiveRequirement_UseItem_SlotAction

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060d060` |
| **Canonical name** | `CVOGObjectiveRequirement_UseItem_SlotAction` |
| **Address** | `0x0060d060` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Completion status** | **Dual A/B present** — clean + raw; runtime/diff/bit-exact open |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

UI progress text: name: cur / req via slot float and +0x50.

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_0060d060_CVOGObjectiveRequirement_UseItem_SlotAction.md` |
| Annotated | `raw/aa_0060d060_CVOGObjectiveRequirement_UseItem_SlotAction.annotated.md` |
| Clean | `reconstructed-exact/CVOGObjectiveRequirement_UseItem_SlotAction.cpp` |
| Dual A | `reviews/A_aa_0060d060_CVOGObjectiveRequirement_UseItem_SlotAction.md` |
| Dual B | `reviews/B_aa_0060d060_CVOGObjectiveRequirement_UseItem_SlotAction.md` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High (see dual A) |
| Parameter semantic names | Probable / Tentative (see dual B) |
| Runtime / bit-exact | Open |

## Open questions

- See dual B open questions
- Runtime observation / differential equivalence
