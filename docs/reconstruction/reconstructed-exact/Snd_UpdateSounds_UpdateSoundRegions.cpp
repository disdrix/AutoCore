// =============================================================================
// Snd_UpdateSounds_UpdateSoundRegions
// -----------------------------------------------------------------------------
// Stable ID: aa_00727440
// Address:   0x00727440  (autoassault.exe, image base 0x400000)
// System:    client audio / CSoundManager
// Generated: 2026-07-29 dual A/B seal (W25-Q); supersedes 2026-07-23 scaffold
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Plate string: "UpdateSounds::updateSoundRegions()" @ 0x00aa91ac
 * - stdcall ret 0xC: (CSoundManager* mgr, uint flag, float dt)
 * - Gate: mgr+0x258 enable AND dt accum mgr+0x6c > 0.0005 (_DAT_00aaab78)
 * - CS at mgr+0x3f8; nests FUN_007252d0 hard-kill/regions; walks 0x30 slots @ +0x31c
 * - Sole caller FUN_00938380. Control flow preserved from Ghidra decompile.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Snd_UpdateSounds_UpdateSoundRegions(int param_1, uint param_2, float param_3)
{
  int *piVar1;
  int iVar2;
  double dVar3;
  DWORD DVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  float10 fVar9;
  float10 extraout_ST0;
  float fVar10;
  undefined8 uVar11;
  int iStack_20;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  dVar3 = _DAT_00aaab78;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b2cff;
  local_c = ExceptionList;
  if ((*(char *)(param_1 + 600) != '\0') &&
     (fVar10 = param_3 + *(float *)(param_1 + 0x6c), ExceptionList = &local_c,
     *(float *)(param_1 + 0x6c) = fVar10, dVar3 < (double)fVar10)) {
    FUN_007272f0(param_1);
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x3f8));
    local_4 = 0;
    DVar4 = GetTickCount();
    *(DWORD *)(param_1 + 0x3dc) = DVar4;
    FUN_00724d70(param_3);
    if ((*(char *)(param_1 + 0x259) != '\0') &&
       (g_flZero !=
        SQRT(*(float *)(param_1 + 0x220) * *(float *)(param_1 + 0x220) +
             *(float *)(param_1 + 0x224) * *(float *)(param_1 + 0x224) +
             *(float *)(param_1 + 0x228) * *(float *)(param_1 + 0x228)))) {
      (**(code **)(**(int **)(param_1 + 4) + 0x38))
                (*(int **)(param_1 + 4),*(undefined4 *)(param_1 + 0x220),
                 *(undefined4 *)(param_1 + 0x224),*(undefined4 *)(param_1 + 0x228),1);
      fVar10 = *(float *)(param_1 + 0x230) * *(float *)(param_1 + 0x230) +
               *(float *)(param_1 + 0x234) * *(float *)(param_1 + 0x234) +
               *(float *)(param_1 + 0x238) * *(float *)(param_1 + 0x238);
      if (fVar10 == 0.0) {
        fVar10 = 0.0;
      }
      else {
        fVar10 = g_flOne / SQRT(fVar10);
      }
      *(float *)(param_1 + 0x230) = fVar10 * *(float *)(param_1 + 0x230);
      *(float *)(param_1 + 0x234) = fVar10 * *(float *)(param_1 + 0x234);
      *(float *)(param_1 + 0x238) = fVar10 * *(float *)(param_1 + 0x238);
      *(float *)(param_1 + 0x23c) = fVar10 * *(float *)(param_1 + 0x23c);
      (**(code **)(**(int **)(param_1 + 4) + 0x34))
                (*(int **)(param_1 + 4),*(undefined4 *)(param_1 + 0x230),0,
                 *(undefined4 *)(param_1 + 0x238),0,0x3f800000,0,1);
    }
    FUN_00786a00("UpdateSounds::updateSoundRegions()");
    uVar8 = param_2;
    local_4._0_1_ = 1;
    FUN_007252d0(param_2,*(undefined4 *)(param_1 + 0x6c));
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_00786990();
    iVar6 = 0;
    if (0 < *(int *)(param_1 + 0x210)) {
      piVar7 = (int *)(param_1 + 0x31c);
      do {
        if (*piVar7 != 0) {
          FUN_0071f760(1);
        }
        iVar6 = iVar6 + 1;
        piVar7 = piVar7 + 1;
        uVar8 = param_2;
      } while (iVar6 < *(int *)(param_1 + 0x210));
    }
    piVar7 = (int *)(param_1 + 0x31c);
    iStack_20 = 0x30;
    do {
      iVar6 = *piVar7;
      if (((((iVar6 != 0) && (-1 < *(int *)(iVar6 + 0x28))) &&
           (*(int **)(iVar6 + 0x10) != (int *)0x0)) &&
          ((*(int *)(iVar6 + 0x1c) != 0 &&
           (piVar1 = (int *)**(int **)(iVar6 + 0x10), piVar1 != (int *)0x0)))) &&
         ((*(char *)(iVar6 + 0x1c5) != '\0' || (*(char *)(iVar6 + 0x3a) != '\0')))) {
        *(float *)(iVar6 + 0x1c0) = *(float *)(iVar6 + 0x1c0) + param_3;
        if (uVar8 == 0) {
          iVar6 = *piVar7;
          if (*(char *)(iVar6 + 0x39) != '\0') {
            fVar10 = *(float *)(param_1 + 0x2dc) * *(float *)(param_1 + 0x2d4);
            if (fVar10 <= g_flOne) {
              *(float *)(iVar6 + 0x1a4) = fVar10;
            }
            else {
              *(float *)(iVar6 + 0x1a4) = g_flOne;
            }
          }
        }
        else if ((*(char *)(param_1 + 0x259) == '\0') ||
                (iVar6 = *piVar7, *(int *)(iVar6 + 0x1c8) == 0)) {
          if (*(int *)(*piVar7 + 0x2c) == 0x28) {
            fVar10 = *(float *)(param_1 + 0x2d0);
          }
          else {
            fVar10 = *(float *)(param_1 + 0x2d4);
          }
          FUN_004bb5b0(*piVar7,*(float *)(param_1 + 0x2dc) * fVar10,param_1 + 0x220,param_1 + 0x230,
                       param_1 + 0x2c0);
        }
        else {
          if (*(int *)(iVar6 + 0x2c) == 0x28) {
            fVar10 = *(float *)(param_1 + 0x2d0);
          }
          else {
            fVar10 = *(float *)(param_1 + 0x2cc);
          }
          FUN_004bb3a0(iVar6,*(float *)(param_1 + 0x2dc) * fVar10,param_1 + 0x220);
        }
        if (*(char *)(*piVar7 + 0x39) != '\0') {
          (**(code **)(*piVar1 + 0x3c))(piVar1,(int)*(float *)(*piVar7 + 0x1a4));
        }
        iVar6 = *piVar7;
        if (*(char *)(iVar6 + 0x38) == '\0') {
          if ((*(char *)(iVar6 + 0x1c5) != '\0') && (*(int *)(iVar6 + 0x1c8) == 0)) {
            iVar6 = *piVar7;
            if (*(float *)(iVar6 + 0x1b0) <= g_flOne) {
              *(float *)(iVar6 + 0x1a4) = *(float *)(iVar6 + 0x1b0);
            }
            else {
              *(float *)(iVar6 + 0x1a4) = g_flOne;
            }
          }
        }
        else if ((*(int *)(iVar6 + 0x2c) == 0x32) || (*(int *)(iVar6 + 0x2c) == 0x28)) {
          FUN_0071f810();
          *(undefined1 *)(*piVar7 + 0x38) = 0;
          uVar8 = param_2;
        }
        else if (*(float *)(iVar6 + 0x1a4) < *(float *)(iVar6 + 0x1b0) ||
                 *(float *)(iVar6 + 0x1a4) == *(float *)(iVar6 + 0x1b0)) {
          FUN_0071f810();
          *(undefined1 *)(*piVar7 + 0x38) = 0;
          fVar9 = (float10)FUN_007227e0(0);
          FUN_004801d0((float)fVar9);
          *(undefined4 *)(*piVar7 + 0x188) = 0;
          uVar8 = param_2;
        }
        else if (*(float *)(param_1 + 0x6c) < *(float *)(iVar6 + 0x1b8)) {
          iVar6 = *piVar7;
          FUN_004801d0(*(float *)(iVar6 + 0x1a4) -
                       ABS((*(float *)(param_1 + 0x6c) / *(float *)(iVar6 + 0x1b8)) *
                           *(float *)(iVar6 + 0x1b0)));
        }
        else {
          fVar9 = (float10)FUN_007227e0(0);
          FUN_004801d0((float)fVar9);
        }
        iVar6 = *piVar7;
        if ((*(char *)(iVar6 + 0x3a) != '\0') && (*(char *)(iVar6 + 0x1c4) == '\0')) {
          *(undefined1 *)(iVar6 + 0x3a) = 0;
          iVar6 = *(int *)(*piVar7 + 0x14);
          uVar5 = 0;
          if (((iVar6 != 0) && (*(uint *)(*piVar7 + 0x238) < *(uint *)(iVar6 + 0x1c))) ||
             (*(char *)(*piVar7 + 0x36) != '\0')) {
            uVar5 = 1;
          }
          iVar6 = *piVar7;
          uVar11 = CONCAT44(uVar5,iVar6);
          if (0.0 < *(float *)(iVar6 + 0x1b8)) {
            uVar11 = FUN_007227e0(0);
            fVar10 = g_flOne;
            if ((float)extraout_ST0 <= g_flOne) {
              fVar10 = (float)extraout_ST0;
            }
LAB_0072798f:
            uVar5 = (undefined4)((ulonglong)uVar11 >> 0x20);
            *(float *)((int)uVar11 + 0x1a4) = fVar10;
          }
          else {
            fVar10 = *(float *)(iVar6 + 0x1b0);
            if (*(float *)(iVar6 + 0x1b0) <= g_flOne) goto LAB_0072798f;
            *(float *)(iVar6 + 0x1a4) = g_flOne;
          }
          iVar6 = FUN_0071fc20(0,uVar5,(int)*(float *)(*piVar7 + 0x1a4),0xffffffff,
                               (int)*(float *)(*piVar7 + 0x188));
          if (iVar6 == 0) {
            FUN_0071f760(1);
          }
        }
        iVar6 = *piVar7;
        if (*(char *)(iVar6 + 0x36) != '\0') {
          if (0.0 < *(float *)(iVar6 + 0x1a4)) {
            *(undefined4 *)(iVar6 + 0x1a4) = 0;
          }
          if (*(float *)(*piVar7 + 0x1a4) != *(float *)(*piVar7 + 0x1b0)) {
            (**(code **)(*piVar1 + 0x3c))(piVar1,(int)*(float *)(*piVar7 + 0x1a4));
          }
        }
      }
      piVar7 = piVar7 + 1;
      iStack_20 = iStack_20 + -1;
    } while (iStack_20 != 0);
    FUN_00723290(param_1);
    (**(code **)(**(int **)(param_1 + 4) + 0x44))(*(int **)(param_1 + 4));
    if (*(int *)(param_1 + 0x30c) == 0) {
      iVar6 = 0;
      param_2 = param_2 & 0xffffff00;
      param_3 = 0.0;
      if (0 < *(int *)(param_1 + 0x210)) {
        do {
          if (*(int *)(param_1 + 0x210) <= (int)(uint)*(byte *)(param_1 + 8)) {
            *(undefined1 *)(param_1 + 8) = 0;
          }
          uVar8 = (uint)*(byte *)(param_1 + 8);
          *(byte *)(param_1 + 8) = *(byte *)(param_1 + 8) + 1;
          iVar2 = *(int *)(param_1 + 0x31c + uVar8 * 4);
          if ((iVar2 != 0) &&
             ((*(char *)(iVar2 + 0x1c5) != '\0' ||
              ((*(char *)(iVar2 + 0x3a) != '\0' && (*(char *)(iVar2 + 0x1c4) != '\0')))))) {
            *(undefined4 *)
             (*(int *)(param_1 + 0x70 + *(int *)(*(int *)(param_1 + 0x31c + uVar8 * 4) + 0x30) * 4)
             + 0x110) = *(undefined4 *)(param_1 + 0x3dc);
            FUN_0071e820(&param_2);
            if ((char)param_2 != '\0') {
              param_3 = (float)((int)param_3 + 1);
            }
            if (1 < (int)param_3) break;
            *(undefined1 *)(*(int *)(param_1 + 0x31c + uVar8 * 4) + 0x1c4) = 0;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < *(int *)(param_1 + 0x210));
      }
      piVar7 = (int *)(param_1 + 0x2a8);
      iVar6 = 5;
      do {
        if ((*piVar7 != 0) && (*(char *)(*piVar7 + 0x1c5) != '\0')) {
          FUN_0071e820(0);
          *(undefined1 *)(*piVar7 + 0x1c4) = 0;
        }
        piVar7 = piVar7 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    *(undefined4 *)(param_1 + 0x6c) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x3f8));
  }
  ExceptionList = local_c;
  return;
}

