// =============================================================================
// FUN_006472e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006472e0
// Address:   0x006472e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006472e0 @ 0x006472e0
// Stable ID: aa_006472e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006472e0.
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

void __thiscall FUN_006472e0(uint32_t /* width from decompiler */ *param_1,int *param_2)



{

  int *piVar1;

  int iVar2;

  

  *param_1 = &PTR_FUN_009e46e8;

  *(uint16_t *)((int)param_1 + 6) = 1;

  param_1[2] = 1;

  iVar2 = *param_2;

  piVar1 = (int *)(iVar2 + -4);

  *piVar1 = *piVar1 + 1;

  param_1[3] = iVar2;

  *param_1 = &PTR_FUN_009e46ec;

  DAT_00d02c6c = DAT_00d02c6c + 1;

  param_1[4] = &DAT_00d02c70;

  param_1[5] = 0;

  param_1[6] = 0;

  return;

}
