// =============================================================================
// FUN_0083e4e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0083e4e0
// Address:   0x0083e4e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0083e4e0 @ 0x0083e4e0
// Stable ID: aa_0083e4e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~134 non-empty decompiler lines.
//  - Control keywords: if×14, return×14, do×3, while×3, switch×2, goto×1.
//  - Notable callees: FUN_0083dae0×3, FUN_007fbbb0×2, atoi×2, Client_SendInventoryGrab_FromGrid, FUN_0083dc20, FUN_0083dcb0, FUN_0083e4e0, FUN_008bff90.
//  - Return sites: 14.

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

uint32_t /* width from decompiler */ __thiscall FUN_0083e4e0(int *param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  int *piVar1;

  char cVar2;

  char *pcVar3;

  char *pcVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  char acStack_50 [15];

  char acStack_41 [65];

  

  switch(param_3) {

  case 40000:

  case 0x9c41:

  case 0x9c42:

  case 0x9c43:

  case 0x9c44:

  case 0x9c45:

  case 0x9c46:

  case 0x9c47:

  case 0x9c48:

  case 0x9c49:

    if ((param_2 != 7) && (param_2 != 9)) {

      return 1;

    }

    FUN_0083dcb0();

    return 1;

  case 0x9c4a:

    if ((param_2 == 7) || (param_2 == 9)) {

      FUN_0083dc20();

    }

    return 1;

  case 0x9c4b:

    if ((param_2 == 7) || (param_2 == 9)) {

      pcVar3 = (char *)(**(code **)(*(int *)param_1[0x144] + 0x1dc))();

      pcVar4 = acStack_41;

      do {

        pcVar4 = pcVar4 + 1;

        cVar2 = *pcVar3;

        *pcVar4 = cVar2;

        pcVar3 = pcVar3 + 1;

      } while (cVar2 != '\0');

      pcVar4 = acStack_41 + 1;

      do {

        cVar2 = *pcVar4;

        pcVar4 = pcVar4 + 1;

      } while (cVar2 != '\0');

      if (pcVar4 != acStack_41 + 2) {

        pcVar4 = acStack_41;

        do {

          pcVar4 = pcVar4 + 1;

        } while (*pcVar4 != '\0');

        pcVar4[-1] = '\0';

        iVar5 = atoi(acStack_41 + 1);

        param_1[0x13f] = iVar5;

        FUN_0083dae0();

      }

    }

    return 1;

  case 0x9c4c:

    if (param_2 == 8) {

      if (param_1[0x142] == 0) {

        if (((((param_1[0x140] != 0) && (0 < param_1[0x13f])) &&

             (cVar2 = FUN_0093c700(param_1[0x140],param_1[0x13f]), piVar1 = DAT_00d1b89c,

             cVar2 != '\0')) &&

            ((DAT_00d1b89c != (int *)0x0 &&

             (cVar2 = (**(code **)(*DAT_00d1b89c + 0x3d8))(), cVar2 != '\0')))) &&

           (piVar1[0x16c] != 0)) {

          FUN_008bff90(param_1[0x140]);

        }

      }

      else {

        switch(*(uint32_t /* width from decompiler */ *)(param_1[0x142] + 0x494)) {

        case 1:

          iVar5 = *(int *)(*(int *)(DAT_00d1b880 + 0x50c) + 0x580);

          break;

        default:

          goto switchD_0083e620_caseD_2;

        case 3:

          iVar5 = *(int *)(*(int *)(DAT_00d1b874 + 0x510) + 0x580);

          break;

        case 4:

          iVar5 = DAT_00d1b89c[0x160];

          break;

        case 5:

          iVar5 = *(int *)(DAT_00d1b890 + 0x588);

        }

        if ((iVar5 != 0) && (0 < param_1[0x13f])) {

          Client_SendInventoryGrab_FromGrid(iVar5,param_1[0x13f]);

          return 1;

        }

      }

switchD_0083e620_caseD_2:

      FUN_007fbbb0();

      return 1;

    }

    break;

  case 0x9c4d:

    if ((param_2 == 7) || (param_2 == 9)) {

      param_1[0x13f] = 0;

      FUN_0083dae0();

      return 1;

    }

    break;

  case 0x9c4e:

    if (param_2 == 0) {

      pcVar4 = (char *)(**(code **)(*(int *)param_1[0x144] + 0x1dc))();

      iVar5 = atoi(pcVar4);

      param_1[0x13f] = iVar5;

      FUN_0083dae0();

      if (iVar5 == param_1[0x13f]) {

        return 1;

      }

      sprintf(acStack_50,"%i",param_1[0x13f]);

      (**(code **)(*(int *)param_1[0x144] + 0x3ac))(acStack_50);

      return 1;

    }

    break;

  case 0x9c4f:

    if (param_2 != 8) {

      return 1;

    }

    FUN_007fbbb0();

    return 1;

  }

  if ((6 < param_2) && (param_2 < 0x10)) {

    return 1;

  }

  cVar2 = (**(code **)(*param_1 + 0xd8))();

  if ((cVar2 != '\0') && ((int *)param_1[0xac] != (int *)0x0)) {

    uVar6 = (**(code **)(*(int *)param_1[0xac] + 0x338))(param_2,param_3);

    return uVar6;

  }

  return 0;

}
