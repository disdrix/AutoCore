# Annotated low-level: FUN_0074fca0

| Field | Value |
|---|---|
| Stable ID | `aa_0074fca0` |
| VA | `0x0074fca0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0074fca0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int __thiscall FUN_0074fca0(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = DAT_00d1f614;
  iVar2 = *(int *)(param_1 + 0x28);
  if (DAT_00d1f614 != 0) {
    piVar1 = (int *)(DAT_00d1f614 + 0xd0 + *(int *)(DAT_00d1f614 + 0xc4) * 0x4c);
    *piVar1 = *piVar1 + 1;
  }
  if ((&DAT_00afe010)[iVar2 * 3] == param_1) {
    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effDeviceEffect.cpp",
                   0xce,1,"effDeviceEffect::Begin() called on an effect that is already active.");
  }
  else {
    if ((&DAT_00afe010)[iVar2 * 3] != 0) {
      FUN_0074f360();
      iVar3 = DAT_00d1f614;
    }
    if (*(int *)(param_1 + 0xc) != 0) {
      (**(code **)(**(int **)(param_1 + 0xc) + 0xfc))(*(int **)(param_1 + 0xc),0,param_2);
      iVar3 = DAT_00d1f614;
    }
    (&DAT_00afe010)[iVar2 * 3] = param_1;
    if (iVar3 != 0) {
      piVar1 = (int *)(iVar3 + 0xcc + *(int *)(iVar3 + 0xc4) * 0x4c);
      *piVar1 = *piVar1 + 1;
    }
    iVar2 = *(int *)(param_1 + 0x20);
    if (iVar2 == 0) {
      return 1;
    }
    if (*(int *)(iVar2 + 200) != 0) {
      return (*(int *)(iVar2 + 0xcc) - *(int *)(iVar2 + 200)) / 0x24;
    }
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
