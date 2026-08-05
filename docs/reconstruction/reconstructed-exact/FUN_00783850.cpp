// =============================================================================
// FUN_00783850
// -----------------------------------------------------------------------------
// Stable ID: aa_00783850
// Address:   0x00783850  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00783850 @ 0x00783850
// Stable ID: aa_00783850
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0077c610, FUN_00783850.
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

void FUN_00783850(int param_1,int param_2,int param_3,int param_4)



{

  int unaff_ESI;

  

  *(int *)(unaff_ESI + 0xc) = *(int *)(unaff_ESI + 0x1c) + param_1;

  *(int *)(unaff_ESI + 0x10) = *(int *)(unaff_ESI + 0x20) + param_2;

  *(int *)(unaff_ESI + 0x14) = *(int *)(unaff_ESI + 0x24) + param_3;

  *(int *)(unaff_ESI + 0x18) = *(int *)(unaff_ESI + 0x28) + param_4;

  FUN_0077c610((int *)(unaff_ESI + 0xc),unaff_ESI + 0x5c,unaff_ESI + 0x6c);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x270) = 0;

  return;

}
