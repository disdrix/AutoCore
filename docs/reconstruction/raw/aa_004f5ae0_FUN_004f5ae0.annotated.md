# Annotated low-level: FUN_004f5ae0

| Field | Value |
|---|---|
| Stable ID | `aa_004f5ae0` |
| VA | `0x004f5ae0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004f5ae0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004f5ae0(int param_1,char param_2,char *param_3)

{
  int *piVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  undefined4 *puVar7;
  char *pcVar8;
  char *pcVar9;
  undefined4 uVar10;
  undefined4 local_124;
  char acStack_120 [2];
  undefined4 auStack_11e [66];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_009a2ca5;
  local_14 = ExceptionList;
  if (param_2 < '\b') {
    piVar1 = (int *)(param_1 + 0x34c + param_2 * 4);
    ExceptionList = &local_14;
    if ((undefined4 *)*piVar1 != (undefined4 *)0x0) {
      ExceptionList = &local_14;
      (*(code *)**(undefined4 **)*piVar1)(1);
      *piVar1 = 0;
    }
    pcVar3 = param_3;
    do {
      cVar2 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar2 != '\0');
    local_124 = (void *)((int)pcVar3 - (int)(param_3 + 1));
    if (local_124 != (void *)0x0) {
      acStack_120[0] = '\0';
      acStack_120[1] = '\0';
      puVar7 = auStack_11e;
      for (iVar4 = 0x40; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
      }
      *(undefined2 *)puVar7 = 0;
      pcVar3 = param_3;
      do {
        cVar2 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar2 != '\0');
      pcVar8 = (char *)((int)&local_124 + 3);
      do {
        pcVar6 = pcVar8 + 1;
        pcVar8 = pcVar8 + 1;
      } while (*pcVar6 != '\0');
      pcVar6 = param_3;
      for (uVar5 = (uint)((int)pcVar3 - (int)param_3) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar8 = pcVar8 + 4;
      }
      pcVar9 = acStack_120;
      uVar10 = 0xffffffff;
      for (uVar5 = (int)pcVar3 - (int)param_3 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar8 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar8 = pcVar8 + 1;
      }
      FUN_007b6a20(pcVar9,0xffffffff);
      cVar2 = FUN_007b6730(pcVar9,uVar10);
      if (cVar2 != '\0') {
        local_124 = operator_new(0x14c);
        uStack_c = 0;
        if (local_124 == (void *)0x0) {
          iVar4 = 0;
        }
        else {
          iVar4 = FUN_00764030();
        }
        uStack_c = 0xffffffff;
        *piVar1 = iVar4;
        FUN_00989e00(&local_124,param_3);
        iVar4 = (**(code **)(*(int *)*piVar1 + 0x5c))(&local_124);
        if (iVar4 < 0) {
          if ((undefined4 *)*piVar1 != (undefined4 *)0x0) {
            (*(code *)**(undefined4 **)*piVar1)(1);
          }
          *piVar1 = 0;
        }
      }
    }
  }
  ExceptionList = local_14;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
