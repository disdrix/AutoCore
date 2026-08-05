// =============================================================================
// FUN_00756900
// -----------------------------------------------------------------------------
// Stable ID: aa_00756900
// Address:   0x00756900  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00756900 @ 0x00756900
// Stable ID: aa_00756900
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~98 non-empty decompiler lines.
//  - Control keywords: if×18, do×2, while×2, return×1.
//  - Notable callees: FUN_00756900.
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

byte __thiscall FUN_00756900(float *param_1,int param_2)



{

  byte bVar1;

  int in_EAX;

  byte bVar2;

  byte bVar3;

  byte bVar4;

  byte bVar5;

  int iVar6;

  int iVar7;

  byte bVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  

  bVar1 = 0;

  iVar6 = 0;

  bVar8 = 0xf;

  if (3 < in_EAX) {

    fVar9 = (float)*(int *)(param_2 + 0x48);

    fVar10 = (float)*(int *)(param_2 + 0x50);

    fVar11 = (float)*(int *)(param_2 + 0x4c);

    fVar12 = (float)*(int *)(param_2 + 0x54);

    iVar7 = (in_EAX - 4U >> 2) + 1;

    iVar6 = iVar7 * 4;

    do {

      bVar2 = *param_1 <= fVar9 && fVar9 != *param_1;

      if (fVar10 < *param_1) {

        bVar2 = bVar2 | 2;

      }

      if (param_1[1] <= fVar11 && fVar11 != param_1[1]) {

        bVar2 = bVar2 | 4;

      }

      if (fVar12 < param_1[1]) {

        bVar2 = bVar2 | 8;

      }

      bVar3 = param_1[6] <= fVar9 && fVar9 != param_1[6];

      if (fVar10 < param_1[6]) {

        bVar3 = bVar3 | 2;

      }

      if (param_1[7] <= fVar11 && fVar11 != param_1[7]) {

        bVar3 = bVar3 | 4;

      }

      if (fVar12 < param_1[7]) {

        bVar3 = bVar3 | 8;

      }

      bVar4 = param_1[0xc] <= fVar9 && fVar9 != param_1[0xc];

      if (fVar10 < param_1[0xc]) {

        bVar4 = bVar4 | 2;

      }

      if (param_1[0xd] <= fVar11 && fVar11 != param_1[0xd]) {

        bVar4 = bVar4 | 4;

      }

      if (fVar12 < param_1[0xd]) {

        bVar4 = bVar4 | 8;

      }

      bVar5 = param_1[0x12] <= fVar9 && fVar9 != param_1[0x12];

      if (fVar10 < param_1[0x12]) {

        bVar5 = bVar5 | 2;

      }

      if (param_1[0x13] <= fVar11 && fVar11 != param_1[0x13]) {

        bVar5 = bVar5 | 4;

      }

      if (fVar12 < param_1[0x13]) {

        bVar5 = bVar5 | 8;

      }

      bVar1 = bVar1 | bVar2 | bVar3 | bVar4 | bVar5;

      bVar8 = bVar8 & bVar2 & bVar3 & bVar4 & bVar5;

      param_1 = param_1 + 0x18;

      iVar7 = iVar7 + -1;

    } while (iVar7 != 0);

  }

  if (iVar6 < in_EAX) {

    iVar6 = in_EAX - iVar6;

    do {

      bVar2 = *param_1 <= (float)*(int *)(param_2 + 0x48) &&

              (float)*(int *)(param_2 + 0x48) != *param_1;

      if ((float)*(int *)(param_2 + 0x50) < *param_1) {

        bVar2 = bVar2 | 2;

      }

      if (param_1[1] <= (float)*(int *)(param_2 + 0x4c) &&

          (float)*(int *)(param_2 + 0x4c) != param_1[1]) {

        bVar2 = bVar2 | 4;

      }

      if ((float)*(int *)(param_2 + 0x54) < param_1[1]) {

        bVar2 = bVar2 | 8;

      }

      bVar1 = bVar1 | bVar2;

      bVar8 = bVar8 & bVar2;

      param_1 = param_1 + 6;

      iVar6 = iVar6 + -1;

    } while (iVar6 != 0);

  }

  if (bVar8 != 0) {

    bVar1 = 0xff;

  }

  return bVar1;

}
