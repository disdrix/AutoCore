// =============================================================================
// FUN_00690190
// -----------------------------------------------------------------------------
// Stable ID: aa_00690190
// Address:   0x00690190  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00690190 @ 0x00690190
// Stable ID: aa_00690190
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00690190, FUN_006a1100.
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

void __thiscall FUN_00690190(int param_1,void *param_2)



{

  void *pvVar1;

  

  pvVar1 = *(void **)(param_1 + 0x30);

  if (pvVar1 != param_2) {

    if (pvVar1 != (void *)0x0) {

      FUN_006a1100();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    *(void **)(param_1 + 0x30) = param_2;

  }

  return;

}
