// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×6, return×4, goto×2.
//  - Notable callees: Client_RecvLoginCallback_7, FUN_007fdfb0, FUN_00944b20, OutputDebugStringA.
//  - Strings: "RecvPlayFail\n"; "Failed to login!  Please try again in a moment.".
//  - Return sites: 4.

// =============================================================================
// Client_RecvLoginCallback_7
// -----------------------------------------------------------------------------
// Stable ID: aa_008226f0
// Address:   0x008226f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

void Client_RecvLoginCallback_7(void)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  

  OutputDebugStringA("RecvPlayFail\n");

  if (DAT_00d1b780 == (int *)0x0) {

    return;

  }

  if (*DAT_00d1b780 != DAT_00d1b77c) {

    return;

  }

  FUN_00944b20(1);

  piVar1 = *(int **)(DAT_00d1b77c + 0xa74);

  if (piVar1 == (int *)0x0) {

    return;

  }

  piVar2 = (int *)piVar1[0x164];

  if (piVar2 == (int *)0x0) {

LAB_008227cf:

    if (DAT_00d1b1e4 == '\0') goto LAB_008227df;

  }

  else if (DAT_00d1b1e4 == '\0') {

    *(uint8_t *)((int)piVar2 + 0x489) = 0;

    piVar3 = (int *)(**(code **)(*piVar2 + 0x170))(3);

    piVar2[0x8b] = *piVar3;

    piVar2 = (int *)piVar1[0x165];

    *(uint8_t *)((int)piVar2 + 0x489) = 0;

    piVar3 = (int *)(**(code **)(*piVar2 + 0x170))(3);

    piVar2[0x8b] = *piVar3;

    (**(code **)(*(int *)piVar1[0x159] + 0xd4))(1);

    (**(code **)(*(int *)piVar1[0x15b] + 0xd4))(1);

    FUN_007fdfb0(&DAT_00d1a840,"Failed to login!  Please try again in a moment.",0x4e24,1,0);

    goto LAB_008227cf;

  }

  DAT_00d1b1e4 = '\0';

LAB_008227df:

  (**(code **)(*piVar1 + 0x34c))();

  return;

}
