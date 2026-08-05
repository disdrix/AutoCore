// =============================================================================
// FUN_00632850
// -----------------------------------------------------------------------------
// Stable ID: aa_00632850
// Address:   0x00632850  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00632850 @ 0x00632850
// Stable ID: aa_00632850
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CVOGHBBase_AttachOwnerObject, CVOGHBBase_SetPeriodAndCounter, CVOGHBBase_ctor, FUN_00632850.
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

uint32_t /* width from decompiler */ * __thiscall FUN_00632850(uint32_t /* width from decompiler */ *param_1,int param_2,int param_3)



{

  CVOGHBBase_ctor(param_1);

  *param_1 = &PTR_FUN_009e3514;

  CVOGHBBase_SetPeriodAndCounter(param_1,1,true);

  if (param_3 < 1000) {

    param_3 = 1000;

  }

  param_1[2] = param_3;

  *(uint8_t *)(param_2 + 0xb0) = 1;

  CVOGHBBase_AttachOwnerObject(param_1,(void *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2));

  return param_1;

}
