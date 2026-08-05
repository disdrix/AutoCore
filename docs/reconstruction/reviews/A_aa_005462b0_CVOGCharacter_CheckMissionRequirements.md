# Review A (reconstruction fidelity): `aa_005462b0` CVOGCharacter_CheckMissionRequirements

| Field | Value |
|---|---|
| **Stable ID** | `aa_005462b0` |
| **VA** | `0x005462b0` |
| **Canonical name** | `CVOGCharacter_CheckMissionRequirements` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw) |
| **Counterpart** | `reviews/B_aa_005462b0_CVOGCharacter_CheckMissionRequirements.md` |
| **System** | `missions-progression` |
| **Dual status** | **Present — residual refresh 2026-07-29** |
| **Verdict** | **accept-with-gaps** |
| **Scratch** | `reviews/a_005462b0.md` |

---

## 1. Purpose

**Pure eligibility gate** — no mission grant, no hash insert, no currency/discipline spend, no flag mutation.
Called from `SearchAutoMissions` before auto-award; also from offerable-interact evaluators.
Returns whether the character meets race / class / level / discipline / event / prerequisite rules
on a mission definition.

**Calling convention (asm-sealed 2026-07-29):**

| Slot | Role | Evidence |
|------|------|----------|
| `ECX` / `this` | **mission definition\*** | All gate fields loaded from `this+0x90…+0x124`; callers `MOV ECX, def` |
| stack0 | **character\*** | Race/class chain + `HasCompletedMission` this; `FUN_0052ada0` this |
| *(no stack1)* | — | **RET 4** epilogue; every call site one `PUSH` only |

**Returns:**

| Code | Meaning | Evidence |
|-----:|---------|----------|
| `-1` | Hard fail (race/class/level/discipline/event **or** inverted-prereq branch) | Multiple early `return -1` + `RequirementsNegative` arm |
| `0` | All requirements pass | Terminal `return 0` |
| `>0` | First blocking prereq mission id (`firstFailId`) | `RequirementsNegative==0` fail path |

