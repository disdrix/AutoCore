# Annotated low-level: FUN_004bbbc0

| Field | Value |
|---|---|
| Stable ID | `aa_004bbbc0` |
| VA | `0x004bbbc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004bbbc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_004bbbc0(int param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x140);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)CVOGReaction_ResolveObjectTarget
                              (*(undefined4 *)(param_1 + 0x130),*(uint *)(param_1 + 0x128),
                               *(undefined4 *)(param_1 + 300));
    *(int **)(param_1 + 0x140) = piVar2;
    if (piVar2 == (int *)0x0) {
      if ((*(uint *)(param_1 + 0x128) & *(uint *)(param_1 + 300)) == 0xffffffff) {
        return 1;
      }
      return 0;
    }
  }
  (**(code **)(*piVar2 + 0x144))();
  *(int *)(param_1 + 0x10) = piVar2[0x20];
  *(int *)(param_1 + 0x14) = piVar2[0x21];
  *(int *)(param_1 + 0x18) = piVar2[0x22];
  *(int *)(param_1 + 0x1c) = piVar2[0x23];
  uVar1 = (**(code **)(*piVar2 + 0x198))();
  *param_2 = uVar1;
  return 1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
