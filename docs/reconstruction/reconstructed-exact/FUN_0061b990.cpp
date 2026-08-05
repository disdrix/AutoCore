// =============================================================================
// FUN_0061b990
// -----------------------------------------------------------------------------
// Stable ID: aa_0061b990
// Address:   0x0061b990  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0061b990 @ 0x0061b990
// Stable ID: aa_0061b990
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00578830, FUN_0061b990.
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

uint32_t /* width from decompiler */ * FUN_0061b990(void)



{

  float fVar1;

  uint32_t /* width from decompiler */ *puVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a86eb;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  puVar2 = operator_new(0x6d0);

  local_4 = 0;

  if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

    FUN_00578830();

    fVar1 = g_flOne;

    *puVar2 = &PTR_FUN_009e1f2c;

    puVar2[0x1b1] = fVar1;

    puVar2[0x1b2] = 0;

    ExceptionList = local_c;

    return puVar2;

  }

  ExceptionList = local_c;

  return (uint32_t /* width from decompiler */ *)0x0;

}
