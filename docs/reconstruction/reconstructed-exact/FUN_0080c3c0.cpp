// =============================================================================
// FUN_0080c3c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0080c3c0
// Address:   0x0080c3c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0080c3c0 @ 0x0080c3c0
// Stable ID: aa_0080c3c0
// Embedded strings (evidence for future rename):
//   - "Failed to login!  Please try again in a moment."
//   - "Login failure. Remove this message when login finalized."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~74 non-empty decompiler lines.
//  - Control keywords: if×13, return×6, goto×5.
//  - Notable callees: FUN_007fdfb0×2, FUN_007a4480, FUN_007fc360, FUN_0080c3c0, FUN_00912820, FUN_009133a0, FUN_0092f440, FUN_00937560.
//  - Strings: "Failed to login!  Please try again in a moment."; "Login failure. Remove this message when login finalized.".
//  - Return sites: 6.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0080c3c0(int param_1)



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
