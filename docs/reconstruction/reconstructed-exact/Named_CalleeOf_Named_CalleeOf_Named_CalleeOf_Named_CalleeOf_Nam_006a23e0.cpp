// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006a23e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006a23e0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x006a23e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0069a050, FUN_006a23e0.
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

uint32_t /* width from decompiler */ * __thiscall

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006a23e0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,uint8_t param_3,uint8_t param_4,

            uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6)



{

  FUN_0069a050();

  *(uint8_t *)(param_1 + 4) = param_4;

  *(uint8_t *)(param_1 + 6) = param_3;

  *param_1 = &PTR_FUN_009eb580;

  param_1[5] = 0xffffffff;

  param_1[9] = 0;

  param_1[8] = 0;

  param_1[7] = 0;

  param_1[0xc] = 0;

  param_1[0xb] = 0;

  param_1[10] = 0;

  param_1[0xf] = 0;

  param_1[0xe] = 0;

  param_1[0xd] = 0;

  *(uint8_t *)(param_1 + 0x10) = 0;

  param_1[0x11] = param_5;

  param_1[0x12] = param_6;

  param_1[1] = *param_2;

  param_1[2] = param_2[1];

  param_1[3] = param_2[2];

  return param_1;

}
