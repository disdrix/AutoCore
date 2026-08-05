# Annotated low-level: FUN_005aca60

| Field | Value |
|---|---|
| Stable ID | `aa_005aca60` |
| VA | `0x005aca60` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005aca60`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int __thiscall FUN_005aca60(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  float *pfVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  int local_24;
  
  iVar4 = CVOGReaction_RandomUnitScalar();
  if (0xfffff < *(int *)(iVar4 + 0xc)) {
    *(undefined4 *)(iVar4 + 0xc) = 0;
  }
  uVar1 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);
  *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;
  iVar4 = (int)((longlong)(ulonglong)uVar1 % (longlong)*(int *)(param_1 + 0x58));
  bVar3 = false;
  local_24 = 100000;
  do {
    if (iVar4 == param_3) {
      iVar4 = (iVar4 + 1) % *(int *)(param_1 + 0x58);
    }
    iVar5 = FUN_004bb1c0(0,*(undefined4 *)(*(int *)(param_1 + 0x4c) + iVar4 * 8),
                         *(undefined4 *)(*(int *)(param_1 + 0x4c) + 4 + iVar4 * 8));
    if (iVar5 == 0) {
LAB_005acb95:
      iVar4 = CVOGReaction_RandomUnitScalar();
      if (0xfffff < *(int *)(iVar4 + 0xc)) {
        *(undefined4 *)(iVar4 + 0xc) = 0;
      }
      uVar1 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);
      *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;
      iVar4 = (int)((longlong)(ulonglong)uVar1 % (longlong)*(int *)(param_1 + 0x58));
    }
    else {
      iVar2 = *(int *)(*(int *)(iVar5 + 4) + 4);
      fVar7 = *(float *)(iVar2 + 0x84 + iVar5);
      iVar5 = iVar2 + 0x84 + iVar5;
      fVar8 = *(float *)(iVar5 + 4);
      fVar9 = *(float *)(iVar5 + 8);
      pfVar6 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) +
                                    0x1a0))();
      fVar7 = fVar7 - *pfVar6;
      fVar8 = fVar8 - pfVar6[1];
      fVar9 = fVar9 - pfVar6[2];
      if ((float)local_24 <= SQRT(fVar7 * fVar7 + fVar8 * fVar8 + fVar9 * fVar9)) goto LAB_005acb95;
      bVar3 = true;
    }
    local_24 = local_24 + 1000;
    if (bVar3) {
      return iVar4;
    }
  } while( true );
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
