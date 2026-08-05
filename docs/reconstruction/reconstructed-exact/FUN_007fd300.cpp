// =============================================================================
// FUN_007fd300
// -----------------------------------------------------------------------------
// Stable ID: aa_007fd300
// Address:   0x007fd300  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fd300 @ 0x007fd300
// Stable ID: aa_007fd300
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_007fd300, FUN_0084e5a0.
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

void FUN_007fd300(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  int *piVar1;

  int in_EAX;

  int unaff_EDI;

  

  piVar1 = *(int **)(unaff_EDI + 0x30a4);

  if (piVar1 != (int *)0x0) {

    piVar1[0x142] = in_EAX;

    (**(code **)(*piVar1 + 0x444))();

    FUN_0084e5a0(param_1,param_2,param_3,param_4);

    *(uint8_t *)(unaff_EDI + 0x30b8) = 0;

    *(uint8_t *)(unaff_EDI + 0x30b9) = 1;

  }

  return;

}
