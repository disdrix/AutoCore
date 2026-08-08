# Review A (reconstruction fidelity): `aa_00522950` Item_PatenteeMatchesCharacterOrEmpty_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00522950` |
| **VA** | `0x00522950`–`0x005229b1` inclusive (**98 B** / `0x62`) |
| **Canonical name** | `Item_PatenteeMatchesCharacterOrEmpty_Inferred` |
| **Ghidra name** | `FUN_00522950` |
| **Prior scaffold** | `Named_CalleeOf_Mission_Mission_Object_00522950` — **retired** |
| **Rejected misname** | Mission_Mission_Object callee; UI_ItemHover_FormatCraftStatus (host, not this VA) |
| **Review date** | `2026-08-05` (MEGA-108 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00522950_Item_PatenteeMatchesCharacterOrEmpty_Inferred.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_function_xrefs` / `get_xrefs_to` + `read_memory` + `get_function_by_address` + caller decompile/disasm + `list_strings`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Leaf **patentee-name predicate** for Reverse Engineer gates:

```text
Item_PatenteeMatchesCharacterOrEmpty_Inferred(character, item) -> bool
  if item == null: return false
  if item.patentedBy[+0x101] empty: return true
  return _stricmp(patentedBy, character.vtbl+0x160()) == 0
```

Parents on fail show `"Cannot be Reverse Engineered."` (tooltip / toast). Sibling detail UI labels `item+0x101` as **`"Patented By: "`**.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ scaffold CF (null / strlen / MI call / stricmp / 0|1) |
| Full body | `disassemble_function` + `read_memory` **98 B** |
| Bounds | `get_function_by_address` → `00522950`–`005229b1` |
| Callers | 4 UNCONDITIONAL_CALL sealed |
| Callee | `_stricmp` IAT `0x009c6678` |
| UI field | `"Patented By: "` @ `0x00a698a8` in `FUN_00847240` |
| Parent dual | `Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred` (`0x0085ce20`) |

---

## 3. Signature (sealed)

```c
// ECX=character; stack item*; AL bool; RET 4
bool __thiscall Item_PatenteeMatchesCharacterOrEmpty_Inferred(
    Character *character,
    Item *item);
```

| Formal | Source | Conf |
|---|---|---|
| character | ECX — `DAT_00d1b6d8` / `[obj+0xe98]` / EDI at call sites | **Confirmed** |
| item | stack `[ESP+4]` after entry; PUSH before CALL | **Confirmed** |
| return | AL 0/1 (`xor al,al` / `mov al,1`) | **Confirmed** |
| cleanup | `RET 4` (`C2 04 00`) ×3 | **Confirmed** |
| stricmp | `CALL [0x009c6678]` + `ADD ESP,8` | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Null item → false | bytes `TEST EAX; JNZ; XOR AL; RET 4` | **Confirmed** |
| Scan `item+0x101` to NUL | `LEA ESI,[EAX+0x101]` + loop | **Confirmed** |
| Empty → true (skip compare) | `SUB EAX,EDI; JZ success` | **Confirmed** |
| MI this-adjust + `CALL [eax+0x160]` | `8B 41 04 … FF 90 60 01 00 00` | **Confirmed** |
| `_stricmp(patentee, name)` | push/push/IAT/add esp,8 | **Confirmed** |
| mismatch → false / match → true | dual epilogues | **Confirmed** |
| No other callees | leaf vs CRT | **Confirmed** |

**Result:** Clean CF ≡ raw ≡ live Ghidra.

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| External callers | **4** UNCONDITIONAL_CALL |
| Site role | RE eligibility / item-hover craft status helper |
| Callees | `_stricmp`; virtual +0x160 |
| Partition host | `0x0085ce20` ItemHover RE/tinker/gadget (not dualled here beyond evidence) |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| `"Patented By: "` + same `+0x101` field | **Yes** |
| RE fail strings on false | **Yes** |
| Character this (not item this) | **Yes** |
| Empty-or-match semantics | **Yes** |
| PDB / product symbol | **No** → `_Inferred` |
| Mission_Mission_Object caller | **No** — scaffold falsified |

---

## 7. Gaps

1. Product English for character vtbl+0x160 (GetName-class).
2. Full MI / vbtable type names for Character secondary base.
3. Product name of this helper (no PDB).
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
