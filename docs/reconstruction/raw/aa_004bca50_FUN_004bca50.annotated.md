# Annotated low-level: FUN_004bca50

| Field | Value |
|---|---|
| Stable ID | `aa_004bca50` |
| VA | `0x004bca50` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004bca50`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall FUN_004bca50(int param_1,int *param_2)

{
  undefined4 *puVar1;
  
  if ((param_2 != (int *)0x0) && (puVar1 = (undefined4 *)*param_2, puVar1 != (undefined4 *)0x0)) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
    if (*(char *)(param_1 + 0x28) == '\0') {
      puVar1[1] = 0;
      FUN_004bc8e0(puVar1);
      (**(code **)*puVar1)(1);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
    return 0;
  }
  return 0x80070057;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
