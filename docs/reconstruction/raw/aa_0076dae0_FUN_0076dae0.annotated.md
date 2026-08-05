# Annotated low-level: FUN_0076dae0

| Field | Value |
|---|---|
| Stable ID | `aa_0076dae0` |
| VA | `0x0076dae0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0076dae0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * FUN_0076dae0(void)

{
  if ((_DAT_00d1f8a4 & 1) == 0) {
    _DAT_00d1f8a4 = _DAT_00d1f8a4 | 1;
    DAT_00d1f898 = '\0';
    _DAT_00d1f89c = 0;
    _DAT_00d1f8a0 = 0;
    _atexit((_func_4879 *)&LAB_009c3280);
  }
  if (DAT_00d1f898 == '\0') {
    FUN_0076d6f0();
  }
  return &DAT_00d1f898;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
