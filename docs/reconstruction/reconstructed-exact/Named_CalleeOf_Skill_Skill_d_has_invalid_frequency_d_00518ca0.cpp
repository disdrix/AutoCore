// =============================================================================
// Named_CalleeOf_Skill_Skill_d_has_invalid_frequency_d_00518ca0
// -----------------------------------------------------------------------------
// Stable ID: aa_00518ca0
// Callee of Skill_Skill_d_has_invalid_frequency_d
// Address:   0x00518ca0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_Skill_d_has_invalid_frequency_d: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004cbe20, FUN_00518c20, FUN_00518ca0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Skill_Skill_d_has_invalid_frequency_d
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

void Named_CalleeOf_Skill_Skill_d_has_invalid_frequency_d_00518ca0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

                 uint32_t /* width from decompiler */ param_5)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ local_18 [2];

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  puVar2 = local_18;

  local_18[0] = param_1;

  local_10 = param_2;

  local_c = param_3;

  local_8 = param_4;

  local_4 = param_5;

  puVar1 = &param_2;

  FUN_00518c20(puVar1,local_18);

  FUN_004cbe20(puVar1,puVar2);

  return;

}
