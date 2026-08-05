// =============================================================================
// FUN_00988e90
// -----------------------------------------------------------------------------
// Stable ID: aa_00988e90
// Address:   0x00988e90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00988e90 @ 0x00988e90
// Stable ID: aa_00988e90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0044eb70, FUN_00985a30, FUN_00988e90.
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

void FUN_00988e90(void)



{

  int *piVar1;

  int iVar2;

  int unaff_ESI;

  

  if (*(int *)(unaff_ESI + 0x10) != 0) {

    if (DAT_00d1f648 != 0) {

      FUN_00985a30();

      if (*(int *)(unaff_ESI + 8) != 0 || *(int *)(unaff_ESI + 0xc) != 0) {

        FUN_0044eb70();

      }

    }

    iVar2 = DAT_00d1f614;

    if (DAT_00d1f614 != 0) {

      *(int *)(DAT_00d1f614 + 0x390) =

           *(int *)(DAT_00d1f614 + 0x390) - *(int *)(unaff_ESI + 0x14) * *(int *)(unaff_ESI + 0x1c);

      piVar1 = (int *)(iVar2 + 0x348);

      *piVar1 = *piVar1 - *(int *)(unaff_ESI + 0x1c);

      piVar1 = (int *)(iVar2 + 0x344);

      *piVar1 = *piVar1 + -1;

    }

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10) = 0;

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x18) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c) = 0;

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(unaff_ESI + 0x20));

}
