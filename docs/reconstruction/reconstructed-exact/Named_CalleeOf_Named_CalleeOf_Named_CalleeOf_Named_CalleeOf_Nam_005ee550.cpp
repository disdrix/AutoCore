// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005ee550
// -----------------------------------------------------------------------------
// Stable ID: aa_005ee550
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST
// Address:   0x005ee550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×2, for×2, return×1.
//  - Notable callees: FUN_005ee170, FUN_005ee550, free, malloc.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST
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

int * __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005ee550(int *param_1,int param_2,int param_3,int param_4)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  

  *param_1 = 0;

  param_1[1] = 0;

  param_1[2] = 0;

  param_1[4] = param_4;

  if (param_3 != 0) {

    puVar4 = malloc(param_3 * 0xc);

    puVar1 = (uint32_t /* width from decompiler */ *)param_1[1];

    puVar3 = puVar4;

    for (puVar5 = (uint32_t /* width from decompiler */ *)*param_1; puVar5 != puVar1; puVar5 = puVar5 + 3) {

      *puVar3 = *puVar5;

      puVar3[1] = puVar5[1];

      puVar3[2] = puVar5[2];

      puVar3 = puVar3 + 3;

    }

    if ((void *)*param_1 != (void *)0x0) {

      free((void *)*param_1);

    }

    iVar2 = *param_1;

    *param_1 = (int)puVar4;

    param_1[2] = (int)(puVar4 + param_3 * 3);

    param_1[1] = (int)(puVar4 + ((param_1[1] - iVar2) / 0xc) * 3);

  }

  for (; param_3 != 0; param_3 = param_3 + -1) {

    FUN_005ee170(param_2);

    param_2 = param_2 + 0xc;

  }

  return param_1;

}
