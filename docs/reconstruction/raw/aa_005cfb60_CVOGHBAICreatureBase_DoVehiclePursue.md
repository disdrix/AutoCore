# Raw capture: CVOGHBAICreatureBase_DoVehiclePursue

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cfb60` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005cfb60` |
| **Canonical name** | `CVOGHBAICreatureBase_DoVehiclePursue` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Vehicle pursuit logic - steering and aiming toward target.
   
   Parameters:
   this - Driver AI pointer
   
   Algorithm:
   1. Get vehicle reference from this+0x19+0x250
   2. Check if active target exists (this+0x6+0xa0), get position via vtable +0x1c8
   3. Check if target alive via vtable +0x198
   4. Calculate target-relative offset based on vehicle type (+0x84 for ground, +0xb0 for air)
   5. Set destination via vtable +0x4c
   6. Get pursuit target from this+0x19+0xb0
   7. Calculate direction vector to target:
      - Get target position (FUN_0053e510)
      - Normalize direction vector
      - Apply max direction clamp (DAT_009da864)
   8. If flag +0xb8 bit 6 is set: scaled pursuit vector
   9. Otherwise:
      - If within speed threshold (target+0x124):
        - Calculate heading via FUN_005cc460
        - Build rotation matrix via FUN_00567ce0
        - Transform pursuit direction
      - Else: direct vector pursuit
   10. Apply velocity via vtable +0x4c */

void __fastcall CVOGHBAICreatureBase_DoVehiclePursue(int *this)

