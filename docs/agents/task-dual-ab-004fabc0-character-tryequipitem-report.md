# Dual A/B report — `aa_004fabc0` Character_TryEquipItem (Broken→**9**, flag **`|0x10`**)

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W17-E  
**Scope:** OWN ONLY VA `0x004fabc0`. Dual A/B + artifacts. Seal equip gates + type switch.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` only (no `disassemble_bytes`).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004fabc0` Character_TryEquipItem | **accept-with-gaps** — **Broken→9**, **`item+0x17c\|=0x10`**, type map **sealed** |

---

## Sealed facts

1. **ABI:** `__thiscall` — **ECX** = host; stack **item***, optional **out***; **`ret 8`**.  
   Boundary: `0x004fabc0` … `0x004fad57`.

2. **On non-null item:** always **`item+0x17c |= 0x10`** then **`FUN_00512670`** (`| 0x20000` self + `+0xac` chain).  
   Bytes: `83 8e 7c 01 00 00 10`; call @ `004FABEE` → `00512670`.

3. **Broken gate:** `(item+0x17c >> 19) & 1` → return **9**.  
   Same **ItemFlag_Broken** bit as `Item_SetBroken` / CountItems residual.

4. **Other fixed codes:** null/unsupported type **8**; precheck fail **6**; session `+0xf6` **0xf**; types **8/0x32** → **0xc**; vehicle path **1 / 0 / 0xe**.

5. **Type switch** on `*(item[0x2a]+0x38)` via tables `0x004fad58` (jumps) + `0x004fad78` (index):  
   6→`FUN_004f6940`; 10→`004f6840`; 0xc→`004f65e0`; 0xe→vehicle; 0x10→`004f6890`; 0x1c→`004f67e0`.

6. **Live decompile ≡ 2026-07-23 raw**.

7. **Not this unit:** type-helper bodies; Broken **setter** `0x00513de0`; Confirm UI parent `0x00941b20`.

---

## Gaps

1. Product English for sticky flag **`0x10`** at `+0x17c`.  
2. Product names for status **6 / 0xc / 0xf** and session byte `+0xf6`.  
3. Duals of type-specific equip helpers.  
4. Original PDB symbol.  
5. Runtime / bit-exact / image diff.

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004fabc0_Character_TryEquipItem.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004fabc0_Character_TryEquipItem.md` |
| Function record | `docs/reconstruction/functions/aa_004fabc0_FUN_004fabc0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_TryEquipItem.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004fabc0.cpp` |
| Raw (authoritative + live) | `docs/reconstruction/raw/aa_004fabc0_FUN_004fabc0.md` |
| Annotated | `docs/reconstruction/raw/aa_004fabc0_FUN_004fabc0.annotated.md` |
| This report | `docs/agents/task-dual-ab-004fabc0-character-tryequipitem-report.md` |

Absolute roots: `C:\Users\josh\Documents\GitHub\AutoCore\` + paths above.

---

## AutoCore impact

- Server equip validation should reject **Broken** items with a dedicated failure (client code **9**).  
- Client always stamps **`flags |= 0x10`** and dirty **`0x20000`** before type-specific equip — mirror if replaying client equip path.  
- Type **0xe** (vehicle) is a separate host path (`FUN_004ce5f0` / `FUN_004f6560`), not the item-vtbl family used by other cases.
