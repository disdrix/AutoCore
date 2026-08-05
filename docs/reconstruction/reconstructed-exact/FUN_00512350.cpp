// =============================================================================
// FUN_00512350
// -----------------------------------------------------------------------------
// Stable ID: aa_00512350
// Address:   0x00512350  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00512350 @ 0x00512350
// Stable ID: aa_00512350
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGClonedObjectBase.cpp"
//   - "Trying to write too large COID, bad things are about to happen"
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00512350, FUN_007a4480, fwrite, vog_LogMessage.
//  - Strings: ",0x149b,2,

                   "; ");

    FUN_007a4480(0,".
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

void FUN_00512350(FILE *param_1,uint *param_2)



{

  uint *puVar1;

  

  puVar1 = param_2 + 1;

  param_2 = (uint *)*param_2;

  if ((-1 < (int)*puVar1) && ((0 < (int)*puVar1 || (0x7fffffff < param_2)))) {

    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGClonedObjectBase.cpp",0x149b,2,

                   "Trying to write too large COID, bad things are about to happen");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  fwrite(&param_2,4,1,param_1);

  return;

}
