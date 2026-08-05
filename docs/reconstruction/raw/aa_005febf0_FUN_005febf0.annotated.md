# Annotated low-level: FUN_005febf0

| Field | Value |
|---|---|
| Stable ID | `aa_005febf0` |
| VA | `0x005febf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005febf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall
FUN_005febf0(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  CreateSimpleObject_Serialize(param_2,param_3,param_4);
  if (param_2 == (undefined4 *)0x0) {
    return 0;
  }
  *param_2 = 0x2060;
  param_2[0x36] = *(undefined4 *)(param_1 + -0x30);
  param_2[0x37] = *(undefined4 *)(param_1 + -0x2c);
  param_2[0x38] = *(undefined4 *)(param_1 + -0x28);
  param_2[0x39] = *(undefined4 *)(param_1 + -0x24);
  param_2[0x3a] = *(undefined4 *)(param_1 + -0x20);
  pcVar2 = (char *)(**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0xdc + param_1)
                               + 0x15c))();
  pcVar3 = (char *)(param_2 + 0x3c);
  do {
    cVar1 = *pcVar2;
    *pcVar3 = cVar1;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  param_2[0x3b] = *(undefined4 *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0x1c + param_1);
  *(undefined1 *)(param_2 + 0x28) = 0;
  *(undefined2 *)(param_2 + 0x55) = *(undefined2 *)(param_1 + -0x14);
  return 0x158;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
