// =============================================================================
// FUN_006e54c0
// -----------------------------------------------------------------------------
// Stable ID: aa_006e54c0
// Address:   0x006e54c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e54c0 @ 0x006e54c0
// Stable ID: aa_006e54c0
// Embedded strings (evidence for future rename):
//   - "LtGsk"
//   - "StTim"
//   - "StGsk"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~142 non-empty decompiler lines.
//  - Control keywords: if×9, goto×1, return×1.
//  - Notable callees: rdtsc×4, FUN_005d6ae0, FUN_0063a3f0, FUN_006e54c0, FUN_006fb6d0, FUN_006fde40.
//  - Strings: "LtGsk"; "StTim"; "StGsk".
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

void __thiscall FUN_006e54c0(int param_1,int *param_2,int *param_3,int param_4,int *param_5)



{

  int iVar1;

  int iVar2;

  float *pfVar3;

  float *pfVar4;

  uint64_t uVar5;

  float fVar6;

  int *piVar7;

  int *piVar8;

  int iVar9;

  float local_240;

  float local_23c;

  float local_238;

  float local_234;

  float local_230;

  float local_22c;

  float local_228;

  float local_224;

  float local_220;

  float local_210;

  float local_20c;

  float local_208;

  uint32_t /* width from decompiler */ local_200;

  uint32_t /* width from decompiler */ local_1fc;

  uint32_t /* width from decompiler */ local_1f8;

  uint32_t /* width from decompiler */ local_1f4;

  float local_1ec;

  float local_1e8;

  float local_1e0;

  float local_1dc;

  float local_1d8;

  float local_1d4;

  float local_1d0;

  float local_1cc;

  float local_1c8;

  uint32_t /* width from decompiler */ local_1c4;

  int *local_1c0;

  int *local_1bc;

  float local_1b8;

  float local_1b0;

  float local_1ac;

  float local_1a8;

  float local_1a0 [6];

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

  if (g_flZero < *(float *)(param_1 + 0x2c)) {

    if (DAT_00bc5644 < DAT_00bc5648) {

      *DAT_00bc5644 = "StTim";

      uVar5 = rdtsc();

      DAT_00bc5644[1] = (int)uVar5;

      DAT_00bc5644 = DAT_00bc5644 + 3;

    }

    pfVar3 = (float *)param_3[2];

    pfVar4 = (float *)param_2[2];

    local_188 = pfVar3[6] - pfVar3[2];

    local_1ec = pfVar4[5] - pfVar4[1];

    local_1e8 = pfVar4[6] - pfVar4[2];

    local_1a0[0] = (pfVar3[4] - *pfVar3) - (pfVar4[4] - *pfVar4);

    fVar6 = *(float *)(param_1 + 0x2c) -

            (local_1a0[0] * *(float *)(param_1 + 0x20) +

             ((pfVar3[5] - pfVar3[1]) - local_1ec) * *(float *)(param_1 + 0x24) +

             (local_188 - local_1e8) * *(float *)(param_1 + 0x28) + pfVar3[3] + pfVar4[3]);

    *(float *)(param_1 + 0x2c) = fVar6;

    if (g_flZero < fVar6) goto LAB_006e5896;

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "StGsk";

    uVar5 = rdtsc();

    DAT_00bc5644[1] = (int)uVar5;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  FUN_0063a3f0(param_2[2] + 0x20,param_3[2] + 0x20);

  local_174 = 0;

  iVar9 = FUN_006fde40(iVar2,iVar1,&local_1e0,param_1 + 0xc,local_1a0);

  if (iVar9 == 0) {

    FUN_006fb6d0(param_1 + 0xc,local_1a0,&local_240);

    FUN_005d6ae0(param_2[2] + 0x20,&local_240);

    piVar8 = local_1bc;

    piVar7 = local_1c0;

    local_220 = (local_220 - *(float *)(iVar2 + 0xc)) - *(float *)(iVar1 + 0xc);

    if (*(float *)(param_4 + 8) <= local_220) {

      if ((*(int *)(param_1 + 0x18) == 0) && (**(char **)(param_4 + 0xc) != '\0')) {

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = local_200;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = local_1fc;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = local_1f8;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = local_1f4;

        *(float *)(param_1 + 0x2c) = local_220 - *(float *)(param_4 + 8) * DAT_00aaaa10;

      }

    }

    else {

      fVar6 = -*(float *)(iVar2 + 0xc);

      local_230 = local_240 * fVar6 + local_230;

      local_22c = local_23c * fVar6 + local_22c;

      local_228 = local_238 * fVar6 + local_228;

      local_224 = local_234 * fVar6 + local_224;

      fVar6 = -local_220;

      local_1ec = local_23c * fVar6 + local_22c;

      local_1e8 = local_238 * fVar6 + local_228;

      local_1b0 = (local_240 * fVar6 + local_230) - local_1b0;

      local_1ac = local_1ec - local_1ac;

      local_1a8 = local_1e8 - local_1a8;

      local_210 = local_1e0 * local_1b0 + local_1d8 * local_1a8 + local_1dc * local_1ac;

      local_20c = local_1d0 * local_1b0 + local_1c8 * local_1a8 + local_1cc * local_1ac;

      local_1bc = param_3;

      iVar1 = param_3[2];

      local_1c0 = param_2;

      local_208 = (float)piVar7 * local_1b0 + local_1b8 * local_1a8 + (float)piVar8 * local_1ac;

      local_1e0 = local_210 * *(float *)(iVar1 + 0x20) +

                  local_20c * *(float *)(iVar1 + 0x30) + local_208 * *(float *)(iVar1 + 0x40) +

                  *(float *)(iVar1 + 0x50);

      local_1dc = local_210 * *(float *)(iVar1 + 0x24) +

                  local_20c * *(float *)(iVar1 + 0x34) + local_208 * *(float *)(iVar1 + 0x44) +

                  *(float *)(iVar1 + 0x54);

      local_1d8 = local_210 * *(float *)(iVar1 + 0x28) +

                  local_20c * *(float *)(iVar1 + 0x38) + local_208 * *(float *)(iVar1 + 0x48) +

                  *(float *)(iVar1 + 0x58);

      local_1d0 = (float)local_200;

      local_1cc = (float)local_1fc;

      local_1c4 = local_1f4;

      local_1c8 = (float)local_1f8;

      local_1d4 = local_220;

      (**(code **)(*param_5 + 4))(&local_1e0);

    }

  }

LAB_006e5896:

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d282c;

    uVar5 = rdtsc();

    DAT_00bc5644[1] = (int)uVar5;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
