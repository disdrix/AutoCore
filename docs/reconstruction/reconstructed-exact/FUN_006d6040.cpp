// =============================================================================
// FUN_006d6040
// -----------------------------------------------------------------------------
// Stable ID: aa_006d6040
// Address:   0x006d6040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006d6040 @ 0x006d6040
// Stable ID: aa_006d6040
// Embedded strings (evidence for future rename):
//   - "TtMultiSphereTriangle"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~215 non-empty decompiler lines.
//  - Control keywords: if×6, do×3, while×3, return×1.
//  - Notable callees: rdtsc×2, FUN_006d6040, FUN_006f7820.
//  - Strings: "TtMultiSphereTriangle".
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

void __thiscall FUN_006d6040(int param_1,int *param_2,int *param_3,int param_4,int *param_5)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  uint uVar7;

  uint64_t uVar8;

  float *pfVar9;

  float *pfVar10;

  float *pfVar11;

  float *pfVar12;

  int iVar13;

  float *pfVar14;

  uint local_124;

  float local_110;

  float local_10c;

  float local_108;

  uint32_t /* width from decompiler */ local_104;

  float local_100;

  float local_fc;

  float local_f8;

  uint32_t /* width from decompiler */ local_f4;

  float local_f0;

  float local_ec;

  float local_e8;

  uint32_t /* width from decompiler */ local_e4;

  float local_e0;

  float local_dc;

  float local_d8;

  float local_d4;

  float local_d0;

  float local_cc;

  float local_c8;

  uint32_t /* width from decompiler */ local_c4;

  int *local_c0;

  int *local_bc;

  float local_b0;

  float local_ac;

  float local_a8;

  uint32_t /* width from decompiler */ local_a4;

  float local_a0;

  float local_90 [6];

  float local_78 [29];

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TtMultiSphereTriangle";

    uVar8 = rdtsc();

    DAT_00bc5644[1] = (int)uVar8;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  iVar4 = *param_3;

  fVar1 = *(float *)(iVar4 + 0x10);

  iVar13 = param_3[2];

  fVar2 = *(float *)(iVar4 + 0x14);

  pfVar9 = (float *)(iVar13 + 0x20);

  fVar3 = *(float *)(iVar4 + 0x18);

  iVar5 = *param_2;

  local_110 = fVar1 * *pfVar9 +

              fVar2 * *(float *)(iVar13 + 0x30) + fVar3 * *(float *)(iVar13 + 0x40) +

              *(float *)(iVar13 + 0x50);

  local_10c = fVar2 * *(float *)(iVar13 + 0x34) +

              fVar3 * *(float *)(iVar13 + 0x44) + fVar1 * *(float *)(iVar13 + 0x24) +

              *(float *)(iVar13 + 0x54);

  local_108 = fVar2 * *(float *)(iVar13 + 0x38) +

              fVar3 * *(float *)(iVar13 + 0x48) + fVar1 * *(float *)(iVar13 + 0x28) +

              *(float *)(iVar13 + 0x58);

  local_104 = 0;

  fVar1 = *(float *)(iVar4 + 0x20);

  fVar2 = *(float *)(iVar4 + 0x24);

  fVar3 = *(float *)(iVar4 + 0x28);

  local_100 = fVar1 * *pfVar9 +

              fVar2 * *(float *)(iVar13 + 0x30) + fVar3 * *(float *)(iVar13 + 0x40) +

              *(float *)(iVar13 + 0x50);

  local_fc = fVar2 * *(float *)(iVar13 + 0x34) +

             fVar3 * *(float *)(iVar13 + 0x44) + fVar1 * *(float *)(iVar13 + 0x24) +

             *(float *)(iVar13 + 0x54);

  local_f8 = fVar2 * *(float *)(iVar13 + 0x38) +

             fVar3 * *(float *)(iVar13 + 0x48) + fVar1 * *(float *)(iVar13 + 0x28) +

             *(float *)(iVar13 + 0x58);

  local_f4 = 0;

  fVar1 = *(float *)(iVar4 + 0x30);

  fVar2 = *(float *)(iVar4 + 0x34);

  fVar3 = *(float *)(iVar4 + 0x38);

  pfVar12 = (float *)(iVar5 + 0x10);

  local_f0 = fVar1 * *pfVar9 + fVar2 * *(float *)(iVar13 + 0x30) + fVar3 * *(float *)(iVar13 + 0x40)

             + *(float *)(iVar13 + 0x50);

  local_ec = fVar2 * *(float *)(iVar13 + 0x34) +

             fVar3 * *(float *)(iVar13 + 0x44) + fVar1 * *(float *)(iVar13 + 0x24) +

             *(float *)(iVar13 + 0x54);

  local_e8 = fVar2 * *(float *)(iVar13 + 0x38) +

             fVar3 * *(float *)(iVar13 + 0x48) + fVar1 * *(float *)(iVar13 + 0x28) +

             *(float *)(iVar13 + 0x58);

  iVar6 = param_2[2];

  local_e4 = 0;

  pfVar10 = (float *)(iVar6 + 0x20);

  uVar7 = *(uint *)(iVar5 + 0xc);

  iVar13 = uVar7 - 1;

  pfVar9 = local_90;

  if (3 < (int)uVar7) {

    local_124 = uVar7 >> 2;

    iVar13 = iVar13 + local_124 * -4;

    pfVar11 = pfVar12;

    pfVar14 = local_78;

    do {

      fVar1 = *pfVar11;

      fVar2 = pfVar11[1];

      fVar3 = pfVar11[2];

      *pfVar9 = fVar2 * *(float *)(iVar6 + 0x30) +

                fVar3 * *(float *)(iVar6 + 0x40) + fVar1 * *pfVar10 + *(float *)(iVar6 + 0x50);

      pfVar14[-5] = fVar2 * *(float *)(iVar6 + 0x34) +

                    fVar3 * *(float *)(iVar6 + 0x44) + fVar1 * *(float *)(iVar6 + 0x24) +

                    *(float *)(iVar6 + 0x54);

      pfVar14[-4] = fVar2 * *(float *)(iVar6 + 0x38) +

                    fVar3 * *(float *)(iVar6 + 0x48) + fVar1 * *(float *)(iVar6 + 0x28) +

                    *(float *)(iVar6 + 0x58);

      pfVar14[-3] = 0.0;

      fVar1 = pfVar11[4];

      fVar2 = pfVar11[5];

      fVar3 = pfVar11[6];

      pfVar14[-2] = fVar2 * *(float *)(iVar6 + 0x30) +

                    fVar3 * *(float *)(iVar6 + 0x40) + fVar1 * *pfVar10 + *(float *)(iVar6 + 0x50);

      pfVar14[-1] = fVar2 * *(float *)(iVar6 + 0x34) +

                    fVar3 * *(float *)(iVar6 + 0x44) + fVar1 * *(float *)(iVar6 + 0x24) +

                    *(float *)(iVar6 + 0x54);

      *pfVar14 = fVar2 * *(float *)(iVar6 + 0x38) +

                 fVar3 * *(float *)(iVar6 + 0x48) + fVar1 * *(float *)(iVar6 + 0x28) +

                 *(float *)(iVar6 + 0x58);

      pfVar14[1] = 0.0;

      fVar1 = pfVar11[8];

      fVar2 = pfVar11[9];

      fVar3 = pfVar11[10];

      pfVar14[2] = fVar2 * *(float *)(iVar6 + 0x30) +

                   fVar3 * *(float *)(iVar6 + 0x40) + fVar1 * *pfVar10 + *(float *)(iVar6 + 0x50);

      pfVar9 = pfVar9 + 0x10;

      pfVar12 = pfVar11 + 0x10;

      pfVar14[3] = fVar2 * *(float *)(iVar6 + 0x34) +

                   fVar3 * *(float *)(iVar6 + 0x44) + fVar1 * *(float *)(iVar6 + 0x24) +

                   *(float *)(iVar6 + 0x54);

      pfVar14[4] = fVar2 * *(float *)(iVar6 + 0x38) +

                   fVar3 * *(float *)(iVar6 + 0x48) + fVar1 * *(float *)(iVar6 + 0x28) +

                   *(float *)(iVar6 + 0x58);

      pfVar14[5] = 0.0;

      fVar1 = pfVar11[0xc];

      fVar2 = pfVar11[0xd];

      fVar3 = pfVar11[0xe];

      pfVar14[6] = fVar2 * *(float *)(iVar6 + 0x30) +

                   fVar3 * *(float *)(iVar6 + 0x40) + fVar1 * *pfVar10 + *(float *)(iVar6 + 0x50);

      pfVar14[7] = fVar2 * *(float *)(iVar6 + 0x34) +

                   fVar3 * *(float *)(iVar6 + 0x44) + fVar1 * *(float *)(iVar6 + 0x24) +

                   *(float *)(iVar6 + 0x54);

      pfVar14[8] = fVar2 * *(float *)(iVar6 + 0x38) +

                   fVar3 * *(float *)(iVar6 + 0x48) + fVar1 * *(float *)(iVar6 + 0x28) +

                   *(float *)(iVar6 + 0x58);

      pfVar14[9] = 0.0;

      local_124 = local_124 - 1;

      pfVar11 = pfVar12;

      pfVar14 = pfVar14 + 0x10;

    } while (local_124 != 0);

  }

  if (-1 < iVar13) {

    iVar13 = iVar13 + 1;

    do {

      fVar1 = *pfVar12;

      fVar2 = pfVar12[1];

      iVar13 = iVar13 + -1;

      fVar3 = pfVar12[2];

      *pfVar9 = fVar2 * *(float *)(iVar6 + 0x30) +

                fVar3 * *(float *)(iVar6 + 0x40) + fVar1 * *pfVar10 + *(float *)(iVar6 + 0x50);

      pfVar9[1] = fVar2 * *(float *)(iVar6 + 0x34) +

                  fVar3 * *(float *)(iVar6 + 0x44) + fVar1 * *(float *)(iVar6 + 0x24) +

                  *(float *)(iVar6 + 0x54);

      pfVar9[2] = fVar2 * *(float *)(iVar6 + 0x38) +

                  fVar3 * *(float *)(iVar6 + 0x48) + fVar1 * *(float *)(iVar6 + 0x28) +

                  *(float *)(iVar6 + 0x58);

      pfVar9[3] = 0.0;

      pfVar9 = pfVar9 + 4;

      pfVar12 = pfVar12 + 4;

    } while (iVar13 != 0);

  }

  local_bc = param_3;

  local_c0 = param_2;

  if (0 < (int)uVar7) {

    pfVar12 = local_90;

    pfVar9 = (float *)(iVar5 + 0x1c);

    local_124 = uVar7;

    do {

      fVar1 = *pfVar9 + *(float *)(iVar4 + 0xc);

      FUN_006f7820(pfVar12,&local_110,param_1 + 0xc,&local_b0);

      if (local_a0 < fVar1 + *(float *)(param_4 + 8)) {

        fVar2 = *(float *)(iVar4 + 0xc) - local_a0;

        local_d0 = local_b0;

        local_c8 = local_a8;

        local_e0 = local_b0 * fVar2 + *pfVar12;

        local_c4 = local_a4;

        local_cc = local_ac;

        local_dc = local_ac * fVar2 + pfVar12[1];

        local_d8 = local_a8 * fVar2 + pfVar12[2];

        local_d4 = local_a0 - fVar1;

        (**(code **)(*param_5 + 4))(&local_e0);

      }

      pfVar12 = pfVar12 + 4;

      pfVar9 = pfVar9 + 4;

      local_124 = local_124 - 1;

    } while (local_124 != 0);

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar8 = rdtsc();

    DAT_00bc5644[1] = (int)uVar8;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
