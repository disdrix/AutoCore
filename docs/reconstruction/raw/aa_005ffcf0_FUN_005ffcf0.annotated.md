# Annotated low-level: FUN_005ffcf0

| Field | Value |
|---|---|
| Stable ID | `aa_005ffcf0` |
| VA | `0x005ffcf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005ffcf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_005ffcf0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = param_1;
  uVar2 = FUN_00650290(param_1);
  FUN_0065ad10(&param_1,uVar2);
  if ((char)param_1 == '\0') {
    if (param_2 != 0) {
      uVar2 = FUN_00638140(param_2);
      FUN_00650210(iVar1,uVar2);
    }
    return;
  }
  uVar3 = FUN_0065acb0(uVar2);
  (**(code **)(*DAT_00b05060 + 4))(uVar3);
  if (param_1 != 0) {
    uVar3 = FUN_00638140(param_1);
    FUN_006501c0(uVar2,uVar3);
    return;
  }
  FUN_00650330(uVar2);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
