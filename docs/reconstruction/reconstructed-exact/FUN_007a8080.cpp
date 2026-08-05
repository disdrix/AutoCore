// =============================================================================
// FUN_007a8080
// -----------------------------------------------------------------------------
// Stable ID: aa_007a8080
// Address:   0x007a8080  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a8080 @ 0x007a8080
// Stable ID: aa_007a8080
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_007a8080.
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

uint __fastcall FUN_007a8080(int *param_1)



{

  uint uVar1;

  

  *(uint8_t *)((int)param_1 + 0xd5) = 1;

  (**(code **)(*param_1 + 0x330))(3);

  uVar1 = (**(code **)(*param_1 + 0xd8))();

  if (((char)uVar1 != '\0') && ((int *)param_1[0xac] != (int *)0x0)) {

                    /* WARNING: Could not recover jumptable at 0x007a80c1. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar1 = (**(code **)(*(int *)param_1[0xac] + 0x338))();

    return uVar1;

  }

  return uVar1 & 0xffffff00;

}
