// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_UnpackSpecialMessage_0042b3a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0042b3a0
// Callee of Named_CalleeOf_Client_UnpackSpecialMessage
// Address:   0x0042b3a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_UnpackSpecialMessage: event/reaction helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0042b3a0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_UnpackSpecialMessage
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Client_UnpackSpecialMessage_0042b3a0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  param_1[4] = param_3;

  param_1[3] = param_2;

  param_1[1] = 0;

  param_1[2] = 0;

  *(uint8_t *)(param_1 + 5) = 0;

  *param_1 = &PTR_LAB_009d7b94;

  param_1[0xb] = param_3 * 8;

  param_1[0xc] = param_3 * 8;

  param_1[6] = 0;

  *(uint8_t *)(param_1 + 7) = 0;

  *(uint8_t *)((int)param_1 + 0x1d) = 0;

  *(uint8_t *)(param_1 + 0xe) = 0;

  param_1[0xd] = 0;

  return;

}
