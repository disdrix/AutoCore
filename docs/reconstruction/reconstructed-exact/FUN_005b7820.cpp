// =============================================================================
// FUN_005b7820
// -----------------------------------------------------------------------------
// Stable ID: aa_005b7820
// Address:   0x005b7820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b7820 @ 0x005b7820
// Stable ID: aa_005b7820
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005b7820, FUN_00752a00, FUN_0096f5d0, FUN_0096fdf0.
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

int FUN_005b7820(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  int iVar2;

  

  cVar1 = FUN_0096fdf0();

  iVar2 = FUN_00752a00(param_1,param_2);

  if ((iVar2 == -1) && (cVar1 != '\0')) {

    FUN_0096f5d0();

  }

  return iVar2;

}
