// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CVOGCharacter_AddSkillPoints, Client_SendLogicUiPacket, delta, pool.
//  - Return sites: 1.

// =============================================================================
// CVOGCharacter_AddSkillPoints
// -----------------------------------------------------------------------------
// Stable ID: aa_005312c0
// Address:   0x005312c0  (autoassault.exe, image base 0x400000)
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

/* CVOGCharacter_AddSkillPoints - add short skill points to character pool (mission

   advance/complete).

   

   Parameters: skill delta (short)

   Called from CVOGReaction_CompleteObjective on both advance and final branches. */



void __thiscall CVOGCharacter_AddSkillPoints(int param_1,short param_2)



{

  int iVar1;

  uint8_t local_138 [28];

  uint32_t /* width from decompiler */ local_11c;

  uint32_t /* width from decompiler */ local_118;

  uint32_t /* width from decompiler */ local_114;

  

  if (*(short *)(param_1 + 0x6ce) < param_2) {

    iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);

    local_118 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x164 + param_1);

    local_114 = *(uint32_t /* width from decompiler */ *)(iVar1 + param_1 + 0x168);

    local_11c = 0x21;

    Client_SendLogicUiPacket(local_138);

  }

  *(uint *)(param_1 + 0x634) = *(uint *)(param_1 + 0x634) | 0x40;

  *(short *)(param_1 + 0x6ce) = param_2;

  return;

}
