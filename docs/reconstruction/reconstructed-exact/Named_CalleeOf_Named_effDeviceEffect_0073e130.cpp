// =============================================================================
// Named_CalleeOf_Named_effDeviceEffect_0073e130
// -----------------------------------------------------------------------------
// Stable ID: aa_0073e130
// Callee of Named_effDeviceEffect
// Address:   0x0073e130  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_effDeviceEffect: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00456ba0, FUN_00456d10, FUN_0073dff0, FUN_0073e130.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_effDeviceEffect
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

void Named_CalleeOf_Named_effDeviceEffect_0073e130(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  uint8_t local_24 [4];

  uint32_t /* width from decompiler */ local_20;

  uint8_t local_1c [4];

  void *local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b11d2;

  local_c = ExceptionList;

  local_18 = (void *)0x0;

  local_14 = 0;

  local_10 = 0;

  local_4 = 0;

  local_24[0] = 1;

  ExceptionList = &local_c;

  FUN_00456d10();

  local_20 = FUN_0073dff0(param_3,local_1c);

  FUN_00456ba0(local_24);

  if (local_18 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_18);

  }

  ExceptionList = local_c;

  return;

}
