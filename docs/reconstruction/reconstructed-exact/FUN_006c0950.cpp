// =============================================================================
// FUN_006c0950
// -----------------------------------------------------------------------------
// Stable ID: aa_006c0950
// Address:   0x006c0950  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c0950 @ 0x006c0950
// Stable ID: aa_006c0950
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~112 non-empty decompiler lines.
//  - Control keywords: if×12, goto×3, do×2, while×2, return×2.
//  - Notable callees: CONCAT22, FUN_006c0570, FUN_006c0640, FUN_006c0950, movmskps.
//  - Return sites: 2.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_006c0950(char *param_1,uint32_t /* width from decompiler */ param_2,int param_3,int param_4,uint32_t /* width from decompiler */ param_5,

                 int *param_6,uint32_t /* width from decompiler */ param_7)



{

  float *pfVar1;

  short sVar2;

  uint8_t auVar3 [16];

  char *pcVar4;

  float *pfVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  bool bVar10;

  uint uVar11;

  uint uVar12;

  uint uVar13;

  uint uVar14;

  uint8_t local_2d;

  int local_2c;

  char local_28 [4];

  char local_24 [4];

  char local_20 [4];

  int local_1c;

  uint32_t /* width from decompiler */ local_18;

  int local_14;

  

  pcVar4 = (char *)FUN_006c0640(&local_2d,param_2,param_4,param_5,param_7);

  iVar6 = param_6[1];

  bVar10 = *pcVar4 != '\0';

  local_2c = 0;

  if (0 < iVar6) {

    local_1c = 0;

    uVar11 = _DAT_00a0d180;

    uVar12 = _UNK_00a0d184;

    uVar13 = _UNK_00a0d188;

    uVar14 = _UNK_00a0d18c;

    local_14 = iVar6;

    do {

      if (bVar10 == false) {

LAB_006c09ca:

        bVar10 = false;

      }

      else {

        iVar7 = *param_6;

        sVar2 = **(short **)(iVar7 + 0x14 + local_1c);

        if ((**(short **)(iVar7 + 0x10 + local_1c) == sVar2) ||

           (sVar2 == **(short **)(iVar7 + local_1c + 0x18))) goto LAB_006c09ca;

        bVar10 = true;

      }

      iVar8 = 0;

      local_28[0] = '\0';

      local_24[0] = '\0';

      local_20[0] = '\0';

      iVar7 = local_1c;

      if (0 < iVar6) {

        iVar9 = 0;

        do {

          if (iVar8 != local_2c) {

            if (bVar10) {

              iVar6 = *param_6;

              pfVar1 = (float *)(iVar9 + iVar6);

              pfVar5 = (float *)(iVar6 + iVar7);

              if (((*(short *)pfVar5[4] == **(short **)(iVar9 + 0x10 + iVar6)) &&

                  (*(short *)pfVar5[5] == *(short *)pfVar1[5])) &&

                 (sVar2 = *(short *)pfVar5[6], sVar2 == *(short *)pfVar1[6])) {

                local_18 = 0x3a83126f;

                auVar3._4_4_ = -(uint)(0.001 < (float)((uint)(pfVar5[1] - pfVar1[1]) & uVar12));

                auVar3._0_4_ = -(uint)(0.001 < (float)((uint)(*pfVar5 - *pfVar1) & uVar11));

                auVar3._8_4_ = -(uint)(0.001 < (float)((uint)(pfVar5[2] - pfVar1[2]) & uVar13));

                auVar3._12_4_ = -(uint)(0.001 < (float)((uint)(pfVar5[3] - pfVar1[3]) & uVar14));

                iVar6 = movmskps(CONCAT22((short)((uint)pfVar5[6] >> 0x10),sVar2),auVar3);

                if (iVar6 == 0) goto LAB_006c0a88;

              }

              pcVar4 = (char *)FUN_006c0570(&local_2d,pfVar5,pfVar1,local_28,local_24,local_20);

              if (*pcVar4 != '\0') {

                bVar10 = true;

                iVar7 = local_1c;

                iVar6 = local_14;

                goto LAB_006c0a92;

              }

            }

LAB_006c0a88:

            bVar10 = false;

            iVar7 = local_1c;

            iVar6 = local_14;

          }

LAB_006c0a92:

          iVar8 = iVar8 + 1;

          iVar9 = iVar9 + 0x20;

        } while (iVar8 < iVar6);

      }

      if (((bVar10) && (local_28[0] != '\0')) && ((local_24[0] != '\0' && (local_20[0] != '\0')))) {

        bVar10 = true;

      }

      else {

        bVar10 = false;

      }

      local_2c = local_2c + 1;

      local_1c = iVar7 + 0x20;

    } while (local_2c < iVar6);

  }

  if (2 < *(int *)(param_4 + 4)) {

    if ((bVar10 != false) && ((iVar6 - *(int *)(param_3 + 8) / 2) + -2 + *(int *)(param_4 + 4) == 0)

       ) {

      *param_1 = '\x01';

      return;

    }

    bVar10 = false;

  }

  *param_1 = bVar10;

  return;

}
