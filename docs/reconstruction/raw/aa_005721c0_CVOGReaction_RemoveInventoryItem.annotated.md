# Annotated low-level: CVOGReaction_RemoveInventoryItem

| Field | Value |
|---|---|
| Stable ID | `aa_005721c0` |
| VA | `0x005721c0` |
| System | inventory-transfer |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005721c0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int __thiscall CVOGReaction_RemoveInventoryItem(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int *local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 *local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar5 = param_3;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a4f22;
  local_c = ExceptionList;
  if ((param_2 == -1) || (param_3 < 1)) {
    return 0;
  }
  ExceptionList = &local_c;
  local_1c = param_1;
  puVar3 = (undefined4 *)FUN_0040fb90();
  local_10 = 0;
  local_4 = 0;
  local_20 = 0;
  param_3 = 0;
  local_14 = puVar3;
  FUN_004294f0();
  iVar4 = FUN_004022a0(&local_20,&local_24);
  piVar2 = local_24;
  do {
    if (iVar4 != 0) {
LAB_005722df:
      if (*(char *)(param_1 + 0x54) != '\0') {
        *(undefined1 *)(param_1 + 0x54) = 0;
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
      }
      for (puVar1 = (undefined4 *)*puVar3; puVar1 != puVar3; puVar1 = (undefined4 *)*puVar1) {
        FUN_00571b80(puVar1[2],1000000,1);
        FUN_004d4790(puVar1[2]);
      }
      FUN_00403430();
      ExceptionList = local_c;
      return param_3;
    }
    local_24 = piVar2;
    if ((piVar2 != (int *)0x0) && (*(int *)(piVar2[0x2a] + 0x34) == param_2)) {
      iVar4 = (**(code **)(*piVar2 + 0x25c))();
      if (0 < iVar4 - iVar5) {
        (**(code **)(*piVar2 + 0x260))(iVar4 - iVar5);
        param_3 = param_3 + iVar5;
        goto LAB_005722df;
      }
      iVar4 = (**(code **)(*piVar2 + 0x25c))();
      iVar5 = iVar5 - iVar4;
      iVar4 = FUN_00418700(puVar3,puVar3[1],&local_24);
      FUN_00404840(1);
      puVar3[1] = iVar4;
      **(int **)(iVar4 + 4) = iVar4;
      iVar4 = (**(code **)(*piVar2 + 0x25c))();
      param_3 = param_3 + iVar4;
      puVar3 = local_14;
    }
    param_1 = local_1c;
    iVar4 = FUN_004022a0(&local_20,&local_24);
    piVar2 = local_24;
  } while( true );
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
