# Review B (skeptical / adversarial): `aa_00826780` UI_QuickBarSlotButton_SetSelected

| Field | Value |
|---|---|
| **Stable ID** | `aa_00826780` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W17-N dual seal) |
| **Counterpart** | `reviews/A_aa_00826780_UI_QuickBarSlotButton_SetSelected.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is QuickBarUpdate `0x2062` sender | **Falsified** — no net callees; sibling is `0x00826720` |
| 2 | Always selects when called with non-zero | **Falsified** — kind 0 or 6 early-out |
| 3 | Clear always touches highlight child | **Falsified** — only if `+0x4fc` was non-zero **and** `+0x56c` non-null |
| 4 | Clear always writes global to -1 | **Falsified** — only if `DAT_00d1da38[page]==column` |
| 5 | `FUN_0089fef0` is independent of cast | **Falsified** — cast result left in EAX as `in_EAX` for helper |
| 6 | Convention is pure `__fastcall` / no stack | **Falsified** — `ret 4`; arg from `[esp+8]` after pushes |
| 7 | `+0x500` is absolute slot (page*10+col) | **Falsified here** — used as **column** into per-page table; absolute slot computed in other units as `page*10+col` |
| 8 | Function mutates character skill/item binds | **Falsified** — only UI fields + global page column table |
| 9 | Kind gate includes empty-only (0) | **Partial** — also rejects **6**; do not collapse to “empty only” |
| 10 | Decompiler “param_1” naming is authoritative product type | **Noise** — product class English open; layout sealed by offsets + ctor sibling |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Selected flag `+0x4fc` | **High** | Wrong exclusivity / page reselect |
| Page/column `+0x504/+0x500` + global | **High** | Broken page restore selection |
| Kind gate 0 & 6 | **High** | Highlight empty/special slots |
| Peer exclusivity via dlg | **High** | Multi-select chrome bugs |
| Client-only (no wire) | **High** | Spurious server packets in ports |
| Kind-6 product meaning | **Low** | Mis-label payload enum |
| Method English name | **Inferred** | Registry rename churn |

---

## 3. Cross-check against raw + bytes

```
if fSelected == 0:
  if fSelectedFlag && pHighlight: vtbl+4(0)
  if pIcon: color=GetColor(0); color.a=0xFF; Invalidate()
  if global[page]==column: global[page]=-1
  fSelectedFlag = 0
else:
  if kind==0 or kind==6: return
  dlg = dynamic_cast<CDlgQuickBar*>(parent)
  ClearOtherSelected(dlg)   // FUN_0089fef0
  if pHighlight: vtbl+4(1)
  global[page] = column
  fSelectedFlag = fSelected
```

Clean must **not** invent packet sends, character SetQuickBar*, or absolute-slot math inside this unit.

---

## 4. Surviving contract for AutoCore

```
// Port of UI_QuickBarSlotButton_SetSelected (client chrome only)
void SetSelected(SlotButton* btn, bool selected) {
  if (!selected) {
    if (btn->fSelected && btn->pHighlight) btn->pHighlight->SetState(0);
    if (btn->pIcon) { auto* c = btn->pIcon->GetColor(0); c->a = 255; btn->pIcon->Invalidate(); }
    if (g_qbSelectedColumnByPage[btn->page] == btn->column)
      g_qbSelectedColumnByPage[btn->page] = -1;
    btn->fSelected = false;
    return;
  }
  if (btn->payloadKind == 0 || btn->payloadKind == 6) return;
  auto* dlg = dynamic_cast_parent_to_CDlgQuickBar(btn);
  ClearOtherSelectedSlots(dlg);
  if (btn->pHighlight) btn->pHighlight->SetState(1);
  g_qbSelectedColumnByPage[btn->page] = btn->column;
  btn->fSelected = true;
}
// Do NOT fold Client_SendQuickBarUpdateFromUi into this helper.
```

---

## 5. Open questions

1. Product symbol string for this method / class (`PTR_FUN_00a75004` family).
2. Enum name for kind **6**.
3. Full vtbl map for highlight/icon widgets.
4. Runtime / differential / bit-exact.

**Verdict:** **accept-with-gaps**
