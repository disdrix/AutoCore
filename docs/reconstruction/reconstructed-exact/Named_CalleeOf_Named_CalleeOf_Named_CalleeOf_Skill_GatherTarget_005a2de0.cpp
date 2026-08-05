// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Skill_GatherTarget_005a2de0
// -----------------------------------------------------------------------------
// Stable ID: aa_005a2de0
// Callee of Named_CalleeOf_Named_CalleeOf_Skill_GatherTargetsInArea (+1 other named callers)
// Address:   0x005a2de0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Skill_GatherTargetsInArea: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_CalleeOf_Skill_GatherTargetsInArea (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005a2de0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Skill_GatherTargetsInArea (+1 other named callers)
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Skill_GatherTarget_005a2de0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ *param_4,

                 uint8_t param_5)



{

  uint32_t /* width from decompiler */ *puVar1;

  

  puVar1 = operator_new(0x30);

  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    *puVar1 = param_1;

    puVar1[1] = param_2;

    puVar1[2] = param_3;

    puVar1[4] = *param_4;

    puVar1[5] = param_4[1];

    puVar1[6] = param_4[2];

    puVar1[7] = param_4[3];

    puVar1[8] = param_4[4];

    puVar1[9] = param_4[5];

    *(uint8_t *)(puVar1 + 10) = param_5;

    *(uint8_t *)((int)puVar1 + 0x29) = 0;

  }

  return;

}
