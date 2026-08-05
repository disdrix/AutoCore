// =============================================================================
// FUN_0088e180
// -----------------------------------------------------------------------------
// Stable ID: aa_0088e180
// Address:   0x0088e180  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0088e180 @ 0x0088e180
// Stable ID: aa_0088e180
// Embedded strings (evidence for future rename):
//   - "Your Inventory is too full to buy this item."
//   - "You cannot afford this!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: CARRY4, Client_SendSectorPacket, FUN_005714e0, FUN_007fdfb0, FUN_0088e180.
//  - Strings: "Your Inventory is too full to buy this item."; "You cannot afford this!".
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ __thiscall FUN_0088e180(int param_1,int *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint uVar2;

  int *piVar3;

  char cVar4;

  uint uVar5;

  int iVar6;

  int iVar7;

  char *pcVar8;

  uint8_t uStack_45;

  int local_44;

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

  uint32_t /* width from decompiler */ uStack_4;

  

  piVar3 = param_2;

  if ((((*(int *)(param_1 + 0x5a0) != 0) && (DAT_00d1b6d8 != 0)) &&

      (*(int *)(DAT_00d1b6d8 + 0x250) != 0)) &&

     (*(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x2b0) != 0)) {

    uVar2 = *(uint *)(DAT_00d1b6d8 + 0xce8);

    iVar6 = *(int *)(DAT_00d1b6d8 + 0xcec);

    local_44 = param_1;

    uVar5 = (**(code **)(*param_2 + 0x168))();

    iVar6 = ((int)uVar5 >> 0x1f) + iVar6 + (uint)CARRY4(uVar5,uVar2);

    iVar7 = (*(int *)(DAT_00d1b6d8 + 0x724) - *(int *)(DAT_00d1b6d8 + 0x72c)) -

            (uint)(*(uint *)(DAT_00d1b6d8 + 0x720) < *(uint *)(DAT_00d1b6d8 + 0x728));

    if ((iVar6 < iVar7) ||

       ((iVar6 <= iVar7 &&

        (uVar5 + uVar2 <= *(uint *)(DAT_00d1b6d8 + 0x720) - *(uint *)(DAT_00d1b6d8 + 0x728))))) {

      uStack_45 = 0;

      param_2 = (int *)((uint)param_2 & 0xffffff00);

      cVar4 = FUN_005714e0(piVar3,&uStack_45,&param_2,1,0xffffffff);

      if (cVar4 != '\0') {

        uStack_4 = 1;

        auStack_40[0] = 0x2027;

        puVar1 = (uint32_t /* width from decompiler */ *)

                 (*(int *)(*(int *)(*(int *)(local_44 + 0x5a0) + 4) + 4) + 0x164 +

                 *(int *)(local_44 + 0x5a0));

        uStack_18 = *puVar1;

        uStack_14 = puVar1[1];

        uStack_10 = puVar1[2];

        uStack_c = puVar1[3];

        iStack_28 = piVar3[0x58];

        iStack_24 = piVar3[0x59];

        iStack_20 = piVar3[0x5a];

        iStack_1c = piVar3[0x5b];

        uStack_8 = 1;

        Client_SendSectorPacket(&DAT_00d1a840,0x40,auStack_40);

        return 1;

      }

      pcVar8 = "Your Inventory is too full to buy this item.";

    }

    else {

      pcVar8 = "You cannot afford this!";

    }

    FUN_007fdfb0(&DAT_00d1a840,pcVar8,0xffffffff,1,0);

    return 1;

  }

  return 0;

}
