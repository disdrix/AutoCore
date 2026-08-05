# Annotated low-level: FUN_006a1ec0

| Field | Value |
|---|---|
| Stable ID | `aa_006a1ec0` |
| VA | `0x006a1ec0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006a1ec0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_006a1ec0(int param_1)

{
  void *pvVar1;
  
  pvVar1 = *(void **)(param_1 + 0x58);
  if (pvVar1 != (void *)0x0) {
    FUN_006a1100();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  pvVar1 = *(void **)(param_1 + 0x5c);
  if (pvVar1 != (void *)0x0) {
    FUN_006a1100();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  pvVar1 = *(void **)(param_1 + 0x54);
  if (pvVar1 != (void *)0x0) {
    FUN_006a1100();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  pvVar1 = *(void **)(param_1 + 0x50);
  if (pvVar1 != (void *)0x0) {
    FUN_006a1100();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  pvVar1 = *(void **)(param_1 + 0x6c);
  if (pvVar1 != (void *)0x0) {
    FUN_006a1100();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  pvVar1 = *(void **)(param_1 + 100);
  if (pvVar1 != (void *)0x0) {
    FUN_006a1100();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  pvVar1 = *(void **)(param_1 + 0x68);
  if (pvVar1 != (void *)0x0) {
    FUN_006a1100();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  pvVar1 = *(void **)(param_1 + 0x60);
  if (pvVar1 != (void *)0x0) {
    FUN_006a1100();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  pvVar1 = *(void **)(param_1 + 0x70);
  if (pvVar1 != (void *)0x0) {
    FUN_006a1100();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
