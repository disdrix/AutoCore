// =============================================================================
// FUN_0060b250
// -----------------------------------------------------------------------------
// Stable ID: aa_0060b250
// Address:   0x0060b250  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0060b250 @ 0x0060b250
// Stable ID: aa_0060b250
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_005b2520, FUN_0060b250.
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

uint32_t /* width from decompiler */ * FUN_0060b250(void)



{

  float fVar1;

  uint32_t /* width from decompiler */ *puVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a82bb;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  puVar2 = operator_new(0x88);

  local_4 = 0;

  if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

    FUN_005b2520();

    fVar1 = g_flOne;

    *puVar2 = &PTR_LAB_009df5c4;

    puVar2[0x1e] = 0;

    puVar2[0x20] = 0xffffffff;

    puVar2[0x16] = fVar1;

    ExceptionList = local_c;

    return puVar2;

  }

  ExceptionList = local_c;

  return (uint32_t /* width from decompiler */ *)0x0;

}
