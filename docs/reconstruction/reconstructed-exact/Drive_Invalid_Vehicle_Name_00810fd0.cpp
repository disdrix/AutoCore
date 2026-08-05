// READABILITY (auto CF):
//  - Body size: ~81 non-empty decompiler lines.
//  - Control keywords: if×10, return×6, do×1, while×1.
//  - Notable callees: FUN_0040abb0, FUN_004f8ce0, FUN_004faaf0, FUN_004fab40, FUN_004fcd80, FUN_004fd970, FUN_007a69d0, FUN_007a6de0.
//  - Strings: "You Do Not Have Enough Trick Materials!"; "You Do Not Have Enough Paint Cans!"; "You Do Not Have Enough Credits!"; "Invalid Vehicle Name!".
//  - Return sites: 6.

// =============================================================================
// Drive_Invalid_Vehicle_Name_00810fd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00810fd0
// Address:   0x00810fd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Invalid Vehicle Name!"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Drive_Invalid_Vehicle_Name_00810fd0(uint32_t /* width from decompiler */ param_1)



{

  char cVar1;

  int in_EAX;

  int *piVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int unaff_retaddr;

  char *pcVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  

  FUN_007a69d0();

  piVar2 = (int *)CVOGReaction_ResolveObjectTarget

                            (*(uint8_t *)(in_EAX + 0x10),*(uint32_t /* width from decompiler */ *)(in_EAX + 8),

                             *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc));

  if (((piVar2 == (int *)0x0) || (*(int *)(piVar2[0x2a] + 0x38) != 0xe)) ||

     (iVar3 = (**(code **)(*piVar2 + 0x1d4))(), iVar3 == 0)) {

    return;

  }

  iVar3 = *(int *)(in_EAX + 0x74);

  if (iVar3 == 2) {

    pcVar6 = "You Do Not Have Enough Trick Materials!";

  }

  else if (iVar3 == 4) {

    pcVar6 = "You Do Not Have Enough Paint Cans!";

  }

  else if (iVar3 == 3) {

    pcVar6 = "You Do Not Have Enough Credits!";

  }

  else {

    if (iVar3 != 5) {

      if (iVar3 != 0) {

        return;

      }

      iVar3 = 0;

      puVar5 = (uint32_t /* width from decompiler */ *)(in_EAX + 0x18);

      do {

        FUN_004f8ce0(iVar3,*puVar5);

        iVar3 = iVar3 + 1;

        puVar5 = puVar5 + 1;

      } while (iVar3 < 8);

      FUN_004faaf0(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x3c));

      FUN_004fab40(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x40));

      FUN_004fd970(*(uint8_t *)(in_EAX + 0x38));

      FUN_004fcd80(0);

      if (*(char *)(in_EAX + 0x50) != '\0') {

        FUN_0040abb0();

      }

      iVar3 = (**(code **)(*piVar2 + 0x210))(0);

      if (iVar3 != 0) {

        uVar4 = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x48);

        uVar7 = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x4c);

        iVar3 = (**(code **)(*piVar2 + 0x210))(0);

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x720) = uVar4;

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x724) = uVar7;

      }

      piVar2 = *(int **)(unaff_retaddr + 0x1048);

      if (piVar2 == (int *)0x0) {

        return;

      }

      cVar1 = (**(code **)(*piVar2 + 0x3d8))();

      if (cVar1 == '\0') {

        return;

      }

      FUN_008fd1e0();

      FUN_008fd160();

      FUN_008ff5a0();

      (**(code **)(*piVar2 + 0x448))();

      return;

    }

    pcVar6 = "Invalid Vehicle Name!";

  }

  uVar9 = 0;

  uVar8 = 1;

  uVar7 = 0xffffffff;

  uVar4 = FUN_007a6de0(pcVar6,0xffffffff);

  FUN_007fdfb0(param_1,uVar4,uVar7,uVar8,uVar9);

  return;

}
