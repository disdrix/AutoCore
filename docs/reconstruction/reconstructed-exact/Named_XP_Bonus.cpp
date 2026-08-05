// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, goto×1.
//  - Notable callees: FUN_007a6de0×5, FUN_007a69d0, FUN_007fca10, FUN_007fef20, FUN_008a27a0, FUN_008f8200, FUN_0094cc00, sprintf.
//  - Strings: "chance that dropped items will be enhanced"; "and an additional"; "XP Bonus"; "When convoy members are in range, you can receive up to a".
//  - Return sites: 2.

// =============================================================================
// Named_XP_Bonus
// -----------------------------------------------------------------------------
// Stable ID: aa_0094cc00
// Address:   0x0094cc00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "XP Bonus"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_XP_Bonus(void)



{

  int *piVar1;

  char cVar2;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint uVar8;

  int iVar9;

  int iVar10;

  char local_200 [512];

  

  if (((*(int *)(in_EAX + 0xe98) != 0) &&

      (iVar10 = *(int *)(*(int *)(in_EAX + 0xe98) + 0xcb0), iVar10 != 0)) &&

     (1 < *(byte *)(iVar10 + 0x1d8))) {

    FUN_007a69d0();

    uVar8 = (uint)*(byte *)(*(int *)(*(int *)(in_EAX + 0xe98) + 0xcb0) + 0x1d8);

    uVar3 = FUN_007a6de0("chance that dropped items will be enhanced",0xffffffff);

    iVar10 = uVar8 - 1;

    uVar4 = FUN_007a6de0("and an additional",0xffffffff);

    uVar5 = FUN_007a6de0("XP Bonus",0xffffffff);

    iVar9 = uVar8 * 10;

    uVar6 = FUN_007a6de0("When convoy members are in range, you can receive up to a",0xffffffff);

    uVar7 = FUN_007a6de0("Current Convoy Size",0xffffffff);

    sprintf(local_200,"%s: %d. %s %+d%% %s %s %+d%% %s.",uVar7,uVar8,uVar6,iVar9,uVar5,uVar4,iVar10,

            uVar3);

    if (((*(int **)(in_EAX + 0xf40) != (int *)0x0) && (**(int **)(in_EAX + 0xf40) != 0)) &&

       (DAT_00d1b8dc != 0)) {

      FUN_008f8200(DAT_00d1b8dc,6,&DAT_00a156cc,local_200,0);

    }

  }

  piVar1 = *(int **)(in_EAX + 0x107c);

  if ((piVar1 != (int *)0x0) && (cVar2 = (**(code **)(*piVar1 + 0x3d8))(), cVar2 != '\0')) {

    if ((char)piVar1[0x14a] == '\0') {

      if ((*(int *)(in_EAX + 0xe98) != 0) && (*(int *)(*(int *)(in_EAX + 0xe98) + 0xcb0) != 0)) {

LAB_0094cd30:

        FUN_007fca10();

        FUN_007fef20(0x13,1,0);

        return;

      }

    }

    else if ((*(int *)(in_EAX + 0xe98) != 0) && (*(int *)(*(int *)(in_EAX + 0xe98) + 0xcb0) == 0))

    goto LAB_0094cd30;

    FUN_008a27a0();

  }

  return;

}
