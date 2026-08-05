// =============================================================================
// Named_AllocateNewObjectFromCbidFailed_0090ed80
// -----------------------------------------------------------------------------
// Stable ID: aa_0090ed80
// Address:   0x0090ed80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_AllocateNewObjectFromCbidFailed_0090ed80 @ 0x0090ed80
// Stable ID: aa_0090ed80
// Embedded strings (evidence for future rename):
//   - "allocatenewobjectfromcbid failed %d Get a programmer"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~82 non-empty decompiler lines.
//  - Control keywords: if×11, return×4, do×1, while×1, goto×1.
//  - Notable callees: CVOGReaction_GiveItemByCbid×4, Vehicle_AttachWeapon×2, FUN_004f8ce0, FUN_004faaf0, FUN_004fab40, FUN_004fd970, FUN_007a4480, Named_AllocateNewObjectFromCbidFailed_0090ed80.
//  - Strings: "allocatenewobjectfromcbid failed %d Get a programmer".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "allocatenewobjectfromcbid failed %d Get a programmer"
 * Domain alias of FUN_0090ed80 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __thiscall Named_AllocateNewObjectFromCbidFailed_0090ed80(int param_1,int param_2)



{

  int in_EAX;

  int *piVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ unaff_EBX;

  int unaff_EBP;

  int unaff_ESI;

  uint32_t /* width from decompiler */ unaff_EDI;

  int in_stack_00000018;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  

  piVar1 = (int *)CVOGReaction_GiveItemByCbid(param_1);

  if (piVar1 != (int *)0x0) {

    uVar6 = 1;

    (**(code **)(*piVar1 + 8))(param_1,DAT_00d1b644,1);

    if (*(int *)(piVar1[0x2a] + 0x38) == 0xe) {

      iVar2 = (**(code **)(*piVar1 + 0x1d4))();

      if (in_EAX == -1) {

        in_EAX = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0xac + iVar2) + 0x3c

                                  ) + 0x6f4);

      }

      piVar1 = (int *)CVOGReaction_GiveItemByCbid(in_EAX);

      if (piVar1 == (int *)0x0) {

        FUN_007a4480(1,"allocatenewobjectfromcbid failed %d Get a programmer",in_EAX);

        return 0;

      }

      (**(code **)(*piVar1 + 8))(in_EAX,DAT_00d1b644,1);

      iVar3 = (**(code **)(*piVar1 + 0x1f0))();

      uVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3) + 0x1f0))();

      Vehicle_SetWheelset(uVar4);

      FUN_004faaf0(uVar6);

      FUN_004fab40(unaff_EDI);

      FUN_004fd970(unaff_EBX);

      iVar3 = 0;

      *(int *)(iVar2 + 0x248) = unaff_ESI;

      *(int *)(iVar2 + 0x24c) = unaff_EBP;

      if (0 < in_stack_00000018) {

        do {

          FUN_004f8ce0(iVar3,*(uint32_t /* width from decompiler */ *)(param_2 + iVar3 * 4));

          iVar3 = iVar3 + 1;

        } while (iVar3 < in_stack_00000018);

      }

      piVar1 = (int *)CVOGReaction_GiveItemByCbid(unaff_ESI);

      if (piVar1 != (int *)0x0) {

        iVar3 = (**(code **)(*piVar1 + 0x1e0))();

        if (iVar3 != 0) {

          iVar3 = (**(code **)(*piVar1 + 8))(unaff_ESI,DAT_00d1b644,1);

          if (-1 < iVar3) {

            uVar5 = 0;

            uVar4 = 0;

            uVar6 = (**(code **)(*piVar1 + 0x1e0))(0,0);

            Vehicle_AttachWeapon(uVar6,uVar4,uVar5);

            goto LAB_0090eef3;

          }

        }

        (**(code **)*piVar1)(1);

      }

LAB_0090eef3:

      piVar1 = (int *)CVOGReaction_GiveItemByCbid(unaff_EBP);

      if (piVar1 != (int *)0x0) {

        iVar3 = (**(code **)(*piVar1 + 0x1e0))();

        if (iVar3 != 0) {

          iVar3 = (**(code **)(*piVar1 + 8))(unaff_EBP,DAT_00d1b644,1);

          if (-1 < iVar3) {

            uVar5 = 0;

            uVar4 = 1;

            uVar6 = (**(code **)(*piVar1 + 0x1e0))(1,0);

            Vehicle_AttachWeapon(uVar6,uVar4,uVar5);

            return iVar2;

          }

        }

        (**(code **)*piVar1)(1);

      }

      return iVar2;

    }

    (**(code **)*piVar1)(1);

  }

  return 0;

}
