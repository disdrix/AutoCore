# Function record: CVOGObjectiveRequirement_Patrol_GetFlags

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060e260` |
| **Canonical name** | `CVOGObjectiveRequirement_Patrol_GetFlags` |
| **Address** | `0x0060e260` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Completion status** | **Dual A/B present** — clean + raw; runtime/diff/bit-exact open |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Patrol XML dump to FILE* (misnamed GetFlags): AutoComplete/Fail, targets, Laps.

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_0060e260_CVOGObjectiveRequirement_Patrol_GetFlags.md` |
| Annotated | `raw/aa_0060e260_CVOGObjectiveRequirement_Patrol_GetFlags.annotated.md` |
| Clean | `reconstructed-exact/CVOGObjectiveRequirement_Patrol_GetFlags.cpp` |
| Dual A | `reviews/A_aa_0060e260_CVOGObjectiveRequirement_Patrol_GetFlags.md` |
| Dual B | `reviews/B_aa_0060e260_CVOGObjectiveRequirement_Patrol_GetFlags.md` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High (see dual A) |
| Parameter semantic names | Probable / Tentative (see dual B) |
| Runtime / bit-exact | Open |

## Open questions

- See dual B open questions
- Runtime observation / differential equivalence
