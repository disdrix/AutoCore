# Function record: CVOGObjectiveRequirement_UseItem_MatchTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060d7f0` |
| **Canonical name** | `CVOGObjectiveRequirement_UseItem_MatchTarget` |
| **Address** | `0x0060d7f0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Completion status** | **Dual A/B present** — clean + raw; runtime/diff/bit-exact open |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

MatchTarget trampoline (vtable +0x38) -> FUN_0060d460 helper.

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_0060d7f0_CVOGObjectiveRequirement_UseItem_MatchTarget.md` |
| Annotated | `raw/aa_0060d7f0_CVOGObjectiveRequirement_UseItem_MatchTarget.annotated.md` |
| Clean | `reconstructed-exact/CVOGObjectiveRequirement_UseItem_MatchTarget.cpp` |
| Dual A | `reviews/A_aa_0060d7f0_CVOGObjectiveRequirement_UseItem_MatchTarget.md` |
| Dual B | `reviews/B_aa_0060d7f0_CVOGObjectiveRequirement_UseItem_MatchTarget.md` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High (see dual A) |
| Parameter semantic names | Probable / Tentative (see dual B) |
| Runtime / bit-exact | Open |

## Open questions

- See dual B open questions
- Runtime observation / differential equivalence
