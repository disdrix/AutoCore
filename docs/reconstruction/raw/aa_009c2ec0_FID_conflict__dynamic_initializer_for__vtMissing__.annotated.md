# Annotated low-level: FID_conflict__dynamic_initializer_for__vtMissing__

| Field | Value |
|---|---|
| Stable ID | `aa_009c2ec0` |
| VA | `0x009c2ec0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_009c2ec0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Library Function - Multiple Matches With Different Base Names
    void __cdecl `dynamic initializer for 'vtMissing''(void)
    _$E1
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug */

void FID_conflict__dynamic_initializer_for__vtMissing__(void)

{
  _variant_t::_variant_t((_variant_t *)&DAT_00d09850,-0x7ffdfffc,10);
  _atexit(FUN_009c5cf0);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
