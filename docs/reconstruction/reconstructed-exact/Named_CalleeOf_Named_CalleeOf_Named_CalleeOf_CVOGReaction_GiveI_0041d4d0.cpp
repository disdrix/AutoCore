// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_GiveI_0041d4d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0041d4d0
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGReaction_GiveItemByCbid
// Address:   0x0041d4d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGReaction_GiveItemByCbid: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_0041d4d0, FUN_00420ab0, FUN_0045f020.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGReaction_GiveItemByCbid
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_GiveI_0041d4d0(uint32_t /* width from decompiler */ param_1)



{

  uint in_EAX;

  uint32_t /* width from decompiler */ uVar1;

  uint uVar2;

  int iVar3;

  int unaff_EBX;

  

  iVar3 = *(int *)(unaff_EBX + 4);

  if (iVar3 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = *(int *)(unaff_EBX + 8) - iVar3 >> 4;

  }

  if (uVar2 < in_EAX) {

    if (iVar3 == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = *(int *)(unaff_EBX + 8) - iVar3 >> 4;

    }

    FUN_00420ab0(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 8),in_EAX - iVar3,&param_1);

    return;

  }

  if (((iVar3 != 0) && (in_EAX < (uint)(*(int *)(unaff_EBX + 8) - iVar3 >> 4))) &&

     (in_EAX * 0x10 + iVar3 != *(int *)(unaff_EBX + 8))) {

    uVar1 = FUN_0045f020(param_1);

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 8) = uVar1;

  }

  return;

}
