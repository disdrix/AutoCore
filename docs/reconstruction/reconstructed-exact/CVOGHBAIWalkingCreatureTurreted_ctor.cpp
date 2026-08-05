// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CVOGHBAIBase_ctor, CVOGHBAIWalkingCreatureTurreted_ctor, FUN_0063a700.
//  - Return sites: 1.

// =============================================================================
// CVOGHBAIWalkingCreatureTurreted_ctor
// -----------------------------------------------------------------------------
// Purpose:  Construct walking turreted-creature HBAI (AICode 6). Factory size 0xD0;
//           also mid-base for Default_ctor.
//
// Address:  0x00639830  (autoassault.exe, image base 0x400000)
// Stable:   aa_00639830
// System:   npc-ai / HBAI
//
// CreateByAICode skips post-ctor profile vtbl init for this AICode only.
//
// Exactness: CF mirrors raw; names cleaned; no invented clamps.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Human-refined plate: 2026-07-23 (AI managers readability)
// =============================================================================

uint32_t /* width from decompiler */ * __thiscall
CVOGHBAIWalkingCreatureTurreted_ctor(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)
{
  CVOGHBAIBase_ctor(param_2,param_3);
  *param_1 = &PTR_LAB_009e3cc0;
  param_1[0x30] = 0;
  param_1[4] = 0;
  FUN_0063a700(0);
  param_1[0x1f] = g_flOne;
  return param_1;
}
