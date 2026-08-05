// =============================================================================
// FUN_00444190
// -----------------------------------------------------------------------------
// Stable ID: aa_00444190
// Address:   0x00444190  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00444190 @ 0x00444190
// Stable ID: aa_00444190
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004437d0, FUN_00444190.
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

uint32_t /* width from decompiler */ * __thiscall FUN_00444190(uint16_t *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009be8b1;

  local_10 = ExceptionList;

  ExceptionList = &local_10;

  puVar1 = operator_new(0x30);

  local_8 = 1;

  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    *puVar1 = param_2;

    puVar1[1] = param_3;

    *(uint16_t *)(puVar1 + 2) = *param_1;

    FUN_004437d0();

  }

  ExceptionList = local_10;

  return puVar1;

}
