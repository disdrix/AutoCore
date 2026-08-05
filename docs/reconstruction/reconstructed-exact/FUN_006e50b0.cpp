// =============================================================================
// FUN_006e50b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006e50b0
// Address:   0x006e50b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e50b0 @ 0x006e50b0
// Stable ID: aa_006e50b0
// Embedded strings (evidence for future rename):
//   - "LtGsk"
//   - "StGsk"
//   - "StTim"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~120 non-empty decompiler lines.
//  - Control keywords: if×9, goto×2, return×1.
//  - Notable callees: rdtsc×4, FUN_005d6ae0, FUN_0063a3f0, FUN_006e50b0, FUN_006f5630, FUN_006f5de0, FUN_006f60b0, FUN_006fb6d0.
//  - Strings: "LtGsk"; "StGsk"; "StTim".
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

void __thiscall FUN_006e50b0(int param_1,int *param_2,int *param_3,int param_4,uint32_t /* width from decompiler */ param_5)



{

  int iVar1;

  int iVar2;

  float *pfVar3;

  float *pfVar4;

  uint64_t uVar5;

  float fVar6;

  int iVar7;

  float local_230;

  float local_22c;

  float local_228;

  float local_224;

  float local_220;

  float local_21c;

  float local_218;

  float local_214;

  float local_210;

  float local_200;

  float local_1fc;

  float local_1f8;

  uint32_t /* width from decompiler */ local_1f0;

  uint32_t /* width from decompiler */ local_1ec;

  uint32_t /* width from decompiler */ local_1e8;

  uint32_t /* width from decompiler */ local_1e4;

  float local_1e0 [4];

  float local_1d0;

  float local_1cc;

  float local_1c8;

  float local_1c0;

  float local_1bc;

  float local_1b8;

  float local_1b0;

  float local_1ac;

  float local_1a8;

  float local_1a0;

  float local_19c;

  float local_198;

  float local_188;

  uint8_t local_174;

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "LtGsk";

    uVar5 = rdtsc();

    DAT_00bc5644[1] = (int)uVar5;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  iVar1 = *param_3;

  iVar2 = *param_2;

  if (*(float *)(param_1 + 0x2c) <= g_flZero) {

LAB_006e51c2:

    if (DAT_00bc5644 < DAT_00bc5648) {

      *DAT_00bc5644 = "StGsk";

      uVar5 = rdtsc();

      DAT_00bc5644[1] = (int)uVar5;

      DAT_00bc5644 = DAT_00bc5644 + 3;

    }

    FUN_0063a3f0(param_2[2] + 0x20,param_3[2] + 0x20);

    local_174 = 0;

    iVar7 = FUN_006fde40(iVar2,iVar1,&local_1d0,param_1 + 0xc,local_1e0);

    if (iVar7 == 0) {

      FUN_006fb6d0(param_1 + 0xc,local_1e0,&local_230);

      FUN_005d6ae0(param_2[2] + 0x20,&local_230);

      local_210 = (local_210 - *(float *)(iVar2 + 0xc)) - *(float *)(iVar1 + 0xc);

      if (local_210 < *(float *)(param_4 + 8)) {

        fVar6 = -*(float *)(iVar2 + 0xc);

        local_220 = local_230 * fVar6 + local_220;

        local_21c = local_22c * fVar6 + local_21c;

        local_218 = local_228 * fVar6 + local_218;

        local_214 = local_224 * fVar6 + local_214;

        fVar6 = -local_210;

        local_1a0 = (local_230 * fVar6 + local_220) - local_1a0;

        local_19c = (local_22c * fVar6 + local_21c) - local_19c;

        local_198 = (local_228 * fVar6 + local_218) - local_198;

        local_200 = local_1d0 * local_1a0 + local_1c8 * local_198 + local_1cc * local_19c;

        local_1fc = local_1c0 * local_1a0 + local_1b8 * local_198 + local_1bc * local_19c;

        local_1f8 = local_1b0 * local_1a0 + local_1a8 * local_198 + local_1ac * local_19c;

        FUN_006f5de0(param_2,param_3,param_4,&local_230,*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_1 + 0x30,

                     param_1 + 0x18);

        FUN_006f60b0(param_2,param_3,param_4,local_210 - g_flMsToSeconds_Inferred,param_1 + 0x30,

                     param_1 + 0x18,param_5,*(uint32_t /* width from decompiler */ *)(param_1 + 8));

        goto LAB_006e543e;

      }

      if ((*(int *)(param_1 + 0x18) == 0) && (**(char **)(param_4 + 0xc) != '\0')) {

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = local_1f0;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = local_1ec;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = local_1e8;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = local_1e4;

        *(float *)(param_1 + 0x2c) = local_210 - *(float *)(param_4 + 8) * DAT_00aaaa10;

      }

    }

  }

  else {

    if (DAT_00bc5644 < DAT_00bc5648) {

      *DAT_00bc5644 = "StTim";

      uVar5 = rdtsc();

      DAT_00bc5644[1] = (int)uVar5;

      DAT_00bc5644 = DAT_00bc5644 + 3;

    }

    pfVar3 = (float *)param_3[2];

    pfVar4 = (float *)param_2[2];

    local_188 = pfVar3[6] - pfVar3[2];

    local_1e0[0] = (pfVar3[4] - *pfVar3) - (pfVar4[4] - *pfVar4);

    fVar6 = *(float *)(param_1 + 0x2c) -

            (local_1e0[0] * *(float *)(param_1 + 0x20) +

             ((pfVar3[5] - pfVar3[1]) - (pfVar4[5] - pfVar4[1])) * *(float *)(param_1 + 0x24) +

             (local_188 - (pfVar4[6] - pfVar4[2])) * *(float *)(param_1 + 0x28) + pfVar3[3] +

            pfVar4[3]);

    *(float *)(param_1 + 0x2c) = fVar6;

    if (fVar6 <= g_flZero) goto LAB_006e51c2;

  }

  FUN_006f5630(param_1 + 0x30,param_1 + 0x18,*(uint32_t /* width from decompiler */ *)(param_1 + 8));

LAB_006e543e:

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d282c;

    uVar5 = rdtsc();

    DAT_00bc5644[1] = (int)uVar5;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
