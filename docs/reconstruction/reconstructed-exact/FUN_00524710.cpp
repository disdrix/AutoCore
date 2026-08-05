// =============================================================================
// FUN_00524710
// -----------------------------------------------------------------------------
// Stable ID: aa_00524710
// Address:   0x00524710  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00524710 @ 0x00524710
// Stable ID: aa_00524710
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_004eb3b0×2, FUN_004a16d0, FUN_004b7550, FUN_004b7e50, FUN_00523f50, FUN_00524710.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall FUN_00524710(int param_1)



{

  int iVar1;

  int iStack_1c;

  

  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + -0xd9c) + 4) + -0xcf4 + param_1);

  iStack_1c = 0x52472e;

  FUN_004eb3b0();

  if ((*(int *)(iVar1 + 0x88) != 0) && (*(int *)(param_1 + -0xd58) != 0)) {

    iStack_1c = 0x52475f;

    FUN_004eb3b0();

    iStack_1c = -1;

    iVar1 = FUN_004a16d0(0,1);

    if (iVar1 != 0) {

      iStack_1c = 0;

      (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xd9c) + 4) + -0xd9c + param_1) + 0xf8))

                (iVar1,1);

      FUN_004b7e50(0,0,0,0,0,0);

      FUN_00523f50(&iStack_1c,*(uint32_t /* width from decompiler */ *)(param_1 + -0x730));

      FUN_004b7550(&stack0xffffffe8,5);

    }

  }

  return;

}
