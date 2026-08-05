# Annotated low-level: getsockname

| Field | Value |
|---|---|
| Stable ID | `aa_00717eac` |
| VA | `0x00717eac` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00717eac`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int getsockname(SOCKET s,sockaddr *name,int *namelen)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00717eac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = getsockname(s,name,namelen);
  return iVar1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
