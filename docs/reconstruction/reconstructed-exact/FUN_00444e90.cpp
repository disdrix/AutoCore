// =============================================================================
// FUN_00444e90
// -----------------------------------------------------------------------------
// Stable ID: aa_00444e90
// Address:   0x00444e90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00444e90 @ 0x00444e90
// Stable ID: aa_00444e90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00444e90.
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

uint32_t /* width from decompiler */ * FUN_00444e90(void)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009be063;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  puVar2 = operator_new(0x20);

  if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar2[1] = 0;

    uVar1 = DAT_00aaa688;

    *puVar2 = &PTR_FUN_00a9dcf4;

    puVar2[3] = 0;

    puVar2[4] = 0;

    puVar2[5] = 0;

    puVar2[6] = 0;

    puVar2[7] = uVar1;

    ExceptionList = local_c;

    return puVar2;

  }

  ExceptionList = local_c;

  return (uint32_t /* width from decompiler */ *)0x0;

}
