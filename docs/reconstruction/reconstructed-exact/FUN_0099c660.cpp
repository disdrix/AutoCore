// =============================================================================
// FUN_0099c660
// -----------------------------------------------------------------------------
// Stable ID: aa_0099c660
// Address:   0x0099c660  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0099c660 @ 0x0099c660
// Stable ID: aa_0099c660
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_004b6e00, FUN_004b99c0, FUN_00720d40, FUN_009423b0, FUN_00976390, FUN_0099c660.
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

void __fastcall FUN_0099c660(uint32_t /* width from decompiler */ *param_1)



{

  void *pvVar1;

  int iVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009bb8b5;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_00a766e8;

  local_4 = 0;

  iVar2 = FUN_00720d40();

  *(uint8_t *)(iVar2 + 0x19) = 1;

  if (param_1[6] != 0) {

    FUN_009423b0(&DAT_00d1a840,*(uint8_t *)(param_1 + 3),0);

    pvVar1 = (void *)param_1[6];

    if (pvVar1 != (void *)0x0) {

      FUN_00976390();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    param_1[6] = 0;

  }

  if (param_1[2] != 0) {

    FUN_004b6e00(1);

  }

  pvVar1 = (void *)param_1[2];

  if (pvVar1 != (void *)0x0) {

    FUN_004b99c0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  param_1[2] = 0;

  *param_1 = &PTR_LAB_00a766f8;

  ExceptionList = local_c;

  return;

}
