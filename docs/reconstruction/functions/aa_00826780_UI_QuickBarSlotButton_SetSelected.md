# Function record: UI_QuickBarSlotButton_SetSelected

| Field | Value |
|---|---|
| **Stable ID** | `aa_00826780` |
| **Canonical name** | `UI_QuickBarSlotButton_SetSelected` (INFERRED) |
| **Address** | `0x00826780` |
| **Body range** | `0x00826780`–`0x0082685e` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client UI / quickbar |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + bytes + layout sealed; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00826780_UI_QuickBarSlotButton_SetSelected.md`, `reviews/B_aa_00826780_UI_QuickBarSlotButton_SetSelected.md` |
| **Last reviewed** | `2026-07-29` |

## Purpose

Set or clear the **visual selected** state of one QuickBar slot-button. Select path is exclusive (clears peers on parent `CDlgQuickBar`), gated on payload kind, updates `DAT_00d1da38[page]=column`. Clear path restores chrome and may clear the global column entry.

## Signature (decompiler + bytes)

```c
void __thiscall UI_QuickBarSlotButton_SetSelected(UI_QuickBarSlotButton *this, char fSelected);
// this = ECX; fSelected on stack; ret 4
```

## Layout (this unit)

| Offset | Field | Role in SetSelected |
|---|---|---|
| `+0x88` | `pParentWindow` | `dynamic_cast` → `CDlgQuickBar` |
| `+0x4fc` | `fSelected` (byte) | gate on clear; written both paths |
| `+0x500` | `columnIndex` | global table value |
| `+0x504` | `pageIndex` | indexes `DAT_00d1da38` |
| `+0x548` | `payloadKind` | select: reject 0 and 6 |
| `+0x564` | `pIconWidget` | clear: alpha + invalidate |
| `+0x56c` | `pHighlightChild` | `vtbl+4(0|1)` |

Ctor (`aa_00825bf0`) seeds `fSelected=0`, column sentinel `-1`.

## Algorithm

1. If `fSelected == 0`: unhighlight (`+0x56c`), force icon alpha (`+0x564`), clear global if match, `fSelected=0`.
2. Else if kind `+0x548` is 0 or 6: return.
3. Else: cast parent → `CDlgQuickBar`, clear other selected slots (`FUN_0089fef0`), highlight, stamp global, store `fSelected`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00826780_UI_QuickBarSlotButton_SetSelected.md`
- Annotated: `docs/reconstruction/raw/aa_00826780_UI_QuickBarSlotButton_SetSelected.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/UI_QuickBarSlotButton_SetSelected.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00826780-ui-quickbarslotbutton-setselected-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `__RTDynamicCast`; `FUN_0089fef0`; virtual `+0x56c`/`+0x564` |
| **Callers** | 13 xrefs: clear-active, assign-skill (`0x00826860`), page select (`0x008a0ed0`), build widgets, `FUN_0089fef0` (peer clear), etc. |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes | **High** |
| ABI thiscall + ret 4 | **High** |
| `fSelected` @ +0x4fc | **High** |
| page/column @ +0x504/+0x500 | **High** |
| Global `DAT_00d1da38[page]` | **High** |
| Kind gate 0/6 @ +0x548 | **High** (value 6 English open) |
| Exclusive peer clear via CDlgQuickBar | **High** |
| Product method English name | **Inferred** |
| Widget vtbl English | **Inferred** |

## Related

- `aa_00825bf0` UI_QuickBar_CreateSlotButton
- `aa_00826720` Client_SendQuickBarUpdateFromUi (sibling wire)
- `0x0089fef0` QuickBar_ClearOtherSelectedSlots_INFERRED
- `0x008a0ed0` QuickBar_SelectPage_Inferred
- `0x008274c0` QuickBar_ClearActiveSlot_INFERRED
