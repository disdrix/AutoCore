// READABILITY (auto CF):
//  - Body size: ~100 non-empty decompiler lines.
//  - Control keywords: if×5, for×2, goto×1, do×1, while×1, return×1.
//  - Notable callees: FUN_004647f0, FUN_0073a2a0, vog_LogMessage.
//  - Strings: "gDirLight"; ",0x4d

                   ,3,

                   ".
//  - Return sites: 1.

// =============================================================================
// Named_gfxLightImplDirectional_0073a2a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0073a2a0
// Address:   0x0073a2a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxLightImplDirectional"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * Named_gfxLightImplDirectional_0073a2a0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  float fVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  int iVar7;

  uint32_t /* width from decompiler */ *puVar8;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009af969;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_004647f0(param_2);

  fVar2 = g_flOne;

  local_4 = 0;

  *param_1 = &PTR_FUN_00aa44e4;

  param_1[0x3f] = fVar2;

  param_1[0x3c] = 0;

  param_1[0x3d] = 0;

  param_1[0x3e] = 0;

  param_1[0x6b] = fVar2;

  param_1[0x6c] = fVar2;

  param_1[0x6d] = fVar2;

  param_1[0x6e] = fVar2;

  param_1[0x6f] = fVar2;

  uVar3 = DAT_00aaaa80;

  param_1[0x61] = DAT_00a0f74c;

  uVar6 = DAT_00a0f720;

  param_1[0x62] = uVar3;

  param_1[99] = uVar6;

  *(uint8_t *)(param_1 + 0x70) = 0;

  param_1[0x71] = 0;

  param_1[0x72] = 0;

  puVar8 = param_1 + 0x46;

  for (iVar7 = 0x1a; iVar7 != 0; iVar7 = iVar7 + -1) {

    *puVar8 = 0;

    puVar8 = puVar8 + 1;

  }

  param_1[0x46] = 3;

  if (*(int *)(DAT_00d1f630 + 4) != 0) {

    iVar7 = *(int *)(DAT_00d1f630 + 8);

    iVar4 = iVar7 - *(int *)(DAT_00d1f630 + 4) >> 2;

    if (iVar4 != 0) {

      iVar5 = *(int *)(iVar7 + -4);

      if (iVar4 != 0) {

        *(int *)(DAT_00d1f630 + 8) = iVar7 + -4;

      }

      goto LAB_0073a3cf;

    }

  }

  iVar5 = *(int *)(DAT_00d1f630 + 0x10);

  *(int *)(DAT_00d1f630 + 0x10) = iVar5 + 1;

LAB_0073a3cf:

  param_1[0x45] = iVar5;

  param_1[0x60] = 0;

  param_1[0x3c] = 0;

  param_1[0x3d] = 0;

  param_1[0x3e] = 0;

  param_1[0x3f] = 0;

  param_1[0x40] = 0;

  param_1[0x41] = 0;

  param_1[0x42] = 0;

  param_1[0x43] = 0;

  param_1[0x44] = 0;

  puVar8 = param_1 + 0x67;

  *puVar8 = 0;

  param_1[0x68] = 0;

  param_1[0x69] = 0;

  param_1[0x6a] = 0;

  if ((*(int *)(*(int *)(DAT_00d1f05c + 4) + 0xc) == 0) ||

     (piVar1 = *(int **)(*(int *)(DAT_00d1f05c + 4) + 0xc),

     iVar7 = (**(code **)(*piVar1 + 0x24))(piVar1,0,"gDirLight"), iVar7 == 0)) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxLightImplDirectional.cpp",0x4d

                   ,3,

                   "Unable to get parameter handle for the Directional Light. May be an incorrect version of PalLighting.fxh."

                  );

  }

  else {

    iVar4 = 0;

    do {

      if (*(int *)(*(int *)(DAT_00d1f05c + 4) + 0xc) == 0) {

        uVar6 = 0;

      }

      else {

        piVar1 = *(int **)(*(int *)(DAT_00d1f05c + 4) + 0xc);

        uVar6 = (**(code **)(*piVar1 + 0x2c))(piVar1,iVar7,iVar4);

      }

      *puVar8 = uVar6;

      iVar4 = iVar4 + 1;

      puVar8 = puVar8 + 1;

    } while (iVar4 < 4);

  }

  ExceptionList = pvStack_c;

  return param_1;

}
