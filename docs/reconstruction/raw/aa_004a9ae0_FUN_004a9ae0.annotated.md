# Annotated low-level: FUN_004a9ae0

| Field | Value |
|---|---|
| Stable ID | `aa_004a9ae0` |
| VA | `0x004a9ae0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004a9ae0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_004a9ae0(int param_1)

{
  void *pvVar1;
  
  pvVar1 = *(void **)(param_1 + 0x394);
  if (pvVar1 != (void *)0x0) {
    FUN_0096f510();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  *(undefined4 *)(param_1 + 0x394) = 0;
  if (*(undefined4 **)(param_1 + 0x390) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x390))(1);
  }
  *(undefined4 *)(param_1 + 0x390) = 0;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
