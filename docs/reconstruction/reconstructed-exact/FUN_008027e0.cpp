// =============================================================================
// FUN_008027e0
// -----------------------------------------------------------------------------
// Stable ID: aa_008027e0
// Address:   0x008027e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008027e0 @ 0x008027e0
// Stable ID: aa_008027e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×10, return×3, goto×1, while×1.
//  - Notable callees: FUN_004c3f10, FUN_007fca10, FUN_008027e0, FUN_0088b980.
//  - Return sites: 3.

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

void __fastcall FUN_008027e0(uint32_t /* width from decompiler */ param_1)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  

  if (DAT_00d1b778 == (int *)0x0) {

    return;

  }

  cVar2 = (**(code **)(*DAT_00d1b778 + 0x3d8))(param_1);

  if (cVar2 == '\0') {

    return;

  }

  if (DAT_00d1b6d8 == 0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_004c3f10(1);

    if (0 < iVar3) goto LAB_00802828;

  }

  FUN_007fca10();

LAB_00802828:

  piVar5 = DAT_00d1b778;

  if (DAT_00d1b938 != 0) {

    FUN_0088b980();

    piVar5 = DAT_00d1b778;

  }

  while( true ) {

    if (piVar5[0x328] == 0) {

      iVar4 = 0;

    }

    else {

      iVar4 = piVar5[0x329] - piVar5[0x328] >> 2;

    }

    if (iVar4 <= iVar3) break;

    piVar1 = *(int **)(piVar5[0x329] + -4);

    if ((piVar5[0x328] != 0) && (piVar5[0x329] - piVar5[0x328] >> 2 != 0)) {

      piVar5[0x329] = piVar5[0x329] + -4;

      piVar5 = DAT_00d1b778;

    }

    if (piVar1 != (int *)0x0) {

      cVar2 = (**(code **)(*piVar1 + 0x3d8))();

      if (cVar2 != '\0') {

        (**(code **)(*piVar1 + 0x440))();

      }

      (**(code **)(*DAT_00d1b778 + 0xb0))(piVar1);

      (**(code **)*piVar1)(1);

      piVar5 = DAT_00d1b778;

    }

  }

  return;

}
