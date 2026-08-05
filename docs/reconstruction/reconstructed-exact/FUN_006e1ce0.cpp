// =============================================================================
// FUN_006e1ce0
// -----------------------------------------------------------------------------
// Stable ID: aa_006e1ce0
// Address:   0x006e1ce0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e1ce0 @ 0x006e1ce0
// Stable ID: aa_006e1ce0
// Embedded strings (evidence for future rename):
//   - "TtSphereTriangle"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~127 non-empty decompiler lines.
//  - Control keywords: if×7, return×1.
//  - Notable callees: rdtsc×2, FUN_005b3370, FUN_006e1ce0, FUN_006f7820.
//  - Strings: "TtSphereTriangle".
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

void __thiscall FUN_006e1ce0(int param_1,int *param_2,int *param_3,int param_4,int *param_5)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int *piVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  uint64_t uVar9;

  uint16_t uVar10;

  float *pfVar11;

  float *pfVar12;

  float local_60;

  float local_5c;

  float local_58;

  float local_54;

  float local_50;

  float local_40;

  float local_3c;

  float local_38;

  uint32_t /* width from decompiler */ local_34;

  float local_30;

  float local_2c;

  float local_28;

  uint32_t /* width from decompiler */ local_24;

  float local_20;

  float local_1c;

  float local_18;

  uint32_t /* width from decompiler */ local_14;

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TtSphereTriangle";

    uVar9 = rdtsc();

    DAT_00bc5644[1] = (int)uVar9;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  piVar4 = (int *)*param_5;

  if (piVar4[1] == (piVar4[2] & 0x7fffffffU)) {

    FUN_005b3370(piVar4,0x30);

  }

  pfVar12 = (float *)(piVar4[1] * 0x30 + *piVar4);

  piVar4[1] = piVar4[1] + 1;

  iVar5 = *param_2;

  iVar6 = param_2[2];

  iVar7 = *param_3;

  fVar1 = *(float *)(iVar7 + 0x10);

  iVar8 = param_3[2];

  fVar2 = *(float *)(iVar7 + 0x14);

  fVar3 = *(float *)(iVar7 + 0x18);

  pfVar11 = (float *)(iVar8 + 0x20);

  local_40 = fVar2 * *(float *)(iVar8 + 0x30) + fVar3 * *(float *)(iVar8 + 0x40) + fVar1 * *pfVar11

             + *(float *)(iVar8 + 0x50);

  local_3c = fVar2 * *(float *)(iVar8 + 0x34) +

             fVar3 * *(float *)(iVar8 + 0x44) + fVar1 * *(float *)(iVar8 + 0x24) +

             *(float *)(iVar8 + 0x54);

  local_38 = fVar2 * *(float *)(iVar8 + 0x38) +

             fVar3 * *(float *)(iVar8 + 0x48) + fVar1 * *(float *)(iVar8 + 0x28) +

             *(float *)(iVar8 + 0x58);

  local_34 = 0;

  fVar1 = *(float *)(iVar7 + 0x20);

  fVar2 = *(float *)(iVar7 + 0x24);

  fVar3 = *(float *)(iVar7 + 0x28);

  local_30 = fVar2 * *(float *)(iVar8 + 0x30) + fVar3 * *(float *)(iVar8 + 0x40) + fVar1 * *pfVar11

             + *(float *)(iVar8 + 0x50);

  local_2c = fVar2 * *(float *)(iVar8 + 0x34) +

             fVar3 * *(float *)(iVar8 + 0x44) + fVar1 * *(float *)(iVar8 + 0x24) +

             *(float *)(iVar8 + 0x54);

  local_28 = fVar2 * *(float *)(iVar8 + 0x38) +

             fVar3 * *(float *)(iVar8 + 0x48) + fVar1 * *(float *)(iVar8 + 0x28) +

             *(float *)(iVar8 + 0x58);

  local_24 = 0;

  fVar1 = *(float *)(iVar7 + 0x30);

  fVar2 = *(float *)(iVar7 + 0x34);

  fVar3 = *(float *)(iVar7 + 0x38);

  local_20 = fVar2 * *(float *)(iVar8 + 0x30) + fVar3 * *(float *)(iVar8 + 0x40) + fVar1 * *pfVar11

             + *(float *)(iVar8 + 0x50);

  local_1c = fVar2 * *(float *)(iVar8 + 0x34) +

             fVar3 * *(float *)(iVar8 + 0x44) + fVar1 * *(float *)(iVar8 + 0x24) +

             *(float *)(iVar8 + 0x54);

  local_18 = fVar2 * *(float *)(iVar8 + 0x38) +

             fVar3 * *(float *)(iVar8 + 0x48) + fVar1 * *(float *)(iVar8 + 0x28) +

             *(float *)(iVar8 + 0x58);

  local_14 = 0;

  FUN_006f7820((float *)(iVar6 + 0x50),&local_40,param_1 + 0x10,&local_60);

  fVar1 = *(float *)(iVar5 + 0xc) + *(float *)(iVar7 + 0xc);

  if (fVar1 + *(float *)(param_4 + 8) <= local_50) {

    *(int *)(*param_5 + 4) = *(int *)(*param_5 + 4) + -1;

    if (*(short *)(param_1 + 0xc) != -1) {

      (**(code **)(**(int **)(param_1 + 8) + 8))(*(short *)(param_1 + 0xc));

      *(uint16_t *)(param_1 + 0xc) = 0xffff;

    }

  }

  else {

    fVar2 = *(float *)(iVar7 + 0xc) - local_50;

    *pfVar12 = *(float *)(iVar6 + 0x50);

    pfVar12[1] = *(float *)(iVar6 + 0x54);

    pfVar12[2] = *(float *)(iVar6 + 0x58);

    pfVar12[3] = *(float *)(iVar6 + 0x5c);

    *pfVar12 = local_60 * fVar2 + *pfVar12;

    pfVar12[1] = local_5c * fVar2 + pfVar12[1];

    pfVar12[2] = local_58 * fVar2 + pfVar12[2];

    pfVar12[3] = local_54 * fVar2 + pfVar12[3];

    pfVar12[4] = local_60;

    pfVar12[5] = local_5c;

    pfVar12[6] = local_58;

    pfVar12[7] = local_54;

    pfVar12[3] = local_50 - fVar1;

    if (*(short *)(param_1 + 0xc) == -1) {

      uVar10 = (**(code **)(**(int **)(param_1 + 8) + 4))(param_2,param_3,param_4,pfVar12);

      *(uint16_t *)(param_1 + 0xc) = uVar10;

    }

    if (*(short *)(param_1 + 0xc) == -1) {

      *(int *)(*param_5 + 4) = *(int *)(*param_5 + 4) + -1;

    }

    else {

      *(short *)(pfVar12 + 8) = *(short *)(param_1 + 0xc);

    }

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar9 = rdtsc();

    DAT_00bc5644[1] = (int)uVar9;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
