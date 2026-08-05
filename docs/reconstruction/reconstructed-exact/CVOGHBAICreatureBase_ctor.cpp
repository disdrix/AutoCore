// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CVOGHBAIBase_ctor, CVOGHBAICreatureBase_ctor.
//  - Return sites: 1.

// =============================================================================
// CVOGHBAICreatureBase_ctor
// -----------------------------------------------------------------------------
// Purpose:  Construct foot-creature HBAI (AICode 2) -- default walking AI. Chains base
//           ctor, installs CreatureBase vtable; factory size 0x100.
//
// Address:  0x005d3c40  (autoassault.exe, image base 0x400000)
// Stable:   aa_005d3c40
// System:   npc-ai / HBAI
//
// Parent of Driver/FollowVehicle behavior via shared pursue/heading helpers.
// OnHeartBeat virtual is the main tick for non-driver creatures.
//
// Exactness: CF mirrors raw; names cleaned; no invented clamps.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Human-refined plate: 2026-07-23 (AI managers readability)
// =============================================================================

uint32_t /* width from decompiler */ * __thiscall
CVOGHBAICreatureBase_ctor(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)
{
  CVOGHBAIBase_ctor(param_2,param_3);
  *param_1 = &PTR_LAB_009dab50;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  param_1[0x34] = 0;
  param_1[0x35] = 0;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  return param_1;
}
