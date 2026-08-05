// =============================================================================
// FUN_0056af90
// -----------------------------------------------------------------------------
// Stable ID: aa_0056af90
// Address:   0x0056af90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056af90 @ 0x0056af90
// Stable ID: aa_0056af90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, while×1, return×1.
//  - Notable callees: FUN_0056af90, ROUND, ceil.
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

void __thiscall FUN_0056af90(int param_1,int param_2,char param_3)



{

  short sVar1;

  short sVar2;

  short sVar3;

  short sVar4;

  short sVar5;

  short sVar6;

  short sVar7;

  short *psVar8;

  int iVar9;

  double dVar10;

  

  sVar1 = *(short *)(param_1 + 0x132);

  sVar2 = *(short *)(param_1 + 0x130);

  psVar8 = (short *)(param_1 + 0x130);

  sVar3 = *(short *)(param_1 + 0x134);

  sVar4 = *(short *)(param_1 + 0x136);

  sVar5 = *(short *)(param_1 + 0x138);

  sVar6 = *(short *)(param_1 + 0x13a);

  iVar9 = 0;

  do {

    if (g_flOne - *(float *)(param_2 + iVar9 * 4) != g_flZero) {

      dVar10 = ceil((double)((*(float *)(param_2 + iVar9 * 4) - g_flOne) *

                            ((float)(int)sVar1 + (float)(int)sVar2 + (float)(int)sVar3 +

                             (float)(int)sVar4 + (float)(int)sVar5 + (float)(int)sVar6)));

      sVar7 = (short)(int)ROUND((float)dVar10);

      if (sVar7 == 0) {

        sVar7 = 1;

      }

      if (param_3 == '\0') {

        *psVar8 = *psVar8 + sVar7;

        if (*psVar8 < 1) {

          *psVar8 = 1;

        }

        if (*psVar8 < psVar8[-6]) {

          *psVar8 = psVar8[-6];

        }

      }

      else {

        if (sVar7 < 1) {

          sVar7 = 1;

        }

        *psVar8 = *psVar8 - sVar7;

      }

    }

    iVar9 = iVar9 + 1;

    psVar8 = psVar8 + 1;

  } while (iVar9 < 6);

  return;

}
