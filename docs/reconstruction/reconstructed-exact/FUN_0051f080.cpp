// =============================================================================
// FUN_0051f080
// -----------------------------------------------------------------------------
// Stable ID: aa_0051f080
// Address:   0x0051f080  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0051f080 @ 0x0051f080
// Stable ID: aa_0051f080
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0051f080, FUN_005cbc00.
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

void __fastcall FUN_0051f080(int param_1)



{

  int iVar1;

  

  *(undefined ***)(param_1 + -0x110) = &PTR_LAB_009ce814;

  *(undefined ***)(param_1 + -0xd0) = &PTR_FUN_009ce7d8;

  *(undefined ***)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x10c + param_1) = &PTR_LAB_009ce514;

  iVar1 = *(int *)(*(int *)(param_1 + -0x10c) + 4);

  *(int *)(iVar1 + -0x110 + param_1) = iVar1 + -0x10c;

  FUN_005cbc00();

  return;

}
