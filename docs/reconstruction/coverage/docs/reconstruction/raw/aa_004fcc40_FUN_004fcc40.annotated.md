# Annotated low-level: FUN_004fcc40

| Field | Value |
|---|---|
| Stable ID | `aa_004fcc40` |
| VA | `0x004fcc40` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004fcc40`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_004fcc40(int param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 0x330);
  if (puVar2 != *(undefined4 **)(param_1 + 0x334)) {
    do {
      pvVar1 = (void *)*puVar2;
      FUN_004b7150();
      if (pvVar1 != (void *)0x0) {
        FUN_004b99c0();
                    /* WARNING: Subroutine does not return */
        operator_delete(pvVar1);
      }
      puVar2 = puVar2 + 1;
    } while (puVar2 != *(undefined4 **)(param_1 + 0x334));
  }
  if (*(void **)(param_1 + 0x330) == (void *)0x0) {
    *(undefined4 *)(param_1 + 0x330) = 0;
    *(undefined4 *)(param_1 + 0x334) = 0;
    *(undefined4 *)(param_1 + 0x338) = 0;
    return;
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(*(void **)(param_1 + 0x330));
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
