// =============================================================================
// FUN_004a8c40
// -----------------------------------------------------------------------------
// Stable ID: aa_004a8c40
// Address:   0x004a8c40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004a8c40 @ 0x004a8c40
// Stable ID: aa_004a8c40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_004a8c40.
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

uint32_t /* width from decompiler */ __thiscall FUN_004a8c40(int param_1,int param_2,int param_3)



{

  if ((((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x10))) && (-1 < param_3)) &&

     (param_3 < *(int *)(param_1 + 0x14))) {

    return *(uint32_t /* width from decompiler */ *)

            (*(int *)(param_1 + 0x3a4) + (*(int *)(param_1 + 0x14) * param_2 + param_3) * 4);

  }

  return 0;

}
