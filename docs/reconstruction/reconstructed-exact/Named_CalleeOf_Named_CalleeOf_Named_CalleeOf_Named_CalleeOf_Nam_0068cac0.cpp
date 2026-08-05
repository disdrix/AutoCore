// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068cac0
// -----------------------------------------------------------------------------
// Stable ID: aa_0068cac0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0068cac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00446860, FUN_004490a0, FUN_0068cac0.
//  - Return sites: 2.

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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068cac0(int param_1,float param_2,byte param_3)



{

  int iVar1;

  float *pfVar2;

  char *pcVar3;

  char cVar4;

  

  param_2 = g_flOne - param_2;

  cVar4 = (char)((uint)param_3 % *(uint *)(*(int *)(param_1 + 4) + 0x2c)) +

          *(char *)(*(int *)(param_1 + 4) + 0x28);

  iVar1 = *(int *)(param_1 + 0xf4);

  param_3 = cVar4;

  if ((iVar1 == 0) ||

     ((uint)(*(int *)(param_1 + 0xfc) - iVar1 >> 2) <= (uint)(*(int *)(param_1 + 0xf8) - iVar1 >> 2)

     )) {

    FUN_004490a0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xf8),1,&param_2);

  }

  else {

    pfVar2 = *(float **)(param_1 + 0xf8);

    *pfVar2 = param_2;

    *(float **)(param_1 + 0xf8) = pfVar2 + 1;

  }

  iVar1 = *(int *)(param_1 + 0x104);

  if ((iVar1 != 0) &&

     ((uint)(*(int *)(param_1 + 0x108) - iVar1) < (uint)(*(int *)(param_1 + 0x10c) - iVar1))) {

    pcVar3 = *(char **)(param_1 + 0x108);

    *pcVar3 = cVar4;

    *(char **)(param_1 + 0x108) = pcVar3 + 1;

    return;

  }

  FUN_00446860(*(uint32_t /* width from decompiler */ *)(param_1 + 0x108),1,&param_3);

  return;

}
