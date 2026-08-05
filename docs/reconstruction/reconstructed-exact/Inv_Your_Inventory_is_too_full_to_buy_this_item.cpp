// READABILITY (auto CF):
//  - Body size: ~111 non-empty decompiler lines.
//  - Control keywords: if×8, return×4, goto×4.
//  - Notable callees: CARRY4, CONCAT44, Client_SendSectorPacket, FUN_00512250, FUN_00521ad0, FUN_005714e0, FUN_007a69d0, FUN_007a6de0.
//  - Strings: "There aren\'t enough of this item currently available!"; "Your Inventory is too full to buy this item."; "You cannot afford this!".
//  - Return sites: 4.

// =============================================================================
// Inv_Your_Inventory_is_too_full_to_buy_this_item
// -----------------------------------------------------------------------------
// Stable ID: aa_0093c700
// Address:   0x0093c700  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Your Inventory is too full to buy this item."
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x0093c7cb) */



uint32_t /* width from decompiler */ Inv_Your_Inventory_is_too_full_to_buy_this_item(int *param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int *piVar3;

  char cVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint uVar7;

  int iVar8;

  void *unaff_EDI;

  uint64_t uVar9;

  longlong lVar10;

  char *pcVar11;

  uint32_t /* width from decompiler */ uVar12;

  uint32_t /* width from decompiler */ uVar13;

  uint32_t /* width from decompiler */ uVar14;

  uint8_t uStack_51;

  uint32_t /* width from decompiler */ local_50;

  int local_4c;

  uint uStack_48;

  int iStack_44;

  uint32_t /* width from decompiler */ auStack_40 [6];

  int iStack_28;

  int iStack_24;

  int iStack_20;

  int iStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  uint8_t uStack_8;

  int iStack_4;

  

  piVar3 = param_1;

  iVar2 = *(int *)(*(int *)((int)unaff_EDI + 0x105c) + 0x588);

  if ((((*(int *)((int)unaff_EDI + 0xe98) == 0) ||

       (iVar8 = *(int *)(*(int *)((int)unaff_EDI + 0xe98) + 0x250), iVar8 == 0)) ||

      (*(int *)(iVar8 + 0x2b0) == 0)) || (iVar2 == 0)) {

    return 0;

  }

  local_4c = iVar2;

  local_50 = FUN_007a69d0();

  iVar5 = (**(code **)(*piVar3 + 0x25c))();

  iVar8 = param_2;

  if (iVar5 < param_2) {

    pcVar11 = "There aren\'t enough of this item currently available!";

    goto LAB_0093c774;

  }

  if (*(char *)(iVar2 + 0x4e6) == '\0') {

LAB_0093c7de:

    iVar2 = *(int *)((int)unaff_EDI + 0xe98);

    uStack_48 = *(uint *)(iVar2 + 0xce8);

    iStack_44 = *(int *)(iVar2 + 0xcec);

    iVar5 = (**(code **)(*piVar3 + 0x168))();

    uVar7 = iVar5 * iVar8;

    iVar5 = ((int)uVar7 >> 0x1f) + iStack_44 + (uint)CARRY4(uVar7,uStack_48);

    iVar8 = (*(int *)(iVar2 + 0x724) - *(int *)(iVar2 + 0x72c)) -

            (uint)(*(uint *)(iVar2 + 0x720) < *(uint *)(iVar2 + 0x728));

    iStack_4 = param_2;

    if ((iVar5 < iVar8) ||

       ((iVar5 <= iVar8 &&

        (uVar7 + uStack_48 <= *(uint *)(iVar2 + 0x720) - *(uint *)(iVar2 + 0x728))))) {

LAB_0093c84d:

      iVar2 = local_4c;

      uStack_51 = 0;

      param_1 = (int *)((uint)param_1 & 0xffffff00);

      cVar4 = FUN_005714e0(piVar3,&uStack_51,&param_1,1,0xffffffff);

      if (cVar4 != '\0') {

        if (*(char *)((int)unaff_EDI + 0xb6) != '\0') {

          return 0;

        }

        auStack_40[0] = 0x2027;

        puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0x164 + iVar2);

        uStack_18 = *puVar1;

        uStack_14 = puVar1[1];

        uStack_10 = puVar1[2];

        uStack_c = puVar1[3];

        iStack_28 = piVar3[0x58];

        iStack_24 = piVar3[0x59];

        iStack_20 = piVar3[0x5a];

        iStack_1c = piVar3[0x5b];

        uStack_8 = 1;

        Client_SendSectorPacket(unaff_EDI,0x40,auStack_40);

        *(uint8_t *)((int)unaff_EDI + 0xb6) = 1;

        return 1;

      }

      pcVar11 = "Your Inventory is too full to buy this item.";

      goto LAB_0093c774;

    }

  }

  else {

    uVar9 = FUN_00512250();

    uVar9 = __allmul(uVar9,iVar8,iVar8 >> 0x1f);

    uStack_48 = (uint)uVar9;

    lVar10 = FUN_00521ad0();

    if (CONCAT44((int)((ulonglong)uVar9 >> 0x20),uStack_48) <= lVar10) {

      iStack_4 = iVar8;

      if (*(char *)(local_4c + 0x4e6) == '\0') goto LAB_0093c7de;

      goto LAB_0093c84d;

    }

  }

  pcVar11 = "You cannot afford this!";

LAB_0093c774:

  uVar14 = 0;

  uVar13 = 1;

  uVar12 = 0xffffffff;

  uVar6 = FUN_007a6de0(pcVar11,0xffffffff);

  FUN_007fdfb0(unaff_EDI,uVar6,uVar12,uVar13,uVar14);

  return 0;

}
