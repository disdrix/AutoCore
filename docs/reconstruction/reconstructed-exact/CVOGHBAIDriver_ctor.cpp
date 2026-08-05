// READABILITY (auto CF):
//  - Body size: ~7 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CVOGHBAICharacterOrMine_ctor, CVOGHBAIDriver_ctor.
//  - Return sites: 1.

// =============================================================================
// CVOGHBAIDriver_ctor
// -----------------------------------------------------------------------------
// Purpose:  Construct vehicle-driver HBAI (AICode 5, DR: profiles). Extends
//           CharacterOrMine mid-size (factory 0x110).
//
// Address:  0x0063cb50  (autoassault.exe, image base 0x400000)
// Stable:   aa_0063cb50
// System:   npc-ai / HBAI
//
// DoLogic is the main tick (not CreatureBase_OnHeartBeat for drivers).
// Uses MapPath_AdvanceAndSteer + ReturnToNormalLocation + FireWeapons.
//
// Exactness: CF mirrors raw; names cleaned; no invented clamps.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Human-refined plate: 2026-07-23 (AI managers readability)
// =============================================================================

uint32_t /* width from decompiler */ * __thiscall
CVOGHBAIDriver_ctor(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)
{
  CVOGHBAICharacterOrMine_ctor(param_2,param_3);
  *param_1 = &PTR_LAB_009e3dc0;
  return param_1;
}
