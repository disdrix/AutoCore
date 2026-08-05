// =============================================================================
// FUN_00642a90
// -----------------------------------------------------------------------------
// Stable ID: aa_00642a90
// Address:   0x00642a90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00642a90 @ 0x00642a90
// Stable ID: aa_00642a90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CVOGHBBase_AttachOwnerObject, CVOGHBBase_ctor, FUN_00642a90, ROUND.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * __thiscall FUN_00642a90(uint32_t /* width from decompiler */ *param_1,void *param_2,float param_3)



{

  CVOGHBBase_ctor(param_1);

  *param_1 = &PTR_FUN_009e43e0;

  param_1[9] = param_2;

  if (param_2 != (void *)0x0) {

    param_2 = (void *)(*(int *)(*(int *)((int)param_2 + 4) + 4) + 4 + (int)param_2);

  }

  CVOGHBBase_AttachOwnerObject(param_1,param_2);

  param_3 = param_3 * DAT_00a0f520;

  param_1[3] = 0xfffffc18;

  param_1[7] = 6;

  param_1[2] = (int)ROUND(param_3);

  return param_1;

}
