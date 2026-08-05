// =============================================================================
// FUN_00873b30
// -----------------------------------------------------------------------------
// Stable ID: aa_00873b30
// Address:   0x00873b30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00873b30 @ 0x00873b30
// Stable ID: aa_00873b30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_008733b0×2, FUN_00873b30.
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

void __fastcall FUN_00873b30(int *param_1)



{

  int iVar1;

  char in_AL;

  uint32_t /* width from decompiler */ uVar2;

  int iStack_14;

  int iStack_10;

  

  if (in_AL != (char)param_1[0x146]) {

    *(char *)(param_1 + 0x146) = in_AL;

    if (in_AL != '\0') {

      iStack_10 = 0;

      iStack_14 = 0x873b57;

      FUN_008733b0();

      iStack_10 = 1;

      iStack_14 = 0x873b64;

      (**(code **)(*(int *)param_1[0x1b4] + 4))();

      iStack_14 = 1;

      (**(code **)(*(int *)param_1[0x1b5] + 4))();

      (**(code **)(*(int *)param_1[0x1b6] + 4))(1);

      param_1[0x13f] = 0;

      param_1[0x140] = 2;

      *(uint8_t *)((int)param_1 + 0xc5) = 1;

      if ((int *)param_1[0x1b4] != (int *)0x0) {

        iVar1 = *param_1;

        uVar2 = (**(code **)(*(int *)param_1[0x1b4] + 0x140))(&iStack_14,1);

        (**(code **)(iVar1 + 0x130))(uVar2);

      }

      iStack_14 = param_1[0x149] + param_1[0x147];

      iStack_10 = param_1[0x14a] + param_1[0x148];

      (**(code **)(*param_1 + 0x110))(&iStack_14);

      return;

    }

    iStack_10 = 1;

    iStack_14 = 0x873bfa;

    FUN_008733b0();

    iStack_10 = 0;

    iStack_14 = 0x873c07;

    (**(code **)(*(int *)param_1[0x1b4] + 4))();

    iStack_14 = 0;

    (**(code **)(*(int *)param_1[0x1b5] + 4))();

    (**(code **)(*(int *)param_1[0x1b6] + 4))(0);

    param_1[0x13f] = 0xf;

    param_1[0x140] = 1;

    (**(code **)(*param_1 + 0x114))(param_1 + 0x147);

    (**(code **)(*param_1 + 0x130))(param_1 + 0x14b);

    *(uint8_t *)((int)param_1 + 0xc5) = 0;

  }

  return;

}
