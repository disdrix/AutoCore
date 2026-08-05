// =============================================================================
// FUN_004ba600
// -----------------------------------------------------------------------------
// Stable ID: aa_004ba600
// Address:   0x004ba600  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004ba600 @ 0x004ba600
// Stable ID: aa_004ba600
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, do×1, while×1.
//  - Notable callees: FUN_004b99c0, FUN_004ba600.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_004ba600(void)



{

  uint *puVar1;

  int *piVar2;

  

  piVar2 = (int *)*DAT_00b03714;

  if (piVar2 != DAT_00b03714) {

    do {

      puVar1 = (uint *)piVar2[2];

      *puVar1 = *puVar1 & 0xfffffffe;

      if (*(char *)((int)puVar1 + 9) == '\0') {

        FUN_004b99c0();

                    /* WARNING: Subroutine does not return */

        operator_delete(puVar1);

      }

      piVar2 = (int *)*piVar2;

    } while (piVar2 != DAT_00b03714);

  }

  piVar2 = (int *)*DAT_00b03714;

  *DAT_00b03714 = (int)DAT_00b03714;

  DAT_00b03714[1] = (int)DAT_00b03714;

  _DAT_00b03718 = 0;

  if (piVar2 == DAT_00b03714) {

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(piVar2);

}
