# Annotated low-level: htonl

| Field | Value |
|---|---|
| Stable ID | `aa_00717eca` |
| VA | `0x00717eca` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00717eca`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
u_long htonl(u_long hostlong)

{
  u_long uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00717eca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = htonl(hostlong);
  return uVar1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
