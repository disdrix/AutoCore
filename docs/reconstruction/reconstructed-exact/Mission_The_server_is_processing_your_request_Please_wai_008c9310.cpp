// READABILITY (auto CF):
//  - Body size: ~142 non-empty decompiler lines.
//  - Control keywords: goto×12, if×11, switch×1, for×1, return×1.
//  - Notable callees: FUN_00794090×2, FUN_007fdfb0×2, FUN_008c9310.
//  - Strings: "The server is processing your request.  Please wait..."; "Failed to login!  Please try again in a moment."; "The server is currently unavailable. Please try again later.".
//  - Return sites: 1.

// =============================================================================
// Mission_The_server_is_processing_your_request_Please_wai_008c9310
// -----------------------------------------------------------------------------
// Stable ID: aa_008c9310
// Address:   0x008c9310  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "The server is processing your request.  Please wait..."
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Mission_The_server_is_processing_your_request_Please_wai_008c9310(void)



{

  int *piVar1;

  uint32_t /* width from decompiler */ in_EAX;

  int *piVar2;

  int *unaff_EDI;

  char *pcVar3;

  uint32_t /* width from decompiler */ uVar4;

  

  switch(in_EAX) {

  case 1:

    if (unaff_EDI[0x164] == 0) goto switchD_008c931e_default;

    FUN_00794090();

    FUN_00794090();

    (**(code **)(*(int *)unaff_EDI[0x159] + 0xd4))(0);

    (**(code **)(*(int *)unaff_EDI[0x15b] + 0xd4))(0);

    uVar4 = 0xffffffff;

    pcVar3 = "The server is processing your request.  Please wait...";

    break;

  case 2:

    piVar1 = (int *)unaff_EDI[0x164];

    if (piVar1 != (int *)0x0) {

      if (DAT_00d1b1e4 != '\0') goto LAB_008c9505;

      *(uint8_t *)((int)piVar1 + 0x489) = 0;

      piVar2 = (int *)(**(code **)(*piVar1 + 0x170))(3);

      piVar1[0x8b] = *piVar2;

      piVar1 = (int *)unaff_EDI[0x165];

      *(uint8_t *)((int)piVar1 + 0x489) = 0;

      piVar2 = (int *)(**(code **)(*piVar1 + 0x170))(3);

      piVar1[0x8b] = *piVar2;

      (**(code **)(*(int *)unaff_EDI[0x159] + 0xd4))(1);

      (**(code **)(*(int *)unaff_EDI[0x15b] + 0xd4))(1);

      uVar4 = 1;

LAB_008c94ea:

      FUN_007fdfb0(&DAT_00d1a840,"Failed to login!  Please try again in a moment.",uVar4,1,0);

    }

LAB_008c94f9:

    if (DAT_00d1b1e4 == '\0') goto switchD_008c931e_default;

    goto LAB_008c9505;

  case 3:

    piVar1 = (int *)unaff_EDI[0x164];

    if (piVar1 != (int *)0x0) {

      *(uint8_t *)((int)piVar1 + 0x489) = 0;

      piVar2 = (int *)(**(code **)(*piVar1 + 0x170))(3);

      piVar1[0x8b] = *piVar2;

      piVar1 = (int *)unaff_EDI[0x165];

      *(uint8_t *)((int)piVar1 + 0x489) = 0;

      piVar2 = (int *)(**(code **)(*piVar1 + 0x170))(3);

      piVar1[0x8b] = *piVar2;

      (**(code **)(*(int *)unaff_EDI[0x159] + 0xd4))(1);

      (**(code **)(*(int *)unaff_EDI[0x15b] + 0xd4))(0);

    }

    goto switchD_008c931e_default;

  case 4:

    piVar1 = (int *)unaff_EDI[0x164];

    if (piVar1 == (int *)0x0) goto switchD_008c931e_default;

    *(uint8_t *)((int)piVar1 + 0x489) = 0;

    piVar2 = (int *)(**(code **)(*piVar1 + 0x170))(3);

    piVar1[0x8b] = *piVar2;

    piVar1 = (int *)unaff_EDI[0x165];

    *(uint8_t *)((int)piVar1 + 0x489) = 0;

    piVar2 = (int *)(**(code **)(*piVar1 + 0x170))(3);

    piVar1[0x8b] = *piVar2;

    (**(code **)(*(int *)unaff_EDI[0x159] + 0xd4))(1);

    (**(code **)(*(int *)unaff_EDI[0x15b] + 0xd4))(1);

    uVar4 = 0x4e24;

    pcVar3 = "The username or password you entered was not found. Please check and try again.";

    break;

  case 5:

    piVar1 = (int *)unaff_EDI[0x164];

    if (piVar1 == (int *)0x0) goto switchD_008c931e_default;

    *(uint8_t *)((int)piVar1 + 0x489) = 0;

    piVar2 = (int *)(**(code **)(*piVar1 + 0x170))(3);

    piVar1[0x8b] = *piVar2;

    piVar1 = (int *)unaff_EDI[0x165];

    *(uint8_t *)((int)piVar1 + 0x489) = 0;

    piVar2 = (int *)(**(code **)(*piVar1 + 0x170))(3);

    piVar1[0x8b] = *piVar2;

    (**(code **)(*(int *)unaff_EDI[0x159] + 0xd4))(1);

    (**(code **)(*(int *)unaff_EDI[0x15b] + 0xd4))(1);

    uVar4 = 0x4e24;

    pcVar3 = 

    "The server is currently unavailable or this account is blocked. If your login attempt falls within the scheduled play times, please contact customer service for more information."

    ;

    break;

  case 6:

    piVar1 = (int *)unaff_EDI[0x164];

    if (piVar1 == (int *)0x0) goto switchD_008c931e_default;

    *(uint8_t *)((int)piVar1 + 0x489) = 0;

    piVar2 = (int *)(**(code **)(*piVar1 + 0x170))(3);

    piVar1[0x8b] = *piVar2;

    piVar1 = (int *)unaff_EDI[0x165];

    *(uint8_t *)((int)piVar1 + 0x489) = 0;

    piVar2 = (int *)(**(code **)(*piVar1 + 0x170))(3);

    piVar1[0x8b] = *piVar2;

    (**(code **)(*(int *)unaff_EDI[0x159] + 0xd4))(1);

    (**(code **)(*(int *)unaff_EDI[0x15b] + 0xd4))(1);

    uVar4 = 0x4e24;

    pcVar3 = "The server is currently unavailable. Please try again later.";

    break;

  case 7:

    piVar1 = (int *)unaff_EDI[0x164];

    if (piVar1 == (int *)0x0) goto switchD_008c931e_default;

    *(uint8_t *)((int)piVar1 + 0x489) = 0;

    piVar2 = (int *)(**(code **)(*piVar1 + 0x170))(3);

    piVar1[0x8b] = *piVar2;

    piVar1 = (int *)unaff_EDI[0x165];

    *(uint8_t *)((int)piVar1 + 0x489) = 0;

    piVar2 = (int *)(**(code **)(*piVar1 + 0x170))(3);

    piVar1[0x8b] = *piVar2;

    (**(code **)(*(int *)unaff_EDI[0x159] + 0xd4))(1);

    (**(code **)(*(int *)unaff_EDI[0x15b] + 0xd4))(1);

    uVar4 = 0x4e24;

    pcVar3 = "There is a problem with your account, please contact customer service.";

    break;

  case 8:

    piVar1 = (int *)unaff_EDI[0x164];

    if (piVar1 == (int *)0x0) goto LAB_008c94f9;

    if (DAT_00d1b1e4 == '\0') {

      *(uint8_t *)((int)piVar1 + 0x489) = 0;

      piVar2 = (int *)(**(code **)(*piVar1 + 0x170))(3);

      piVar1[0x8b] = *piVar2;

      piVar1 = (int *)unaff_EDI[0x165];

      *(uint8_t *)((int)piVar1 + 0x489) = 0;

      piVar2 = (int *)(**(code **)(*piVar1 + 0x170))(3);

      piVar1[0x8b] = *piVar2;

      (**(code **)(*(int *)unaff_EDI[0x159] + 0xd4))(1);

      (**(code **)(*(int *)unaff_EDI[0x15b] + 0xd4))(1);

      uVar4 = 0x4e24;

      goto LAB_008c94ea;

    }

LAB_008c9505:

    DAT_00d1b1e4 = '\0';

  default:

    goto switchD_008c931e_default;

  }

  FUN_007fdfb0(&DAT_00d1a840,pcVar3,uVar4,1,0);

switchD_008c931e_default:

                    /* WARNING: Could not recover jumptable at 0x008c9707. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*unaff_EDI + 0x34c))();

  return;

}
