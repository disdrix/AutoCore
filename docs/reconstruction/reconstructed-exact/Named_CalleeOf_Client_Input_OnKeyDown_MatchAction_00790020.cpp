// =============================================================================
// Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_00790020
// -----------------------------------------------------------------------------
// Stable ID: aa_00790020
// Callee of Client_Input_OnKeyDown_MatchAction
// Address:   0x00790020  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_Input_OnKeyDown_MatchAction: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×5, return×4.
//  - Notable callees: FUN_00790020.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Client_Input_OnKeyDown_MatchAction
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_00790020(int *param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar1 == '\0') {

    return 0;

  }

  if (param_1[0x12f] != 0) {

    (**(code **)(*(int *)param_1[0x12f] + 0x358))(param_2,param_3);

  }

  if (param_2 == 0x1b) {

    if (param_1[0x12f] != 0) {

      (**(code **)(*param_1 + 0x3bc))(0);

      return 1;

    }

    if (-1 < param_1[0x127]) {

      uVar2 = (**(code **)(*param_1 + 0x338))(8,param_1[0x127]);

      return uVar2;

    }

  }

  return 1;

}
