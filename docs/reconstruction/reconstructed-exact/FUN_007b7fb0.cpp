// =============================================================================
// FUN_007b7fb0
// -----------------------------------------------------------------------------
// Stable ID: aa_007b7fb0
// Address:   0x007b7fb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007b7fb0 @ 0x007b7fb0
// Stable ID: aa_007b7fb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00404b30, FUN_007b7fb0, block, wcscpy.
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

/* WARNING: Removing unreachable block (ram,0x007b7ff3) */



void FUN_007b7fb0(uint32_t /* width from decompiler */ param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  wchar_t local_100 [128];

  

  uVar1 = (*(code *)PTR_FUN_00af8c9c)();

  FUN_00404b30(param_1,uVar1);

  wcscpy((wchar_t *)&DAT_00d09c78,local_100);

  return;

}
