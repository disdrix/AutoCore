# Annotated low-level: WSACleanup

| Field | Value |
|---|---|
| Stable ID | `aa_009c53c0` |
| VA | `0x009c53c0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_009c53c0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int WSACleanup(void)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x009c53c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = WSACleanup();
  return iVar1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
