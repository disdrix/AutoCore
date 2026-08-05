// =============================================================================
// FUN_00809e30
// -----------------------------------------------------------------------------
// Stable ID: aa_00809e30
// Address:   0x00809e30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00809e30 @ 0x00809e30
// Stable ID: aa_00809e30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00531960, FUN_00809e30, FUN_008a05a0.
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

void FUN_00809e30(void)



{

  char cVar1;

  int in_EAX;

  int unaff_ESI;

  

  FUN_00531960(*(uint16_t *)(in_EAX + 4));

  if (*(int *)(unaff_ESI + 0x10b0) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x10b0) + 0x3d8))();

    if (cVar1 != '\0') {

      FUN_008a05a0();

    }

  }

  cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x1030) + 0xd0))();

  if (cVar1 != '\0') {

                    /* WARNING: Could not recover jumptable at 0x00809e82. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(**(int **)(unaff_ESI + 0x1030) + 0x448))();

    return;

  }

  return;

}
