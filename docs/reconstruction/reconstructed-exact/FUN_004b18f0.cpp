// =============================================================================
// FUN_004b18f0  (decompiler-faithful twin)
// -----------------------------------------------------------------------------
// Stable ID: aa_004b18f0
// Address:   0x004b18f0 – 0x004b1a56  (autoassault.exe, image base 0x400000)
// Structural: ObjectMotion_SyncChildPoseHF_Inferred
// Generated: 2026-07-29 W27-F — line-faithful mirror of live decompile
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

extern float DAT_00aaa8f4;
extern uint32_t DAT_00afdef0;
extern uint32_t DAT_00b03530;
extern uint32_t DAT_00b03534;
extern uint32_t DAT_00b03538;
extern uint8_t DAT_00aef980[];

void FUN_00973820(void *p);
void FUN_00973690(uint32_t a, uint32_t b, uint32_t c);
uint8_t FUN_006a3db0(void);
long double FUN_004cd220(uint32_t x, uint32_t z);

void __thiscall FUN_004b18f0(int param_1, int param_2)
{
  int iVar1;
  uint8_t uVar2;
  long double fVar3;
  float fVar4;

  if (param_2 != 0) {
    FUN_00973820(&DAT_00aef980);
    FUN_00973690(0x3f400000u,
                 *(uint32_t *)(*(int *)(param_1 + 8) + 0x34),
                 DAT_00afdef0);
    uVar2 = FUN_006a3db0();
    *(uint8_t *)(*(int *)(param_1 + 8) + 0x37) = uVar2;
    *(uint32_t *)(*(int *)(param_1 + 8) + 0x10) = *(uint32_t *)(param_1 + 0x10);
    *(uint32_t *)(*(int *)(param_1 + 8) + 0x18) = *(uint32_t *)(param_1 + 0x18);
    *(uint32_t *)(*(int *)(param_1 + 8) + 0x2c) = *(uint32_t *)(param_1 + 0x2c);
    fVar3 = (long double)FUN_004cd220(*(uint32_t *)(param_1 + 0x178),
                                      *(uint32_t *)(param_1 + 0x180));
    fVar4 = *(float *)(param_1 + 0x17c);
    iVar1 = *(int *)(param_1 + 8);
    *(uint32_t *)(iVar1 + 0x178) = DAT_00b03530;
    *(uint32_t *)(iVar1 + 0x17c) = DAT_00b03534;
    *(uint32_t *)(iVar1 + 0x180) = DAT_00b03538;
    iVar1 = *(int *)(param_1 + 8);
    fVar4 = 0.0f - (float)((long double)fVar4 - fVar3) / *(float *)(iVar1 + 0x17c);
    *(float *)(iVar1 + 0x178) = *(float *)(iVar1 + 0x178) * fVar4;
    *(float *)(iVar1 + 0x17c) = *(float *)(iVar1 + 0x17c) * fVar4;
    *(float *)(iVar1 + 0x180) = *(float *)(iVar1 + 0x180) * fVar4;
    iVar1 = *(int *)(param_1 + 8);
    *(float *)(iVar1 + 0x178) = *(float *)(param_1 + 0x178) + *(float *)(iVar1 + 0x178);
    *(float *)(iVar1 + 0x17c) = *(float *)(param_1 + 0x17c) + *(float *)(iVar1 + 0x17c);
    *(float *)(iVar1 + 0x180) = *(float *)(param_1 + 0x180) + *(float *)(iVar1 + 0x180);
    *(float *)(*(int *)(param_1 + 8) + 0x17c) =
        *(float *)(*(int *)(param_1 + 8) + 0x17c) + DAT_00aaa8f4;
  }
  return;
}
