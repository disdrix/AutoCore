// =============================================================================
// Named_CalleeOf_Skill_Skill_d_had_invalid_creature_d_00614dc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00614dc0
// Callee of Skill_Skill_d_had_invalid_creature_d
// Address:   0x00614dc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_Skill_d_had_invalid_creature_d: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005788d0, FUN_00614dc0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Skill_Skill_d_had_invalid_creature_d
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

Named_CalleeOf_Skill_Skill_d_had_invalid_creature_d_00614dc0(uint32_t /* width from decompiler */ *param_1,int *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7)



{

  uint16_t uVar1;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a8648;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_005788d0(param_2,param_3,param_4,param_5,param_6,param_7);

  *param_1 = &PTR_FUN_009d0ec4;

  local_4 = 0;

  uVar1 = (**(code **)(*param_2 + 0x27c))();

  *(uint16_t *)(param_1 + 0x1b1) = uVar1;

  ExceptionList = pvStack_c;

  return param_1;

}
