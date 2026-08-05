// =============================================================================
// Named_CalleeOf_Named_gfxDeviceVB_004451c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004451c0
// Callee of Named_gfxDeviceVB (+5 other named callers)
// Address:   0x004451c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxDeviceVB: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_gfxDeviceVB (+5 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004451c0, FUN_00448130.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxDeviceVB (+5 other named callers)
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

int Named_CalleeOf_Named_gfxDeviceVB_004451c0(int param_1,int param_2)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009be038;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  local_4 = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x10);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x14);

  FUN_00448130(*(uint32_t /* width from decompiler */ *)(param_2 + 4),*(uint32_t /* width from decompiler */ *)(param_2 + 8),param_2);

  ExceptionList = local_c;

  return param_1;

}
