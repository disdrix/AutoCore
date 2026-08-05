// =============================================================================
// FUN_009302b0
// -----------------------------------------------------------------------------
// Stable ID: aa_009302b0
// Address:   0x009302b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009302b0 @ 0x009302b0
// Stable ID: aa_009302b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00406710, FUN_004ba600, FUN_004cd630, FUN_00560020, FUN_00590120, FUN_00593d70, FUN_009302b0, FUN_00976390.
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

uint32_t /* width from decompiler */ FUN_009302b0(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *pvVar2;

  int unaff_EDI;

  

  if (*(int *)(unaff_EDI + 0xed4) != 0) {

    FUN_00560020(*(int *)(unaff_EDI + 0xed4));

    puVar1 = *(uint32_t /* width from decompiler */ **)(unaff_EDI + 0xed4);

    *(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1;

    if (*(short *)((int)puVar1 + 6) == 0) {

      (**(code **)*puVar1)(1);

    }

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xed4) = 0;

  }

  FUN_00406710(*(uint32_t /* width from decompiler */ *)(*(int *)(unaff_EDI + 0xedc) + 4));

  *(int *)(*(int *)(unaff_EDI + 0xedc) + 4) = *(int *)(unaff_EDI + 0xedc);

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xee0) = 0;

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xedc) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xedc);

  *(int *)(*(int *)(unaff_EDI + 0xedc) + 8) = *(int *)(unaff_EDI + 0xedc);

  FUN_004cd630();

  FUN_004ba600();

  FUN_00590120();

  FUN_00593d70();

  (**(code **)(**(int **)(unaff_EDI + 0xe04) + 4))();

  pvVar2 = *(void **)(unaff_EDI + 0xc80);

  if (pvVar2 != (void *)0x0) {

    FUN_00976390();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar2);

  }

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xc80) = 0;

  return 0;

}
