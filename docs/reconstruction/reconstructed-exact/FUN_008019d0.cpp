// =============================================================================
// FUN_008019d0
// -----------------------------------------------------------------------------
// Stable ID: aa_008019d0
// Address:   0x008019d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008019d0 @ 0x008019d0
// Stable ID: aa_008019d0
// Embedded strings (evidence for future rename):
//   - "allocatenewobjectfromcbid failed %d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~75 non-empty decompiler lines.
//  - Control keywords: if×7, return×5, do×1, while×1.
//  - Notable callees: Client_RefreshOpenMissionUiWindows×2, FUN_00513de0×2, CVOGReaction_GiveItemByCbid, Client_SendInventoryAddItem, FUN_00512160, FUN_00512670, FUN_00513e70, FUN_00571010.
//  - Strings: "allocatenewobjectfromcbid failed %d".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ FUN_008019d0(uint param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  uint16_t uVar2;

  int in_EAX;

  int *piVar3;

  int iVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint uVar7;

  uint32_t /* width from decompiler */ unaff_ESI;

  uint uVar8;

  uint8_t local_c [4];

  uint32_t /* width from decompiler */ uStack_8;

  

  iVar4 = *(int *)(in_EAX + 0xe98);

  if ((((iVar4 == 0) || (*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xa8 + iVar4) == 0)) ||

      (*(int *)(iVar4 + 0x250) == 0)) || (*(int *)(*(int *)(iVar4 + 0x250) + 0x2b0) == 0)) {

    return 0;

  }

  piVar3 = (int *)FUN_00571010(param_1,param_2);

  if (((piVar3 != (int *)0x0) && (((uint)piVar3[0x5f] >> 0x13 & 1) == 0)) &&

     (*(int *)(piVar3[0x2a] + 0x38) != 0x1a)) {

    local_c[0] = 0;

    param_1 = param_1 & 0xffffff00;

    cVar1 = FUN_00513e70();

    if (((cVar1 == '\0') || (iVar4 = (**(code **)(*piVar3 + 0x25c))(), iVar4 < 2)) ||

       (cVar1 = FUN_005714e0(piVar3,local_c,&param_1,1,0xffffffff), cVar1 != '\0')) {

      if ((*(int *)(piVar3[0x2a] + 0x3c) != 0) &&

         (iVar4 = (**(code **)(*piVar3 + 0x25c))(), 1 < iVar4)) {

        iVar4 = CVOGReaction_GiveItemByCbid(*(int *)(piVar3[0x2a] + 0x34));

        if (iVar4 == 0) {

          (**(code **)(_DAT_00000000 + 8))(*(uint32_t /* width from decompiler */ *)(piVar3[0x2a] + 0x34),piVar3[0x29],1);

          uVar8 = *(uint *)(DAT_00d1b644 + 0xe6e0);

          iVar4 = *(int *)(DAT_00d1b644 + 0xe6e4);

          piVar5 = (int *)(DAT_00d1b644 + 0xe6e0);

          *(uint *)(DAT_00d1b644 + 0xe6e4) = iVar4 + (uint)(0xfffffffe < uVar8);

          *piVar5 = uVar8 + 1;

          FUN_00512160(uVar8,iVar4,1);

          _DAT_0000017c = _DAT_0000017c | 0x10;

          FUN_00512670();

          (**(code **)(_DAT_00000000 + 0x24c))(unaff_ESI,uStack_8);

          FUN_00513de0(1);

          (**(code **)(_DAT_00000000 + 0x2a4))(*(uint32_t /* width from decompiler */ *)(_DAT_000000a4 + 0xe4e8));

          FUN_00571b80(piVar3,1,0);

          uVar6 = (**(code **)(_DAT_00000000 + 0x25c))();

          Client_SendInventoryAddItem(0,uVar6);

          Client_RefreshOpenMissionUiWindows(&DAT_00d1a840);

          return 1;

        }

        FUN_007a4480(0,"allocatenewobjectfromcbid failed %d",*(uint32_t /* width from decompiler */ *)(piVar3[0x2a] + 0x34));

        return 0;

      }

      uVar8 = 0;

      iVar4 = (**(code **)(*piVar3 + 0x80))();

      if (iVar4 != 0) {

        do {

          uVar7 = (**(code **)(*piVar3 + 0x7c))(uVar8);

          if ((uVar7 & 0xffff) != 0xffffffff) {

            iVar4 = *piVar3;

            uVar2 = (**(code **)(iVar4 + 0x7c))(uVar8,1);

            (**(code **)(iVar4 + 0x68))(uVar2);

          }

          uVar8 = uVar8 + 1;

          uVar7 = (**(code **)(*piVar3 + 0x80))();

        } while (uVar8 < uVar7);

      }

      (**(code **)(*piVar3 + 0x84))();

      FUN_00513de0(1);

      Client_RefreshOpenMissionUiWindows(&DAT_00d1a840);

      return 1;

    }

  }

  return 0;

}
