// =============================================================================
// FUN_0079d330
// -----------------------------------------------------------------------------
// Stable ID: aa_0079d330
// Address:   0x0079d330  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0079d330 @ 0x0079d330
// Stable ID: aa_0079d330
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_0079d330.
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

uint32_t /* width from decompiler */ __fastcall FUN_0079d330(int *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  

  if (*(char *)((int)param_1 + 5) != '\0') {

                    /* WARNING: Could not recover jumptable at 0x0079d338. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar1 = (**(code **)(*param_1 + 4))();

    return uVar1;

  }

  if (*(char *)((int)param_1 + 6) != '\0') {

                    /* WARNING: Could not recover jumptable at 0x0079d343. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar1 = (**(code **)(*param_1 + 8))();

    return uVar1;

  }

  return 0;

}
