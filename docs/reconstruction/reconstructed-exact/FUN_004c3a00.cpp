// =============================================================================
// FUN_004c3a00
// -----------------------------------------------------------------------------
// Stable ID: aa_004c3a00
// Address:   0x004c3a00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c3a00 @ 0x004c3a00
// Stable ID: aa_004c3a00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_004c3a00.
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

undefined * __fastcall FUN_004c3a00(int param_1)



{

  int iVar1;

  

  if ((*(int *)(param_1 + -0x2b0) == 0) || (*(char *)(param_1 + -500) == '\0')) {

    if (*(int *)(param_1 + -0x4f8) != 0) {

      return (undefined *)(*(int *)(*(int *)(param_1 + -0x4f8) + 0x3c) + 0x40);

    }

  }

  else {

    iVar1 = *(int *)(*(int *)(param_1 + -0x2b0) + 8);

    if (iVar1 != 0) {

      return (undefined *)(*(int *)(iVar1 + 0x3c) + 0x40);

    }

  }

  return &DAT_00b037b0;

}
