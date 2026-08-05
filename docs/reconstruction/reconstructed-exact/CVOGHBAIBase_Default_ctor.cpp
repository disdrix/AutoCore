// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CVOGHBAIBase_Default_ctor, CVOGHBAIWalkingCreatureTurreted_ctor, FUN_0063a700.
//  - Return sites: 1.

// =============================================================================
// CVOGHBAIBase_Default_ctor
// -----------------------------------------------------------------------------
// Purpose:  Default HBAI when AICode is unrecognized: construct WalkingCreatureTurreted
//           mid-size base, install default vtable, seed scalar +0x1f = g_flOne.
//
// Address:  0x0063c940  (autoassault.exe, image base 0x400000)
// Stable:   aa_0063c940
// System:   npc-ai / HBAI
//
// Calls: CVOGHBAIWalkingCreatureTurreted_ctor -> FUN_0063a700(0).
// Vtable: PTR_FUN_009e3d40. Size family 0xD0 (factory default branch).
//
// Exactness: CF mirrors raw; names cleaned; no invented clamps.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Human-refined plate: 2026-07-23 (AI managers readability)
// =============================================================================

uint32_t /* width from decompiler */ * __thiscall
CVOGHBAIBase_Default_ctor(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)
{
  CVOGHBAIWalkingCreatureTurreted_ctor(param_2,param_3);
  *param_1 = &PTR_FUN_009e3d40;
  param_1[4] = 0;
  FUN_0063a700(0);
  param_1[0x1f] = g_flOne;
  return param_1;
}
