// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_ShowNpcMissionDialogUI_0052a020
// -----------------------------------------------------------------------------
// Stable ID: aa_0052a020
// Callee of Named_CalleeOf_Client_ShowNpcMissionDialogUI
// Address:   0x0052a020  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_ShowNpcMissionDialogUI: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×5, return×4, while×1.
//  - Notable callees: CNDHash_LookupByKey, FUN_0052a020.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_ShowNpcMissionDialogUI
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

bool __thiscall Named_CalleeOf_Named_CalleeOf_Client_ShowNpcMissionDialogUI_0052a020(int param_1,int param_2,char param_3)



{

  int iVar1;

  int *piVar2;

  char cVar3;

  void *pvVar4;

  uint uVar5;

  

  if (param_2 == 0) {

    return false;

  }

  if ((*(int *)(param_2 + 0x158) != 0) &&

     (*(int *)(param_2 + 0x15c) - *(int *)(param_2 + 0x158) >> 2 != 0)) {

    pvVar4 = CNDHash_LookupByKey(*(void **)(param_1 + 0x55c),*(uint *)(param_2 + 0x10));

    uVar5 = 0;

    while( true ) {

      iVar1 = *(int *)(param_2 + 0x158);

      if ((iVar1 == 0) || ((uint)(*(int *)(param_2 + 0x15c) - iVar1 >> 2) <= uVar5)) {

        return true;

      }

      piVar2 = *(int **)(iVar1 + uVar5 * 4);

      if (param_3 == '\0') {

        cVar3 = (**(code **)(*piVar2 + 0xc))();

      }

      else {

        cVar3 = (**(code **)(*piVar2 + 8))(param_1,pvVar4);

      }

      if (cVar3 == '\0') break;

      uVar5 = uVar5 + 1;

    }

    return false;

  }

  return *(int *)(param_2 + 0x138) != 0;

}
