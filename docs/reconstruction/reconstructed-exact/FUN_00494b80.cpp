// =============================================================================
// FUN_00494b80
// -----------------------------------------------------------------------------
// Stable ID: aa_00494b80
// Address:   0x00494b80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00494b80 @ 0x00494b80
// Stable ID: aa_00494b80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~183 non-empty decompiler lines.
//  - Control keywords: if×16, do×3, while×3, goto×1, return×1.
//  - Notable callees: ROUND×4, ceil×2, floor×2, FUN_00494310, FUN_00494b80, FUN_004cdda0, FUN_0075b390, FUN_0076cef0.
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

void __thiscall FUN_00494b80(int param_1,int param_2,float param_3,char param_4)



{

  char cVar1;

  float *pfVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  float *pfVar6;

  int iVar7;

  int iVar8;

  double dVar9;

  int local_cc;

  int local_c8;

  int local_bc;

  int local_b8;

  float local_ac;

  float local_a8;

  float local_a4;

  uint8_t *local_a0;

  float local_9c;

  float local_98;

  float local_94;

  float local_90;

  float local_8c;

  float local_88;

  float local_84;

  float local_80;

  float local_7c;

  float local_78;

  float local_74;

  float local_70;

  float local_6c;

  float local_68;

  float local_64;

  float local_60;

  float local_5c;

  float local_58;

  float local_54;

  float local_50;

  float local_4c;

  float local_48;

  float local_44;

  float local_40;

  uint8_t local_3c [8];

  float local_34 [10];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a0c0f;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0076cf00();

  local_4 = 0;

  dVar9 = floor((double)((*(float *)(param_1 + 0x8c) - param_3) / DAT_00aefa50));

  *(int *)(param_1 + 100) = (int)ROUND(dVar9);

  dVar9 = floor((double)((*(float *)(param_1 + 0x94) - param_3) / DAT_00aefa50));

  *(int *)(param_1 + 0x68) = (int)ROUND(dVar9);

  dVar9 = ceil((double)((param_3 + *(float *)(param_1 + 0x8c)) / DAT_00aefa50));

  *(int *)(param_1 + 0x6c) = (int)ROUND(dVar9);

  dVar9 = ceil((double)((param_3 + *(float *)(param_1 + 0x94)) / DAT_00aefa50));

  *(int *)(param_1 + 0x70) = (int)ROUND(dVar9);

  iVar4 = *(int *)(*(int *)(param_2 + 0xe894) + 0xc0);

  FUN_0075b390();

  if (param_4 != '\0') {

    local_9c = *(float *)(iVar4 + 0xf8);

    local_94 = *(float *)(iVar4 + 0xf0);

    local_8c = 0.0 - local_9c;

    local_84 = 0.0 - local_9c;

    local_80 = 0.0 - local_9c;

    local_78 = 0.0 - local_9c;

    local_48 = *(float *)(iVar4 + 0xf4) / local_94;

    local_64 = local_94 * local_48;

    local_5c = local_8c * local_48;

    local_68 = local_9c * local_48;

    local_6c = local_9c * local_48;

    local_58 = local_94 * local_48;

    local_60 = local_9c * local_48;

    local_4c = local_94 * local_48;

    local_54 = local_84 * local_48;

    local_50 = local_80 * local_48;

    local_40 = local_94 * local_48;

    local_44 = local_9c * local_48;

    local_48 = local_78 * local_48;

    iVar7 = 8;

    local_98 = local_9c;

    local_90 = local_9c;

    local_88 = local_94;

    local_7c = local_94;

    local_74 = local_9c;

    local_70 = local_94;

    do {

      if ((*(byte *)(*(int *)(iVar4 + 8) + 0xbc) & 1) != 0) {

        FUN_00972e50();

      }

      FUN_00972a60();

      iVar7 = iVar7 + -1;

    } while (iVar7 != 0);

    iVar7 = *(int *)(param_2 + 0xe894);

    pfVar2 = (float *)(iVar7 + 0x128);

    pfVar6 = &local_94;

    iVar8 = 0;

    local_a0 = local_3c + -(int)pfVar6;

    local_cc = 0;

    do {

      local_ac = pfVar6[10] - pfVar6[-2];

      local_a8 = pfVar6[0xb] - pfVar6[-1];

      local_a4 = pfVar6[0xc] - *pfVar6;

      FUN_0076f5f0(&local_ac,&local_ac);

      cVar1 = FUN_004cdda0(pfVar2,&local_ac,local_a0 + (int)pfVar6,*(uint32_t /* width from decompiler */ *)(iVar4 + 0xf4));

      if (cVar1 == '\0') goto LAB_00495097;

      local_cc = local_cc + 1;

      iVar8 = iVar8 + 1;

      pfVar6 = pfVar6 + 3;

    } while (iVar8 < 4);

    local_bc = *(int *)(param_1 + 0x6c);

    local_b8 = *(int *)(param_1 + 0x70);

    iVar4 = *(int *)(param_1 + 100);

    iVar8 = *(int *)(param_1 + 0x68);

    if (0 < local_cc) {

      pfVar6 = local_34;

      local_c8 = local_cc;

      do {

        iVar5 = (int)(pfVar6[-2] * (g_flOne / DAT_00aefa50));

        if (iVar4 <= iVar5) {

          iVar4 = iVar5;

        }

        iVar3 = (int)((g_flOne / DAT_00aefa50) * *pfVar6);

        if (iVar8 <= iVar3) {

          iVar8 = iVar3;

        }

        if (iVar5 <= local_bc) {

          local_bc = iVar5;

        }

        if (iVar3 <= local_b8) {

          local_b8 = iVar3;

        }

        pfVar6 = pfVar6 + 3;

        local_c8 = local_c8 + -1;

      } while (local_c8 != 0);

    }

    iVar5 = (int)(*pfVar2 * (g_flOne / DAT_00aefa50));

    if (iVar4 <= iVar5) {

      iVar4 = iVar5;

    }

    iVar7 = (int)(*(float *)(iVar7 + 0x130) * (g_flOne / DAT_00aefa50));

    if (iVar8 <= iVar7) {

      iVar8 = iVar7;

    }

    if (iVar5 <= local_bc) {

      local_bc = iVar5;

    }

    if (iVar7 <= local_b8) {

      local_b8 = iVar7;

    }

    if (DAT_00aefa65 != '\0') {

      *(int *)(param_1 + 100) = local_bc + -2;

      *(int *)(param_1 + 0x68) = local_b8 + -2;

      *(int *)(param_1 + 0x6c) = iVar4 + 2;

      *(int *)(param_1 + 0x70) = iVar8 + 2;

    }

  }

LAB_00495097:

  if (*(char *)(param_2 + 0x7d) == '\0') {

    iVar7 = 0x640;

    iVar4 = 0x28;

    if (*(char *)(param_2 + 0xf5) != '\0') {

      iVar7 = 0x1900;

      iVar4 = 0x50;

    }

    iVar8 = (*(int *)(param_1 + 0x70) - *(int *)(param_1 + 0x68)) *

            (*(int *)(param_1 + 0x6c) - *(int *)(param_1 + 100));

    if (iVar8 - iVar7 != 0 && iVar7 <= iVar8) {

      *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 100) + iVar4;

      *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x68) + iVar4;

    }

  }

  FUN_00494310();

  local_4 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = local_c;

  return;

}
