# Raw capture: CVOGHBAICreatureBase_DecideHeading

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d0840` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005d0840` |
| **Canonical name** | `CVOGHBAICreatureBase_DecideHeading` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Decide heading direction for creature movement.
   
   Parameters:
   this - Creature pointer
   fDeltaTime - Time delta for rotation speed
   pDirection - Target direction vector (xyz)
   
   Algorithm:
   1. Check if time since last decision (FUN_004c56a0) > threshold
   2. Validate creature via vtable +0x214 and +0xbc (state check at +0x6bc)
   3. Calculate direction difference from current position vs target
   4. If direction difference is zero, use stored position (offsets +0x50-0x5c)
   5. If direction changed:
      - Get rotation matrix from +0x30-0x3c
      - Calculate heading angle via acos
      - Check if forward component < 0, adjust angle
      - Apply rotation limit based on deltaTime
      - Call vtable +0x54 to set new heading
   
   Uses global position constants:
   DAT_00bc5570, DAT_00bc5574, DAT_00bc5578: World position reference
   DAT_00bc557c: Height reference */

void __thiscall CVOGHBAICreatureBase_DecideHeading(void *this,float fDeltaTime,float *pDirection)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  float10 fVar4;
  undefined1 uStack_81;
  float fStack_80;
  float fStack_7c;
  undefined4 local_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  undefined4 uStack_60;
  float fStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  undefined1 auStack_40 [4];
  float fStack_3c;
  undefined1 auStack_30 [20];
  void *pvStack_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_009a6fe0;
  pvStack_1c = ExceptionList;
  local_78 = DAT_00d1f040;
  ExceptionList = &pvStack_1c;
  FUN_0076cf00("CVOGHBAICreatureBase::DecideHeading");
  local_14 = 0;
  fVar4 = (float10)FUN_004c56a0();
  if ((((float10)g_flZero < fVar4) &&
      ((iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)((int)this + 100) + 4) + 4) + 4 +
                                     *(int *)((int)this + 100)) + 0x210))(0), iVar2 == 0 ||
       (iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)((int)this + 100) + 4) + 4) + 4 +
                                     *(int *)((int)this + 100)) + 0x210))(0),
       *(char *)(iVar2 + 0x6bc) == '\0')))) &&
     ((iVar2 = (**(code **)(**(int **)((int)this + 100) + 0xbc))(), iVar2 == 0 ||
      (iVar2 = (**(code **)(**(int **)((int)this + 100) + 0xbc))(), *(char *)(iVar2 + 0x6bc) == '\0'
      )))) {
    fStack_74 = (float)((uint)(DAT_00a0f718 <
                              ABS(pDirection[2] - (float)g_abInferredDefaultAimPos._8_4_)) * 2 |
                        (uint)(DAT_00a0f718 <
                              ABS(pDirection[1] - (float)g_abInferredDefaultAimPos._4_4_)) * 4 |
                       (uint)(DAT_00a0f718 <
                             ABS(*pDirection - (float)g_abInferredDefaultAimPos._0_4_)) * -8 & 0xe);
    if (fStack_74 == 0.0) {
      iVar2 = *(int *)(*(int *)(*(int *)((int)this + 100) + 8) + 0x3c);
      fStack_70 = ABS(*(float *)(iVar2 + 0x50) - (float)g_abInferredDefaultAimPos._0_4_);
      fStack_6c = ABS(*(float *)(iVar2 + 0x54) - (float)g_abInferredDefaultAimPos._4_4_);
      fStack_68 = ABS(*(float *)(iVar2 + 0x58) - (float)g_abInferredDefaultAimPos._8_4_);
      fStack_64 = ABS(*(float *)(iVar2 + 0x5c) - (float)g_abInferredDefaultAimPos._12_4_);
      fStack_74 = (float)((uint)(g_flMsToSeconds_Inferred < fStack_68) * 2 |
                          (uint)(g_flMsToSeconds_Inferred < fStack_6c) * 4 |
                         (uint)(g_flMsToSeconds_Inferred < fStack_70) * -8 & 0xe);
      if (fStack_74 != 0.0) {
        FUN_0040d040(g_abInferredDefaultAimPos);
      }
    }
    else {
      iVar2 = *(int *)(*(int *)(*(int *)((int)this + 100) + 8) + 0x3c);
      fStack_70 = *(float *)(iVar2 + 0x30);
      fStack_6c = *(float *)(iVar2 + 0x34);
      fStack_68 = *(float *)(iVar2 + 0x38);
      fStack_64 = *(float *)(iVar2 + 0x3c);
      FUN_004e8a40(&fStack_70,auStack_30);
      FUN_004e8ad0(&fStack_70,&fStack_50);
      fStack_80 = ABS(fStack_64);
      if (ABS(fStack_80) < g_flOne) {
        fVar4 = (float10)_CIacos();
        fStack_7c = (float)fVar4;
      }
      else {
        fStack_7c = 0.0;
        if (fStack_80 <= 0.0) {
          fStack_7c = DAT_009da860;
        }
      }
      fStack_7c = fStack_7c * g_flLevelUpUiBase_Inferred;
      if ((_DAT_009da864 <
           SQRT(fStack_70 * fStack_70 + fStack_6c * fStack_6c + fStack_68 * fStack_68)) &&
         (FUN_005d1c00(auStack_40), fStack_3c < 0.0)) {
        fStack_7c = DAT_00aaa7dc - fStack_7c;
      }
      fStack_74 = pDirection[2] * _DAT_00af41e8 + pDirection[1] * _DAT_00af41e4 +
                  *pDirection * _DAT_00af41e0;
      fStack_80 = _DAT_00af41d0 * *pDirection +
                  _DAT_00af41d4 * pDirection[1] + _DAT_00af41d8 * pDirection[2];
      if (ABS(fStack_80) < g_flOne) {
        fVar4 = (float10)_CIacos();
        fStack_80 = (float)fVar4;
      }
      else {
        bVar1 = fStack_80 <= 0.0;
        fStack_80 = 0.0;
        if (bVar1) {
          fStack_80 = DAT_009da860;
        }
      }
      if (fStack_74 < 0.0) {
        fStack_80 = DAT_00aaa7dc - fStack_80;
      }
      fStack_80 = ABS(fStack_80 - fStack_7c);
      if (g_flMsToSeconds_Inferred <= fStack_80) {
        fVar4 = (float10)FUN_004c56a0();
        if (fVar4 * (float10)fDeltaTime < (float10)fStack_80) {
          fVar4 = (float10)FUN_004c56a0();
          fStack_80 = (float)fVar4;
        }
        fStack_5c = fStack_80;
        if (*pDirection * fStack_50 + pDirection[2] * fStack_48 + pDirection[1] * fStack_4c < 0.0) {
          fStack_5c = fStack_80 * DAT_00aaa668;
        }
      }
      else {
        fStack_5c = 0.0;
      }
      uStack_60 = 0;
      uStack_58 = 0;
      uStack_54 = 0;
      iVar2 = *(int *)(*(int *)((int)this + 100) + 8);
      pcVar3 = (char *)FUN_005070b0(&uStack_81);
      if ((*pcVar3 == '\0') && (*(int *)(iVar2 + 0x44) != 0)) {
        FUN_005070d0();
      }
      (**(code **)(**(int **)(iVar2 + 0x3c) + 0x54))(&uStack_60);
    }
  }
  local_14 = 0xffffffff;
  FUN_0076cef0();
  ExceptionList = pvStack_1c;
  return;
}
```
