# Review A (reconstruction fidelity): `aa_008285a0` UI_QuickBarSlotButton_AssignItemObject_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008285a0` |
| **VA** | `0x008285a0` |
| **Body** | `0x008285a0`–`0x00828756` (`0x1B7` bytes) |
| **Canonical name** | `UI_QuickBarSlotButton_AssignItemObject_Inferred` |
| **Prior scaffold** | `FUN_008285a0` |
| **Review date** | `2026-08-05` (R11-026 dual seal) |
| **Reviewer role** | Independent reconstruction review (Path A fidelity) |
| **Counterpart** | `reviews/B_aa_008285a0_UI_QuickBarSlotButton_AssignItemObject_Inferred.md` |
| **System** | skills-abilities / client UI quickbar |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Bind a live **item object** onto a QuickBar **slot-button**, update local character QB arrays (set item id from `*(item+0xa8)+0x34`, clear skill), rebuild inventory icon path from the object, and refresh chrome widgets.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x008285a0` |
| Bytes / ABI | `disassemble_function` + `read_memory` entry/epilog/call sites |
| Bounds | `get_function_by_address` body `008285a0`–`00828756` |
| Callees | SetQuickBarItem/Skill, SetSelected, FUN_0085d970 |
| Callers | xrefs `0x00828b00`, `0x00828ef8` |
| Nested peers | dualed AssignItem `0x008283a0`, AssignSkill `0x00826860`, SetSelected `0x00826780` |
| Raw / clean | `aa_008285a0_*`, named clean cpp |

**Not performed:** Launcher, runtime, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Null item → return 0, plain `ret` | **High** | prolog/epilog bytes `C3` |
| Item in EAX, button in ESI | **High** | `MOV EDI,EAX`; ESI never stack-loaded |
| `payloadKind` @ +0x548 set to 2 | **High** | `MOV [ESI+0x548],2` |
| Id from `*( *(item+0xa8)+0x34 )` + cdq | **High** | disasm; clonebase id pattern |
| Slot = page*10+col | **High** | lea/imul path matches siblings |
| SetQuickBarItem then SetQuickBarSkill(−1) | **High** | rel32 → `00520890` / `005208c0` |
| Same-bind skip clear-select | **High** | kind==2 && id match |
| Icon via FUN_0085d970(item,path) not GiveItemByCbid | **High** | disasm push order; contrast twin |
| DAT_00afdf0c color block | **High** | `read_memory` ffffffff / 3f800000 |
| Product English name | **Inferred** | role-sealed AssignItemObject |
| Widget vtbl English | **Inferred** | call-order only |
| `item+0xa8` = clonebase* product name | **Probable** | cross-unit pattern |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null reject return 0 | Yes |
| Same-bind flag | Yes |
| Cache id/kind/slot/pSkill=0 | Yes |
| Character item set + skill clear | Yes |
| Optional SetSelected(0) | Yes |
| Icon via object path helper | Yes |
| Chrome + button vtbl+0x448 | Yes |
| Return 1 | Yes |

---

## 5. Gaps / open

1. Product plate spelling of the method.
2. Exact item-object class / `+0xa8` English.
3. `char+0xcd0` producer at site `0x00828b00`.
4. Full `FUN_0085d970` dual.
5. Whether callers send QuickBarUpdate C2S.
6. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
