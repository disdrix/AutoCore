# Annotated low-level: FUN_009bfa50

| Field | Value |
|---|---|
| Stable ID | `aa_009bfa50` |
| VA | `0x009bfa50` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_009bfa50`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_009bfa50(void)

{
  BOOL BVar1;
  LARGE_INTEGER local_8;
  
  BVar1 = QueryPerformanceFrequency(&local_8);
  DAT_00d1eaa0 = BVar1 != 0;
  _DAT_00d1ea98 = _DAT_00aaa658 / (double)(longlong)local_8;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
