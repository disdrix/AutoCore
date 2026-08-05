// =============================================================================
// FUN_0082cf50
// -----------------------------------------------------------------------------
// Stable ID: aa_0082cf50
// Address:   0x0082cf50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0082cf50 @ 0x0082cf50
// Stable ID: aa_0082cf50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00792600, FUN_0082cf50.
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

void __fastcall FUN_0082cf50(int *param_1)



{

  char cVar1;

  

  param_1[0x141] = param_1[0x149];

  param_1[0x140] = param_1[0x148];

  FUN_00792600();

  (**(code **)(*param_1 + 0x44c))();

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar1 != '\0') {

    (**(code **)(*param_1 + 0x460))(0xffffffff);

                    /* WARNING: Could not recover jumptable at 0x0082cf9b. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(*param_1 + 0x34c))();

    return;

  }

  return;

}
