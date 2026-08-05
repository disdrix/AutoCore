// =============================================================================
// FUN_0085e4a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0085e4a0
// Address:   0x0085e4a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0085e4a0 @ 0x0085e4a0
// Stable ID: aa_0085e4a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×5, return×4.
//  - Notable callees: FUN_0096efd0×3, FUN_007b5be0, FUN_0085e4a0.
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

void __fastcall FUN_0085e4a0(uint32_t /* width from decompiler */ *param_1)



{

  void *pvVar1;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint local_4;

  

  puStack_8 = &LAB_009b370f;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_00a65354;

  local_4 = 1;

  pvVar1 = (void *)param_1[0x143];

  if (pvVar1 != (void *)0x0) {

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  pvVar1 = (void *)param_1[0x144];

  param_1[0x143] = 0;

  if (pvVar1 != (void *)0x0) {

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  param_1[0x144] = 0;

  if ((param_1[0x123] != 0) &&

     ((DAT_00d1d8dc == (int *)0x0 || (param_1[0x123] == DAT_00d1d8dc[0x146])))) {

    DAT_00d1d8f4 = 1;

    DAT_00d1d8f5 = 0;

    if (DAT_00d1d8dc != (int *)0x0) {

      (**(code **)(*DAT_00d1d8dc + 4))(0);

    }

  }

  local_4 = local_4 & 0xffffff00;

  pvVar1 = (void *)param_1[300];

  if (pvVar1 != (void *)0x0) {

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  param_1[300] = 0;

  local_4 = 0xffffffff;

  FUN_007b5be0();

  ExceptionList = pvStack_c;

  return;

}
