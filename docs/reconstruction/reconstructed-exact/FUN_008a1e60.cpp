// =============================================================================
// FUN_008a1e60
// -----------------------------------------------------------------------------
// Stable ID: aa_008a1e60
// Address:   0x008a1e60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008a1e60 @ 0x008a1e60
// Stable ID: aa_008a1e60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~81 non-empty decompiler lines.
//  - Control keywords: if×11, return×9, switch×1.
//  - Notable callees: FUN_008a0fb0×2, Client_QuickBar_ActivateSlot, FUN_007fb990, FUN_007fc9b0, FUN_0087b500, FUN_008a04b0, FUN_008a1e60, FUN_0090d400.
//  - Return sites: 9.

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

uint32_t /* width from decompiler */ __thiscall FUN_008a1e60(int *param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  int *piVar1;

  int *piVar2;

  char cVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  

  piVar2 = DAT_00d09a44;

  switch(param_3) {

  case 40000:

    if (param_2 == 8) {

      FUN_007fc9b0();

      return 1;

    }

    break;

  case 0x9c42:

    if (param_2 == 8) {

      piVar1 = (int *)param_1[0xac];

      if ((((piVar1 != (int *)0x0) && (DAT_00d1b644 != 0)) &&

          (*(char *)(DAT_00d1b644 + 0xf6) == '\0')) && (DAT_00d09a44 != (int *)0x0)) {

        cVar3 = (**(code **)(*DAT_00d09a44 + 0x3d8))();

        if (cVar3 != '\0') {

          FUN_0090d400();

          return 1;

        }

        cVar3 = (**(code **)(*piVar2 + 0x3d8))();

        if (cVar3 == '\0') {

          (**(code **)(*piVar1 + 0x3ec))();

          (**(code **)(*piVar1 + 0x3f4))(1);

          (**(code **)(*piVar1 + 0xa8))(piVar2);

          (**(code **)(*piVar2 + 0xcc))(1);

          (**(code **)(*piVar2 + 0x43c))();

        }

      }

      return 1;

    }

    break;

  case 0x9c43:

    if (param_2 == 8) {

      iVar4 = (**(code **)(*param_1 + 0xe8))();

      if (iVar4 != -1) {

        FUN_008a04b0();

        *(char *)((int)param_1 + 0x521) = (char)param_1[0x148];

        FUN_007fb990();

      }

      return 1;

    }

    break;

  case 0x9c46:

    if (param_2 == 8) {

      FUN_008a0fb0(0xffffffff);

      return 1;

    }

    break;

  case 0x9c47:

    if (param_2 == 8) {

      FUN_008a0fb0(1);

      return 1;

    }

    break;

  case 0x9c48:

  case 0x9c49:

  case 0x9c4a:

  case 0x9c4b:

  case 0x9c4c:

  case 0x9c4d:

  case 0x9c4e:

  case 0x9c4f:

  case 0x9c50:

  case 0x9c51:

    if (param_2 == 7) {

      return 1;

    }

    if (param_2 == 8) {

      Client_QuickBar_ActivateSlot((char)param_3 + -0x48,0,0xffffffff);

      return 1;

    }

  }

  uVar5 = FUN_0087b500(param_2,param_3);

  return uVar5;

}
