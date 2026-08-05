// =============================================================================
// Named_CalleeOf_Named_gfxEffectDetailDisplay_00759860
// -----------------------------------------------------------------------------
// Stable ID: aa_00759860
// Callee of Named_gfxEffectDetailDisplay (+1 other named callers)
// Address:   0x00759860  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxEffectDetailDisplay: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_gfxEffectDetailDisplay (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT31, FUN_00441f20, FUN_00442390, FUN_004568c0, FUN_00759860.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxEffectDetailDisplay (+1 other named callers)
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

uint32_t /* width from decompiler */ * __fastcall Named_CalleeOf_Named_gfxEffectDetailDisplay_00759860(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b2510;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_00a9f304;

  iVar1 = FUN_00441f20();

  param_1[2] = iVar1;

  *(uint8_t *)(iVar1 + 0x3d) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1[2] + 4) = param_1[2];

  *(uint32_t /* width from decompiler */ *)param_1[2] = param_1[2];

  *(uint32_t /* width from decompiler */ *)(param_1[2] + 8) = param_1[2];

  param_1[3] = 0;

  local_4 = 0;

  iVar1 = FUN_00442390();

  param_1[5] = iVar1;

  *(uint8_t *)(iVar1 + 0x1d) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1[5] + 4) = param_1[5];

  *(uint32_t /* width from decompiler */ *)param_1[5] = param_1[5];

  *(uint32_t /* width from decompiler */ *)(param_1[5] + 8) = param_1[5];

  param_1[6] = 0;

  param_1[8] = 0;

  param_1[9] = 0;

  param_1[10] = 0;

  param_1[0xb] = 0xffffffff;

  param_1[0xd] = 0;

  param_1[0xc] = &PTR_FUN_00a9db18;

  param_1[0xf] = 0;

  param_1[0x10] = 0;

  param_1[0x11] = 0;

  param_1[0x17] = 0;

  param_1[0x18] = 0;

  param_1[0x19] = 0;

  param_1[0x1a] = 0;

  param_1[0x1b] = 0;

  param_1[0x1c] = 0;

  param_1[0x1d] = 0;

  param_1[0x1e] = DAT_00d1f024;

  param_1[0x1f] = DAT_00d1f028;

  param_1[0x20] = DAT_00d1f01c;

  param_1[0x21] = DAT_00d1f020;

  param_1[0x22] = 0;

  *(uint8_t *)(param_1 + 0x23) = 1;

  *(uint8_t *)((int)param_1 + 0x8d) = 0;

  param_1[0x25] = 0;

  param_1[0x26] = 0;

  param_1[0x27] = 0;

  local_4 = CONCAT31(local_4._1_3_,6);

  param_1[0x28] = 0;

  iVar1 = FUN_004568c0();

  param_1[0x2a] = iVar1;

  *(uint8_t *)(iVar1 + 0x11) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1[0x2a] + 4) = param_1[0x2a];

  *(uint32_t /* width from decompiler */ *)param_1[0x2a] = param_1[0x2a];

  *(uint32_t /* width from decompiler */ *)(param_1[0x2a] + 8) = param_1[0x2a];

  param_1[0x2b] = 0;

  param_1[0x2c] = 0;

  param_1[0x2d] = 0;

  ExceptionList = local_c;

  return param_1;

}
