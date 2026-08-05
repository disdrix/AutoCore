// =============================================================================
// FUN_008df870
// -----------------------------------------------------------------------------
// Stable ID: aa_008df870
// Address:   0x008df870  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008df870 @ 0x008df870
// Stable ID: aa_008df870
// Embedded strings (evidence for future rename):
//   - "You currently have other disciplines that rely on this discipline!  You must unlearn those"
//   - "Are you sure you want to unlearn this discipline?"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~75 non-empty decompiler lines.
//  - Control keywords: if×8, return×7, goto×2, switch×1.
//  - Notable callees: FUN_007a6de0×2, FUN_007fca10×2, FUN_007fdfb0×2, FUN_0052ad60, FUN_0052e0e0, FUN_007a69d0, FUN_007fbb30, FUN_007fef20.
//  - Strings: "Are you sure you want to unlearn this discipline?".
//  - Return sites: 7.

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

uint32_t /* width from decompiler */ __thiscall FUN_008df870(int *param_1,int param_2,int param_3)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint8_t local_10 [16];

  

  FUN_007a69d0();

  if ((param_3 < 0x9c43) || (0x9c53 < param_3)) {

LAB_008df9d1:

    if (param_3 == 40000) {

      if (param_2 != 8) goto LAB_008dfa49;

      FUN_007fca10();

    }

    else {

      if ((param_3 != 0x9c41) || (param_2 != 8)) {

LAB_008dfa49:

        uVar5 = FUN_0087b500(param_2,param_3);

        return uVar5;

      }

      (**(code **)(*param_1 + 0x120))(local_10,1,0);

      FUN_007fca10();

      FUN_007fef20(0xe,1,0);

      if ((DAT_00d1b8a8 != (int *)0x0) &&

         (cVar1 = (**(code **)(*DAT_00d1b8a8 + 0x3d8))(), cVar1 != '\0')) {

        (**(code **)(*DAT_00d1b8a8 + 0x114))(&stack0xffffffe4);

        return 1;

      }

    }

  }

  else {

    switch(param_2) {

    case 5:

      if (param_1[param_3 + -0x9add] != 0) {

        uVar7 = 1;

        uVar5 = 1;

        (**(code **)(*(int *)param_1[param_3 + -0x9add] + 0x120))(local_10,1,1);

        puVar2 = (uint32_t /* width from decompiler */ *)

                 (**(code **)(*(int *)param_1[param_3 + -0x9add] + 0x140))(&stack0xffffffec,1);

        func_0x007fd2b0(uVar5,uVar7,*puVar2,puVar2[1]);

        return 1;

      }

      break;

    case 6:

      FUN_007fbb30();

      return 1;

    default:

      goto LAB_008df9d1;

    case 8:

    case 0xe:

      iVar3 = param_1[param_3 + -0x9aee];

      param_1[0x1aa] = iVar3;

      if ((DAT_00d1b6d8 != 0) && (iVar3 = FUN_0052ad60(iVar3), 0 < iVar3)) {

        cVar1 = FUN_0052e0e0(param_1[0x1aa]);

        uVar7 = 0;

        uVar5 = 0;

        if (cVar1 == '\0') {

          uVar6 = 0xffffffff;

          uVar4 = FUN_007a6de0("You currently have other disciplines that rely on this discipline!  You must unlearn those first!"

                               ,0xffffffff);

          FUN_007fdfb0(&DAT_00d1a840,uVar4,uVar6,uVar5,uVar7);

          return 1;

        }

        uVar6 = 0x4e55;

        uVar4 = FUN_007a6de0("Are you sure you want to unlearn this discipline?",0xffffffff);

        FUN_007fdfb0(&DAT_00d1a840,uVar4,uVar6,uVar5,uVar7);

        return 1;

      }

    }

  }

  return 1;

}
