// =============================================================================
// FUN_008bd4f0
// -----------------------------------------------------------------------------
// Stable ID: aa_008bd4f0
// Address:   0x008bd4f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008bd4f0 @ 0x008bd4f0
// Stable ID: aa_008bd4f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, return×1.
//  - Notable callees: FUN_00792490, FUN_008bd4f0.
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

void __fastcall FUN_008bd4f0(int *param_1)



{

  int iVar1;

  int *piVar2;

  uint uVar3;

  

  piVar2 = DAT_00d1d8dc;

  for (uVar3 = 0;

      (iVar1 = param_1[0x154], iVar1 != 0 && (uVar3 < (uint)(param_1[0x155] - iVar1 >> 2)));

      uVar3 = uVar3 + 1) {

    iVar1 = *(int *)(iVar1 + uVar3 * 4);

    if (((iVar1 == 0) || (piVar2 == (int *)0x0)) || (iVar1 == piVar2[0x146])) {

      DAT_00d1d8f4 = 1;

      DAT_00d1d8f5 = 0;

      if (piVar2 != (int *)0x0) {

        (**(code **)(*piVar2 + 4))(0);

        piVar2 = DAT_00d1d8dc;

      }

    }

  }

  param_1[0x144] = -1;

  param_1[0x145] = -1;

  (**(code **)(*param_1 + 0x3ac))();

  FUN_00792490();

  return;

}
