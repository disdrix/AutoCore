// =============================================================================
// FUN_00610f20
// -----------------------------------------------------------------------------
// Stable ID: aa_00610f20
// Address:   0x00610f20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00610f20 @ 0x00610f20
// Stable ID: aa_00610f20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_005711c0, FUN_00610f20.
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

uint32_t /* width from decompiler */ __thiscall FUN_00610f20(int param_1,int param_2,int param_3)



{

  int iVar1;

  

  if ((*(int *)(param_1 + 0x18) == param_2) && (*(int *)(*(int *)(param_3 + 0x250) + 0x2b0) != 0)) {

    iVar1 = FUN_005711c0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x10),0);

    if ((*(int *)(param_1 + 0x14) <= iVar1) || (*(char *)(param_1 + 0x23) == '\0')) {

      return 1;

    }

  }

  return 0;

}
