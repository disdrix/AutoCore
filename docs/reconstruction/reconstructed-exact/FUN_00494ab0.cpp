// =============================================================================
// FUN_00494ab0
// -----------------------------------------------------------------------------
// Stable ID: aa_00494ab0
// Address:   0x00494ab0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00494ab0 @ 0x00494ab0
// Stable ID: aa_00494ab0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, do×1, goto×1, while×1.
//  - Notable callees: FUN_00494ab0, FUN_004bdd40, FUN_0074c8a0.
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

uint32_t /* width from decompiler */ __thiscall FUN_00494ab0(int param_1,uint32_t /* width from decompiler */ param_2,int param_3,uint32_t /* width from decompiler */ *param_4)



{

  int *piVar1;

  char cVar2;

  byte bVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ uVar5;

  byte bVar6;

  int iVar7;

  int iVar8;

  uint32_t /* width from decompiler */ uVar9;

  

  piVar4 = *(int **)(param_1 + 0xac);

  bVar6 = 0;

  if (piVar4 != *(int **)(param_1 + 0xb0)) {

    do {

      piVar1 = (int *)*piVar4;

      if ((param_4 == (uint32_t /* width from decompiler */ *)0x0) || (cVar2 = (**(code **)*param_4)(piVar1), cVar2 != '\0'))

      {

        if ((*(char *)(param_1 + 0x4d) == '\0') ||

           (((char *)piVar1[0x1e] == (char *)0x0 || (*(char *)piVar1[0x1e] != '\n')))) {

          bVar3 = (**(code **)(*piVar1 + 0x78))(param_2,param_3);

        }

        else {

          uVar9 = 0;

          iVar8 = param_3 + 0x10;

          iVar7 = param_3 + 4;

          uVar5 = (**(code **)(*piVar1 + 0xc))(iVar7,iVar8,0);

          (**(code **)(*piVar1 + 0x48))(uVar5);

          cVar2 = FUN_0074c8a0(uVar5,iVar7,iVar8,uVar9);

          if (cVar2 == '\0') goto LAB_00494b48;

          bVar3 = FUN_004bdd40(param_2,param_3);

        }

        bVar6 = bVar6 | bVar3;

      }

LAB_00494b48:

      piVar4 = piVar4 + 1;

    } while (piVar4 != *(int **)(param_1 + 0xb0));

    if (bVar6 != 0) {

      return *(uint32_t /* width from decompiler */ *)(param_3 + 0x38);

    }

  }

  return 0;

}
