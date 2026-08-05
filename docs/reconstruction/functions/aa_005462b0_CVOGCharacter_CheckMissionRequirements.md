# Function record: CVOGCharacter_CheckMissionRequirements

| Field | Value |
|---|---|
| **Stable ID** | `aa_005462b0` |
| **Canonical name** | `CVOGCharacter_CheckMissionRequirements` |
| **Address** | `0x005462b0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Calling convention** | MSVC `__thiscall` — **ECX = mission def**, stack0 = character; **RET 4** (no third arg) |
| **Completion status** | **Human-refined clean** — dual residual 2026-07-29 sealed Ored/Negative/Discipline/Event + ABI |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Validate race, class, min/max level, discipline balance, requirement event, and up to 4 prerequisite missions. Used by `SearchAutoMissions` and offerable-interact evaluators.

## Signature (corrected)

```c
// this = mission definition* (despite CVOGCharacter_ prefix)
// No third formal — decompiler stack1 was phantom (RET 4 / one-push call sites)
int __thiscall CVOGCharacter_CheckMissionRequirements(
    void* thisMissionDef, int* pCharacter);
```

Returns: `-1` hard fail; `0` pass; `>0` first blocking prereq id.

## Behavioral summary

| Check | Mission field | Character / global source |
|---|---|---|
| Race | `+0x90` ReqRace (`0xFFFF` skip) | char data `+0x532` |
| Class | `+0x92` ReqClass | char data `+0x531` |
| Min level | `+0x94` ReqLevelMin | vtable `+0x27c` |
| Max level | `+0x98` ReqLevelMax (0 = none) | same |
| Discipline | `+0x104` type / `+0x108` value | `FUN_0052ada0` map @ char `+0x584` |
| Event | `+0x118` RequirementEventId (`-1` skip) | `FUN_005405e0` global vector |
| Prereqs | 4× `+0x9c` ReqMissionId | `HasCompletedMission` |
| Combine | `+0x120` RequirementsOred / `+0x124` RequirementsNegative | — |

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Function boundary | High | Named; multi-callers |
| **this = mission def** | High | Field offsets on ECX |
| ABI 2-arg thiscall | High | RET 4 + call-site pushes (2026-07-29) |
| Race/class/level offsets | High | missionState + Mission.cs |
| Discipline / Event field names | High | WAD layout residual seal |
| `FUN_0052ada0` / `FUN_005405e0` roles | High | Image; product symbols open |
| Prereq mode Ored/Negative | High | Mission.cs + CF truth table |
| Return codes | High | plate + CF |
| Overall | **High (static)** | |

## Open questions

- Product symbols for `FUN_0052ada0` / `FUN_005405e0`.
- GetLevel string for vtbl `+0x27c`.
- Server port of `RequirementsNegative`.
- Runtime multi-prereq matrix.

## Dual review status

| Kind | Path | Verdict |
|---|---|---|
| A (fidelity) | `reviews/A_aa_005462b0_CVOGCharacter_CheckMissionRequirements.md` | **accept-with-gaps** (2026-07-29 residual) |
| B (skeptical) | `reviews/B_aa_005462b0_CVOGCharacter_CheckMissionRequirements.md` | **accept-with-gaps** + reject raw param names |
| Scratch | `reviews/a_005462b0.md` | residual seals ledger |

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_005462b0_CVOGCharacter_CheckMissionRequirements.md` |
| Annotated | `raw/aa_005462b0_CVOGCharacter_CheckMissionRequirements.annotated.md` |
| Clean | `reconstructed-exact/CVOGCharacter_CheckMissionRequirements.cpp` |
| Dual A/B | `reviews/A_aa_005462b0_*.md` / `reviews/B_aa_005462b0_*.md` |
