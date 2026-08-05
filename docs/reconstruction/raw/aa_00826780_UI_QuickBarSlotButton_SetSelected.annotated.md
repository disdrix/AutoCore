# Annotated low-level: UI_QuickBarSlotButton_SetSelected

| Field | Value |
|---|---|
| Stable ID | `aa_00826780` |
| VA | `0x00826780`–`0x0082685e` |
| System | client UI / quickbar |
| Date | `2026-07-29` |
| Tools | Ghidra `decompile_function` + `read_memory` (no `disassemble_bytes`) |

---

## Machine-level notes

- **ABI:** `__thiscall` — `this` in **ECX**, `char fSelected` on stack, epilogue **`ret 4`**.
- **Purpose:** Set or clear visual **selected** state on one QuickBar slot-button widget (class of `UI_QuickBar_CreateSlotButton` / size `0x554`).
- **Select (`fSelected != 0`):**
  1. Require payload kind `this+0x548` non-zero and **≠ 6**.
  2. `dynamic_cast` parent `this+0x88` from `gfxUIWindow` → `CDlgQuickBar`.
  3. `FUN_0089fef0(dlg)` clears any other slot with `+0x4fc != 0` by recursive `SetSelected(0)`.
  4. Optional child widget `this+0x56c` → `vtbl+4(1)` (highlight/show).
  5. Global `DAT_00d1da38[page]` = column (`page=this+0x504`, `column=this+0x500`).
  6. Store `this+0x4fc = fSelected`.
- **Clear (`fSelected == 0`):**
  1. If was selected and `+0x56c`: `vtbl+4(0)`.
  2. If color/icon widget `+0x564`: `vtbl+0x164(0)` → set byte `result+3 = 0xFF` (alpha), `vtbl+0x34c()` refresh.
  3. If `DAT_00d1da38[page] == column`, set that entry to **`-1`**.
  4. `this+0x4fc = 0`.
- Prefer bytes when decompiler names drift; CF matches bytes.

---

## Layout (this unit)

| Offset | Field | Role |
|---|---|---|
| `+0x88` | parent window* | RTTI cast source → `CDlgQuickBar` |
| `+0x4fc` | `fSelected` (byte) | selected/active flag (ctor seeds 0) |
| `+0x500` | column index | written into global per-page table |
| `+0x504` | page index | indexes `DAT_00d1da38` |
| `+0x548` | payload kind (dword) | select gate: reject 0 and 6 |
| `+0x564` | icon/color widget* | clear path alpha force + refresh |
| `+0x56c` | highlight child* | `vtbl+4(fSelected)` |

## Globals

| Address | Type | Role |
|---|---|---|
| `DAT_00d1da38` | `int[10]` | last selected **column** per page; `-1` = none |

---

## Byte map (key sites)

| VA | Bytes | Meaning |
|---|---|---|
| `00826780` | `53 8A 5C 24 08` | push ebx; load `fSelected` from `[esp+8]` |
| `00826785` | `84 DB 56 8B F1` | test bl; push esi; `esi=this` |
| `0082678a` | `74 68` | jz → clear path |
| `0082678c` | `8B 86 48 05 00 00` | `eax = [this+0x548]` kind |
| `00826792` | `85 C0 0F 84 C0 00 00 00` | kind==0 → ret |
| `0082679a` | `83 F8 06 0F 84 B7 00 00 00` | kind==6 → ret |
| `008267a2` | `8B 86 88 00 00 00` … RTTI … | cast parent → CDlgQuickBar |
| `008267c5` | `E8 2B 97 07 00` | `call FUN_0089fef0` (EAX=dlg) |
| `008267d5` | `6A 01 FF 50 04` | `vtbl+4(1)` on `+0x56c` |
| `008267e2` | `89 14 8D 38 DA D1 00` | `DAT_00d1da38[page]=column` |
| `008267e9` | `88 9E FC 04 00 00` | `+0x4fc = fSelected` |
| `008267ef` | `5E 5B C2 04 00` | epilogue select |
| `008267f4` | `80 BE FC 04 00 00 00` | clear: was selected? |
| `00826805` | `6A 00 FF 50 04` | `vtbl+4(0)` |
| `0082681a` | `C6 40 03 FF` | alpha byte `+3 = 0xFF` |
| `00826849` | `C7 04 85 38 DA D1 00 FF FF FF FF` | clear global column if match |
| `00826854` | `88 9E FC 04 00 00 5E 5B C2 04 00` | `+0x4fc=0`; ret 4 |

---

## Pseudocode (annotated)

```c
// UI_QuickBarSlotButton_SetSelected — client chrome only
void __thiscall UI_QuickBarSlotButton_SetSelected(SlotButton *this, char fSelected)
{
  if (fSelected == 0) {
    if (this->fSelected != 0 && this->pHighlightChild != NULL)
      this->pHighlightChild->vtbl->SetState(this->pHighlightChild, 0); // +4
    if (this->pIconWidget != NULL) {
      Color *c = this->pIconWidget->vtbl->GetColor(this->pIconWidget, 0); // +0x164
      c->a = 0xFF; // byte at +3
      this->pIconWidget->vtbl->Invalidate(this->pIconWidget); // +0x34c
    }
    if (g_qbSelectedColumnByPage[this->page] == this->column)
      g_qbSelectedColumnByPage[this->page] = -1;
    this->fSelected = 0;
    return;
  }

  // select path
  if (this->payloadKind == 0 || this->payloadKind == 6)
    return;

  CDlgQuickBar *dlg = dynamic_cast<CDlgQuickBar*>(this->pParentWindow); // +0x88
  QuickBar_ClearOtherSelectedSlots(dlg); // FUN_0089fef0; EAX = dlg

  if (this->pHighlightChild != NULL)
    this->pHighlightChild->vtbl->SetState(this->pHighlightChild, 1);

  g_qbSelectedColumnByPage[this->page] = this->column;
  this->fSelected = fSelected;
}
```

---

## Cross-unit contracts (context only)

- Ctor `UI_QuickBar_CreateSlotButton` (`0x00825bf0`): seeds `+0x4fc=0`, `+0x500=-1`.
- `FUN_0089fef0`: for i in 0..9 of `dlg+0x63c` slot*, if `slot+0x4fc` call **this** with 0.
- `QuickBar_SelectPage` / `FUN_008a0ed0`: stamps each slot `+0x504 = page`, clears selected, may reselect via `SetSelected(1)`.
- `Client_SendQuickBarUpdateFromUi` (`0x00826720`): sibling wire path — **not** this unit.

## Open questions

- Product/PDB English for method name and for kind value **6**.
- Exact widget type / English for `vtbl+4` on `+0x56c` and `+0x164/+0x34c` on `+0x564`.
- Whether `fSelected` is ever stored as a value other than 0/1 (body stores `param_2` as-is on select).
