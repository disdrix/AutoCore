// =============================================================================
// FUN_0088f410
// -----------------------------------------------------------------------------
// Stable ID: aa_0088f410
// Address:   0x0088f410  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0088f410 @ 0x0088f410
// Stable ID: aa_0088f410
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×7, return×1.
//  - Notable callees: FUN_005876c0, FUN_00792490, FUN_007fbb70, FUN_007fc360, FUN_0085fd80, FUN_0088f410.
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

void __fastcall FUN_0088f410(int *param_1)



{

  char cVar1;

  uint32_t /* width from decompiler */ auStack_18 [2];

  int iStack_10;

  int iStack_c;

  int iStack_8;

  int iStack_4;

  

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar1 != '\0') {

    iStack_10 = param_1[0x14a];

    iStack_c = param_1[0x14b];

    iStack_8 = param_1[0x14c];

    iStack_4 = param_1[0x14d];

    auStack_18[0] = 0x202a;

    if (g_pSectorNetConnection_INFERRED != (void *)0x0) {

      (**(code **)(*(int *)g_pSectorNetConnection_INFERRED + 0x18))(0xffffffff,auStack_18,0x18,0);

    }

    if (param_1[0x16b] != 0) {

      FUN_0085fd80();

    }

    if (DAT_00d1b6d8 != 0) {

      if (param_1[0x162] != 0) {

        FUN_005876c0(*(uint32_t /* width from decompiler */ *)(DAT_00d1b644 + 0xe4e8));

      }

      FUN_007fbb70();

    }

    if (param_1[0x16b] != 0) {

      cVar1 = (**(code **)(*(int *)param_1[0x16b] + 0x3d8))();

      if (cVar1 != '\0') {

        (**(code **)(*(int *)param_1[0x16b] + 0x440))();

      }

    }

  }

  (**(code **)(*param_1 + 0x3ac))();

  FUN_007fc360();

  FUN_00792490();

  return;

}
