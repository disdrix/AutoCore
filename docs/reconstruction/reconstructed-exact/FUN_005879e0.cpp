// =============================================================================
// FUN_005879e0
// -----------------------------------------------------------------------------
// Stable ID: aa_005879e0
// Address:   0x005879e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005879e0 @ 0x005879e0
// Stable ID: aa_005879e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×11, return×2.
//  - Notable callees: FUN_004d4790×2, FUN_00570710×2, FUN_005710c0×2, FUN_00571b80×2, CONCAT44, CVOGCharacter_AddCredits, FUN_005879e0.
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

int FUN_005879e0(void *param_1,int param_2,int param_3,char param_4)



{

  int in_EAX;

  int *piVar1;

  int iVar2;

  int iVar3;

  longlong lVar4;

  

  if (param_1 != (void *)0x0) {

    if (param_4 == '\0') {

      lVar4 = CVOGCharacter_AddCredits(param_1,CONCAT44(-(param_3 + (uint)(param_2 != 0)),-param_2))

      ;

      return (int)lVar4;

    }

    in_EAX = 0;

    if ((*(int *)((int)param_1 + 0x250) != 0) &&

       (in_EAX = 0, *(int *)(*(int *)((int)param_1 + 0x250) + 0x2b0) != 0)) {

      piVar1 = (int *)FUN_005710c0(0x21a3,0,0);

      in_EAX = 0;

      if (piVar1 != (int *)0x0) {

        iVar2 = (**(code **)(*piVar1 + 0x25c))();

        iVar3 = param_2;

        if (iVar2 <= param_2) {

          iVar3 = (**(code **)(*piVar1 + 0x25c))();

        }

        in_EAX = FUN_00571b80(piVar1,iVar3,0);

        if (piVar1[0x2b] == 0) {

          FUN_004d4790(piVar1);

          in_EAX = FUN_00570710();

        }

        if (iVar3 < 2) {

          iVar3 = 1;

        }

        param_2 = param_2 - iVar3;

      }

    }

    if ((((0 < param_2) && (*(int *)((int)param_1 + 0xcbc) != 0)) &&

        (in_EAX = *(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xa8 + (int)param_1),

        in_EAX != 0)) && (*(char *)(in_EAX + 0xf5) != '\0')) {

      piVar1 = (int *)FUN_005710c0(0x21a3,0,0);

      in_EAX = 0;

      if (piVar1 != (int *)0x0) {

        iVar3 = (**(code **)(*piVar1 + 0x25c))();

        if (iVar3 <= param_2) {

          param_2 = (**(code **)(*piVar1 + 0x25c))();

        }

        in_EAX = FUN_00571b80(piVar1,param_2,0);

        if (piVar1[0x2b] == 0) {

          FUN_004d4790(piVar1);

          in_EAX = FUN_00570710();

        }

      }

    }

  }

  return in_EAX;

}
