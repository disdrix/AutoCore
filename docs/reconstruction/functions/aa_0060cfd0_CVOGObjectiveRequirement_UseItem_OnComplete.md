# Function record: CVOGObjectiveRequirement_UseItem_OnComplete

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060cfd0` |
| **Canonical name** | `CVOGObjectiveRequirement_UseItem_OnComplete` |
| **Address** | `0x0060cfd0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Completion status** | **Dual A/B present** — clean + raw; runtime/diff/bit-exact open |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Empty OnComplete stub (return only).

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_0060cfd0_CVOGObjectiveRequirement_UseItem_OnComplete.md` |
| Annotated | `raw/aa_0060cfd0_CVOGObjectiveRequirement_UseItem_OnComplete.annotated.md` |
| Clean | `reconstructed-exact/CVOGObjectiveRequirement_UseItem_OnComplete.cpp` |
| Dual A | `reviews/A_aa_0060cfd0_CVOGObjectiveRequirement_UseItem_OnComplete.md` |
| Dual B | `reviews/B_aa_0060cfd0_CVOGObjectiveRequirement_UseItem_OnComplete.md` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High (see dual A) |
| Parameter semantic names | Probable / Tentative (see dual B) |
| Runtime / bit-exact | Open |

## Open questions

- See dual B open questions
- Runtime observation / differential equivalence
