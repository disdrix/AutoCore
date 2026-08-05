// =============================================================================
// FUN_00787480
// -----------------------------------------------------------------------------
// Stable ID: aa_00787480
// Address:   0x00787480  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00787480 @ 0x00787480
// Stable ID: aa_00787480
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CONCAT31, FUN_00787480.
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

uint __thiscall FUN_00787480(uint *param_1,int param_2,int param_3)



{

  uint in_EAX;

  int iVar1;

  

  if ((((-1 < param_2) && (in_EAX = *param_1, param_2 < (int)in_EAX)) && (-1 < param_3)) &&

     (param_3 < (int)param_1[1])) {

    iVar1 = in_EAX * param_3 + param_1[2];

    return CONCAT31((int3)((uint)iVar1 >> 8),*(uint8_t *)(iVar1 + param_2));

  }

  return in_EAX & 0xffffff00;

}
