// =============================================================================
// FUN_007afe80
// -----------------------------------------------------------------------------
// Stable ID: aa_007afe80
// Address:   0x007afe80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007afe80 @ 0x007afe80
// Stable ID: aa_007afe80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_004246a0, FUN_007afe80.
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

void FUN_007afe80(int param_1)



{

  int iVar1;

  int iVar2;

  

  if (param_1 != 0) {

    if (*(int *)(param_1 + 0xc0) == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = *(int *)(param_1 + 0xc4) - *(int *)(param_1 + 0xc0) >> 2;

    }

    iVar2 = 0;

    if (0 < iVar1) {

      do {

        if (*(int *)(*(int *)(param_1 + 0xc0) + iVar2 * 4) != 0) {

          FUN_004246a0();

        }

        iVar2 = iVar2 + 1;

      } while (iVar2 < iVar1);

    }

  }

  return;

}
