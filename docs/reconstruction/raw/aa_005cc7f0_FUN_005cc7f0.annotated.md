# Annotated low-level: FUN_005cc7f0

| Field | Value |
|---|---|
| Stable ID | `aa_005cc7f0` |
| VA | `0x005cc7f0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005cc7f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __fastcall FUN_005cc7f0(int *param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  void *this;
  float10 fVar7;
  undefined4 *pTeleportData;
  undefined4 auStack_20 [3];
  undefined4 uStack_14;
  
  iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1[0x19] + 4) + 4) + 4 + param_1[0x19]) +
                      0x19c))();
  iVar4 = *(int *)(iVar4 + 8);
  if (iVar4 != 0) {
    if ((*(char *)(iVar4 + 0x40) == '\0') || (*(int *)(iVar4 + 8) == 0)) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    if (bVar3) {
      iVar4 = param_1[0x19];
      uStack_14 = *(undefined4 *)(iVar4 + 0x234);
      iVar4 = FUN_004baec0(*(undefined4 *)(iVar4 + 0x230),*(undefined4 *)(iVar4 + 0x228),
                           *(undefined4 *)(iVar4 + 0x22c));
      if (iVar4 != 0) {
        iVar1 = param_1[0x19];
        iVar2 = *(int *)(*(int *)(iVar1 + 4) + 4);
        uVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x19c))();
        (**(code **)(*(int *)(iVar2 + 4 + iVar1) + 0x19c))(uVar5);
        fVar7 = (float10)FUN_0053e510(uVar5);
        iVar1 = param_1[0x19];
        if (*(float *)(iVar1 + 0x270) < (float)fVar7) {
          if ((0.0 < *(float *)(iVar1 + 0x310) || *(float *)(iVar1 + 0x310) == 0.0) &&
             (*(float *)(iVar1 + 0x310) < (float)fVar7)) {
            iVar4 = *(int *)(*(int *)(iVar4 + 4) + 4) + iVar4;
            uVar5 = *(undefined4 *)(iVar4 + 0xa8);
            uVar6 = (**(code **)(*(int *)(iVar4 + 4) + 0x1a0))
                              (0x41700000,0x40a00000,auStack_20,1,5,0);
            FUN_004e9720(uVar5,uVar6);
            pTeleportData = auStack_20;
            this = (void *)(**(code **)(*(int *)(*(int *)(*(int *)(param_1[0x19] + 4) + 4) + 4 +
                                                param_1[0x19]) + 0x19c))();
            CVOGReaction_TeleportTarget(this,pTeleportData);
            return 1;
          }
          iVar1 = *param_1;
          uVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x1a0))(1);
          (**(code **)(iVar1 + 0x4c))(uVar5);
          return 1;
        }
      }
    }
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
