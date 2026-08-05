// =============================================================================
// FUN_008b2630
// -----------------------------------------------------------------------------
// Stable ID: aa_008b2630
// Address:   0x008b2630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008b2630 @ 0x008b2630
// Stable ID: aa_008b2630
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_00792490, FUN_008b2630, FUN_0097ae30.
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

void __fastcall FUN_008b2630(int *param_1)



{

  int *piVar1;

  

  piVar1 = (int *)param_1[0x146];

  if (piVar1 != (int *)0x0) {

    param_1[0x149] = piVar1[0x172];

    (**(code **)(*piVar1 + 0x440))();

    (**(code **)(*param_1 + 0xb0))(param_1[0x146]);

  }

  if ((int *)param_1[0x148] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0x148] + 0x440))();

    (**(code **)(*param_1 + 0xb0))(param_1[0x148]);

    if ((uint32_t /* width from decompiler */ *)param_1[0x148] != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x148])(1);

    }

    param_1[0x148] = 0;

  }

  if (param_1[0x14a] != 0) {

    FUN_0097ae30();

    (**(code **)(*(int *)param_1[0x14a] + 0xcc))(0);

    (**(code **)(*param_1 + 0xb0))(param_1[0x14a]);

  }

  (**(code **)(*param_1 + 0x3ac))();

  FUN_00792490();

  return;

}
