// =============================================================================
// FUN_00756d40
// -----------------------------------------------------------------------------
// Stable ID: aa_00756d40
// Address:   0x00756d40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00756d40 @ 0x00756d40
// Stable ID: aa_00756d40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00756be0×2, FUN_004406e0, FUN_00756d40.
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

uint32_t /* width from decompiler */ __fastcall FUN_00756d40(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x88);

  if (iVar1 != 0) {

    FUN_00756be0(param_1);

    if (*(int *)(param_1 + 0x88) != 0) {

      FUN_00756be0(param_1);

    }

    *(int *)(param_1 + 0x88) = iVar1;

    FUN_004406e0();

    return 0;

  }

  return 0xffffffff;

}
