// =============================================================================
// FUN_00951cc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00951cc0
// Address:   0x00951cc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00951cc0 @ 0x00951cc0
// Stable ID: aa_00951cc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_008076c0, FUN_00951cc0, Sleep.
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

uint32_t /* width from decompiler */ __fastcall FUN_00951cc0(int param_1)



{

  uint32_t /* width from decompiler */ local_10 [2];

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_10[0] = 0x2066;

  local_8 = 900000;

  local_4 = 0;

  if (*(int *)(param_1 + 0xc78) != 0) {

    (**(code **)(**(int **)(param_1 + 0xc78) + 0x18))(0xffffffff,local_10,0x10,0);

  }

  Sleep(2000);

  FUN_008076c0();

  return 0;

}
