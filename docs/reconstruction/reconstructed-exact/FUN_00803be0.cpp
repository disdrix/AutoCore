// =============================================================================
// FUN_00803be0
// -----------------------------------------------------------------------------
// Stable ID: aa_00803be0
// Address:   0x00803be0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00803be0 @ 0x00803be0
// Stable ID: aa_00803be0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00415e90, FUN_00803be0.
//  - Return sites: 1.

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

void FUN_00803be0(void)



{

  int *piVar1;

  int unaff_EDI;

  

  piVar1 = (int *)**(int **)(unaff_EDI + 0x38);

  if (piVar1 != *(int **)(unaff_EDI + 0x38)) {

    do {

      if ((uint32_t /* width from decompiler */ *)piVar1[2] != (uint32_t /* width from decompiler */ *)0x0) {

        (*(code *)**(uint32_t /* width from decompiler */ **)piVar1[2])(1);

      }

      piVar1 = (int *)*piVar1;

    } while (piVar1 != (int *)*(int *)(unaff_EDI + 0x38));

  }

  FUN_00415e90();

  return;

}
