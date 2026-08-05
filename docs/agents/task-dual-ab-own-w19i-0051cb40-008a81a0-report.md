# Dual A/B report — W19-I OWN (`aa_0051cb40`, `aa_008a81a0`)

**Date:** 2026-07-29  
**Scope:** OWN ONLY VAs `0x0051cb40`, `0x008a81a0`. Dual A/B + artifacts.  
**Agent:** W19-I  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledgers.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ xrefs / callees / strings). No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdicts

| Unit | Canonical name | Verdict |
|------|----------------|---------|
| `aa_0051cb40` / `0x0051cb40` | `Map_EraseNode` | **accept-with-gaps** |
| `aa_008a81a0` / `0x008a81a0` | `Client_InteractPrompt_SetTarget_Inferred` | **accept-with-gaps** |

---

## Sealed facts — `0x0051cb40` Map_EraseNode

1. **ABI:** `__thiscall` — **map in ECX**; stack `(void **pOutIt, node *pNode)`; **`ret 8`**.
2. **Body:** `0x0051cb40`–`0x0051cdf5` (**694 bytes**). Ghidra plate end `0x0051cdc6` **superseded** (false noreturn on `operator_delete`).
3. **Identity:** MSVC map/set erase — throw **`"invalid map/set<T> iterator"`** @ `0x00a152f0` when isnil `@node+0x29`.
4. **Layout:** map `head@+4`, `size@+8`; node `left/parent/right`, `key@+0x10`, `color@+0x28`, `isnil@+0x29`.
5. **CF:** successor (`FUN_004cb270`) → unlink → RB rebalance (`FUN_004192a0`/`FUN_004192f0`) → `operator_delete` → **size-- if >0** → `*pOutIt = successor` → ret 8.
6. **Family:** same node schema as `Map_ExactFindByIntKey` (`0x0051c150`). Distinct from `Map_EraseNode_IntKey` (`0x005d1df0`, isnil@+0x15).
7. **Name:** `Map_EraseNode` — structural. Ghidra `FUN_0051cb40`. Reject chain alias Named_CalleeOf_*.
8. **Callers:** `Skill_ClearCastBindingAndMaybeRestartCd`, `FUN_0051c7c0`, `FUN_0051d880`, `CVOGHBAIBase_GetTargetFromAggro`.

### Gaps (`0051cb40`)

1. Product/PDB symbol.  
2. Per-caller value payload English.  
3. Runtime / bit-exact / differential — open.

---

## Sealed facts — `0x008a81a0` Client_InteractPrompt_SetTarget_Inferred

1. **ABI:** stack **promptHost***; target in **ESI** (caller convention); **`ret 4`**.
2. **Body:** `0x008a81a0`–`0x008a856e` (**974 bytes**).
3. **Gates:** same target `@host+0x50c` → ret; no `DAT_00d1b6d8` → ret; no widget `@host+0x68c` → ret.
4. **CF:** classify ESI → talk (`type 0x12` + `FUN_008a8140`) / pick up (`FUN_005130e0`) / trade (`vtbl+0x210` + faction) / interact (`flag` or `FUN_00524520`) → sprintf `Press <key> to …` → cache `@+0x50c` → widget `vtbl+0x1d8` text + `vtbl+0xfc(show, 0.5f)`.
5. **Not** UseObject send — chrome only.
6. **Name:** `Client_InteractPrompt_SetTarget_Inferred` — role High; product English open. Ghidra `FUN_008a81a0`.
7. **Callers:** `Client_RefreshInteractPromptTarget_Inferred` / `FUN_009210e0` @ `0x0092134a` (`DAT_00d1b8c8`); CODE `0x009254ae` (null-ESI clear; container undefined).

### Gaps (`008a81a0`)

1. Product host class / method English.  
2. `FUN_008a8140` full talkable schema (sibling).  
3. Function containing `0x009254ae`.  
4. Runtime / bit-exact / differential — open.

---

## Dual A/B

| VA | Review A | Review B | Verdict |
|---|---|---|---|
| `0x0051cb40` | `reviews/A_aa_0051cb40_Map_EraseNode.md` | `reviews/B_aa_0051cb40_Map_EraseNode.md` | **accept-with-gaps** |
| `0x008a81a0` | `reviews/A_aa_008a81a0_Client_InteractPrompt_SetTarget_Inferred.md` | `reviews/B_aa_008a81a0_Client_InteractPrompt_SetTarget_Inferred.md` | **accept-with-gaps** |

---

## Files

### `aa_0051cb40` / `Map_EraseNode`

| Kind | Path |
|------|------|
| Review A | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\A_aa_0051cb40_Map_EraseNode.md` |
| Review B | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\B_aa_0051cb40_Map_EraseNode.md` |
| Function record | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_0051cb40_Map_EraseNode.md` |
| Function alias | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_0051cb40_FUN_0051cb40.md` |
| Clean named | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\Map_EraseNode.cpp` |
| Clean FUN_* | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\FUN_0051cb40.cpp` |
| Raw | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_0051cb40_FUN_0051cb40.md` |
| Annotated | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_0051cb40_FUN_0051cb40.annotated.md` |

### `aa_008a81a0` / `Client_InteractPrompt_SetTarget_Inferred`

| Kind | Path |
|------|------|
| Review A | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\A_aa_008a81a0_Client_InteractPrompt_SetTarget_Inferred.md` |
| Review B | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\B_aa_008a81a0_Client_InteractPrompt_SetTarget_Inferred.md` |
| Function record | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_008a81a0_Client_InteractPrompt_SetTarget_Inferred.md` |
| Function alias | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_008a81a0_FUN_008a81a0.md` |
| Clean named | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\Client_InteractPrompt_SetTarget_Inferred.cpp` |
| Clean FUN_* | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\FUN_008a81a0.cpp` |
| Raw | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_008a81a0_FUN_008a81a0.md` |
| Annotated | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_008a81a0_FUN_008a81a0.annotated.md` |

### This report

`C:\Users\josh\Documents\GitHub\AutoCore\docs\agents\task-dual-ab-own-w19i-0051cb40-008a81a0-report.md`

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x0051c150` | `Map_ExactFindByIntKey` (find pair for cast map) |
| `0x0051c7c0` / `0x0051d880` | range erase wrappers calling erase-node |
| `0x004cb270` | tree successor (isnil@+0x29) |
| `0x0051a700` | `Skill_ClearCastBindingAndMaybeRestartCd` (caller) |
| `0x009210e0` | `Client_RefreshInteractPromptTarget_Inferred` (caller of 008a81a0) |
| `0x008a8140` | talkable gate |
| `0x00524520` | `CVOGCharacter_FindActiveObjectiveIdForInteract` |
| `0x005130e0` | pick-up gate |

---

## AutoCore impact

- **`Map_EraseNode`:** client STL helper. Ports use standard `map::erase(iterator)` / container erase — preserve successor return + size. Do **not** omit post-delete size publish (decomp trap).
- **`Client_InteractPrompt_SetTarget_Inferred`:** client UI chrome only. Server has no equivalent prompt host. Preserve verb classification order if reimplementing client assist UI; do **not** treat as UseObject wire.
