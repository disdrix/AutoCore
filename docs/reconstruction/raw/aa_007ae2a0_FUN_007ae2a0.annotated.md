# Annotated low-level: FUN_007ae2a0

| Field | Value |
|---|---|
| Stable ID | `aa_007ae2a0` |
| VA | `0x007ae2a0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007ae2a0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_007ae2a0(int param_1)

{
  int iVar1;
  int iVar2;
  int local_8;
  undefined4 local_4;
  
  local_4 = 0;
  local_8 = 0;
  FUN_004294f0();
  iVar2 = FUN_00423f40(&local_8);
  iVar1 = local_8;
  while( true ) {
    local_8 = iVar1;
    if (iVar2 != 0) {
      if (DAT_00d1e848 != '\0') {
        DAT_00d1e848 = '\0';
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00d1e824);
      }
      return 0;
    }
    if ((iVar1 != 0) && (*(int *)(iVar1 + 8) == param_1)) break;
    iVar2 = FUN_00423f40(&local_8);
    iVar1 = local_8;
  }
  if (DAT_00d1e848 != '\0') {
    DAT_00d1e848 = '\0';
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00d1e824);
  }
  return *(undefined4 *)(iVar1 + 4);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
