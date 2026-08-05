// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_effDeviceEff_00448410
// -----------------------------------------------------------------------------
// Stable ID: aa_00448410
// Callee of Named_CalleeOf_Named_CalleeOf_Named_effDeviceEffect
// Address:   0x00448410  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_effDeviceEffect: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: for×1, if×1, return×1.
//  - Notable callees: FUN_004475e0, FUN_00448410.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_effDeviceEffect
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_effDeviceEff_00448410(int param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  void *local_10;

  uint8_t *puStack_c;

  uint8_t local_8;

  undefined3 uStack_7;

  

  puStack_c = &LAB_009be021;

  local_10 = ExceptionList;

  uStack_7 = 0;

  ExceptionList = &local_10;

  for (; param_1 != 0; param_1 = param_1 + -1) {

    local_8 = 1;

    if (param_2 != 0) {

      FUN_004475e0(param_2,param_3);

    }

    param_2 = param_2 + 0xc;

  }

  ExceptionList = local_10;

  return;

}
