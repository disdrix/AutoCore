// =============================================================================
// FUN_006ef400
// -----------------------------------------------------------------------------
// Stable ID: aa_006ef400
// Address:   0x006ef400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006ef400 @ 0x006ef400
// Stable ID: aa_006ef400
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005eb040, FUN_006ef400.
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

uint32_t /* width from decompiler */ * __thiscall FUN_006ef400(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  short *psVar1;

  int iVar2;

  

  *param_1 = &PTR_FUN_009e5fdc;

  *(uint16_t *)((int)param_1 + 6) = 1;

  param_1[2] = *param_2;

  *param_1 = &PTR_FUN_00a0ecf8;

  FUN_005eb040(param_2 + 4);

  iVar2 = param_2[1];

  param_1[3] = iVar2;

  psVar1 = (short *)(iVar2 + 6);

  *psVar1 = *psVar1 + 1;

  return param_1;

}
