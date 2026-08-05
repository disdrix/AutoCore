// =============================================================================
// Named_CalleeOf_CVOGHBMissionPatrol_Fn6_005083f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005083f0
// Callee of CVOGHBMissionPatrol_Fn6
// Address:   0x005083f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGHBMissionPatrol_Fn6: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0050843d×2, FUN_005083f0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of CVOGHBMissionPatrol_Fn6
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

void __thiscall Named_CalleeOf_CVOGHBMissionPatrol_Fn6_005083f0(int *param_1,char param_2)



{

  void *pvStack_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  puStack_c = &LAB_009a31d0;

  pvStack_10 = ExceptionList;

  local_8 = 1;

  if (param_2 == '\0') {

    ExceptionList = &pvStack_10;

    param_1[6] = 0;

    FUN_0050843d();

    return;

  }

  ExceptionList = &pvStack_10;

  (**(code **)(*param_1 + 0x14))();

  FUN_0050843d();

  return;

}
