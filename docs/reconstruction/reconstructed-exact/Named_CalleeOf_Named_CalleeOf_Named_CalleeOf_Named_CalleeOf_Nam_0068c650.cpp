// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068c650
// -----------------------------------------------------------------------------
// Stable ID: aa_0068c650
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0068c650  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_006a3db0×3, FUN_005a3920, FUN_0068c650.
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068c650(int param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  

  iVar3 = FUN_006a3db0();

  iVar4 = FUN_006a3db0();

  param_2 = FUN_006a3db0();

  iVar1 = *(int *)(param_1 + 0x54);

  param_2 = ((0xff00 - iVar3) * 0x100 - iVar4) * 0x100 - param_2;

  if ((iVar1 != 0) &&

     ((uint)(*(int *)(param_1 + 0x58) - iVar1 >> 2) < (uint)(*(int *)(param_1 + 0x5c) - iVar1 >> 2))

     ) {

    piVar2 = *(int **)(param_1 + 0x58);

    *piVar2 = param_2;

    *(int **)(param_1 + 0x58) = piVar2 + 1;

    return;

  }

  FUN_005a3920(*(uint32_t /* width from decompiler */ *)(param_1 + 0x58),1,&param_2);

  return;

}
