// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxShadowVolume_00995150
// -----------------------------------------------------------------------------
// Stable ID: aa_00995150
// Callee of Named_CalleeOf_Named_gfxShadowVolume
// Address:   0x00995150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxShadowVolume: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00414b60, FUN_00414c20, FUN_004451c0, FUN_007475c0, FUN_00995150.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxShadowVolume
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

void Named_CalleeOf_Named_CalleeOf_Named_gfxShadowVolume_00995150(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int unaff_ESI;

  uint8_t local_24 [24];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b22a8;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_004451c0(local_24,param_1 + 0xac);

  local_4 = 0;

  FUN_007475c0(local_24,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xb0));

  *(uint *)(unaff_ESI + 0xbc) = *(uint *)(unaff_ESI + 0xbc) | 1;

  FUN_00414c20(param_2,local_24,0x20,0);

  FUN_00414b60();

  ExceptionList = local_c;

  return;

}
