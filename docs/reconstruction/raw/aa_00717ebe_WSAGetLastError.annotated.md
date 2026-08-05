# Annotated low-level: WSAGetLastError

| Field | Value |
|---|---|
| Stable ID | `aa_00717ebe` |
| VA | `0x00717ebe` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00717ebe`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int WSAGetLastError(void)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00717ebe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = WSAGetLastError();
  return iVar1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
