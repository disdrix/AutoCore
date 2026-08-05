// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGCombat_OnDeathAwardKillXp_004cf120
// -----------------------------------------------------------------------------
// Stable ID: aa_004cf120
// Callee of Named_CalleeOf_CVOGCombat_OnDeathAwardKillXp (+1 other named callers)
// Address:   0x004cf120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGCombat_OnDeathAwardKillXp: combat/reward helper. Evidence string: "allocatenewobjectfromcbid failed %d". Supports parent flow (not a free-standing entry point). Named_CalleeOf_CVOGCombat_OnDeathAwardKillXp (+1 other named callers).
// Embedded strings (evidence):
//   - "allocatenewobjectfromcbid failed %d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~67 non-empty decompiler lines.
//  - Control keywords: if×8, return×4, do×2, while×2.
//  - Notable callees: CONCAT13, CVOGReaction_GiveItemByCbid, FUN_004cf120, FUN_00508e20, FUN_00509c70, FUN_00512160, FUN_00512670, FUN_00516720.
//  - Strings: "allocatenewobjectfromcbid failed %d".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGCombat_OnDeathAwardKillXp (+1 other named callers)
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int * __thiscall Named_CalleeOf_Named_CalleeOf_CVOGCombat_OnDeathAwardKillXp_004cf120(uint param_1,int param_2,int param_3)



{

  uint uVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ unaff_EDI;

  uint32_t /* width from decompiler */ uStack_4;

  

  iVar4 = 0;

  uStack_4 = param_1 & 0xffffff;

  if (param_3 != -1) {

    iVar4 = FUN_00508e20(param_3);

    if (iVar4 == 0) {

      return (int *)0x0;

    }

    param_2 = *(int *)(iVar4 + 0x84);

    uStack_4 = CONCAT13(1,(int3)param_1);

  }

  if (param_2 == -1) {

    return (int *)0x0;

  }

  piVar2 = (int *)CVOGReaction_GiveItemByCbid(param_2);

  if (piVar2 == (int *)0x0) {

    FUN_007a4480(0,"allocatenewobjectfromcbid failed %d",param_2);

  }

  else {

    iVar3 = (**(code **)(*piVar2 + 8))(param_2,param_1,1);

    if (-1 < iVar3) {

      if ((char)((uint)unaff_EDI >> 0x18) != '\0') {

        FUN_00516720(iVar4 + 4);

        FUN_00509c70(piVar2,0,0x80000000,0,*(uint32_t /* width from decompiler */ *)(iVar4 + 0x88));

        piVar5 = (int *)(iVar4 + 0x90);

        iVar3 = 5;

        do {

          if (*piVar5 != -1) {

            (**(code **)(*piVar2 + 0x78))((short)*piVar5);

          }

          piVar5 = piVar5 + 1;

          iVar3 = iVar3 + -1;

        } while (iVar3 != 0);

        piVar5 = (int *)(iVar4 + 0xa4);

        iVar4 = 5;

        do {

          if (*piVar5 != -1) {

            (**(code **)(*piVar2 + 0x54))((short)*piVar5);

          }

          piVar5 = piVar5 + 1;

          iVar4 = iVar4 + -1;

        } while (iVar4 != 0);

        (**(code **)(*piVar2 + 100))();

        (**(code **)(*piVar2 + 0x9c))(uStack_4);

      }

      piVar2[0x5f] = piVar2[0x5f] | 0x10;

      FUN_00512670();

      uVar1 = *(uint *)(param_1 + 0xe6e0);

      iVar4 = *(int *)(param_1 + 0xe6e4);

      *(uint *)(param_1 + 0xe6e4) = iVar4 + (uint)(0xfffffffe < uVar1);

      *(uint *)(param_1 + 0xe6e0) = uVar1 + 1;

      FUN_00512160(uVar1,iVar4,1);

      (**(code **)(*piVar2 + 0x218))(param_1);

      (**(code **)(*piVar2 + 0x2a4))(*(uint32_t /* width from decompiler */ *)(param_1 + 0xe4e8));

      return piVar2;

    }

  }

  return (int *)0x0;

}
