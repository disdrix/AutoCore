// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CVOGHBAIBase_ctor, CVOGHBAICharacterOrMine_ctor.
//  - Return sites: 1.

// =============================================================================
// CVOGHBAICharacterOrMine_ctor
// -----------------------------------------------------------------------------
// Purpose:  Shared mid-size ctor for Character (AICode 1) and Mine (AICode 4) HBAI.
//           Factory size 0x110.
//
// Address:  0x0063d0b0  (autoassault.exe, image base 0x400000)
// Stable:   aa_0063d0b0
// System:   npc-ai / HBAI
//
// Character path may redirect to CreatureBase when profile val gate fails
// (see CreateByAICode case 1 ABS-sum check).
//
// Exactness: CF mirrors raw; names cleaned; no invented clamps.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Human-refined plate: 2026-07-23 (AI managers readability)
// =============================================================================

uint32_t /* width from decompiler */ * __thiscall
CVOGHBAICharacterOrMine_ctor(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)
{
  float fVar1;
  
  CVOGHBAIBase_ctor(param_2,param_3);
  fVar1 = g_flOne;
  *param_1 = &PTR_LAB_009e3e40;
  param_1[0x38] = fVar1;
  param_1[0x39] = fVar1;
  param_1[0x3a] = fVar1;
  param_1[0x3b] = fVar1;
  param_1[0x3f] = 0;
  param_1[0x3e] = 0;
  param_1[0x3d] = 0;
  param_1[0x3c] = 0;
  param_1[0x43] = 0;
  param_1[0x42] = 0;
  param_1[0x41] = 0;
  param_1[0x40] = 0;
  param_1[0x33] = 0;
  param_1[0x32] = 0;
  param_1[0x31] = 0;
  param_1[0x30] = 0;
  param_1[0x37] = 0;
  param_1[0x36] = 0;
  param_1[0x35] = 0;
  param_1[0x34] = 0;
  param_1[4] = DAT_00aaa668;
  return param_1;
}
