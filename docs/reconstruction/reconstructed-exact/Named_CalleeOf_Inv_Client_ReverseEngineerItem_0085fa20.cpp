// =============================================================================
// Named_CalleeOf_Inv_Client_ReverseEngineerItem_0085fa20
// -----------------------------------------------------------------------------
// Stable ID: aa_0085fa20
// Callee of Inv_Client_ReverseEngineerItem
// Address:   0x0085fa20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Inv_Client_ReverseEngineerItem: inventory/item helper. Evidence string: "Applying this gadget will make it unusable to you!  Do you wish to apply the gadget anyway". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Applying this gadget will make it unusable to you!  Do you wish to apply the gadget anyway"
//   - "Are you sure you wish to apply this gadget?  This is permanent and irreversible."
//   - "No gadget slots are available."
//   - "This is the wrong type of gadget to use on this item."
//   - "That gadget is already on the item, no duplicates allowed."
//   - "You cannot use this gadget on this item."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~96 non-empty decompiler lines.
//  - Control keywords: if×8, return×5, for×3, goto×2.
//  - Notable callees: FUN_007fdfb0×3, FUN_004fabc0×2, FUN_0040f540, FUN_00413f00, FUN_00513400, FUN_0085fa20.
//  - Strings: "No gadget slots are available."; "This is the wrong type of gadget to use on this item."; "That gadget is already on the item, no duplicates allowed."; "You cannot use this gadget on this item.".
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Callee of Inv_Client_ReverseEngineerItem
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall Named_CalleeOf_Inv_Client_ReverseEngineerItem_0085fa20(int param_1)



{

  short sVar1;

  int *in_EAX;

  int iVar2;

  char *pcVar3;

  char *pcVar4;

  char *pcVar5;

  char *pcVar6;

  char local_100 [256];

  

  if (DAT_00d1b6d8 == 0) {

    return;

  }

  if (*(int *)(DAT_00d1b6d8 + 0x250) == 0) {

    return;

  }

  iVar2 = FUN_00513400(param_1);

  if (iVar2 == 0) {

    iVar2 = *(int *)(*(int *)(param_1 + 4) + 4);

    _DAT_00d1d918 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x164 + param_1);

    _DAT_00d1d91c = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x168 + param_1);

    _DAT_00d1d920 = in_EAX[0x58];

    _DAT_00d1d924 = in_EAX[0x59];

    iVar2 = FUN_004fabc0(in_EAX,0);

    if (iVar2 == 0) {

      sVar1 = FUN_0040f540();

      (**(code **)(*in_EAX + 0x68))

                (*(uint32_t /* width from decompiler */ *)

                  (*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x34),0);

      iVar2 = FUN_004fabc0(in_EAX,0);

      (**(code **)(*in_EAX + 0x68))

                (*(uint32_t /* width from decompiler */ *)

                  (*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x34),1);

      FUN_00413f00((int)sVar1);

      if (iVar2 != 0) {

        FUN_007fdfb0(&DAT_00d1a840,

                     "Applying this gadget will make it unusable to you!  Do you wish to apply the gadget anyway?"

                     ,0x4e4d,1,0);

        return;

      }

    }

    FUN_007fdfb0(&DAT_00d1a840,

                 "Are you sure you wish to apply this gadget?  This is permanent and irreversible.",

                 0x4e4d,1,0);

    return;

  }

  if (iVar2 == 1) {

    iVar2 = 7;

    pcVar5 = "No gadget slots are available.";

    pcVar4 = local_100;

LAB_0085fbab:

    for (; iVar2 != 0; iVar2 = iVar2 + -1) {

      *(uint32_t /* width from decompiler */ *)pcVar4 = *(uint32_t /* width from decompiler */ *)pcVar5;

      pcVar5 = pcVar5 + 4;

      pcVar4 = pcVar4 + 4;

    }

    pcVar6 = pcVar4 + 2;

    pcVar3 = pcVar5 + 2;

    *(uint16_t *)pcVar4 = *(uint16_t *)pcVar5;

  }

  else {

    if (iVar2 == 2) {

      pcVar4 = "This is the wrong type of gadget to use on this item.";

      pcVar5 = local_100;

      for (iVar2 = 0xd; iVar2 != 0; iVar2 = iVar2 + -1) {

        *(uint32_t /* width from decompiler */ *)pcVar5 = *(uint32_t /* width from decompiler */ *)pcVar4;

        pcVar4 = pcVar4 + 4;

        pcVar5 = pcVar5 + 4;

      }

      *(uint16_t *)pcVar5 = *(uint16_t *)pcVar4;

      goto LAB_0085fbb0;

    }

    if (iVar2 == 3) {

      iVar2 = 0xe;

      pcVar5 = "That gadget is already on the item, no duplicates allowed.";

      pcVar4 = local_100;

      goto LAB_0085fbab;

    }

    pcVar3 = "You cannot use this gadget on this item.";

    pcVar6 = local_100;

    for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {

      *(uint32_t /* width from decompiler */ *)pcVar6 = *(uint32_t /* width from decompiler */ *)pcVar3;

      pcVar3 = pcVar3 + 4;

      pcVar6 = pcVar6 + 4;

    }

  }

  *pcVar6 = *pcVar3;

LAB_0085fbb0:

  _DAT_00d1d918 = 0xffffffff;

  _DAT_00d1d91c = 0xffffffff;

  _DAT_00d1d920 = 0xffffffff;

  _DAT_00d1d924 = 0xffffffff;

  FUN_007fdfb0(&DAT_00d1a840,local_100,0xffffffff,1,0);

  return;

}
