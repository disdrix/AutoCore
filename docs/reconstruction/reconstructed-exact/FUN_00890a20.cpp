// =============================================================================
// FUN_00890a20
// -----------------------------------------------------------------------------
// Stable ID: aa_00890a20
// Address:   0x00890a20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00890a20 @ 0x00890a20
// Stable ID: aa_00890a20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×8, return×5, goto×1, while×1.
//  - Notable callees: FUN_004113b0×3, FUN_00890710×2, FUN_0041aed0, FUN_00427d20, FUN_004294f0, FUN_007fb9e0, FUN_0087b500, FUN_00890960.
//  - Return sites: 5.

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

uint32_t /* width from decompiler */ __thiscall FUN_00890a20(int param_1,int param_2,int param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  int local_4;

  

  local_4 = param_1;

  if (param_3 == 0x9c41) {

    if (param_2 != 7) goto LAB_00890a9c;

    if (DAT_00d1790c != '\0') {

      if (*(int *)(param_1 + 0x530) == 0) {

        DAT_00d17910 = 0;

        return 1;

      }

      param_1 = param_1 + 0x50c;

      param_3 = 0;

      local_4 = 0;

      FUN_004294f0();

      iVar1 = FUN_004113b0(param_1,&param_3);

      while (iVar3 = 0, iVar1 == 0) {

        if (param_3 == DAT_00d17910) {

          FUN_004113b0(param_1,&local_4);

          iVar3 = local_4;

          break;

        }

        iVar1 = FUN_004113b0(param_1,&param_3);

      }

      FUN_0041aed0();

      if (iVar3 == 0) {

        FUN_00427d20(0,&DAT_00d17910);

        FUN_00890710();

        return 1;

      }

      DAT_00d17910 = iVar3;

      FUN_00890710();

    }

  }

  else {

    if ((param_3 != 0x9c42) || (param_2 != 8)) {

LAB_00890a9c:

      uVar2 = FUN_0087b500(param_2,param_3);

      return uVar2;

    }

    FUN_00890960(0);

    if ((*(int *)(param_1 + 0x538) != 0) &&

       (iVar1 = (**(code **)(**(int **)(param_1 + 0x538) + 0x30c))(), iVar1 != 0)) {

      (**(code **)(**(int **)(param_1 + 0x538) + 0x30c))();

      FUN_007fb9e0();

      return 1;

    }

  }

  return 1;

}
