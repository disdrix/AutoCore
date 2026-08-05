// =============================================================================
// FUN_0079cc30
// -----------------------------------------------------------------------------
// Stable ID: aa_0079cc30
// Address:   0x0079cc30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0079cc30 @ 0x0079cc30
// Stable ID: aa_0079cc30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0079cc30, fwrite.
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

int __thiscall FUN_0079cc30(int param_1,void *param_2,size_t param_3)



{

  size_t sVar1;

  

  if ((((*(FILE **)(param_1 + 0x694) != (FILE *)0x0) && (*(char *)(param_1 + 5) == '\0')) &&

      (*(char *)(param_1 + 6) != '\0')) && ((param_2 != (void *)0x0 && (param_3 != 0)))) {

    sVar1 = fwrite(param_2,param_3,1,*(FILE **)(param_1 + 0x694));

    return sVar1 * param_3;

  }

  return 0;

}
