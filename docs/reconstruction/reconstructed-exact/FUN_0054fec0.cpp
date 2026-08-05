// =============================================================================
// FUN_0054fec0
// -----------------------------------------------------------------------------
// Stable ID: aa_0054fec0
// Address:   0x0054fec0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0054fec0 @ 0x0054fec0
// Stable ID: aa_0054fec0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0054fec0, FUN_00627be0.
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

void __fastcall FUN_0054fec0(int param_1)



{

  uint uVar1;

  

  uVar1 = FUN_00627be0();

  if (*(uint *)(param_1 + 0x620) == 0) {

    *(uint *)(param_1 + 0x624) = uVar1;

  }

  else {

    *(uint *)(param_1 + 0x624) = uVar1 | 4;

    if (*(char *)(param_1 + 0x148) == '\0') {

      *(uint *)(param_1 + 0x620) = *(uint *)(param_1 + 0x620) | 0x100000;

      return;

    }

  }

  return;

}
