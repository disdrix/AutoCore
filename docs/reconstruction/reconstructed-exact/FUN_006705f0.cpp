// =============================================================================
// FUN_006705f0
// -----------------------------------------------------------------------------
// Stable ID: aa_006705f0
// Address:   0x006705f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006705f0 @ 0x006705f0
// Stable ID: aa_006705f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~128 non-empty decompiler lines.
//  - Control keywords: if×9, for×2, return×2.
//  - Notable callees: FUN_00671b40×7, CONCAT22×6, FUN_0067a190×2, FUN_0067a740×2, FUN_0067ae10×2, FUN_00680c30×2, FUN_00680c50×2, CONCAT31.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ __thiscall FUN_006705f0(int param_1,byte *param_2)



{

  int iVar1;

  byte bVar2;

  byte *pbVar3;

  byte *pbVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint uVar7;

  uint16_t extraout_var;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint16_t extraout_var_00;

  uint32_t /* width from decompiler */ *puVar10;

  uint32_t /* width from decompiler */ *puVar11;

  uint8_t local_44 [28];

  uint8_t local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  pbVar4 = param_2;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a9005;

  local_c = ExceptionList;

  bVar2 = *param_2;

  puVar10 = *(uint32_t /* width from decompiler */ **)(param_2 + 4);

  puVar11 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x17c) + *(int *)(param_1 + 0x178));

  ExceptionList = &local_c;

  for (uVar7 = (uint)(bVar2 >> 2); uVar7 != 0; uVar7 = uVar7 - 1) {

    *puVar11 = *puVar10;

    puVar10 = puVar10 + 1;

    puVar11 = puVar11 + 1;

  }

  for (uVar7 = bVar2 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {

    *(uint8_t *)puVar11 = *(uint8_t *)puVar10;

    puVar10 = (uint32_t /* width from decompiler */ *)((int)puVar10 + 1);

    puVar11 = (uint32_t /* width from decompiler */ *)((int)puVar11 + 1);

  }

  iVar5 = *(int *)(param_1 + 0x1bc);

  iVar1 = param_1 + 0x1b8;

  if ((iVar5 == 0) ||

     ((uint)(*(int *)(param_1 + 0x1c4) - iVar5) <= (uint)(*(int *)(param_1 + 0x1c0) - iVar5))) {

    FUN_00446860(*(uint32_t /* width from decompiler */ *)(param_1 + 0x1c0),1,param_2);

  }

  else {

    pbVar3 = *(byte **)(param_1 + 0x1c0);

    *pbVar3 = *param_2;

    *(byte **)(param_1 + 0x1c0) = pbVar3 + 1;

  }

  *(int *)(param_1 + 0x180) = *(int *)(param_1 + 0x180) + 1;

  *(int *)(param_1 + 0x17c) = *(int *)(param_1 + 0x17c) + (uint)*pbVar4;

  iVar5 = FUN_00671b40();

  if (iVar5 <= *(int *)(param_1 + 0x180)) {

    FUN_00680c30();

    uVar6 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x178);

    local_4 = 0;

    if (*(char *)(*(int *)(*(int *)(param_1 + 0x2c) + 0x15c) + 0x14) == '\0') {

      uVar8 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x17c);

      uVar9 = CONCAT22((short)((uint)uVar8 >> 0x10),*(uint16_t *)(param_1 + 0x50));

      if (*(int *)(param_1 + 0x1c8) == 4) {

        uVar6 = FUN_00671b40(uVar9,uVar6,uVar8);

        FUN_0067a740(local_28,*(uint8_t *)(param_1 + 0xc),uVar6);

      }

      else {

        uVar6 = FUN_00671b40(uVar9,uVar6,uVar8);

        FUN_0067a530(local_28,uVar6);

      }

    }

    else {

      uVar8 = CONCAT22(extraout_var,*(uint16_t *)(param_1 + 0x17c));

      uVar9 = CONCAT22(extraout_var,*(uint16_t *)(param_1 + 0x50));

      if (*(int *)(param_1 + 0x1c8) == 4) {

        uVar6 = FUN_00671b40(uVar9,uVar6,uVar8,iVar1);

        FUN_0067ae10(local_28,*(uint8_t *)(param_1 + 0xc),uVar6);

      }

      else {

        uVar6 = FUN_00671b40(uVar9,uVar6,uVar8,iVar1);

        FUN_0067ad60(local_28,uVar6);

      }

    }

    *(short *)(param_1 + 0x50) = *(short *)(param_1 + 0x50) + 1;

    if (*(int *)(param_1 + 0x1c8) == 4) {

      iVar5 = *(int *)(param_1 + 0x214);

      param_2 = (byte *)FUN_00671630(iVar5,*(uint32_t /* width from decompiler */ *)(iVar5 + 4),local_28);

      FUN_006716c0(1);

      *(byte **)(iVar5 + 4) = param_2;

      **(uint32_t /* width from decompiler */ **)(param_2 + 4) = param_2;

    }

    else {

      (**(code **)(**(int **)(param_1 + 0x38) + 4))(local_28,0xfe);

    }

    if (*(char *)(param_1 + 0x1cc) != '\0') {

      FUN_00680c30();

      local_4 = CONCAT31(local_4._1_3_,1);

      if (*(char *)(*(int *)(*(int *)(param_1 + 0x2c) + 0x15c) + 0x14) == '\0') {

        uVar6 = FUN_00671b40(CONCAT22((short)((uint)*(uint32_t /* width from decompiler */ *)(param_1 + 0x17c) >> 0x10),

                                      *(uint16_t *)(param_1 + 0x50)),

                             *(uint32_t /* width from decompiler */ *)(param_1 + 0x178),*(uint32_t /* width from decompiler */ *)(param_1 + 0x17c));

        FUN_0067a740(local_44,*(uint8_t *)(param_1 + 0xc),uVar6);

        FUN_0067a190(local_44,&param_2);

        FUN_00674980(local_44);

      }

      else {

        uVar6 = FUN_00671b40(CONCAT22(extraout_var_00,*(uint16_t *)(param_1 + 0x50)),

                             *(uint32_t /* width from decompiler */ *)(param_1 + 0x178),

                             CONCAT22(extraout_var_00,*(uint16_t *)(param_1 + 0x17c)),iVar1);

        FUN_0067ae10(local_44,*(uint8_t *)(param_1 + 0xc),uVar6);

        FUN_0067a190(local_44,&param_2);

        FUN_00674990(local_44);

      }

      local_4 = local_4 & 0xffffff00;

      FUN_00680c50();

    }

    if (*(void **)(param_1 + 0x1bc) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)(param_1 + 0x1bc));

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1bc) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c0) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c4) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x17c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x180) = 0;

    local_4 = 0xffffffff;

    FUN_00680c50();

  }

  ExceptionList = local_c;

  return 0;

}
