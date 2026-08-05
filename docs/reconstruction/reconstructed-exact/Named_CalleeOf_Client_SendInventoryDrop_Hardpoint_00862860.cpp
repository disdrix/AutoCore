// =============================================================================
// Named_CalleeOf_Client_SendInventoryDrop_Hardpoint_00862860
// -----------------------------------------------------------------------------
// Stable ID: aa_00862860
// Callee of Client_SendInventoryDrop_Hardpoint (+1 other named callers)
// Address:   0x00862860  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer / hardpoint equip UI
// Dual seal: 2026-07-29 W18-O ? Client_ItemMatchesActiveHardpointMode_Inferred.cpp
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_SendInventoryDrop_Hardpoint: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_SendInventoryDrop_Hardpoint (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: return×11, if×7, switch×1.
//  - Notable callees: FUN_0040da70, FUN_00862860.
//  - Return sites: 11.

/*
 * Behavioral notes:
 * Callee of Client_SendInventoryDrop_Hardpoint (+1 other named callers)
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

bool __fastcall Named_CalleeOf_Client_SendInventoryDrop_Hardpoint_00862860(int *param_1)



{

  byte bVar1;

  short sVar2;

  int iVar3;

  int *unaff_ESI;

  

  if (param_1 != (int *)0x0) {

    switch(*(uint32_t /* width from decompiler */ *)(param_1[0x2a] + 0x38)) {

    case 6:

      sVar2 = *(short *)(*(int *)(param_1[0x2a] + 0x3c) + 0x3f4);

      if (sVar2 == 10) {

        iVar3 = (**(code **)(*unaff_ESI + 0x3cc))();

        return iVar3 == 9;

      }

      if (sVar2 == 0xb) {

        iVar3 = (**(code **)(*unaff_ESI + 0x3cc))();

        return iVar3 == 8;

      }

      break;

    case 10:

      iVar3 = (**(code **)(*unaff_ESI + 0x3cc))();

      return iVar3 == 1;

    case 0xc:

      (**(code **)(*param_1 + 0x1e0))();

      iVar3 = FUN_0040da70();

      if (*(char *)(iVar3 + 0x3f4) == '\t') {

        iVar3 = (**(code **)(*unaff_ESI + 0x3cc))();

        return iVar3 == 7;

      }

      bVar1 = *(byte *)(iVar3 + 0x536);

      if ((bVar1 & 2) != 0) {

        iVar3 = (**(code **)(*unaff_ESI + 0x3cc))();

        return iVar3 == 4;

      }

      if ((bVar1 & 0x10) != 0) {

        iVar3 = (**(code **)(*unaff_ESI + 0x3cc))();

        return iVar3 == 5;

      }

      if ((bVar1 & 4) != 0) {

        iVar3 = (**(code **)(*unaff_ESI + 0x3cc))();

        return iVar3 == 6;

      }

      break;

    case 0xe:

      iVar3 = (**(code **)(*unaff_ESI + 0x3cc))();

      return iVar3 == 0xd;

    case 0x10:

      iVar3 = (**(code **)(*unaff_ESI + 0x3cc))();

      return iVar3 == 2;

    case 0x1c:

      iVar3 = (**(code **)(*unaff_ESI + 0x3cc))();

      return iVar3 == 3;

    }

  }

  return false;

}
