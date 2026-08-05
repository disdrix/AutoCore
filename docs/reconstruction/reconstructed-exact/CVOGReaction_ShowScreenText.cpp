// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CVOGReaction_ShowScreenText, Client_SendLogicUiPacket.
//  - Return sites: 1.

// =============================================================================
// CVOGReaction_ShowScreenText
// -----------------------------------------------------------------------------
// Stable ID: aa_0057c4a0
// Address:   0x0057c4a0  (autoassault.exe, image base 0x400000)
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
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall CVOGReaction_ShowScreenText(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ local_138 [7];

  uint32_t /* width from decompiler */ local_11c;

  uint32_t /* width from decompiler */ local_110;

  uint32_t /* width from decompiler */ local_10c;

  uint32_t /* width from decompiler */ local_108;

  uint32_t /* width from decompiler */ local_104;

  

  local_138[0] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x160);

  local_110 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x160);

  local_10c = *(uint32_t /* width from decompiler */ *)(param_2 + 0x164);

  local_108 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x168);

  local_104 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x16c);

  local_11c = 0x26;

  Client_SendLogicUiPacket(local_138);

  return;

}
