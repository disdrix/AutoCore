// =============================================================================
// FUN_004b99c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004b99c0
// Address:   0x004b99c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004b99c0 @ 0x004b99c0
// Stable ID: aa_004b99c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: CONCAT31, FUN_004b85d0, FUN_004b99c0, FUN_004bacf0, FUN_005875c0.
//  - Return sites: 3.

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

void __fastcall FUN_004b99c0(uint *param_1)



{

  uint *local_14;

  uint *local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a15f7;

  pvStack_c = ExceptionList;

  local_4 = 8;

  local_10 = param_1;

  if ((void *)param_1[0xf] != (void *)0x0) {

    ExceptionList = &pvStack_c;

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0xf]);

  }

  ExceptionList = &pvStack_c;

  param_1[0xf] = 0;

  if ((void *)param_1[0x18] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x18]);

  }

  param_1[0x18] = 0;

  FUN_004b85d0();

  if ((*param_1 & 1) != 0) {

    local_14 = param_1;

    FUN_005875c0(&local_14);

    *param_1 = *param_1 & 0xfffffffe;

  }

  local_4 = CONCAT31(local_4._1_3_,7);

  FUN_004bacf0(&local_14,*(uint32_t /* width from decompiler */ *)param_1[0x8a],(uint32_t /* width from decompiler */ *)param_1[0x8a]);

                    /* WARNING: Subroutine does not return */

  operator_delete((void *)param_1[0x8a]);

}
