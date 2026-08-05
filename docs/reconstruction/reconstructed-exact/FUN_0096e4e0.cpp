// =============================================================================
// FUN_0096e4e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0096e4e0
// Address:   0x0096e4e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096e4e0 @ 0x0096e4e0
// Stable ID: aa_0096e4e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_0096bab0, FUN_0096e4e0.
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

void FUN_0096e4e0(void)



{

  uint32_t /* width from decompiler */ in_EAX;

  int *piVar1;

  int unaff_EDI;

  

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x2c) = in_EAX;

  piVar1 = (int *)**(int **)(unaff_EDI + 8);

  if (piVar1 != *(int **)(unaff_EDI + 8)) {

    do {

      if (*(int *)(piVar1[2] + 0x30) == 1) {

        FUN_0096bab0(piVar1[2]);

      }

      piVar1 = (int *)*piVar1;

    } while (piVar1 != (int *)*(int *)(unaff_EDI + 8));

  }

  (**(code **)(*(int *)*DAT_00d1f044 + 0x14))((int *)*DAT_00d1f044);

  return;

}
