// READABILITY (auto CF):
//  - Body size: ~74 non-empty decompiler lines.
//  - Control keywords: if×13, return×6, goto×5.
//  - Notable callees: FUN_007fdfb0×2, FUN_007a4480, FUN_007fc360, FUN_0080c3c0, FUN_00912820, FUN_009133a0, FUN_0092f440, FUN_00937560.
//  - Strings: "Failed to login!  Please try again in a moment."; "Login failure. Remove this message when login finalized.".
//  - Return sites: 6.

// =============================================================================
// Client_ShowLoginFailureDialog
// -----------------------------------------------------------------------------
// Purpose:  Shows generic login-failure dialog after auth/sector login attempt fails.
//
// Address:  0x0080c3c0  (autoassault.exe, image base 0x400000)
// Stable:   aa_0080c3c0
// System:   auth
//
// String evidence: "Failed to login!  Please try again in a moment."
//
// Exactness: Behavior-preserving rewrite of decompiler control flow (scaffold).
// Bit-for-bit vs retail EXE: DEFERRED.
// Source:    Prefer over FUN_0080c3c0.cpp; FUN_* left intact as raw scaffold twin.
// =============================================================================

/*
 * Behavioral notes:
 * - Renamed from FUN_0080c3c0 using string evidence: "Failed to login!  Please try again in a moment."
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 */

void Client_ShowLoginFailureDialog(int param_1)

{

  int *piVar1;

  int *piVar2;

  int in_EAX;

  uint uVar3;

  int *piVar4;

  

  uVar3 = *(uint *)(in_EAX + 4) >> 0x18 & 0x7f;

  if (uVar3 != 0) {

    if (uVar3 != 1) {

      return;

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x140) = 0;

    FUN_007fc360();

    if (*(char *)(param_1 + 0xa6) != '\0') {

      if (DAT_00d1b77c == 0) goto LAB_0080c47b;

      _DAT_00d1b6a4 = 1;

      FUN_00912820();

    }

    FUN_009133a0(2);

LAB_0080c47b:

    FUN_0092f440();

    return;

  }

  if ((int)*(uint *)(in_EAX + 4) < 0) {

    if (*(int **)(param_1 + 0xf40) == (int *)0x0) {

      return;

    }

    if (**(int **)(param_1 + 0xf40) != *(int *)(param_1 + 0xf38)) {

      return;

    }

    FUN_00937560(param_1);

    return;

  }

  FUN_007fdfb0(param_1,"Failed to login!  Please try again in a moment.",0x9c47,1,0);

  if (DAT_00d1b77c == 0) {

    FUN_007a4480(1,"Login failure. Remove this message when login finalized.");

    goto LAB_0080c5a9;

  }

  piVar1 = *(int **)(DAT_00d1b77c + 0xa74);

  if (piVar1 == (int *)0x0) goto LAB_0080c5a9;

  piVar2 = (int *)piVar1[0x164];

  if (piVar2 == (int *)0x0) {

LAB_0080c580:

    if (DAT_00d1b1e4 != '\0') goto LAB_0080c588;

  }

  else {

    if (DAT_00d1b1e4 == '\0') {

      *(uint8_t *)((int)piVar2 + 0x489) = 0;

      piVar4 = (int *)(**(code **)(*piVar2 + 0x170))(3);

      piVar2[0x8b] = *piVar4;

      piVar2 = (int *)piVar1[0x165];

      *(uint8_t *)((int)piVar2 + 0x489) = 0;

      piVar4 = (int *)(**(code **)(*piVar2 + 0x170))(3);

      piVar2[0x8b] = *piVar4;

      (**(code **)(*(int *)piVar1[0x159] + 0xd4))(1);

      (**(code **)(*(int *)piVar1[0x15b] + 0xd4))(1);

      FUN_007fdfb0(&DAT_00d1a840,"Failed to login!  Please try again in a moment.",0x4e24,1,0);

      goto LAB_0080c580;

    }

LAB_0080c588:

    DAT_00d1b1e4 = '\0';

  }

  (**(code **)(*piVar1 + 0x34c))();

LAB_0080c5a9:

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0xc7c) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0xc7c))(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc7c) = 0;

  *(uint8_t *)(param_1 + 0x113) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x134) = 0;

  return;

}
