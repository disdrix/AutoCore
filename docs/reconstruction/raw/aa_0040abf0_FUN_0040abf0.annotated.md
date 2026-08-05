# Annotated low-level: Item_CanAcceptStackQty (FUN_0040abf0)

| Field | Value |
|---|---|
| Stable ID | `aa_0040abf0` |
| VA | `0x0040abf0` |
| Canonical | `Item_CanAcceptStackQty` |
| System | inventory-transfer |
| Date | 2026-07-29 (dual A/B seal; supersedes 2026-07-23 scaffold notes) |

## Machine-level notes

- Source: raw capture + live `decompile_function` / `read_memory` 2026-07-29.
- `__thiscall`: ECX = destination item; stack ushort = `addQty`; `ret 4`.
- Leaf except virtual `vtbl+0x25C` (quantity).
- Max formula shared with inlined path in `InventoryGrid_FindItemByCbid` (`0x005710c0`).
- Not eligibility: `Item_IsStackEligible` (`0x00513e70`).

## Pseudocode (annotated)

```c
// bool Item_CanAcceptStackQty(Item* this /*ECX*/, ushort addQty)
undefined4 __thiscall FUN_0040abf0(int *param_1, ushort param_2)
{
  ushort uVar1;   // def max-stack field
  int iVar2;      // current qty from vtbl+0x25c
  uint uVar3;     // maxStack (may be 999999 before mask)

  // clonebase @ item+0xA8 (param_1[0x2a])
  if (*(int *)(param_1[0x2a] + 0x38) == 4) {
    // type class 4 → load 999999 (0xF423F)
    uVar3 = 999999;
  }
  else {
    // *( *(clonebase+0x3C) + 0x4BA ) as ushort
    uVar1 = *(ushort *)(*(int *)(param_1[0x2a] + 0x3c) + 0x4ba);
    uVar3 = (uint)uVar1;
    if (uVar1 == 0) {
      uVar3 = 200;   // default max stack
    }
  }
  iVar2 = (**(code **)(*param_1 + 0x25c))();  // GetQuantity
  // retail: setle after (qty+add) cmp (max & 0xFFFF)
  // type-4 effective max = 999999 & 0xFFFF = 16959
  return CONCAT31((int3)(iVar2 + (uint)param_2 >> 8),
                  (int)(iVar2 + (uint)param_2) <= (int)(uVar3 & 0xffff));
}
```

## Callers (sealed)

| Site | Parent | this | addQty |
|------|--------|------|--------|
| `0x004fae64` | Inventory_SerializeAddItemPacket | existing stack | new qty |
| `0x00571558` | FUN_005714e0 | found stack | source qty |
| `0x0094564b` | FUN_00945540 | existing stack | loot qty |
| `0x00801406` / `0x0080159c` | FUN_008012f0 | existing (EBX) | source qty |

## Open questions

- Product name for clonebase type class **4**.
- Whether server max-stack policy mirrors the type-4 u16 mask quirk.
