// =============================================================================
// Named_CalleeOf_Client_ShowNpcMissionDialogUI_008aa490
// -----------------------------------------------------------------------------
// Stable ID: aa_008aa490
// Callee of Client_ShowNpcMissionDialogUI
// Address:   0x008aa490  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_ShowNpcMissionDialogUI: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_008aa490.
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

void __fastcall Named_CalleeOf_Client_ShowNpcMissionDialogUI_008aa490(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  int in_EAX;

  

  *(char *)(in_EAX + 0x580) = (char)param_2;

  if (*(int **)(in_EAX + 0x6e8) != (int *)0x0) {

    (**(code **)(**(int **)(in_EAX + 0x6e8) + 4))(param_2);

  }

  return;

}
