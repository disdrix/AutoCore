# Review A (reconstruction fidelity): `aa_008283a0` UI_QuickBarSlotButton_AssignItem_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008283a0` |
| **VA** | `0x008283a0` |
| **Body** | `0x008283a0`–`0x0082859e` (0x1FE bytes) |
| **Canonical name** | `UI_QuickBarSlotButton_AssignItem_Inferred` |
| **Prior scaffold** | `FUN_008283a0` |
| **Review date** | `2026-07-29` (W24-J dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008283a0_UI_QuickBarSlotButton_AssignItem_Inferred.md` |
| **System** | client UI / quickbar / inventory-items |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Bind an **item id** onto a QuickBar **slot-button**, update local character QB arrays (set item COID, clear skill), rebuild icon via clonebase factory, and refresh related chrome widgets.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x008283a0` |
| Bytes | `read_memory` entry + call sites + epilog |
| Bounds | `get_function_by_address` body `008283a0`–`0082859e` |
| Callees | `get_function_callees` → SetQuickBarItem/Skill, ClearActiveSlot, GiveItemByCbid, SetSelected |
| Callers | xrefs → `FUN_008a0e10` + two UI sites |
| Nested peer | sealed skill twin `UI_QuickBarSlotButton_AssignSkill_Inferred` @ `0x00826860` |
| Raw / clean | `aa_008283a0_*`, named clean cpp |

**Not performed:** Launcher, runtime, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| itemId == -1 → ClearActiveSlot, return 1, plain ret | **Confirmed** | prolog/epilog bytes |
| Button in EAX, itemId in ECX | **Confirmed** | `mov esi,eax`; `cmp ecx,-1` |
| `payloadKind` @ +0x548 set to 2 | **Confirmed** | `mov edi,2` / store |
| Slot = page*10+col | **Confirmed** | lea / imul 10 path |
| SetQuickBarItem then SetQuickBarSkill(-1) | **Confirmed** | rel32 → `00520890` / `005208c0` |
| Same-bind skip clear-select | **Confirmed** | kind==2 && id match |
| GiveItemByCbid icon path | **Confirmed** | rel32 → `0051a170` |
| Product English name | **Inferred** | role-sealed AssignItem |
| Item id CBID vs COID domain | **Probable** | lo half to GiveItemByCbid |
| Widget vtbl English | **Inferred** | call-order only |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| -1 clear path | Yes |
| Cache id/kind/slot/pSkill=0 | Yes |
| Character item set + skill clear | Yes |
| Optional SetSelected(0) | Yes |
| Icon via GiveItemByCbid | Yes |
| Return 1 | Yes |

---

## 5. Gaps / open

1. Product plate spelling of the method.
2. Exact item-id domain (template CBID vs instance COID).
3. Full icon path extract (`FUN_0085d970`) dual.
4. Whether callers send `QuickBarUpdate` C2S (outside this VA).
5. Runtime / bit-exact / differential.

**Verdict:** **accept**
