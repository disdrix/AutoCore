// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0044d180
// -----------------------------------------------------------------------------
// Stable ID: aa_0044d180
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0044d180  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00746810×6, FUN_0044d180.
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0044d180(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  int iVar4;

  

  iVar3 = FUN_00746810();

  iVar4 = FUN_00746810();

  if (iVar4 < iVar3) {

    uVar1 = *param_2;

    uVar2 = param_2[1];

    *param_2 = *param_1;

    param_2[1] = param_1[1];

    *param_1 = uVar1;

    param_1[1] = uVar2;

  }

  iVar3 = FUN_00746810();

  iVar4 = FUN_00746810();

  if (iVar4 < iVar3) {

    uVar1 = *param_3;

    uVar2 = param_3[1];

    *param_3 = *param_2;

    param_3[1] = param_2[1];

    *param_2 = uVar1;

    param_2[1] = uVar2;

  }

  iVar3 = FUN_00746810();

  iVar4 = FUN_00746810();

  if (iVar4 < iVar3) {

    uVar1 = *param_2;

    uVar2 = param_2[1];

    *param_2 = *param_1;

    param_2[1] = param_1[1];

    *param_1 = uVar1;

    param_1[1] = uVar2;

  }

  return;

}
