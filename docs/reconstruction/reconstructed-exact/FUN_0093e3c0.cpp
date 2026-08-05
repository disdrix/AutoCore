// =============================================================================
// FUN_0093e3c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0093e3c0
// Address:   0x0093e3c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0093e3c0 @ 0x0093e3c0
// Stable ID: aa_0093e3c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, do×1, while×1.
//  - Notable callees: FUN_00800e60×2, FUN_007fef20, FUN_0093e3c0.
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

void FUN_0093e3c0(void)



{

  char cVar1;

  int iVar2;

  int unaff_EDI;

  

  iVar2 = 0;

  do {

    if (*(char *)(unaff_EDI + 0x22 + iVar2) != '\0') {

      FUN_007fef20(iVar2,1,0);

    }

    iVar2 = iVar2 + 1;

  } while (iVar2 < 0x3a);

  if (*(int *)(unaff_EDI + 0x1044) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_EDI + 0x1044) + 0x3d8))();

    if (cVar1 != '\0') {

      FUN_00800e60();

    }

  }

  if (*(int *)(unaff_EDI + 0x1164) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_EDI + 0x1164) + 0x3d8))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(unaff_EDI + 0x1164) + 0xfc))(1,0x3f000000);

      if (*(int *)(*(int *)(unaff_EDI + 0x1164) + 0x52c) == 0) {

        FUN_00800e60();

        return;

      }

    }

  }

  return;

}
