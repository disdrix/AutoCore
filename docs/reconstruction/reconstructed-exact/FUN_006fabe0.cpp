// =============================================================================
// FUN_006fabe0
// -----------------------------------------------------------------------------
// Stable ID: aa_006fabe0
// Address:   0x006fabe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006fabe0 @ 0x006fabe0
// Stable ID: aa_006fabe0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~126 non-empty decompiler lines.
//  - Control keywords: if×16, do×5, while×5, return×5.
//  - Notable callees: FUN_006f80d0×2, FUN_006f8340, FUN_006f8b10, FUN_006f8c00, FUN_006f9a10, FUN_006f9c20, FUN_006f9e30, FUN_006f9f90.
//  - Return sites: 5.

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

uint32_t /* width from decompiler */ __thiscall FUN_006fabe0(int param_1,int param_2,short *param_3,int param_4)



{

  int iVar1;

  float fVar2;

  int iVar3;

  short sVar4;

  char *pcVar5;

  float *pfVar6;

  int iVar7;

  short *psVar8;

  short *psVar9;

  int iVar10;

  bool bVar11;

  uint8_t local_d;

  int local_c;

  int local_8;

  char local_4 [4];

  

  iVar3 = param_4;

  local_8 = 8;

  local_c = param_1;

  do {

    fVar2 = *(float *)(local_c + 0xd0);

    iVar10 = 0;

    pfVar6 = (float *)(local_c + 0xd8);

    iVar7 = 3;

    do {

      if (fVar2 < pfVar6[-1]) {

        iVar10 = iVar7 + -2;

        fVar2 = pfVar6[-1];

      }

      if (fVar2 < *pfVar6) {

        iVar10 = iVar7 + -1;

        fVar2 = *pfVar6;

      }

      if (fVar2 < pfVar6[1]) {

        fVar2 = pfVar6[1];

        iVar10 = iVar7;

      }

      if (fVar2 < pfVar6[2]) {

        iVar10 = iVar7 + 1;

        fVar2 = pfVar6[2];

      }

      if (fVar2 < pfVar6[3]) {

        iVar10 = iVar7 + 2;

        fVar2 = pfVar6[3];

      }

      if (fVar2 < pfVar6[4]) {

        iVar10 = iVar7 + 3;

        fVar2 = pfVar6[4];

      }

      if (fVar2 < pfVar6[5]) {

        iVar10 = iVar7 + 4;

        fVar2 = pfVar6[5];

      }

      iVar1 = iVar7 + 5;

      pfVar6 = pfVar6 + 7;

      iVar7 = iVar7 + 7;

    } while (iVar1 < 0xf);

    if (iVar10 < 3) {

      *param_3 = (short)iVar10;

      FUN_006f9a10(iVar3,iVar10);

      sVar4 = FUN_006f80d0(*(uint32_t /* width from decompiler */ *)(iVar3 + 0x30));

      param_3[1] = sVar4;

      iVar7 = *(int *)(param_2 + 0x54) + -1;

      if (-1 < iVar7) {

        psVar9 = (short *)(param_2 + 0x22 + iVar7 * 6);

        do {

          if ((psVar9[-1] == *param_3) && (*psVar9 == sVar4)) {

            return 1;

          }

          iVar7 = iVar7 + -1;

          psVar9 = psVar9 + -3;

        } while (-1 < iVar7);

      }

      pcVar5 = (char *)FUN_006f8b10(&param_4,iVar3);

      bVar11 = *pcVar5 == '\0';

    }

    else if (iVar10 < 6) {

      *param_3 = (short)iVar10;

      FUN_006f9c20(iVar3,iVar10 + -3);

      sVar4 = FUN_006f80d0(*(uint32_t /* width from decompiler */ *)(iVar3 + 0x30));

      param_3[1] = sVar4;

      iVar7 = *(int *)(param_2 + 0x54) + -1;

      if (-1 < iVar7) {

        psVar9 = (short *)(param_2 + 0x22 + iVar7 * 6);

        do {

          if ((psVar9[-1] == *param_3) && (*psVar9 == sVar4)) {

            return 1;

          }

          iVar7 = iVar7 + -1;

          psVar9 = psVar9 + -3;

        } while (-1 < iVar7);

      }

      pcVar5 = (char *)FUN_006f8c00(&local_d,iVar3);

      bVar11 = *pcVar5 == '\0';

    }

    else {

      *(uint16_t *)(iVar3 + 0x38) = *(uint16_t *)(&DAT_00a0ef08 + iVar10 * 4);

      *(uint16_t *)(iVar3 + 0x3a) = *(uint16_t *)(&DAT_00a0ef2c + iVar10);

      FUN_006f9e30(iVar3);

      psVar9 = param_3 + 1;

      FUN_006f8340(param_3,psVar9);

      *(short *)(iVar3 + 0x38) = *param_3;

      *(short *)(iVar3 + 0x3a) = *psVar9;

      iVar7 = *(int *)(param_2 + 0x54) + -1;

      if (-1 < iVar7) {

        psVar8 = (short *)(param_2 + 0x22 + iVar7 * 6);

        do {

          if ((psVar8[-1] == *param_3) && (*psVar8 == *psVar9)) {

            return 1;

          }

          iVar7 = iVar7 + -1;

          psVar8 = psVar8 + -3;

        } while (-1 < iVar7);

      }

      FUN_006f9f90(local_4,iVar3);

      bVar11 = local_4[0] == '\0';

    }

    if (!bVar11) {

      return 2;

    }

    *(uint32_t /* width from decompiler */ *)(local_c + 0xd0 + iVar10 * 4) = 0xff7fffff;

    local_8 = local_8 + -1;

  } while (0 < local_8);

  return 0;

}
