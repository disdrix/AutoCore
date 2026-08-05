// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SERVER_GOT_G_00658bf0
// -----------------------------------------------------------------------------
// Stable ID: aa_00658bf0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x
// Address:   0x00658bf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00636370, FUN_00658bf0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x
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

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SERVER_GOT_G_00658bf0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7)



{

  FUN_00636370(param_7);

  *param_1 = &PTR_FUN_009e5e88;

  param_1[2] = &PTR_LAB_009e5e78;

  param_1[8] = *param_2;

  param_1[9] = param_2[1];

  param_1[10] = param_2[2];

  param_1[0xb] = param_2[3];

  param_1[0xc] = *param_3;

  param_1[0xd] = param_3[1];

  param_1[0xe] = param_3[2];

  param_1[0xf] = param_3[3];

  param_1[0x10] = param_4;

  param_1[0x11] = param_5;

  param_1[0x13] = param_6;

  param_1[0x12] = DAT_00aaaab4;

  return param_1;

}
