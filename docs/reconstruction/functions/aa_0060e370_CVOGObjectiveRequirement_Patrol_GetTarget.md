# Function record: CVOGObjectiveRequirement_Patrol_GetTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060e370` |
| **Canonical name** | `CVOGObjectiveRequirement_Patrol_GetTarget` |
| **Address** | `0x0060e370` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Completion status** | **Dual A/B present** — clean + raw; runtime/diff/bit-exact open |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Next patrol waypoint from progress: TFID index = (int)slot % required.

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_0060e370_CVOGObjectiveRequirement_Patrol_GetTarget.md` |
| Annotated | `raw/aa_0060e370_CVOGObjectiveRequirement_Patrol_GetTarget.annotated.md` |
| Clean | `reconstructed-exact/CVOGObjectiveRequirement_Patrol_GetTarget.cpp` |
| Dual A | `reviews/A_aa_0060e370_CVOGObjectiveRequirement_Patrol_GetTarget.md` |
| Dual B | `reviews/B_aa_0060e370_CVOGObjectiveRequirement_Patrol_GetTarget.md` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High (see dual A) |
| Parameter semantic names | Probable / Tentative (see dual B) |
| Runtime / bit-exact | Open |

## Open questions

- See dual B open questions
- Runtime observation / differential equivalence
