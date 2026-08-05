// READABILITY (auto CF):
//  - Body size: ~114 non-empty decompiler lines.
//  - Control keywords: if×8, for×3, return×3, goto×2.
//  - Notable callees: FUN_004647f0, FUN_0073aeb0, vog_LogMessage.
//  - Strings: "gHemiLight"; ",0x4d,3

                 ,

                 ".
//  - Return sites: 3.

// =============================================================================
// Named_gfxLightImplHemispheric_0073aeb0
// -----------------------------------------------------------------------------
// Stable ID: aa_0073aeb0
// Address:   0x0073aeb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxLightImplHemispheric"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * Named_gfxLightImplHemispheric_0073aeb0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  int *piVar2;

  float fVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  uint32_t /* width from decompiler */ *puVar8;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009af98d;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_004647f0(param_2);

  fVar3 = g_flOne;

  local_4 = 0;

  *param_1 = &PTR_FUN_00aa4384;

  param_1[0x3c] = 0;

  param_1[0x3d] = 0;

  param_1[0x3e] = 0;

  param_1[0x3f] = fVar3;

  param_1[0x40] = 0;

  param_1[0x41] = 0;

  param_1[0x42] = 0;

  param_1[0x43] = fVar3;

  param_1[0x7d] = 0;

  param_1[0x7e] = 0;

  param_1[0x7f] = fVar3;

  param_1[0x80] = fVar3;

  param_1[0x81] = fVar3;

  param_1[0x82] = 0;

  param_1[0x83] = 0;

  param_1[0x84] = fVar3;

  param_1[0x44] = 0xffffffff;

  param_1[0x7b] = 0xffffffff;

  iVar7 = DAT_00d1f630;

  param_1[0x85] = fVar3;

  *(uint8_t *)(param_1 + 0x86) = 0;

  param_1[0x87] = 0;

  if (*(int *)(iVar7 + 4) == 0) {

LAB_0073afb1:

    iVar6 = *(int *)(iVar7 + 0x10);

    *(int *)(iVar7 + 0x10) = iVar6 + 1;

  }

  else {

    iVar1 = *(int *)(iVar7 + 8);

    iVar5 = iVar1 - *(int *)(iVar7 + 4) >> 2;

    if (iVar5 == 0) goto LAB_0073afb1;

    iVar6 = *(int *)(iVar1 + -4);

    if (iVar5 != 0) {

      *(int *)(iVar7 + 8) = iVar1 + -4;

    }

  }

  param_1[0x45] = iVar6;

  if (*(int *)(iVar7 + 4) != 0) {

    iVar1 = *(int *)(iVar7 + 8);

    iVar5 = iVar1 - *(int *)(iVar7 + 4) >> 2;

    if (iVar5 != 0) {

      iVar6 = *(int *)(iVar1 + -4);

      if (iVar5 != 0) {

        *(int *)(iVar7 + 8) = iVar1 + -4;

      }

      goto LAB_0073affe;

    }

  }

  iVar6 = *(int *)(iVar7 + 0x10);

  *(int *)(iVar7 + 0x10) = iVar6 + 1;

LAB_0073affe:

  uVar4 = DAT_00aaa668;

  param_1[0x46] = iVar6;

  puVar8 = param_1 + 0x47;

  for (iVar7 = 0x1a; iVar7 != 0; iVar7 = iVar7 + -1) {

    *puVar8 = 0;

    puVar8 = puVar8 + 1;

  }

  param_1[0x47] = 3;

  param_1[0x57] = 0;

  param_1[0x58] = uVar4;

  param_1[0x59] = 0;

  puVar8 = param_1 + 0x61;

  for (iVar7 = 0x1a; iVar7 != 0; iVar7 = iVar7 + -1) {

    *puVar8 = 0;

    puVar8 = puVar8 + 1;

  }

  param_1[0x61] = 3;

  param_1[0x71] = 0;

  param_1[0x72] = fVar3;

  param_1[0x73] = 0;

  param_1[0x7c] = 0;

  if ((*(int *)(*(int *)(DAT_00d1f05c + 4) + 0xc) != 0) &&

     (piVar2 = *(int **)(*(int *)(DAT_00d1f05c + 4) + 0xc),

     iVar7 = (**(code **)(*piVar2 + 0x24))(piVar2,0,"gHemiLight"), iVar7 != 0)) {

    if (*(int *)(*(int *)(DAT_00d1f05c + 4) + 0xc) == 0) {

      param_1[0x7c] = 0;

      ExceptionList = pvStack_c;

      return param_1;

    }

    piVar2 = *(int **)(*(int *)(DAT_00d1f05c + 4) + 0xc);

    uVar4 = (**(code **)(*piVar2 + 0x2c))(piVar2,iVar7,0);

    param_1[0x7c] = uVar4;

    ExceptionList = (void *)0x0;

    return param_1;

  }

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxLightImplHemispheric.cpp",0x4d,3

                 ,

                 "Unable to get parameter handle for the Hemispheric Light. May be an incorrect version of PalLighting.fxh."

                );

  ExceptionList = pvStack_c;

  return param_1;

}
