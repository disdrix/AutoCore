// =============================================================================
// FUN_00757510
// -----------------------------------------------------------------------------
// Stable ID: aa_00757510
// Address:   0x00757510  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00757510 @ 0x00757510
// Stable ID: aa_00757510
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_00999830×2, FUN_00757510.
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

uint32_t /* width from decompiler */ __thiscall FUN_00757510(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  

  if (param_2 == 0) {

    return 1;

  }

  if (*(int *)(*(int *)(param_1 + 4) + 4) == 0) {

    uVar1 = FUN_00999830(param_2,0);

    return uVar1;

  }

  uVar1 = FUN_00999830(param_2,*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 4) + 4));

  return uVar1;

}
