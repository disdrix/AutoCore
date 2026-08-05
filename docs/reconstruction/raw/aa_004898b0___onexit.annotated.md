# Annotated low-level: __onexit

| Field | Value |
|---|---|
| Stable ID | `aa_004898b0` |
| VA | `0x004898b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004898b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Library Function - Single Match
    __onexit
   
   Library: Visual Studio 2003 Release */

void __onexit(_onexit_t param_1)

{
  if (DAT_00d21a08 == -1) {
                    /* WARNING: Could not recover jumptable at 0x004898b9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    _onexit(param_1);
    return;
  }
  __dllonexit(param_1,&DAT_00d21a08,&DAT_00d21a04);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
