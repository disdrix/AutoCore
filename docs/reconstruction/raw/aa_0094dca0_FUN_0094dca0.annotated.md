# Annotated low-level: FUN_0094dca0

| Field | Value |
|---|---|
| Stable ID | `aa_0094dca0` |
| VA | `0x0094dca0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0094dca0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_0094dca0(undefined4 param_1,char *param_2)

{
  char *_String;
  double dVar1;
  undefined4 local_20;
  float local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  _String = strtok((char *)0x0,param_2);
  if (_String != (char *)0x0) {
    dVar1 = atof(_String);
    local_1c = -(float)dVar1;
    local_20 = 0;
    local_18 = 0;
    local_14 = 0;
    FUN_0055df80(&local_20);
  }
  return 1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
