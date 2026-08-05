# Annotated low-level: FUN_007aeb00

| Field | Value |
|---|---|
| Stable ID | `aa_007aeb00` |
| VA | `0x007aeb00` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007aeb00`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall
FUN_007aeb00(int *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined1 auStack_58 [84];
  undefined1 uStack_4;
  undefined1 uStack_3;
  undefined1 uStack_2;
  undefined1 uStack_1;
  
  cVar1 = (**(code **)(*param_1 + 0x324))();
  if (cVar1 == '\0') {
    cVar1 = (**(code **)(*param_1 + 0x328))();
    if (cVar1 == '\0') {
      uVar5 = (**(code **)(*param_1 + 0x14c))(param_2,param_3,param_4);
      return uVar5;
    }
    iVar2 = (**(code **)(*param_1 + 700))();
    if (iVar2 != 0) {
      cVar1 = (**(code **)(*param_1 + 0x14c))(param_2,param_3,param_4);
      if (cVar1 != '\0') {
        uVar5 = (**(code **)(*param_1 + 0x168))(param_2,param_3,param_4);
        return uVar5;
      }
      return 0;
    }
  }
  else {
    iVar2 = (**(code **)(*param_1 + 0x290))();
    if (iVar2 != 0) {
      uStack_2 = 0xff;
      uStack_3 = 0xff;
      uStack_4 = 0xff;
      uStack_1 = 0xff;
      uStack_60 = *param_2;
      uStack_5c = param_2[1];
      piVar3 = (int *)(**(code **)(*param_1 + 0x1a0))();
      iVar2 = (**(code **)(*piVar3 + 0x10))(&uStack_60,5,auStack_58,0);
      if (iVar2 != 0) {
        iVar4 = (**(code **)(*param_1 + 0x290))();
        if (iVar2 == iVar4) {
          return 1;
        }
      }
    }
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
