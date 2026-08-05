// =============================================================================
// FUN_0060df70
// -----------------------------------------------------------------------------
// Stable ID: aa_0060df70
// Address:   0x0060df70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0060df70 @ 0x0060df70
// Stable ID: aa_0060df70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×8, return×2, while×1, goto×1.
//  - Notable callees: FUN_005319d0, FUN_0060d460, FUN_0060d630, FUN_0060df70.
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

uint __thiscall

FUN_0060df70(int *param_1,int param_2,uint32_t /* width from decompiler */ param_3,int param_4,uint32_t /* width from decompiler */ param_5,int param_6)



{

  int iVar1;

  uint in_EAX;

  uint uVar2;

  int iVar3;

  

  if ((param_4 == 9) || (param_4 == 10)) {

    in_EAX = (**(code **)(*param_1 + 8))(param_2,param_3);

    if (((char)in_EAX == '\0') &&

       ((in_EAX = param_1[0x15], in_EAX == 0xffffffff ||

        (*(uint *)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xa8 + param_2) + 0xfc) == in_EAX)

        ))) {

      in_EAX = FUN_0060d460(param_2,param_6);

      if ((char)in_EAX != '\0') {

        if ((param_4 == 10) || (param_1[0xd] == 0)) {

          uVar2 = FUN_0060d630(param_2,param_3,param_6);

          return uVar2;

        }

        iVar1 = param_1[1];

        iVar3 = 0;

        while( true ) {

          if (*(int *)(iVar1 + 0x158) == 0) {

            in_EAX = 0;

          }

          else {

            in_EAX = *(int *)(iVar1 + 0x15c) - *(int *)(iVar1 + 0x158) >> 2;

          }

          if ((int)in_EAX <= iVar3) goto LAB_0060e04f;

          in_EAX = *(int *)(iVar1 + 0x158) + iVar3 * 4;

          if (param_1 == *(int **)(*(int *)(iVar1 + 0x158) + iVar3 * 4)) break;

          iVar3 = iVar3 + 1;

        }

        if (iVar3 != -1) {

          in_EAX = FUN_005319d0(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x10),iVar3,*(uint32_t /* width from decompiler */ *)(param_6 + 0x160)

                                ,*(uint32_t /* width from decompiler */ *)(param_6 + 0x164),*(uint32_t /* width from decompiler */ *)(param_6 + 0x168),

                                *(uint32_t /* width from decompiler */ *)(param_6 + 0x16c));

        }

      }

    }

  }

LAB_0060e04f:

  return in_EAX & 0xffffff00;

}
