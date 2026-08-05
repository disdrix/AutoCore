// =============================================================================
// FUN_0067b860
// -----------------------------------------------------------------------------
// Stable ID: aa_0067b860
// Address:   0x0067b860  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0067b860 @ 0x0067b860
// Stable ID: aa_0067b860
// Embedded strings (evidence for future rename):
//   - "Send Socket Error: %d"
//   - "C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSocket.cpp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0067b860, FUN_0076cec0, WSAGetLastError, closesocket, sendto, vog_LogMessage.
//  - Strings: "Send Socket Error: %d".
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

int __thiscall FUN_0067b860(SOCKET *param_1,char *param_2,int param_3,sockaddr *param_4)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  iVar1 = sendto(*param_1,param_2,param_3,0,param_4,0x10);

  if (iVar1 == -1) {

    iVar1 = WSAGetLastError();

    uVar2 = FUN_0076cec0(&param_4,"Send Socket Error: %d",iVar1);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSocket.cpp",

                   0x1e4,2,uVar2);

    if (*param_1 != 0xffffffff) {

      closesocket(*param_1);

      *param_1 = 0xffffffff;

    }

    return -1;

  }

  return -(uint)(iVar1 != param_3);

}
