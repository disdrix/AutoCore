// =============================================================================
// FUN_004351c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004351c0
// Address:   0x004351c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004351c0 @ 0x004351c0
// Stable ID: aa_004351c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_004351c0.
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

uint __fastcall FUN_004351c0(int *param_1)



{

  byte bVar1;

  char cVar2;

  

  cVar2 = (**(code **)(*param_1 + 0x20))();

  if (cVar2 != '\0') {

    return 0xffffffff;

  }

  bVar1 = *(byte *)(param_1[1] + param_1[4]);

  param_1[4] = param_1[4] + 1;

  return (uint)bVar1;

}
