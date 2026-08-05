// =============================================================================
// FUN_006d6e10
// -----------------------------------------------------------------------------
// Stable ID: aa_006d6e10
// Address:   0x006d6e10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006d6e10 @ 0x006d6e10
// Stable ID: aa_006d6e10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~183 non-empty decompiler lines.
//  - Control keywords: if×4, while×3, do×2, return×2.
//  - Notable callees: FUN_006d6e10, FUN_006f7340, FUN_006f7820.
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

void FUN_006d6e10(int *param_1,int *param_2,uint32_t /* width from decompiler */ param_3,int *param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  int iVar7;

  float *pfVar8;

  float *pfVar9;

  float *pfVar10;

  float *pfVar11;

  int iVar12;

  float *pfVar13;

  uint local_fc;

  float local_f0;

  float local_ec;

  float local_e8;

  uint32_t /* width from decompiler */ local_e4;

  float local_e0;

  float local_dc;

  float local_d8;

  uint32_t /* width from decompiler */ local_d4;

  float local_d0;

  float local_cc;

  float local_c8;

  uint32_t /* width from decompiler */ local_c4;

  uint8_t local_c0 [16];

  uint8_t local_b0 [16];

  float local_a0;

  float local_90 [6];

  float local_78 [29];

  

  iVar4 = *param_2;

  fVar1 = *(float *)(iVar4 + 0x10);

  iVar12 = param_2[2];

  fVar2 = *(float *)(iVar4 + 0x14);

  fVar3 = *(float *)(iVar4 + 0x18);

  pfVar8 = (float *)(iVar12 + 0x20);

  iVar5 = *param_1;

  local_f0 = fVar2 * *(float *)(iVar12 + 0x30) + fVar3 * *(float *)(iVar12 + 0x40) + fVar1 * *pfVar8

             + *(float *)(iVar12 + 0x50);

  local_ec = fVar1 * *(float *)(iVar12 + 0x24) +

             fVar2 * *(float *)(iVar12 + 0x34) + fVar3 * *(float *)(iVar12 + 0x44) +

             *(float *)(iVar12 + 0x54);

  local_e8 = fVar1 * *(float *)(iVar12 + 0x28) +

             fVar2 * *(float *)(iVar12 + 0x38) + fVar3 * *(float *)(iVar12 + 0x48) +

             *(float *)(iVar12 + 0x58);

  local_e4 = 0;

  fVar1 = *(float *)(iVar4 + 0x20);

  fVar2 = *(float *)(iVar4 + 0x24);

  fVar3 = *(float *)(iVar4 + 0x28);

  local_e0 = fVar2 * *(float *)(iVar12 + 0x30) + fVar3 * *(float *)(iVar12 + 0x40) + fVar1 * *pfVar8

             + *(float *)(iVar12 + 0x50);

  local_dc = fVar1 * *(float *)(iVar12 + 0x24) +

             fVar2 * *(float *)(iVar12 + 0x34) + fVar3 * *(float *)(iVar12 + 0x44) +

             *(float *)(iVar12 + 0x54);

  local_d8 = fVar1 * *(float *)(iVar12 + 0x28) +

             fVar2 * *(float *)(iVar12 + 0x38) + fVar3 * *(float *)(iVar12 + 0x48) +

             *(float *)(iVar12 + 0x58);

  local_d4 = 0;

  fVar1 = *(float *)(iVar4 + 0x30);

  fVar2 = *(float *)(iVar4 + 0x34);

  fVar3 = *(float *)(iVar4 + 0x38);

  pfVar13 = local_90;

  local_d0 = fVar2 * *(float *)(iVar12 + 0x30) + fVar3 * *(float *)(iVar12 + 0x40) + fVar1 * *pfVar8

             + *(float *)(iVar12 + 0x50);

  local_cc = fVar1 * *(float *)(iVar12 + 0x24) +

             fVar2 * *(float *)(iVar12 + 0x34) + fVar3 * *(float *)(iVar12 + 0x44) +

             *(float *)(iVar12 + 0x54);

  local_c8 = fVar1 * *(float *)(iVar12 + 0x28) +

             fVar2 * *(float *)(iVar12 + 0x38) + fVar3 * *(float *)(iVar12 + 0x48) +

             *(float *)(iVar12 + 0x58);

  pfVar8 = (float *)(iVar5 + 0x10);

  local_c4 = 0;

  uVar6 = *(uint *)(iVar5 + 0xc);

  iVar7 = param_1[2];

  iVar12 = uVar6 - 1;

  pfVar9 = (float *)(iVar7 + 0x20);

  if (3 < (int)uVar6) {

    local_fc = uVar6 >> 2;

    iVar12 = iVar12 + local_fc * -4;

    pfVar10 = pfVar8;

    pfVar11 = local_78;

    do {

      fVar1 = *pfVar10;

      fVar2 = pfVar10[1];

      fVar3 = pfVar10[2];

      *pfVar13 = fVar1 * *pfVar9 +

                 fVar2 * *(float *)(iVar7 + 0x30) + fVar3 * *(float *)(iVar7 + 0x40) +

                 *(float *)(iVar7 + 0x50);

      pfVar11[-5] = fVar2 * *(float *)(iVar7 + 0x34) +

                    fVar3 * *(float *)(iVar7 + 0x44) + fVar1 * *(float *)(iVar7 + 0x24) +

                    *(float *)(iVar7 + 0x54);

      pfVar11[-4] = fVar2 * *(float *)(iVar7 + 0x38) +

                    fVar3 * *(float *)(iVar7 + 0x48) + fVar1 * *(float *)(iVar7 + 0x28) +

                    *(float *)(iVar7 + 0x58);

      pfVar11[-3] = 0.0;

      fVar1 = pfVar10[4];

      fVar2 = pfVar10[5];

      fVar3 = pfVar10[6];

      pfVar11[-2] = fVar1 * *pfVar9 +

                    fVar2 * *(float *)(iVar7 + 0x30) + fVar3 * *(float *)(iVar7 + 0x40) +

                    *(float *)(iVar7 + 0x50);

      pfVar11[-1] = fVar2 * *(float *)(iVar7 + 0x34) +

                    fVar3 * *(float *)(iVar7 + 0x44) + fVar1 * *(float *)(iVar7 + 0x24) +

                    *(float *)(iVar7 + 0x54);

      *pfVar11 = fVar2 * *(float *)(iVar7 + 0x38) +

                 fVar3 * *(float *)(iVar7 + 0x48) + fVar1 * *(float *)(iVar7 + 0x28) +

                 *(float *)(iVar7 + 0x58);

      pfVar11[1] = 0.0;

      fVar1 = pfVar10[8];

      fVar2 = pfVar10[9];

      fVar3 = pfVar10[10];

      pfVar11[2] = fVar1 * *pfVar9 +

                   fVar2 * *(float *)(iVar7 + 0x30) + fVar3 * *(float *)(iVar7 + 0x40) +

                   *(float *)(iVar7 + 0x50);

      pfVar13 = pfVar13 + 0x10;

      pfVar8 = pfVar10 + 0x10;

      pfVar11[3] = fVar2 * *(float *)(iVar7 + 0x34) +

                   fVar3 * *(float *)(iVar7 + 0x44) + fVar1 * *(float *)(iVar7 + 0x24) +

                   *(float *)(iVar7 + 0x54);

      pfVar11[4] = fVar2 * *(float *)(iVar7 + 0x38) +

                   fVar3 * *(float *)(iVar7 + 0x48) + fVar1 * *(float *)(iVar7 + 0x28) +

                   *(float *)(iVar7 + 0x58);

      pfVar11[5] = 0.0;

      fVar1 = pfVar10[0xc];

      fVar2 = pfVar10[0xd];

      fVar3 = pfVar10[0xe];

      pfVar11[6] = fVar1 * *pfVar9 +

                   fVar2 * *(float *)(iVar7 + 0x30) + fVar3 * *(float *)(iVar7 + 0x40) +

                   *(float *)(iVar7 + 0x50);

      pfVar11[7] = fVar2 * *(float *)(iVar7 + 0x34) +

                   fVar3 * *(float *)(iVar7 + 0x44) + fVar1 * *(float *)(iVar7 + 0x24) +

                   *(float *)(iVar7 + 0x54);

      pfVar11[8] = fVar2 * *(float *)(iVar7 + 0x38) +

                   fVar3 * *(float *)(iVar7 + 0x48) + fVar1 * *(float *)(iVar7 + 0x28) +

                   *(float *)(iVar7 + 0x58);

      pfVar11[9] = 0.0;

      local_fc = local_fc - 1;

      pfVar10 = pfVar8;

      pfVar11 = pfVar11 + 0x10;

    } while (local_fc != 0);

  }

  if (-1 < iVar12) {

    iVar12 = iVar12 + 1;

    do {

      fVar1 = *pfVar8;

      fVar2 = pfVar8[1];

      iVar12 = iVar12 + -1;

      fVar3 = pfVar8[2];

      *pfVar13 = fVar1 * *pfVar9 +

                 fVar2 * *(float *)(iVar7 + 0x30) + fVar3 * *(float *)(iVar7 + 0x40) +

                 *(float *)(iVar7 + 0x50);

      pfVar13[1] = fVar2 * *(float *)(iVar7 + 0x34) +

                   fVar3 * *(float *)(iVar7 + 0x44) + fVar1 * *(float *)(iVar7 + 0x24) +

                   *(float *)(iVar7 + 0x54);

      pfVar13[2] = fVar2 * *(float *)(iVar7 + 0x38) +

                   fVar3 * *(float *)(iVar7 + 0x48) + fVar1 * *(float *)(iVar7 + 0x28) +

                   *(float *)(iVar7 + 0x58);

      pfVar13[3] = 0.0;

      pfVar8 = pfVar8 + 4;

      pfVar13 = pfVar13 + 4;

    } while (iVar12 != 0);

  }

  FUN_006f7340(iVar4 + 0x10,local_c0);

  iVar12 = 0;

  if (0 < (int)uVar6) {

    pfVar8 = local_90;

    pfVar13 = (float *)(iVar5 + 0x1c);

    while (fVar1 = *pfVar13, fVar2 = *(float *)(iVar4 + 0xc),

          FUN_006f7820(pfVar8,&local_f0,local_c0,local_b0), fVar1 + fVar2 <= local_a0) {

      iVar12 = iVar12 + 1;

      pfVar13 = pfVar13 + 4;

      pfVar8 = pfVar8 + 4;

      if ((int)uVar6 <= iVar12) {

        return;

      }

    }

    (**(code **)(*param_4 + 4))(param_1,param_2);

  }

  return;

}
