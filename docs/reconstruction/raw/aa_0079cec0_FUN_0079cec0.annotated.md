# Annotated low-level: FUN_0079cec0

| Field | Value |
|---|---|
| Stable ID | `aa_0079cec0` |
| VA | `0x0079cec0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0079cec0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int FUN_0079cec0(char *param_1)

{
  char *pcVar1;
  int iVar2;
  char unaff_BP;
  int *unaff_ESI;
  int iVar3;
  int unaff_retaddr;
  
  pcVar1 = param_1;
  param_1 = (char *)((uint)param_1 & 0xffffff00);
  (**(code **)(*unaff_ESI + 4))(&param_1,1);
  iVar3 = 0;
  if ((((unaff_BP != '\0') && (iVar3 = 0, unaff_BP != '\r')) && (unaff_BP != '\n')) &&
     (0 < unaff_retaddr + -2)) {
    *pcVar1 = unaff_BP;
    iVar3 = 1;
    (**(code **)(*unaff_ESI + 4))(&stack0xfffffffc,1);
    unaff_BP = '\0';
  }
  pcVar1[iVar3] = '\0';
  if (unaff_BP == '\r') {
    iVar2 = (**(code **)(*unaff_ESI + 0x1c))();
    (**(code **)(*unaff_ESI + 0x24))(iVar2 + 1);
  }
  return iVar3;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
