// =============================================================================
// ObjectMotion_ApplyStageParams_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004b2b90
// Address:   0x004b2b90 – 0x004b3253  (autoassault.exe, image base 0x400000)
// Body size: 1732 B / 0x6C4
// System:    client object motion / reaction stage params
// Generated: 2026-07-29 W27-E dual seal (decompile + read_memory)
// Exactness: Named CF-preserving twin. dirty!=0 reinit; dirty==0 lerp + rate*dt.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Apply stage-template parameters to a motion slot.
//   - dirty != 0: re-sample end-state + flag-gated fields from stage; RNG; snapshot baseline
//   - dirty == 0: progress = 1 - rem/total; lerp baseline→end; always slot[0xb] += slot[9]*dt
// ABI: thiscall; stack (char dirty, float dt); ret 8; void
// Callers: ObjectMotion_SlotTick_Inferred (0x004b4620); FUN_005bc120
//
// =============================================================================

#include <cstdint>
#include <cmath>

extern float DAT_00aaa638; // ≈ 1/65535
extern float g_flOne;

void FUN_004b2910(float t, void *a, void *b, void *c);
int CVOGReaction_RandomUnitScalar(void);
#ifndef ROUND
#define ROUND(x) ((int)floor((double)(x) + 0.5))
#endif

void __thiscall ObjectMotion_ApplyStageParams_Inferred(int *param_1,char param_2,float param_3)



