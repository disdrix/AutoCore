# Dual A/B report — W20-F OWN-ONLY (`0x008a8770`, `0x008be900`)

**Date:** 2026-07-29  
**Scope:** OWN ONLY VAs `0x008a8770`, `0x008be900`. Dual A/B + artifacts.  
**Agent:** W20-F  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledgers.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory`. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdicts

| Unit | Canonical name | Verdict |
|------|----------------|---------|
| `aa_008a8770` / `0x008a8770` | `Client_MissionTrackerHud_Refresh_Inferred` | **accept-with-gaps** |
| `aa_008be900` / `0x008be900` | `UI_InventoryPanel_MessageHandler_Inferred` | **accept-with-gaps** |

---

## Sealed facts — `0x008a8770` Client_MissionTrackerHud_Refresh_Inferred

1. **ABI:** `__thiscall`/`__fastcall` — **host in ECX** (`mov esi,ecx`); **no stack args**; epilogue **`ret`** (`C3`).
2. **Body:** `0x008a8770`–`0x008a9618` (**3752** bytes / `0xEA8`).
3. **Gates:** `DAT_00d1b6d8==0`; `byte[client+0x4f1]!=0`; missing host widgets dword indices **`[0x1a2]`/`[0x1a5]`/`[0x1a4]`** (byte offs **0x688 / 0x694 / 0x690**).
4. **Role:** Mission-tracker **HUD chrome refresh** — title / instruction / icon materials / optional range string. **No** sector packet builders.
5. **Title arm:** tracker `DAT_00d1ad10` key `+0x10`; mission hash `client+0x548`; strings `"No Objective"` / `"Next mission"` / contact path; objective types 3/6 scan.
6. **Instruction arm** when `FUN_0092c810()<1`: `"Look in your Mission Inventory"` / `"Read mission journal for details"` / `"Go to %s"`; uses `FUN_0052b420`, `FUN_005710c0`.
7. **Range arm** when `FUN_0092c810()>=1`: `Client_EvalAutoPatrolWaypoint` + distance (metric/imperial) + MatDiffuse/Ambient/Emissive.
8. **Name:** `Client_MissionTrackerHud_Refresh_Inferred` — role High. **Reject** sole name `Mission_Look_in_your_Mission_Inventory` (one branch). Ghidra `FUN_008a8770`.
9. **Xrefs:** DATA `0x00a4b55c` only (no CODE callers).

### Gaps (`008a8770`)

1. Product host class / method English.  
2. `FUN_0092c810` product meaning.  
3. Owner of DATA slot `0x00a4b55c`.  
4. Runtime / bit-exact / differential — open.

---

## Sealed facts — `0x008be900` UI_InventoryPanel_MessageHandler_Inferred

1. **ABI:** `__thiscall` — **ECX=this**; stack **`(int msg, int controlId)`**; epilogue **`ret 8`** (`C2 08 00`).
2. **Body:** `0x008be900`–`0x008beb13` (**531** bytes / `0x213`).
3. **Slot band:** exclusive `0x9c42 < controlId < 0x9c47` ⇒ ids **`0x9c43..0x9c46`**; index `controlId-0x9c43`; widgets **`this+0x55c[slot]`**.
4. **msg 5:** dual widget rects → `FUN_007fd420` → return 1.  
5. **msg 6:** `DAT_00d1d8f4=1`, `DAT_00d1d8f5=0`; hide `DAT_00d1d8dc` → return 1.  
6. **msg 0xe:** `Client_UseInventoryItem_Inferred(1)` / `FUN_00941d50(1)`; on fail → `Client_SendUseObject_IfInteractable` → return 1.  
7. **control `0x9c40` (40000) + msg 8:** `FUN_007fca10` leave; **falls through** to default (not return-1).  
8. **control `0x9c41` + msg 8:** return 1 (swallow).  
9. **control `0x9c42` + msg `0x1a`:** scroll index via size-4 and scrollbar fraction; `FUN_008bda60` on change; bias float **`2^32`** @ `0x00aaa5dc`.  
10. **Default:** `UI_DefaultMessageHandler` / `FUN_0087b500(msg, controlId)`.  
11. **Name:** `UI_InventoryPanel_MessageHandler_Inferred` — role High; class English open. Ghidra `FUN_008be900`.  
12. **Xrefs:** DATA `0x00a457a4` only.

### Gaps (`008be900`)

1. Product panel class English.  
2. Product lexicon for msg codes `5`/`6`/`0xe`/`8`/`0x1a`.  
3. Item register setup before msg `0xe` use path.  
4. Owner of DATA slot `0x00a457a4`.  
5. Runtime / bit-exact — open.

---

## Dual A/B

| VA | Review A | Review B | Verdict |
|---|---|---|---|
| `0x008a8770` | `reviews/A_aa_008a8770_Client_MissionTrackerHud_Refresh_Inferred.md` | `reviews/B_aa_008a8770_Client_MissionTrackerHud_Refresh_Inferred.md` | **accept-with-gaps** |
| `0x008be900` | `reviews/A_aa_008be900_UI_InventoryPanel_MessageHandler_Inferred.md` | `reviews/B_aa_008be900_UI_InventoryPanel_MessageHandler_Inferred.md` | **accept-with-gaps** |

---

## Files

### `aa_008a8770` / `Client_MissionTrackerHud_Refresh_Inferred`

| Kind | Path |
|------|------|
| Review A | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\A_aa_008a8770_Client_MissionTrackerHud_Refresh_Inferred.md` |
| Review B | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\B_aa_008a8770_Client_MissionTrackerHud_Refresh_Inferred.md` |
| Function record | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_008a8770_Client_MissionTrackerHud_Refresh_Inferred.md` |
| Function alias | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_008a8770_FUN_008a8770.md` |
| Clean named | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\Client_MissionTrackerHud_Refresh_Inferred.cpp` |
| Clean FUN_* | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\FUN_008a8770.cpp` |
| String-alias note | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\Mission_Look_in_your_Mission_Inventory_008a8770.cpp` |
| Raw | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_008a8770_FUN_008a8770.md` |
| Annotated | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_008a8770_FUN_008a8770.annotated.md` |

