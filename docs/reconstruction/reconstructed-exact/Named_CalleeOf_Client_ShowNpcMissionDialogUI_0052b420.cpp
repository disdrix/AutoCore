// =============================================================================
// Named_CalleeOf_Client_ShowNpcMissionDialogUI_0052b420
// -----------------------------------------------------------------------------
// Stable ID: aa_0052b420
// Callee of Client_ShowNpcMissionDialogUI
// Address:   0x0052b420  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_ShowNpcMissionDialogUI: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×7, return×6, while×2.
//  - Notable callees: FUN_0052a020, FUN_0052b420.
//  - Return sites: 6.

/*
 * Behavioral notes:
 * Callee of Client_ShowNpcMissionDialogUI
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

uint8_t __thiscall Named_CalleeOf_Client_ShowNpcMissionDialogUI_0052b420(int param_1,int param_2,int param_3)



{

  int iVar1;

  char cVar2;

  int iVar3;

  uint8_t uVar4;

  int *piVar5;

  

  iVar1 = *(int *)(*(int *)(param_2 + 0x13c) + -4 + (uint)*(byte *)(param_2 + 0x130) * 4);

  iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x548) + 0x10) +

                           (*(uint *)(*(int *)(param_1 + 0x548) + 8) & *(uint *)(iVar1 + 0x10)) * 4)

                  + 4);

  while( true ) {

    if (iVar3 == 0) {

      return 0;

    }

    if (*(uint *)(iVar1 + 0x10) == *(uint *)(iVar3 + 0x10)) break;

    iVar3 = *(int *)(iVar3 + 0xc);

  }

  if (iVar3 == 0) {

    return 0;

  }

  if (*(int *)(iVar3 + 8) == 0) {

    return 0;

  }

  cVar2 = FUN_0052a020(iVar1,1);

  if (cVar2 == '\0') {

    return 0;

  }

  uVar4 = 1;

  if ((param_3 != 0) && (piVar5 = *(int **)(iVar1 + 0x158), piVar5 != *(int **)(iVar1 + 0x15c))) {

    while ((iVar3 = (**(code **)(*(int *)*piVar5 + 0x50))(), iVar3 != 3 ||

           (*(int *)(*piVar5 + 0x18) ==

            *(int *)(*(int *)(*(int *)(*(int *)(param_3 + 4) + 4) + 0xac + param_3) + 0x34)))) {

      piVar5 = piVar5 + 1;

      if (piVar5 == *(int **)(iVar1 + 0x15c)) {

        return 1;

      }

    }

    uVar4 = 0;

  }

  return uVar4;

}
