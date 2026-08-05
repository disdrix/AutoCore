// =============================================================================
// FUN_005a2ba0
// -----------------------------------------------------------------------------
// Stable ID: aa_005a2ba0
// Address:   0x005a2ba0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a2ba0 @ 0x005a2ba0
// Stable ID: aa_005a2ba0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_005a2ba0, FUN_00780820.
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

uint32_t /* width from decompiler */ * FUN_005a2ba0(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a62ab;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  puVar1 = operator_new(0x28);

  local_4 = 0;

  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    FUN_00780820(2,1);

    *puVar1 = &PTR_LAB_009d7cbc;

    puVar1[6] = &PTR_FUN_009d7bd4;

    puVar1[7] = &LAB_005a2100;

    puVar1[9] = 0;

    puVar1[5] = puVar1 + 6;

    ExceptionList = local_c;

    return puVar1;

  }

  ExceptionList = local_c;

  return (uint32_t /* width from decompiler */ *)0x0;

}
