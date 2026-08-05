# Function record: CVOGCharacter_IsMissionTurnInReady

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052b420` |
| **Canonical name** | `CVOGCharacter_IsMissionTurnInReady` |
| **Ghidra name** | `FUN_0052b420` |
| **Address** | `0x0052b420` |
| **Body** | `0x0052b420`–`0x0052b4d8` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` |
| **Calling convention** | MSVC `__thiscall` (ECX=character; 2 stack args; `ret 8`) |
| **Completion status** | **Sealed** — dual A/B 2026-07-29; last-obj + active-hash + readiness gates High |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_0052b420`
- `Named_CalleeOf_Client_ShowNpcMissionDialogUI_0052b420` (legacy scaffold name)

## Purpose

Return whether the character may treat `mission` as **turn-in ready**: last objective is active on the character, complete under strict evaluator mode, and (if NPC provided) all type-3 interact evaluators target that NPC.

## Signature

```c
bool __thiscall CVOGCharacter_IsMissionTurnInReady(
    void* this /* CVOGCharacter* */,
    void* missionDef,
    void* npcOpt /* nullable object; 0 skips NPC filter */);
```

## Behavioral summary (sealed)

1. **Last objective:** `lastObj = *( *(mission+0x13c) + (uint8)*(mission+0x130)*4 - 4 )`.
2. **Active hash:** bucket-walk `*(this+0x548)` by key `*(lastObj+0x10)`; require node and `*(node+0x8) != 0`.
3. **Complete:** `FUN_0052a020(this, lastObj, 1)` must return true (flag 1 → vtbl+8 eval path).
4. **NPC filter (optional):** if `npcOpt != 0` and evaluators `[lastObj+0x158, +0x15c)` non-empty, any type-3 (`vtbl+0x50 == 3`) with `*(eval+0x18) != npc_clonebase(+0x34 via +0xac chain)` → false.
5. Else true. **No memory stores.**

## Callers / callees

| Direction | Address / name | Role |
|---|---|---|
| Caller | `Client_ShowNpcMissionDialogUI` `0x009438f0` | claim chrome / `+0x64c` |
| Caller | `FUN_004d5c10` `0x004d5c10` (2 sites) | interact / offer state `+0x2c` |
| Caller | `FUN_008a8770` `0x008a8770` | journal UI; npc=0 |
| Callee | `FUN_0052a020` `0x0052a020` | last-objective complete eval |

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Function boundary | **High** | Ghidra body end `0x0052b4d8`; image |
| Signature / thiscall | **High** | ECX+0x548; `ret 8`; 4 call sites |
| Last-objective formula | **High** | sealed LEA |
| Active hash `+0x548` | **High** | image + missionState |
| Readiness gates G1–G4 | **High** | dual A/B |
| `FUN_0052a020` semantics | **High** CF / **Tentative** name | live decompile |
| Overall static | **High** | dual sealed 2026-07-29 |

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_0052b420_FUN_0052b420.md` |
| Annotated | `raw/aa_0052b420_FUN_0052b420.annotated.md` |
| Clean | `reconstructed-exact/CVOGCharacter_IsMissionTurnInReady.cpp` |
| Dual A | `reviews/A_aa_0052b420_CVOGCharacter_IsMissionTurnInReady.md` |
| Dual B | `reviews/B_aa_0052b420_CVOGCharacter_IsMissionTurnInReady.md` |
| Primary consumer | `reviews/A_aa_009438f0_Client_ShowNpcMissionDialogUI.md` |

## Open questions

- Product name for `FUN_0052a020`.
- Full evaluator type enum beyond type 3.
- Runtime / image diff verification.
