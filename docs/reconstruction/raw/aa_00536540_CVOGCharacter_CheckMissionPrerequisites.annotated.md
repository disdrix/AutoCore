# Annotated low-level: CVOGCharacter_CheckMissionPrerequisites (`aa_00536540`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00536540` |
| **VA** | `0x00536540` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **System** | missions-progression |
| **Source raw** | `aa_00536540_CVOGCharacter_CheckMissionPrerequisites.md` (capture 2026-07-23; re-confirmed 2026-07-29) |
| **Status** | Human-refined annotated layer |

This file is the **annotated** layer: widths, signedness, branch order, side effects, and decompiler corrections. It does not replace the immutable raw capture.

---

## 1. Corrected signature

```c
// MSVC __thiscall — ECX = character (CVOGCharacter*)
char /* bool 0|1 */ __thiscall CVOGCharacter_CheckMissionPrerequisites(
    CVOGCharacter* this,       // ECX
    uint32_t       missionId,  // stack
    char           autoComplete, // stack; non-zero → CompleteMissionObjectives after grant / if already live-active
    char           checkLevel    // stack; non-zero → enforce race + faction before award
);
```

| Name | Width | Signedness | Origin | Role |
|---|---|---|---|---|
| `this` | 32-bit pointer | — | `ECX` | Character owning mission hashes |
| `missionId` | **u32** | unsigned | stack | Target mission id |
| `autoComplete` | **i8 / char** | flag (0 / nonzero) | stack | Bulk-complete after award, or force-complete if already active |
| `checkLevel` | **i8 / char** | flag (0 / nonzero) | stack | When set, race/faction gate required for award path |
| return | **char** `0` / `1` | — | `AL` | `1` = awarded or auto-completed success; `0` = reject / already-active without autoComplete |

**Naming collision:** Despite “Prerequisites”, this function **mutates** progression: recursive grant/complete of prereqs, optional XP inject to meet min level, `GiveMission`, optional `CompleteMissionObjectives`. It is **not** a pure eligibility predicate.

**Split vs `CheckMissionRequirements` (`aa_005462b0`):** Requirements is mission-def `this`, returns `-1/0/blockingId`, **no** grants. This unit is character `this`, returns `0/1`, **does** grant. See dual A/B residual table.

---

## 2. Width / signedness map (body-backed)

### 2.1 Character / hash

| Location | Width | Role | Evidence |
|---|---|---|---|
| `this+0x540` | hash object | **Active** missions hash | Raw bucket walk; missionState §2.1 |
| hash `+8` | **u32** mask | Bucket index `mask & missionId` | Raw |
| hash `+0x10` | pointer | Bucket table base | Raw |
| node `+0x10` | **u32** | Key = mission id | Compare to `uMissionID` |
| node `+0xc` | pointer | Next in chain | Chain walk |
| node `+8` | pointer | Payload; **nonzero = live active** | Gate for early complete/return |
| Entity chain via `this+4` → `+4` → `+0xac+this` → `+0x3c` | pointer | Char race/faction blob | Same pattern as Requirements |
| blob `+0x532` | **u8** → zext **u16** | Live race | Compared to def `+0x90` |
| blob `+0x531` | **u8** → zext **u16** | Live faction | Compared to def `+0x92` |
| Entity `vtbl+0x27c` | method | Get level (**s32** return) | Called 1–3× on award path |

### 2.2 Mission definition (after `FUN_0053fff0` + `CNDHash_LookupByKey`)

| Offset | Width | Role | Notes |
|---|---|---|---|
| `+0x88` | **u32** | **NPC** (giver CBID) → prep `uStack_10` | `Mission.Read` layout |
| `+0x90` | **u16** | **ReqRace** | When `checkLevel`: **must equal** char race (no `0xFFFF` skip in this unit) |
| `+0x92` | **u16** | **ReqClass** (plate “faction”) | When `checkLevel`: `0xFFFF` = any, else must equal char faction |
| `+0x94` | **s32** (compared with signed `<`) | **ReqLevelMin** | Level gap → XP bridge |
| `+0x9c` | 4× **u32** | **ReqMissionId[4]** | Slot `0xFFFFFFFF` = empty |
| `+0xfc` | **u32** copy of **AutoAssign** (WAD `i16`) | prep `uStack_c` | `Mission.Read` |
| `+0x124` | **s32** | **RequirementsNegative** | Recurse award **only if `== 0`** (Requirements dual owns query polarity) |

### 2.3 Stack prep blob (`uStack_30` … `uStack_4`, 12 dwords shape)

| Slot | Init | Role |
|---|---|---|
| `uStack_30` … `uStack_14` | `0xFFFFFFFF` × 8 | Filled constants before `FUN_0052c700` |
| `uStack_10` | `def+0x88` | Field copy |
| `uStack_c` | `def+0xfc` | Field copy |
| `uStack_8` | `missionId` (**u32**) | Target id |
| `uStack_4` | `0` (**u8** zero-extended / dword 0) | Flag / pad |

Callee `FUN_0052c700` is `__thiscall` character + `(missionId, blob*)` at the call site (Ghidra often drops `this`).

---

## 3. Decompiler corrections

