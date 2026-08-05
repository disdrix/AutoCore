# Annotated low-level: FUN_009c5bf0

| Field | Value |
|---|---|
| Stable ID | `aa_009c5bf0` |
| VA | `0x009c5bf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_009c5bf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_009c5bf0(void)

{
  _DAT_00d095f0 = &PTR_FUN_009d81e8;
  if ((char)(DAT_00d095f4 >> 8) < '\0') {
    DAT_00d095f4 = DAT_00d095f4 & 0xffff7fff;
    FUN_005ffdb0(0);
  }
  _DAT_00d095f0 = &PTR_LAB_009cc290;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
