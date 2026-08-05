// =============================================================================
// FUN_007fc9b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007fc9b0
// Address:   0x007fc9b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fc9b0 @ 0x007fc9b0
// Stable ID: aa_007fc9b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_007fb990, FUN_007fc970, FUN_007fc9b0.
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

void FUN_007fc9b0(void)



{

  char cVar1;

  int in_EAX;

  int *unaff_EDI;

  

  if ((*(int *)(in_EAX + 0xf40) != 0) && (unaff_EDI != (int *)0x0)) {

    cVar1 = (**(code **)(*unaff_EDI + 0x3d8))();

    if (cVar1 != '\0') {

      FUN_007fc970();

      *(uint8_t *)(in_EAX + 0x30b4) = 1;

      *(uint8_t *)(in_EAX + 0x30b5) = 0;

      if (*(int **)(in_EAX + 0x309c) != (int *)0x0) {

        (**(code **)(**(int **)(in_EAX + 0x309c) + 4))(0);

      }

      FUN_007fb990();

      (**(code **)(*unaff_EDI + 0xfc))(0,0x3f000000);

    }

  }

  return;

}
