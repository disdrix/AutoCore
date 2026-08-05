# Function record: CVOGObjectiveRequirement_UseItem_InitActive

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060d540` |
| **Canonical name** | `CVOGObjectiveRequirement_UseItem_InitActive` |
| **Address** | `0x0060d540` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Completion status** | **Dual A/B present** — clean + raw; runtime/diff/bit-exact open |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Init active: give primary/secondary items at start when flags set (continent +0x7e).

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_0060d540_CVOGObjectiveRequirement_UseItem_InitActive.md` |
| Annotated | `raw/aa_0060d540_CVOGObjectiveRequirement_UseItem_InitActive.annotated.md` |
| Clean | `reconstructed-exact/CVOGObjectiveRequirement_UseItem_InitActive.cpp` |
| Dual A | `reviews/A_aa_0060d540_CVOGObjectiveRequirement_UseItem_InitActive.md` |
| Dual B | `reviews/B_aa_0060d540_CVOGObjectiveRequirement_UseItem_InitActive.md` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High (see dual A) |
| Parameter semantic names | Probable / Tentative (see dual B) |
| Runtime / bit-exact | Open |

## Open questions

- See dual B open questions
- Runtime observation / differential equivalence
