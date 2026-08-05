# Annotated low-level: FUN_0094eda0

| Field | Value |
|---|---|
| Stable ID | `aa_0094eda0` |
| VA | `0x0094eda0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0094eda0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_0094eda0(undefined4 param_1,char *param_2)

{
  char *_String;
  int iVar1;
  double dVar2;
  float local_8 [2];
  
  _String = strtok((char *)0x0,param_2);
  if (_String != (char *)0x0) {
    iVar1 = 0;
    do {
      dVar2 = atof(_String);
      local_8[iVar1] = (float)dVar2;
      iVar1 = iVar1 + 1;
      _String = strtok((char *)0x0,param_2);
    } while (_String != (char *)0x0);
    if (iVar1 == 2) {
      DAT_00aefa5c = local_8[0];
      DAT_00aefa58 = local_8[1];
    }
  }
  return 1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
