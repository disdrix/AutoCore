# Annotated low-level: Vehicle_SetEquippedArmor

| Field | Value |
|---|---|
| Stable ID | `aa_00502090` |
| VA | `0x00502090` |
| System | inventory-transfer |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00502090`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Vehicle_SetEquippedArmor — set armor slot and recalc pools.
   
   Parameters:
     this: vehicle; pArmorItem: item or null; bSkipUnbind: skip prior unbind if non-zero
   Returns: void.
   
   Algorithm:
     Unbind old armor@+0x254 unless bSkipUnbind; store new
     Expect item type 0x1c; log unhappy type otherwise
     Bind via vfunc+0x158; Vehicle_RecalcCombatPools (HP uses ArmorFactor@item+0xb4) */

void __thiscall Vehicle_SetEquippedArmor(void *this,void *pArmorItem,char bSkipUnbind)

{
  int pPrevOrBindCtx;
  
  FUN_00512670();
  if (bSkipUnbind == '\0') {
    pPrevOrBindCtx = *(int *)((int)this + 0x254);
    if (pPrevOrBindCtx != 0) {
      pPrevOrBindCtx = *(int *)(*(int *)(pPrevOrBindCtx + 4) + 4) + 4 + pPrevOrBindCtx;
    }
    FUN_004fbb50(pPrevOrBindCtx);
  }
  *(void **)((int)this + 0x254) = pArmorItem;
  if (pArmorItem != (void *)0x0) {
    if (*(int *)(*(int *)(*(int *)(*(int *)((int)pArmorItem + 4) + 4) + 0xac + (int)pArmorItem) +
                0x38) != 0x1c) {
      pPrevOrBindCtx = *(int *)(*(int *)((int)pArmorItem + 4) + 4);
      FUN_007a4480(1,"Set armor of unhappy type: CBID:%d COID:%I64d",
                   *(undefined4 *)(*(int *)((int)pArmorItem + pPrevOrBindCtx + 0xac) + 0x34),
                   *(undefined4 *)(pPrevOrBindCtx + 0x164 + (int)pArmorItem),
                   *(undefined4 *)(pPrevOrBindCtx + 0x168 + (int)pArmorItem));
    }
    (**(code **)(*(int *)(*(int *)(*(int *)((int)pArmorItem + 4) + 4) + 4 + (int)pArmorItem) + 0x158
                ))(*(int *)(*(int *)((int)this + 4) + 4) + 4 + (int)this);
    pPrevOrBindCtx = *(int *)((int)this + 0x254);
    if (pPrevOrBindCtx == 0) {
      FUN_004fdcb0(0);
      Vehicle_RecalcCombatPools(this);
      return;
    }
    FUN_004fdcb0(*(int *)(*(int *)(pPrevOrBindCtx + 4) + 4) + 4 + pPrevOrBindCtx);
  }
  Vehicle_RecalcCombatPools(this);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
