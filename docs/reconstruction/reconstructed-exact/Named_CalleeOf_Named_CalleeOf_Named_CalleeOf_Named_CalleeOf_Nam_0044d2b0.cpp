// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0044d2b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0044d2b0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0044d2b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: while×1, if×1, return×1.
//  - Notable callees: FUN_00746810×2, FUN_0044d2b0.
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0044d2b0(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  uint32_t /* width from decompiler */ *puVar1;

  int in_EAX;

  int iVar2;

  int iVar3;

  int iVar4;

  

  while (param_2 < in_EAX) {

    iVar4 = (in_EAX + -1) / 2;

    puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + iVar4 * 8);

    iVar2 = FUN_00746810();

    iVar3 = FUN_00746810();

    if (iVar3 <= iVar2) break;

    *(uint32_t /* width from decompiler */ *)(param_1 + in_EAX * 8) = *puVar1;

    *(uint32_t /* width from decompiler */ *)(param_1 + 4 + in_EAX * 8) = puVar1[1];

    in_EAX = iVar4;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + in_EAX * 8) = param_3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 4 + in_EAX * 8) = param_4;

  return;

}
