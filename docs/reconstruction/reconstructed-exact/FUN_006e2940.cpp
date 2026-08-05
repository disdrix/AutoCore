// =============================================================================
// FUN_006e2940
// -----------------------------------------------------------------------------
// Stable ID: aa_006e2940
// Address:   0x006e2940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e2940 @ 0x006e2940
// Stable ID: aa_006e2940
// Embedded strings (evidence for future rename):
//   - "TtSphereCapsule"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~161 non-empty decompiler lines.
//  - Control keywords: if×11, return×1.
//  - Notable callees: ABS×3, SQRT×2, rdtsc×2, FUN_005b3370, FUN_006e2940, FUN_006f71e0.
//  - Strings: "TtSphereCapsule".
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

void __thiscall FUN_006e2940(int param_1,int *param_2,int *param_3,int param_4,int *param_5)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int *piVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  bool bVar9;

  uint64_t uVar10;

  float fVar11;

  uint16_t uVar12;

  uint uVar13;

  uint uVar14;

  float *pfVar15;

  float *pfVar16;

  float local_50 [4];

  float local_40;

  float local_3c;

  float local_38;

  float local_34;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TtSphereCapsule";

    uVar10 = rdtsc();

    DAT_00bc5644[1] = (int)uVar10;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  piVar4 = (int *)*param_5;

  if (piVar4[1] == (piVar4[2] & 0x7fffffffU)) {

    FUN_005b3370(piVar4,0x30);

  }

  pfVar15 = (float *)(piVar4[1] * 0x30 + *piVar4);

  piVar4[1] = piVar4[1] + 1;

  iVar5 = *param_2;

  iVar6 = param_2[2];

  iVar7 = *param_3;

  fVar1 = *(float *)(iVar7 + 0x10);

  iVar8 = param_3[2];

  fVar2 = *(float *)(iVar7 + 0x14);

  pfVar16 = (float *)(iVar6 + 0x50);

  fVar3 = *(float *)(iVar7 + 0x18);

  local_30 = fVar1 * *(float *)(iVar8 + 0x20) +

             fVar2 * *(float *)(iVar8 + 0x30) + fVar3 * *(float *)(iVar8 + 0x40) +

             *(float *)(iVar8 + 0x50);

  local_2c = fVar2 * *(float *)(iVar8 + 0x34) +

             fVar3 * *(float *)(iVar8 + 0x44) + fVar1 * *(float *)(iVar8 + 0x24) +

             *(float *)(iVar8 + 0x54);

  local_28 = fVar2 * *(float *)(iVar8 + 0x38) +

             fVar3 * *(float *)(iVar8 + 0x48) + fVar1 * *(float *)(iVar8 + 0x28) +

             *(float *)(iVar8 + 0x58);

  local_24 = 0.0;

  fVar1 = *(float *)(iVar7 + 0x20);

  fVar2 = *(float *)(iVar7 + 0x24);

  fVar3 = *(float *)(iVar7 + 0x28);

  local_20 = fVar1 * *(float *)(iVar8 + 0x20) +

             fVar2 * *(float *)(iVar8 + 0x30) + fVar3 * *(float *)(iVar8 + 0x40) +

             *(float *)(iVar8 + 0x50);

  local_1c = fVar2 * *(float *)(iVar8 + 0x34) +

             fVar3 * *(float *)(iVar8 + 0x44) + fVar1 * *(float *)(iVar8 + 0x24) +

             *(float *)(iVar8 + 0x54);

  local_18 = fVar2 * *(float *)(iVar8 + 0x38) +

             fVar3 * *(float *)(iVar8 + 0x48) + fVar1 * *(float *)(iVar8 + 0x28) +

             *(float *)(iVar8 + 0x58);

  local_14 = 0.0;

  FUN_006f71e0(pfVar16,&local_30,&local_20,&local_40);

  fVar11 = g_flZero;

  local_50[0] = *pfVar16 - local_40;

  local_50[1] = *(float *)(iVar6 + 0x54) - local_3c;

  local_50[2] = *(float *)(iVar6 + 0x58) - local_38;

  local_50[3] = *(float *)(iVar6 + 0x5c) - local_34;

  fVar2 = *(float *)(iVar5 + 0xc) + *(float *)(iVar7 + 0xc);

  fVar3 = fVar2 + *(float *)(param_4 + 8);

  fVar1 = local_50[0] * local_50[0] + local_50[1] * local_50[1] + local_50[2] * local_50[2];

  if (fVar3 * fVar3 <= fVar1) {

    *(int *)(*param_5 + 4) = *(int *)(*param_5 + 4) + -1;

    if (*(short *)(param_1 + 0xc) != -1) {

      (**(code **)(**(int **)(param_1 + 8) + 8))(*(short *)(param_1 + 0xc));

      *(uint16_t *)(param_1 + 0xc) = 0xffff;

    }

  }

  else {

    if (fVar1 <= g_flZero) {

      local_50[0] = local_20 - local_30;

      local_50[1] = local_1c - local_2c;

      local_50[2] = local_18 - local_28;

      local_50[3] = local_14 - local_24;

      fVar1 = ABS(local_20 - local_30);

      fVar3 = ABS(local_1c - local_2c);

      bVar9 = fVar1 <= fVar3;

      if (!bVar9) {

        fVar1 = fVar3;

      }

      uVar14 = (uint)!bVar9;

      if (fVar1 <= ABS(local_18 - local_28)) {

        uVar13 = 2;

      }

      else {

        uVar13 = uVar14;

        uVar14 = 2;

      }

      pfVar15[uVar14 + 4] = 0.0;

      fVar1 = local_50[bVar9];

      pfVar15[bVar9 + 4] = local_50[uVar13];

      pfVar15[uVar13 + 4] = -fVar1;

    }

    else {

      fVar11 = SQRT(fVar1);

      pfVar15[4] = local_50[0];

      pfVar15[5] = local_50[1];

      pfVar15[6] = local_50[2];

      pfVar15[7] = local_50[3];

    }

    fVar1 = pfVar15[6] * pfVar15[6] + pfVar15[5] * pfVar15[5] + pfVar15[4] * pfVar15[4];

    fVar3 = g_flZero;

    if (fVar1 != g_flZero) {

      fVar3 = g_flOne / SQRT(fVar1);

    }

    pfVar15[4] = fVar3 * pfVar15[4];

    pfVar15[5] = fVar3 * pfVar15[5];

    pfVar15[6] = fVar3 * pfVar15[6];

    pfVar15[7] = fVar3 * pfVar15[7];

    fVar1 = *(float *)(iVar7 + 0xc);

    *pfVar15 = *pfVar16;

    fVar1 = fVar1 - fVar11;

    pfVar15[1] = *(float *)(iVar6 + 0x54);

    pfVar15[2] = *(float *)(iVar6 + 0x58);

    pfVar15[3] = *(float *)(iVar6 + 0x5c);

    *pfVar15 = fVar1 * pfVar15[4] + *pfVar15;

    pfVar15[1] = fVar1 * pfVar15[5] + pfVar15[1];

    pfVar15[2] = fVar1 * pfVar15[6] + pfVar15[2];

    pfVar15[3] = fVar1 * pfVar15[7] + pfVar15[3];

    pfVar15[3] = fVar11 - fVar2;

    if (*(short *)(param_1 + 0xc) == -1) {

      uVar12 = (**(code **)(**(int **)(param_1 + 8) + 4))(param_2,param_3,param_4,pfVar15);

      *(uint16_t *)(param_1 + 0xc) = uVar12;

    }

    if (*(short *)(param_1 + 0xc) == -1) {

      *(int *)(*param_5 + 4) = *(int *)(*param_5 + 4) + -1;

    }

    else {

      *(short *)(pfVar15 + 8) = *(short *)(param_1 + 0xc);

    }

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar10 = rdtsc();

    DAT_00bc5644[1] = (int)uVar10;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
