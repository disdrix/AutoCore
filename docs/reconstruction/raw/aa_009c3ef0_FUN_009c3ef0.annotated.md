# Annotated low-level: FUN_009c3ef0

| Field | Value |
|---|---|
| Stable ID | `aa_009c3ef0` |
| VA | `0x009c3ef0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_009c3ef0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_009c3ef0(void)

{
  _DAT_00d02688 = &PTR_FUN_009d81e8;
  if ((DAT_00d0268d & 0x80) != 0) {
    DAT_00d0268d = DAT_00d0268d & 0x7f;
    FUN_005ffdb0(0);
  }
  _DAT_00d02688 = &PTR_LAB_009cc290;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
