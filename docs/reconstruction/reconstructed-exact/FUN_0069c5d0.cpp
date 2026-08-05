// =============================================================================
// FUN_0069c5d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0069c5d0
// Address:   0x0069c5d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0069c5d0 @ 0x0069c5d0
// Stable ID: aa_0069c5d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~147 non-empty decompiler lines.
//  - Control keywords: if×4, for×1, do×1, while×1, return×1.
//  - Notable callees: SQRT×2, FUN_0068ec20, FUN_0069a330, FUN_0069bd50, FUN_0069c5d0, FUN_0069fec0, FUN_006a1be0.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall

FUN_0069c5d0(uint32_t /* width from decompiler */ param_1,int *param_2,float param_3,int param_4,float *param_5,

            uint32_t /* width from decompiler */ param_6,float *param_7,float *param_8,uint32_t /* width from decompiler */ param_9,uint32_t /* width from decompiler */ param_10,

            uint32_t /* width from decompiler */ param_11)



{

  float fVar1;

  int iVar2;

  float *pfVar3;

  float10 fVar4;

  float local_bc;

  float local_b8;

  float local_b4;

  float local_b0;

  float local_ac;

  float local_a8;

  float local_a4;

  float local_a0;

  float local_9c;

  float local_98;

  float local_94;

  float local_90;

  float local_8c;

  float local_88;

  float local_84;

  float local_80;

  float local_7c;

  float local_74 [11];

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ local_40;

  float local_3c;

  float local_38;

  float local_34;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  

  iVar2 = *(int *)(DAT_00d08ef0 + param_4 * 4);

  local_88 = 0.0;

  local_8c = 0.0;

  local_90 = 0.0;

  local_7c = 0.0;

  local_80 = 0.0;

  local_84 = 0.0;

  local_74[0] = 1.0;

  local_74[1] = 0.0;

  local_74[2] = 0.0;

  local_74[3] = 0.0;

  local_74[4] = 1.0;

  local_74[5] = 0.0;

  local_74[6] = 0.0;

  local_74[7] = 0.0;

  local_74[8] = 1.0;

  local_40 = 0;

  local_44 = 0;

  local_48 = 0;

  local_34 = 0.0;

  local_38 = 0.0;

  local_3c = 0.0;

  local_2c = 0x3f800000;

  local_28 = 0;

  local_24 = 0;

  local_20 = 0;

  local_1c = 0x3f800000;

  local_18 = 0;

  local_14 = 0;

  local_10 = 0;

  local_c = 0x3f800000;

  fVar4 = (float10)FUN_0069fec0(param_6);

  local_a4 = (float)((fVar4 * (float10)param_3) / (float10)*(int *)(iVar2 + 4));

  fVar4 = (float10)FUN_006a1be0(0xc3340000,0x43340000);

  local_94 = (float)fVar4;

  local_bc = *param_7 * *param_8 + param_7[2] * param_8[2] + param_7[1] * param_8[1];

  local_b8 = param_7[5] * param_8[2] + param_7[3] * *param_8 + param_7[4] * param_8[1];

  local_b4 = param_7[8] * param_8[2] + param_7[6] * *param_8 + param_7[7] * param_8[1];

  local_84 = *param_5;

  local_80 = param_5[1];

  local_7c = param_5[2];

  pfVar3 = local_74;

  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {

    *pfVar3 = *param_7;

    param_7 = param_7 + 1;

    pfVar3 = pfVar3 + 1;

  }

  FUN_0069a330(local_94,local_bc,local_b8,local_b4);

  FUN_0068ec20(0x42700000);

  local_90 = local_74[0] * _DAT_00af55b8 + local_74[3] * _DAT_00af55bc + local_74[6] * _DAT_00af55c0

  ;

  local_8c = local_74[1] * _DAT_00af55b8 + local_74[4] * _DAT_00af55bc + local_74[7] * _DAT_00af55c0

  ;

  local_88 = local_74[2] * _DAT_00af55b8 + local_74[5] * _DAT_00af55bc + local_74[8] * _DAT_00af55c0

  ;

  local_98 = local_88 * local_a4;

  local_3c = local_84 + local_90 * local_a4;

  local_38 = local_80 + local_8c * local_a4;

  local_34 = local_7c + local_98;

  local_bc = local_3c - local_84;

  local_b8 = local_38 - local_80;

  local_b4 = local_34 - local_7c;

  local_a4 = g_flOne / SQRT(local_bc * local_bc + local_b8 * local_b8 + local_b4 * local_b4);

  local_bc = local_bc * local_a4;

  local_b8 = local_b8 * local_a4;

  local_b4 = local_b4 * local_a4;

  local_a8 = local_b4;

  local_b0 = local_bc;

  local_ac = local_b8;

  if ((param_2 != (int *)0x0) && (param_2[7] != 0)) {

    iVar2 = param_2[6];

    local_b0 = *(float *)(iVar2 + 0xc);

    local_ac = *(float *)(iVar2 + 0x10);

    local_a8 = *(float *)(iVar2 + 0x14);

    if (*(int *)(DAT_00d08ebc + 0x28) != 0) {

      iVar2 = 0;

      do {

        if (*(int *)(DAT_00d08ebc + 0x28) <= iVar2) {

          if (param_2 != (int *)0x0) {

            iVar2 = param_2[6];

            local_b0 = *(float *)(iVar2 + 0xc);

            local_ac = *(float *)(iVar2 + 0x10);

            local_a8 = *(float *)(iVar2 + 0x14);

          }

          break;

        }

        param_2 = (int *)*param_2;

        iVar2 = iVar2 + 1;

      } while (param_2 != (int *)0x0);

    }

    local_a0 = local_3c - local_b0;

    local_9c = local_38 - local_ac;

    local_98 = local_34 - local_a8;

    local_a8 = local_98;

    local_b0 = local_a0;

    local_ac = local_9c;

  }

  fVar1 = g_flOne / SQRT(local_b0 * local_b0 + local_a8 * local_a8 + local_ac * local_ac);

  local_b0 = local_b0 * fVar1;

  local_ac = local_ac * fVar1;

  local_a8 = local_a8 * fVar1;

  FUN_0069bd50(&local_3c,param_6,param_1,&local_bc,&local_b0,param_10,param_11,param_9);

  return;

}
