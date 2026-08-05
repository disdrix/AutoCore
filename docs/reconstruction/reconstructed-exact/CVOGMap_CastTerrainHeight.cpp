// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_0055e530, FUN_005a58c0, from.
//  - Return sites: 3.

// =============================================================================
// CVOGMap_CastTerrainHeight
// -----------------------------------------------------------------------------
// Stable ID: aa_004cfe60
// Address:   0x004cfe60  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* Terrain height raycast used by CreateCreature / FindTerrainHeight.

   Casts down from (x,z,yStart) against map collision. */



float10 __thiscall

CVOGMap_CastTerrainHeight

          (int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,float param_4,char param_5)



{

  float10 fVar1;

  uint32_t /* width from decompiler */ local_70;

  float local_6c;

  uint32_t /* width from decompiler */ local_68;

  uint32_t /* width from decompiler */ local_64;

  uint32_t /* width from decompiler */ local_60;

  float local_5c;

  uint32_t /* width from decompiler */ local_58;

  uint32_t /* width from decompiler */ local_54;

  uint8_t local_50;

  int local_4c;

  uint8_t local_40 [20];

  float local_2c;

  int local_20;

  

  if (*(int *)(param_1 + 0xe4e0) == 0) {

    return (float10)g_flZero;

  }

  fVar1 = (float10)FUN_005a58c0(param_2,param_3);

  local_5c = (float)fVar1 + DAT_00a0f718;

  local_2c = g_flOne;

  local_6c = param_4;

  local_4c = (-(uint)(param_5 != '\0') & 0xd) + 5;

  local_20 = 0;

  local_70 = param_2;

  local_68 = param_3;

  local_64 = 0;

  local_50 = 0;

  local_60 = param_2;

  local_58 = param_3;

  local_54 = 0;

  FUN_0055e530(&local_70,local_40);

  if (local_20 != 0) {

    return (float10)(local_6c * (g_flOne - local_2c) + local_5c * local_2c);

  }

  return (float10)(float)fVar1;

}
