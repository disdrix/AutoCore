// =============================================================================
// FUN_0073f4a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0073f4a0
// Address:   0x0073f4a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073f4a0 @ 0x0073f4a0
// Stable ID: aa_0073f4a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, for×1.
//  - Notable callees: FUN_0073f400, FUN_0073f4a0.
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

void FUN_0073f4a0(void)



{

  int *piVar1;

  int *piVar2;

  int unaff_EDI;

  

  FUN_0073f400(unaff_EDI);

  piVar1 = *(int **)(unaff_EDI + 0x18);

  for (piVar2 = *(int **)(unaff_EDI + 0x14); piVar2 != piVar1; piVar2 = piVar2 + 1) {

    if ((uint32_t /* width from decompiler */ *)*piVar2 != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)*piVar2)(1);

    }

  }

  if (*(void **)(unaff_EDI + 0x14) == (void *)0x0) {

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x14) = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x18) = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x1c) = 0;

    if (*(void **)(unaff_EDI + 0x24) == (void *)0x0) {

      *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x24) = 0;

      *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x28) = 0;

      *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x2c) = 0;

      return;

    }

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(unaff_EDI + 0x24));

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(unaff_EDI + 0x14));

}
