// =============================================================================
// FUN_00549120
// -----------------------------------------------------------------------------
// Stable ID: aa_00549120
// Address:   0x00549120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00549120 @ 0x00549120
// Stable ID: aa_00549120
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00549120, FUN_00618100.
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

uint32_t /* width from decompiler */ * FUN_00549120(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a43fb;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  puVar1 = operator_new(0x6d0);

  local_4 = 0;

  puVar2 = (uint32_t /* width from decompiler */ *)0x0;

  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    FUN_00618100();

    *puVar1 = &PTR_FUN_009d18bc;

    puVar2 = puVar1;

  }

  ExceptionList = local_c;

  return puVar2;

}
