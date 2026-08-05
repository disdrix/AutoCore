# Annotated low-level: FUN_004aee50

| Field | Value |
|---|---|
| Stable ID | `aa_004aee50` |
| VA | `0x004aee50` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004aee50`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_004aee50(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,code *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  
  cVar3 = (*param_4)(*param_2,param_2[1],*param_1,param_1[1]);
  if (cVar3 != '\0') {
    uVar1 = *param_2;
    uVar2 = param_2[1];
    *param_2 = *param_1;
    param_2[1] = param_1[1];
    *param_1 = uVar1;
    param_1[1] = uVar2;
  }
  cVar3 = (*param_4)(*param_3,param_3[1],*param_2,param_2[1]);
  if (cVar3 != '\0') {
    uVar1 = *param_3;
    uVar2 = param_3[1];
    *param_3 = *param_2;
    param_3[1] = param_2[1];
    *param_2 = uVar1;
    param_2[1] = uVar2;
  }
  cVar3 = (*param_4)(*param_2,param_2[1],*param_1,param_1[1]);
  if (cVar3 != '\0') {
    uVar1 = *param_2;
    uVar2 = param_2[1];
    *param_2 = *param_1;
    param_2[1] = param_1[1];
    *param_1 = uVar1;
    param_1[1] = uVar2;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
