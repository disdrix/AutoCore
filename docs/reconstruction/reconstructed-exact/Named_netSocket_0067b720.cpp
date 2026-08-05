// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, while×1.
//  - Notable callees: FUN_0067b720, WSAGetLastError, recv, vog_LogMessage.
//  - Strings: ",

                   0x172,3,".
//  - Return sites: 2.

// =============================================================================
// Named_netSocket_0067b720
// -----------------------------------------------------------------------------
// Stable ID: aa_0067b720
// Address:   0x0067b720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "netSocket"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_netSocket_0067b720(SOCKET *param_1,char *param_2,int param_3)



{

  int iVar1;

  

  while( true ) {

    if (param_3 < 1) {

      return 0;

    }

    iVar1 = recv(*param_1,param_2,param_3,0);

    if (iVar1 < 1) break;

    param_3 = param_3 - iVar1;

    param_2 = param_2 + iVar1;

  }

  iVar1 = WSAGetLastError();

  if (iVar1 == 0x2733) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSocket.cpp",

                   0x172,3,"Attempted RecvExactly on non-blocking socket, bad!");

  }

  return 0xffffffff;

}
