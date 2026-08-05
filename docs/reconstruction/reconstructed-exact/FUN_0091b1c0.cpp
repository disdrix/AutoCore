// =============================================================================
// FUN_0091b1c0 / Client_Camera_Modes257_ChaseUpdate_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0091b1c0
// Address:   0x0091b1c0  (autoassault.exe, image base 0x400000)
// Body:      0x0091b1c0–0x0091b8c6 (1798 B); RET 0x14
// Dual A/B:  2026-07-29 accept-with-gaps (W25-B)
// System:    client camera / modes 2·5·7 chase update
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// ABI: stdcall 5 stack floats + EDI = CameraController* (caller-set).
// Reject alias Named_VOG_DEBUG_STOP_0091b1c0 (string is error-path only).
//
// Named twin: Client_Camera_Modes257_ChaseUpdate_Inferred.cpp
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

#include <cstdint>

// External symbols (Ghidra names preserved where not dual-sealed)
extern int DAT_00d1b6d8;
extern int DAT_00d17944;
extern int DAT_00d1b644;
extern float _DAT_00a240ec;
extern float DAT_00aaa640;
extern float g_flLevelUpUiBase_Inferred; // 2.0 @ 0x00a10e74 (misnamed)
extern float g_flOne;
extern float DAT_00d1f0ac;
extern float _DAT_00afe268;              // 12.0
extern float _DAT_009da8a4;              // 3.5
extern float DAT_00aaa688;               // 5.0
extern float DAT_00a0f70c;               // 0.2
extern float DAT_00aaa668;               // -1.0

extern void FUN_00917cd0(void *, void *, void *, void *);
extern void FUN_007a4480(int, const char *);
extern float FUN_00916090(float, float, float, float, float, float);
extern void FUN_0076f5f0(float *, float *);
extern void FUN_00915da0(float, float, float);
extern void FUN_0090e1b0(float, float, float);
extern void D3DXVec3Normalize(void *, void *);
extern void FUN_0040cf90(float *);
extern void FUN_0099b8b0(float *, float *);
extern int sprintf(char *, const char *, ...);
extern void OutputDebugStringA(const char *);
extern float SQRT(float);
extern float ABS(float);
extern long double fsin(long double);
extern long double fcos(long double);

