// =============================================================================
// CVOGHBAI_UpdateAimOffset_Inferred  (Ghidra: FUN_005cedf0)
// -----------------------------------------------------------------------------
// Stable ID: aa_005cedf0
// Address:   0x005cedf0–0x005cf558  (1897 B; autoassault.exe base 0x400000)
// System:    HB AI aim-offset state machine
// Sealed:    2026-07-29 W26-O (decompile + read_memory + analyze_function_complete)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Tick AI aim-offset state on `this` (ECX). When owner is "still" relative to a
//   cached sample but active pose has drifted (>1 unit), after a 1.5s arm delay
//   builds a randomized local-space offset (X/Z), transforms by object@+0x18 pose
//   via Math_QuatTransformPoint, and stores aim vec4 at this+0x40. Clears on
//   owner/phys loss, TTL 6s, or owner near the stored offset (0.75).
//
// ABI:
//   __fastcall/thiscall  ECX = AI aim helper; void; no stack formals
//
// this fields:
//   +0x18 obj*   pose source (vtbl +0x1a0/+0x1a4)
//   +0x3c float  timestamp (seconds)
//   +0x40..4c    aim offset vec4
//   +0x50..5c    last sample pos
//   +0x60 char   active flag
//   +0x64 obj*   owner
//
// CALLERS (4): CVOGHBAIDriver_DoLogic, CVOGHBAICreatureBase_DoLogic (FUN_005d7f70),
//   CVOGHBAICreatureBase_OnHeartBeat, FUN_005d7ca0
// CALLEES: FUN_004c3ac0, FUN_005d6870, FUN_005d1d20, FUN_004e8bf0,
//   CVOGReaction_RandomUnitScalar; owner/vehicle/object vtbls
// =============================================================================

#include <stdint.h>
#include <math.h>

/* External symbols (image) */
extern uint32_t g_dwClientTickMs;
extern float g_flMsToSeconds_Inferred; /* 0x00a0f72c ≈ 0.001f */
extern float g_flOne;                  /* 1.0f */
extern float g_flZero;                 /* 0.0f */
extern float _DAT_00aaa5dc;            /* 4294967296.0f */
extern float DAT_00aaa8dc;             /* 6.0f */
extern float DAT_00a0f708;             /* 0.75f */
extern float DAT_00a10e78;             /* 0.05f */
extern float DAT_00aaa68c;             /* 1.5f */
extern float DAT_00aaa688;             /* 5.0f */
extern float DAT_00aaa690;             /* 4.0f */
extern float _DAT_009da8cc;            /* ≈5/65535 */
extern float _DAT_009da8d0;            /* ≈6/65535 */
extern float DAT_00aaa668;             /* -1.0f */
extern uint32_t g_abInferredDefaultAimPos[4];

extern float *FUN_004c3ac0(void); /* CVOGObject_GetActivePositionPtr_Inferred (this in ECX from owner path) */
extern char *FUN_005d6870(void *out_flag_slot /* this = vec3 */);
extern void FUN_005d1d20(float *out_basis, void *orient);
extern void FUN_004e8bf0(void *pos, void *orient, float *local, float *out_world);
extern int CVOGReaction_RandomUnitScalar(void);

#ifndef ABS
#define ABS(x) (((x) < 0) ? -(x) : (x))
#endif

