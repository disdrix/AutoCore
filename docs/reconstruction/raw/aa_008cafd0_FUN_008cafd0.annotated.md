# Annotated low-level: FUN_008cafd0

| Field | Value |
|---|---|
| Stable ID | `aa_008cafd0` |
| VA | `0x008cafd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008cafd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_008cafd0(int param_1)

{
  *(undefined4 *)(param_1 + 0x4b8) = 0;
  *(undefined4 *)(param_1 + 0x4bc) = 0;
  *(undefined4 *)(param_1 + 0x4b4) = 0;
  *(undefined4 *)(param_1 + 0x504) = 0;
  *(undefined4 *)(param_1 + 0x508) = 0;
  *(undefined4 *)(param_1 + 0x924) = 0;
  *(undefined4 *)(param_1 + 0x928) = 0;
  *(undefined4 *)(param_1 + 0x92c) = 0;
  *(undefined4 *)(param_1 + 0x930) = 0;
  *(undefined4 *)(param_1 + 0x934) = 0;
  *(undefined4 *)(param_1 + 0x938) = 0;
  *(undefined4 *)(param_1 + 0x93c) = 0;
  *(undefined4 *)(param_1 + 0x940) = 0;
  *(undefined4 *)(param_1 + 0x944) = 0;
  if (*(int **)(param_1 + 0x948) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x948) + 0x458))();
  }
  if (*(int **)(param_1 + 0x94c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x94c) + 0x458))();
  }
  *(undefined4 *)(param_1 + 0x948) = 0;
  *(undefined4 *)(param_1 + 0x94c) = 0;
  *(undefined4 *)(param_1 + 0x950) = 0;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
