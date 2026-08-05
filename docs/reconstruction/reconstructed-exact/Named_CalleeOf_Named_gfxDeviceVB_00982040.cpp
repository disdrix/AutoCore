// =============================================================================
// Named_CalleeOf_Named_gfxDeviceVB_00982040
// -----------------------------------------------------------------------------
// Stable ID: aa_00982040
// Callee of Named_gfxDeviceVB
// Address:   0x00982040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxDeviceVB: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00982040.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxDeviceVB
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

void __fastcall Named_CalleeOf_Named_gfxDeviceVB_00982040(uint32_t /* width from decompiler */ *param_1)



{

  float fVar1;

  float fVar2;

  

  fVar1 = g_flOne;

  *param_1 = &PTR_FUN_00aa6d74;

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[4] = 0;

  param_1[5] = DAT_00d1a6c0;

  param_1[6] = DAT_00d1a6c4;

  param_1[7] = DAT_00d1a6c8;

  param_1[8] = 0;

  param_1[10] = 0;

  fVar2 = g_flMultiKillCountBlend;

  param_1[9] = fVar1;

  param_1[0xb] = fVar2;

  param_1[0xc] = DAT_00a0f70c;

  param_1[0xd] = DAT_00a0f71c;

  param_1[0xe] = DAT_00a0f720;

  param_1[0xf] = fVar1;

  param_1[0x10] = DAT_00afdf0c;

  return;

}
