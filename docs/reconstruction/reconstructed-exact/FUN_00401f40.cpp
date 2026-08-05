// =============================================================================
// FUN_00401f40
// -----------------------------------------------------------------------------
// Stable ID: aa_00401f40
// Address:   0x00401f40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00401f40 @ 0x00401f40
// Stable ID: aa_00401f40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00401f40, FUN_00401fe0.
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

void * FUN_00401f40(uint32_t /* width from decompiler */ param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ in_stack_00000014;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bc811;

  local_10 = ExceptionList;

  ExceptionList = &local_10;

  pvVar1 = operator_new(0x30);

  local_8 = 1;

  if (pvVar1 != (void *)0x0) {

    FUN_00401fe0(pvVar1,param_1,in_stack_00000014);

  }

  ExceptionList = local_10;

  return pvVar1;

}
