// =============================================================================
// FUN_004329a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004329a0
// Address:   0x004329a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004329a0 @ 0x004329a0
// Stable ID: aa_004329a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: fseek×2, ftell×2, FUN_004329a0.
//  - Return sites: 2.

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

long __fastcall FUN_004329a0(int param_1)



{

  long _Offset;

  long lVar1;

  

  if (*(FILE **)(param_1 + 4) == (FILE *)0x0) {

    return -1;

  }

  _Offset = ftell(*(FILE **)(param_1 + 4));

  fseek(*(FILE **)(param_1 + 4),0,2);

  lVar1 = ftell(*(FILE **)(param_1 + 4));

  fseek(*(FILE **)(param_1 + 4),_Offset,0);

  return lVar1;

}
