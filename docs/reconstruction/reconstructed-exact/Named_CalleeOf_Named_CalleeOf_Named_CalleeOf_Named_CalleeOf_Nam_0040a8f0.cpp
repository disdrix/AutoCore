// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0040a8f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0040a8f0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli
// Address:   0x0040a8f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×3, while×1, return×1.
//  - Notable callees: FUN_0040a8f0, FUN_0040a9d0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0040a8f0(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5,

                 uint32_t /* width from decompiler */ param_6,code *param_7)



{

  int iVar1;

  char cVar2;

  int in_EAX;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  

  iVar1 = in_EAX;

  while( true ) {

    iVar3 = iVar1 * 2;

    iVar5 = iVar3 + 2;

    if (param_2 <= iVar5) break;

    cVar2 = (*param_7)(iVar5 * 0x10 + param_1,(iVar3 + 0x10000001) * 0x10 + param_1);

    if (cVar2 != '\0') {

      iVar5 = iVar3 + 1;

    }

    iVar3 = iVar5 * 0x10 + param_1;

    puVar4 = (uint32_t /* width from decompiler */ *)(iVar1 * 0x10 + param_1);

    *puVar4 = *(uint32_t /* width from decompiler */ *)(iVar5 * 0x10 + param_1);

    puVar4[1] = *(uint32_t /* width from decompiler */ *)(iVar3 + 4);

    puVar4[2] = *(uint32_t /* width from decompiler */ *)(iVar3 + 8);

    puVar4[3] = *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc);

    iVar1 = iVar5;

  }

  if (iVar5 == param_2) {

    iVar5 = (param_2 + 0xfffffff) * 0x10;

    iVar3 = iVar5 + param_1;

    puVar4 = (uint32_t /* width from decompiler */ *)(iVar1 * 0x10 + param_1);

    *puVar4 = *(uint32_t /* width from decompiler */ *)(iVar5 + param_1);

    puVar4[1] = *(uint32_t /* width from decompiler */ *)(iVar3 + 4);

    puVar4[2] = *(uint32_t /* width from decompiler */ *)(iVar3 + 8);

    puVar4[3] = *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc);

  }

  FUN_0040a9d0(param_1,in_EAX,param_3,param_4,param_5,param_6,param_7);

  return;

}
