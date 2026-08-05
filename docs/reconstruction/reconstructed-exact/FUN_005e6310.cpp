// =============================================================================
// FUN_005e6310
// -----------------------------------------------------------------------------
// Stable ID: aa_005e6310
// Address:   0x005e6310  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005e6310 @ 0x005e6310
// Stable ID: aa_005e6310
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: return×4, if×3.
//  - Notable callees: FUN_005a67a0, FUN_005e5590, FUN_005e6310.
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

void __fastcall FUN_005e6310(uint32_t /* width from decompiler */ *param_1)



{

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a7627;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_009dca4c;

  local_4 = 3;

  FUN_005e5590();

  if ((void *)param_1[0x66] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x66]);

  }

  param_1[0x66] = 0;

  param_1[0x67] = 0;

  param_1[0x68] = 0;

  if ((void *)param_1[0x5e] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x5e]);

  }

  param_1[0x5e] = 0;

  param_1[0x5f] = 0;

  param_1[0x60] = 0;

  if ((void *)param_1[0x5a] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x5a]);

  }

  param_1[0x5a] = 0;

  param_1[0x5b] = 0;

  param_1[0x5c] = 0;

  local_4 = 0xffffffff;

  FUN_005a67a0();

  ExceptionList = pvStack_c;

  return;

}
