// =============================================================================
// Named_CalleeOf_Client_ShowNpcMissionDialogUI_008aa4b0
// -----------------------------------------------------------------------------
// Stable ID: aa_008aa4b0
// Callee of Client_ShowNpcMissionDialogUI
// Address:   0x008aa4b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_ShowNpcMissionDialogUI: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_008aa4b0.
//  - Return sites: 2.

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

void Named_CalleeOf_Client_ShowNpcMissionDialogUI_008aa4b0(void)



{

  int *piVar1;

  int iVar2;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar3;

  int unaff_ESI;

  

  piVar1 = *(int **)(unaff_ESI + 0x6d8);

  *(int *)(unaff_ESI + 0x644) = in_EAX;

  if (piVar1 != (int *)0x0) {

    if (in_EAX == 0) {

      (**(code **)(*piVar1 + 0x1d8))(&DAT_00a1419b,1,1);

    }

    else {

      iVar2 = *piVar1;

      uVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(in_EAX + 4) + 4) + 4 + in_EAX) + 0x160))(1,1);

      (**(code **)(iVar2 + 0x1d8))(uVar3);

    }

                    /* WARNING: Could not recover jumptable at 0x008aa508. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(**(int **)(unaff_ESI + 0x6d8) + 0x34c))();

    return;

  }

  return;

}
