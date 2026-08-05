// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00692010
// -----------------------------------------------------------------------------
// Stable ID: aa_00692010
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00692010  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_006918b0, FUN_00692010.
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00692010(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ in_stack_00000034;

  uint32_t /* width from decompiler */ in_stack_00000038;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c [9];

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_34 = param_2;

  local_38 = param_1;

  local_30 = param_3;

  puVar2 = (uint32_t /* width from decompiler */ *)&stack0x00000010;

  puVar3 = local_2c;

  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  local_8 = in_stack_00000034;

  local_4 = in_stack_00000038;

  FUN_006918b0(&local_38);

  return;

}
