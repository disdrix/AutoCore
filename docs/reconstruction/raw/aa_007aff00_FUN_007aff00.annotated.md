# Annotated low-level: FUN_007aff00

| Field | Value |
|---|---|
| Stable ID | `aa_007aff00` |
| VA | `0x007aff00` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007aff00`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_007aff00(int param_1)

{
  void *pvVar1;
  
  if (*(int *)(param_1 + 0x20c) != 0) {
    pvVar1 = *(void **)(param_1 + 0x28c);
    if (pvVar1 != (void *)0x0) {
      FUN_00797d70(pvVar1);
                    /* WARNING: Subroutine does not return */
      operator_delete(pvVar1);
    }
    *(undefined4 *)(param_1 + 0x28c) = 0;
  }
  FUN_00424060();
  *(undefined4 *)(param_1 + 0x128) = 0;
  *(undefined4 *)(param_1 + 300) = 0;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
