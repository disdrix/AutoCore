// =============================================================================
// Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_0049cc30
// -----------------------------------------------------------------------------
// Stable ID: aa_0049cc30
// Callee of Mission_Uses_Client_GetMissionCompleteAudioTable
// Address:   0x0049cc30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Uses_Client_GetMissionCompleteAudioTable: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0049cc30, FUN_0058f780.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Mission_Uses_Client_GetMissionCompleteAudioTable
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_0049cc30(int param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  

  if ((*(byte *)(param_1 + 0x90e) & 0x20) != 0) {

    return 1;

  }

  uVar1 = FUN_0058f780(param_2);

  return uVar1;

}
