// =============================================================================
// FUN_004cd630
// -----------------------------------------------------------------------------
// Stable ID: aa_004cd630
// Address:   0x004cd630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004cd630 @ 0x004cd630
// Stable ID: aa_004cd630
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_004cd630.
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

void __fastcall FUN_004cd630(int param_1)



{

  int *piVar1;

  

  piVar1 = *(int **)(param_1 + 0x78);

  if (piVar1 != (int *)0x0) {

    if (*(int *)(param_1 + 0xe4ec) != 0) {

      (**(code **)(*piVar1 + 0x18))(1);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = 0;

      return;

    }

    (**(code **)*piVar1)(1);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = 0;

  }

  return;

}
