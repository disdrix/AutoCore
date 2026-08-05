// =============================================================================
// FUN_00804330
// -----------------------------------------------------------------------------
// Stable ID: aa_00804330
// Address:   0x00804330  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00804330 @ 0x00804330
// Stable ID: aa_00804330
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00804330, GetTickCount.
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

void __fastcall FUN_00804330(int *param_1)



{

  DWORD DVar1;

  

  param_1[0x65] = 0;

  param_1[0x5c] = 0;

  DVar1 = GetTickCount();

  param_1[0x60] = DVar1;

  param_1[0x62] = -1;

  param_1[99] = 0;

  (**(code **)(*param_1 + 0x94))(0);

  (**(code **)(*param_1 + 0x3c))(0,0);

  return;

}
