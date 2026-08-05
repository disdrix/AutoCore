// =============================================================================
// FUN_0088b980
// -----------------------------------------------------------------------------
// Stable ID: aa_0088b980
// Address:   0x0088b980  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0088b980 @ 0x0088b980
// Stable ID: aa_0088b980
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_00412060, FUN_0046f100, FUN_0088ad60, FUN_0088b980.
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

void FUN_0088b980(void)



{

  bool bVar1;

  int unaff_ESI;

  int unaff_EDI;

  int local_8;

  uint8_t local_4 [4];

  

  local_8 = **(int **)(unaff_ESI + 0x524);

  bVar1 = false;

  if ((int *)local_8 != *(int **)(unaff_ESI + 0x524)) {

    do {

      if (*(int *)(local_8 + 0x10) == unaff_EDI) {

        bVar1 = true;

        local_8 = FUN_00412060(unaff_ESI + 0x520,local_4,local_8);

        local_8 = *(int *)local_8;

      }

      else {

        FUN_0046f100();

      }

    } while (local_8 != *(int *)(unaff_ESI + 0x524));

    if (bVar1) {

      FUN_0088ad60(unaff_ESI,1,0);

    }

  }

  return;

}
