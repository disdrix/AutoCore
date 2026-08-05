# Dual A/B report — `aa_00826780` UI_QuickBarSlotButton_SetSelected

**Date:** 2026-07-29  
**Scope:** OWN ONLY VA `0x00826780`. Dual A/B + artifacts. Seal select/clear chrome + kind gate + global page column.  
**Agent:** W17-N OWN dual.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00826780` UI_QuickBarSlotButton_SetSelected | **accept-with-gaps** — **CF + bytes + layout sealed; kind-6 English open** |

---

## Sealed facts

1. **ABI:** `void __thiscall UI_QuickBarSlotButton_SetSelected(this, char fSelected)` — **ECX = this**, stack arg, epilogue **`ret 4`**. Body **`0x00826780`–`0x0082685e`**.

2. **`fSelected` flag byte `this+0x4fc`:** written both paths; ctor (`0x00825bf0`) seeds **0**.

3. **Clear path (`fSelected==0`):** optional `+0x56c` → `vtbl+4(0)`; optional `+0x564` → `vtbl+0x164(0)`, set `*(result+3)=0xFF`, `vtbl+0x34c()`; if `DAT_00d1da38[page]==column` then global=`-1`; store `+0x4fc=0`.

4. **Select path:** require `*(this+0x548) != 0 && != 6`; `dynamic_cast` parent `+0x88` `gfxUIWindow`→`CDlgQuickBar`; `FUN_0089fef0` clears peer selected slots; `+0x56c`→`vtbl+4(1)`; `DAT_00d1da38[page]=column`; store `+0x4fc=fSelected`.

5. **Globals:** `DAT_00d1da38` is `int[10]` selected **column** per **page** (`page@+0x504`, `column@+0x500`).

6. **Not wire / not cast:** no QuickBarUpdate `0x2062`, no character SetQuickBar*. Sibling wire: `Client_SendQuickBarUpdateFromUi` `0x00826720`.

7. **Name:** `UI_QuickBarSlotButton_SetSelected` — **INFERRED** from CDlgQuickBar RTTI + offsets shared with CreateSlotButton.

---

## Gaps

1. Product/PDB English for method/class name.  
2. Payload kind value **6** English.  
3. Widget types / vtbl English for `+0x56c` and `+0x564`.  
4. Runtime / bit-exact / differential — open.

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00826780_UI_QuickBarSlotButton_SetSelected.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00826780_UI_QuickBarSlotButton_SetSelected.md` |
| Function record | `docs/reconstruction/functions/aa_00826780_UI_QuickBarSlotButton_SetSelected.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_QuickBarSlotButton_SetSelected.cpp` |
| Raw | `docs/reconstruction/raw/aa_00826780_UI_QuickBarSlotButton_SetSelected.md` |
| Annotated | `docs/reconstruction/raw/aa_00826780_UI_QuickBarSlotButton_SetSelected.annotated.md` |
| Scratch | `tmp/a_00826780.md` |
| This report | `docs/agents/task-dual-ab-00826780-ui-quickbarslotbutton-setselected-report.md` |

---

## AutoCore impact

- **Client UI only** — do not map this VA to server QuickBar persistence or cast.  
- Emulating client chrome: exclusive selection + `g_qbSelectedColumnByPage[page]`; reject kind 0 and 6 on select.  
- Keep `Client_SendQuickBarUpdateFromUi` as separate wire helper.
