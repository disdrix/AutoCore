// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0059dcc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0059dcc0
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x0059dcc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_0059dcc0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0059dcc0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  param_1[0x56] = 0;

  param_1[0x57] = 0;

  param_1[0x58] = 0;

  param_1[0x53] = param_3;

  puVar2 = param_1 + 3;

  for (iVar1 = 0x50; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = *param_2;

    param_2 = param_2 + 1;

    puVar2 = puVar2 + 1;

  }

  *param_1 = 0;

  param_1[2] = 0;

  param_1[1] = 0;

  param_1[0x54] = 0;

  param_1[0x59] = 0;

  return;

}
