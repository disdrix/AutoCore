// READABILITY (auto CF):
//  - Body size: ~160 non-empty decompiler lines.
//  - Control keywords: if×6, for×2, goto×1, do×1, while×1, return×1.
//  - Notable callees: FUN_004647f0, FUN_004653e0, FUN_00736f20, vog_LogMessage.
//  - Strings: "gPointLight"; ",0x67,3,

                   ".
//  - Return sites: 1.

// =============================================================================
// Named_gfxLightImplPoint
// -----------------------------------------------------------------------------
// Stable ID: aa_00736f20
// Address:   0x00736f20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxLightImplPoint"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * Named_gfxLightImplPoint(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  float fVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  int iVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ *puVar9;

  int iVar10;

  uint32_t /* width from decompiler */ uVar11;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009af8d4;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_004647f0(param_2);

  uVar5 = DAT_00a10e78;

  fVar2 = g_flOne;

  local_4 = 0;

  uVar11 = 0;

  *param_1 = &PTR_FUN_00aa4b14;

  param_1[0x40] = 0;

  param_1[0x41] = 0;

  param_1[0x42] = 0;

  param_1[0x43] = fVar2;

  param_1[0x44] = 0;

  param_1[0x45] = 0;

  param_1[0x46] = 0;

  param_1[0x47] = fVar2;

  param_1[0x73] = uVar5;

  uVar5 = DAT_00a110d8;

  *(uint8_t *)(param_1 + 0x72) = 1;

  *(uint8_t *)(param_1 + 0x74) = 1;

  param_1[0x75] = 0;

  param_1[0x76] = 0;

  param_1[0x77] = 0;

  param_1[0x78] = uVar5;

  param_1[0x79] = 0;

  param_1[0x7a] = 0;

  param_1[0x7b] = fVar2;

  uVar5 = DAT_00aaa7b8;

  param_1[0x7c] = DAT_00aaa7b8;

  param_1[0x7d] = uVar5;

  param_1[0x7e] = uVar5;

  param_1[0x7f] = fVar2;

  puVar8 = param_1 + 0x78;

  param_1[0x80] = fVar2;

  param_1[0x81] = 0;

  param_1[0x82] = fVar2;

  param_1[0x83] = fVar2;

  param_1[0x84] = 0;

  param_1[0x85] = fVar2;

  *(uint8_t *)(param_1 + 0x86) = 0;

  param_1[0x87] = 0;

  param_1[0x3c] = DAT_00d1a6c0;

  param_1[0x3d] = DAT_00d1a6c4;

  param_1[0x3e] = DAT_00d1a6c8;

  param_1[0x40] = *puVar8;

  param_1[0x41] = param_1[0x79];

  param_1[0x42] = param_1[0x7a];

  param_1[0x43] = param_1[0x7b];

  param_1[0x44] = param_1[0x7c];

  param_1[0x45] = param_1[0x7d];

  param_1[0x46] = param_1[0x7e];

  param_1[0x3f] = fVar2;

  param_1[0x47] = param_1[0x7f];

  param_1[0x48] = fVar2;

  param_1[0x49] = fVar2;

  param_1[0x4a] = 0;

  param_1[0x4b] = 0;

  param_1[0x4c] = 0xffffffff;

  puVar9 = param_1 + 0x4f;

  for (iVar6 = 0x1a; iVar6 != 0; iVar6 = iVar6 + -1) {

    *puVar9 = 0;

    puVar9 = puVar9 + 1;

  }

  param_1[0x4f] = 1;

  uVar3 = DAT_00d1a6c8;

  uVar5 = DAT_00d1a6c4;

  param_1[0x5c] = DAT_00d1a6c0;

  param_1[0x5d] = uVar5;

  param_1[0x62] = param_1[0x80];

  param_1[0x5e] = uVar3;

  param_1[0x50] = *puVar8;

  param_1[0x51] = param_1[0x79];

  param_1[0x52] = param_1[0x7a];

  param_1[0x53] = param_1[0x7b];

  param_1[0x54] = *puVar8;

  param_1[0x55] = param_1[0x79];

  param_1[0x56] = param_1[0x7a];

  param_1[0x57] = param_1[0x7b];

  param_1[0x58] = param_1[0x7c];

  param_1[0x59] = param_1[0x7d];

  param_1[0x5a] = param_1[0x7e];

  param_1[0x5b] = param_1[0x7f];

  param_1[0x65] = param_1[0x83];

  iVar6 = DAT_00d1f630;

  param_1[100] = param_1[0x82];

  param_1[0x66] = param_1[0x84];

  if (*(int *)(iVar6 + 4) != 0) {

    iVar10 = *(int *)(iVar6 + 8);

    iVar7 = iVar10 - *(int *)(iVar6 + 4) >> 2;

    if (iVar7 != 0) {

      iVar4 = *(int *)(iVar10 + -4);

      if (iVar7 != 0) {

        *(int *)(iVar6 + 8) = iVar10 + -4;

      }

      goto LAB_007371f2;

    }

  }

  iVar4 = *(int *)(iVar6 + 0x10);

  *(int *)(iVar6 + 0x10) = iVar4 + 1;

LAB_007371f2:

  param_1[0x4e] = iVar4;

  param_1[0x69] = 0xffffffff;

  if ((*(char *)(param_1 + 0x72) != '\0') && (*(char *)(param_1 + 0x74) == '\0')) {

    FUN_004653e0();

    param_1[0x37] = param_1[0x37] + 1;

    param_1[0x80] = uVar11;

    *(uint8_t *)(param_1 + 0x74) = 1;

  }

  puVar8 = param_1 + 0x6a;

  *puVar8 = 0;

  param_1[0x6b] = 0;

  param_1[0x6c] = 0;

  param_1[0x6d] = 0;

  param_1[0x6e] = 0;

  param_1[0x6f] = 0;

  param_1[0x70] = 0;

  param_1[0x71] = 0;

  if ((*(int *)(*(int *)(DAT_00d1f05c + 4) + 0xc) == 0) ||

     (piVar1 = *(int **)(*(int *)(DAT_00d1f05c + 4) + 0xc),

     iVar6 = (**(code **)(*piVar1 + 0x24))(piVar1,0,"gPointLight"), iVar6 == 0)) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxLightImplPoint.cpp",0x67,3,

                   "Unable to get parameter handle for a Point Light. May be an incorrect version of PalLighting.fxh."

                  );

  }

  else {

    iVar10 = 0;

    do {

      if (*(int *)(*(int *)(DAT_00d1f05c + 4) + 0xc) == 0) {

        uVar5 = 0;

      }

      else {

        piVar1 = *(int **)(*(int *)(DAT_00d1f05c + 4) + 0xc);

        uVar5 = (**(code **)(*piVar1 + 0x2c))(piVar1,iVar6,iVar10);

      }

      *puVar8 = uVar5;

      iVar10 = iVar10 + 1;

      puVar8 = puVar8 + 1;

    } while (iVar10 < 8);

  }

  ExceptionList = pvStack_c;

  return param_1;

}
