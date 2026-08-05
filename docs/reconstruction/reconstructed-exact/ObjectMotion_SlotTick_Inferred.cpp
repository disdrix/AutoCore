// =============================================================================
// ObjectMotion_SlotTick_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004b4620
// Address:   0x004b4620 – 0x004b490d  (autoassault.exe, image base 0x400000)
// System:    client object motion / reaction slot
// Generated: 2026-07-29 W26-H dual seal (decompile + read_memory)
// Exactness: Behavior-preserving CF reconstruction. Twin FUN_004b4620.cpp is the
//            line-faithful decompiler mirror.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Outer per-slot tick for an object-motion / reaction entity bound to a host:
//     - profiler counter DAT_00d17958+0x13c
//     - early abort on host +0x98c bit6 + (+0x7f9|+0x7fa)
//     - radius pull when outside host sphere (+0x980) toward +0x880..888
//       * Y damp: if |dy| < radius*0.4 → dy *= -0.5
//       * normalize FUN_0076f5f0; scale by radius*0.99
//       * optional heightfield Y (host+0x989 bit4) via CVOGMap_SampleHeightfieldY
//     - duration countdown slot[0x5c]; secondary timer slot[0x5b] when host+0x7fb
//     - FUN_004b2b90 → ObjectMotion_IntegrateStep (FUN_004b1100) → optional FUN_004b18f0
//     - return 1 keep / 0 remove (sole caller FUN_005bb5e0 unlinks on 0)
//
// ABI:
//   __thiscall (ECX = slot); stack formals (flag:int-as-float bits, dt:float);
//   epilogue ret 8 (C2 08 00). Return AL 0|1.
//
// CONSTANTS (read_memory Confirmed):
//   DAT_00a0f720 = 0.4f; DAT_00aaa6cc = -0.5f; DAT_009c8354 ≈ 0.99f; g_flZero
//
// RELATED (sealed peers):
//   FUN_004b1100 = ObjectMotion_IntegrateStep_Inferred (W24-C)
//   FUN_004cd220 = CVOGMap_SampleHeightfieldY
// =============================================================================

#include <cstdint>

extern int DAT_00d17958;
extern float g_flZero;
extern float DAT_00a0f720;   // 0.4f
extern float DAT_00aaa6cc;   // -0.5f
extern float DAT_009c8354;   // ~0.99f
float ABS(float x);
void FUN_0076f5f0(float *out, float *in);
long double FUN_004cd220(float x, float z); // CVOGMap_SampleHeightfieldY
uint8_t __thiscall FUN_004b0f80(int *self, char mode);
void __thiscall FUN_004b2b90(int *self, int dirty, float dt);
void __thiscall FUN_004b1100(int *self, int flag, int dirty, float dt); // IntegrateStep
void __thiscall FUN_004b18f0(int *self, int flag);

// param_2 is integer flag (Ghidra types as float); param_3 = dt.
uint32_t __thiscall ObjectMotion_SlotTick_Inferred(int *param_1, float param_2, float param_3)
{
  float *pfVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  long double fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  uint32_t local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  iVar3 = (int)param_2;
  *(int *)(DAT_00d17958 + 0x13c) = *(int *)(DAT_00d17958 + 0x13c) + 1;
  iVar2 = *param_1;
  if (((*(uint8_t *)(iVar2 + 0x98c) & 0x40) != 0) &&
     ((*(char *)(iVar2 + 0x7f9) != '\0' || (*(char *)(iVar2 + 0x7fa) != '\0')))) {
    return 0;
  }
  local_28 = 0;
  if ((*(float *)(iVar2 + 0x980) != g_flZero) &&
     (fVar8 = *(float *)(iVar2 + 0x840) - (float)param_1[0x60],
     fVar7 = *(float *)(iVar2 + 0x83c) - (float)param_1[0x5f],
     fVar6 = *(float *)(iVar2 + 0x838) - (float)param_1[0x5e], pfVar1 = (float *)(param_1 + 0x5e),
     *(float *)(iVar2 + 0x980) * *(float *)(iVar2 + 0x980) <
     fVar8 * fVar8 + fVar7 * fVar7 + fVar6 * fVar6)) {
    if ((*(uint8_t *)(iVar2 + 0x989) & 2) != 0) {
      return 0;
    }
    local_14 = *(float *)(iVar2 + 0x884);
    local_18 = *(float *)(iVar2 + 0x880);
    local_10 = *(float *)(iVar2 + 0x888);
    local_8 = local_14 - (float)param_1[0x5f];
    local_24 = local_18 - *pfVar1;
    local_1c = local_10 - (float)param_1[0x60];
    local_20 = local_8;
    if (ABS(local_8) < *(float *)(iVar2 + 0x980) * DAT_00a0f720) {
      local_20 = local_8 * DAT_00aaa6cc;
    }
    FUN_0076f5f0(&local_24, &local_24);
    param_2 = 0.0f;
    if (((*(uint8_t *)(*param_1 + 0x989) & 4) != 0) && (iVar3 != 0)) {
      fVar5 = FUN_004cd220(*pfVar1, (float)param_1[0x60]);
      param_2 = (float)((long double)(float)param_1[0x5f] - fVar5);
    }
    fVar7 = DAT_009c8354;
    fVar6 = *(float *)(*param_1 + 0x980);
    local_c = local_24 * fVar6 * DAT_009c8354 + local_18;
    local_8 = local_20 * fVar6 * DAT_009c8354 + local_14;
    *pfVar1 = local_c;
    local_4 = local_1c * fVar6 * fVar7 + local_10;
    param_1[0x5f] = (int)local_8;
    param_1[0x60] = (int)local_4;
    if (((*(uint8_t *)(*param_1 + 0x989) & 4) != 0) && (iVar3 != 0)) {
      fVar5 = FUN_004cd220(*pfVar1, (float)param_1[0x60]);
      param_1[0x5f] = (int)(float)(fVar5 + (long double)param_2);
    }
    param_1[1] = *(int *)(*param_1 + 0x304);
    FUN_004b0f80(param_1, 0);
    local_28 = 1;
  }
  fVar6 = (float)param_1[0x5c];
  iVar2 = *(int *)(*param_1 + 0x308);
  param_1[0x5c] = (int)(fVar6 - param_3);
  if (fVar6 - param_3 <= 0.0f) {
    local_28 = 1;
    cVar4 = (char)FUN_004b0f80(param_1, 1);
    if (cVar4 == '\0') {
      return 0;
    }
  }
  if (*(char *)(*param_1 + 0x7fb) != '\0') {
    fVar6 = (float)param_1[0x5b];
    param_1[0x5b] = (int)(fVar6 - param_3);
    if (fVar6 - param_3 <= 0.0f) {
      return 0;
    }
    *(uint8_t *)(iVar2 + 0x2ee) = 0;
  }
  FUN_004b2b90(param_1, (int)local_28, param_3);
  FUN_004b1100(param_1, iVar3, (int)local_28, param_3);
  if (param_1[2] != 0) {
    FUN_004b18f0(param_1, iVar3);
  }
  *(uint8_t *)(param_1 + 0x90) = 0;
  return 1;
}
