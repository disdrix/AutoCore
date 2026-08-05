// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×3, for×1, return×1.
//  - Notable callees: Client_RecvLoginCallback_3, FUN_0076cec0, FUN_007fdfb0, FUN_00944b20, OutputDebugStringA, code, vog_LogMessage.
//  - Strings: "RecvBlockedAccount\n"; "Blocked Account: code()"; "C:\\vog\\1_code\\vog_14_117_branch\\appClient\\NDAuthClient.cpp".
//  - Return sites: 1.

// =============================================================================
// Client_RecvLoginCallback_3
// -----------------------------------------------------------------------------
// Stable ID: aa_008227f0
// Address:   0x008227f0  (autoassault.exe, image base 0x400000)
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

void Client_RecvLoginCallback_3(uint32_t /* width from decompiler */ param_1)



{

  int *piVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ uVar3;

  int *piVar4;

  

  if (((DAT_00d1b77c != 0) && (DAT_00d1b780 != (int *)0x0)) && (*DAT_00d1b780 == DAT_00d1b77c)) {

    OutputDebugStringA("RecvBlockedAccount\n");

    uVar3 = FUN_0076cec0(&param_1,"Blocked Account: code()",param_1);

    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\appClient\\NDAuthClient.cpp",0xb8,3,uVar3);

    FUN_00944b20(1);

    piVar1 = *(int **)(DAT_00d1b77c + 0xa74);

    if (piVar1 != (int *)0x0) {

      piVar2 = (int *)piVar1[0x164];

      if (piVar2 != (int *)0x0) {

        *(uint8_t *)((int)piVar2 + 0x489) = 0;

        piVar4 = (int *)(**(code **)(*piVar2 + 0x170))(3);

        piVar2[0x8b] = *piVar4;

        piVar2 = (int *)piVar1[0x165];

        *(uint8_t *)((int)piVar2 + 0x489) = 0;

        piVar4 = (int *)(**(code **)(*piVar2 + 0x170))(3);

        piVar2[0x8b] = *piVar4;

        (**(code **)(*(int *)piVar1[0x159] + 0xd4))(1);

        (**(code **)(*(int *)piVar1[0x15b] + 0xd4))(1);

        FUN_007fdfb0(&DAT_00d1a840,

                     "The server is currently unavailable or this account is blocked. If your login attempt falls within the scheduled play times, please contact customer service for more information."

                     ,0x4e24,1,0);

      }

      (**(code **)(*piVar1 + 0x34c))();

    }

  }

  return;

}
