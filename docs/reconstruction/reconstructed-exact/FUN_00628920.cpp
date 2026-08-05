// =============================================================================
// FUN_00628920
// -----------------------------------------------------------------------------
// Stable ID: aa_00628920
// Address:   0x00628920  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00628920 @ 0x00628920
// Stable ID: aa_00628920
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×7, do×2, while×2, return×1.
//  - Notable callees: FUN_00628920.
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

void FUN_00628920(void)



{

  int *piVar1;

  int *in_EAX;

  float *pfVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  float fVar6;

  

  piVar1 = (int *)*in_EAX;

  iVar4 = piVar1[1];

  iVar5 = 0;

  fVar6 = DAT_009e3300;

  if (3 < iVar4) {

    pfVar2 = (float *)(*piVar1 + 0x3c);

    iVar3 = (iVar4 - 4U >> 2) + 1;

    iVar5 = iVar3 * 4;

    do {

      if (pfVar2[-0xc] <= fVar6 && fVar6 != pfVar2[-0xc]) {

        fVar6 = pfVar2[-0xc];

      }

      if (*pfVar2 <= fVar6 && fVar6 != *pfVar2) {

        fVar6 = *pfVar2;

      }

      if (pfVar2[0xc] <= fVar6 && fVar6 != pfVar2[0xc]) {

        fVar6 = pfVar2[0xc];

      }

      if (pfVar2[0x18] <= fVar6 && fVar6 != pfVar2[0x18]) {

        fVar6 = pfVar2[0x18];

      }

      pfVar2 = pfVar2 + 0x30;

      iVar3 = iVar3 + -1;

    } while (iVar3 != 0);

  }

  if (iVar5 < iVar4) {

    pfVar2 = (float *)(iVar5 * 0x30 + 0xc + *piVar1);

    iVar4 = iVar4 - iVar5;

    do {

      if (*pfVar2 <= fVar6 && fVar6 != *pfVar2) {

        fVar6 = *pfVar2;

      }

      pfVar2 = pfVar2 + 0xc;

      iVar4 = iVar4 + -1;

    } while (iVar4 != 0);

  }

  return;

}
