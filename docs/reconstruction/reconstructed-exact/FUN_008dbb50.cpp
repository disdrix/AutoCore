// =============================================================================
// FUN_008dbb50
// -----------------------------------------------------------------------------
// Stable ID: aa_008dbb50
// Address:   0x008dbb50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008dbb50 @ 0x008dbb50
// Stable ID: aa_008dbb50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×7, return×1.
//  - Notable callees: FUN_008db370×3, FUN_008db2d0×2, FUN_008db1e0, FUN_008db6d0, FUN_008db890, FUN_008dbb50.
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

void __thiscall FUN_008dbb50(int *param_1,char param_2)



{

  int iVar1;

  int *piVar2;

  uint8_t local_8 [8];

  

  if (((char)param_1[0x146] == '\0') && (param_2 != '\0')) {

    piVar2 = (int *)(**(code **)(*param_1 + 0x120))(local_8,1,0);

    iVar1 = piVar2[1];

    param_1[0x147] = *piVar2;

    param_1[0x148] = iVar1;

  }

  *(char *)(param_1 + 0x146) = param_2;

  if (param_2 == '\0') {

    iVar1 = param_1[0x14b];

    if (iVar1 == 0) {

      FUN_008db370(1);

    }

    else {

      FUN_008db370(0);

    }

    FUN_008db2d0(iVar1 != 0);

    if ((int *)param_1[0x168] != (int *)0x0) {

      (**(code **)(*(int *)param_1[0x168] + 4))(0);

    }

    if ((int *)param_1[0x16a] != (int *)0x0) {

      (**(code **)(*(int *)param_1[0x16a] + 4))(0);

    }

    if ((int *)param_1[0x16b] != (int *)0x0) {

      (**(code **)(*(int *)param_1[0x16b] + 4))(0);

    }

    piVar2 = param_1 + 0x147;

  }

  else {

    FUN_008db370(0);

    FUN_008db2d0(0);

    if ((int *)param_1[0x168] != (int *)0x0) {

      (**(code **)(*(int *)param_1[0x168] + 4))(1);

    }

    piVar2 = param_1 + 0x149;

  }

  (**(code **)(*param_1 + 0x110))(piVar2);

  FUN_008db890();

  FUN_008db1e0();

  FUN_008db6d0();

  return;

}
