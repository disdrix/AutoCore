// =============================================================================
// FUN_00870680
// -----------------------------------------------------------------------------
// Stable ID: aa_00870680
// Address:   0x00870680  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00870680 @ 0x00870680
// Stable ID: aa_00870680
// Embedded strings (evidence for future rename):
//   - "Please wait for next match"
//   - "Finished round"
//   - "%s %d / %d. %s."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~110 non-empty decompiler lines.
//  - Control keywords: if×23, return×4, goto×4, do×2, while×2, for×1.
//  - Notable callees: FUN_00870290×3, FUN_007a6de0×2, FUN_007a69d0, FUN_00870680, GetTickCount, sprintf.
//  - Strings: "Please wait for next match"; "Finished round"; "%s %d / %d. %s.".
//  - Return sites: 4.

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

void __thiscall FUN_00870680(int *param_1,int param_2)



{

  int in_EAX;

  int iVar1;

  DWORD DVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  int *piVar5;

  int iVar6;

  char acStack_400 [1024];

  

  param_1[0x143] = param_2;

  if (param_1[0x15f] == 0) {

    return;

  }

  if (param_2 == -1) {

    FUN_00870290();

    param_1[0x153] = 0x9c44;

    *(uint8_t *)(param_1 + 0x154) = 0;

    piVar5 = param_1 + 0x186;

    iVar6 = 4;

    do {

      if (piVar5[-4] != 0) {

        iVar1 = (**(code **)(*(int *)piVar5[-4] + 0x164))(0);

        *(uint8_t *)(iVar1 + 3) = 0;

      }

      if (*piVar5 != 0) {

        iVar1 = (**(code **)(*(int *)*piVar5 + 0x164))(0);

        *(uint8_t *)(iVar1 + 3) = 0;

      }

      piVar5 = piVar5 + 1;

      iVar6 = iVar6 + -1;

    } while (iVar6 != 0);

    piVar5 = (int *)param_1[0x170];

    if (DAT_00d1b20d == '\0') {

      if (piVar5 != (int *)0x0) {

        (**(code **)(*piVar5 + 4))(1);

      }

    }

    else if (piVar5 != (int *)0x0) {

      (**(code **)(*piVar5 + 4))(0);

    }

    if ((int *)param_1[0x171] != (int *)0x0) {

      (**(code **)(*(int *)param_1[0x171] + 4))(0);

    }

    if ((int *)param_1[0x172] == (int *)0x0) {

      return;

    }

    (**(code **)(*(int *)param_1[0x172] + 4))(0);

    return;

  }

  if (in_EAX != -1) {

    *(bool *)(param_1 + 0x157) = 0 < in_EAX;

    param_1[0x156] = in_EAX;

    DVar2 = GetTickCount();

    param_1[0x155] = DVar2;

  }

  if (DAT_00d1b6d8 == 0) goto LAB_00870853;

  iVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) + 0x28c

                      ))();

  if (iVar6 == param_2) {

    if (*(int *)(DAT_00d1b644 + 0xc960) == -1) goto LAB_00870853;

    if (*(short *)(DAT_00d1b644 + 0xc964) != *(short *)(DAT_00d1b644 + 0xc966)) {

      FUN_007a69d0();

      iVar6 = DAT_00d1b644;

      uVar3 = FUN_007a6de0("Please wait for next match",0xffffffff);

      iVar1 = *(ushort *)(iVar6 + 0xc966) + 1;

      iVar6 = *(ushort *)(iVar6 + 0xc964) + 1;

      uVar4 = FUN_007a6de0("Finished round",0xffffffff);

      sprintf(acStack_400,"%s %d / %d. %s.",uVar4,iVar6,iVar1,uVar3);

      FUN_00870290();

      goto LAB_00870853;

    }

  }

  else if (*(int *)(DAT_00d1b644 + 0xc960) == -1) goto LAB_00870853;

  FUN_00870290();

LAB_00870853:

  iVar6 = 0;

  piVar5 = param_1 + 0x146;

  do {

    if (*piVar5 == param_2) {

      if (param_1[iVar6 + 0x182] != 0) {

        iVar1 = (**(code **)(*(int *)param_1[iVar6 + 0x182] + 0x164))(0);

        *(uint8_t *)(iVar1 + 3) = 0x78;

      }

      if (param_1[iVar6 + 0x186] != 0) {

        iVar6 = (**(code **)(*(int *)param_1[iVar6 + 0x186] + 0x164))(0);

        *(uint8_t *)(iVar6 + 3) = 0x78;

      }

      break;

    }

    iVar6 = iVar6 + 1;

    piVar5 = piVar5 + 3;

  } while (iVar6 < 4);

  if ((DAT_00d1b20d == '\0') || ((char)param_1[0x157] == '\0')) {

    if ((int *)param_1[0x170] != (int *)0x0) {

      (**(code **)(*(int *)param_1[0x170] + 4))(1);

    }

  }

  else if ((int *)param_1[0x170] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0x170] + 4))(0);

  }

  if ((int *)param_1[0x171] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0x171] + 4))(0);

  }

  if ((int *)param_1[0x172] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0x172] + 4))(0);

  }

  (**(code **)(*param_1 + 0x448))();

  return;

}
