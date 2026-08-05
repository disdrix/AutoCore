// =============================================================================
// FUN_004c3f60
// -----------------------------------------------------------------------------
// Stable ID: aa_004c3f60
// Address:   0x004c3f60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c3f60 @ 0x004c3f60
// Stable ID: aa_004c3f60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_004c3f60.
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

void __thiscall FUN_004c3f60(int param_1,float param_2)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + -0x2b0);

  if (iVar1 != 0) {

                    /* WARNING: Could not recover jumptable at 0x004c3f76. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x29c))();

    return;

  }

  iVar1 = *(int *)(*(int *)(param_1 + -0x4fc) + 4);

  *(float *)(iVar1 + param_1 + -0x41c) = *(float *)(iVar1 + -0x41c + param_1) + param_2;

  return;

}