// stdcall RET 0x14; EDI = cam* (documented as first explicit param for readability)
void FUN_0091b1c0(float param_1, float param_2, float param_3, float param_4, float param_5)
{
  // NOTE: production uses EDI = cam* from caller; decompiler residual unaff_EDI.
  // Clean twin keeps decompiler CF; see named twin comments for sealed ABI.

  int *piVar1;
  int iVar2;
  uint8_t bVar3;
  int iVar4;
  int extraout_EDX;
  int unaff_EDI; // cam*
  long double fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float local_8c;
  float local_88;
  float local_84;
  float fStack_80;
  float local_7c;
  float local_78;
  float fStack_74;
  float local_70;
  uint8_t local_60[16];
  char acStack_50[76];

  FUN_00917cd0(&local_84, &local_78, &param_1, local_60);
  if ((((*(char *)(DAT_00d1b6d8 + 0x6b9) == '\0') &&
       (iVar4 = *(int *)(DAT_00d1b6d8 + 0x250), iVar4 != 0)) && (*(int *)(iVar4 + 600) != 0)) &&
     ('\0' < *(char *)(*(int *)(iVar4 + 600) + 0xb0))) {
    bVar3 = 0;
    do {
      if (*(char *)((char)bVar3 + 0xf4 + *(int *)(iVar4 + 600)) != '\0') break;
      bVar3 = bVar3 + 1;
    } while ((int)(uint32_t)bVar3 < (int)*(char *)(*(int *)(iVar4 + 600) + 0xb0));
  }
  *(float *)(unaff_EDI + 0xd04) = param_1;
  *(float *)(unaff_EDI + 0xd08) = param_2;
  *(uint8_t *)(unaff_EDI + 0xd00) = 0;
  *(float *)(unaff_EDI + 0xd0c) = param_3;
  if (((*(int *)(DAT_00d1b6d8 + 0x250) == 0) || (*(char *)(DAT_00d1b6d8 + 0x6b9) != '\0')) ||
     (*(char *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xa8 + DAT_00d1b6d8) + 0xf5) !=
      '\0')) {
    if (*(int **)(DAT_00d1b6d8 + 0x48) == (int *)0x0) {
      FUN_007a4480(0, "VOG_DEBUG_STOP");
    }
    else {
      (*(int (**)(void))(**(int **)(DAT_00d1b6d8 + 0x48) + 0xc))();
      iVar4 = (*(int (**)(void))(**(int **)(DAT_00d1b6d8 + 0x48) + 0xc))();
      local_7c = (*(float *)(iVar4 + 0x88) * *(float *)(iVar4 + 0x80) -
                 *(float *)(iVar4 + 0x84) * *(float *)(iVar4 + 0x8c)) * g_flLevelUpUiBase_Inferred;
      fStack_80 = (*(float *)(iVar4 + 0x84) * *(float *)(iVar4 + 0x80) +
                  *(float *)(iVar4 + 0x88) * *(float *)(iVar4 + 0x8c)) * g_flLevelUpUiBase_Inferred;
      local_84 = g_flOne - (*(float *)(iVar4 + 0x84) * *(float *)(iVar4 + 0x84) +
                           *(float *)(iVar4 + 0x88) * *(float *)(iVar4 + 0x88)) *
                           g_flLevelUpUiBase_Inferred;
      fStack_74 = fStack_80;
    }
  }
  else {
    (*(int (**)(void))(**(int **)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x48) + 0xc))();
    iVar4 = (*(int (**)(void))(**(int **)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x48) + 0xc))();
    local_7c = (*(float *)(iVar4 + 0x80) * *(float *)(iVar4 + 0x88) -
               *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x84)) * g_flLevelUpUiBase_Inferred;
    fStack_80 = (*(float *)(iVar4 + 0x80) * *(float *)(iVar4 + 0x84) +
                *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x88)) * g_flLevelUpUiBase_Inferred;
    local_84 = g_flOne - (*(float *)(iVar4 + 0x84) * *(float *)(iVar4 + 0x84) +
                         *(float *)(iVar4 + 0x88) * *(float *)(iVar4 + 0x88)) *
                         g_flLevelUpUiBase_Inferred;
    fStack_74 = fStack_80;
  }
  local_78 = *(float *)(DAT_00d17944 + 0x21c);
  local_70 = *(float *)(DAT_00d17944 + 0x224);
  fVar9 = SQRT(local_84 * local_84 + local_7c * local_7c);
  fVar11 = 0.0f;
  fVar8 = 0.0f;
  if ((_DAT_00a240ec <= fVar9) || (fVar6 = local_7c, fVar10 = local_84, fVar9 <= DAT_00aaa640)) {
    fVar9 = g_flOne / fVar9;
    fVar11 = fVar9 * 0.0f;
    fVar6 = local_7c * fVar9;
    fVar10 = local_84 * fVar9;
  }
  local_88 = SQRT(local_70 * local_70 + local_78 * local_78);
  if ((_DAT_00a240ec <= local_88) || (fVar9 = local_70, fVar7 = local_78, local_88 <= DAT_00aaa640))
  {
    fVar7 = g_flOne / local_88;
    fVar8 = fVar7 * 0.0f;
    fVar9 = fVar7 * local_70;
    fVar7 = fVar7 * local_78;
  }
  fVar5 = (long double)fsin((long double)*(float *)(unaff_EDI + 0xcc8));
  local_8c = fVar6 * fVar9 + fVar8 * fVar11 + fVar10 * fVar7;
  param_5 = (float)(fVar5 * (long double)param_5);
  if ((*(char *)(unaff_EDI + 0x493) != '\0') && (*(char *)(unaff_EDI + 0xa83) != '\0')) {
    if (DAT_00d1f0ac < local_8c) {
      if (local_8c < DAT_00d1f0ac) goto LAB_0091b5da;
      fVar9 = ABS(local_8c) * _DAT_00afe268 * _DAT_009da8a4 + *(float *)(unaff_EDI + 0x538);
    }
    else {
      fVar9 = *(float *)(unaff_EDI + 0x538) - ABS(local_8c) * _DAT_00afe268 * _DAT_009da8a4;
    }
    *(float *)(unaff_EDI + 0x538) = fVar9;
  }
