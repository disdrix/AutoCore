// =============================================================================
// FUN_00770970
// -----------------------------------------------------------------------------
// Stable ID: aa_00770970
// Address:   0x00770970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00770970 @ 0x00770970
// Stable ID: aa_00770970
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00770650, FUN_00770970.
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

int FUN_00770970(void)



{

  int in_EAX;

  int iVar1;

  int unaff_ESI;

  

  if ((in_EAX != unaff_ESI) && (iVar1 = FUN_00770650(), iVar1 != 0)) {

    return iVar1;

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = 0;

  return 0;

}
