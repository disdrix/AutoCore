// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGReaction_RandomUnitScalar_00424890
// -----------------------------------------------------------------------------
// Stable ID: aa_00424890
// Callee of Named_CalleeOf_CVOGReaction_RandomUnitScalar
// Address:   0x00424890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGReaction_RandomUnitScalar: event/reaction helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_00424890.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGReaction_RandomUnitScalar
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

void __fastcall Named_CalleeOf_Named_CalleeOf_CVOGReaction_RandomUnitScalar_00424890(uint32_t /* width from decompiler */ param_1,uint param_2)



{

  uint *in_EAX;

  int iVar1;

  

  iVar1 = 1;

  *in_EAX = param_2;

  do {

    in_EAX[1] = (*in_EAX >> 0x1e ^ *in_EAX) * 0x6c078965 + iVar1;

    iVar1 = iVar1 + 1;

    in_EAX = in_EAX + 1;

  } while (iVar1 < 0x270);

  return;

}
