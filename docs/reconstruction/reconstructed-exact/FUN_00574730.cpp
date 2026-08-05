// =============================================================================
// FUN_00574730
// -----------------------------------------------------------------------------
// Stable ID: aa_00574730
// Address:   0x00574730  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00574730 @ 0x00574730
// Stable ID: aa_00574730
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CONCAT44, FUN_00574730.
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

uint64_t __thiscall FUN_00574730(int param_1,int param_2)



{

  if ((-1 < param_2) && (param_2 < 4)) {

    return CONCAT44(*(uint32_t /* width from decompiler */ *)(param_2 * 0x10 + 0x19c + param_1),

                    *(uint32_t /* width from decompiler */ *)(param_2 * 0x10 + 0x198 + param_1));

  }

  return 0xffffffffffffffff;

}
