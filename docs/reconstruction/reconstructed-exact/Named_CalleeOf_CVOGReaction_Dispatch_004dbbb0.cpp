// =============================================================================
// Named_CalleeOf_CVOGReaction_Dispatch_004dbbb0
// -----------------------------------------------------------------------------
// Stable ID: aa_004dbbb0
// Callee of CVOGReaction_Dispatch
// Address:   0x004dbbb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_Dispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×4, goto×2, do×1, while×1, return×1.
//  - Notable callees: CNDHash_LookupByKey, FUN_004dbbb0, FUN_004e7c30.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGReaction_Dispatch
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

void __thiscall Named_CalleeOf_CVOGReaction_Dispatch_004dbbb0(int param_1,uint32_t /* width from decompiler */ param_2,uint param_3)



{

  void *pvVar1;

  int iVar2;

  

  iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe5c8) + 0x10) +

                           (*(uint *)(*(int *)(param_1 + 0xe5c8) + 8) & param_3) * 4) + 4);

  if (iVar2 == 0) {

LAB_004dbbe4:

    iVar2 = 0;

  }

  else {

    do {

      if (param_3 == *(uint *)(iVar2 + 0x10)) {

        if (iVar2 == 0) goto LAB_004dbbe4;

        iVar2 = *(int *)(iVar2 + 8);

        goto LAB_004dbbeb;

      }

      iVar2 = *(int *)(iVar2 + 0xc);

    } while (iVar2 != 0);

    iVar2 = 0;

  }

LAB_004dbbeb:

  if ((iVar2 != 0) &&

     (pvVar1 = CNDHash_LookupByKey(*(void **)(param_1 + 0xe5cc),param_3), pvVar1 == (void *)0x0)) {

    FUN_004e7c30(param_3,iVar2,0);

  }

  return;

}
