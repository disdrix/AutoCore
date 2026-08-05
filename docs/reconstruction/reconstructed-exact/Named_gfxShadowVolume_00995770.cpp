// READABILITY (auto CF):
//  - Body size: ~181 non-empty decompiler lines.
//  - Control keywords: if×21, return×3, do×2, while×2.
//  - Notable callees: vog_LogMessage×3, FUN_00414c20×2, FUN_0044b9c0×2, FUN_0044bbc0×2, FUN_00450e60×2, FUN_0076cec0×2, CONCAT31, FUN_00414b60.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxShadowVolume.cpp"; "Creating Static Shadow Volume Object:"; "PalShadowProjection.fx"; "Initial Mesh Piece Contains: %d verts, %d faces".
//  - Return sites: 3.

// =============================================================================
// Named_gfxShadowVolume_00995770
// -----------------------------------------------------------------------------
// Stable ID: aa_00995770
// Address:   0x00995770  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxShadowVolume"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int * Named_gfxShadowVolume_00995770(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  int *piVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  undefined *puVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  int *piVar10;

  int iStack_40;

  int *piStack_38;

  undefined **ppuStack_34;

  int *piStack_30;

  undefined **ppuStack_2c;

  int *piStack_28;

  uint8_t auStack_20 [20];

  uint32_t /* width from decompiler */ *puStack_c;

  uint8_t *puStack_8;

  uint uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b2318;

  puStack_c = ExceptionList;

  ExceptionList = &puStack_c;

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxShadowVolume.cpp",0xda,1,

                 "Creating Static Shadow Volume Object:");

  piVar2 = (int *)(**(code **)(*(int *)*param_1 + 0x7c))();

  iVar8 = 0;

  if (piVar2 == (int *)0x0) {

    ExceptionList = puStack_c;

    return (int *)0x0;

  }

  piVar2[0x2f] = piVar2[0x2f] | 0x40;

  (**(code **)(*piVar2 + 0x68))();

  FUN_00989e00(&piStack_38,"PalShadowProjection.fx");

  FUN_009701d0(&piStack_38);

  piStack_30 = (int *)0x0;

  ppuStack_34 = &PTR_FUN_00a9db18;

  piStack_28 = (int *)0x0;

  ppuStack_2c = &PTR_FUN_00a9da80;

  iVar4 = 0;

  iVar6 = 0;

  uStack_4._0_1_ = 1;

  uStack_4._1_3_ = 0;

  if (0 < param_2) {

    do {

      iVar9 = *(int *)(param_1[iVar4] + 0x14);

      if (iVar9 == 0) {

        iVar9 = 0;

      }

      else {

        iVar9 = *(int *)(iVar9 + 0x18);

      }

      iVar7 = *(int *)(param_1[iVar4] + 0xc);

      iVar6 = iVar6 + iVar9;

      if (iVar7 == 0) {

        iVar9 = 0;

      }

      else {

        iVar9 = *(int *)(iVar7 + 0x1c);

      }

      iVar4 = iVar4 + 1;

      iVar8 = iVar8 + iVar9;

    } while (iVar4 < param_2);

    if ((iVar6 != 0) && (iVar8 != 0)) {

      uVar3 = FUN_00414bc0(0x100c);

      uStack_4._0_1_ = 2;

      FUN_00414c20(iVar6,uVar3,8,0);

      uStack_4 = CONCAT31(uStack_4._1_3_,1);

      FUN_00414b60();

      piVar10 = (int *)0x0;

      FUN_0044b9c0(iVar8,8,0);

      uVar3 = FUN_0076cec0(&puStack_c,"Initial Mesh Piece Contains: %d verts, %d faces",iVar6,

                           iVar8 / 3);

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxShadowVolume.cpp",0xf7,1,

                     uVar3);

      iVar8 = 0;

      iVar4 = 0;

      iVar6 = 0;

      do {

        iVar9 = param_1[iVar6];

        FUN_0044bbc0(iVar9 + 0x10,0,iVar8);

        FUN_00450e60(iVar9 + 8,0,iVar4,iVar8);

        if (*(int *)(iVar9 + 0x14) == 0) {

          iVar7 = 0;

        }

        else {

          iVar7 = *(int *)(*(int *)(iVar9 + 0x14) + 0x18);

        }

        iVar8 = iVar8 + iVar7;

        if (*(int *)(iVar9 + 0xc) == 0) {

          iVar9 = 0;

        }

        else {

          iVar9 = *(int *)(*(int *)(iVar9 + 0xc) + 0x1c);

        }

        iVar4 = iVar4 + iVar9;

        iVar6 = iVar6 + 1;

        param_1 = puStack_c;

      } while (iVar6 < (int)puStack_8);

      iVar8 = FUN_00994b40();

      if (-1 < iVar8) {

        if (piStack_38 == (int *)0x0) {

          iVar8 = 0;

        }

        else {

          iVar8 = piStack_38[7];

        }

        piVar2[0x2a] = iVar8 / 3;

        puVar5 = (undefined *)(*(int *)(piVar2[8] + 0x14) + 0xac);

        if (*(int *)(piVar2[8] + 0x14) == 0) {

          puVar5 = &DAT_00d1eccc;

        }

        if (iStack_40 == 0) {

          uVar3 = 0;

        }

        else {

          uVar3 = *(uint32_t /* width from decompiler */ *)(iStack_40 + 0x18);

        }

        piVar2[0x2f] = piVar2[0x2f] | 1;

        FUN_00414c20(uVar3,puVar5,0x20,0);

        piVar2[0x2f] = piVar2[0x2f] | 1;

        FUN_0044bbc0(&stack0xffffffbc,0,0);

        if (piStack_38 == (int *)0x0) {

          iVar8 = 0;

        }

        else {

          iVar8 = piStack_38[7];

        }

        FUN_0044b9c0(iVar8,0x20,0,0);

        FUN_00450e60(&stack0xffffffb4,0,0,0);

        iVar8 = (**(code **)(*piVar2 + 0x50))(0x5400000);

        if (iVar8 < 0) {

          uVar3 = FUN_0076cec0(auStack_20,"Unable to optimize shadow mesh");

          vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxShadowVolume.cpp",0x123,

                         2,uVar3);

        }

        piVar2[0x2f] = piVar2[0x2f] | 0x20;

        piStack_28 = (int *)((uint)piStack_28 & 0xffffff00);

        if (piStack_38 != (int *)0x0) {

          piVar1 = piStack_38 + 1;

          *piVar1 = *piVar1 + -1;

          if (*piVar1 == 0) {

            (**(code **)(*piStack_38 + 8))();

          }

        }

        piStack_28 = (int *)0xffffffff;

        if (piVar10 != (int *)0x0) {

          piVar1 = piVar10 + 1;

          *piVar1 = *piVar1 + -1;

          if (*piVar1 == 0) {

            (**(code **)(*piVar10 + 8))();

          }

        }

        ExceptionList = piStack_30;

        return piVar2;

      }

      (**(code **)*piVar2)(1);

      uStack_4 = uStack_4 & 0xffffff00;

      if (piStack_28 != (int *)0x0) {

        piVar2 = piStack_28 + 1;

        *piVar2 = *piVar2 + -1;

        if (*piVar2 == 0) {

          (**(code **)(*piStack_28 + 8))();

        }

      }

      uStack_4 = 0xffffffff;

      if (piStack_30 != (int *)0x0) {

        piVar2 = piStack_30 + 1;

        *piVar2 = *piVar2 + -1;

        if (*piVar2 == 0) {

          (**(code **)(*piStack_30 + 8))();

        }

      }

    }

  }

  ExceptionList = puStack_c;

  return (int *)0x0;

}
