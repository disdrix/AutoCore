// =============================================================================
// FUN_00700730
// -----------------------------------------------------------------------------
// Stable ID: aa_00700730
// Address:   0x00700730  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00700730 @ 0x00700730
// Stable ID: aa_00700730
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×7, do×2, while×2, return×1.
//  - Notable callees: FUN_00700730.
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

int __fastcall FUN_00700730(int param_1)



{

  float *pfVar1;

  float fVar2;

  uint uVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  

  iVar5 = *(int *)(param_1 + 0x1b0);

  fVar2 = *(float *)(iVar5 + 0x10);

  iVar4 = *(int *)(param_1 + 0x1b4) + -2;

  uVar3 = *(int *)(param_1 + 0x1b4) - 1;

  iVar6 = iVar5;

  if (3 < (int)uVar3) {

    uVar3 = uVar3 >> 2;

    iVar4 = iVar4 + uVar3 * -4;

    do {

      if (*(float *)(iVar5 + 0x60) < fVar2) {

        iVar6 = iVar5 + 0x50;

        fVar2 = *(float *)(iVar5 + 0x60);

      }

      if (*(float *)(iVar5 + 0xb0) < fVar2) {

        iVar6 = iVar5 + 0xa0;

        fVar2 = *(float *)(iVar5 + 0xb0);

      }

      if (*(float *)(iVar5 + 0x100) < fVar2) {

        iVar6 = iVar5 + 0xf0;

        fVar2 = *(float *)(iVar5 + 0x100);

      }

      if (*(float *)(iVar5 + 0x150) < fVar2) {

        iVar6 = iVar5 + 0x140;

        fVar2 = *(float *)(iVar5 + 0x150);

      }

      iVar5 = iVar5 + 0x140;

      uVar3 = uVar3 - 1;

    } while (uVar3 != 0);

  }

  if (-1 < iVar4) {

    iVar4 = iVar4 + 1;

    do {

      pfVar1 = (float *)(iVar5 + 0x60);

      iVar5 = iVar5 + 0x50;

      if (*pfVar1 < fVar2) {

        iVar6 = iVar5;

        fVar2 = *pfVar1;

      }

      iVar4 = iVar4 + -1;

    } while (iVar4 != 0);

  }

  return iVar6;

}
