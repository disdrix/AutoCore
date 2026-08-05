// =============================================================================
// FUN_006c6c50
// -----------------------------------------------------------------------------
// Stable ID: aa_006c6c50
// Address:   0x006c6c50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c6c50 @ 0x006c6c50
// Stable ID: aa_006c6c50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_006c6c50.
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

void __thiscall FUN_006c6c50(int param_1,uint8_t *param_2,uint param_3,uint param_4)



{

  if ((((param_3 ^ param_4) & 0xffff0000) == 0) && ((param_3 & 0xffff0000) != 0)) {

    *param_2 = 0;

    return;

  }

  *param_2 = (*(uint *)(param_1 + 0x1c + (param_3 & 0x1f) * 4) & 1 << ((byte)param_4 & 0x1f)) != 0;

  return;

}
