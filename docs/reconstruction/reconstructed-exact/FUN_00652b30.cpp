// =============================================================================
// FUN_00652b30
// -----------------------------------------------------------------------------
// Stable ID: aa_00652b30
// Address:   0x00652b30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00652b30 @ 0x00652b30
// Stable ID: aa_00652b30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_006483f0, FUN_00652b30.
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

uint32_t /* width from decompiler */ * __fastcall FUN_00652b30(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  

  *(uint16_t *)((int)param_1 + 6) = 1;

  *param_1 = &PTR_FUN_009e5bc4;

  iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0xc,0x17);

  if (iVar1 != 0) {

    FUN_006483f0();

    param_1[2] = iVar1;

    return param_1;

  }

  param_1[2] = 0;

  return param_1;

}
