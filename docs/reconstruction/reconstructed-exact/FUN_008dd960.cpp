// =============================================================================
// FUN_008dd960
// -----------------------------------------------------------------------------
// Stable ID: aa_008dd960
// Address:   0x008dd960  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008dd960 @ 0x008dd960
// Stable ID: aa_008dd960
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_0087b500, FUN_008dd960.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ __thiscall FUN_008dd960(int *param_1,int param_2,int param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  iVar1 = (**(code **)(*param_1 + 0xe8))();

  if (iVar1 == -1) {

    return 0xffffff00;

  }

  if ((param_3 == 40000) && (param_2 == 8)) {

    return 0x9c01;

  }

  uVar2 = FUN_0087b500(param_2,param_3);

  return uVar2;

}
