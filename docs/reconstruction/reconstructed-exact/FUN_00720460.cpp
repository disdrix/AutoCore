// =============================================================================
// FUN_00720460
// -----------------------------------------------------------------------------
// Stable ID: aa_00720460
// Address:   0x00720460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00720460 @ 0x00720460
// Stable ID: aa_00720460
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, while×1, return×1.
//  - Notable callees: FUN_00720460, _stricmp.
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

uint32_t /* width from decompiler */ FUN_00720460(void)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  int unaff_EDI;

  

  if (*(char *)(unaff_EDI + 0x10) != '\0') {

    iVar2 = -1;

    *(uint8_t *)(unaff_EDI + 0x12) = 0;

    iVar4 = 0;

    piVar3 = (int *)(unaff_EDI + 0x80);

    do {

      if ((*piVar3 != 0) &&

         (iVar1 = _stricmp((char *)(unaff_EDI + 0x90),(char *)(*piVar3 + 0x48)), iVar1 == 0)) {

        iVar2 = iVar4;

      }

      iVar4 = iVar4 + 1;

      piVar3 = piVar3 + 1;

    } while (iVar4 < 2);

    if (iVar2 != -1) {

      if (*(char *)(unaff_EDI + 0x135) != '\0') {

        *(uint8_t *)(*(int *)(unaff_EDI + 0x80 + iVar2 * 4) + 0x36) = 0;

      }

      if (*(char *)(unaff_EDI + 0x136) != '\0') {

        *(uint8_t *)(unaff_EDI + 0x17) = 1;

      }

    }

  }

  return 0;

}