| Decompiler artifact | Correction | Confidence |
|---|---|---|
| Active hash walk `this+0x540` | Active-mission probe (not completed `+0x538`) | **High** |
| `node+8 != 0` | Live payload required to treat as “already active” | **High** |
| Missing `this` on `GiveMission` / `FUN_0052c700` | Both are character `__thiscall`; ECX still character | **High** (sibling units) |
| `CompleteMissionObjectives(id, 1)` | `__cdecl` static; reason `1` | **High** (`aa_00536080`) |
| Race always strict when `checkLevel` | Unlike Requirements, **no** `0xFFFF` race skip here | **High** (raw compare) |
| Faction `0xFFFF` | Wildcard (any faction) | **High** |
| `def+0x124 == 0` | Enables recursive **award** of prereqs (not HasCompleted check) | **High** CF; English of field open |
| Recursive call discards return | Side-effect only; failures do not abort award | **High** |
| Vtable `+0x27c` | Get character level | **Probable** (name); slot **High** |
| `Experience_XpToReachRelativeLevel` + `AddExperience(..., PacketOrNonKill)` | Client XP inject to meet min level | **High** present |
| `FUN_0052c700` | Character thiscall; store 12-dword prep into map ~`char+0x50c` keyed by missionId | **High** shape; product English **Tentative** |
| `FUN_0053fff0` | Lazy mission-def table at object `+0xf18` | **High** shape; owner name **Probable** |
| `def+0x124` | Product **`RequirementsNegative`** — award-recurse gate when `==0` | **High** |
| Plate “not completed” | **This body does not walk `+0x538`**; caller `FUN_00536740` does completed skip first | **High** |

---

## 4. Control flow

```text
// --- Active-hash chain at this+0x540 ---
node = bucket_head(this+0x540, missionId)
loop:
  if node == null:
    goto AWARD
  if node.key == missionId:
    if node.payload != null:          // live active
      if autoComplete:
        CompleteMissionObjectives(id, reason=1)
        return 1
      return 0
    else:
      goto AWARD                      // key present but empty payload
  node = node.next

AWARD:
  table = FUN_0053fff0()
  if table root null OR Lookup(id) null:
    return 0
  if checkLevel:
    // race MUST match (no 0xFFFF skip)
    // faction 0xFFFF OR match
    if race/faction fail: return 0

  if def+0x124 == 0:
    for i in 0..3:
      pid = def.prereq[i]   // +0x9c
      if pid != 0xFFFFFFFF:
        CheckMissionPrerequisites(this, pid, autoComplete=1, checkLevel)
        // return ignored

  minLevel = def+0x94
  level = GetLevel()   // vtbl+0x27c
  if level < minLevel:
    level = GetLevel()
    xp = XpToReachRelativeLevel(this, minLevel - level)
    GetLevel()          // third call; return unused
    AddExperience(this, xp, PacketOrNonKill)

  build prep blob (8× -1, def+0x88, def+0xfc, id, 0)
  FUN_0052c700(this, id, &blob)   // thiscall shape
  GiveMission(this, id)
  if autoComplete:
    CompleteMissionObjectives(id, 1)
  return 1
```

| Branch | Effect |
|---|---|
| Live-active + !autoComplete | return `0` (already have it) |
| Live-active + autoComplete | force complete objs → `1` |
| Def miss / race-faction fail | `0` |
| Success award path | GiveMission ± complete → `1` |

---

## 5. Side-effect order (award path)

1. Optional recursive prereq awards/completes (`autoComplete` forced to `1` on children).
2. Optional XP grant (level bridge).
3. `FUN_0052c700` prep structure.
4. `CVOGReaction_GiveMission`.
5. Optional bulk `CompleteMissionObjectives(..., reason=1)`.

**Not a pure check** — mutates XP, active missions, objectives.

---

## 6. Split vs CheckMissionRequirements (`aa_005462b0`)

| Dimension | Prerequisites `0x00536540` | Requirements `0x005462b0` |
|---|---|---|
| `this` / ECX | **Character** | **Mission def** |
| Return | `char` 0/1 | `int` -1 / 0 / blocking prereq id |
| Side effects | **Yes** (XP, GiveMission, complete) | **None** |
| Active check | Hash `char+0x540` | Not in body |
| Completed check | **Not in body** (caller may) | Via `HasCompletedMission` for prereqs |
| Race | When `checkLevel`; **no** `0xFFFF` skip | `0xFFFF` = unrestricted |
| Faction | When `checkLevel`; `0xFFFF` = any | `0xFFFF` = unrestricted |
| Min level | Bridge with XP grant | Fail `-1` if below |
| Max level | **Not checked** | `+0x98` (0 = none) |
| Currency / flag | **Not checked** | `+0x104/+0x108`, `+0x118` |
| Prereqs `+0x9c` | **Recursive award** if `+0x124==0` | **Query** `HasCompletedMission` + mode `+0x120/+0x124` |
| Primary retail path | `FUN_00536740` → force auto+check | `SearchAutoMissions` → if 0 then GiveMission |

---

## 7. Call-site matrix (residual sealed 2026-07-29)

| Site VA | auto | check | Role |
|---|---|---|---|
| `0x00536631` self | 1 | parent | Internal prereq force-award |
| `0x005368ef` `FUN_00536740` | 1 | 1 | Bulk auto-award after completed-hash skip |
| `0x00950915` client | 1 | **0** | External prereq walk (`*(client+0xe98)`) |
| `0x00954575` debug | **0** | **0** | `"Forced add mission (%i)"` @ `0x00a28af4` |

## 8. Open residual questions

1. ~~Retail English for `def+0x124`~~ **Sealed** — `RequirementsNegative` (award gate when `==0`; query polarity owned by Requirements dual).
2. ~~Prep fields `+0x88` / `+0xfc`~~ **Sealed names** — NPC / AutoAssign; `FUN_0052c700` product English still open.
3. Why GetLevel is called three times on the XP path (side effect vs pure query).
4. Server parity of client XP bridge before grant.
5. ~~Call sites with `checkLevel=0` / `autoComplete=0`~~ **Sealed** — matrix §7.
6. `missionState.md` note that this function “reads completed hash `+0x538`” is **incorrect for this body** — completed gate is on caller `FUN_00536740` only.
7. Full dual of client hosts for sites `0x00950915` / `0x00954575` (out of OWN; args sealed).
