// =============================================================================
// FUN_008f7520
// -----------------------------------------------------------------------------
// Stable ID: aa_008f7520
// Address:   0x008f7520  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008f7520 @ 0x008f7520
// Stable ID: aa_008f7520
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×5, return×4, do×1, while×1.
//  - Notable callees: FUN_008f5dd0×2, FUN_008f7520.
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

uint32_t /* width from decompiler */ __thiscall FUN_008f7520(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  char cVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  int unaff_EBX;

  int iVar5;

  int *piVar6;

  int *piVar7;

  uint8_t local_c [4];

  uint32_t /* width from decompiler */ uStack_8;

  int local_4;

  

  local_4 = (int)(short)((uint)param_2 >> 0x10);

  piVar6 = (int *)0x0;

  iVar3 = (**(code **)(*param_1 + 0x120))(local_c,1,1);

  iVar5 = DAT_00d1d870 - *(int *)(iVar3 + 4);

  piVar7 = param_1 + 0x150;

  iVar3 = 2;

  do {

    iVar1 = *piVar7;

    if ((iVar1 != 0) && (*(int *)(iVar1 + 0xe80) != 0)) {

      cVar2 = (**(code **)(**(int **)(iVar1 + 0xe80) + 0xd8))();

      if ((cVar2 != '\0') &&

         ((piVar6 == (int *)0x0 ||

          ((iVar5 < *(int *)(*piVar7 + 0x10ec) && (*(int *)(*piVar7 + 0x10e4) <= iVar5)))))) {

        piVar6 = *(int **)(*piVar7 + 0xe80);

      }

    }

    piVar7 = piVar7 + 1;

    iVar3 = iVar3 + -1;

  } while (iVar3 != 0);

  if (piVar6 != (int *)0x0) {

    if (0 < unaff_EBX) {

      (**(code **)(*piVar6 + 0x45c))(0xbf800000);

      FUN_008f5dd0();

      return 1;

    }

    (**(code **)(*piVar6 + 0x45c))(0x3f800000);

    FUN_008f5dd0();

    return 1;

  }

  cVar2 = (**(code **)(*param_1 + 0x3d8))();

  if ((cVar2 != '\0') && (param_1[0x12e] != 0)) {

    uVar4 = (**(code **)(*(int *)param_1[0x12e] + 0x39c))(uStack_8,local_4);

    return uVar4;

  }

  return 0;

}
