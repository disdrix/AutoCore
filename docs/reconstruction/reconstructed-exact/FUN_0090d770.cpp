// =============================================================================
// FUN_0090d770
// -----------------------------------------------------------------------------
// Stable ID: aa_0090d770
// Address:   0x0090d770  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0090d770 @ 0x0090d770
// Stable ID: aa_0090d770
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, return×1.
//  - Notable callees: FUN_0090d770.
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

void FUN_0090d770(void)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  

  if (DAT_00d1a8e9 == '\0') {

    piVar2 = &DAT_00d09940;

    do {

      iVar3 = 0xc;

      do {

        iVar1 = *piVar2;

        if (iVar1 != 0) {

          (*(code *)**(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1))(1);

        }

        *piVar2 = 0;

        piVar2 = piVar2 + 1;

        iVar3 = iVar3 + -1;

      } while (iVar3 != 0);

    } while ((int)piVar2 < 0xd09971);

  }

  return;

}
