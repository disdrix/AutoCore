# Annotated low-level: _com_issue_error

| Field | Value |
|---|---|
| Stable ID | `aa_00717f00` |
| VA | `0x00717f00` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00717f00`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Library Function - Single Match
    void __stdcall _com_issue_error(long)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug */

void _com_issue_error(long param_1)

{
  (*(code *)PTR_FUN_00af8b20)(param_1,0);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
