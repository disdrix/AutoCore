// =============================================================================
// FUN_0067b680
// -----------------------------------------------------------------------------
// Stable ID: aa_0067b680
// Address:   0x0067b680  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0067b680 @ 0x0067b680
// Stable ID: aa_0067b680
// Embedded strings (evidence for future rename):
//   - "Recv Socket Error: %d"
//   - "C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSocket.cpp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0067b680, FUN_0076cec0, WSAGetLastError, closesocket, recvfrom, vog_LogMessage.
//  - Strings: "Recv Socket Error: %d".
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ __thiscall

FUN_0067b680(SOCKET *param_1,char *param_2,int param_3,int *param_4,sockaddr *param_5,char param_6)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int local_4;

  

  local_4 = 0x10;

  iVar1 = recvfrom(*param_1,param_2,param_3,-(uint)(param_6 != '\0') & 2,param_5,&local_4);

  if (iVar1 == -1) {

    *param_4 = 0;

    iVar1 = WSAGetLastError();

    if (iVar1 != 0x2733) {

      uVar2 = FUN_0076cec0(&param_6,"Recv Socket Error: %d",iVar1);

      vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSocket.cpp"

                     ,0x14c,2,uVar2);

      if (*param_1 != 0xffffffff) {

        closesocket(*param_1);

        *param_1 = 0xffffffff;

      }

      return 0xffffffff;

    }

  }

  else {

    *param_4 = iVar1;

  }

  return 0;

}
