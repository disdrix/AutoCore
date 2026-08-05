// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_hkWorld_0063f400
// -----------------------------------------------------------------------------
// Stable ID: aa_0063f400
// Callee of Named_CalleeOf_Named_CalleeOf_Named_hkWorld
// Address:   0x0063f400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_hkWorld: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0063f330, FUN_0063f400.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_hkWorld
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_hkWorld_0063f400(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  float fVar2;

  

  fVar2 = g_flOne;

  param_1[0x14] = DAT_00a0f718;

  param_1[0x15] = g_flHardKillInterpolate;

  param_1[0x16] = g_flMultiKillCountBlend;

  param_1[0x17] = DAT_00a0f70c;

  uVar1 = DAT_009e3ebc;

  *(uint16_t *)((int)param_1 + 6) = 1;

  *param_1 = &PTR_FUN_009e3ec0;

  param_1[4] = uVar1;

  param_1[5] = uVar1;

  param_1[6] = uVar1;

  param_1[7] = uVar1;

  param_1[0xc] = uVar1;

  param_1[0xd] = uVar1;

  param_1[0xe] = uVar1;

  param_1[0xf] = uVar1;

  param_1[0xb] = 0;

  param_1[10] = 0;

  param_1[9] = 0;

  param_1[8] = 0;

  param_1[0xb] = fVar2;

  param_1[0x13] = 0;

  param_1[0x12] = 0;

  param_1[0x11] = 0;

  param_1[0x10] = 0;

  param_1[0x13] = fVar2;

  FUN_0063f330(*(uint32_t /* width from decompiler */ *)(param_2 + 0xc));

  return param_1;

}
