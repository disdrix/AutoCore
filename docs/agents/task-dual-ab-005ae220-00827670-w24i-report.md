# Dual A/B report — W24-I OWN-ONLY (`0x005ae220`, `0x00827670`)

**Date:** 2026-07-29  
**Agent:** W24-I OWN-ONLY  
**Scope:** OWN ONLY VAs `0x005ae220`, `0x00827670`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / xrefs / complete analysis). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_005ae220` StdTree_Buynode_Val12 | **accept** — **0x1c tree node buy; ret 0x14; Val12 + color/isnil sealed** |
| `aa_00827670` UI_QuickBarSlotButton_AssignItemOrMacro_Inferred | **accept** — **ESI button / EAX kind / stack id; item set + skill clear; kinds 3/4/5 chrome** |

---

## `aa_005ae220` — StdTree_Buynode_Val12

### Sealed facts

1. **Body:** `0x005ae220`–`0x005ae268` exclusive (**72** B / `0x48`). Final **`c2 14 00`** (`ret 0x14`); following `cc` pad.

2. **ABI:** five stack args (left, parent, right, `value*`, color); **stdcall-like** clean 20 B. **Return in EAX** = node* or null (decompiler `void` is wrong).

3. **Algorithm:**
   ```
   node = operator_new(0x1c)
   if !node: return 0
   node.left/parent/right = args
   copy value[0..2] → +0x0c
   color → +0x18; isnil = 0 @ +0x19
   return node
   ```

4. **Callees:** `operator_new` only.

5. **Callers (6):** `FUN_0051c1c0` (category-cooldown insert+rebalance), `FUN_00539210`, `FUN_00567450`, `FUN_00573510`, `FUN_005ae4e0`, `FUN_005e13b0`.

6. **Twin:** `FUN_005ae1c0` — same CF with `operator_new(0x24)` / 5-dword value. **Do not merge.**

7. **Name:** structural `StdTree_Buynode_Val12`. Auto-seed `Named_CalleeOf_…CategoryCooldownMap_Insert` is **narrow** (shared helper).

### Gaps

1. Product/MSVC demangle per map instantiation.  
2. Runtime OOM / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_005ae220_StdTree_Buynode_Val12.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_005ae220_StdTree_Buynode_Val12.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005ae220_StdTree_Buynode_Val12.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005ae220_StdTree_Buynode_Val12.md` |
| Function record | `docs/reconstruction/functions/aa_005ae220_StdTree_Buynode_Val12.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_005ae220_FUN_005ae220.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Buynode_Val12.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_005ae220.cpp` |
| Legacy alias clean | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Skill_CategoryCooldownMap_Insert_005ae220.cpp` |
| Raw | `docs/reconstruction/raw/aa_005ae220_FUN_005ae220.md` |
| Annotated | `docs/reconstruction/raw/aa_005ae220_FUN_005ae220.annotated.md` |

---

## `aa_00827670` — UI_QuickBarSlotButton_AssignItemOrMacro_Inferred

### Sealed facts

1. **Body:** `0x00827670`–`0x00827918` exclusive (**680** B / `0x2A8`). Final **`c2 04 00`** (`ret 4`); epilogue **`mov al,1`**.

2. **ABI:** **ESI** = slot-button*; **EAX** = kind; stack = **id** (int32, `cdq` to 64-bit). **Not** ECX thiscall. Distinct from skill twin ABI.

3. **Exclusive character mirror:** `SetQuickBarItem(DAT_00d1b6d8, page*10+col, idLo, idHi)` then `SetQuickBarSkill(..., −1)`.

4. **Same-bind gate:** kind + id64 match → skip selection clear.

5. **Kind chrome:**
   | Kind | Labels / icon |
   |---|---|
   | 3 | `"Power"` |
   | 4 | `"Battle"` |
   | 5 | `"i_d_macro_2d_wnd_icon.dds"` + `sprintf("(%d)", id+0xbb9)` + `FUN_008264f0` |

6. **Callees:** `CVOGCharacter_SetQuickBarItem`, `CVOGCharacter_SetQuickBarSkill`, `FUN_00826780` (SetSelected), `FUN_008264f0`, `sprintf`, icon vtbls.

7. **Callers:** rebind `FUN_008a0e10` (table type **5**, forces EAX=5); four sites in `0x00828cbb`…`0x00829000`.

8. **Name:** `UI_QuickBarSlotButton_AssignItemOrMacro_Inferred`. Legacy CreateCharacter seed is **indirect only**.

### Gaps

1. Product English method name.  
2. Whether kinds 3/4 are live from any current caller (body yes; sealed sites use 5).  
3. Display bias `id+0xbb9` product meaning.  
4. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00827670_UI_QuickBarSlotButton_AssignItemOrMacro_Inferred.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00827670_UI_QuickBarSlotButton_AssignItemOrMacro_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00827670_UI_QuickBarSlotButton_AssignItemOrMacro_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00827670_UI_QuickBarSlotButton_AssignItemOrMacro_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00827670_UI_QuickBarSlotButton_AssignItemOrMacro_Inferred.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_00827670_FUN_00827670.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_QuickBarSlotButton_AssignItemOrMacro_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00827670.cpp` |
| Legacy alias clean | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Client_RecvCreateCharacter_00827670.cpp` |
| Raw | `docs/reconstruction/raw/aa_00827670_FUN_00827670.md` |
| Annotated | `docs/reconstruction/raw/aa_00827670_FUN_00827670.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### StdTree_Buynode_Val12 (`0x005ae220`)

- Port as **generic 12-byte-value RB node allocator**, not a cooldown-only ctor.
- Node size **0x1c**; color @ +0x18; isnil forced **0**.
- Preserve **null return** on alloc fail; **ret 0x14** ABI if matching retail call sites.
- Do not substitute twin `FUN_005ae1c0` (0x24 / Val20).

### UI_QuickBarSlotButton_AssignItemOrMacro_Inferred (`0x00827670`)

- **Client UI only** — do not put in sector sim.
- Exclusive slot policy: **item/macro id set, skill cleared** (inverse of skill assign `0x00826860`).
- Flat index **`page * 10 + column`** (matches 100-slot CreateCharacter layout).
- Rebind table type **5** → this unit with kind **5**; type **1** skill / type **2** item-object are siblings.
- Server already models exclusive slots via `QuickBarUpdate` / `CharacterSkillService.TryUpdateQuickBar`; this unit is local apply + chrome.

---

## This report

`docs/agents/task-dual-ab-005ae220-00827670-w24i-report.md`
