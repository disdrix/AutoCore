// =============================================================================
// FUN_00582670
// -----------------------------------------------------------------------------
// Stable ID: aa_00582670
// Address:   0x00582670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00582670 @ 0x00582670
// Stable ID: aa_00582670
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×6, goto×5, switch×2, return×1.
//  - Notable callees: FUN_004eb3b0×4, FUN_004a16d0×2, FUN_004b9270, FUN_004b9af0, FUN_00518370, FUN_00519d80, FUN_00582670.
//  - Return sites: 1.

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

void __thiscall FUN_00582670(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  char cVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  

  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x8c) + 4) + -0x8c + param_1) + 0xfc))();

  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x8c) + 4) + -0x8c + param_1) + 0x17c))();

  FUN_00518370(3);

  if (*(int *)(param_1 + -0x88) == 0) goto LAB_0058285a;

  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + -0x8c) + 4) + 0x1c + param_1);

  iVar4 = 0;

  FUN_004eb3b0();

  if (*(int *)(iVar1 + 0x88) != 0) {

    switch(param_2) {

    case 1:

      uVar3 = 0x12;

      break;

    case 2:

      uVar3 = 1;

      break;

    case 3:

      uVar3 = 0x10;

      break;

    case 4:

      uVar3 = 0x11;

      break;

    default:

      goto switchD_00582706_default;

    }

    switch(uVar3) {

    case 1:

switchD_0058273a_caseD_1:

      FUN_004eb3b0();

      uVar3 = 1;

      break;

    default:

      goto switchD_00582706_default;

    case 0x10:

    case 0x11:

      FUN_004eb3b0();

      iVar4 = FUN_004a16d0(uVar3,1,0xffffffff);

      if (iVar4 == 0) goto switchD_0058273a_caseD_1;

      goto LAB_005827b6;

    case 0x12:

      FUN_004eb3b0();

      uVar3 = 0x12;

    }

    iVar4 = FUN_004a16d0(uVar3,1,0xffffffff);

    if (iVar4 != 0) {

LAB_005827b6:

      *(uint32_t /* width from decompiler */ *)(iVar4 + 0x2c) =

           *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0x8c) + 4) + 0x18 + param_1);

      FUN_004b9af0(param_1 + -0x90);

      FUN_004b9270(iVar4);

    }

  }

switchD_00582706_default:

  cVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x8c) + 4) + -0x8c + param_1) + 0x198))

                    ();

  if ((cVar2 == '\0') &&

     (*(char *)(*(int *)(*(int *)(param_1 + -0x8c) + 4) + 0xdc + param_1) == '\0')) {

    (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x8c) + 4) + -0x8c + param_1) + 0x144))();

    (**(code **)(*(int *)(param_1 + -0x90) + 4))();

    if (((*(uint *)(*(int *)(*(int *)(param_1 + -0x8c) + 4) + 0xf0 + param_1) >> 0xc & 1) != 0) &&

       (iVar4 != 0)) {

      *(uint8_t *)(iVar4 + 9) = 1;

    }

  }

LAB_0058285a:

  FUN_00519d80(param_2);

  return;

}