### `aa_008be900` / `UI_InventoryPanel_MessageHandler_Inferred`

| Kind | Path |
|------|------|
| Review A | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\A_aa_008be900_UI_InventoryPanel_MessageHandler_Inferred.md` |
| Review B | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\B_aa_008be900_UI_InventoryPanel_MessageHandler_Inferred.md` |
| Function record | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_008be900_UI_InventoryPanel_MessageHandler_Inferred.md` |
| Function alias | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_008be900_FUN_008be900.md` |
| Clean named | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\UI_InventoryPanel_MessageHandler_Inferred.cpp` |
| Clean FUN_* | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\FUN_008be900.cpp` |
| Raw | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_008be900_FUN_008be900.md` |
| Annotated | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_008be900_FUN_008be900.annotated.md` |

### This report

`C:\Users\josh\Documents\GitHub\AutoCore\docs\agents\task-dual-ab-own-w20f-008a8770-008be900-report.md`

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x0087b500` | `UI_DefaultMessageHandler` — default fallthrough of `008be900` |
| `0x00941d50` | `Client_UseInventoryItem_Inferred` — msg `0xe` callee (C2S 0x2045 arm dual-sealed) |
| `0x00930d70` | `Client_SendUseObject_IfInteractable` — msg `0xe` fallback |
| `0x007fca10` | Leave dialog host (close path) |
| `0x00870e15` | `UI_Case_CloseBtn_9c40` — peer close case (different return shape) |
| `0x0052b420` | `CVOGCharacter_IsMissionTurnInReady` — journal branch gate in `008a8770` |
| `0x00929ec0` | `Client_EvalAutoPatrolWaypoint` — range arm |
| `0x008a8040` / `0x008a8660` | Title/contact helpers (siblings of tracker HUD) |

---

## AutoCore impact

- **`Client_MissionTrackerHud_Refresh_Inferred`:** client presentation only. Server owns objective state; do **not** port as authority. Instruction strings are UI hints.
- **`UI_InventoryPanel_MessageHandler_Inferred`:** client UI dispatch only. Real wire effects are in sealed callees (`0x2045` use item / UseObject). Do **not** assume msg `0xe` always emits a packet. Close path fallthrough differs from `UI_Case_CloseBtn_9c40` (no early return 1 after leave).
