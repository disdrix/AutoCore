// =============================================================================
// FUN_006a1ec0
// -----------------------------------------------------------------------------
// Stable ID: aa_006a1ec0
// Address:   0x006a1ec0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006a1ec0 @ 0x006a1ec0
// Stable ID: aa_006a1ec0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: return×10, if×9.
//  - Notable callees: FUN_006a1100×9, FUN_006a1ec0.
//  - Return sites: 10.

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

void __fastcall FUN_006a1ec0(int param_1)



{

  void *pvVar1;

  

  pvVar1 = *(void **)(param_1 + 0x58);

  if (pvVar1 != (void *)0x0) {

    FUN_006a1100();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  pvVar1 = *(void **)(param_1 + 0x5c);

  if (pvVar1 != (void *)0x0) {

    FUN_006a1100();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  pvVar1 = *(void **)(param_1 + 0x54);

  if (pvVar1 != (void *)0x0) {

    FUN_006a1100();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  pvVar1 = *(void **)(param_1 + 0x50);

  if (pvVar1 != (void *)0x0) {

    FUN_006a1100();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  pvVar1 = *(void **)(param_1 + 0x6c);

  if (pvVar1 != (void *)0x0) {

    FUN_006a1100();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  pvVar1 = *(void **)(param_1 + 100);

  if (pvVar1 != (void *)0x0) {

    FUN_006a1100();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  pvVar1 = *(void **)(param_1 + 0x68);

  if (pvVar1 != (void *)0x0) {

    FUN_006a1100();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  pvVar1 = *(void **)(param_1 + 0x60);

  if (pvVar1 != (void *)0x0) {

    FUN_006a1100();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  pvVar1 = *(void **)(param_1 + 0x70);

  if (pvVar1 != (void *)0x0) {

    FUN_006a1100();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x58) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x50) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 100) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x68) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x60) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x70) = 0;

  return;

}
