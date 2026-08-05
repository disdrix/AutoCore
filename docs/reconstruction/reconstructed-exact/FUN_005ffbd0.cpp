// =============================================================================
// FUN_005ffbd0
// -----------------------------------------------------------------------------
// Stable ID: aa_005ffbd0
// Address:   0x005ffbd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005ffbd0 @ 0x005ffbd0
// Stable ID: aa_005ffbd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CVOGHBBase_AttachOwnerObject×2, CVOGHBBase_SetPeriodAndCounter, CVOGHBBase_ctor, DAT_00af0c6c, TimedAction_CreateTokenFlagAction.
//  - Return sites: 2.

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

/* TimedAction_CreateTokenFlagAction - enter-world action with period DAT_00af0c6c (300000).

   Sets character token/flag via FUN_005ffc20 / mask 0x100. NOT combat pools. */



uint32_t /* width from decompiler */ * __thiscall

TimedAction_CreateTokenFlagAction(uint32_t /* width from decompiler */ *param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  CVOGHBBase_ctor(param_1);

  *param_1 = &PTR_FUN_009dde2c;

  CVOGHBBase_SetPeriodAndCounter(param_1,1,true);

  param_1[2] = param_3;

  if (param_2 == 0) {

    CVOGHBBase_AttachOwnerObject(param_1,(void *)0x0);

    return param_1;

  }

  CVOGHBBase_AttachOwnerObject(param_1,(void *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2));

  return param_1;

}
