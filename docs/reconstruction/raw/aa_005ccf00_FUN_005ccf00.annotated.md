# Annotated low-level: FUN_005ccf00

| Field | Value |
|---|---|
| Stable ID | `aa_005ccf00` |
| VA | `0x005ccf00` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005ccf00`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
uint __fastcall FUN_005ccf00(int param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = *(int *)(param_1 + 100);
  if ((iVar2 != 0) &&
     (iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x27c))(),
     iVar2 < 6)) {
    iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 100) + 4) + 4) + 4 +
                                 *(int *)(param_1 + 100)) + 0x27c))();
    if (iVar2 + -3 < 2) {
      iVar2 = 1;
    }
    else {
      iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 100) + 4) + 4) + 4 +
                                   *(int *)(param_1 + 100)) + 0x27c))();
      iVar2 = iVar2 + -3;
    }
    iVar3 = CVOGReaction_RandomUnitScalar();
    if (0xfffff < *(int *)(iVar3 + 0xc)) {
      *(undefined4 *)(iVar3 + 0xc) = 0;
    }
    uVar1 = *(ushort *)(*(int *)(iVar3 + 8) + *(int *)(iVar3 + 0xc) * 2);
    *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + 1;
    iVar3 = (int)((longlong)(ulonglong)uVar1 % (longlong)iVar2) - iVar2 / 2;
    if (iVar3 < 0) {
      iVar3 = iVar3 + 0xc;
    }
    *(byte *)(param_1 + 0x6c) = (byte)iVar3;
    if ((byte)iVar3 < 0xc) {
      return iVar2 / 2;
    }
  }
  iVar2 = CVOGReaction_RandomUnitScalar();
  if (0xfffff < *(int *)(iVar2 + 0xc)) {
    *(undefined4 *)(iVar2 + 0xc) = 0;
  }
  uVar1 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);
  *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;
  uVar4 = (uint)uVar1;
  *(char *)(param_1 + 0x6c) = (char)((ulonglong)uVar4 % 0xc);
  return uVar4 / 0xc;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
