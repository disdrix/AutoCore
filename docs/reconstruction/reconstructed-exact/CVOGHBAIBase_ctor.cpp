// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CVOGHBAIBase_ctor, FUN_005eadb0.
//  - Return sites: 1.

// =============================================================================
// CVOGHBAIBase_ctor
// -----------------------------------------------------------------------------
// Purpose:  Construct base HBAI: vtable, zero fields, default floats (g_flOne range
//           scales), clear target/owner slots used by FindTarget/GetTargetFromAggro.
//
// Address:  0x005d3b30  (autoassault.exe, image base 0x400000)
// Stable:   aa_005d3b30
// System:   npc-ai / HBAI
//
// Convention: MSVC __thiscall; returns this.
// Key zeros: target ptrs, range slots, aggro-related floats at +0x08..+0x5C.
// Vtable: PTR_LAB_009daad0.
// Parent for CreatureBase / CharacterOrMine / Bot factories.
//
// Exactness: CF mirrors raw; names cleaned; no invented clamps.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Human-refined plate: 2026-07-23 (AI managers readability)
// =============================================================================

uint32_t /* width from decompiler */ * __thiscall
CVOGHBAIBase_ctor(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3)
{
  float fVar1;
  
  fVar1 = g_flOne;
  param_1[2] = 0;
  *param_1 = &PTR_LAB_009daad0;
  param_1[0x13] = 0;
  param_1[0x12] = 0;
  param_1[0x11] = 0;
  param_1[0x10] = 0;
  param_1[0x17] = 0;
  param_1[0x16] = 0;
  param_1[0x15] = 0;
  param_1[0x14] = 0;
  param_1[0xb] = 0;
  param_1[10] = 0;
  param_1[9] = 0;
  param_1[8] = 0;
  param_1[3] = fVar1;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[0xb] = 0;
  param_1[10] = 0;
  param_1[9] = 0;
  param_1[8] = 0;
  param_1[0x18] = *param_2;
  param_1[0x19] = param_2[1];
  param_1[0x1a] = param_2[2];
  param_1[0x1b] = param_2[3];
  param_1[0x1b] = 0;
  param_1[0x1c] = *param_2;
  param_1[0x1d] = param_2[1];
  param_1[0x1e] = param_2[2];
  param_1[0x1f] = param_2[3];
  param_1[0x2c] = *param_2;
  param_1[0x2d] = param_2[1];
  param_1[0x2e] = param_2[2];
  param_1[0x2f] = param_2[3];
  param_1[0xc] = *param_3;
  param_1[0xd] = param_3[1];
  param_1[0xe] = param_3[2];
  param_1[0xf] = param_3[3];
  FUN_005eadb0(param_3);
  param_1[0x1f] = 0;
  return param_1;
}
