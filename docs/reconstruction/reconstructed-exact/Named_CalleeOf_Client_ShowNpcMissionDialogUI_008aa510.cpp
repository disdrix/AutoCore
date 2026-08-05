// =============================================================================
// Named_CalleeOf_Client_ShowNpcMissionDialogUI_008aa510
// -----------------------------------------------------------------------------
// Stable ID: aa_008aa510
// Callee of Client_ShowNpcMissionDialogUI
// Address:   0x008aa510  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_ShowNpcMissionDialogUI: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_008aa510.
//  - Return sites: 1.

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

void __fastcall

Named_CalleeOf_Client_ShowNpcMissionDialogUI_008aa510(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  int *piVar1;

  int unaff_ESI;

  int unaff_EDI;

  

  if ((-1 < unaff_ESI) && (unaff_ESI < *(int *)(unaff_EDI + 0x510))) {

    piVar1 = *(int **)(unaff_EDI + 0x708 + unaff_ESI * 4);

    if (piVar1 != (int *)0x0) {

      (**(code **)(*piVar1 + 0x1d8))(param_2,1,1);

      (**(code **)(**(int **)(unaff_EDI + 0x708 + unaff_ESI * 4) + 0x34c))();

    }

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x518 + unaff_ESI * 8) = param_3;

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x51c + unaff_ESI * 8) = param_4;

  }

  return;

}
