# Annotated low-level: isspace

| Field | Value |
|---|---|
| Stable ID | `aa_006a3d54` |
| VA | `0x006a3d54` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006a3d54`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int __cdecl isspace(int _C)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x006a3d54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = isspace(_C);
  return iVar1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
