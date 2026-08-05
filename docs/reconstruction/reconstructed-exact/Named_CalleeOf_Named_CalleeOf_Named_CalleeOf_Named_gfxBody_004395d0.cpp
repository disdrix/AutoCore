// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxBody_004395d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004395d0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxBody (+1 other named callers)
// Address:   0x004395d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_gfxBody: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_CalleeOf_Named_gfxBody (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00438490, FUN_004395d0, FUN_0043ad40.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxBody (+1 other named callers)
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

int __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxBody_004395d0(int param_1,int param_2)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bd650;

  local_10 = ExceptionList;

  iVar2 = 0;

  if (*(int *)(param_2 + 4) != 0) {

    iVar2 = (*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) / 0x38;

  }

  ExceptionList = &local_10;

  cVar1 = FUN_00438490(iVar2);

  if (cVar1 != '\0') {

    local_8 = 0;

    uVar3 = FUN_0043ad40(*(uint32_t /* width from decompiler */ *)(param_2 + 4),*(uint32_t /* width from decompiler */ *)(param_2 + 8),

                         *(uint32_t /* width from decompiler */ *)(param_1 + 4),param_1,param_2);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar3;

  }

  ExceptionList = local_10;

  return param_1;

}
