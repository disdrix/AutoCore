// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_00581220
// -----------------------------------------------------------------------------
// Stable ID: aa_00581220
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x00581220  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00581220.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
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

void __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_00581220(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  *(uint16_t *)((int)param_1 + 6) = 1;

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[5] = 0;

  param_1[6] = 0;

  param_1[4] = 0xffffffff;

  param_1[7] = 0;

  param_1[8] = 0;

  param_1[10] = 0;

  param_1[9] = 2;

  param_1[0xb] = 0;

  param_1[0xc] = 0;

  param_1[0xd] = 0;

  param_1[0xe] = 0x80000000;

  param_1[0xf] = 0;

  param_1[0x10] = 0;

  param_1[0x11] = 0x80000000;

  param_1[0x12] = 0;

  param_1[0x13] = 0;

  param_1[0x14] = 0x80000000;

  param_1[0xb] = param_1;

  *param_1 = &PTR_FUN_009d45b0;

  param_1[0x20] = 0;

  param_1[0x21] = 0;

  param_1[0x22] = 0x80000000;

  param_1[0x18] = param_2[8];

  param_1[0x19] = param_2[9];

  param_1[0x1a] = param_2[10];

  param_1[0x1b] = param_2[0xb];

  param_1[0x1c] = param_2[0xc];

  param_1[0x1d] = param_2[0xd];

  param_1[0x1e] = param_2[0xe];

  param_1[0x1f] = param_2[0xf];

  param_1[10] = *param_2;

  return;

}
