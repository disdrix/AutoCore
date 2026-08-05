# Annotated low-level: FUN_0094eae0

| Field | Value |
|---|---|
| Stable ID | `aa_0094eae0` |
| VA | `0x0094eae0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0094eae0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_0094eae0(undefined4 param_1,char *param_2)

{
  char *pcVar1;
  
  pcVar1 = strtok((char *)0x0,param_2);
  if (pcVar1 != (char *)0x0) {
    atoi(pcVar1);
    pcVar1 = strtok((char *)0x0,param_2);
    if (pcVar1 != (char *)0x0) {
      atoi(pcVar1);
    }
  }
  return 1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
