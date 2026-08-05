# Annotated low-level: ftell

| Field | Value |
|---|---|
| Stable ID | `aa_006a3d48` |
| VA | `0x006a3d48` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006a3d48`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
long __cdecl ftell(FILE *_File)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x006a3d48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = ftell(_File);
  return lVar1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
