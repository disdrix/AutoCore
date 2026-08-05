// =============================================================================
// FUN_007a2610
// -----------------------------------------------------------------------------
// Stable ID: aa_007a2610
// Address:   0x007a2610  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a2610 @ 0x007a2610
// Stable ID: aa_007a2610
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00415e90, FUN_0079e3e0, FUN_007a2610.
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

void __fastcall FUN_007a2610(uint32_t /* width from decompiler */ *param_1)



{

  void *pvVar1;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b005b;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_00a97170;

  local_4 = 2;

  FUN_0079e3e0();

  pvVar1 = (void *)param_1[0xb7];

  if (pvVar1 != (void *)0x0) {

    if (*(void **)((int)pvVar1 + 0x6c) != (void *)0x0) {

      operator_delete__(*(void **)((int)pvVar1 + 0x6c));

    }

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x6c) = 0;

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  param_1[0xb7] = 0;

  FUN_00415e90();

                    /* WARNING: Subroutine does not return */

  operator_delete((void *)param_1[0xb5]);

}
