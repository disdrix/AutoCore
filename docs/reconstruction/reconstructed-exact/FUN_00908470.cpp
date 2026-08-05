// =============================================================================
// FUN_00908470
// -----------------------------------------------------------------------------
// Stable ID: aa_00908470
// Address:   0x00908470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00908470 @ 0x00908470
// Stable ID: aa_00908470
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00908350×2, FUN_0085d970, FUN_00908470.
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

void FUN_00908470(void)



{

  int iVar1;

  int unaff_ESI;

  int unaff_EDI;

  uint8_t local_104 [260];

  

  if (*(int *)(unaff_ESI + 0x688) != 0) {

    if (unaff_EDI == 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x688) + 0x58))();

      (**(code **)(**(int **)(unaff_ESI + 0x688) + 0x15c))();

      FUN_00908350();

    }

    else {

      FUN_0085d970();

      iVar1 = **(int **)(unaff_ESI + 0x688);

      (**(code **)(**(int **)(unaff_ESI + 0x688) + 0x2c8))();

      (**(code **)(iVar1 + 0x50))(local_104);

      (**(code **)(**(int **)(unaff_ESI + 0x688) + 0x15c))(0,&stack0xfffffeec);

      FUN_00908350();

    }

    (**(code **)(**(int **)(unaff_ESI + 0x688) + 0x34c))();

  }

  return;

}
