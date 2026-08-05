# Annotated low-level: FUN_004d4da0

| Field | Value |
|---|---|
| Stable ID | `aa_004d4da0` |
| VA | `0x004d4da0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004d4da0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004d4da0(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int local_48;
  undefined4 local_44;
  int *local_3c;
  int *local_38;
  undefined4 local_34;
  undefined1 local_30 [20];
  void *pvStack_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_009a20dc;
  pvStack_1c = ExceptionList;
  local_44 = DAT_00d1f040;
  ExceptionList = &pvStack_1c;
  FUN_0076cf00("CVOGSectorMap::StepCreatures");
  local_14 = 0;
  FUN_004e9530(local_30,*(int *)(param_1 + 0xe898) + 0x8c);
  local_3c = (int *)0x0;
  local_38 = (int *)0x0;
  local_34 = 0;
  piVar5 = *(int **)(param_1 + 0xe720);
  local_14 = CONCAT31(local_14._1_3_,1);
  if (piVar5 != *(int **)(param_1 + 0xe724)) {
    do {
      iVar1 = *piVar5;
      iVar3 = *(int *)(iVar1 + 8);
      local_48 = iVar1;
      if ((iVar3 != 0) && ((*(char *)(iVar3 + 0x40) == '\0' || (*(int *)(iVar3 + 8) == 0)))) {
        if ((*(char *)(param_1 + 0x7e) == '\0') &&
           ((iVar3 = *(int *)(*(int *)(iVar1 + 4) + 4),
            (*(uint *)(iVar3 + 0x180 + iVar1) >> 1 & 1) == 0 &&
            (*(int *)(*(int *)(*(int *)(iVar3 + iVar1 + 0xac) + 0x3c) + 0x4e0) != 1)))) {
          piVar2 = *(int **)(param_1 + 0xe8a0);
          iVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x1dc))();
          iVar4 = (**(code **)(*piVar2 + 0x1dc))();
          if ((iVar3 != iVar4) &&
             (((0x77a1 < g_dwClientTickMs - *(int *)(iVar1 + 0x14) &&
               (*(char *)(iVar1 + 0x10) != '\0')) &&
              (*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0x18 + iVar1) == 0)))) {
            FUN_004e54a0(&local_48);
          }
        }
        if (((*(int *)(iVar1 + 8) == 0) ||
            (iVar3 = (**(code **)(**(int **)(*(int *)(iVar1 + 8) + 0x3c) + 0x18))(), iVar3 != 6)) ||
           (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xac + iVar1) + 0x3c) +
                    0x4e0) == 1)) {
          FUN_004c2f40(param_2);
        }
      }
      piVar5 = piVar5 + 1;
    } while (piVar5 != *(int **)(param_1 + 0xe724));
    if (local_3c != (int *)0x0) {
      local_48 = (int)local_38 - (int)local_3c >> 2;
      if ((local_48 != 0) && (piVar5 = local_3c, local_3c != local_38)) {
        do {
          iVar3 = *piVar5;
          iVar4 = *(int *)(*(int *)(iVar3 + 4) + 4);
          iVar1 = iVar4 + iVar3;
          FUN_007a4480(0,"Autodeleting Creature %I64d %d",*(undefined4 *)(iVar1 + 0x164),
                       *(undefined4 *)(iVar1 + 0x168),
                       *(undefined4 *)(*(int *)(iVar4 + 0xac + iVar3) + 0x34));
          *(undefined4 *)(*(int *)(*(int *)(iVar3 + 4) + 4) + iVar3 + 0xd0) = 0;
          FUN_004d4790(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3);
          piVar5 = piVar5 + 1;
        } while (piVar5 != local_38);
      }
                    /* WARNING: Subroutine does not return */
      operator_delete(local_3c);
    }
  }
  local_14 = 0xffffffff;
  FUN_0076cef0();
  ExceptionList = pvStack_1c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
