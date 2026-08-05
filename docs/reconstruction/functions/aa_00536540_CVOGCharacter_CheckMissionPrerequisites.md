# Function record: CVOGCharacter_CheckMissionPrerequisites

| Field | Value |
|---|---|
| **Stable ID** | `aa_00536540` |
| **Canonical name** | `CVOGCharacter_CheckMissionPrerequisites` |
| **Address** | `0x00536540` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Calling convention** | MSVC `__thiscall` — **ECX = character**, stack: missionId, autoComplete, checkLevel |
| **Completion status** | **Human-refined clean** — mutator award path + dual residual **edges sealed** 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Character-side **mission award bootstrap**: if not live-active (or force-complete when already active), look up mission def, optionally enforce race/faction, recursively award prereqs when `RequirementsNegative==0`, bridge min level with XP, prep + `GiveMission`, optional bulk objective complete.

**Not a pure predicate.** Distinct from `CheckMissionRequirements` (`aa_005462b0`), which is mission-def `this`, status-only.

## Signature

```c
// this = CVOGCharacter* (character)
char __thiscall CVOGCharacter_CheckMissionPrerequisites(
    void* thisCharacter,
    unsigned missionId,
    char autoComplete,   // nonzero → CompleteMissionObjectives after grant / if already live-active
    char checkLevel);    // nonzero → enforce race + faction
```

Returns: `1` success (award or auto-complete); `0` reject / already-active without autoComplete.

## Behavioral summary

| Stage | Behavior |
|---|---|
| Active hash `+0x540` | Live payload → autoComplete complete+`1` else `0`; miss/null payload → award |
| Def lookup | `FUN_0053fff0` (lazy table `+0xf18`) + `CNDHash_LookupByKey` |
| Race / faction | When `checkLevel`; race strict; faction `0xFFFF`=any |
| Prereqs | If `def+0x124` (**`RequirementsNegative`**) `==0`, recurse 4× `+0x9c` with `autoComplete=1` (return ignored) |
| Min level `+0x94` | If below, `XpToReachRelativeLevel` + `AddExperience` |
| Prep | 8×`0xFFFFFFFF` + **NPC** (`+0x88`) + **AutoAssign** (`+0xfc`) + id + 0 → `FUN_0052c700` (12-dword map store ~`char+0x50c`) |
| Grant | `GiveMission` → optional `CompleteMissionObjectives(...,1)` |

## Call sites (asm-sealed 2026-07-29)

| Site | VA | auto | check | Notes |
|---|---|---|---|---|
| Self recurse | `0x00536631` | 1 | parent | When `RequirementsNegative==0` |
| `FUN_00536740` | `0x005368ef` | 1 | 1 | After completed-hash `+0x538` skip |
| Client cmd | `0x00950915` | 1 | 0 | External prereq force; `*(client+0xe98)` |
| Debug force-add | `0x00954575` | 0 | 0 | `"Forced add mission (%i)"`; entry `0x00954510` |

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Function boundary | **High** | Named; fresh decompile 2026-07-29 ≡ prior raw |
| Signature (char thiscall, 3 stack args) | **High** | Body + 4 call sites |
| Control flow | **High** | Clean ≡ raw stage table |
| Active hash `+0x540` / live payload | **High** | Body + missionState §2.1 |
| Race/faction when checkLevel | **High** | Body; race no `0xFFFF` skip (unlike Requirements) |
| Recursive prereq award gate `+0x124==0` | **High** | CF + product **`RequirementsNegative`** |
| Prep NPC / AutoAssign | **High** | Layout + copies |
| `FUN_0052c700` shape | **High** | 12-dword store; English open |
| XP bridge callees | **High** present; formula in sibling unit | — |
| Side-effect / mutator nature | **High** | Explicit GiveMission/XP/complete |
| Call-site arg matrix | **High** | Xrefs + assembly context |
| Split vs Requirements | **High** | Dual residual table |
| Runtime / server parity | **Open** | Not observed |
| Overall | **High (static)** | Dual accept-with-gaps |

## Open questions

- Formal product names of `FUN_0052c700`, `FUN_0053fff0` owner.
- Server authority of client XP bridge.
- Full dual of client cmd hosts `0x0095084f` / `0x00954510` (args sealed only).
- Runtime award cascade observation.

## Dual review status

| Kind | Path | Verdict |
|---|---|---|
| A (fidelity) | `reviews/A_aa_00536540_CVOGCharacter_CheckMissionPrerequisites.md` | **accept-with-gaps** (edges sealed 2026-07-29) |
| B (skeptical) | `reviews/B_aa_00536540_CVOGCharacter_CheckMissionPrerequisites.md` | **accept-with-gaps** + reject pure-predicate / sole-caller stories |

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_00536540_CVOGCharacter_CheckMissionPrerequisites.md` |
| Annotated | `raw/aa_00536540_CVOGCharacter_CheckMissionPrerequisites.annotated.md` |
| Clean | `reconstructed-exact/CVOGCharacter_CheckMissionPrerequisites.cpp` |
| Dual A/B | `reviews/A_aa_00536540_*.md` / `reviews/B_aa_00536540_*.md` |
| Sibling | `aa_005462b0` CheckMissionRequirements (do not re-dual here) |
