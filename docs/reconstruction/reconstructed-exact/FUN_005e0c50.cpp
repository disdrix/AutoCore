// =============================================================================
// FUN_005e0c50
// -----------------------------------------------------------------------------
// Stable ID: aa_005e0c50
// Address:   0x005e0c50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005e0c50 @ 0x005e0c50
// Stable ID: aa_005e0c50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CVOGReaction_FailMissionNotify, FUN_005e0430, FUN_005e0480, FUN_005e0c50.
//  - Return sites: 1.

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

void FUN_005e0c50(uint32_t /* width from decompiler */ param_1,short param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  

  if ((param_2 < 0x33) && (iVar1 = FUN_005e0480(param_1), -1 < iVar1)) {

    FUN_005e0430(param_4);

    CVOGReaction_FailMissionNotify(&stack0x00000014);

  }

  return;

}
