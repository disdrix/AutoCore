// =============================================================================
// FUN_005ff810
// -----------------------------------------------------------------------------
// Stable ID: aa_005ff810
// Address:   0x005ff810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005ff810 @ 0x005ff810
// Stable ID: aa_005ff810
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0056d020, FUN_005ff810.
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

void __fastcall FUN_005ff810(int param_1)



{

  int iVar1;

  

  *(undefined ***)(param_1 + -0x150) = &PTR_LAB_009dda7c;

  *(undefined ***)(*(int *)(*(int *)(param_1 + -0x14c) + 4) + -0x14c + param_1) = &PTR_LAB_009dd7b4;

  iVar1 = *(int *)(*(int *)(param_1 + -0x14c) + 4);

  *(int *)(iVar1 + -0x150 + param_1) = iVar1 + -0x14c;

  FUN_0056d020();

  return;

}
