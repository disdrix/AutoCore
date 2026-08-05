// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CVOGCharacter_AddAttributePoints, Client_SendLogicUiPacket, pool.
//  - Return sites: 1.

// =============================================================================
// CVOGCharacter_AddAttributePoints
// -----------------------------------------------------------------------------
// Stable ID: aa_00531250
// Address:   0x00531250  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 */

/* CVOGCharacter_AddAttributePoints - add short attribute points to character pool (mission

   advance/complete).

   

   Parameters: attrib delta

   Called from CVOGReaction_CompleteObjective on both advance and final branches. */



void __thiscall CVOGCharacter_AddAttributePoints(int param_1,short param_2)



{

  int iVar1;

  uint8_t local_138 [28];

  uint32_t /* or float bits */ local_11c;

  uint32_t /* or float bits */ local_118;

  uint32_t /* or float bits */ local_114;

  

  if (*(short *)(param_1 + 0x6cc) < param_2) {

    iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);

    local_118 = *(uint32_t /* or float bits */ *)(iVar1 + 0x164 + param_1);

    local_114 = *(uint32_t /* or float bits */ *)(iVar1 + param_1 + 0x168);

    local_11c = 0x23;

    Client_SendLogicUiPacket(local_138);

  }

  *(uint *)(param_1 + 0x634) = *(uint *)(param_1 + 0x634) | 0x40;

  *(short *)(param_1 + 0x6cc) = param_2;

  return;

}
