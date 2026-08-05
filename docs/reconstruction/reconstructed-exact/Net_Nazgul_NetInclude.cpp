// =============================================================================
// Net_Nazgul_NetInclude
// -----------------------------------------------------------------------------
// Stable ID: aa_0046e2a0
// Address:   0x0046e2a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Domain alias Net_Nazgul_NetInclude for FUN_0046e2a0 @ 0x0046e2a0
// Stable ID: aa_0046e2a0
// Embedded strings (evidence for future rename):
//   - "c:\\vog\\1_code\\palantir\\platform\\library\\include\\nazgul\\net\\../../../src/nazgul/ne"
//   - "Unable to set socket non-blocking for non-blocking connect."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, for×1.
//  - Notable callees: Net_Nazgul_NetInclude, FUN_0067bac0, WSAGetLastError, connect, vog_LogMessage.
//  - Strings: "

                   ,0x118,2,".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "c:\vog\1_code\palantir\platform\library\include\nazgul\net\../../../src/nazgul/ne"
 * Domain alias of FUN_0046e2a0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Net_Nazgul_NetInclude(SOCKET *param_1,sockaddr *param_2,uint32_t /* width from decompiler */ *param_3)



{

  int iVar1;

  

  *param_3 = 0;

  iVar1 = FUN_0067bac0(1);

  if (iVar1 < 0) {

    vog_LogMessage("c:\\vog\\1_code\\palantir\\platform\\library\\include\\nazgul\\net\\../../../src/nazgul/net/netSocket.h"

                   ,0x118,2,"Unable to set socket non-blocking for non-blocking connect.");

  }

  iVar1 = connect(*param_1,param_2,0x10);

  if (iVar1 != 0) {

    iVar1 = WSAGetLastError();

    if ((iVar1 != 0x2733) && (iVar1 != 0x2734)) {

      return 0xffffffff;

    }

    *param_3 = 2;

  }

  return 0;

}
