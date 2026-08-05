// =============================================================================
// FUN_007abf00
// -----------------------------------------------------------------------------
// Stable ID: aa_007abf00
// Address:   0x007abf00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007abf00 @ 0x007abf00
// Stable ID: aa_007abf00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_007abf00.
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

uint __fastcall FUN_007abf00(int *param_1)



{

  uint uVar1;

  

  *(uint8_t *)((int)param_1 + 0xd3) = 0;

  *(uint8_t *)(param_1 + 0x35) = 0;

  *(uint8_t *)((int)param_1 + 0xd5) = 0;

  (**(code **)(*param_1 + 0x330))(5);

  uVar1 = (**(code **)(*param_1 + 0xd8))();

  if (((char)uVar1 != '\0') && ((int *)param_1[0xac] != (int *)0x0)) {

                    /* WARNING: Could not recover jumptable at 0x007abf4f. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar1 = (**(code **)(*(int *)param_1[0xac] + 0x338))();

    return uVar1;

  }

  return uVar1 & 0xffffff00;

}
