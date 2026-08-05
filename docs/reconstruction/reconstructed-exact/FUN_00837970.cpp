// =============================================================================
// FUN_00837970
// -----------------------------------------------------------------------------
// Stable ID: aa_00837970
// Address:   0x00837970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00837970 @ 0x00837970
// Stable ID: aa_00837970
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: return×5, if×4.
//  - Notable callees: FUN_0096efd0×4, FUN_007b5be0, FUN_00837970.
//  - Return sites: 5.

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

void __fastcall FUN_00837970(uint32_t /* width from decompiler */ *param_1)



{

  void *pvVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b347d;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_00a6e67c;

  local_4 = 0;

  pvVar1 = (void *)param_1[0x122];

  if (pvVar1 != (void *)0x0) {

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  pvVar1 = (void *)param_1[0x123];

  param_1[0x122] = 0;

  if (pvVar1 != (void *)0x0) {

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  pvVar1 = (void *)param_1[0x124];

  param_1[0x123] = 0;

  if (pvVar1 != (void *)0x0) {

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  pvVar1 = (void *)param_1[0x125];

  param_1[0x124] = 0;

  if (pvVar1 != (void *)0x0) {

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  param_1[0x125] = 0;

  local_4 = 0xffffffff;

  FUN_007b5be0();

  ExceptionList = local_c;

  return;

}
