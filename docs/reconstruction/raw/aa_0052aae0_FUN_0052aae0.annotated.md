# Annotated low-level: FUN_0052aae0

| Field | Value |
|---|---|
| Stable ID | `aa_0052aae0` |
| VA | `0x0052aae0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0052aae0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0052aae0(int param_1)

{
  void *pvVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  uint uStack_8;
  uint local_4;
  
  if ((*(int *)(param_1 + 0xd80) != 0) &&
     (local_4 = *(int *)(param_1 + 0xd84) - *(int *)(param_1 + 0xd80) >> 2, local_4 != 0)) {
    iVar7 = 0;
    while( true ) {
      if (*(int *)(param_1 + 0xd80) == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(param_1 + 0xd84) - *(int *)(param_1 + 0xd80) >> 2;
      }
      pvVar1 = *(void **)(param_1 + 0xd80);
      if (iVar3 <= iVar7) break;
      iVar3 = iVar7 * 4;
      iVar4 = FUN_005710c0(*(undefined4 *)(*(int *)(*(int *)((int)pvVar1 + iVar3) + 0xa8) + 0x34),0,
                           0);
      if (iVar4 == 0) {
        iVar4 = (**(code **)(**(int **)(*(int *)(param_1 + 0xd80) + iVar3) + 0x25c))();
        if (0 < iVar4) {
          local_4 = local_4 & 0xffffff00;
          uStack_8 = uStack_8 & 0xffffff00;
          cVar2 = FUN_005714e0(*(undefined4 *)(*(int *)(param_1 + 0xd80) + iVar3),&local_4,&uStack_8
                               ,1,0xffffffff);
          if (cVar2 != '\0') {
            puVar8 = (undefined4 *)(iVar3 + *(int *)(param_1 + 0xd80));
            uVar6 = (**(code **)(*(int *)*puVar8 + 0x25c))();
            FUN_00571620(*puVar8,local_4,uStack_8,uVar6);
          }
        }
        iVar7 = iVar7 + 1;
      }
      else {
        uVar6 = *(undefined4 *)(iVar4 + 0x160);
        uVar9 = *(undefined4 *)(iVar4 + 0x164);
        uVar5 = (**(code **)(**(int **)(*(int *)(param_1 + 0xd80) + iVar3) + 0x25c))(uVar6,uVar9);
        FUN_00571830(uVar5,uVar6,uVar9);
        iVar7 = iVar7 + 1;
      }
    }
    if (pvVar1 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete(pvVar1);
    }
    *(undefined4 *)(param_1 + 0xd80) = 0;
    *(undefined4 *)(param_1 + 0xd84) = 0;
    *(undefined4 *)(param_1 + 0xd88) = 0;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