LAB_0091b5da:
  sprintf(acStack_50, "%.02f\n", (double)local_8c);
  OutputDebugStringA(acStack_50);
  iVar4 = DAT_00d17944;
  fVar5 = (long double)fcos((long double)*(float *)(unaff_EDI + 0xcc8));
  fStack_74 = *(float *)(unaff_EDI + 0xd08);
  local_78 = *(float *)(unaff_EDI + 0xd04);
  local_70 = *(float *)(unaff_EDI + 0xd0c);
  fVar9 = *(float *)(unaff_EDI + 0x5b4);
  param_4 = (float)(fVar5 * (long double)param_4);
  *(float *)(DAT_00d17944 + 0x228) = *(float *)(unaff_EDI + 0x5ac) * param_4 + local_78;
  *(float *)(iVar4 + 0x230) = fVar9 * param_4 + local_70;
  *(float *)(iVar4 + 0x22c) = fStack_74 + param_5;
  fStack_80 = param_2 + DAT_00aaa688;
  fVar5 = (long double)FUN_00916090(param_1, fStack_80, param_3, param_1, param_2, param_3);
  local_88 = (float)fVar5;
  if (DAT_00a0f70c < local_88) {
    fVar9 = 0.0f;
    fVar8 = fStack_80 - param_2;
    fVar11 = 0.0f;
    local_78 = 0.0f;
    local_70 = 0.0f;
    fStack_74 = fVar8;
    FUN_0076f5f0(&local_78, &local_78);
    local_88 = SQRT(fVar9 * fVar9 + fVar8 * fVar8 + fVar11 * fVar11) - local_88;
    *(float *)(extraout_EDX + 0x228) = local_88 * local_78;
    *(float *)(extraout_EDX + 0x22c) = local_88 * fStack_74;
    *(float *)(extraout_EDX + 0x230) = local_88 * local_70;
    local_84 = fVar9;
    fStack_80 = fVar8;
    local_7c = fVar11;
  }
  FUN_00915da0(param_1, param_2, param_3);
  FUN_0090e1b0(0.0f, DAT_00aaa668, 0.0f);
  D3DXVec3Normalize((void *)(DAT_00d17944 + 0x21c), (void *)(DAT_00d17944 + 0x21c));
  iVar2 = DAT_00d17944;
  fStack_80 = *(float *)(DAT_00d17944 + 0x228);
  local_7c = *(float *)(DAT_00d17944 + 0x22c);
  local_78 = *(float *)(DAT_00d17944 + 0x230);
  FUN_0040cf90(&fStack_80);
  fStack_80 = *(float *)(iVar2 + 0x210);
  iVar4 = *(int *)(*(int *)(*(int *)(DAT_00d1b644 + 0xe894) + 0xc0) + 8);
  local_7c = *(float *)(iVar2 + 0x214);
  local_78 = *(float *)(iVar2 + 0x218);
  local_8c = *(float *)(iVar2 + 0x21c);
  local_88 = *(float *)(iVar2 + 0x220);
  local_84 = *(float *)(iVar2 + 0x224);
  *(uint32_t *)(iVar4 + 0xbc) = 0xffffffffu;
  piVar1 = (int *)(iVar4 + 0xb4);
  *piVar1 = *piVar1 + 1;
  FUN_0099b8b0(&local_8c, &fStack_80);
  return;
}
