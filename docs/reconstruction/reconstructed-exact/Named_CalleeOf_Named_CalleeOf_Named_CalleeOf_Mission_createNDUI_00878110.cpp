// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI_00878110
// -----------------------------------------------------------------------------
// Stable ID: aa_00878110
// Callee of Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs
// Address:   0x00878110  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00878110, NDUIWindow_ReloadInterface.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI_00878110(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  uint8_t local_8 [8];

  

  uStack_10 = param_2;

  uStack_14 = 0x878120;

  NDUIWindow_ReloadInterface();

  uStack_10 = 0;

  uStack_14 = 1;

  piVar1 = (int *)(**(code **)(*param_1 + 0x120))(local_8);

  param_1[0x14a] = *piVar1;

  param_1[0x14b] = piVar1[1];

  piVar1 = (int *)(**(code **)(*param_1 + 0x140))(&uStack_14,1);

  param_1[0x14e] = *piVar1;

  param_1[0x14f] = piVar1[1];

  return;

}
