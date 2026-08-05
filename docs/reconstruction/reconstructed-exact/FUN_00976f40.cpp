// =============================================================================
// FUN_00976f40
// -----------------------------------------------------------------------------
// Stable ID: aa_00976f40
// Address:   0x00976f40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00976f40 @ 0x00976f40
// Stable ID: aa_00976f40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: return×7, if×6.
//  - Notable callees: FUN_0096efd0×6, FUN_00976f40.
//  - Return sites: 7.

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

void FUN_00976f40(void)



{

  void *pvVar1;

  int unaff_ESI;

  

  pvVar1 = *(void **)(unaff_ESI + 4);

  if (pvVar1 != (void *)0x0) {

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  pvVar1 = *(void **)(unaff_ESI + 8);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 4) = 0;

  if (pvVar1 != (void *)0x0) {

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  pvVar1 = *(void **)(unaff_ESI + 0xc);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = 0;

  if (pvVar1 != (void *)0x0) {

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  pvVar1 = *(void **)(unaff_ESI + 0x10);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc) = 0;

  if (pvVar1 != (void *)0x0) {

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  pvVar1 = *(void **)(unaff_ESI + 0x14);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10) = 0;

  if (pvVar1 != (void *)0x0) {

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  pvVar1 = *(void **)(unaff_ESI + 0x18);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14) = 0;

  if (pvVar1 != (void *)0x0) {

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x18) = 0;

  return;

}
