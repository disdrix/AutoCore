// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00687370
// -----------------------------------------------------------------------------
// Stable ID: aa_00687370
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00687370  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00687370, FUN_0069e2c0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00687370(int *param_1)



{

  float *pfVar1;

  float local_24;

  float local_20;

  float local_1c;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  puStack_c = &LAB_009a9ec2;

  local_10 = ExceptionList;

  local_14 = &stack0xffffffa4;

  pfVar1 = (float *)param_1[0x10];

  local_1c = (pfVar1[5] + pfVar1[2]) * DAT_00a0f298;

  local_8 = 0;

  local_20 = (pfVar1[4] + pfVar1[1]) * DAT_00a0f298;

  local_24 = (pfVar1[3] + *pfVar1) * DAT_00a0f298;

  ExceptionList = &local_10;

  FUN_0069e2c0(&local_24,*(uint32_t /* width from decompiler */ *)(*param_1 + 200),*(uint16_t *)(*param_1 + 0xb4));

  ExceptionList = local_10;

  return;

}
