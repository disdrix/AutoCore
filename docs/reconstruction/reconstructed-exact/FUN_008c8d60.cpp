// =============================================================================
// FUN_008c8d60
// -----------------------------------------------------------------------------
// Stable ID: aa_008c8d60
// Address:   0x008c8d60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008c8d60 @ 0x008c8d60
// Stable ID: aa_008c8d60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~86 non-empty decompiler lines.
//  - Control keywords: if×17, return×10, goto×5.
//  - Notable callees: FUN_007fca10, FUN_0087b500, FUN_008c8d60, FUN_00914890, FUN_0093e120.
//  - Return sites: 10.

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

uint32_t /* width from decompiler */ __thiscall FUN_008c8d60(int *param_1,int param_2,int param_3)



{

  char cVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint8_t *puVar5;

  int unaff_ESI;

  int unaff_EDI;

  uint8_t local_18 [8];

  uint8_t local_10 [8];

  uint8_t local_8 [8];

  

  if (param_3 == 40000) {

    if (param_2 == 8) {

      FUN_007fca10();

      return 1;

    }

    goto LAB_008c8db3;

  }

  if (param_3 == 0x9c41) {

    if (param_2 != 7) {

      if (param_2 == 8) {

        (**(code **)(*param_1 + 0x120))(local_18,1,0);

        if (DAT_00d1b6d8 == (int *)0x0) {

          return 1;

        }

        if (unaff_EDI != DAT_00d218c8) {

          return 1;

        }

        if (unaff_ESI != DAT_00d218cc) {

          return 1;

        }

LAB_008c8ed9:

        iVar4 = (**(code **)(*(int *)(*(int *)(DAT_00d1b6d8[1] + 4) + 4 + (int)DAT_00d1b6d8) + 0x19c

                            ))();

        if (iVar4 == 0) {

          iVar4 = 0;

        }

        else {

          iVar4 = *(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4;

        }

        FUN_0093e120(iVar4);

        return 1;

      }

      goto LAB_008c8db3;

    }

    iVar4 = *param_1;

    puVar5 = local_8;

  }

  else {

    if (param_3 != 0x9c42) goto LAB_008c8db3;

    if (param_2 != 7) {

      if (param_2 == 8) {

        (**(code **)(*param_1 + 0x120))(local_18,1,0);

        if (DAT_00d1b6d8 == (int *)0x0) {

          return 1;

        }

        if (unaff_EDI != DAT_00d218c8) {

          return 1;

        }

        if (unaff_ESI != DAT_00d218cc) {

          return 1;

        }

        if (((char)param_1[0x17a] != '\0') && (0 < (short)DAT_00d1b6d8[0x4b])) {

          if ((DAT_00d1b778 != (int *)0x0) &&

             (cVar1 = (**(code **)(*DAT_00d1b778 + 0x3d8))(), cVar1 != '\0')) {

            FUN_00914890();

          }

          (**(code **)(*DAT_00d1b6d8 + 0xac))(0);

          (**(code **)(*(int *)param_1[0x159] + 0x3ac))(0);

          return 1;

        }

        goto LAB_008c8ed9;

      }

      goto LAB_008c8db3;

    }

    iVar4 = *param_1;

    puVar5 = local_10;

  }

  piVar2 = (int *)(**(code **)(iVar4 + 0x120))(puVar5,1,0);

  DAT_00d218c8 = *piVar2;

  DAT_00d218cc = piVar2[1];

LAB_008c8db3:

  uVar3 = FUN_0087b500(param_2,param_3);

  return uVar3;

}
