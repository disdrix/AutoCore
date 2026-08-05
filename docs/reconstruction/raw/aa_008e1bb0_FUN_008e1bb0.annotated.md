# Annotated low-level: FUN_008e1bb0

| Field | Value |
|---|---|
| Stable ID | `aa_008e1bb0` |
| VA | `0x008e1bb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008e1bb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_008e1bb0(void)

{
  int unaff_ESI;
  char local_100 [256];
  
  if ((*(int *)(unaff_ESI + 0x51c) != 0) && (DAT_00d1b6d8 != 0)) {
    sprintf(local_100,"%i",(int)*(short *)(DAT_00d1b6d8 + 0x580));
    (**(code **)(**(int **)(unaff_ESI + 0x51c) + 0x1d8))(local_100,1,1);
    (**(code **)(**(int **)(unaff_ESI + 0x51c) + 0x34c))();
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
