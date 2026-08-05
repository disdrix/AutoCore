# Annotated low-level: FUN_0095cfb0

| Field | Value |
|---|---|
| Stable ID | `aa_0095cfb0` |
| VA | `0x0095cfb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0095cfb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Removing unreachable block (ram,0x0095cfd8) */

void FUN_0095cfb0(void)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = &PTR_FUN_00aa99f0;
  if ((void *)unaff_ESI[5] == (void *)0x0) {
    unaff_ESI[5] = 0;
    unaff_ESI[6] = 0;
    unaff_ESI[7] = 0;
    unaff_ESI[5] = 0;
    unaff_ESI[6] = 0;
    unaff_ESI[7] = 0;
    FUN_00718c50();
    return;
  }
                    /* WARNING: Subroutine does not return */
  operator_delete((void *)unaff_ESI[5]);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