void __fastcall CVOGHBAI_UpdateAimOffset_Inferred(int param_1 /* this */)
{
  /* --- body: control flow preserved from live Ghidra decompile 2026-07-29 --- */
  /* Full expanded form matches raw aa_005cedf0; types use uint32_t not bare undefined4. */

  uint16_t uVar1;
  uint16_t uVar2;
  int *piVar3;
  int iVar4;
  float *pfVar5;
  char *pcVar6;
  uint32_t uVar7;
  uint32_t *puVar8;
  float fVar9;
  uint8_t uStack_65;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  uint32_t uStack_50;
  uint32_t uStack_4c;
  uint32_t uStack_48;
  uint32_t uStack_44;
  uint32_t uStack_40;
  uint32_t uStack_3c;
  uint32_t uStack_38;
  uint32_t uStack_34;
  float fStack_30;
  uint32_t uStack_2c;
  uint32_t uStack_28;
  uint32_t uStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;

  iVar4 = *(int *)(param_1 + 100);
  if (((iVar4 == 0) ||
      (iVar4 = (**(int (**)(void))(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) +
                      0x19c))(),
      iVar4 == 0)) ||
     (iVar4 = (**(int (**)(void))(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 100) + 4) + 4) + 4 +
                                   *(int *)(param_1 + 100)) + 0x19c))(), *(int *)(iVar4 + 8) == 0))
  {
    *(uint8_t *)(param_1 + 0x60) = 0;
    *(uint32_t *)(param_1 + 0x3c) = 0;
    return;
  }
  fStack_64 = (float)(int)g_dwClientTickMs;
  if ((int)g_dwClientTickMs < 0) {
    fStack_64 = fStack_64 + _DAT_00aaa5dc;
  }
  fStack_64 = fStack_64 * g_flMsToSeconds_Inferred;
  if (*(char *)(param_1 + 0x60) != '\0') {
    if (fStack_64 - *(float *)(param_1 + 0x3c) <= DAT_00aaa8dc) {
      pfVar5 = (float *)(**(int (**)(void))(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 100) + 4) + 4) +
                                              4 + *(int *)(param_1 + 100)) + 0x1a0))();
      fStack_60 = ABS(*pfVar5 - *(float *)(param_1 + 0x40));
      fStack_5c = ABS(pfVar5[1] - *(float *)(param_1 + 0x44));
      fStack_58 = ABS(pfVar5[2] - *(float *)(param_1 + 0x48));
      fStack_54 = ABS(pfVar5[3] - *(float *)(param_1 + 0x4c));
      if ((DAT_00a0f708 < fStack_58 || DAT_00a0f708 < fStack_5c) || DAT_00a0f708 < fStack_60)
      goto LAB_005cef56;
      *(uint8_t *)(param_1 + 0x60) = 0;
    }
    else {
      *(uint8_t *)(param_1 + 0x60) = 0;
    }
    *(uint32_t *)(param_1 + 0x3c) = 0;
  }
