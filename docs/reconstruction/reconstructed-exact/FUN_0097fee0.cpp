// =============================================================================
// FUN_0097fee0
// -----------------------------------------------------------------------------
// Stable ID: aa_0097fee0
// Address:   0x0097fee0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0097fee0 @ 0x0097fee0
// Stable ID: aa_0097fee0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: return×4, if×3.
//  - Notable callees: FUN_0096efd0×3, FUN_007b5be0, FUN_0097fee0.
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

void __fastcall FUN_0097fee0(uint32_t /* width from decompiler */ *param_1)



{

  void *pvVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b4aa4;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_00a61e44;

  local_4 = 0;

  pvVar1 = (void *)param_1[0x12d];

  if (pvVar1 != (void *)0x0) {

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  pvVar1 = (void *)param_1[0x12e];

  param_1[0x12d] = 0;

  if (pvVar1 != (void *)0x0) {

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  pvVar1 = (void *)param_1[0x12f];

  param_1[0x12e] = 0;

  if (pvVar1 != (void *)0x0) {

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  param_1[0x12f] = 0;

  *param_1 = &PTR_FUN_00a61a1c;

  local_4 = 0xffffffff;

  FUN_007b5be0();

  ExceptionList = local_c;

  return;

}
