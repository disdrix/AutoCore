// =============================================================================
// FUN_004c4400
// -----------------------------------------------------------------------------
// Stable ID: aa_004c4400
// Address:   0x004c4400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c4400 @ 0x004c4400
// Stable ID: aa_004c4400
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: CONCAT31, FUN_004c4400.
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

uint __fastcall FUN_004c4400(int param_1)



{

  uint uVar1;

  

  if (*(char *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x4d8 + param_1) != '\0') {

    return CONCAT31((int3)((uint)*(int *)(param_1 + -0x4fc) >> 8),1);

  }

  uVar1 = *(uint *)(param_1 + -0x2b0);

  if ((uVar1 != 0) && (*(char *)(param_1 + -500) != '\0')) {

                    /* WARNING: Could not recover jumptable at 0x004c4435. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(uVar1 + 4) + 4) + 4 + uVar1) + 0x228))();

    return uVar1;

  }

  return uVar1 & 0xffffff00;

}
