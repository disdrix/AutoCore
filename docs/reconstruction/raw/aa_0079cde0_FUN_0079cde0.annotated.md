# Annotated low-level: FUN_0079cde0

| Field | Value |
|---|---|
| Stable ID | `aa_0079cde0` |
| VA | `0x0079cde0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0079cde0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0079cde0(int *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  undefined4 unaff_ESI;
  
  pcVar2 = param_2;
  cVar1 = *param_2;
  pcVar3 = param_2;
  while (cVar1 != '\0') {
    pcVar3 = pcVar3 + 1;
    cVar1 = *pcVar3;
  }
  param_2 = pcVar3 + (1 - (int)param_2);
  (**(code **)(*param_1 + 8))(&param_2,4);
  (**(code **)(*param_1 + 8))(pcVar2,unaff_ESI);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
