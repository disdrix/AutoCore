// =============================================================================
// Named_CalleeOf_Named_gfxBody_004363b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004363b0
// Callee of Named_gfxBody
// Address:   0x004363b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxBody: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004363b0, FUN_004364b0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxBody
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

void Named_CalleeOf_Named_gfxBody_004363b0(int param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  int iVar2;

  int in_EAX;

  uint uVar3;

  uint *unaff_EDI;

  

  iVar1 = *(int *)(in_EAX + 8);

  FUN_004364b0(param_1,param_2,param_3);

  iVar2 = *(int *)(in_EAX + 8);

  uVar3 = (param_2 - iVar1 >> 2) * 0x20 + param_1;

  *unaff_EDI = uVar3 & 0x1f;

  unaff_EDI[1] = iVar2 + (uVar3 >> 5) * 4;

  return;

}
