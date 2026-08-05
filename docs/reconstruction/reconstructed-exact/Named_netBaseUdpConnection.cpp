// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×7, return×4, while×2.
//  - Notable callees: FUN_0076cec0×3, vog_LogMessage×3, FUN_00685210, FUN_00685540, FUN_00685620, FUN_006856f0, flags, thunk_FUN_0076c4d0.
//  - Strings: "

                        );

    uVar3 = vog_LogMessage("; "Empty packet received."; "packet header unknown flags (%x) set".
//  - Return sites: 4.

// =============================================================================
// Named_netBaseUdpConnection
// -----------------------------------------------------------------------------
// Stable ID: aa_006856f0
// Address:   0x006856f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "netBaseUdpConnection"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint __thiscall Named_netBaseUdpConnection(int param_1,int param_2)



{

  bool bVar1;

  int iVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint8_t local_c [4];

  uint8_t local_8 [4];

  byte local_4;

  

  iVar2 = param_2;

  if (*(int *)(param_1 + 4) != 5) {

    uVar4 = FUN_0076cec0(&param_2,"trying to receive over a not-yet-connected or closing connection"

                        );

    uVar3 = vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netBaseUdpConnection.cpp"

                           ,0xff,2,uVar4);

    return uVar3 & 0xffffff00;

  }

  bVar1 = false;

  while( true ) {

    while( true ) {

      uVar3 = FUN_00685210(iVar2,local_8);

      if ((char)uVar3 != '\x01') {

        return uVar3;

      }

      if (local_4 != 0) break;

      if (*(int *)(iVar2 + 0xc) == 0) {

        uVar4 = FUN_0076cec0(&param_2,"Empty packet received.");

        vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netBaseUdpConnection.cpp"

                       ,0xd8,2,uVar4);

        bVar1 = true;

      }

      else if (!bVar1) {

        return uVar3;

      }

    }

    if ((local_4 & 8) != 0) break;

    if (local_4 == 6) {

      FUN_00685620();

      bVar1 = true;

    }

    else {

      uVar4 = FUN_0076cec0(local_c,"packet header unknown flags (%x) set",local_4);

      vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netBaseUdpConnection.cpp"

                     ,0xf4,2,uVar4);

      bVar1 = true;

    }

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 7;

  thunk_FUN_0076c4d0();

  uVar3 = FUN_00685540(0);

  return uVar3 & 0xffffff00;

}
