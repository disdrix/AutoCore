# Annotated low-level: FUN_008bcb80

| Field | Value |
|---|---|
| Stable ID | `aa_008bcb80` |
| VA | `0x008bcb80` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008bcb80`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_008bcb80(int param_1,undefined4 param_2)

{
  float10 fVar1;
  
  FUN_007916e0(param_2);
  if (((char)param_2 != '\0') && (*(int *)(param_1 + 0x524) != 0)) {
    fVar1 = (float10)(**(code **)(**(int **)(param_1 + 0x524) + 0x3c4))();
    if ((float10)g_flZero == fVar1) {
      (**(code **)(**(int **)(param_1 + 0x524) + 0xcc))(0);
      if (*(int *)(param_1 + 0x520) != 0) {
                    /* WARNING: Could not recover jumptable at 0x008bcbe4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(**(int **)(param_1 + 0x520) + 0xcc))();
        return;
      }
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
