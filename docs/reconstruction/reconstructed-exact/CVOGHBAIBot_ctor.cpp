// READABILITY (auto CF):
//  - Body size: ~6 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CVOGHBAIBot_ctor, CVOGHBAICreatureBase_ctor.
//  - Return sites: 1.

// =============================================================================
// CVOGHBAIBot_ctor
// -----------------------------------------------------------------------------
// Purpose:  Construct Bot HBAI (AICode 3) -- summons / bot AI. Chains CreatureBase-family
//           mid ctor and installs Bot vtable.
//
// Address:  0x005d3cf0  (autoassault.exe, image base 0x400000)
// Stable:   aa_005d3cf0
// System:   npc-ai / HBAI
//
// Factory alloc size 0x100. Profile string family: "Bot summons ai".
//
// Exactness: CF mirrors raw; names cleaned; no invented clamps.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Human-refined plate: 2026-07-23 (AI managers readability)
// =============================================================================

uint32_t /* width from decompiler */ * __thiscall CVOGHBAIBot_ctor(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)
{
  CVOGHBAICreatureBase_ctor(param_2,param_3);
  *param_1 = &PTR_LAB_009dabd0;
  return param_1;
}
