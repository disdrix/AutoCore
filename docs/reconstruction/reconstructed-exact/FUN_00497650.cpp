// =============================================================================
// FUN_00497650
// -----------------------------------------------------------------------------
// Stable ID: aa_00497650
// Address:   0x00497650  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00497650 @ 0x00497650
// Stable ID: aa_00497650
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00497650, FUN_00787480.
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

uint8_t __thiscall FUN_00497650(int param_1,int param_2,int param_3)



{

  uint8_t uVar1;

  

  if ((((-1 < param_2) && (param_2 < *(int *)(param_1 + 4))) && (-1 < param_3)) &&

     (param_3 < *(int *)(param_1 + 8))) {

    uVar1 = FUN_00787480(param_2,(*(int *)(param_1 + 0xbc) - param_3) + -1);

    return uVar1;

  }

  return 0;

}
