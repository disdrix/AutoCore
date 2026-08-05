// =============================================================================
// FUN_004c1880
// -----------------------------------------------------------------------------
// Stable ID: aa_004c1880
// Address:   0x004c1880  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c1880 @ 0x004c1880
// Stable ID: aa_004c1880
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_0096f510×2, FUN_004c16f0, FUN_004c1880, FUN_007563c0.
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

void __fastcall FUN_004c1880(uint32_t /* width from decompiler */ *param_1)



{

  void *pvVar1;

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009a1ad0;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_009cb62c;

  DAT_00b03790 = 0;

  local_4 = 2;

  if ((uint32_t /* width from decompiler */ *)param_1[0x27] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x27])(1);

  }

  param_1[0x27] = 0;

  if ((void *)param_1[0x2d] != (void *)0x0) {

    operator_delete__((void *)param_1[0x2d]);

  }

  param_1[0x2d] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0x2b] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x2b])(1);

  }

  pvVar1 = (void *)param_1[0x31];

  param_1[0x2b] = 0;

  param_1[0x2c] = 0;

  if (pvVar1 != (void *)0x0) {

    FUN_004c16f0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  param_1[0x31] = 0;

  local_4._0_1_ = 1;

  FUN_0096f510();

  local_4 = (uint)local_4._1_3_ << 8;

  FUN_0096f510();

  local_4 = 0xffffffff;

  FUN_007563c0();

  ExceptionList = pvStack_c;

  return;

}
