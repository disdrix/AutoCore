// READABILITY (auto CF):
//  - Body size: ~200 non-empty decompiler lines.
//  - Control keywords: if×12, do×5, while×5, for×3, goto×1, return×1.
//  - Notable callees: FUN_00764030×2, FUN_00989e00×2, FUN_004c7bd0, FUN_004c8050, FUN_005d4d70, FUN_0076cec0, FUN_007a4480, FUN_007b6730.
//  - Strings: "C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGCreature.cpp".
//  - Return sites: 1.

// =============================================================================
// CVOGCreature_SetupGraphics
// -----------------------------------------------------------------------------
// Stable ID: aa_004c8b60
// Address:   0x004c8b60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

/* CVOGCreature graphics/physics setup.

   For type Creature with flag bit4 clear: subtracts rlFlyingHeight from Y

   before placement (pairs with CreateCreature add). IsNPC calls name setup. */



uint32_t /* width from decompiler */ __thiscall

CVOGCreature_SetupGraphics

          (int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,float param_4,uint8_t *param_5,

          uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7)



{

  char cVar1;

  char *pcVar2;

  char *pcVar3;

  int *piVar4;

  int iVar5;

  void *pvVar6;

  int iVar7;

  uint uVar8;

  char *pcVar9;

  uint32_t /* width from decompiler */ *puVar10;

  char *pcVar11;

  uint32_t /* width from decompiler */ local_150;

  float local_14c;

  uint8_t *local_148;

  int *local_144;

  uint32_t /* width from decompiler */ *local_140;

  uint32_t /* width from decompiler */ uStack_124;

  uint8_t *local_120;

  char cStack_119;

  char local_118 [2];

  uint32_t /* width from decompiler */ uStack_116;

  char local_110 [252];

  void *pvStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ local_c;

  

  local_c = 0xffffffff;

  puStack_10 = &LAB_009a1c25;

  pvStack_14 = ExceptionList;

  ExceptionList = &pvStack_14;

  *(uint8_t *)(param_1 + 0xd) = 0;

  if ((*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x3c) + 4) + 0x6c + param_1) + 0x38) == 0x12)

     && ((*(uint *)(param_1 + 0x1c0) >> 4 & 1) == 0)) {

    param_4 = param_4 - *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x3c) + 4) + 0x6c

                                                    + param_1) + 0x3c) + 0x4d4);

  }

  local_144 = (int *)param_6;

  local_140 = (uint32_t /* width from decompiler */ *)param_7;

  local_120 = (uint8_t *)&local_150;

  local_150 = param_3;

  local_148 = param_5;

  local_14c = param_4;

  FUN_005d4d70(param_2);

  if (*(int *)(param_1 + 8) != 0) {

    *(uint8_t *)(*(int *)(param_1 + 8) + 0x13a) = 1;

  }

  iVar5 = *(int *)(param_1 + -0x3c);

  local_118[0] = '\0';

  local_118[1] = '\0';

  puVar10 = &uStack_116;

  for (iVar7 = 0x3f; iVar7 != 0; iVar7 = iVar7 + -1) {

    *puVar10 = 0;

    puVar10 = puVar10 + 1;

  }

  *(uint16_t *)puVar10 = 0;

  pcVar2 = (char *)(*(int *)(*(int *)(iVar5 + 4) + 0x6c + param_1) + 0x188);

  pcVar3 = pcVar2;

  do {

    cVar1 = *pcVar3;

    pcVar3 = pcVar3 + 1;

  } while (cVar1 != '\0');

  pcVar11 = &cStack_119;

  do {

    pcVar9 = pcVar11 + 1;

    pcVar11 = pcVar11 + 1;

  } while (*pcVar9 != '\0');

  pcVar9 = pcVar2;

  for (uVar8 = (uint)((int)pcVar3 - (int)pcVar2) >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar11 = *(uint32_t /* width from decompiler */ *)pcVar9;

    pcVar9 = pcVar9 + 4;

    pcVar11 = pcVar11 + 4;

  }

  for (uVar8 = (int)pcVar3 - (int)pcVar2 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {

    *pcVar11 = *pcVar9;

    pcVar9 = pcVar9 + 1;

    pcVar11 = pcVar11 + 1;

  }

  pcVar3 = &cStack_119;

  do {

    pcVar2 = pcVar3;

    pcVar3 = pcVar2 + 1;

  } while (pcVar2[1] != '\0');

  *(uint32_t /* width from decompiler */ *)(pcVar2 + 1) = DAT_00a67574;

  *(uint32_t /* width from decompiler */ *)(pcVar2 + 5) = DAT_00a67578;

  pcVar2[9] = DAT_00a6757c;

  FUN_007b6a20();

  cVar1 = FUN_007b6730();

  if (cVar1 != '\0') {

    pcVar2 = (char *)(*(int *)(*(int *)(*(int *)(param_1 + -0x3c) + 4) + 0x6c + param_1) + 0x188);

    pcVar3 = local_118;

    do {

      cVar1 = *pcVar2;

      *pcVar3 = cVar1;

      pcVar2 = pcVar2 + 1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    pcVar3 = &cStack_119;

    do {

      pcVar2 = pcVar3;

      pcVar3 = pcVar2 + 1;

    } while (pcVar2[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar2 + 1) = DAT_00a67574;

    *(uint32_t /* width from decompiler */ *)(pcVar2 + 5) = DAT_00a67578;

    pcVar2[9] = DAT_00a6757c;

    local_120 = operator_new(0x14c);

    local_c = 0;

    if (local_120 == (uint8_t *)0x0) {

      piVar4 = (int *)0x0;

    }

    else {

      piVar4 = (int *)FUN_00764030();

    }

    local_c = 0xffffffff;

    FUN_00989e00();

    iVar5 = (**(code **)(*piVar4 + 0x5c))();

    if (iVar5 < 0) {

      local_140 = (uint32_t /* width from decompiler */ *)0x1;

      local_144 = (int *)0x4c8eb0;

      FUN_007a4480();

      (**(code **)*piVar4)();

    }

    else {

      *(uint8_t *)((int)piVar4 + 0x13a) = 1;

      uStack_124 = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0x3c) + 4) + 0x7c + param_1);

      (**(code **)(*piVar4 + 0x1c))();

      *(int **)(param_1 + 0x244) = piVar4;

      if ((*(int *)(param_1 + 8) != 0) && (*(int *)(param_1 + 0x240) != 0)) {

        local_140 = (uint32_t /* width from decompiler */ *)0x4c8da6;

        FUN_0096d550();

      }

      if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x240) != (uint32_t /* width from decompiler */ *)0x0) {

        local_140 = (uint32_t /* width from decompiler */ *)0x4c8db6;

        (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x240))();

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x240) = 0;

      local_140 = (uint32_t /* width from decompiler */ *)0x4c8dc6;

      pvVar6 = operator_new(0x14c);

      pvStack_14 = (void *)0x1;

      if (pvVar6 == (void *)0x0) {

        piVar4 = (int *)0x0;

      }

      else {

        piVar4 = (int *)FUN_00764030();

      }

      local_140 = (uint32_t /* width from decompiler */ *)&stack0xfffffed8;

      pvStack_14 = (void *)0xffffffff;

      local_144 = (int *)0x4c8e08;

      FUN_00989e00();

      local_140 = (uint32_t /* width from decompiler */ *)0x4c8e14;

      (**(code **)(*piVar4 + 0x5c))();

      *(int **)(param_1 + 0x240) = piVar4;

      if (*(int *)(param_1 + 8) != 0) {

        local_140 = (uint32_t /* width from decompiler */ *)0x0;

        local_148 = (uint8_t *)0x1f;

        local_14c = 7.030497e-39;

        local_144 = piVar4;

        iVar5 = FUN_0096dc80();

        if (-1 < iVar5) {

          local_140 = (uint32_t /* width from decompiler */ *)0x3;

          local_144 = (int *)0x4c8e37;

          (**(code **)(*piVar4 + 0x10))();

          local_144 = (int *)0x3;

          local_148 = (uint8_t *)0x4c8e41;

          (**(code **)(**(int **)(param_1 + 8) + 0x10))();

          FUN_004c7bd0();

          goto LAB_004c8ebb;

        }

      }

      local_140 = &uStack_124;

      local_148 = &stack0xfffffed8;

      local_144 = (int *)0x9cbb18;

      local_14c = 7.030578e-39;

      local_14c = (float)FUN_0076cec0();

      local_150 = 3;

      vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGCreature.cpp",0xc25);

      local_140 = (uint32_t /* width from decompiler */ *)0x1;

      local_144 = (int *)0x4c8e81;

      (**(code **)*piVar4)();

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x240) = 0;

      if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x244) != (uint32_t /* width from decompiler */ *)0x0) {

        (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x244))();

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x244) = 0;

    }

  }

LAB_004c8ebb:

  if (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x3c) + 4) + 0x6c + param_1) + 0x3c) +

              0x4e0) == 1) {

    FUN_004c8050();

  }

  ExceptionList = pvStack_14;

  return 1;

}
