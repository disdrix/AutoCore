# Annotated low-level: select

| Field | Value |
|---|---|
| Stable ID | `aa_00717ec4` |
| VA | `0x00717ec4` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00717ec4`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int select(int nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,timeval *timeout)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00717ec4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = select(nfds,readfds,writefds,exceptfds,timeout);
  return iVar1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
