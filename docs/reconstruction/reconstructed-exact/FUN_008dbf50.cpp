// =============================================================================
// FUN_008dbf50
// -----------------------------------------------------------------------------
// Stable ID: aa_008dbf50
// Address:   0x008dbf50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008dbf50 @ 0x008dbf50
// Stable ID: aa_008dbf50
// Embedded strings (evidence for future rename):
//   - "Human Advantages"
//   - "Defense Grid"
//   - "Controls"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×7, return×4, goto×2.
//  - Notable callees: FUN_008dbf50.
//  - Strings: "Human Advantages"; "Defense Grid"; "Controls".
//  - Return sites: 4.

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

void __thiscall FUN_008dbf50(int param_1,int param_2)



{

  int iVar1;

  char *pcVar2;

  

  if (*(int *)(param_1 + 0x57c) == 0) {

    return;

  }

  if (param_2 < 0) {

    return;

  }

  if (0x31 < param_2) {

    return;

  }

  if (param_2 == 0x30) {

    if (DAT_00d1b6d8 == 0) goto LAB_008dc00d;

    pcVar2 = "Human Advantages" +

             (uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xac +

                                              DAT_00d1b6d8) + 0x3c) + 0x532) * 0x1e;

  }

  else if (param_2 == 0x31) {

    if (DAT_00d1b6d8 == 0) goto LAB_008dc00d;

    iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xac + DAT_00d1b6d8) + 0x3c

                    );

    pcVar2 = "Defense Grid" +

             ((uint)*(byte *)(iVar1 + 0x531) + (uint)*(byte *)(iVar1 + 0x532) * 4) * 0x1e;

  }

  else {

    pcVar2 = "Controls" + param_2 * 0x1e;

  }

  (**(code **)(**(int **)(param_1 + 0x57c) + 0x1d8))(pcVar2,1,1);

LAB_008dc00d:

  (**(code **)(**(int **)(param_1 + 0x57c) + 0x34c))();

  return;

}
