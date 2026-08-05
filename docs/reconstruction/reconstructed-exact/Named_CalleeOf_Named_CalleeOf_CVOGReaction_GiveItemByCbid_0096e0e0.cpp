// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGReaction_GiveItemByCbid_0096e0e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0096e0e0
// Callee of Named_CalleeOf_CVOGReaction_GiveItemByCbid
// Address:   0x0096e0e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGReaction_GiveItemByCbid: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0096e0e0, FUN_00972cc0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGReaction_GiveItemByCbid
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

int __fastcall Named_CalleeOf_Named_CalleeOf_CVOGReaction_GiveItemByCbid_0096e0e0(uint32_t /* width from decompiler */ *param_1)



{

  int extraout_EDX;

  

  *param_1 = &PTR_LAB_00aa04e8;

  FUN_00972cc0();

  *(uint32_t /* width from decompiler */ *)(extraout_EDX + 0xf4) = 0;

  *(undefined ***)(extraout_EDX + 0xf0) = &PTR_FUN_00aa0504;

  *(uint32_t /* width from decompiler */ *)(extraout_EDX + 0x140) = 0xffffffff;

  return extraout_EDX;

}
