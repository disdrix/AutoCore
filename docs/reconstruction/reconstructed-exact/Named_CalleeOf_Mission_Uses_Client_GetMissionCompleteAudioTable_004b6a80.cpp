// =============================================================================
// Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_004b6a80
// -----------------------------------------------------------------------------
// Stable ID: aa_004b6a80
// Callee of Mission_Uses_Client_GetMissionCompleteAudioTable
// Address:   0x004b6a80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Uses_Client_GetMissionCompleteAudioTable: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, while×1.
//  - Notable callees: CONCAT31, FUN_004b6a80.
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

uint __fastcall Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_004b6a80(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  

  puVar1 = (uint32_t /* width from decompiler */ *)**(uint32_t /* width from decompiler */ **)(param_1 + 0x1e0);

  while( true ) {

    if (puVar1 == *(uint32_t /* width from decompiler */ **)(param_1 + 0x1e0)) {

      return (uint)puVar1 & 0xffffff00;

    }

    if ((*(byte *)(puVar1[2] + 0x989) & 0x10) != 0) break;

    puVar1 = (uint32_t /* width from decompiler */ *)*puVar1;

  }

  return CONCAT31((int3)((uint)puVar1 >> 8),1);

}
