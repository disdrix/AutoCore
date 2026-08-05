// =============================================================================
// FUN_005d9060
// -----------------------------------------------------------------------------
// Stable ID: aa_005d9060
// Address:   0x005d9060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d9060 @ 0x005d9060
// Stable ID: aa_005d9060
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_004a2670, FUN_005d9060, FUN_0076c4a0.
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

void __fastcall FUN_005d9060(uint32_t /* width from decompiler */ *param_1)



{

  void *pvVar1;

  

  *param_1 = &PTR_FUN_009db450;

  FUN_0076c4a0();

  pvVar1 = (void *)param_1[1];

  if (pvVar1 != (void *)0x0) {

    FUN_004a2670();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  param_1[1] = 0;

  return;

}
