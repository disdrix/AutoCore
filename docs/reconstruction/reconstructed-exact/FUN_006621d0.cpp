// =============================================================================
// FUN_006621d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006621d0
// Address:   0x006621d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006621d0 @ 0x006621d0
// Stable ID: aa_006621d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006621d0, FUN_0066dcf0.
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

uint32_t /* width from decompiler */ * __fastcall FUN_006621d0(uint32_t /* width from decompiler */ *param_1)



{

  float fVar1;

  

  FUN_0066dcf0();

  param_1[2] = DAT_00a0f298;

  param_1[1] = g_flVehicleHpTechCoeff;

  *param_1 = DAT_00aaa688;

  param_1[3] = DAT_00aaa68c;

  fVar1 = g_flLevelUpUiBase_Inferred;

  param_1[6] = 0x18;

  param_1[4] = fVar1;

  param_1[5] = fVar1;

  return param_1;

}
