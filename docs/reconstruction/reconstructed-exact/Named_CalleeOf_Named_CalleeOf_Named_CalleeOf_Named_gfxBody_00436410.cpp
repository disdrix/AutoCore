// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxBody_00436410
// -----------------------------------------------------------------------------
// Stable ID: aa_00436410
// Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxBody
// Address:   0x00436410  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_gfxBody: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00436410, FUN_004365e0, FUN_004369a0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxBody
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxBody_00436410(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  uint uVar1;

  uint *in_EAX;

  uint uVar2;

  uint uVar3;

  uint *unaff_EBX;

  uint uVar4;

  

  uVar3 = in_EAX[2];

  uVar2 = 0;

  uVar1 = *in_EAX;

  uVar4 = ((int)(param_2 - uVar3) >> 2) * 0x20 + param_1;

  if (uVar1 != 0) {

    uVar3 = uVar3 + (uVar1 >> 5) * 4;

    uVar2 = uVar1 & 0x1f;

  }

  FUN_004369a0(&param_1,param_3,param_4,uVar2,uVar3,param_1,param_2,param_1);

  FUN_004365e0(((int)(param_2 - in_EAX[2]) >> 2) * 0x20 + param_1);

  uVar3 = in_EAX[2];

  *unaff_EBX = uVar4 & 0x1f;

  unaff_EBX[1] = uVar3 + (uVar4 >> 5) * 4;

  return;

}
