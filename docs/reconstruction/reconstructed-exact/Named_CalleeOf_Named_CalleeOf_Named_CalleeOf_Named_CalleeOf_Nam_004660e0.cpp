// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004660e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004660e0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxAdapter
// Address:   0x004660e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxAdapter: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_004540b0, FUN_00465bf0, FUN_004660e0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxAdapter
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

int __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004660e0(int param_1,int param_2)



{

  uint uVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ uVar3;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bd2d0;

  local_10 = ExceptionList;

  if (*(int *)(param_1 + 4) == 0) {

    uVar1 = 0;

  }

  else {

    uVar1 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 4;

  }

  ExceptionList = &local_10;

  *(uint32_t /* width from decompiler */ *)(param_2 + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_2 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0xc) = 0;

  if (uVar1 != 0) {

    if (0xfffffff < uVar1) {

      uVar1 = FUN_004540b0();

    }

    pvVar2 = operator_new(uVar1 * 0x10);

    local_8 = 0;

    *(void **)(param_2 + 4) = pvVar2;

    *(void **)(param_2 + 8) = pvVar2;

    *(void **)(param_2 + 0xc) = (void *)(uVar1 * 0x10 + (int)pvVar2);

    uVar3 = FUN_00465bf0(*(uint32_t /* width from decompiler */ *)(param_1 + 4),*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_2);

    *(uint32_t /* width from decompiler */ *)(param_2 + 8) = uVar3;

  }

  ExceptionList = local_10;

  return param_2;

}
