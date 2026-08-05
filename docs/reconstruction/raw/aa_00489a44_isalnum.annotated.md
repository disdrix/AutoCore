# Annotated low-level: isalnum

| Field | Value |
|---|---|
| Stable ID | `aa_00489a44` |
| VA | `0x00489a44` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00489a44`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int __cdecl isalnum(int _C)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00489a44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = isalnum(_C);
  return iVar1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
