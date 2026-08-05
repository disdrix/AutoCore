# Review A (reconstruction fidelity): `aa_00826860` UI_QuickBarSlotButton_AssignSkill_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00826860` |
| **VA** | `0x00826860` |
| **Body** | `0x00826860`–`0x00826ad9` (0x27A bytes) |
| **Canonical name** | `UI_QuickBarSlotButton_AssignSkill_Inferred` |
| **Prior scaffold** | `FUN_00826860` |
| **Review date** | `2026-07-29` (W23-D dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00826860_UI_QuickBarSlotButton_AssignSkill_Inferred.md` |
| **System** | client UI / quickbar / skills-abilities |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Bind a **skill object** onto a QuickBar **slot-button**, update local character QB arrays (clear item COID, set skill id), rebuild the skill icon texture path, and refresh related chrome widgets.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00826860` |
| Bytes | `read_memory` entry + call sites + strings |
| Bounds | `get_function_by_address` body `00826860`–`00826ad9` |
| Callees | `get_function_callees` → SetQuickBarItem/Skill, SetSelected |
| Callers | xrefs → `FUN_008a0e10` + four UI sites |
| Nested peer | sealed `UI_QuickBarSlotButton_SetSelected`, `CVOGCharacter_SetQuickBarSkill` |
| Raw / clean | `aa_00826860_*`, named clean cpp |

**Not performed:** Launcher, runtime, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Null skill → return 0, `ret 4` | **Confirmed** | prolog/epilog bytes |
| Skill in EAX, button stack | **Confirmed** | `mov esi,eax`; `mov ebp,[esp+…]` |
| `payloadKind` @ +0x548 set to 1 | **Confirmed** | cmp/store path |
| Slot = page*10+col | **Confirmed** | `lea` page*5*2 + col |
| SetQuickBarItem then SetQuickBarSkill | **Confirmed** | rel32 → `00520890` / `005208c0` |
| Same-bind skip clear-select | **Confirmed** | kind==1 && pSkill==skill |
| Icon prefix string | **Confirmed** | `i_d_s_2d_wnd_icon_` @ `00a540d0` |
| Product English name | **Inferred** | role-sealed AssignSkill |
| Widget vtbl English | **Inferred** | call-order only |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null reject | Yes |
| Cache id/ptr/kind/slot | Yes |
| Character item clear + skill set | Yes |
| Optional SetSelected(0) | Yes |
| Icon path rebuild | Yes (string family) |
| Return 1 | Yes |

---

## 5. Gaps / open

1. Product plate spelling of the method.
2. Full icon/chrome vtbl English.
3. Whether callers send `QuickBarUpdate` C2S (outside this VA).
4. Runtime / bit-exact / differential.

**Verdict:** **accept**
