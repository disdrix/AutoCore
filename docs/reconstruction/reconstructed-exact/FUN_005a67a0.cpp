// =============================================================================
// FUN_005a67a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005a67a0
// Address:   0x005a67a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a67a0 @ 0x005a67a0
// Stable ID: aa_005a67a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: return×4, if×3.
//  - Notable callees: FUN_005a6170, FUN_005a67a0.
//  - Return sites: 4.

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

void __fastcall FUN_005a67a0(uint32_t /* width from decompiler */ *param_1)



{

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a63de;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_009d8244;

  local_4 = 2;

  FUN_005a6170();

  if ((void *)param_1[0x55] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x55]);

  }

  param_1[0x55] = 0;

  param_1[0x56] = 0;

  param_1[0x57] = 0;

  if ((void *)param_1[9] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[9]);

  }

  param_1[9] = 0;

  param_1[10] = 0;

  param_1[0xb] = 0;

  if ((void *)param_1[5] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[5]);

  }

  param_1[5] = 0;

  param_1[6] = 0;

  param_1[7] = 0;

  ExceptionList = pvStack_c;

  return;

}
