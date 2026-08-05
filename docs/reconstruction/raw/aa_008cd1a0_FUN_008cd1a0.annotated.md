# Annotated low-level: FUN_008cd1a0

| Field | Value |
|---|---|
| Stable ID | `aa_008cd1a0` |
| VA | `0x008cd1a0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008cd1a0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_008cd1a0(void)

{
  undefined4 in_EAX;
  int *unaff_ESI;
  
  DAT_00d1a980 = in_EAX;
  FUN_008cd070();
                    /* WARNING: Could not recover jumptable at 0x008cd1b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*unaff_ESI + 0x444))();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
