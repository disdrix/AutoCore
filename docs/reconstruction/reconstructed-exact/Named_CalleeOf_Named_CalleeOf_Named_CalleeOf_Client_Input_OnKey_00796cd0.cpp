// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_OnKey_00796cd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00796cd0
// Callee of Named_CalleeOf_Named_CalleeOf_Client_Input_OnKeyDown_MatchActio
// Address:   0x00796cd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_Input_OnKeyDown_MatchActio: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: for×2, return×1.
//  - Notable callees: FUN_00796cd0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_Input_OnKeyDown_MatchActio
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

uint32_t /* width from decompiler */ * __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_OnKey_00796cd0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  param_2[2] = 0;

  param_2[0x1f] = 0;

  param_2[0x20] = 0;

  param_2[0x73] = 0;

  param_2[0x74] = 0;

  param_2[0x75] = 0;

  puVar2 = param_2 + 0x21;

  for (iVar1 = 0x52; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  *param_2 = &LAB_007969b0;

  param_2[1] = &LAB_007969a0;

  puVar2 = param_2 + 3;

  for (iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  param_2[0x1c] = 0;

  param_2[0x1d] = 0;

  param_2[0x1e] = 0;

  return param_2;

}
