// =============================================================================
// FUN_004ff630
// -----------------------------------------------------------------------------
// Stable ID: aa_004ff630
// Address:   0x004ff630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004ff630 @ 0x004ff630
// Stable ID: aa_004ff630
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CVOGReaction_FailMissionNotify, FUN_004a16d0, FUN_004eb3b0, FUN_004ff630.
//  - Return sites: 1.

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

void __fastcall FUN_004ff630(int param_1)



{

  int iVar1;

  int iStack_10;

  

  iStack_10 = 0x4ff649;

  FUN_004eb3b0();

  iStack_10 = -1;

  iVar1 = FUN_004a16d0(7,1);

  if (iVar1 != 0) {

    iStack_10 = param_1 + 0x32c;

    (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0xf8))(iVar1,0);

    CVOGReaction_FailMissionNotify(&iStack_10);

  }

  return;

}
