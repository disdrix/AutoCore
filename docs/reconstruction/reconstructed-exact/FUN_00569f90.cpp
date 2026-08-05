// =============================================================================
// FUN_00569f90
// -----------------------------------------------------------------------------
// Stable ID: aa_00569f90
// Address:   0x00569f90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00569f90 @ 0x00569f90
// Stable ID: aa_00569f90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00569f90, FUN_006a3db0, floor.
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

void __thiscall FUN_00569f90(int param_1,float param_2)



{

  short sVar1;

  

  floor((double)((float)(int)*(short *)(param_1 + 0xd4) * param_2));

  sVar1 = FUN_006a3db0();

  *(short *)(param_1 + 0xd4) = sVar1;

  if (sVar1 < 1) {

    *(uint16_t *)(param_1 + 0xd4) = 1;

  }

  return;

}
