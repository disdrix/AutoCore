// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxAdapter_004664c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004664c0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxAdapter
// Address:   0x004664c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_gfxAdapter: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004660e0, FUN_004664c0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxAdapter
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxAdapter_004664c0(uint8_t *param_1,uint8_t *param_2)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009bdcb1;

  local_c = ExceptionList;

  local_4 = 0;

  if (param_2 != (uint8_t *)0x0) {

    ExceptionList = &local_c;

    *param_2 = *param_1;

    *(uint32_t /* width from decompiler */ *)(param_2 + 4) = *(uint32_t /* width from decompiler */ *)(param_1 + 4);

    *(uint32_t /* width from decompiler */ *)(param_2 + 8) = *(uint32_t /* width from decompiler */ *)(param_1 + 8);

    *(uint32_t /* width from decompiler */ *)(param_2 + 0xc) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xc);

    param_2[0x10] = param_1[0x10];

    param_2[0x11] = param_1[0x11];

    FUN_004660e0(param_2 + 0x14);

  }

  ExceptionList = local_c;

  return;

}
