// =============================================================================
// FUN_005e7310
// -----------------------------------------------------------------------------
// Stable ID: aa_005e7310
// Address:   0x005e7310  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005e7310 @ 0x005e7310
// Stable ID: aa_005e7310
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00404d80, FUN_005e7310.
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

void __fastcall FUN_005e7310(int *param_1)



{

  int *piVar1;

  int iVar2;

  int *piStack_34;

  uint8_t *puStack_30;

  int *piStack_2c;

  code *pcStack_28;

  int aiStack_20 [2];

  uint8_t auStack_18 [4];

  uint8_t auStack_14 [20];

  

  if (*(char *)(param_1[0x4e] + 0x7d) != '\0') {

    pcStack_28 = (code *)0x5e732b;

    (**(code **)(*param_1 + 0x84))();

  }

  piVar1 = (int *)param_1[5];

  if ((*piVar1 != 0) && (piVar1[1] != 0)) {

    pcStack_28 = (code *)0x5e734a;

    iVar2 = (**(code **)(*(int *)*piVar1 + 0x20))();

    if (iVar2 == 0) {

      pcStack_28 = FUN_005edf20;

      piStack_2c = (int *)0x4;

      puStack_30 = (uint8_t *)0x8;

      piStack_34 = aiStack_20;

      FUN_00404d80();

      piStack_2c = aiStack_20;

      puStack_30 = auStack_18;

      piStack_34 = (int *)0x5e737a;

      pcStack_28 = (code *)param_1;

      (**(code **)(**(int **)param_1[5] + 0x34))();

      piStack_34 = param_1;

      (**(code **)(**(int **)(param_1[5] + 4) + 0x30))(auStack_14);

      aiStack_20[0] = param_1[0x52];

      (**(code **)(*param_1 + 0xc0))

                (&piStack_34,param_1 + 0x53,param_1[0x50],param_1[0x51],param_1[0x52],0,0);

    }

  }

  return;

}
