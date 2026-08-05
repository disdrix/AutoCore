// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RecvCreateCharacter_008283a0
// -----------------------------------------------------------------------------
// Stable ID: aa_008283a0
// Callee of Named_CalleeOf_Client_RecvCreateCharacter
// Address:   0x008283a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RecvCreateCharacter: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×8, return×3.
//  - Notable callees: QuickBar_ClearActiveSlot_INFERRED×2, CVOGCharacter_SetQuickBarSkill, CVOGReaction_GiveItemByCbid, FUN_00826780, FUN_008283a0, FUN_0085d970.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RecvCreateCharacter
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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Named_CalleeOf_Client_RecvCreateCharacter_008283a0(int param_1)



{

  int iVar1;

  bool bVar2;

  int *in_EAX;

  int *piVar3;

  uint32_t /* width from decompiler */ uVar4;

  

  if (param_1 == -1) {

    QuickBar_ClearActiveSlot_INFERRED();

    return 1;

  }

  if (((in_EAX[0x152] == 2) && (in_EAX[0x154] == param_1)) && (in_EAX[0x155] == param_1 >> 0x1f)) {

    bVar2 = false;

  }

  else {

    bVar2 = true;

  }

  in_EAX[0x154] = param_1;

  in_EAX[0x155] = param_1 >> 0x1f;

  in_EAX[0x157] = in_EAX[0x140] + in_EAX[0x141] * 10;

  in_EAX[0x152] = 2;

  in_EAX[0x156] = 0;

  CVOGCharacter_SetQuickBarItem

            (DAT_00d1b6d8,(char)in_EAX[0x141] * '\n' + (char)in_EAX[0x140],in_EAX[0x154],

             in_EAX[0x155]);

  CVOGCharacter_SetQuickBarSkill(DAT_00d1b6d8,(char)in_EAX[0x141] * '\n' + (char)in_EAX[0x140],-1);

  if ((bVar2) && ((char)in_EAX[0x13f] != '\0')) {

    FUN_00826780();

  }

  *(uint8_t *)((int)in_EAX + 0x4fe) = 0;

  if ((int *)in_EAX[0x15f] != (int *)0x0) {

    (**(code **)(*(int *)in_EAX[0x15f] + 4))();

  }

  if (in_EAX[0x159] != 0) {

    piVar3 = (int *)CVOGReaction_GiveItemByCbid(in_EAX[0x154]);

    if (piVar3 == (int *)0x0) {

      QuickBar_ClearActiveSlot_INFERRED();

      return 1;

    }

    (**(code **)(*piVar3 + 8))(in_EAX[0x154],DAT_00d1b644);

    FUN_0085d970(piVar3,&stack0xfffffef0);

    (**(code **)*piVar3)(1);

    iVar1 = *(int *)in_EAX[0x159];

    uVar4 = (**(code **)(iVar1 + 0x2c8))(0);

    (**(code **)(iVar1 + 0x50))(&stack0xfffffeec,uVar4);

    (**(code **)(*(int *)in_EAX[0x159] + 0x15c))(0,&DAT_00afdf0c);

    (**(code **)(*(int *)in_EAX[0x159] + 0x34c))();

  }

  if ((int *)in_EAX[0x15d] != (int *)0x0) {

    (**(code **)(*(int *)in_EAX[0x15d] + 0x1d8))(0,1);

    (**(code **)(*(int *)in_EAX[0x15d] + 0x34c))();

  }

  if ((int *)in_EAX[0x15e] != (int *)0x0) {

    (**(code **)(*(int *)in_EAX[0x15e] + 0x1d8))(0,1);

    (**(code **)(*(int *)in_EAX[0x15e] + 0x34c))();

  }

  (**(code **)(*in_EAX + 0x448))();

  return 1;

}
