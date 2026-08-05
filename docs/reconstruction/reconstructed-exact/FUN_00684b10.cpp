// =============================================================================
// FUN_00684b10
// -----------------------------------------------------------------------------
// Stable ID: aa_00684b10
// Address:   0x00684b10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00684b10 @ 0x00684b10
// Stable ID: aa_00684b10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00684b10, FUN_0076c3c0.
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

void __fastcall FUN_00684b10(int param_1)



{

  int iVar1;

  

  iVar1 = FUN_0076c3c0();

  *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + iVar1;

  if (*(int *)(param_1 + 0x74) < iVar1) {

    *(int *)(param_1 + 0x74) = iVar1;

  }

  return;

}
