// =============================================================================
// FUN_00710fa0
// -----------------------------------------------------------------------------
// Stable ID: aa_00710fa0
// Address:   0x00710fa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00710fa0 @ 0x00710fa0
// Stable ID: aa_00710fa0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×4, if×3.
//  - Notable callees: FUN_00710fa0.
//  - Return sites: 4.

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

uint32_t /* width from decompiler */ FUN_00710fa0(int *param_1,uint16_t *param_2)



{

  if (param_2 == (uint16_t *)0x0) {

    return 0x181a;

  }

  if ((param_1 != (int *)0x0) && (*param_1 == 0xface)) {

    if ((char)param_1[3] != '\n') {

      return 0x17de;

    }

    *param_2 = *(uint16_t *)(*(int *)(param_1[4] + 0x4c) + 0x1c);

    return 0;

  }

  return 0x17d4;

}
