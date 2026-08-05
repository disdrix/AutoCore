// =============================================================================
// Named_CalleeOf_Mission_i_d_objective_xml_008a8570
// -----------------------------------------------------------------------------
// Stable ID: aa_008a8570
// Callee of Mission_i_d_objective_xml
// Address:   0x008a8570  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_i_d_objective_xml: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00416c90, FUN_008a8570.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_i_d_objective_xml
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

void __fastcall Named_CalleeOf_Mission_i_d_objective_xml_008a8570(int param_1)



{

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4b8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4bc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4b4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x504) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x508) = 0;

  FUN_00416c90();

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x670) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x674) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x67c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x680) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x684) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x688) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x690) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x694) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x68c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x50c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x698) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x678) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x510) = 0;

  *(float *)(param_1 + 0x514) = g_flOne;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x520) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x524) = 0xffffffff;

  return;

}
