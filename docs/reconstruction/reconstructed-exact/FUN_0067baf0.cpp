// =============================================================================
// FUN_0067baf0
// -----------------------------------------------------------------------------
// Stable ID: aa_0067baf0
// Address:   0x0067baf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0067baf0 @ 0x0067baf0
// Stable ID: aa_0067baf0
// Embedded strings (evidence for future rename):
//   - "WSAIoctl(SIO_UDP_CONNRESET) error: %lu"
//   - "C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSocket.cpp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×3, for×1, return×1.
//  - Notable callees: WSAIoctl×2, FUN_0067baf0, FUN_0076cec0, GetVersionExA, WSAGetLastError, vog_LogMessage.
//  - Strings: "WSAIoctl(SIO_UDP_CONNRESET) error: %lu".
//  - Return sites: 1.

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

/* WARNING: Type propagation algorithm not settling */



void __thiscall FUN_0067baf0(uint32_t /* width from decompiler */ *param_1,char param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  _OSVERSIONINFOA *p_Var3;

  uint local_ac [2];

  uint8_t local_a4 [4];

  _OSVERSIONINFOA local_a0;

  

  p_Var3 = &local_a0;

  for (iVar2 = 0x25; iVar2 != 0; iVar2 = iVar2 + -1) {

    p_Var3->dwOSVersionInfoSize = 0;

    p_Var3 = (_OSVERSIONINFOA *)&p_Var3->dwMajorVersion;

  }

  local_a0.dwMinorVersion = 0;

  local_a0.dwOSVersionInfoSize = 0x94;

  local_a0.dwMajorVersion = 5;

  GetVersionExA(&local_a0);

  if ((5 < local_a0.dwMajorVersion) || (local_a0.dwMajorVersion == 5)) {

    local_ac[0] = (uint)(param_2 != '\0');

    local_ac[1] = 0;

    iVar2 = WSAIoctl(*param_1,0x9800000c,local_ac,4,0,0,local_ac + 1,0,0);

    if (iVar2 == -1) {

      iVar2 = WSAGetLastError();

      if (iVar2 != 0x2733) {

        uVar1 = FUN_0076cec0(local_a4,"WSAIoctl(SIO_UDP_CONNRESET) error: %lu",iVar2);

        vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSocket.cpp"

                       ,0x290,2,uVar1);

      }

    }

  }

  return;

}
