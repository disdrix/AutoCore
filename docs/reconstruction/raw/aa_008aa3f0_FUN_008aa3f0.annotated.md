# Annotated low-level: FUN_008aa3f0 (Dialog_SelectRewardSlot)

| Field | Value |
|---|---|
| Stable ID | `aa_008aa3f0` |
| VA | `0x008aa3f0` |
| System | `missions-progression` |
| Date | 2026-07-29 (dual A/B annotate) |

---

## Machine-level notes

- **ABI:** `EAX` = dialog host (`MOV EDI,EAX` at entry). Stack arg = slot index. **Not** ECX `__thiscall`.
- **TFID select:** `[EDI+0x578] = [EDI+EAX*8+0x558]`; `[EDI+0x57c] = [EDI+EAX*8+0x55c]`.
- **Widgets:** `ESI = EDI+0x698`, loop count `EBX=4`, stride `ADD ESI,4`.
- **Styles:** unselected block `EDI+0x594` (EBP); selected block `EDI+0x5a4`.
- **Vtbl:** `CALL [vtbl+0x158]` with args `(0, stylePtr)`; then `CALL [vtbl+0x34c]` refresh.
- **Hint clear:** if `[EDI+0x708]≠0`, `vtbl+0x308(&DAT_00a1419b)` — empty C-string.
- Prefer bytes/prologue when decompiler shows `in_EAX` phantom.

## Call sites

| VA | Parent | Slot arg | Host in EAX |
|---|---|---|---|
| `0x008aa968` | `FUN_008aa760` | imm `0` | EDI (dialog) |
| `0x008aed23` | `FUN_008aec40` | `EBX - 0x9c42` | ESI (dialog) |

## Pseudocode (annotated)

```c
// EAX = dialog, param_1 = slotIndex
void FUN_008aa3f0(int slotIndex)
{
  int dialog = /* EAX */;
  // 1) Commit selection TFID from slot table
  *(uint32_t *)(dialog + 0x578) = *(uint32_t *)(dialog + 0x558 + slotIndex * 8);
  *(uint32_t *)(dialog + 0x57c) = *(uint32_t *)(dialog + 0x55c + slotIndex * 8);

  // 2) All four reward widgets → unselected style (+0x594)
  undefined4 *widgetCursor = (undefined4 *)(dialog + 0x698);
  int remaining = 4;
  do {
    (**(code **)(*(int *)*widgetCursor + 0x158))(0, dialog + 0x594);
    (**(code **)(*(int *)*widgetCursor + 0x34c))();
    widgetCursor = widgetCursor + 1;  // +4 bytes
    remaining = remaining - 1;
  } while (remaining != 0);

  // 3) Selected slot widget → selected style (+0x5a4)
  (**(code **)(**(int **)(dialog + 0x698 + slotIndex * 4) + 0x158))(0, dialog + 0x5a4);
  (**(code **)(**(int **)(dialog + 0x698 + slotIndex * 4) + 0x34c))();

  // 4) Clear choose-reward hint (empty string)
  if (*(int **)(dialog + 0x708) != (int *)0x0) {
    (**(code **)(**(int **)(dialog + 0x708) + 0x308))(&DAT_00a1419b);
  }
  return;
}
```

## Open questions

- Layout of style blobs at `+0x594` / `+0x5a4` (and hover `+0x584` used only in dispatcher).
- Product names for UI vtbl ordinals `0x158` / `0x34c` / `0x308`.
- Runtime behavior if widgets null or slot out of range.
