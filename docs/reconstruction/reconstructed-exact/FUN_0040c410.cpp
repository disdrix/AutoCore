// =============================================================================
// FUN_0040c410  (twin of SoftCastHitList_CtorInitBuffer_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0040c410
// Address:   0x0040c410 – 0x0040c4df inclusive (208 B / 0xD0)
// Module:    autoassault.exe (image base 0x400000)
// System:    interaction-activation
// Generated: 2026-08-05 MEGA-111 OWN dual — Ghidra-name twin
// Exactness: Behavior-preserving; prefer named twin for AutoCore port notes.
// Canonical: SoftCastHitList_CtorInitBuffer_Inferred
// =============================================================================

#include <cstdint>

extern "C" float g_flOne;
extern "C" void *PTR_LAB_00a2f52c;
extern "C" void *PTR_LAB_00a2f538;

// Ghidra signature form: first stack arg = object*; RET 4; void.
void FUN_0040c410(uint32_t *param_1)
{
  float fVar1 = g_flOne;

  *param_1 = reinterpret_cast<uint32_t>(&PTR_LAB_00a2f52c);
  param_1[1] = *reinterpret_cast<uint32_t *>(&fVar1);
  *param_1 = reinterpret_cast<uint32_t>(&PTR_LAB_00a2f538);
  param_1[4] = reinterpret_cast<uint32_t>(param_1 + 8);
  param_1[5] = 0;
  param_1[6] = 0x80000008;
  param_1[0x0d] = *reinterpret_cast<uint32_t *>(&fVar1);
  param_1[0x10] = 0;
  param_1[0x19] = *reinterpret_cast<uint32_t *>(&fVar1);
  param_1[0x1c] = 0;
  param_1[0x25] = *reinterpret_cast<uint32_t *>(&fVar1);
  param_1[0x28] = 0;
  param_1[0x31] = *reinterpret_cast<uint32_t *>(&fVar1);
  param_1[0x34] = 0;
  param_1[0x3d] = *reinterpret_cast<uint32_t *>(&fVar1);
  param_1[0x40] = 0;
  param_1[0x49] = *reinterpret_cast<uint32_t *>(&fVar1);
  param_1[0x4c] = 0;
  param_1[0x55] = *reinterpret_cast<uint32_t *>(&fVar1);
  param_1[0x58] = 0;
  param_1[0x61] = *reinterpret_cast<uint32_t *>(&fVar1);
  param_1[100] = 0; // decimal 100 == 0x64 → elem7 +0x20
  param_1[5] = 0;
  param_1[1] = *reinterpret_cast<uint32_t *>(&fVar1);
}
