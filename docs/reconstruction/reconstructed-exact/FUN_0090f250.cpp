// =============================================================================
// FUN_0090f250
// -----------------------------------------------------------------------------
// Stable ID: aa_0090f250
// Address:   0x0090f250  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0090f250 @ 0x0090f250
// Stable ID: aa_0090f250
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×7, return×2, goto×2, switch×1.
//  - Notable callees: FUN_0040b1b0, FUN_007f9df0, FUN_0090f250, Object_GetRootRaceId.
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

void __thiscall FUN_0090f250(int *param_1,uint32_t /* width from decompiler */ *param_2)



{

  char cVar1;

  int iVar2;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  puStack_c = &LAB_009af093;

  local_10 = ExceptionList;

  local_8 = 0;

  if (DAT_00d1b9a8 == (int *)0x0) {

    return;

  }

  if (DAT_00d1d900 == -1) {

    if (param_1[0x12e] == 0) {

      ExceptionList = &local_10;

      if (param_1[0x1d6] != 0) {

        ExceptionList = &local_10;

        if (DAT_00d1b6d8 == 0) goto LAB_0090f43a;

        ExceptionList = &local_10;

        iVar2 = (**(code **)(*(int *)param_1[0x1d6] + 0x1d8))();

        if (((iVar2 == 0) || (cVar1 = FUN_0040b1b0(), cVar1 == '\0')) &&

           (cVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 +

                                         DAT_00d1b6d8) + 0x298))(param_1[0x1d6]), cVar1 != '\0')) {

          Object_GetRootRaceId((void *)param_1[0x1d6]);

        }

      }

    }

    else {

      ExceptionList = &local_10;

      cVar1 = (**(code **)(*param_1 + 0x3e4))();

      if (((cVar1 != '\0') &&

          (cVar1 = (**(code **)(*(int *)param_1[0x12e] + 0xd8))(), cVar1 != '\0')) &&

         (DAT_00d1b9a8[0x13b] == 1)) goto LAB_0090f43a;

    }

  }

  else {

    switch(DAT_00d1d900) {

    case 0:

      ExceptionList = &local_10;

      break;

    default:

      ExceptionList = &local_10;

      break;

    case 2:

      ExceptionList = &local_10;

      break;

    case 3:

      ExceptionList = &local_10;

      break;

    case 4:

      ExceptionList = &local_10;

      break;

    case 5:

      ExceptionList = &local_10;

    }

  }

  FUN_007f9df0();

LAB_0090f43a:

  (**(code **)(*DAT_00d1b9a8 + 0x33c))(*param_2);

  ExceptionList = local_10;

  return;

}
