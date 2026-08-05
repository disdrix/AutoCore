// =============================================================================
// FUN_0066edb0
// -----------------------------------------------------------------------------
// Stable ID: aa_0066edb0
// Address:   0x0066edb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0066edb0 @ 0x0066edb0
// Stable ID: aa_0066edb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0066edb0.
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

uint32_t /* width from decompiler */ * __thiscall FUN_0066edb0(uint32_t /* width from decompiler */ *param_1,byte param_2)



{

  *param_1 = &PTR_FUN_009e7ba8;

  if ((uint32_t /* width from decompiler */ *)param_1[1] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[1])(1);

  }

  param_1[1] = 0;

  if ((param_2 & 1) != 0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(param_1);

  }

  return param_1;

}
