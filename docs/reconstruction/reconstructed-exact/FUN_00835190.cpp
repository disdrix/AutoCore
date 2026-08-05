// =============================================================================
// FUN_00835190
// -----------------------------------------------------------------------------
// Stable ID: aa_00835190
// Address:   0x00835190  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00835190 @ 0x00835190
// Stable ID: aa_00835190
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×8, goto×1, do×1, while×1, return×1.
//  - Notable callees: FUN_004c4e20×2, FUN_008350a0, FUN_00835190.
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

int FUN_00835190(void)



{

  int iVar1;

  int iVar2;

  int extraout_ECX;

  int iVar3;

  uint uVar4;

  int *unaff_EDI;

  float10 fVar5;

  

  uVar4 = unaff_EDI[0x2d];

  iVar3 = 0;

  if ((uVar4 & 0x1000) == 0) {

    iVar1 = (**(code **)(*unaff_EDI + 0x1d8))();

    if (iVar1 != 0) {

      (**(code **)(*unaff_EDI + 0x1d8))();

      fVar5 = (float10)FUN_004c4e20();

      if (fVar5 < (float10)DAT_00aaa6b4) {

        uVar4 = uVar4 | 0x1000;

        goto LAB_00835210;

      }

    }

  }

  if ((uVar4 & 0x4000) == 0) {

    iVar1 = (**(code **)(*unaff_EDI + 0x1d8))();

    if (iVar1 != 0) {

      (**(code **)(*unaff_EDI + 0x1d8))();

      fVar5 = (float10)FUN_004c4e20();

      if ((float10)DAT_00aaa664 < fVar5) {

        uVar4 = uVar4 | 0x4000;

      }

    }

  }

LAB_00835210:

  iVar1 = 0;

  do {

    if ((uVar4 & 1 << ((byte)iVar1 & 0x1f)) != 0) {

      iVar2 = FUN_008350a0();

      iVar1 = extraout_ECX;

      if (-1 < iVar2) {

        iVar3 = iVar3 + 1;

      }

    }

    iVar1 = iVar1 + 1;

  } while (iVar1 < 0x20);

  return iVar3;

}
