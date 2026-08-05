// =============================================================================
// FUN_00568640
// -----------------------------------------------------------------------------
// Stable ID: aa_00568640
// Address:   0x00568640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00568640 @ 0x00568640
// Stable ID: aa_00568640
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00568640, FUN_00569030.
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

int __fastcall FUN_00568640(int param_1)



{

  int *piVar1;

  int local_4;

  

  local_4 = param_1;

  piVar1 = (int *)FUN_00569030(&local_4,&stack0x00000004);

  if (*piVar1 != *(int *)(param_1 + 0x18)) {

    return *piVar1 + 0x10;

  }

  return 0;

}
