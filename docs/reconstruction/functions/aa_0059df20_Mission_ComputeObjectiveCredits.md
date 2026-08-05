# Function record: Mission_ComputeObjectiveCredits

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059df20` |
| **Canonical name** | `Mission_ComputeObjectiveCredits` |
| **Address** | `0x0059df20` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Calling convention** | MSVC `__fastcall` (objective in ECX) |
| **Completion status** | **Human-refined clean** + dual residual sealed 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Pure mission-complete **credit delta** calculator. Sibling of `Mission_ComputeObjectiveXp`. Uses tQuestBaseCredits (by mission TargetLevel) × tQuestCreditsLookup frac (by CreditsIndex) × CreditScaler, then `ceil` + FISTP (RC=chop).

Caller CompleteObjective **adds** the result into character money at `+0x720` (64-bit with carry to `+0x724`). UI toast/list callers also **read** the delta for display (no currency write).

## Signature

```c
int __fastcall Mission_ComputeObjectiveCredits(void* pObjective);
```

Returns `0` on base or lookup map end. **Does not** null-check mission def (unlike XP calculator).

## Behavioral summary

1. Key = `missionDef+0x11c` (TargetLevel short); if `g_nQuestBaseCreditsLoaded==0` → `EnsureQuestBaseCreditsLoaded` `0x00512870`; lower_bound.
2. `base = (float)*(int*)(row+0x10)` (`intBaseCredits`).
3. Key = `obj+0x13e` (CreditsIndex); if lookup not loaded → `EnsureQuestCreditsLookupLoaded` `0x00512830`; lower_bound.
4. Return `FISTP_chop(ceil(CreditScaler(+0x148) * frac(+0x10) * base))`.

## Offsets (this unit)

| Location | Role |
|---|---|
| `obj+0x13e` | short CreditsIndex |
| `obj+0x148` | float CreditScaler |
| `obj+0x14c` | mission def* (unchecked) |
| `mission+0x11c` | short TargetLevel |
| map node `+0x0C` | int key |
| map node `+0x10` | base int or frac float |
| map node `+0x15` | color / nil flag |

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Function boundary | High | Named sibling of XP calc |
| Control flow | High | Raw plate + 2026-07-29 re-decompile |
| ceil + FISTP RC=chop | High | image at `0x0059dfca` |
| No mission-def null check | High | raw vs XP contrast |
| Ensure-load names | **High** | callees `0x00512870` / `0x00512830` |
| Map node layout | **High** | residual via `0x0050f940` |
| Overall | **High (static)** | runtime still open |

## Open questions

- Full WAD row bit-exact dump (schema sealed).
- Runtime compare vs live complete.
- Image / bit-exact EXE diff.

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_0059df20_Mission_ComputeObjectiveCredits.md` |
| Annotated | `raw/aa_0059df20_Mission_ComputeObjectiveCredits.annotated.md` |
| Clean | `reconstructed-exact/Mission_ComputeObjectiveCredits.cpp` |
| Residual scratch | `reviews/a_0059df20.md` |
| Dual A/B | `reviews/A_aa_0059df20_*`, `reviews/B_aa_0059df20_*` |
| Caller | `functions/aa_00533f90_CVOGReaction_CompleteObjective.md` |
| Loaders | `EnsureQuestBaseCreditsLoaded`, `EnsureQuestCreditsLookupLoaded`, wad Load* exacts |
| Prior art | `docs/XP.md` (credits sibling) |
