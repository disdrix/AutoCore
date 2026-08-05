// =============================================================================
// FUN_0094e9c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0094e9c0
// Address:   0x0094e9c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0094e9c0 @ 0x0094e9c0
// Stable ID: aa_0094e9c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0066e8d0, FUN_0066e9c0, FUN_0094e9c0.
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

uint32_t /* width from decompiler */ __fastcall FUN_0094e9c0(int param_1)



{

  char cVar1;

  

  if (*(int *)(param_1 + 0xdec) != 0) {

    cVar1 = FUN_0066e9c0();

    if (cVar1 != '\0') {

      FUN_0066e8d0();

    }

  }

  return 1;

}
