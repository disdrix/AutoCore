// =============================================================================
// FUN_00763400
// -----------------------------------------------------------------------------
// Stable ID: aa_00763400
// Address:   0x00763400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00763400 @ 0x00763400
// Stable ID: aa_00763400
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_00456780, FUN_00763400.
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

void FUN_00763400(void)



{

  int *piVar1;

  int unaff_EDI;

  

  piVar1 = *(int **)(unaff_EDI + 0xc0);

  if (piVar1 != *(int **)(unaff_EDI + 0xc4)) {

    do {

      if ((uint32_t /* width from decompiler */ *)*piVar1 != (uint32_t /* width from decompiler */ *)0x0) {

        (*(code *)**(uint32_t /* width from decompiler */ **)*piVar1)(1);

      }

      piVar1 = piVar1 + 1;

    } while (piVar1 != *(int **)(unaff_EDI + 0xc4));

  }

  FUN_00456780(0);

  if (*(int *)(unaff_EDI + 0x94) != 0) {

                    /* WARNING: Could not recover jumptable at 0x00763448. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(**(int **)(unaff_EDI + 0x94) + 0x2c))();

    return;

  }

  return;

}
