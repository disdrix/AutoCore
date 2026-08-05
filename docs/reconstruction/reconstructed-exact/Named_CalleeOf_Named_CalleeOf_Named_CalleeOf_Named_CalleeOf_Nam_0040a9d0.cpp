// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0040a9d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0040a9d0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0040a9d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: while×1, if×1, return×1.
//  - Notable callees: FUN_0040a9d0.
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0040a9d0(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5,

                 uint32_t /* width from decompiler */ param_6,code *param_7)



{

  char cVar1;

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  

  while (param_2 < in_EAX) {

    iVar4 = (in_EAX + -1) / 2;

    puVar3 = (uint32_t /* width from decompiler */ *)(iVar4 * 0x10 + param_1);

    cVar1 = (*param_7)(puVar3,&param_3);

    if (cVar1 == '\0') break;

    puVar2 = (uint32_t /* width from decompiler */ *)(in_EAX * 0x10 + param_1);

    *puVar2 = *puVar3;

    puVar2[1] = puVar3[1];

    puVar2[2] = puVar3[2];

    puVar2[3] = puVar3[3];

    in_EAX = iVar4;

  }

  puVar3 = (uint32_t /* width from decompiler */ *)(in_EAX * 0x10 + param_1);

  *puVar3 = param_3;

  puVar3[1] = param_4;

  puVar3[2] = param_5;

  puVar3[3] = param_6;

  return;

}
