// =============================================================================
// FUN_007599b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007599b0
// Address:   0x007599b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007599b0 @ 0x007599b0
// Stable ID: aa_007599b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0043f410, FUN_0043f4b0, FUN_00734550, FUN_0074f360, FUN_00756b40, FUN_00758c80, FUN_00759090, FUN_007599b0.
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

uint32_t /* width from decompiler */ FUN_007599b0(int *param_1)



{

  if (param_1[0xd] == 0) {

    FUN_00758c80();

    FUN_00759090();

  }

  (**(code **)(*param_1 + 0x1c))();

  FUN_00756b40();

  FUN_0096f800(2);

  FUN_0043f410();

  if (param_1[0xd] != 0) {

    FUN_0043f4b0();

  }

  if (*(int *)(param_1[0xd] + 0x34) == 0) {

    FUN_00967150(param_1[0xd] + 0x24);

  }

  FUN_00734550();

  FUN_0075e8e0(4,param_1[0xb],2);

  FUN_0074f360();

  return 0;

}
