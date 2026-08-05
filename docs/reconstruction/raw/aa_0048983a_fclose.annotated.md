# Annotated low-level: fclose

| Field | Value |
|---|---|
| Stable ID | `aa_0048983a` |
| VA | `0x0048983a` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0048983a`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int __cdecl fclose(FILE *_File)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0048983a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = fclose(_File);
  return iVar1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
