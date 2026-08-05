// =============================================================================
// FUN_00641ad0
// -----------------------------------------------------------------------------
// Stable ID: aa_00641ad0
// Address:   0x00641ad0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00641ad0 @ 0x00641ad0
// Stable ID: aa_00641ad0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0044f660, FUN_00641680, FUN_00641860, FUN_00641900, FUN_00641960, FUN_00641ad0.
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

uint32_t /* width from decompiler */ __fastcall FUN_00641ad0(uint param_1)



{

  int *piVar1;

  

  FUN_00641960(param_1 + 0x18,param_1 & 0xffffff00);

  FUN_00641900(*(uint32_t /* width from decompiler */ *)(param_1 + 0xc));

  FUN_00641860(*(uint32_t /* width from decompiler */ *)(param_1 + 8),*(uint32_t /* width from decompiler */ *)(param_1 + 0xc));

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  piVar1 = (int *)FUN_0044f660();

  (**(code **)(*piVar1 + 0x14))(0,0);

  FUN_00641680();

  return 0;

}
