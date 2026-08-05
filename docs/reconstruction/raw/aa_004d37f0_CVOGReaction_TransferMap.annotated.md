# Annotated low-level: CVOGReaction_TransferMap

| Field | Value |
|---|---|
| Stable ID | `aa_004d37f0` |
| VA | `0x004d37f0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004d37f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall CVOGReaction_TransferMap(int param_1,int *param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  
  if ((((*(char *)(param_1 + 0x7e) != '\0') && (param_2 != (int *)0x0)) &&
      (iVar2 = (**(code **)(*param_2 + 0x210))(0), iVar2 != 0)) &&
     ((*(char *)(iVar2 + 0x4f4) == '\0' &&
      (cVar1 = FUN_004d2ac0(iVar2,param_2,param_3), cVar1 != '\0')))) {
    *(undefined1 *)(iVar2 + 0x4f4) = 1;
    FUN_004025e0(&stack0xffffffd4);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