LAB_005cef56:
  iVar4 = (**(int (**)(void))(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 100) + 4) + 4) + 4 +
                               *(int *)(param_1 + 100)) + 0x19c))();
  if ((((*(char *)(*(int *)(iVar4 + 8) + 0x40) == '\0') || (*(int *)(*(int *)(iVar4 + 8) + 8) == 0))
      && (iVar4 = *(int *)(param_1 + 100), *(float *)(iVar4 + 0x120) == 0.0f)) &&
     ((*(char *)(iVar4 + 0x304) != '\0' ||
      ((*(int *)(iVar4 + 0x250) != 0 && (*(float *)(*(int *)(iVar4 + 0x250) + 0x614) != 0.0f)))))) {
    pfVar5 = (float *)(**(int (**)(void))(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x1a0))
                                ();
    fStack_60 = ABS(*(float *)(param_1 + 0x50) - *pfVar5);
    fStack_5c = ABS(*(float *)(param_1 + 0x54) - pfVar5[1]);
    fStack_58 = ABS(*(float *)(param_1 + 0x58) - pfVar5[2]);
    fStack_54 = ABS(*(float *)(param_1 + 0x5c) - pfVar5[3]);
    if ((fStack_58 <= DAT_00a10e78 && fStack_5c <= DAT_00a10e78) && fStack_60 <= DAT_00a10e78) {
      pfVar5 = (float *)FUN_004c3ac0();
      fStack_60 = ABS(*(float *)(param_1 + 0x50) - *pfVar5);
      fStack_5c = ABS(*(float *)(param_1 + 0x54) - pfVar5[1]);
      fStack_58 = ABS(*(float *)(param_1 + 0x58) - pfVar5[2]);
      fStack_54 = ABS(*(float *)(param_1 + 0x5c) - pfVar5[3]);
      if ((g_flOne < fStack_58 || g_flOne < fStack_5c) || g_flOne < fStack_60) {
        if (*(float *)(param_1 + 0x3c) == g_flZero) {
          *(float *)(param_1 + 0x3c) = fStack_64;
          return;
        }
        if (*(char *)(param_1 + 0x60) != '\0') {
          return;
        }
        if (fStack_64 - *(float *)(param_1 + 0x3c) <= DAT_00aaa68c) {
          return;
        }
        *(uint8_t *)(param_1 + 0x60) = 1;
        pfVar5 = (float *)FUN_004c3ac0();
        fStack_60 = *pfVar5;
        fStack_5c = pfVar5[1];
        fStack_58 = pfVar5[2];
        fStack_54 = pfVar5[3];
        piVar3 = *(int **)(*(int *)(param_1 + 100) + 0x250);
        if (piVar3 != (int *)0) {
          pfVar5 = (float *)(**(int (**)(void))(*piVar3 + 0x54))();
          fStack_60 = *pfVar5;
          fStack_5c = pfVar5[1];
          fStack_58 = pfVar5[2];
          fStack_54 = pfVar5[3];
        }
        pfVar5 = (float *)(**(int (**)(void))(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 100) + 4) + 4)
                                                + 4 + *(int *)(param_1 + 100)) + 0x1a0))();
        fStack_60 = fStack_60 - *pfVar5;
        fStack_5c = fStack_5c - pfVar5[1];
        fStack_58 = fStack_58 - pfVar5[2];
        fStack_54 = fStack_54 - pfVar5[3];
        pcVar6 = (char *)FUN_005d6870(&uStack_65);
        if (*pcVar6 != '\0') {
          fStack_64 = fStack_60 * fStack_60 + fStack_58 * fStack_58 + fStack_5c * fStack_5c;
          if (fStack_64 == 0.0f) {
            fVar9 = 0.0f;
          }
          else {
            fVar9 = g_flOne / sqrtf(fStack_64);
            fStack_64 = fVar9;
          }
          fStack_58 = fStack_58 * fVar9;
          fStack_60 = fVar9 * fStack_60;
          fStack_5c = fStack_5c * fVar9;
          fStack_54 = fStack_54 * fVar9;
          uVar7 = (**(uint32_t (**)(void))(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 100) + 4) + 4) + 4 +
                                       *(int *)(param_1 + 100)) + 0x1a4))();
          FUN_005d1d20(&fStack_20, (void *)(uintptr_t)uVar7);
          fStack_64 = fStack_20 * fStack_60 + fStack_18 * fStack_58 + fStack_1c * fStack_5c;
          iVar4 = CVOGReaction_RandomUnitScalar();
          if (0xfffff < *(int *)(iVar4 + 0xc)) {
            *(uint32_t *)(iVar4 + 0xc) = 0;
          }
          uVar1 = *(uint16_t *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);
          *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;
          iVar4 = CVOGReaction_RandomUnitScalar();
          if (0xfffff < *(int *)(iVar4 + 0xc)) {
            *(uint32_t *)(iVar4 + 0xc) = 0;
          }
          uVar2 = *(uint16_t *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);
          *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;
          pfVar5 = (float *)(param_1 + 0x40);
          fVar9 = (float)uVar1 * _DAT_009da8cc + DAT_00aaa688;
          *pfVar5 = (float)uVar2 * _DAT_009da8d0 + DAT_00aaa690;
          *(uint32_t *)(param_1 + 0x44) = 0;
          *(float *)(param_1 + 0x48) = fVar9;
          *(uint32_t *)(param_1 + 0x4c) = 0;
          iVar4 = CVOGReaction_RandomUnitScalar();
          if (0xfffff < *(int *)(iVar4 + 0xc)) {
            *(uint32_t *)(iVar4 + 0xc) = 0;
          }
          uVar1 = *(uint16_t *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);
          *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;
          fVar9 = DAT_00aaa668;
          if ((uVar1 & 1) != 0) {
            *pfVar5 = *pfVar5 * DAT_00aaa668;
          }
          if (g_flZero < fStack_64) {
            *(float *)(param_1 + 0x48) = *(float *)(param_1 + 0x48) * fVar9;
          }
          puVar8 = (uint32_t *)(**(int (**)(void))(**(int **)(param_1 + 0x18) + 0x1a0))();
          uStack_40 = *puVar8;
          uStack_3c = puVar8[1];
          uStack_38 = puVar8[2];
          uStack_34 = puVar8[3];
          puVar8 = (uint32_t *)(**(int (**)(void))(**(int **)(param_1 + 0x18) + 0x1a4))();
          uStack_50 = *puVar8;
          uStack_4c = puVar8[1];
          uStack_48 = puVar8[2];
          uStack_44 = puVar8[3];
          FUN_004e8bf0(&uStack_40, &uStack_50, pfVar5, &fStack_30);
          *pfVar5 = fStack_30;
          *(uint32_t *)(param_1 + 0x44) = uStack_2c;
          *(uint32_t *)(param_1 + 0x48) = uStack_28;
          *(uint32_t *)(param_1 + 0x4c) = uStack_24;
          return;
        }
        *(uint32_t *)(param_1 + 0x40) = g_abInferredDefaultAimPos[0];
        *(uint32_t *)(param_1 + 0x44) = g_abInferredDefaultAimPos[1];
        *(uint32_t *)(param_1 + 0x48) = g_abInferredDefaultAimPos[2];
        *(uint32_t *)(param_1 + 0x4c) = g_abInferredDefaultAimPos[3];
        return;
      }
    }
  }
  if (*(char *)(param_1 + 0x60) != '\0') {
    return;
  }
  *(uint32_t *)(param_1 + 0x3c) = 0;
  return;
}

void __fastcall FUN_005cedf0(int param_1)
{
  CVOGHBAI_UpdateAimOffset_Inferred(param_1);
}