{
  int *piVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  float10 fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fStack_7c;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float afStack_40 [4];
  undefined1 auStack_30 [20];
  void *pvStack_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_009a6fbc;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  FUN_0076cf00("CVOGHBAICreatureBase::DoVehiclePursue");
  iVar6 = *(int *)(this[0x19] + 0x250);
  local_14 = 0;
  if (((*(int **)(this[6] + 0xa0) != (int *)0x0) &&
      (iVar4 = (**(code **)(**(int **)(this[6] + 0xa0) + 0x1c8))(), iVar4 != 0)) &&
     (cVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0x198))(),
     cVar3 == '\0')) {
    if (*(int *)(iVar4 + 8) == 0) {
      iVar5 = *(int *)(*(int *)(iVar4 + 4) + 4) + 0x84 + iVar4;
    }
    else {
      iVar5 = *(int *)(*(int *)(iVar4 + 8) + 0x3c) + 0xb0;
    }
    (**(code **)(*this + 0x4c))(iVar5,0);
    piVar1 = *(int **)(*(int *)(*(int *)(iVar6 + 4) + 4) + 0xb0 + iVar6);
    if ((piVar1 != (int *)0x0) && (iVar5 = (**(code **)(*piVar1 + 0x1d8))(), iVar5 != 0)) {
      fVar8 = (float10)FUN_0053e510(iVar4);
      fVar10 = (float)fVar8;
      iVar6 = (**(code **)(**(int **)(*(int *)(*(int *)(iVar6 + 4) + 4) + 0xb0 + iVar6) + 0x1d8))();
      uVar2 = *(uint *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 0xb8 + iVar6);
      if ((uVar2 & 0x40) == 0) {
        if ((char)uVar2 < '\0') {
          pfVar7 = (float *)FUN_00404c90();
          fStack_60 = *pfVar7;
          fStack_5c = pfVar7[1];
          fStack_58 = pfVar7[2];
          fStack_54 = pfVar7[3];
          pfVar7 = (float *)FUN_00404c90();
          fStack_60 = fStack_60 - *pfVar7;
          fStack_5c = fStack_5c - pfVar7[1];
          fStack_58 = fStack_58 - pfVar7[2];
          fStack_54 = fStack_54 - pfVar7[3];
          fVar10 = fStack_58 * fStack_58 + fStack_5c * fStack_5c + fStack_60 * fStack_60;
          if (_DAT_009da864 < SQRT(fVar10)) {
            if (fVar10 == 0.0) {
              fVar10 = 0.0;
            }
            else {
              fVar10 = g_flOne / SQRT(fVar10);
            }
            fStack_60 = fVar10 * fStack_60;
            fStack_5c = fStack_5c * fVar10;
            fStack_58 = fStack_58 * fVar10;
            fStack_54 = fStack_54 * fVar10;
          }
          pfVar7 = (float *)FUN_00404c90();
          fVar10 = pfVar7[2] * fStack_58 + pfVar7[1] * fStack_5c + *pfVar7 * fStack_60;
          fStack_5c = fStack_5c * fVar10;
          fStack_60 = fVar10 * fStack_60;
          fStack_58 = fStack_58 * fVar10;
          fStack_54 = fStack_54 * fVar10;
          (**(code **)(*this + 0x4c))(&fStack_60,1);
        }
        else if (fVar10 < *(float *)(iVar6 + 0x124)) {
          fStack_7c = 0.0;
          cVar3 = FUN_005cc460(iVar6);
          if (cVar3 != '\0') {
            pfVar7 = &fStack_60;
            (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x1a4))(pfVar7);
            FUN_005d1c00(pfVar7);
            (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x1a4))();
            fVar8 = (float10)FUN_005d1bb0();
            fStack_7c = (float)fVar8;
            if (fStack_5c < 0.0) {
              fStack_7c = 0.0 - fStack_7c;
            }
          }
          pfVar7 = (float *)FUN_00404c90();
          fStack_60 = *pfVar7;
          fStack_58 = pfVar7[2];
          pfVar7 = (float *)FUN_00404c90();
          fStack_60 = fStack_60 - *pfVar7;
          fStack_58 = fStack_58 - pfVar7[2];
          fStack_5c = 0.0;
          pfVar7 = (float *)FUN_00404c90();
          fStack_50 = *pfVar7;
          fStack_4c = pfVar7[1];
          fStack_48 = pfVar7[2];
          fStack_44 = pfVar7[3];
          fVar9 = fStack_58 * fStack_58 + fStack_60 * fStack_60;
          if (_DAT_009da864 < SQRT(fVar9)) {
            if (fVar9 == 0.0) {
              fStack_5c = 0.0;
            }
            else {
              fStack_5c = g_flOne / SQRT(fVar9);
            }
            fStack_60 = fStack_5c * fStack_60;
            fStack_58 = fStack_5c * fStack_58;
            fStack_5c = fStack_5c * 0.0;
          }
          fVar13 = fStack_5c * DAT_00af41c8 - fStack_58 * DAT_00af41c4;
          fVar9 = fStack_60 * DAT_00af41c4 - fStack_5c * DAT_00af41c0;
          fVar12 = fStack_58 * DAT_00af41c0 - fStack_60 * DAT_00af41c8;
          FUN_00567ce0(&DAT_00af41c0,(float)*(byte *)(this + 0x1b) * _DAT_00bc5580 + fStack_7c);
          FUN_004e8a40(auStack_30,afStack_40);
          fVar11 = *(float *)(iVar6 + 0x124) * DAT_00a0f734;
          afStack_40[1] = 0.0;
          if ((ABS(fStack_5c * g_flZero + afStack_40[2] * fStack_58 + afStack_40[0] * fStack_60) <=
               DAT_00a0f734) || (fVar10 <= fVar11)) {
            if (0.0 < afStack_40[2] * fVar9 + fVar13 * afStack_40[0] + fVar12 * 0.0) {
              fVar13 = fVar13 * DAT_00aaa668;
              fVar12 = fVar12 * DAT_00aaa668;
              fVar9 = fVar9 * DAT_00aaa668;
            }
            fStack_60 = fVar13 * fVar11;
            fStack_5c = fVar12 * fVar11;
            fStack_58 = fVar9 * fVar11;
            fStack_54 = fVar11 * 0.0;
            pfVar7 = (float *)FUN_00404c90();
            fStack_50 = *pfVar7 + fStack_60;
            fStack_4c = pfVar7[1] + fStack_5c;
            fStack_48 = pfVar7[2] + fStack_58;
            fStack_44 = pfVar7[3] + fStack_54;
          }
          else {
            pfVar7 = (float *)FUN_00404c90();
            fStack_50 = *pfVar7;
            fStack_4c = pfVar7[1];
            fStack_48 = pfVar7[2];
            fStack_44 = pfVar7[3];
          }
          (**(code **)(*this + 0x4c))(&fStack_50,0);
        }
      }
      else {
        pfVar7 = (float *)FUN_00404c90();
        fStack_60 = *pfVar7;
        fStack_5c = pfVar7[1];
        fStack_58 = pfVar7[2];
        fStack_54 = pfVar7[3];
        pfVar7 = (float *)FUN_00404c90();
        fStack_60 = fStack_60 - *pfVar7;
        fStack_5c = fStack_5c - pfVar7[1];
        fStack_58 = fStack_58 - pfVar7[2];
        fStack_54 = fStack_54 - pfVar7[3];
        fVar9 = fStack_58 * fStack_58 + fStack_5c * fStack_5c + fStack_60 * fStack_60;
        if (_DAT_009da864 < SQRT(fVar9)) {
          if (fVar9 == 0.0) {
            fVar9 = 0.0;
          }
          else {
            fVar9 = g_flOne / SQRT(fVar9);
          }
          fStack_60 = fVar9 * fStack_60;
          fStack_5c = fStack_5c * fVar9;
          fStack_58 = fStack_58 * fVar9;
          fStack_54 = fStack_54 * fVar9;
        }
        fVar10 = fVar10 * DAT_00aaa668;
        fStack_60 = fVar10 * fStack_60;
        fStack_5c = fStack_5c * fVar10;
        fStack_58 = fStack_58 * fVar10;
        fStack_54 = fStack_54 * fVar10;
        (**(code **)(*this + 0x4c))(&fStack_60,1);
      }
    }
  }
  local_14 = 0xffffffff;
  FUN_0076cef0();
  ExceptionList = pvStack_1c;
  return;
}
```
