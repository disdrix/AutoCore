// =============================================================================
// FUN_0053eec0
// -----------------------------------------------------------------------------
// Stable ID: aa_0053eec0
// Address:   0x0053eec0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0053eec0 @ 0x0053eec0
// Stable ID: aa_0053eec0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~125 non-empty decompiler lines.
//  - Control keywords: if×15, return×3.
//  - Notable callees: FUN_0053e020×5, SQRT×3, CVOGPhysics_ApplyImpulseVector, FUN_00404dc0, FUN_0040d040, FUN_0040d2a0, FUN_005070b0, FUN_005070d0.
//  - Return sites: 3.

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



void __thiscall

FUN_0053eec0(int *param_1,float *param_2,uint32_t /* width from decompiler */ *param_3,float *param_4,uint32_t /* width from decompiler */ *param_5,

            float param_6)



{

  uint32_t /* width from decompiler */ *puVar1;

  float fVar2;

  bool bVar3;

  char *pcVar4;

  int iVar5;

  float *pfVar6;

  uint8_t local_21;

  float local_20;

  float local_1c;

  float local_18;

  

  iVar5 = param_1[2];

  if (((iVar5 != 0) && (fVar2 = *(float *)(*(int *)(iVar5 + 0x3c) + 0x2c), fVar2 != 0.0)) &&

     (g_flOne / fVar2 != 0.0)) {

    if ((*(char *)(iVar5 + 0x40) == '\0') || (*(int *)(iVar5 + 8) == 0)) {

      bVar3 = true;

    }

    else {

      bVar3 = false;

    }

    if (bVar3) {

      pcVar4 = (char *)FUN_005070b0(&local_21);

      if (*pcVar4 == '\0') {

        FUN_005070d0();

      }

      param_1[5] = g_dwClientTickMs;

      *(uint8_t *)(param_1 + 4) = 1;

      if (param_1[10] == 0) {

        iVar5 = FUN_0053e020();

        param_1[10] = iVar5;

      }

      pfVar6 = (float *)param_1[10];

      *pfVar6 = *param_2;

      pfVar6[1] = param_2[1];

      pfVar6[2] = param_2[2];

      pfVar6[3] = param_2[3];

      if (DAT_00a0f718 <=

          SQRT(param_4[2] * param_4[2] + param_4[1] * param_4[1] + *param_4 * *param_4)) {

        if (param_1[10] == 0) {

          iVar5 = FUN_0053e020();

          param_1[10] = iVar5;

        }

        iVar5 = param_1[10];

        *(float *)(iVar5 + 0x20) = *param_4;

        *(float *)(iVar5 + 0x24) = param_4[1];

        *(float *)(iVar5 + 0x28) = param_4[2];

        *(float *)(iVar5 + 0x2c) = param_4[3];

      }

      else {

        if (param_1[10] == 0) {

          iVar5 = FUN_0053e020();

          param_1[10] = iVar5;

        }

        iVar5 = param_1[10];

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x20) = DAT_00b04610;

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x24) = DAT_00b04614;

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x28) = DAT_00b04618;

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x2c) = DAT_00b0461c;

      }

      pcVar4 = (char *)FUN_00568100(&local_21);

      if (*pcVar4 != '\0') {

        if (param_1[10] == 0) {

          iVar5 = FUN_0053e020();

          param_1[10] = iVar5;

        }

        iVar5 = param_1[10];

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x10) = *param_3;

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x14) = param_3[1];

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x18) = param_3[2];

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x1c) = param_3[3];

      }

      if (param_1[10] == 0) {

        iVar5 = FUN_0053e020();

        param_1[10] = iVar5;

      }

      iVar5 = param_1[10];

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0x30) = *param_5;

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0x34) = param_5[1];

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0x38) = param_5[2];

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0x3c) = param_5[3];

      local_20 = *param_2;

      local_1c = param_2[1];

      local_18 = param_2[2];

      if (param_1[2] == 0) {

        pfVar6 = (float *)(*(int *)(param_1[1] + 4) + 0x84 + (int)param_1);

      }

      else {

        pfVar6 = (float *)(*(int *)(param_1[2] + 0x3c) + 0xb0);

      }

      if (DAT_009d000c <

          SQRT((local_20 - *pfVar6) * (local_20 - *pfVar6) +

               (local_1c - pfVar6[1]) * (local_1c - pfVar6[1]) +

               (local_18 - pfVar6[2]) * (local_18 - pfVar6[2]))) {

        (**(code **)(*param_1 + 0x40))();

        FUN_0040d2a0(param_2);

        CVOGPhysics_ApplyImpulseVector(param_4);

        FUN_00404dc0(param_3);

        FUN_0040d040(param_5);

      }

      if (param_6 == g_flZero) {

        return;

      }

      FUN_0053eb90(0,param_6);

      return;

    }

  }

  if (_DAT_009d0010 < SQRT(*param_2 * *param_2 + param_2[2] * param_2[2] + param_2[1] * param_2[1]))

  {

    pfVar6 = (float *)(*(int *)(param_1[1] + 4) + 0x84 + (int)param_1);

    *pfVar6 = *param_2;

    pfVar6[1] = param_2[1];

    pfVar6[2] = param_2[2];

    pfVar6[3] = param_2[3];

    puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1[1] + 4) + 0x94 + (int)param_1);

    *puVar1 = *param_3;

    puVar1[1] = param_3[1];

    puVar1[2] = param_3[2];

    puVar1[3] = param_3[3];

  }

  return;

}