{

  ushort uVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  int *piVar5;

  float fVar6;

  float fVar7;

  char local_4;

  

  if (param_2 != '\0') {

    iVar2 = param_1[1];

    piVar4 = (int *)(iVar2 + 0x36c);

    piVar5 = param_1 + 0x3e;

    for (iVar3 = 0x1d; iVar3 != 0; iVar3 = iVar3 + -1) {

      *piVar5 = *piVar4;

      piVar4 = piVar4 + 1;

      piVar5 = piVar5 + 1;

    }

    if ((*(byte *)(iVar2 + 0x3e2) & 0x20) != 0) {

      param_1[0xc] = *(int *)(iVar2 + 0x318);

    }

    if ((*(byte *)(iVar2 + 0x3e0) & 0x40) != 0) {

      param_1[0xb] = *(int *)(iVar2 + 0x314);

    }

    if ((*(byte *)(iVar2 + 0x3e0) & 1) != 0) {

      param_1[0xf] = *(int *)(iVar2 + 0x324);

      param_1[0x10] = *(int *)(iVar2 + 0x328);

      param_1[0x11] = *(int *)(iVar2 + 0x32c);

    }

    if ((*(byte *)(iVar2 + 0x3e0) & 2) != 0) {

      param_1[0x13] = *(int *)(iVar2 + 0x334);

      param_1[0x14] = *(int *)(iVar2 + 0x338);

      param_1[0x15] = *(int *)(iVar2 + 0x33c);

    }

    if ((*(byte *)(iVar2 + 0x3e0) & 4) != 0) {

      *(uint8_t *)((int)param_1 + 0x36) = *(uint8_t *)(iVar2 + 0x31e);

      *(uint8_t *)((int)param_1 + 0x35) = *(uint8_t *)(iVar2 + 0x31d);

      *(uint8_t *)(param_1 + 0xd) = *(uint8_t *)(iVar2 + 0x31c);

    }

    if ((*(byte *)(iVar2 + 0x3e0) & 8) != 0) {

      *(uint8_t *)((int)param_1 + 0x37) = *(uint8_t *)(iVar2 + 799);

    }

    if ((*(byte *)(iVar2 + 0x3e0) & 0x10) != 0) {

      param_1[4] = *(int *)(iVar2 + 0x2f8);

    }

    if ((*(byte *)(iVar2 + 0x3e0) & 0x20) != 0) {

      fVar6 = *(float *)(iVar2 + 0x300);

      param_1[6] = (int)fVar6;

      if (*(char *)(iVar2 + 0x308) != '\0') {

        param_1[6] = (int)(*(float *)(iVar2 + 0x2f8) * fVar6);

      }

      *(uint8_t *)((int)param_1 + 0x242) = 1;

    }

    if ((*(byte *)(iVar2 + 0x3e0) & 0x80) != 0) {

      param_1[9] = *(int *)(iVar2 + 0x30c);

      param_1[10] = *(int *)(iVar2 + 0x310);

    }

    param_1[5] = *(int *)(iVar2 + 0x2fc);

    param_1[7] = *(int *)(iVar2 + 0x304);

    if (0 < *(int *)(iVar2 + 0x344)) {

      iVar2 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar2 + 0xc)) {

        *(uint32_t *)(iVar2 + 0xc) = 0;

      }

      uVar1 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

      *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

      iVar2 = param_1[1];

      param_1[0x20] =

           *(int *)(iVar2 + 0x348 +

                   (int)((longlong)(ulonglong)uVar1 % (longlong)*(int *)(iVar2 + 0x344)) * 4);

    }

    param_1[0xe] = *(int *)(iVar2 + 800);

    if ((*(byte *)(iVar2 + 0x3e3) & 1) != 0) {

      iVar2 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar2 + 0xc)) {

        *(uint32_t *)(iVar2 + 0xc) = 0;

      }

      uVar1 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

      *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

      param_1[0xb] = (int)((float)uVar1 * (float)param_1[0xb] * DAT_00aaa638);

    }

    if ((*(byte *)(param_1[1] + 0x3e2) & 0x80) != 0) {

      iVar2 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar2 + 0xc)) {

        *(uint32_t *)(iVar2 + 0xc) = 0;

      }

      uVar1 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

      *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

      param_1[9] = (int)((float)uVar1 * (float)param_1[10] * DAT_00aaa638 + (float)param_1[9]);

    }

    if ((*(byte *)(param_1[1] + 0x3e2) & 2) != 0) {

      iVar2 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar2 + 0xc)) {

        *(uint32_t *)(iVar2 + 0xc) = 0;

      }

      uVar1 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

      *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

      FUN_004b2910((float)uVar1 * DAT_00aaa638,param_1 + 0xd,param_1[1] + 0x31c,param_1[1] + 800);

    }

    if ((*(byte *)(param_1[1] + 0x3e2) & 4) != 0) {

      iVar2 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar2 + 0xc)) {

        *(uint32_t *)(iVar2 + 0xc) = 0;

      }

      uVar1 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

      *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

      FUN_004b2910((float)uVar1 * DAT_00aaa638,param_1 + 0x47,param_1[1] + 0x390,param_1[1] + 0x394)

      ;

    }

    if ((*(byte *)(param_1[1] + 0x3e2) & 8) != 0) {

      iVar2 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar2 + 0xc)) {

        *(uint32_t *)(iVar2 + 0xc) = 0;

      }

      uVar1 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

      *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

      iVar2 = param_1[1];

      param_3._0_1_ =

           (char)(int)ROUND((float)uVar1 * DAT_00aaa638 *

                            (float)(int)((uint)*(byte *)(iVar2 + 0x323) -

                                        (uint)*(byte *)(iVar2 + 799)));

      *(char *)((int)param_1 + 0x37) = *(char *)(iVar2 + 799) + param_3._0_1_;

    }

    if ((*(byte *)(param_1[1] + 0x3e2) & 0x10) != 0) {

      iVar2 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar2 + 0xc)) {

        *(uint32_t *)(iVar2 + 0xc) = 0;

      }

      uVar1 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

      *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

      iVar2 = param_1[1];

      param_3._0_1_ =

           (char)(int)ROUND((float)uVar1 * DAT_00aaa638 *

                            (float)(int)((uint)*(byte *)(iVar2 + 0x397) -

                                        (uint)*(byte *)(iVar2 + 0x393)));

      *(char *)((int)param_1 + 0x11f) = *(char *)(iVar2 + 0x393) + param_3._0_1_;

    }

    iVar2 = param_1[1];

    if ((*(byte *)(iVar2 + 0x3e1) & 2) != 0) {

      iVar2 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar2 + 0xc)) {

        *(uint32_t *)(iVar2 + 0xc) = 0;

      }

      uVar1 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

      *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

      iVar2 = param_1[1];

      fVar6 = (float)uVar1 * *(float *)(iVar2 + 0x2fc) * DAT_00aaa638 + (float)param_1[4];

      param_1[4] = (int)fVar6;

      if (*(char *)(iVar2 + 0x308) != '\0') {

        param_1[6] = (int)(*(float *)(iVar2 + 0x300) * fVar6);

      }

    }

    if ((*(byte *)(iVar2 + 0x3e1) & 8) != 0) {

      iVar2 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar2 + 0xc)) {

        *(uint32_t *)(iVar2 + 0xc) = 0;

      }

      uVar1 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

      *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

      iVar2 = param_1[1];

      param_1[6] = (int)((float)uVar1 * *(float *)(iVar2 + 0x304) * DAT_00aaa638 + (float)param_1[6]

                        );

    }

    if ((*(byte *)(iVar2 + 0x3e1) & 4) != 0) {

      iVar2 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar2 + 0xc)) {

        *(uint32_t *)(iVar2 + 0xc) = 0;

      }

      uVar1 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

      *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

      iVar2 = param_1[1];

      param_1[0x3e] =

           (int)((float)uVar1 * *(float *)(iVar2 + 0x370) * DAT_00aaa638 + (float)param_1[0x3e]);

    }

    if ((*(byte *)(iVar2 + 0x3e1) & 0x10) != 0) {

      iVar2 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar2 + 0xc)) {

        *(uint32_t *)(iVar2 + 0xc) = 0;

      }

      uVar1 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

      *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

      iVar2 = param_1[1];

      param_1[0x40] =

           (int)((float)uVar1 * *(float *)(iVar2 + 0x378) * DAT_00aaa638 + (float)param_1[0x40]);

    }

    if ((*(char *)((int)param_1 + 0x242) == '\0') &&

       ((*(int *)(*param_1 + 0x8d4) == 0 || (*(int *)(*param_1 + 0x8d4) == 2)))) {

      param_1[6] = param_1[4];

      param_1[0x40] = param_1[0x3e];

    }

    if ((*(byte *)(iVar2 + 0x3e3) & 2) != 0) {

      *(byte *)((int)param_1 + 0x241) = *(byte *)(iVar2 + 0x3e3) >> 2 & 1;

    }

    piVar4 = param_1 + 4;

    piVar5 = param_1 + 0x21;

    for (iVar2 = 0x1d; iVar2 != 0; iVar2 = iVar2 + -1) {

      *piVar5 = *piVar4;

      piVar4 = piVar4 + 1;

      piVar5 = piVar5 + 1;

    }

    return;

  }

  fVar6 = g_flOne - (float)param_1[0x5c] / (float)param_1[0x5d];

  if ((*(byte *)(param_1[1] + 0x3e1) & 0x20) != 0) {

    FUN_004b2910(fVar6,param_1 + 0xd,param_1 + 0x2a,param_1 + 0x47);

  }

  if ((*(byte *)(param_1[1] + 0x3e2) & 1) != 0) {

    local_4 = (char)(int)ROUND((float)(int)((uint)*(byte *)((int)param_1 + 0x11f) -

                                           (uint)*(byte *)((int)param_1 + 0xab)) * fVar6);

    *(char *)((int)param_1 + 0x37) = *(char *)((int)param_1 + 0xab) + local_4;

  }

  iVar2 = param_1[1];

  if ((*(byte *)(iVar2 + 0x3e1) & 1) != 0) {

    fVar7 = ((float)param_1[0x3e] - (float)param_1[0x21]) * fVar6 + (float)param_1[0x21];

    param_1[4] = (int)fVar7;

    if (*(char *)(iVar2 + 0x308) == '\0') {

      param_1[6] = (int)(((float)param_1[0x40] - (float)param_1[0x23]) * fVar6 +

                        (float)param_1[0x23]);

    }

    else {

      param_1[6] = (int)((((float)param_1[0x40] - *(float *)(iVar2 + 0x300)) * fVar6 +

                         *(float *)(iVar2 + 0x300)) * fVar7);

    }

  }

  if ((*(byte *)(iVar2 + 0x3e2) & 0x40) != 0) {

    param_1[0xc] = (int)(((float)param_1[0x46] - (float)param_1[0x29]) * fVar6 +

                        (float)param_1[0x29]);

  }

  param_1[0xb] = (int)((float)param_1[9] * param_3 + (float)param_1[0xb]);

  return;

}
