# Annotated low-level: FUN_008ffe20

| Field | Value |
|---|---|
| Stable ID | `aa_008ffe20` |
| VA | `0x008ffe20` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008ffe20`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_008ffe20(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  NDUIWindow_ReloadInterface(param_2);
  if ((int *)param_1[0x1cc] != (int *)0x0) {
    iVar1 = (**(code **)(*(int *)param_1[0x1cc] + 0x1a8))();
    *(undefined1 *)(iVar1 + 0x78) = 0;
  }
  iVar1 = DAT_00aaabe4;
  param_1[0x1a] = 7;
  param_1[0x1d] = iVar1;
  if (param_1[0x1c] < 7) {
    param_1[0x1c] = 7;
  }
  FUN_008ff260();
  FUN_008fee00(param_1);
  (**(code **)(*param_1 + 0x448))();
  (**(code **)(*param_1 + 0x34c))();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
