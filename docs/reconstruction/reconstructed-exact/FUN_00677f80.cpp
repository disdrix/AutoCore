// =============================================================================
// FUN_00677f80
// -----------------------------------------------------------------------------
// Stable ID: aa_00677f80
// Address:   0x00677f80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00677f80 @ 0x00677f80
// Stable ID: aa_00677f80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_00679a80×2, FUN_00677f80.
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

void __fastcall FUN_00677f80(uint32_t /* width from decompiler */ *param_1)



{

  void *pvVar1;

  void *pvVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  pvVar2 = ExceptionList;

  puStack_8 = &LAB_009a9548;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_009e8618;

  pvVar1 = (void *)param_1[0xb];

  local_4 = 0;

  if (pvVar1 != (void *)0x0) {

    FUN_00679a80();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  param_1[0xb] = 0;

  pvVar1 = (void *)param_1[0xc];

  if (pvVar1 != (void *)0x0) {

    FUN_00679a80();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  param_1[0xc] = 0;

  *param_1 = &PTR_LAB_009e84f4;

  ExceptionList = pvVar2;

  return;

}
