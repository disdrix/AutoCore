# Annotated low-level: inet_addr

| Field | Value |
|---|---|
| Stable ID | `aa_00717ed0` |
| VA | `0x00717ed0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00717ed0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
ulong inet_addr(char *cp)

{
  ulong uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00717ed0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = inet_addr(cp);
  return uVar1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