**No side effects.** Body only reads defs/character state and calls pure queries
(`FUN_0052ada0`, `FUN_005405e0`, `HasCompletedMission`); does not call `GiveMission` or write mission hashes.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005462b0_CVOGCharacter_CheckMissionRequirements.md` |
| Annotated | `docs/reconstruction/raw/aa_005462b0_CVOGCharacter_CheckMissionRequirements.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_CheckMissionRequirements.cpp` |
| Function record | `docs/reconstruction/functions/aa_005462b0_CVOGCharacter_CheckMissionRequirements.md` |
| Prior dual (legacy) | `aa_005462b0_reconstruction_review.md` / `aa_005462b0_skeptical_review.md` |
| Residual scratch | `reviews/a_005462b0.md` |
| WAD / product fields | `src/AutoCore.Game/Mission/Mission.cs` (`Mission.Read`) |
| System map | `docs/reconstruction/systems/missions-progression.md` |
| Offset cross-ref | `docs/missionState.md` §2.2 |
| Callee | `CVOGCharacter_HasCompletedMission` (`aa_0052aa20`) |

**Not performed:** `disassemble_bytes` (image bytes via `read_memory` + call-site context only); Launcher; live eligibility matrix.

---

## 3. Mission-def offsets (raw body + WAD names)

Every offset is a direct load from `this` / `thisMissionDef` in raw + clean.
English product names from `Mission.Read` sequential layout (Id@0 → race@`+0x90` sealed).

| Offset | Width | Product name (`Mission.cs`) | Role | Skip / special |
|--------|-------|----------------------------|------|----------------|
| `+0x90` | `u16` | `ReqRace` | Required race | `0xFFFF` = unrestricted |
| `+0x92` | `u16` | `ReqClass` | Required class (client plate often “faction”) | `0xFFFF` = unrestricted |
| `+0x94` | `i32` | `ReqLevelMin` | Min level | — |
| `+0x98` | `i32` | `ReqLevelMax` | Max level | `0` = no max |
| `+0x9c` | 4× `u32` | `ReqMissionId[4]` | Prereq mission ids | slot `0xFFFFFFFF` = empty |
| `+0x104` | `i32` | `Discipline` | Required resource/type id for balance gate | skip if `< 0` |
| `+0x108` | `i32` | `DisciplineValue` | Min balance for type | balance `>=` threshold |
| `+0x118` | `i32` | `RequirementEventId` | Active-event membership | `-1` = skip |
| `+0x120` | `i32` | **`RequirementsOred`** | Prereq OR vs AND | `0` = AND-all; ≠0 = OR-any |
| `+0x124` | `i32` | **`RequirementsNegative`** | Invert prereq sense | `0` = require; ≠0 = block if met |

**Character sources (via stack0 / `pCharacter`):**

| Source | Role | Evidence |
|--------|------|----------|
| Race byte `+0x532` | vs mission `+0x90` | Raw chain |
| Class/faction byte `+0x531` | vs mission `+0x92` | Same chain |
| Level | Virtual call entity vtable slot `+0x27c` | Two call sites (min + max) |
| Resource balance | `FUN_0052ada0(char, type)` map @ char `+0x584` | Asm @ `0x0052ada0` + call site |
| Completed missions | `HasCompletedMission(character, id)` | Prereq loop |
| Active events | `FUN_005405e0(id)` global vector | Sole caller |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Function boundary @ `0x005462b0` | **High** | Named capture; multi-callers |
| `this` / ECX = **mission definition** | **High** | Field loads + `MOV ECX,def` |
| stack0 = **character** | **High** | Race chain + `HasCompletedMission` + `FUN_0052ada0` this |
| **No third formal** (ABI `RET 4`) | **High** | **Sealed 2026-07-29** residual |
| Race `+0x90` / class `+0x92`, `0xFFFF` skip | **High** | Raw CF + `Mission.cs` |
| Char race `+0x532` / class `+0x531` | **High** | Body + missionState §2.1 |
| Min `+0x94` / max `+0x98` (0=none) | **High** | Raw guards |
| Level via vtbl `+0x27c` | **High** (slot); **Probable** (GetLevel name) | Shared with XP duals |
| `+0x104/+0x108` = Discipline / DisciplineValue | **High** | WAD layout math |
| `FUN_0052ada0` = char resource balance by type | **High** (role/ABI); product symbol open | Image + call site |
| `+0x118` = RequirementEventId | **High** | WAD layout |
| `FUN_005405e0` = event-id membership | **High** (role); product symbol open | Image; sole xref |
| 4 prereqs @ `+0x9c`, empty=`0xFFFFFFFF` | **High** | Loop |
| `+0x120/+0x124` = RequirementsOred / Negative | **High** | **Sealed 2026-07-29** |
| Prereq truth table (below) | **High** | CF + product names |
| Return set `-1` / `0` / blocking id | **High** | All three sites |
| **No GiveMission / no state writes** | **High** | Read + query only |
| Runtime eligibility matrix | **Open** | Not observed |

---

## 5. Control flow: clean ≡ raw

| Stage | Raw | Clean | Match |
|---|---|---|---|
| Race **or** class fail → `-1` | Combined `if` | Same | **Yes** |
| Min level vtbl `+0x27c` vs `+0x94` | Present | Present | **Yes** |
| Max level when `+0x98 > 0` | Present | Present | **Yes** |
| Discipline: type≥0 and balance < threshold → `-1` | Present | Present | **Yes** |
| Event: id≠-1 and helper==0 → `-1` | Present | Present | **Yes** |
| Prereq loop 4 slots | Present | Present | **Yes** |
| Mode eval `+0x124` / `+0x120` | Present | Present | **Yes** |
| Returns `-1` / `0` / firstFailId | Present | Present | **Yes** |
| No invented grants / stores | N/A | None added | **Yes** |

### Prereq matrix (CF + sealed English)

When at least one slot at `+0x9c` is nonempty (`bAnyPrereq`):

| `RequirementsNegative` (`+0x124`) | `RequirementsOred` (`+0x120`) | Fail condition | Return |
|-----------------------------------|-------------------------------|----------------|--------|
| `0` | `0` | `!allPass` | `firstFailId` |
| `0` | ≠0 | `!anyPass` | `firstFailId` |
| ≠0 | `0` | `allPass` | `-1` |
| ≠0 | ≠0 | `anyPass` | `-1` |

If no nonempty prereq slots → fall through to `0`.

---

## 6. Gaps / open questions

1. Product / PDB symbols for `FUN_0052ada0` and `FUN_005405e0` (roles sealed; leave FUN_*).
2. Confirm retail strings for GetLevel at vtbl `+0x27c` (Probable).
3. Typed layout of race/class pointer chain (`[1]+4`, `+0xac`, `+0x3c`).
4. Live multi-prereq + Negative/Ored matrix vs auto-award.
5. Server port: `RequirementsNegative` not in `MeetsMissionPrerequisites` (client CF sealed).
6. Whether discipline balance map is identical to cash currency map or a shared resource table (same helper).

---

## 7. Relation to prior reviews

| Review | Date | Verdict | Notes |
|--------|------|---------|-------|
| Legacy reconstruction | 2026-07-23 | accept-with-gaps | CF sealed; naming open |
| Legacy skeptical | 2026-07-23 | **needs-revision** | Attacked raw `this`/`pMissionDef` names |
| Dual A (first modern) | 2026-07-28 | accept-with-gaps | CF + binding; mode English open |
| Dual A residual | **2026-07-29** | **accept-with-gaps** | Mode English, ABI, field names, FUN roles sealed |

---

## 8. Verdict

### **accept-with-gaps**

**Accept because:** Clean control flow matches raw; mission-def offsets body-backed; product names for
`RequirementsOred` / `RequirementsNegative` / `Discipline` / `DisciplineValue` / `RequirementEventId`
sealed via WAD layout; ABI sealed as 2-arg thiscall; helpers role-sealed from image; no side effects.

**Gaps:** FUN product symbols, GetLevel name, typed char chain, runtime matrix, server Negative port.

**Not invent side effects:** Do not treat this as grant, spend, or flag-write.

---

## Checklist

| Check | Result |
|---|---|
| Raw + clean + function record exist | **Yes** |
| Clean CF ≡ raw | **Pass** |
| Offsets body-backed | **Pass** |
| Prereq mode English sealed | **Pass** (Ored/Negative) |
| ABI sealed (no third arg) | **Pass** |
| Return codes match | **Pass** |
| No invented side effects | **Pass** |
| Dual A/B present | **Yes** |
| Verdict | **accept-with-gaps** |
