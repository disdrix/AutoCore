// =============================================================================
// FUN_005c8270
// -----------------------------------------------------------------------------
// Stable ID: aa_005c8270
// Address:   0x005c8270  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c8270 @ 0x005c8270
// Stable ID: aa_005c8270
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00518370, FUN_005c8270.
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

void __fastcall FUN_005c8270(int param_1)



{

  int iVar1;

  

  iVar1 = 0;

  if (1 < *(int *)(param_1 + -0x30)) {

    iVar1 = ((*(int *)(param_1 + -0x30) - *(int *)(param_1 + -0x34)) * 3) /

            *(int *)(param_1 + -0x30);

  }

  FUN_00518370(iVar1);

  return;

}
