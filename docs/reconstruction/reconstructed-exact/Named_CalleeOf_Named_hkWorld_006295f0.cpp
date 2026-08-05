// =============================================================================
// Named_CalleeOf_Named_hkWorld_006295f0
// -----------------------------------------------------------------------------
// Stable ID: aa_006295f0
// Callee of Named_hkWorld (+1 other named callers)
// Address:   0x006295f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_hkWorld: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_hkWorld (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006295f0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_hkWorld (+1 other named callers)
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

void __thiscall Named_CalleeOf_Named_hkWorld_006295f0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[4] = 0;

  param_1[5] = 0;

  param_1[6] = 0;

  param_1[7] = &PTR_LAB_009d2794;

  param_1[8] = param_2;

  *param_1 = &PTR_FUN_009e331c;

  param_1[7] = &PTR_LAB_009e3310;

  *(uint8_t *)(param_1 + 10) = 0;

  *(uint8_t *)((int)param_1 + 0x29) = 1;

  *(uint8_t *)(param_1 + 0xb) = 0;

  *(uint8_t *)(param_1 + 0xc) = 1;

  param_1[0xd] = 0;

  param_1[0xe] = 0;

  param_1[0x10] = 0;

  param_1[0x11] = 0x80000001;

  param_1[0xf] = param_1 + 0x12;

  param_1[0x13] = 0;

  param_1[0x14] = 0;

  param_1[0x15] = 0x80000000;

  param_1[0x17] = 0;

  param_1[0x18] = 0x80000001;

  param_1[0x16] = param_1 + 0x19;

  param_1[0x1a] = 0;

  param_1[0x1b] = 0;

  param_1[0x1c] = 0x80000000;

  param_1[0x1d] = 0;

  param_1[0x1e] = 0;

  param_1[0x1f] = 0x80000000;

  param_1[0x20] = 0;

  param_1[0x21] = 0;

  param_1[0x22] = 0x80000000;

  param_1[0x23] = 0;

  param_1[0x24] = 0;

  param_1[0x25] = 0x80000000;

  return;

}
