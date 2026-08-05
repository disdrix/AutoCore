# Annotated low-level: FUN_0051def0

| Field | Value |
|---|---|
| Stable ID | `aa_0051def0` |
| VA | `0x0051def0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0051def0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0051def0(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 4);
  if (iVar4 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(int *)(param_1 + 8) - iVar4 >> 4;
  }
  if (uVar3 < param_2) {
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(param_1 + 8) - iVar4 >> 4;
    }
    FUN_0051d4a0(*(undefined4 *)(param_1 + 8),param_2 - iVar4,&stack0x00000008);
    return;
  }
  if (((iVar4 != 0) && (iVar1 = *(int *)(param_1 + 8), param_2 < (uint)(iVar1 - iVar4 >> 4))) &&
     (iVar4 = param_2 * 0x10 + iVar4, iVar4 != iVar1)) {
    uVar2 = FUN_0043fb00(iVar1,iVar1,iVar4,param_2);
    *(undefined4 *)(param_1 + 8) = uVar2;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
