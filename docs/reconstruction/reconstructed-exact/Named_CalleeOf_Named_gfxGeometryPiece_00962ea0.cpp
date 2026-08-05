// =============================================================================
// Named_CalleeOf_Named_gfxGeometryPiece_00962ea0
// -----------------------------------------------------------------------------
// Stable ID: aa_00962ea0
// Callee of Named_gfxGeometryPiece (+1 other named callers)
// Address:   0x00962ea0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxGeometryPiece: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_gfxGeometryPiece (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0044bd70, FUN_00962ea0, FUN_0098ce00.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_gfxGeometryPiece_00962ea0(int param_1,float param_2)



{

  int iVar1;

  float fVar2;

  char cVar3;

  uint32_t /* width from decompiler */ local_4;

  

  fVar2 = param_2;

  FUN_0044bd70(&param_2,&local_4);

  iVar1 = param_1;

  cVar3 = FUN_0098ce00(param_1 + 4,param_2,&param_1,&local_4);

  if (((cVar3 != '\0') && (g_flZero <= param_2)) && (param_2 < *(float *)(iVar1 + 0x1c))) {

    *(float *)(iVar1 + 0x1c) = param_2;

    *(int *)(iVar1 + 0x44) = param_1;

    *(float *)(iVar1 + 0x40) = fVar2;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x48) = local_4;

    return 1;

  }

  return 0;

}
