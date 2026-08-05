// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00481c90
// -----------------------------------------------------------------------------
// Stable ID: aa_00481c90
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_stoPackOSFil
// Address:   0x00481c90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_stoPackOSFil: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004396a0, FUN_00481c90.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_stoPackOSFil
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

uint32_t /* width from decompiler */ * __thiscall

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00481c90(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint8_t param_5)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bd251;

  local_10 = ExceptionList;

  ExceptionList = &local_10;

  puVar1 = operator_new(0x28);

  local_8 = 1;

  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar1[1] = param_3;

    puVar1[2] = param_4;

    *puVar1 = param_2;

    puVar1[3] = *param_1;

    puVar1[4] = param_1[1];

    FUN_004396a0(puVar1 + 5);

    *(uint8_t *)(puVar1 + 9) = param_5;

    *(uint8_t *)((int)puVar1 + 0x25) = 0;

  }

  ExceptionList = local_10;

  return puVar1;

}
