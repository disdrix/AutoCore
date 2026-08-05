// =============================================================================
// FUN_00498dd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00498dd0
// Address:   0x00498dd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00498dd0 @ 0x00498dd0
// Stable ID: aa_00498dd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~346 non-empty decompiler lines.
//  - Control keywords: if×21, for×6, return×1.
//  - Notable callees: free×6, malloc×5, FUN_00498dd0, _eh_vector_destructor_iterator_.
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

void __thiscall FUN_00498dd0(int *param_1,int *param_2,uint32_t /* width from decompiler */ param_3,char param_4)



{

  uint uVar1;

  int *piVar2;

  int *piVar3;

  int iVar4;

  uint uVar5;

  int *piVar6;

  float *pfVar7;

  float local_338 [5];

  uint32_t /* width from decompiler */ local_324;

  uint32_t /* width from decompiler */ local_320;

  uint32_t /* width from decompiler */ local_31c;

  float local_318;

  uint32_t /* width from decompiler */ local_314;

  uint32_t /* width from decompiler */ local_310;

  uint32_t /* width from decompiler */ local_30c;

  float *local_308;

  float local_304;

  uint32_t /* width from decompiler */ local_300;

  uint16_t local_2fc;

  uint32_t /* width from decompiler */ local_2f8;

  uint32_t /* width from decompiler */ local_2f4;

  uint32_t /* width from decompiler */ local_2f0;

  uint32_t /* width from decompiler */ local_2ec;

  int *local_2e8;

  int *local_2e4;

  int *local_2e0;

  int *local_2d8;

  float local_2d4 [5];

  uint32_t /* width from decompiler */ local_2c0;

  uint32_t /* width from decompiler */ local_2bc;

  uint32_t /* width from decompiler */ local_2b8;

  float local_2b4;

  uint32_t /* width from decompiler */ local_2b0;

  uint32_t /* width from decompiler */ local_2ac;

  uint32_t /* width from decompiler */ local_2a8;

  uint32_t /* width from decompiler */ local_2a4;

  uint32_t /* width from decompiler */ local_2a0;

  uint32_t /* width from decompiler */ local_29c;

  uint32_t /* width from decompiler */ local_298;

  uint32_t /* width from decompiler */ local_294;

  uint32_t /* width from decompiler */ local_290;

  uint32_t /* width from decompiler */ local_28c;

  uint32_t /* width from decompiler */ local_288;

  uint32_t /* width from decompiler */ local_284;

  uint32_t /* width from decompiler */ local_280;

  uint32_t /* width from decompiler */ local_27c;

  uint32_t /* width from decompiler */ local_278;

  uint32_t /* width from decompiler */ local_274;

  uint32_t /* width from decompiler */ local_270;

  uint32_t /* width from decompiler */ local_26c;

  uint32_t /* width from decompiler */ local_268;

  uint32_t /* width from decompiler */ local_264;

  uint32_t /* width from decompiler */ local_260;

  uint32_t /* width from decompiler */ local_25c;

  uint32_t /* width from decompiler */ local_258;

  uint32_t /* width from decompiler */ local_254;

  uint8_t local_250 [44];

  uint32_t /* width from decompiler */ local_224;

  uint32_t /* width from decompiler */ local_220;

  uint32_t /* width from decompiler */ local_21c;

  uint32_t /* width from decompiler */ local_218;

  void *local_1e8;

  int local_1e4;

  void *local_1e0;

  uint8_t local_1dc [44];

  uint32_t /* width from decompiler */ local_1b0;

  uint32_t /* width from decompiler */ local_1ac;

  uint32_t /* width from decompiler */ local_1a8;

  uint32_t /* width from decompiler */ local_1a4;

  void *local_174;

  void *local_170;

  int local_16c;

  uint8_t local_168 [44];

  uint32_t /* width from decompiler */ local_13c;

  uint32_t /* width from decompiler */ local_138;

  uint32_t /* width from decompiler */ local_134;

  uint32_t /* width from decompiler */ local_130;

  void *local_100;

  void *local_fc;

  int local_f8;

  uint8_t local_f4 [44];

  uint32_t /* width from decompiler */ local_c8;

  uint32_t /* width from decompiler */ local_c4;

  uint32_t /* width from decompiler */ local_c0;

  uint32_t /* width from decompiler */ local_bc;

  int local_8c;

  void *local_88;

  void *local_84;

  uint8_t local_80 [44];

  uint32_t /* width from decompiler */ local_54;

  uint32_t /* width from decompiler */ local_50;

  uint32_t /* width from decompiler */ local_4c;

  uint32_t /* width from decompiler */ local_48;

  int local_18;

  void *local_14;

  void *local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a0e51;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  local_2d8 = param_1;

  if (*param_1 == 0) {

    ExceptionList = &pvStack_c;

    param_1[1] = (int)param_2;

    _eh_vector_constructor_iterator_

              (local_250,0x74,5,(_func_void_void_ptr *)&LAB_0049c0e0,FUN_004b6740);

    local_27c = DAT_009c7b84;

    local_2e8 = (int *)0x0;

    local_2e0 = (int *)0x0;

    pfVar7 = local_338;

    for (iVar4 = 0x18; iVar4 != 0; iVar4 = iVar4 + -1) {

      *pfVar7 = 0.0;

      pfVar7 = pfVar7 + 1;

    }

    local_274 = DAT_00a10e78;

    local_2d4[0] = g_flOne;

    local_2d4[1] = 0.0;

    local_2d4[2] = 0.0;

    local_2d4[3] = 0.0;

    local_2d4[4] = g_flOne;

    local_2c0 = 0;

    local_2bc = 0;

    local_2b8 = 0;

    local_2b4 = g_flOne;

    local_2a8 = 0;

    local_2ac = 0;

    local_2b0 = 0;

    local_29c = 0;

    local_2a0 = 0;

    local_2a4 = 0;

    local_28c = 0;

    local_290 = 0;

    local_294 = 0;

    local_280 = 0;

    local_284 = 0;

    local_288 = 0;

    local_298 = 0;

    local_278 = 0;

    local_270 = DAT_00aaa668;

    local_264 = DAT_00aaa668;

    local_260 = DAT_00aaa668;

    local_26c = 0;

    local_25c = 4;

    local_258 = DAT_00aaa668;

    local_254 = 0;

    local_268 = 0x80;

    local_338[0] = g_flOne;

    local_338[1] = 0.0;

    local_338[2] = 0.0;

    local_338[3] = 0.0;

    local_338[4] = g_flOne;

    local_324 = 0;

    local_320 = 0;

    local_31c = 0;

    local_318 = g_flOne;

    local_30c = 0;

    local_310 = 0;

    local_314 = 0;

    local_300 = 0;

    local_2f8 = 0;

    local_2f4 = 0;

    local_2f0 = 0;

    local_2e4 = local_2e8;

    local_2ec = 1;

    local_4 = 1;

    local_308 = local_2d4;

    local_304 = g_flOne;

    local_2fc = 3;

    if (param_4 == '\0') {

      local_1e4 = g_nInferredThreatDefault;

      local_1e8 = DAT_00aaa954;

      local_1e0 = DAT_00aaa954;

      local_224 = 0;

      local_220 = DAT_009c7bc4;

      local_21c = 0;

      local_218 = 0x100;

      if ((local_2e0 <= local_2e8) &&

         ((local_2e8 == (int *)0x0 || ((uint)((int)local_2e0 - (int)local_2e8 >> 2) < 2)))) {

        piVar2 = malloc(8);

        piVar6 = piVar2;

        for (piVar3 = local_2e8; piVar3 != local_2e4; piVar3 = piVar3 + 1) {

          *piVar6 = *piVar3;

          piVar6 = piVar6 + 1;

        }

        if (local_2e8 != (int *)0x0) {

          free(local_2e8);

        }

        local_2e0 = piVar2 + 2;

        local_2e4 = piVar2 + ((int)local_2e4 - (int)local_2e8 >> 2);

        local_2e8 = piVar2;

      }

      local_174 = DAT_00aaa954;

      local_16c = g_nInferredThreatDefault;

      *local_2e4 = (int)local_250;

      local_2e4 = local_2e4 + 1;

      local_1b0 = 0;

      local_1ac = 0;

      local_1a8 = DAT_00aaa950;

      local_1a4 = 0x100;

      local_100 = local_174;

      local_170 = local_174;

      if (local_2e0 <= local_2e4) {

        uVar1 = ((int)local_2e4 - (int)local_2e8 >> 2) * 2 + 2;

        if (local_2e8 == (int *)0x0) {

          uVar5 = 0;

        }

        else {

          uVar5 = (int)local_2e0 - (int)local_2e8 >> 2;

        }

        if (uVar5 < uVar1) {

          piVar2 = malloc(uVar1 * 4);

          piVar6 = piVar2;

          for (piVar3 = local_2e8; piVar3 != local_2e4; piVar3 = piVar3 + 1) {

            *piVar6 = *piVar3;

            piVar6 = piVar6 + 1;

          }

          if (local_2e8 != (int *)0x0) {

            free(local_2e8);

          }

          local_2e0 = piVar2 + uVar1;

          local_2e4 = piVar2 + ((int)local_2e4 - (int)local_2e8 >> 2);

          local_100 = DAT_00aaa954;

          local_2e8 = piVar2;

        }

      }

      local_f8 = g_nInferredThreatDefault;

      *local_2e4 = (int)local_1dc;

      local_2e4 = local_2e4 + 1;

      local_13c = 0;

      local_138 = 0;

      local_134 = DAT_009c7bc4;

      local_130 = 0x100;

      local_88 = local_100;

      local_fc = local_100;

      if (local_2e0 <= local_2e4) {

        uVar1 = ((int)local_2e4 - (int)local_2e8 >> 2) * 2 + 2;

        if (local_2e8 == (int *)0x0) {

          uVar5 = 0;

        }

        else {

          uVar5 = (int)local_2e0 - (int)local_2e8 >> 2;

        }

        if (uVar5 < uVar1) {

          piVar2 = malloc(uVar1 * 4);

          piVar6 = piVar2;

          for (piVar3 = local_2e8; piVar3 != local_2e4; piVar3 = piVar3 + 1) {

            *piVar6 = *piVar3;

            piVar6 = piVar6 + 1;

          }

          if (local_2e8 != (int *)0x0) {

            free(local_2e8);

          }

          local_2e0 = piVar2 + uVar1;

          local_2e4 = piVar2 + ((int)local_2e4 - (int)local_2e8 >> 2);

          local_88 = DAT_00aaa954;

          local_2e8 = piVar2;

        }

      }

      local_8c = g_nInferredThreatDefault;

      *local_2e4 = (int)local_168;

      local_2e4 = local_2e4 + 1;

      local_c8 = DAT_009c7bc4;

      local_c4 = 0;

      local_c0 = 0;

      local_bc = 0x100;

      local_14 = local_88;

      local_84 = local_88;

      if (local_2e0 <= local_2e4) {

        uVar1 = ((int)local_2e4 - (int)local_2e8 >> 2) * 2 + 2;

        if (local_2e8 == (int *)0x0) {

          uVar5 = 0;

        }

        else {

          uVar5 = (int)local_2e0 - (int)local_2e8 >> 2;

        }

        if (uVar5 < uVar1) {

          piVar2 = malloc(uVar1 * 4);

          piVar6 = piVar2;

          for (piVar3 = local_2e8; piVar3 != local_2e4; piVar3 = piVar3 + 1) {

            *piVar6 = *piVar3;

            piVar6 = piVar6 + 1;

          }

          if (local_2e8 != (int *)0x0) {

            free(local_2e8);

          }

          local_2e0 = piVar2 + uVar1;

          local_2e4 = piVar2 + ((int)local_2e4 - (int)local_2e8 >> 2);

          local_14 = DAT_00aaa954;

          local_2e8 = piVar2;

        }

      }

      local_18 = g_nInferredThreatDefault;

      *local_2e4 = (int)local_f4;

      local_2e4 = local_2e4 + 1;

      local_54 = DAT_00aaa950;

      local_50 = 0;

      local_4c = 0;

      local_48 = 0x100;

      local_10 = local_14;

      if (local_2e0 <= local_2e4) {

        uVar1 = ((int)local_2e4 - (int)local_2e8 >> 2) * 2 + 2;

        if (local_2e8 == (int *)0x0) {

          uVar5 = 0;

        }

        else {

          uVar5 = (int)local_2e0 - (int)local_2e8 >> 2;

        }

        if (uVar5 < uVar1) {

          piVar2 = malloc(uVar1 * 4);

          piVar6 = piVar2;

          for (piVar3 = local_2e8; piVar3 != local_2e4; piVar3 = piVar3 + 1) {

            *piVar6 = *piVar3;

            piVar6 = piVar6 + 1;

          }

          if (local_2e8 != (int *)0x0) {

            free(local_2e8);

          }

          local_2e0 = piVar2 + uVar1;

          local_2e4 = piVar2 + ((int)local_2e4 - (int)local_2e8 >> 2);

          local_2e8 = piVar2;

        }

      }

      *local_2e4 = (int)local_80;

      local_2e4 = local_2e4 + 1;

      param_1 = local_2d8;

    }

    iVar4 = (**(code **)(*param_2 + 0x18))(local_338);

    *param_1 = iVar4;

    if (local_2e8 != (int *)0x0) {

      free(local_2e8);

    }

    local_2e8 = (int *)0x0;

    local_2e4 = (int *)0x0;

    local_2e0 = (int *)0x0;

    local_4 = 0xffffffff;

    _eh_vector_destructor_iterator_(local_250,0x74,5,FUN_004b6740);

  }

  (**(code **)(*(int *)*param_1 + 0x14))(param_3);

  ExceptionList = local_10;

  return;

}
