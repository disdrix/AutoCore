# Annotated low-level: _aligned_free

| Field | Value |
|---|---|
| Stable ID | `aa_005a4e30` |
| VA | `0x005a4e30` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005a4e30`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __cdecl _aligned_free(void *_Memory)

{
                    /* WARNING: Could not recover jumptable at 0x005a4e30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _aligned_free(_Memory);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
