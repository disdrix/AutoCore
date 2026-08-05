// =============================================================================
// FUN_008c4310
// -----------------------------------------------------------------------------
// Stable ID: aa_008c4310
// Address:   0x008c4310  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008c4310 @ 0x008c4310
// Stable ID: aa_008c4310
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00792250, FUN_007fdcc0, FUN_00800e60, FUN_008c4310.
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

void __thiscall FUN_008c4310(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  

  cVar1 = (**(code **)(*param_1 + 0xd0))();

  FUN_00792250(param_2,0x3f000000);

  if ((char)param_2 == '\0') {

    if (cVar1 != '\0') {

      FUN_007fdcc0(&DAT_00d1a840);

    }

  }

  else if (cVar1 == '\0') {

    FUN_00800e60();

    return;

  }

  return;

}
