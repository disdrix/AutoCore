// =============================================================================
// FUN_004168c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004168c0
// Address:   0x004168c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004168c0 @ 0x004168c0
// Stable ID: aa_004168c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004168c0.
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

uint32_t /* width from decompiler */ * FUN_004168c0(uint32_t /* width from decompiler */ param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ab4eb;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  puVar1 = operator_new(0x14);

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *puVar1 = &PTR_FUN_00a733ec;

    puVar1[1] = param_1;

    puVar1[3] = 0;

    puVar1[2] = 0;

    puVar1[4] = 0;

  }

  ExceptionList = local_c;

  return puVar1;

}
