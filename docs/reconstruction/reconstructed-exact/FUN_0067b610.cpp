// =============================================================================
// FUN_0067b610
// -----------------------------------------------------------------------------
// Stable ID: aa_0067b610
// Address:   0x0067b610  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0067b610 @ 0x0067b610
// Stable ID: aa_0067b610
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0067b610, WSAGetLastError, closesocket, recv.
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

FUN_0067b610(SOCKET *param_1,char *param_2,int param_3,int *param_4,char param_5)



{

  int iVar1;

  

  iVar1 = recv(*param_1,param_2,param_3,-(uint)(param_5 != '\0') & 2);

  if (iVar1 == -1) {

    *param_4 = 0;

    iVar1 = WSAGetLastError();

    if (iVar1 != 0x2733) {

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
