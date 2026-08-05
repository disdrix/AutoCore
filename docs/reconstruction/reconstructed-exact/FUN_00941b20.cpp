// =============================================================================
// FUN_00941b20
// -----------------------------------------------------------------------------
// Stable ID: aa_00941b20
// Address:   0x00941b20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00941b20 @ 0x00941b20
// Stable ID: aa_00941b20
// Embedded strings (evidence for future rename):
//   - "This item can only be changed in town."
//   - "There is not enough space in your inventory for this equipment."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~83 non-empty decompiler lines.
//  - Control keywords: if×9, return×6, for×1, do×1.
//  - Notable callees: FUN_007a69d0×3, FUN_007a6de0×3, FUN_007fdfb0×3, CONCAT31×2, FUN_004ce5f0, FUN_004fabc0, FUN_00513fc0, FUN_00522020.
//  - Strings: "This item can only be changed in town.".
//  - Return sites: 6.

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

uint32_t /* width from decompiler */ FUN_00941b20(int *param_1,uint32_t /* width from decompiler */ param_2,char param_3)



{

  int *piVar1;

  char cVar2;

  uint8_t uVar3;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  int iVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint uStack_10;

  uint uStack_c;

  uint8_t auStack_8 [8];

  

  piVar1 = param_1;

  if (((*(int *)(in_EAX + 0xe98) != 0) && (*(int *)(*(int *)(in_EAX + 0xe98) + 0x250) != 0)) &&

     (param_1 != (int *)0x0)) {

    if (*(int *)(param_1[0x2a] + 0x38) == 0xe) {

      uVar4 = (**(code **)(*param_1 + 0x1d4))();

      cVar2 = FUN_004ce5f0(uVar4);

      if ((cVar2 == '\0') && (*(int *)(*(int *)(in_EAX + 0xe98) + 0x6b4) < 1)) {

        FUN_007a69d0();

        uVar9 = 0;

        uVar8 = 1;

        uVar7 = 0xffffffff;

        uVar4 = FUN_007a6de0("This item can only be changed in town.",0xffffffff);

        FUN_007fdfb0(in_EAX,uVar4,uVar7,uVar8,uVar9);

        return 0;

      }

    }

    if (*(int *)(piVar1[0x2a] + 0x38) != 4) {

      FUN_007a69d0();

      iVar5 = FUN_00522020(param_2);

      param_1 = (int *)0x0;

      uStack_c = uStack_c & 0xffffff00;

      uStack_10 = uStack_10 & 0xffffff00;

      iVar6 = FUN_004fabc0(piVar1,&param_1);

      if (iVar6 != 0) {

        FUN_00931db0();

        return 0;

      }

      if (param_1 != (int *)0x0) {

        if (iVar5 == 0) {

          FUN_007fc270(2);

        }

        else {

          uVar3 = (**(code **)(*piVar1 + 0x250))();

          uStack_c = CONCAT31(uStack_c._1_3_,uVar3);

          uVar3 = (**(code **)(*piVar1 + 0x254))();

          uStack_10 = CONCAT31(uStack_10._1_3_,uVar3);

          cVar2 = FUN_005715d0(param_1,uStack_c,uStack_10,auStack_8);

          if ((cVar2 == '\0') &&

             (cVar2 = FUN_005714e0(param_1,&uStack_c,&uStack_10,1,0xffffffff), cVar2 == '\0')) {

            FUN_007a69d0();

            uVar9 = 0;

            uVar8 = 1;

            uVar7 = 0xffffffff;

            uVar4 = FUN_007a6de0("There is not enough space in your inventory for this equipment.",

                                 0xffffffff);

            FUN_007fdfb0(in_EAX,uVar4,uVar7,uVar8,uVar9);

            return 0;

          }

        }

      }

      if (((param_3 != '\0') && (((uint)piVar1[0x5f] >> 0x14 & 1) == 0)) &&

         (cVar2 = FUN_00513fc0(piVar1[0x58],piVar1[0x59]), cVar2 != '\0')) {

        uVar9 = 0;

        uVar8 = 1;

        uVar7 = 0x4e59;

        *(int **)(in_EAX + 0x3bf8) = piVar1;

        *(uint32_t /* width from decompiler */ *)(in_EAX + 0x3bfc) = param_2;

        uVar4 = FUN_007a6de0("Warning: This will permanently customize this item to you!  If you do this, you will no longer be able to trade it.  Are you sure?"

                             ,0xffffffff);

        FUN_007fdfb0(&DAT_00d1a840,uVar4,uVar7,uVar8,uVar9);

        return 0;

      }

      FUN_00931440(param_2);

      return 1;

    }

  }

  return 0;

}
