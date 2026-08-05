// =============================================================================
// FUN_00590120
// -----------------------------------------------------------------------------
// Stable ID: aa_00590120
// Address:   0x00590120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00590120 @ 0x00590120
// Stable ID: aa_00590120
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, while×1.
//  - Notable callees: FUN_004b6780, FUN_00590120.
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

void FUN_00590120(void)



{

  void *pvVar1;

  uint uVar2;

  

  uVar2 = 0;

  while( true ) {

    if (DAT_00b04e34 == (void *)0x0) {

      DAT_00b04e34 = (void *)0x0;

      DAT_00b04e38 = 0;

      DAT_00b04e3c = 0;

      return;

    }

    if ((uint)(DAT_00b04e38 - (int)DAT_00b04e34 >> 2) <= uVar2) break;

    pvVar1 = *(void **)((int)DAT_00b04e34 + uVar2 * 4);

    if (pvVar1 != (void *)0x0) {

      FUN_004b6780();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    uVar2 = uVar2 + 1;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(DAT_00b04e34);

}
