// =============================================================================
// FUN_0088d7d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0088d7d0
// Address:   0x0088d7d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0088d7d0 @ 0x0088d7d0
// Stable ID: aa_0088d7d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_005876c0, FUN_00792490, FUN_007fc360, FUN_007fea50, FUN_0088d7d0.
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

void __fastcall FUN_0088d7d0(int *param_1)



{

  char cVar1;

  uint32_t /* width from decompiler */ auStack_18 [2];

  int iStack_10;

  int iStack_c;

  int iStack_8;

  int iStack_4;

  

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar1 != '\0') {

    iStack_10 = param_1[0x152];

    iStack_c = param_1[0x153];

    iStack_8 = param_1[0x154];

    iStack_4 = param_1[0x155];

    auStack_18[0] = 0x202a;

    if (g_pSectorNetConnection_INFERRED != (void *)0x0) {

      (**(code **)(*(int *)g_pSectorNetConnection_INFERRED + 0x18))(0xffffffff,auStack_18,0x18,0);

    }

    if ((DAT_00d1b6d8 != 0) && (param_1[0x168] != 0)) {

      FUN_005876c0(*(uint32_t /* width from decompiler */ *)(DAT_00d1b644 + 0xe4e8));

    }

    (**(code **)(*param_1 + 0x3b8))(param_1[0x16c]);

    DAT_00d1d8f4 = 1;

    DAT_00d1d8f5 = 0;

    if (DAT_00d1d8dc != (int *)0x0) {

      (**(code **)(*DAT_00d1d8dc + 4))(0);

    }

  }

  (**(code **)(*param_1 + 0x3ac))();

  FUN_007fc360();

  FUN_00792490();

  FUN_007fea50();

  return;

}
