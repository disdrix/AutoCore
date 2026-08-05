# Function record: CVOGReaction_FailMission

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052da30` |
| **Canonical name** | `CVOGReaction_FailMission` |
| **Address** | `0x0052da30` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Calling convention** | MSVC `__thiscall` — `ECX` = `CVOGCharacter*`; stack `missionId` u32; `RET 4` |
| **Return** | **`AL`** 0 or 1 (not full EAX) |
| **Completion status** | **Human-refined kernel** — CF sealed; dual residual body pass 2 sealed Notify `this`/body + **11-xref** drain table (2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Mark an **active** mission as failed for a character:

1. Lookup `missionId` in active-missions hash **`char+0x540`** (mask `hash+8`, buckets `hash+0x10`, chain `node+0xc`, key `node+0x10`).
2. Require live payload (`node+8 != 0`).
3. Log `"Player %I64d failed mission %d"` (`0x009cfa28`) with character COID (`dual-base +0x164/+0x168`).
4. Push `missionId` via `CVOGReaction_FailMissionNotify` with **`ECX = char+0x560`** (end-quest id vector: begin/end/cap at `+0x564/+0x568/+0x56c`).
5. `char+0x634 |= 0x10` (mission dirty / state-changed bit family).
6. Return **1** (`AL`); else **0**.

Does **not** free hash nodes or walk objectives in this function — notify/downstream owns cleanup.

## Signature

```c
uint32_t /* bool-like 0/1 in AL */ __thiscall
CVOGReaction_FailMission(CVOGCharacter* this, uint32_t missionId);
```

## Behavioral summary

| Branch | Condition | Effect |
|---|---|---|
| Miss / empty payload | no node or `node+8==0` | `return 0` — no notify, no flag |
| Hit | live active mission | log → vector push → dirty `0x10` → `return 1` |

## Callers (Ghidra xrefs, 2026-07-29 pass 2)

**11** `UNCONDITIONAL_CALL` sites. Named containers (5 functions; 6 sites) + 5 orphan sites.

| Caller / site | Address | Role | Drains `FUN_005307e0`? |
|---|---:|---|---|
| **`Client_RecvFailMission`** | call `0x0080b111` | S2C **0x20B2** after abandon / server fail | **Yes** |
| `FUN_006508d0` | call `0x00650c62` | Mission HB fail arm | **Yes** |
| orphan (UI/event; `DAT_00d1b6d8`) | call `0x00886402` | id `[ESI+0x540]`; then CALL drain | **Yes** |
| `CVOGHBMissionPatrol_Fn3` | call `0x00650f11` | Patrol HB fail (`**(+0x14c)`) | **No** |
| `CVOGObjectiveRequirement_Kill_Precheck` | call `0x00613df2` | Kill precheck; gate `req+0x1c` | **No** |
| `FUN_0060e800` site A | call `0x0060e82f` | `param_4==0xc` fail arm | **No** |
| `FUN_0060e800` site B | call `0x0060e9c3` | `param_4==0xb` fail-distance arm | **No** |
| orphan | `0x0060caa2` | req-family `+0x14c`; `RET 0x1C` | **No** |
| orphan | `0x0060ec36` | req-family `+0x14c`; `RET 0x1C` | **No** |
| orphan | `0x00612970` | gate `+0x34`; `+0x14c`; `RET 0x1C` | **No** |
| orphan | `0x0057f44c` | id `[ESI+0x25C]` | **No** |

Abandon UI does **not** call this directly: confirm sends C2S `0x20B2` from `Client_UiModalDispatch` case `0x4e46`; server applies; S2C `0x20B2` → `Client_RecvFailMission` → **this**.

### MissionId source family (non-Recv)

Most reaction/requirement arms:

```text
missionId = **(*(obj + 4) + 0x14c)
```

Exceptions: packet `+0x10` (Recv); orphan `00886402` → `[ESI+0x540]`; orphan `0057f44c` → `[ESI+0x25C]`.

## Callees

| Symbol | Role |
|---|---|
| `FUN_007a4480` | Debug / log printf-style |
| `CVOGReaction_FailMissionNotify` (`0x004149d0`) | **u32 vector push** at `char+0x560` (name is fail-site historical; multi-caller generic push) |

### Asm (Notify + dirty) — image sealed

```
0052da9a  LEA EDX,[ESP+0xc]        ; &missionId
0052da9e  PUSH EDX
0052da9f  LEA ECX,[ESI+0x560]      ; end-quest vector base
0052daa5  MOV [ESP+0x10],EDI       ; store missionId local
0052daa9  CALL 0x004149d0          ; push_back
0052daae  OR  [ESI+0x634],0x10
0052dab5  POP EDI
0052dab6  MOV AL,1
0052dab8  POP ESI
0052dab9  RET 4
```

Body size ≈ `0x0052da30`–`0x0052dabb` (`RET 4`).

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Function boundary | High | Small sealed body + image end |
| Signature thiscall + missionId + RET 4 | High | Raw + dual + image |
| Active hash `+0x540` walk | High | Same family as GiveMission |
| Notify `ECX = char+0x560` | **High / Confirmed** | Asm residual seal |
| Notify body = vector push | High | Decompile `0x004149d0` |
| Dirty bit `+0x634 \|= 0x10` | High write; Probable English | Explicit; shared writers |
| 11-xref + drain table | High (static) | Ghidra xrefs + image + decomp |
| Hash teardown inside this unit | None | Owned by drain / end-quest |
| Orphan host product names | Open | Ghidra undef |
| Overall | **High (static)** | Runtime / bit-exact open |

## Open questions

- Full dual of `FUN_005307e0` end-quest teardown (hash remove, "Failed" toast).
- Readers of dirty bit `0x10` on `+0x634`.
- Deferred drain timing when callers skip `FUN_005307e0`.
- Recover orphan host functions (5 sites).
- Optional rename of generic push `0x004149d0` (multi-unit).

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_0052da30_CVOGReaction_FailMission.md` |
| Annotated | `raw/aa_0052da30_CVOGReaction_FailMission.annotated.md` |
| Clean | `reconstructed-exact/CVOGReaction_FailMission.cpp` |
| Dual A | `reviews/A_aa_0052da30_CVOGReaction_FailMission.md` |
| Dual B | `reviews/B_aa_0052da30_CVOGReaction_FailMission.md` |
| Residual scratch | `tmp/a_0052da30.md` |
| Notify | `functions/aa_004149d0_CVOGReaction_FailMissionNotify.md` |
| S2C apply | `functions/aa_0080b100_Client_RecvFailMission.md` |
| Abandon C2S | `functions/aa_00911840_Client_UiModalDispatch.md` |
| Chain | `reviews/CHAIN_2026-07-29_abandon_failmission.md` |
