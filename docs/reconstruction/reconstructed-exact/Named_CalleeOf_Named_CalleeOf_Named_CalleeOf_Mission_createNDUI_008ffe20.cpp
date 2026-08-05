// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI_008ffe20
// -----------------------------------------------------------------------------
// Stable ID: aa_008ffe20
// Callee of Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs
// Address:   0x008ffe20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_008fee00, FUN_008ff260, FUN_008ffe20, NDUIWindow_ReloadInterface.
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI_008ffe20(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  

  NDUIWindow_ReloadInterface(param_2);

  if ((int *)param_1[0x1cc] != (int *)0x0) {

    iVar1 = (**(code **)(*(int *)param_1[0x1cc] + 0x1a8))();

    *(uint8_t *)(iVar1 + 0x78) = 0;

  }

  iVar1 = DAT_00aaabe4;

  param_1[0x1a] = 7;

  param_1[0x1d] = iVar1;

  if (param_1[0x1c] < 7) {

    param_1[0x1c] = 7;

  }

  FUN_008ff260();

  FUN_008fee00(param_1);

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x34c))();

  return;

}
