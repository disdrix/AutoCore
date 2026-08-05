# Annotated low-level: FUN_005ffa10

| Field | Value |
|---|---|
| Stable ID | `aa_005ffa10` |
| VA | `0x005ffa10` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005ffa10`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
uint __fastcall FUN_005ffa10(void *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uStack_24;
  undefined1 auStack_20 [28];
  
  iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 4 + (int)param_1) + 0x214
                      ))();
  uVar2 = 0;
  if ((((iVar1 != 0) && (uVar2 = Weapon_ApplyShotHeatAndPowerCost(param_1), (char)uVar2 != '\0')) &&
      (uVar2 = (**(code **)(*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 4 + (int)param_1) +
                           0x214))(),
      (*(byte *)(*(int *)(*(int *)(uVar2 + 4) + 4) + 0xb8 + uVar2) & 0x10) == 0)) &&
     ((uVar2 = (**(code **)(*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 4 + (int)param_1) +
                           0x214))(),
      (*(byte *)(*(int *)(*(int *)(uVar2 + 4) + 4) + 0xb8 + uVar2) & 2) == 0 &&
      (iVar1 = *(int *)(*(int *)((int)param_1 + 4) + 4), uVar2 = iVar1 + (int)param_1,
      *(int *)(iVar1 + 0x74 + (int)param_1) != 0)))) {
    FUN_00518630(1,1,2);
    uStack_24 = 0;
    FUN_00402c40();
    iVar1 = FUN_00411900(&uStack_24);
    while (iVar1 != 0) {
      if ((*(uint *)(iVar1 + 0x614) & 0x100) == 0) {
        FUN_0056cc70(auStack_20);
        CVOGReaction_CastSkillOnTarget
                  (iVar1,*(undefined4 *)
                          (*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xb0 + (int)param_1)
                          + 0xac),0,0,0,auStack_20,0,0xffffffff,0,0);
      }
      iVar1 = FUN_00411900(&uStack_24);
    }
    iVar1 = *(int *)((int)param_1 + 4);
    *(undefined1 *)(*(int *)(*(int *)(iVar1 + 4) + 0x74 + (int)param_1) + 0x1d) = 0;
    return CONCAT31((int3)((uint)iVar1 >> 8),1);
  }
  return uVar2 & 0xffffff00;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
