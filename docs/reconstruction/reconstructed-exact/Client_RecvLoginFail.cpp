// READABILITY (auto CF):
//  - Body size: ~88 non-empty decompiler lines.
//  - Control keywords: return×9, if×7, goto×2, switch×1.
//  - Notable callees: FUN_00912b00×2, Client_RecvLoginFail, FUN_00729940, FUN_0076c130, FUN_007fdfb0, FUN_008c9310, Sleep.
//  - Strings: "RecvLoginFail code:%d\n"; "The server is currently unavailable. Please try again later.".
//  - Return sites: 9.

// =============================================================================
// Client_RecvLoginFail
// -----------------------------------------------------------------------------
// Stable ID: aa_00821e30
// Address:   0x00821e30  (autoassault.exe, image base 0x400000)
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

void __thiscall Client_RecvLoginFail(int param_1,uint8_t param_2)



{

  int iVar1;

  int *piVar2;

  int *piVar3;

  int *piVar4;

  char *pcVar5;

  

  if (((DAT_00d1b77c == 0) || (DAT_00d1b780 == (int *)0x0)) || (*DAT_00d1b780 != DAT_00d1b77c)) {

    return;

  }

  FUN_0076c130("RecvLoginFail code:%d\n",param_2);

  switch(param_2) {

  case 1:

  case 6:

  case 8:

  case 0xf:

  case 0x14:

    piVar4 = *(int **)(DAT_00d1b77c + 0xa74);

    if (piVar4 == (int *)0x0) {

      return;

    }

    piVar2 = (int *)piVar4[0x164];

    if (piVar2 == (int *)0x0) goto LAB_00821f71;

    *(uint8_t *)((int)piVar2 + 0x489) = 0;

    piVar3 = (int *)(**(code **)(*piVar2 + 0x170))(3);

    piVar2[0x8b] = *piVar3;

    piVar2 = (int *)piVar4[0x165];

    *(uint8_t *)((int)piVar2 + 0x489) = 0;

    piVar3 = (int *)(**(code **)(*piVar2 + 0x170))(3);

    piVar2[0x8b] = *piVar3;

    (**(code **)(*(int *)piVar4[0x159] + 0xd4))(1);

    (**(code **)(*(int *)piVar4[0x15b] + 0xd4))(1);

    pcVar5 = "The server is currently unavailable. Please try again later.";

    break;

  case 2:

  case 3:

    FUN_00912b00();

    return;

  case 4:

  case 5:

  case 10:

  case 0xb:

  case 0xc:

  case 0x10:

  case 0x11:

  case 0x12:

    piVar4 = *(int **)(DAT_00d1b77c + 0xa74);

    if (piVar4 == (int *)0x0) {

      return;

    }

    piVar2 = (int *)piVar4[0x164];

    if (piVar2 == (int *)0x0) goto LAB_00821f71;

    *(uint8_t *)((int)piVar2 + 0x489) = 0;

    piVar3 = (int *)(**(code **)(*piVar2 + 0x170))(3);

    piVar2[0x8b] = *piVar3;

    piVar2 = (int *)piVar4[0x165];

    *(uint8_t *)((int)piVar2 + 0x489) = 0;

    piVar3 = (int *)(**(code **)(*piVar2 + 0x170))(3);

    piVar2[0x8b] = *piVar3;

    (**(code **)(*(int *)piVar4[0x159] + 0xd4))(1);

    (**(code **)(*(int *)piVar4[0x15b] + 0xd4))(1);

    pcVar5 = "There is a problem with your account, please contact customer service.";

    break;

  case 7:

  case 0xd:

  case 0xe:

    iVar1 = *(int *)(param_1 + 0x4c);

    *(int *)(param_1 + 0x4c) = iVar1 + -1;

    if (iVar1 < 1) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = 6;

      FUN_00912b00();

      return;

    }

    Sleep(0x5dc);

    FUN_00729940(param_1 + 8,param_1 + 0x29);

    return;

  default:

    if (*(int *)(DAT_00d1b77c + 0xa74) == 0) {

      return;

    }

    FUN_008c9310();

    return;

  }

  FUN_007fdfb0(&DAT_00d1a840,pcVar5,0x4e24,1,0);

LAB_00821f71:

  (**(code **)(*piVar4 + 0x34c))();

  return;

}
