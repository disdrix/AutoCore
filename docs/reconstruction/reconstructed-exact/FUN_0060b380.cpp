// =============================================================================
// FUN_0060b380
// -----------------------------------------------------------------------------
// Stable ID: aa_0060b380
// Address:   0x0060b380  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0060b380 @ 0x0060b380
// Stable ID: aa_0060b380
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CVOGHBBase_AttachOwnerObject×2, CVOGHBBase_ctor, FUN_0060b380.
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

uint32_t /* width from decompiler */ * __thiscall FUN_0060b380(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,int param_3,int param_4)



{

  CVOGHBBase_ctor(param_1);

  *param_1 = &PTR_FUN_009df668;

  param_1[2] = param_4 * 1000;

  param_1[3] = 1;

  param_1[7] = 10;

  param_1[9] = param_2;

  param_1[10] = param_3;

  if (param_3 == 0) {

    CVOGHBBase_AttachOwnerObject(param_1,(void *)0x0);

    return param_1;

  }

  CVOGHBBase_AttachOwnerObject(param_1,(void *)(*(int *)(*(int *)(param_3 + 4) + 4) + 4 + param_3));

  return param_1;

}
