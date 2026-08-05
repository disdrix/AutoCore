// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_0056bab0
// -----------------------------------------------------------------------------
// Stable ID: aa_0056bab0
// Callee of Named_CalleeOf_Client_PacketDispatch
// Address:   0x0056bab0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~67 non-empty decompiler lines.
//  - Control keywords: if×11, return×2, goto×1.
//  - Notable callees: FUN_004ec010×6, FUN_004eb3b0×3, FUN_0056a9e0×3, FUN_004b67d0, FUN_004da2e0, FUN_0056bab0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_PacketDispatch
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_0056bab0(int param_1,uint param_2,uint param_3,uint32_t /* width from decompiler */ param_4,int param_5)



{

  int iVar1;

  uint uVar2;

  int iVar3;

  uint uVar4;

  int iVar5;

  

  uVar2 = param_3;

  if (((param_5 != 0) &&

      (iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1), iVar1 != 0)) &&

     (FUN_004eb3b0(), *(int *)(iVar1 + 0x88) != 0)) {

    iVar1 = FUN_004ec010(0x15);

    if (iVar1 == 0) {

      iVar1 = FUN_004ec010(0x14);

      uVar4 = param_2;

    }

    else {

      uVar4 = param_3;

      param_3 = *(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1;

    }

    FUN_0056a9e0(iVar1,param_3,uVar4);

  }

  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);

  iVar5 = 0;

  iVar3 = 0;

  param_3 = param_2;

  if (param_5 == 0) {

    iVar1 = *(int *)(iVar1 + 0xac + param_1);

    if ((iVar1 != 0) && (FUN_004eb3b0(), *(int *)(iVar1 + 0x88) != 0)) {

      iVar3 = FUN_004ec010(0xc);

    }

    param_1 = *(int *)(*(int *)(param_1 + 4) + 4) + param_1;

    uVar4 = param_1 + 4;

    param_3 = -(uint)(uVar2 != *(uint *)(param_1 + 0xb0)) & uVar2;

  }

  else {

    iVar1 = *(int *)(iVar1 + 0xac + param_1);

    if ((iVar1 == 0) || (FUN_004eb3b0(), *(int *)(iVar1 + 0x88) == 0)) goto LAB_0056bc47;

    iVar5 = FUN_004ec010(0xe);

    uVar4 = uVar2;

    if (iVar5 != 0) {

      uVar4 = *(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1;

      FUN_0056a9e0(iVar5,uVar4,uVar2);

      param_3 = uVar2;

    }

    if ((*(int *)(*(int *)(uVar2 + 0xa8) + 0x38) != 0xe) || (iVar3 = FUN_004ec010(6), iVar3 == 0)) {

      iVar3 = FUN_004ec010(5);

    }

    if (iVar5 == 0) {

      iVar5 = iVar3;

    }

  }

  FUN_0056a9e0(iVar3,uVar4,param_3);

LAB_0056bc47:

  if (param_2 != uVar2) {

    uVar2 = *(uint *)(param_2 + 0xac);

    if (*(uint *)(param_2 + 0xac) == 0) {

      uVar2 = param_2;

    }

    if ((iVar5 != 0) && (*(char *)(iVar5 + 0xc) != '\0')) {

      FUN_004b67d0(param_4,1,uVar2 + 0x160);

      return;

    }

    FUN_004da2e0(param_4,1,uVar2,1,1,0,DAT_009d2f68,DAT_009d2f6c,DAT_009d2f70,DAT_009d2f74,0);

  }

  return;

}
