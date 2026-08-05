// =============================================================================
// FUN_007707a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007707a0
// Address:   0x007707a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007707a0 @ 0x007707a0
// Stable ID: aa_007707a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_00770710×2, FUN_007707a0.
//  - Return sites: 3.

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

int FUN_007707a0(void)



{

  int in_EAX;

  int iVar1;

  int unaff_ESI;

  

  iVar1 = *(int *)(unaff_ESI + 8);

  if (iVar1 != *(int *)(in_EAX + 8)) {

    return (uint)(iVar1 != 1) * 2 + -1;

  }

  if (iVar1 == 1) {

    iVar1 = FUN_00770710();

    return iVar1;

  }

  iVar1 = FUN_00770710();

  return iVar1;

}
