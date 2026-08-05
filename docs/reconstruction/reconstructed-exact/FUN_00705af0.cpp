// =============================================================================
// FUN_00705af0
// -----------------------------------------------------------------------------
// Stable ID: aa_00705af0
// Address:   0x00705af0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00705af0 @ 0x00705af0
// Stable ID: aa_00705af0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~270 non-empty decompiler lines.
//  - Control keywords: return×30, if×18, while×11, do×10, switch×1.
//  - Notable callees: FUN_00702f90×20, FUN_006a3db0, FUN_007031b0, FUN_00705af0, floor.
//  - Return sites: 30.

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



uint32_t /* width from decompiler */ FUN_00705af0(uint32_t /* width from decompiler */ *param_1,float param_2,float *param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  float fVar4;

  int iVar5;

  int iStack_4;

  

  puVar1 = param_1;

  switch(param_2) {

  case 4.2039e-45:

    *param_3 = (float)param_1[2];

    return 0;

  case 5.60519e-45:

    fVar4 = *param_3;

    if ((int)fVar4 < 0) {

      fVar4 = 0.0;

    }

    else if (10 < (int)fVar4) {

      fVar4 = 1.4013e-44;

    }

    uVar3 = *(uint32_t /* width from decompiler */ *)(*(int *)*param_1 + 0x78 + (int)fVar4 * 4);

    param_1[0x3a] = uVar3;

    param_1[0x3b] = uVar3;

    puVar1 = param_1 + 1;

    param_1 = (uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(*(int *)*param_1 + 0x4c + (int)fVar4 * 4);

    FUN_00702f90(*puVar1,6,&param_1);

    return 0;

  default:

    FUN_007031b0(s_Unknown_nb_ctl_request__00af6674,param_2);

    return 0xffffffff;

  case 8.40779e-45:

    FUN_00702f90(param_1,4,param_3);

    return 0;

  case 1.12104e-44:

    FUN_00702f90(param_1[1],8,param_3);

    return 0;

  case 1.26117e-44:

    FUN_00702f90(param_1[1],9,param_3);

    return 0;

  case 1.4013e-44:

    fVar4 = *param_3;

    param_1[0x3a] = fVar4;

    param_1[0x3b] = fVar4;

    return 0;

  case 1.68156e-44:

    param_1[0x31] = *param_3;

    FUN_00702f90(param_1[1],0xc,param_3);

    return 0;

  case 1.82169e-44:

    *param_3 = (float)param_1[0x31];

    return 0;

  case 1.96182e-44:

    param_2 = *param_3 + (float)_DAT_00a0f130;

    param_1[0x30] = *param_3;

    if (DAT_00a110d8 < param_2) {

      param_2 = 10.0;

    }

    floor((double)(*param_3 + (float)_DAT_00aaa5e0));

    param_1 = (uint32_t /* width from decompiler */ *)FUN_006a3db0();

    if (10 < (int)param_1) {

      param_1 = (uint32_t /* width from decompiler */ *)0xa;

    }

    FUN_00702f90(puVar1[1],0xe,&param_2);

    FUN_00702f90(puVar1,4,&param_1);

    return 0;

  case 2.24208e-44:

    FUN_00702f90(param_1[1],0x10,param_3);

    fVar4 = *param_3;

    puVar1[0x3c] = fVar4;

    if ((int)fVar4 < 1) {

      puVar1[0x3c] = 1;

      return 0;

    }

    break;

  case 2.38221e-44:

    *param_3 = (float)param_1[0x3c];

    return 0;

  case 2.52234e-44:

    param_2 = 1.4013e-44;

    fVar4 = *param_3;

    while( true ) {

      FUN_00702f90(puVar1,4,&param_2);

      FUN_00702f90(puVar1,0x13,&param_1);

      if ((int)param_1 <= (int)fVar4) break;

      param_2 = (float)((int)param_2 + -1);

      if ((int)param_2 < 0) {

        return 0;

      }

    }

    break;

  case 2.66247e-44:

    FUN_00702f90(param_1[1],param_2,param_3);

    iVar5 = *(int *)(puVar1[0x39] + puVar1[0x3a] * 4);

    if (iVar5 != 0) {

      *param_3 = (float)((int)*param_3 + (*(int *)(iVar5 + 0x3c) * puVar1[0x3d]) / (int)puVar1[2]);

      return 0;

    }

    *param_3 = (float)((int)*param_3 + (int)(puVar1[0x3d] << 2) / (int)puVar1[2]);

    return 0;

  case 3.36312e-44:

    fVar4 = *param_3;

    param_1[0x3d] = fVar4;

    puVar1 = param_1 + 1;

    param_1 = (uint32_t /* width from decompiler */ *)((int)fVar4 >> 1);

    FUN_00702f90(*puVar1,0x18,&param_1);

    return 0;

  case 3.50325e-44:

    *param_3 = (float)param_1[0x3d];

    return 0;

  case 3.64338e-44:

    param_1[9] = 1;

    iVar5 = 0;

    if (0 < (int)param_1[7]) {

      do {

        iVar2 = iVar5 + 1;

        *(float *)(param_1[0x22] + iVar5 * 4) =

             ((float)iVar2 * (float)_DAT_00a0f190) / (float)(param_1[7] + 1);

        iVar5 = iVar2;

      } while (iVar2 < (int)param_1[7]);

    }

    if (0 < (int)param_1[7]) {

      iVar5 = 0;

      do {

        *(uint32_t /* width from decompiler */ *)(param_1[0x2d] + iVar5 * 4) = 0;

        *(uint32_t /* width from decompiler */ *)(param_1[0x2c] + iVar5 * 4) = 0;

        *(uint32_t /* width from decompiler */ *)(param_1[0x2e] + iVar5 * 4) = 0;

        iVar5 = iVar5 + 1;

      } while (iVar5 < (int)param_1[7]);

    }

    iVar5 = 0;

    if (0 < (int)param_1[8]) {

      do {

        *(uint32_t /* width from decompiler */ *)(param_1[0x18] + iVar5 * 4) = 0;

        iVar5 = iVar5 + 1;

      } while (iVar5 < (int)param_1[8]);

    }

    iVar5 = 0xc;

    do {

      *(uint32_t /* width from decompiler */ *)(iVar5 + -0xc + param_1[0x17]) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar5 + -0xc + param_1[0x16]) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar5 + -0xc + param_1[0x15]) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar5 + -0xc + param_1[0x14]) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1[0x17] + -8 + iVar5) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar5 + -8 + param_1[0x16]) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1[0x15] + -8 + iVar5) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1[0x14] + -8 + iVar5) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar5 + -4 + param_1[0x17]) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar5 + -4 + param_1[0x16]) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar5 + -4 + param_1[0x15]) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar5 + -4 + param_1[0x14]) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar5 + param_1[0x17]) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar5 + param_1[0x16]) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar5 + param_1[0x15]) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar5 + param_1[0x14]) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar5 + 4 + param_1[0x17]) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar5 + 4 + param_1[0x16]) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar5 + 4 + param_1[0x15]) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar5 + 4 + param_1[0x14]) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar5 + 8 + param_1[0x17]) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar5 + 8 + param_1[0x16]) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar5 + 8 + param_1[0x15]) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar5 + 8 + param_1[0x14]) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0xc + param_1[0x17]) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0xc + param_1[0x16]) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0xc + param_1[0x15]) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0xc + param_1[0x14]) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0x10 + param_1[0x17]) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0x10 + param_1[0x16]) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0x10 + param_1[0x15]) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0x10 + param_1[0x14]) = 0;

      iVar5 = iVar5 + 0x20;

    } while (iVar5 < 0x10c);

    return 0;

  case 4.06377e-44:

    *param_3 = (float)param_1[0x37];

    break;

  case 4.2039e-44:

    param_1[0x36] = *param_3;

    FUN_00702f90(param_1[1],0x1e,param_3);

    return 0;

  case 4.34403e-44:

    *param_3 = (float)param_1[0x36];

    return 0;

  case 4.48416e-44:

    param_1[0x32] = *param_3;

    param_1[0x31] = 1;

    FUN_00702f90(param_1[1],0xc,param_1 + 0x31);

    param_1 = (uint32_t /* width from decompiler */ *)0xa;

    fVar4 = *param_3;

    do {

      FUN_00702f90(puVar1,4,&param_1);

      FUN_00702f90(puVar1,0x13,&iStack_4);

      if (iStack_4 <= (int)fVar4) break;

      param_1 = (uint32_t /* width from decompiler */ *)((int)param_1 + -1);

    } while (-1 < (int)param_1);

    param_2 = (float)(int)param_1;

    if ((float)(int)param_1 < g_flZero) {

      param_2 = 0.0;

    }

    FUN_00702f90(puVar1,0xe,&param_2);

    puVar1[0x35] = 0;

    puVar1[0x33] = 0;

    puVar1[0x34] = 0;

    return 0;

  case 4.62428e-44:

    *param_3 = (float)param_1[0x32];

    return 0;

  case 4.76441e-44:

    FUN_00702f90(param_1[1],0x22,param_3);

    return 0;

  case 4.90454e-44:

    FUN_00702f90(param_1[1],0x23,param_3);

    return 0;

  case 5.04467e-44:

    param_1[0x38] = *param_3;

    FUN_00702f90(param_1[1],0x24,&param_3);

    return 0;

  case 5.1848e-44:

    *param_3 = (float)param_1[0x38];

    return 0;

  case 1.4013e-43:

    iVar5 = 0;

    if (0 < (int)param_1[5]) {

      do {

        param_3[iVar5] = *(float *)(param_1[0x2f] + iVar5 * 4);

        iVar5 = iVar5 + 1;

      } while (iVar5 < (int)param_1[5]);

      return 0;

    }

    break;

  case 1.41531e-43:

    iVar5 = 0;

    if (0 < (int)param_1[2]) {

      do {

        param_3[iVar5] = 0.0;

        iVar5 = iVar5 + 1;

      } while (iVar5 < (int)param_1[2]);

    }

    iVar5 = 0;

    if (0 < (int)param_1[3]) {

      do {

        fVar4 = *(float *)(param_1[0x19] + iVar5 * 4);

        iVar5 = iVar5 + 1;

        param_3[iVar5 * 2 + -2] = fVar4 + fVar4;

      } while (iVar5 < (int)param_1[3]);

      return 0;

    }

    break;

  case 1.42932e-43:

    iVar5 = 0;

    if (0 < (int)param_1[2]) {

      do {

        param_3[iVar5] = 0.0;

        iVar5 = iVar5 + 1;

      } while (iVar5 < (int)param_1[2]);

    }

    iVar5 = 0;

    if (0 < (int)param_1[3]) {

      do {

        fVar4 = *(float *)(param_1[0x19] + iVar5 * 4);

        iVar5 = iVar5 + 1;

        param_3[iVar5 * 2 + -2] = fVar4 + fVar4;

      } while (iVar5 < (int)param_1[3]);

      return 0;

    }

  }

  return 0;

}
