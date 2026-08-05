// =============================================================================
// FUN_00605f80
// -----------------------------------------------------------------------------
// Stable ID: aa_00605f80
// Address:   0x00605f80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00605f80 @ 0x00605f80
// Stable ID: aa_00605f80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005cb480, FUN_00605f80.
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

void __fastcall FUN_00605f80(int param_1)



{

  int iVar1;

  

  *(undefined ***)(param_1 + -0xd0) = &PTR_FUN_009de73c;

  *(undefined ***)(*(int *)(*(int *)(param_1 + -0xcc) + 4) + -0xcc + param_1) = &PTR_LAB_009de474;

  iVar1 = *(int *)(*(int *)(param_1 + -0xcc) + 4);

  *(int *)(iVar1 + -0xd0 + param_1) = iVar1 + -0xcc;

  FUN_005cb480();

  return;

}
