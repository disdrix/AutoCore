// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGReaction_GiveItemByCbid_005d55f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005d55f0
// Callee of Named_CalleeOf_CVOGReaction_GiveItemByCbid
// Address:   0x005d55f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGReaction_GiveItemByCbid: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005d55f0.
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

void __thiscall Named_CalleeOf_Named_CalleeOf_CVOGReaction_GiveItemByCbid_005d55f0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint8_t param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  

  uVar1 = DAT_00aaa7a4;

  param_1[4] = param_2;

  *param_1 = &PTR_LAB_009dacdc;

  param_1[0xc] = DAT_009dacc8;

  param_1[0xd] = DAT_009daccc;

  param_1[0xe] = DAT_009dacd0;

  param_1[0xf] = DAT_009dacd4;

  *(uint8_t *)(param_1 + 0x17) = param_3;

  param_1[0x13] = uVar1;

  *(uint8_t *)((int)param_1 + 0x52) = 0;

  param_1[0x15] = 0;

  param_1[0x16] = 0;

  *(uint8_t *)(param_1 + 0x14) = 2;

  param_1[0x10] = 0xffffffff;

  param_1[0x11] = 0xffffffff;

  param_1[0x12] = 0xffffffff;

  *(uint8_t *)((int)param_1 + 0x51) = 0;

  param_1[8] = 0;

  param_1[9] = 0;

  param_1[10] = 0;

  param_1[0xb] = 0;

  return;

}
