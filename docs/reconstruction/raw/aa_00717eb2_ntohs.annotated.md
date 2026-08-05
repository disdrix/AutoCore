# Annotated low-level: ntohs

| Field | Value |
|---|---|
| Stable ID | `aa_00717eb2` |
| VA | `0x00717eb2` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00717eb2`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
u_short ntohs(u_short netshort)

{
  u_short uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00717eb2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = ntohs(netshort);
  return uVar1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
