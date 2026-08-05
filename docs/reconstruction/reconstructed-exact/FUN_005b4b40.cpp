// =============================================================================
// FUN_005b4b40
// -----------------------------------------------------------------------------
// Stable ID: aa_005b4b40
// Address:   0x005b4b40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b4b40 @ 0x005b4b40
// Stable ID: aa_005b4b40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005b4b40, FUN_0096ef70, FUN_0096f3e0, FUN_00989e00.
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

uint32_t /* width from decompiler */ FUN_005b4b40(uint32_t /* width from decompiler */ param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  void *local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a689b;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  local_10 = operator_new(4);

  local_4 = 0;

  if (local_10 == (void *)0x0) {

    uVar1 = 0;

  }

  else {

    uVar1 = FUN_0096ef70();

  }

  local_4 = 0xffffffff;

  FUN_00989e00(&local_10,param_1);

  FUN_0096f3e0(&local_10,0);

  ExceptionList = local_c;

  return uVar1;

}
