// =============================================================================
// UI_macro_icon
// -----------------------------------------------------------------------------
// Stable ID: aa_00827670
// Address:   0x00827670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_macro_icon @ 0x00827670
// Stable ID: aa_00827670
// Embedded strings (evidence for future rename):
//   - "Power"
//   - "Battle"
//   - "i_d_macro_2d_wnd_icon.dds"
//   - "(%d)"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~87 non-empty decompiler lines.
//  - Control keywords: if×14, return×1.
//  - Notable callees: FUN_008264f0, FUN_00826780, UI_macro_icon, sprintf.
//  - Strings: "Power"; "Battle"; "i_d_macro_2d_wnd_icon.dds"; "(%d)".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_macro_2d_wnd_icon.dds"
 * Domain alias of FUN_00827670 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ UI_macro_icon(int param_1)



{

  int iVar1;

  bool bVar2;

  int iVar3;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar4;

  int *unaff_ESI;

  char acStack_c [8];

  uint8_t uStack_4;

  uint8_t uStack_3;

  uint8_t uStack_2;

  uint8_t uStack_1;

  

  iVar3 = param_1;

  if (((unaff_ESI[0x152] == in_EAX) && (unaff_ESI[0x154] == param_1)) &&

     (unaff_ESI[0x155] == param_1 >> 0x1f)) {

    bVar2 = false;

  }

  else {

    bVar2 = true;

  }

  unaff_ESI[0x154] = param_1;

  unaff_ESI[0x155] = param_1 >> 0x1f;

  unaff_ESI[0x157] = unaff_ESI[0x140] + unaff_ESI[0x141] * 10;

  unaff_ESI[0x152] = in_EAX;

  unaff_ESI[0x156] = 0;

  CVOGCharacter_SetQuickBarItem

            (DAT_00d1b6d8,(char)unaff_ESI[0x141] * '\n' + (char)unaff_ESI[0x140],unaff_ESI[0x154],

             unaff_ESI[0x155]);

  CVOGCharacter_SetQuickBarSkill

            (DAT_00d1b6d8,(char)unaff_ESI[0x141] * '\n' + (char)unaff_ESI[0x140],-1);

  if ((bVar2) && ((char)unaff_ESI[0x13f] != '\0')) {

    FUN_00826780(0);

  }

  *(uint8_t *)((int)unaff_ESI + 0x4fe) = 0;

  if ((int *)unaff_ESI[0x15f] != (int *)0x0) {

    (**(code **)(*(int *)unaff_ESI[0x15f] + 4))(1);

  }

  if ((int *)unaff_ESI[0x159] != (int *)0x0) {

    (**(code **)(*(int *)unaff_ESI[0x159] + 0x58))();

    if (in_EAX == 3) {

      (**(code **)(*(int *)unaff_ESI[0x159] + 0x1d8))(&DAT_00a1419b,1,1);

      if ((int *)unaff_ESI[0x15e] != (int *)0x0) {

        (**(code **)(*(int *)unaff_ESI[0x15e] + 0x1d8))(0,1,1);

      }

      if ((int *)unaff_ESI[0x15d] != (int *)0x0) {

        (**(code **)(*(int *)unaff_ESI[0x15d] + 0x1d8))("Power",1,1);

      }

    }

    else if (in_EAX == 4) {

      (**(code **)(*(int *)unaff_ESI[0x159] + 0x1d8))(&DAT_00a1419b,1,1);

      if ((int *)unaff_ESI[0x15e] != (int *)0x0) {

        (**(code **)(*(int *)unaff_ESI[0x15e] + 0x1d8))(0,1,1);

      }

      if ((int *)unaff_ESI[0x15d] != (int *)0x0) {

        (**(code **)(*(int *)unaff_ESI[0x15d] + 0x1d8))("Battle",1,1);

      }

    }

    else if (in_EAX == 5) {

      (**(code **)(*(int *)unaff_ESI[0x159] + 0x1d8))(&DAT_00a1419b,1,1);

      iVar1 = *(int *)unaff_ESI[0x159];

      uVar4 = (**(code **)(iVar1 + 0x2c8))(0);

      (**(code **)(iVar1 + 0x50))("i_d_macro_2d_wnd_icon.dds",uVar4);

      sprintf(acStack_c,"(%d)",iVar3 + 0xbb9);

      if ((int *)unaff_ESI[0x15e] != (int *)0x0) {

        (**(code **)(*(int *)unaff_ESI[0x15e] + 0x1d8))(acStack_c,1,1);

      }

      FUN_008264f0(unaff_ESI);

    }

    if ((int *)unaff_ESI[0x15e] != (int *)0x0) {

      (**(code **)(*(int *)unaff_ESI[0x15e] + 0x34c))();

    }

    if ((int *)unaff_ESI[0x15d] != (int *)0x0) {

      (**(code **)(*(int *)unaff_ESI[0x15d] + 0x34c))();

    }

    param_1 = -1;

    (**(code **)(*(int *)unaff_ESI[0x159] + 0x15c))(1,&param_1);

    uStack_2 = 0xff;

    uStack_3 = 0xff;

    uStack_4 = 0xff;

    uStack_1 = 0xff;

    (**(code **)(*(int *)unaff_ESI[0x159] + 0x15c))(0,&uStack_4);

    (**(code **)(*(int *)unaff_ESI[0x159] + 0x34c))();

  }

  (**(code **)(*unaff_ESI + 0x448))();

  return 1;

}
