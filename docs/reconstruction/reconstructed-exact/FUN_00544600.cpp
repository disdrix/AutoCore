// =============================================================================
// FUN_00544600
// -----------------------------------------------------------------------------
// Stable ID: aa_00544600
// Address:   0x00544600  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00544600 @ 0x00544600
// Stable ID: aa_00544600
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_00544020, FUN_00544600.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ * __thiscall FUN_00544600(uint32_t /* width from decompiler */ *param_1,byte param_2)



{

  void *pvVar1;

  

  pvVar1 = (void *)param_1[2];

  *param_1 = &PTR_FUN_009d016c;

  if (pvVar1 != (void *)0x0) {

    FUN_00544020();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  param_1[2] = 0;

  if ((param_2 & 1) != 0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(param_1);

  }

  return param_1;

}
