// =============================================================================
// FUN_006e65d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006e65d0
// Address:   0x006e65d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e65d0 @ 0x006e65d0
// Stable ID: aa_006e65d0
// Embedded strings (evidence for future rename):
//   - "LtHeightField"
//   - "StGetSpheres"
//   - "StCastSpheres"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~175 non-empty decompiler lines.
//  - Control keywords: if×9, do×1, while×1, goto×1, return×1.
//  - Notable callees: rdtsc×4, FUN_0063a3f0, FUN_006e5dd0, FUN_006e65d0.
//  - Strings: "LtHeightField"; "StGetSpheres"; "StCastSpheres".
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

void FUN_006e65d0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,int param_3,uint32_t /* width from decompiler */ param_4,int param_5

                 )



{

  int *piVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  int *piVar5;

  int iVar6;

  uint64_t uVar7;

  int *piVar8;

  int iVar9;

  int iVar10;

  float *pfVar11;

  uint uVar12;

  int unaff_EBX;

  float fStack_10c;

  uint8_t local_108 [4];

  uint32_t /* width from decompiler */ uStack_104;

  int *piStack_100;

  int iStack_fc;

  float local_f8;

  float fStack_f4;

  float fStack_f0;

  float fStack_ec;

  float fStack_e8;

  float fStack_e4;

  float local_e0;

  float fStack_d8;

  float fStack_d4;

  float fStack_d0;

  float fStack_c8;

  float fStack_c4;

  float fStack_c0;

  float fStack_b8;

  float fStack_b4;

  float fStack_b0;

  float fStack_a8;

  float fStack_a4;

  float fStack_a0;

  uint32_t /* width from decompiler */ uStack_9c;

  float fStack_98;

  float fStack_94;

  float fStack_90;

  uint32_t /* width from decompiler */ uStack_8c;

  uint32_t /* width from decompiler */ uStack_84;

  float fStack_78;

  uint32_t /* width from decompiler */ uStack_74;

  undefined **ppuStack_68;

  uint32_t /* width from decompiler */ uStack_64;

  float fStack_58;

  float fStack_54;

  float fStack_50;

  uint32_t /* width from decompiler */ uStack_4c;

  float fStack_48;

  uint32_t /* width from decompiler */ uStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ *puStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "LtHeightField";

    uVar7 = rdtsc();

    DAT_00bc5644[1] = (int)uVar7;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  if (param_5 != 0) {

    FUN_006e5dd0(param_1,param_2,param_3,param_5);

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "StGetSpheres";

    uVar7 = rdtsc();

    DAT_00bc5644[1] = (int)uVar7;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  piVar5 = (int *)*param_1;

  local_f8 = (float)*param_2;

  FUN_0063a3f0(param_2[2] + 0x20,param_1[2] + 0x20);

  (**(code **)(*piVar5 + 0x28))(local_108);

  piVar8 = DAT_00b05060;

  piVar1 = DAT_00b05060 + 3;

  local_f8 = fStack_10c;

  iVar9 = (int)fStack_10c * 0x10;

  if (*piVar1 < iVar9) {

    iVar10 = (**(code **)(*DAT_00b05060 + 0x24))(iVar9);

  }

  else {

    iVar10 = DAT_00b05060[2];

    DAT_00b05060[2] = iVar10 + iVar9;

    piVar8[3] = *piVar1 + (int)fStack_10c * -0x10;

  }

  fVar2 = *(float *)(param_3 + 0x10);

  fVar3 = *(float *)(param_3 + 0x14);

  iVar9 = param_2[2];

  fVar4 = *(float *)(param_3 + 0x18);

  fStack_f4 = fVar2 * *(float *)(iVar9 + 0x20) +

              fVar3 * *(float *)(iVar9 + 0x24) + fVar4 * *(float *)(iVar9 + 0x28);

  fStack_f0 = fVar2 * *(float *)(iVar9 + 0x30) +

              fVar3 * *(float *)(iVar9 + 0x34) + fVar4 * *(float *)(iVar9 + 0x38);

  fStack_ec = fVar2 * *(float *)(iVar9 + 0x40) +

              fVar3 * *(float *)(iVar9 + 0x44) + fVar4 * *(float *)(iVar9 + 0x48);

  pfVar11 = (float *)(**(code **)(*piVar5 + 0x2c))(iVar10);

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "StCastSpheres";

    uVar7 = rdtsc();

    uStack_104 = (uint32_t /* width from decompiler */)uVar7;

    DAT_00bc5644[1] = uStack_104;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  uStack_74 = *(uint32_t /* width from decompiler */ *)(param_3 + 0x20);

  uStack_38 = *(uint32_t /* width from decompiler */ *)(param_3 + 0x10);

  uStack_34 = *(uint32_t /* width from decompiler */ *)(param_3 + 0x14);

  uStack_30 = *(uint32_t /* width from decompiler */ *)(param_3 + 0x18);

  uStack_2c = *(uint32_t /* width from decompiler */ *)(param_3 + 0x1c);

  uStack_84 = 0;

  uStack_64 = 0x3f800000;

  ppuStack_68 = &PTR_FUN_00a0e790;

  puStack_28 = param_1;

  uStack_24 = param_4;

  iVar9 = iStack_fc;

  if (0 < iStack_fc) {

    do {

      fVar2 = *pfVar11;

      fVar3 = pfVar11[1];

      iVar6 = param_1[2];

      fVar4 = pfVar11[2];

      fStack_78 = pfVar11[3];

      uStack_9c = 0;

      uStack_8c = 0;

      fStack_a8 = fStack_e8 * fVar2 + fStack_d8 * fVar3 + fStack_c8 * fVar4 + fStack_b8;

      fStack_a4 = fStack_e4 * fVar2 + fStack_d4 * fVar3 + fStack_c4 * fVar4 + fStack_b4;

      fStack_a0 = local_e0 * fVar2 + fStack_d0 * fVar3 + fStack_c0 * fVar4 + fStack_b0;

      fStack_98 = local_f8 + fStack_a8;

      fStack_94 = fStack_f4 + fStack_a4;

      fStack_90 = fStack_f0 + fStack_a0;

      fVar2 = *pfVar11;

      fVar3 = pfVar11[1];

      fVar4 = pfVar11[2];

      fStack_58 = fVar2 * *(float *)(iVar6 + 0x20) +

                  fVar3 * *(float *)(iVar6 + 0x30) + fVar4 * *(float *)(iVar6 + 0x40) +

                  *(float *)(iVar6 + 0x50);

      fStack_54 = fVar2 * *(float *)(iVar6 + 0x24) +

                  fVar3 * *(float *)(iVar6 + 0x34) + fVar4 * *(float *)(iVar6 + 0x44) +

                  *(float *)(iVar6 + 0x54);

      fStack_50 = fVar2 * *(float *)(iVar6 + 0x28) +

                  fVar3 * *(float *)(iVar6 + 0x38) + fVar4 * *(float *)(iVar6 + 0x48) +

                  *(float *)(iVar6 + 0x58);

      uStack_4c = 0;

      fStack_48 = fStack_78;

      (**(code **)(*piStack_100 + 0x2c))(&fStack_a8,param_2,&ppuStack_68);

      pfVar11 = pfVar11 + 4;

      iVar9 = iVar9 + -1;

    } while (iVar9 != 0);

  }

  piVar1 = DAT_00b05060;

  uVar12 = iVar10 + 0xfU & 0xfffffff0;

  if (uVar12 != 0) {

    if ((unaff_EBX == DAT_00b05060[5]) || (DAT_00b05060[5] == 0)) {

      (**(code **)(*DAT_00b05060 + 0x28))(unaff_EBX,uVar12);

      goto LAB_006e6962;

    }

  }

  piVar5 = DAT_00b05060 + 3;

  DAT_00b05060[2] = DAT_00b05060[2] - uVar12;

  piVar1[3] = *piVar5 + uVar12;

LAB_006e6962:

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d282c;

    uVar7 = rdtsc();

    DAT_00bc5644[1] = (int)uVar7;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
