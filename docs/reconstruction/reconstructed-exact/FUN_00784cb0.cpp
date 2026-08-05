// =============================================================================
// FUN_00784cb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00784cb0
// Address:   0x00784cb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00784cb0 @ 0x00784cb0
// Stable ID: aa_00784cb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_007843e0, FUN_00784cb0, WSAGetLastError, accept.
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

uint32_t /* width from decompiler */ __thiscall FUN_00784cb0(short *param_1,SOCKET *param_2)



{

  SOCKET *in_EAX;

  SOCKET SVar1;

  int local_14;

  sockaddr local_10;

  

  if (in_EAX[1] != 0) {

    local_14 = 0x10;

    SVar1 = accept(*in_EAX,&local_10,&local_14);

    if (SVar1 != 0xffffffff) {

      *param_2 = SVar1;

      FUN_007843e0();

      if (*param_1 == 0) {

        *param_1 = 1;

      }

      return 0;

    }

    WSAGetLastError();

  }

  return 4;

}
