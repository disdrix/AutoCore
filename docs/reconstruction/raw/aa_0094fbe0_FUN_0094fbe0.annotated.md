# Annotated low-level: FUN_0094fbe0

| Field | Value |
|---|---|
| Stable ID | `aa_0094fbe0` |
| VA | `0x0094fbe0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0094fbe0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall FUN_0094fbe0(int param_1,int param_2,char *param_3)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined4 uStack_60;
  undefined1 local_5c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  char local_30 [24];
  undefined4 local_18;
  undefined4 local_14;
  
  *(undefined1 *)(param_2 + 0x2e) = 0;
  local_18 = 0;
  local_14 = 0;
  local_48 = 0;
  local_44 = 0;
  local_30[0] = '\0';
  local_5c = 0;
  puVar4 = (undefined4 *)
           (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) + 4 +
                                *(int *)(param_1 + 0xe98)) + 0x1a0))();
  uStack_40 = *puVar4;
  uStack_3c = puVar4[1];
  uStack_38 = puVar4[2];
  uStack_34 = puVar4[3];
  iVar1 = *(int *)(param_1 + 0xe98);
  iVar2 = *(int *)(*(int *)(iVar1 + 4) + 4);
  local_48 = *(undefined4 *)(iVar2 + 0x164 + iVar1);
  local_44 = *(undefined4 *)(iVar2 + 0x168 + iVar1);
  pcVar5 = strtok((char *)0x0,param_3);
  if (pcVar5 == (char *)0x0) {
    return 1;
  }
  iVar1 = -(int)pcVar5;
  do {
    cVar3 = *pcVar5;
    pcVar5[(int)(local_30 + iVar1)] = cVar3;
    pcVar5 = pcVar5 + 1;
  } while (cVar3 != '\0');
  uStack_60 = 0x8019;
  if (*(int *)(param_1 + 0xc7c) != 0) {
    cVar3 = (**(code **)(**(int **)(param_1 + 0xc7c) + 8))();
    if (cVar3 != '\0') {
      (**(code **)(**(int **)(param_1 + 0xc7c) + 0x18))(0xffffffff,&uStack_60,0x50,0);
      return 0;
    }
  }
  return 0x80004005;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
