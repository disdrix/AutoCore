# Annotated low-level: FUN_0068bcd0

| Field | Value |
|---|---|
| Stable ID | `aa_0068bcd0` |
| VA | `0x0068bcd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0068bcd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0068bcd0(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  uint local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined1 local_3c [48];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009aa328;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 100) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(int *)(param_1 + 0x68) - *(int *)(param_1 + 100) >> 2;
  }
  local_50 = uVar3 / 3 & 0xffff;
  if (local_50 != 0) {
    iVar4 = 0;
    ExceptionList = &local_c;
    do {
      iVar2 = *(int *)(param_1 + 100);
      local_40 = *(undefined4 *)(iVar4 + 8 + iVar2);
      local_44 = *(undefined4 *)(iVar4 + 4 + iVar2);
      local_48 = *(undefined4 *)(iVar4 + iVar2);
      puVar1 = (undefined4 *)FUN_0069f950(local_3c,&local_48);
      puVar5 = param_2;
      for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar1;
        puVar1 = puVar1 + 1;
        puVar5 = puVar5 + 1;
      }
      local_4 = 0;
      FUN_0056f570();
      local_4 = 0xffffffff;
      FUN_0056f570();
      iVar4 = iVar4 + 0xc;
      local_50 = local_50 - 1;
    } while (local_50 != 0);
  }
  ExceptionList = local_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
