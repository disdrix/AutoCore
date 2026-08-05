// =============================================================================
// Named_CalleeOf_Named_gfxGeometryPiece_0044bd10
// -----------------------------------------------------------------------------
// Stable ID: aa_0044bd10
// Callee of Named_gfxGeometryPiece (+1 other named callers)
// Address:   0x0044bd10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxGeometryPiece: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_gfxGeometryPiece (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0044b610, FUN_0044bd10.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxGeometryPiece (+1 other named callers)
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

uint32_t /* width from decompiler */ * __fastcall

Named_CalleeOf_Named_gfxGeometryPiece_0044bd10(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ param_4)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009be7b8;

  local_c = ExceptionList;

  local_4 = 0;

  ExceptionList = &local_c;

  *param_3 = &PTR_FUN_00aa1354;

  param_3[1] = param_4;

  param_3[2] = param_1;

  param_3[3] = param_2;

  FUN_0044b610();

  ExceptionList = local_c;

  return param_3;

}
