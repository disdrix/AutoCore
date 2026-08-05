// =============================================================================
// FUN_00808ad0
// -----------------------------------------------------------------------------
// Stable ID: aa_00808ad0
// Address:   0x00808ad0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00808ad0 @ 0x00808ad0
// Stable ID: aa_00808ad0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_004d2a20, FUN_005a5190, FUN_00808ad0.
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

void FUN_00808ad0(void)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  int iVar4;

  int unaff_ESI;

  

  iVar2 = FUN_004d2a20(*(uint8_t *)(unaff_ESI + 4));

  if (iVar2 != 0) {

    FUN_005a5190(*(float *)(unaff_ESI + 8) - *(float *)(unaff_ESI + 0xc),

                 *(float *)(unaff_ESI + 8) <= 0.0 && *(float *)(unaff_ESI + 8) != 0.0,0,0,1,0);

    pcVar3 = (char *)(unaff_ESI + 0x10);

    iVar4 = (iVar2 + 0x1d) - (int)pcVar3;

    do {

      cVar1 = *pcVar3;

      pcVar3[iVar4] = cVar1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    *(uint8_t *)(iVar2 + 0x1b) = *(uint8_t *)(unaff_ESI + 5);

  }

  return;

}
