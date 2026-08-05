# Annotated low-level: CVOGReaction_FailMission (`aa_0052da30`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052da30` |
| **VA** | `0x0052da30` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **System** | missions-progression |
| **Source raw** | `aa_0052da30_CVOGReaction_FailMission.md` (capture 2026-07-23) |
| **Residual** | `tmp/a_0052da30.md` (2026-07-29 dual residual body pass 2) |

This file is the **annotated** layer: widths, signedness, branch order, side effects, and decompiler corrections. It does not replace the immutable raw capture.

---

## 1. Corrected signature

```c
// MSVC thiscall: ECX = character
// Return: AL = 0 or 1 (bool-like); RET 4
uint32_t /* bool-like 0/1 */ __thiscall
CVOGReaction_FailMission(CVOGCharacter* this, uint32_t missionId);
```

| Name | Width | Signedness | Origin | Role |
|---|---|---|---|---|
| `this` / `param_1` | 32-bit pointer | unsigned | `ECX` → `ESI` | Character |
| `missionId` / `param_2` | **u32** | unsigned | stack → `EDI` | Active mission key to fail |
| return | **u8 in AL** 0 or 1 | unsigned | `EAX` low | 1 = failed an active entry; 0 = not found / no payload |

---

## 2. Decompiler corrections

| Decompiler artifact | Correction | Confidence |
|---|---|---|
| `int param_1` | **`CVOGCharacter*`** | **High** |
| `uint param_2` | **u32 missionId** | **High** |
| Hash walk `+0x540` | Active-missions CNDHash (same family as GiveMission insert) | **High** |
| Node `+0x10` | Mission id key in hash node | **High** |
| Node `+0x8` | Payload / mission instance pointer; **must be non-null** to fail | **High** |
| Node `+0xc` | Next collision-chain pointer | **High** |
| `CVOGReaction_FailMissionNotify(&param_2)` alone | **`ECX = this+0x560`**, arg `&missionId` | **High / Confirmed** (asm + image) |
| Notify callee | **u32 vector push_back**; not hash teardown | **High** |
| Vector fields | `char+0x564` begin, `+0x568` end, `+0x56c` capacity | **High** |
| `param_1 + 0x634 \|= 0x10` | Character dirty / mission-state-changed flag bit family | **High** write; **Probable** English |
| Player id print `*(base+4)+4` + `param_1 + 0x164/0x168` | 64-bit character object id (COID) for debug log | **High** |
| Format string | Immediate `0x009cfa28` = `"Player %I64d failed mission %d"` | **High** |
| `return 1` as full EAX | **`MOV AL,1`** only; epilogue **`RET 4`** | **High** |

---

## 3. Active-mission hash probe (width-expanded)

```text
hash = *(u32*)(this + 0x540)
bucket = *(u32*)(hash + 0x10)
mask   = *(u32*)(hash + 8)
node   = *(u32*)(*(u32*)(bucket + (mask & missionId)*4) + 4)  // chain head

while (node != 0):
  if (*(u32*)(node + 0x10) == missionId):
    break
  node = *(u32*)(node + 0xc)

// require node && *(node+8) != 0
```

All indices and keys are **u32**. Mask-and-bucket is classic open/chained hash.

---

## 4. Control flow and branches

```text
node = find_active_mission(this+0x540, missionId)
if node == 0: return 0
if payload(node+8) == 0: return 0

log "Player %I64d failed mission %d"
// asm: LEA ECX,[this+0x560]; push &missionId; CALL Notify
vector_push_u32(this+0x560, missionId)
*(u32*)(this+0x634) |= 0x10
return 1
```

| Branch | Condition | Effect |
|---|---|---|
| Miss / empty payload | no node or `+8==0` | `return 0`, no notify, no flag |
| Hit | node with payload | push + dirty bit + `return 1` |

**Does not** free hash nodes or walk objectives in this function — failure notify/downstream owns cleanup.

---

## 5. Side-effect order

1. Read-only hash walk on `this+0x540`.
2. Debug log `FUN_007a4480` (format with COID + mission id).
3. `CVOGReaction_FailMissionNotify` — **`this = char+0x560`**, stack local mission id copy.
4. **OR** `0x10` into `*(u32*)(this+0x634)`.
5. Return 1 in `AL` (`RET 4`).

---

## 6. Callers (strengthened 2026-07-29 residual pass 2)

**11** CALL xrefs. Drain is **caller-owned**.

| Caller / site | Address | Path | Drains `FUN_005307e0`? |
|---|---:|---|---|
| `Client_RecvFailMission` | call `0x0080b111` | S2C **0x20B2** | **Yes** |
| `FUN_006508d0` | call `0x00650c62` | Mission HB fail | **Yes** |
| orphan (`DAT_00d1b6d8`) | call `0x00886402` | id `[ESI+0x540]` then drain | **Yes** |
| `CVOGHBMissionPatrol_Fn3` | call `0x00650f11` | Patrol HB: fail from block `+0x14c` | **No** |
| `CVOGObjectiveRequirement_Kill_Precheck` | call `0x00613df2` | Kill precheck; gate `req+0x1c` | **No** |
| `FUN_0060e800` A | call `0x0060e82f` | `param_4==0xc` | **No** |
| `FUN_0060e800` B | call `0x0060e9c3` | `param_4==0xb` | **No** |
| orphan | `0x0060caa2` | req-family `+0x14c` | **No** |
| orphan | `0x0060ec36` | req-family `+0x14c` | **No** |
| orphan | `0x00612970` | gate `+0x34` + `+0x14c` | **No** |
| orphan | `0x0057f44c` | id `[ESI+0x25C]` | **No** |

**MissionId family (HB/req):** `**(*(obj+4)+0x14c)` double-deref is the common pattern.

**Abandon chain:** UI confirm does not call this unit.  
`Client_MissionDialogHandleButton` state 2 → modal → `Client_UiModalDispatch` case `0x4e46` → C2S `0x20B2` → server → S2C `0x20B2` → `Client_RecvFailMission` → **here** → `FUN_005307e0`.

Local reaction/HB callers **can** fail without an S2C packet; only some drain immediately.

---

## 7. Open questions

- Full dual of `FUN_005307e0` (hash remove, "Failed" toast, audio).
- Readers of dirty bit `0x10` on `+0x634`.
- Deferred drain when caller skips end-quest.
- Orphan host function recovery (5 sites).
- Runtime abandon e2e observation (C2S send → S2C apply).
