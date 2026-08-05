// =============================================================================
// FUN_00963ee0
// -----------------------------------------------------------------------------
// Stable ID: aa_00963ee0
// Address:   0x00963ee0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00963ee0 @ 0x00963ee0
// Stable ID: aa_00963ee0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CONCAT31, FUN_00448ed0, FUN_00963890, FUN_00963ee0.
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

void __fastcall FUN_00963ee0(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009af86c;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_00aa5a80;

  local_4 = 2;

  FUN_00963890(param_1);

  local_4 = CONCAT31(local_4._1_3_,1);

  FUN_00448ed0();

  if ((void *)param_1[3] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[3]);

  }

  param_1[3] = 0;

  param_1[4] = 0;

  param_1[5] = 0;

  *param_1 = &PTR_LAB_00a9a9bc;

  ExceptionList = local_c;

  return;

}
