# Annotated low-level: _snprintf

| Field | Value |
|---|---|
| Stable ID | `aa_0048989e` |
| VA | `0x0048989e` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0048989e`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int __cdecl _snprintf(char *_Dest,size_t _Count,char *_Format,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0048989e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = _snprintf(_Dest,_Count,_Format);
  return iVar1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
