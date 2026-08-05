# Function record: CVOGCharacter_IsMissionJournalReady

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052b3b0` |
| **Canonical name** | `CVOGCharacter_IsMissionJournalReady` |
| **Ghidra name** | `FUN_0052b3b0` |
| **Address** | `0x0052b3b0` |
| **Body** | `0x0052b3b0`–`0x0052b412` (then `CC` pad; sibling starts `0x0052b420`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` |
| **Calling convention** | MSVC `__thiscall` (ECX=character; 1 stack arg; `ret 4`) |
| **Completion status** | **Sealed** — dual A/B 2026-07-29; last-obj + active-hash + mode-0 gates High |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_0052b3b0`
- `Named_CalleeOf_Named_CalleeOf_Client_UpdateMissionJournal_0052b3b0` (legacy scaffold name)
- Journal readiness sibling (mode 0) of `CVOGCharacter_IsMissionTurnInReady` (`aa_0052b420`)

## Purpose

Return whether the character may treat `mission` as **journal-complete / ready** for UI chrome: last objective is active on the character and passes **mode-0** objective readiness (`FUN_0052a020(..., 0)`). Does **not** apply the turn-in NPC type-3 filter and does **not** use pending-aware (mode 1) evaluators.

## Signature

```c
bool __thiscall CVOGCharacter_IsMissionJournalReady(
    void* this /* CVOGCharacter* */,
    void* missionDef);
```

## Behavioral summary (sealed)

1. **Last objective:** `lastObj = *( *(mission+0x13c) + (uint8)*(mission+0x130)*4 - 4 )`.
2. **Active hash:** bucket-walk `*(this+0x548)` by key `*(lastObj+0x10)`; require node and `*(node+0x8) != 0`.
3. **Ready:** `FUN_0052a020(this, lastObj, 0)` must return true (flag 0 → evaluator `vtbl+0xc`).
4. Else true. **No NPC filter. No memory stores.**

## Contrast (mode 1 turn-in)

| | Journal `0x0052b3b0` | Turn-in `0x0052b420` |
|---|---|---|
| Stack | mission only (`ret 4`) | mission + npcOpt (`ret 8`) |
| `FUN_0052a020` flag | **0** | **1** |
| NPC type-3 gate | no | yes (if npc≠0) |

## Callers / callees

| Direction | Address / name | Role |
|---|---|---|
| Caller | `FUN_008a2020` `0x008a2020` | null-safe wrapper (`DAT_00d1b6d8`); mission detail panel |
| Caller | `FUN_0082a050` `0x0082a050` | journal selection UI → label `"(Complete)"` |
| Caller | `FUN_00829b20` `0x00829b20` | journal list helper (UpdateMissionJournal family) |
| Callee | `FUN_0052a020` `0x0052a020` | last-objective ready eval (mode 0) |

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Function boundary | **High** | image + pad before `0x0052b420` |
| Signature / thiscall | **High** | ECX+0x548; `ret 4`; 3 call sites |
| Last-objective formula | **High** | sealed LEA (shared with turn-in) |
| Active hash `+0x548` | **High** | image + missionState |
| Mode-0 gate | **High** | dual A/B + `push 0` |
| Distinct from turn-in | **High** | arity / flag / no NPC |
| Overall static | **High** | dual sealed 2026-07-29 |

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_0052b3b0_FUN_0052b3b0.md` |
| Annotated | `raw/aa_0052b3b0_FUN_0052b3b0.annotated.md` |
| Clean | `reconstructed-exact/CVOGCharacter_IsMissionJournalReady.cpp` |
| Dual A | `reviews/A_aa_0052b3b0_CVOGCharacter_IsMissionJournalReady.md` |
| Dual B | `reviews/B_aa_0052b3b0_CVOGCharacter_IsMissionJournalReady.md` |
| Sibling turn-in | `reviews/A_aa_0052b420_CVOGCharacter_IsMissionTurnInReady.md` |
| Mode owner | `reviews/A_aa_0052a020_CVOGCharacter_IsObjectiveReady.md` |

## Open questions

- Retail product symbol.
- Product names for journal UI callers.
- Runtime divergence mode 0 vs mode 1 / wrong-NPC turn-in.
