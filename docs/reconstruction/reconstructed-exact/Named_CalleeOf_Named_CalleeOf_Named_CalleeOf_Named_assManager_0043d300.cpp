// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assManager_0043d300
// -----------------------------------------------------------------------------
// Stable ID: aa_0043d300
// Callee of Named_CalleeOf_Named_CalleeOf_Named_assManager
// Address:   0x0043d300  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_assManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×2, while×1, return×1.
//  - Notable callees: FUN_0043d300.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_assManager
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

int * Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assManager_0043d300(int *param_1,int param_2,uint param_3,int param_4,uint param_5,int param_6,

                  uint param_7)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  uint uVar4;

  

  while ((param_2 != param_4 || (param_3 != param_5))) {

    param_5 = param_5 - 1;

    uVar4 = param_5 >> 2;

    iVar1 = uVar4 * -4;

    if (*(uint *)(param_4 + 8) <= uVar4) {

      uVar4 = uVar4 - *(uint *)(param_4 + 8);

    }

    param_7 = param_7 - 1;

    uVar3 = param_7 >> 2;

    iVar2 = uVar3 * -4;

    if (*(uint *)(param_6 + 8) <= uVar3) {

      uVar3 = uVar3 - *(uint *)(param_6 + 8);

    }

    *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_6 + 4) + uVar3 * 4) + (param_7 + iVar2) * 4) =

         *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_4 + 4) + uVar4 * 4) + (param_5 + iVar1) * 4);

  }

  param_1[1] = param_7;

  *param_1 = param_6;

  return param_1;

}
