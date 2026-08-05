# Annotated low-level: FUN_0053dac0

| Field | Value |
|---|---|
| Stable ID | `aa_0053dac0` |
| VA | `0x0053dac0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0053dac0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0053dac0(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined2 extraout_var;
  uint uVar3;
  
  if (*(int *)(param_1 + 8) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 8) + 0x28) = *(undefined4 *)(param_1 + 0x18);
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    uVar3 = 0;
    iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x4c))();
    if (iVar1 != 0) {
      do {
        iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x50))();
        (**(code **)(**(int **)(iVar1 + uVar3 * 4) + 8))
                  (CONCAT22(extraout_var,*(undefined2 *)(param_1 + 0x1c)));
        uVar3 = uVar3 + 1;
        uVar2 = (**(code **)(**(int **)(param_1 + 0xc) + 0x4c))();
      } while (uVar3 < uVar2);
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
