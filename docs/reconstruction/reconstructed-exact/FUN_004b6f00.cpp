// =============================================================================
// FUN_004b6f00
// -----------------------------------------------------------------------------
// Stable ID: aa_004b6f00
// Address:   0x004b6f00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004b6f00 @ 0x004b6f00
// Stable ID: aa_004b6f00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, return×1.
//  - Notable callees: FUN_004b6f00, FUN_005b8600, FUN_005bb670.
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

void __thiscall FUN_004b6f00(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  

  piVar1 = (int *)**(int **)(param_1 + 0x1e0);

  if (piVar1 != *(int **)(param_1 + 0x1e0)) {

    do {

      FUN_005bb670(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 0x2c));

      piVar1 = (int *)*piVar1;

    } while (piVar1 != (int *)*(int *)(param_1 + 0x1e0));

  }

  piVar1 = (int *)**(int **)(param_1 + 0x210);

  if (piVar1 != *(int **)(param_1 + 0x210)) {

    do {

      FUN_005b8600();

      piVar1 = (int *)*piVar1;

    } while (piVar1 != (int *)*(int *)(param_1 + 0x210));

  }

  return;

}
