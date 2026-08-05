# Annotated low-level: FUN_005acc90

| Field | Value |
|---|---|
| Stable ID | `aa_005acc90` |
| VA | `0x005acc90` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005acc90`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int __thiscall FUN_005acc90(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*(char *)(param_1 + 0x6d) != '\0') {
    local_4 = param_3;
    local_8 = param_2;
    piVar2 = (int *)FUN_005ae140(&local_8);
    piVar1 = *(int **)(param_1 + 0x80);
    if (piVar2 != (int *)*piVar1) {
      FUN_005adff0();
    }
    if (piVar2 != piVar1) {
      return piVar2[6];
    }
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
