# Annotated low-level: FUN_007b7fb0

| Field | Value |
|---|---|
| Stable ID | `aa_007b7fb0` |
| VA | `0x007b7fb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007b7fb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Removing unreachable block (ram,0x007b7ff3) */

void FUN_007b7fb0(undefined4 param_1)

{
  undefined4 uVar1;
  wchar_t local_100 [128];
  
  uVar1 = (*(code *)PTR_FUN_00af8c9c)();
  FUN_00404b30(param_1,uVar1);
  wcscpy((wchar_t *)&DAT_00d09c78,local_100);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
