# Annotated low-level: FUN_004ebfd0

| Field | Value |
|---|---|
| Stable ID | `aa_004ebfd0` |
| VA | `0x004ebfd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004ebfd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_004ebfd0(int param_1)

{
  void *pvVar1;
  
  pvVar1 = *(void **)(param_1 + 0x88);
  if (pvVar1 != (void *)0x0) {
    FUN_004a2670();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  *(undefined4 *)(param_1 + 0x88) = 0;
  FUN_004eb3b0();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
