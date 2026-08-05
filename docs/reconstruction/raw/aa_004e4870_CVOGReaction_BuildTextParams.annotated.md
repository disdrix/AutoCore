# Annotated low-level: CVOGReaction_BuildTextParams

| Field | Value |
|---|---|
| Stable ID | `aa_004e4870` |
| VA | `0x004e4870` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004e4870`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall CVOGReaction_BuildTextParams(int param_1,undefined4 param_2)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 4);

  iVar2 = FUN_004e29c0(iVar1,*(undefined4 *)(iVar1 + 4),param_2);

  FUN_004e29f0(1);

  *(int *)(iVar1 + 4) = iVar2;

  **(int **)(iVar2 + 4) = iVar2;

  return;

}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.

## Human refine (2026-07-23, priority_012)

- human-refined clean: list insert at this+0x04 via FUN_004e29c0/0x004e29f0
- Clean: docs/reconstruction/reconstructed-exact/CVOGReaction_BuildTextParams.cpp
- Dual review: open

