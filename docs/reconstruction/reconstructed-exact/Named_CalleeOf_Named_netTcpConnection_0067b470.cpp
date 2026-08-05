// =============================================================================
// Named_CalleeOf_Named_netTcpConnection_0067b470
// -----------------------------------------------------------------------------
// Stable ID: aa_0067b470
// Callee of Named_netTcpConnection
// Address:   0x0067b470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_netTcpConnection: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: __WSAFDIsSet×2, FUN_0067b470, select.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_netTcpConnection
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

bool __thiscall Named_CalleeOf_Named_netTcpConnection_0067b470(SOCKET *param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  timeval local_210;

  fd_set local_208;

  fd_set local_104;

  

  *param_2 = 0;

  local_208.fd_array[0] = *param_1;

  local_210.tv_sec = 0;

  local_210.tv_usec = 0;

  local_104.fd_count = 1;

  local_208.fd_count = 1;

  local_104.fd_array[0] = local_208.fd_array[0];

  iVar1 = select(0,(fd_set *)0x0,&local_104,&local_208,&local_210);

  if (iVar1 == -1) {

    *param_2 = 1;

    return false;

  }

  iVar1 = __WSAFDIsSet(*param_1,&local_208);

  if (iVar1 != 0) {

    *param_2 = 1;

    return true;

  }

  iVar1 = __WSAFDIsSet(*param_1,&local_104);

  return iVar1 != 0;

}
