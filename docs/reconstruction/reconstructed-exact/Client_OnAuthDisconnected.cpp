// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, goto×2.
//  - Notable callees: FUN_007fdfb0, FUN_008221e0, OutputDebugStringA.
//  - Strings: "OnDisconnected\n"; "Failed to login!  Please try again in a moment.".
//  - Return sites: 2.

// =============================================================================
// Client_OnAuthDisconnected
// -----------------------------------------------------------------------------
// Purpose:  Auth OnDisconnected path - surfaces login-failure toast/dialog.
//
// Address:  0x008221e0  (autoassault.exe, image base 0x400000)
// Stable:   aa_008221e0
// System:   auth
//
// String evidence: "OnDisconnected" / "Failed to login!"
//
// Exactness: Behavior-preserving rewrite of decompiler control flow (scaffold).
// Bit-for-bit vs retail EXE: DEFERRED.
// Source:    Prefer over FUN_008221e0.cpp; FUN_* left intact as raw scaffold twin.
// =============================================================================

/*
 * Behavioral notes:
 * - Renamed from FUN_008221e0 using string evidence: "OnDisconnected" / "Failed to login!"
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 */

void __fastcall Client_OnAuthDisconnected(int param_1)

{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  

  OutputDebugStringA("OnDisconnected\n");

  *(uint8_t *)(param_1 + 0x4a) = 0;

  if ((((DAT_00d1b77c == 0) || (DAT_00d1b780 == (int *)0x0)) || (*DAT_00d1b780 != DAT_00d1b77c)) ||

     ((*(int *)(DAT_00d1b77c + 0xa90) != 0 ||

      (piVar1 = *(int **)(DAT_00d1b77c + 0xa74), piVar1 == (int *)0x0)))) {

    return;

  }

  piVar2 = (int *)piVar1[0x164];

  if (piVar2 == (int *)0x0) {

LAB_008222bd:

    if (DAT_00d1b1e4 == '\0') goto LAB_008222cb;

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

    goto LAB_008222bd;

  }

  DAT_00d1b1e4 = '\0';

LAB_008222cb:

                    /* WARNING: Could not recover jumptable at 0x008222d2. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*piVar1 + 0x34c))();

  return;

}
