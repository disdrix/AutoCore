# Function record: CVOGObjectiveRequirement_Patrol_GetSomething

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060e9e0` |
| **Canonical name** | `CVOGObjectiveRequirement_Patrol_GetSomething` |
| **Address** | `0x0060e9e0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Completion status** | **Dual A/B present** — clean + raw; runtime/diff/bit-exact open |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Getter: return dword req+0x28 (ContinentCBID / primary). Placeholder name.

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_0060e9e0_CVOGObjectiveRequirement_Patrol_GetSomething.md` |
| Annotated | `raw/aa_0060e9e0_CVOGObjectiveRequirement_Patrol_GetSomething.annotated.md` |
| Clean | `reconstructed-exact/CVOGObjectiveRequirement_Patrol_GetSomething.cpp` |
| Dual A | `reviews/A_aa_0060e9e0_CVOGObjectiveRequirement_Patrol_GetSomething.md` |
| Dual B | `reviews/B_aa_0060e9e0_CVOGObjectiveRequirement_Patrol_GetSomething.md` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High (see dual A) |
| Parameter semantic names | Probable / Tentative (see dual B) |
| Runtime / bit-exact | Open |

## Open questions

- See dual B open questions
- Runtime observation / differential equivalence
