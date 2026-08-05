// =============================================================================
// Named_CalleeOf_Named_netTcpConnection_0067bce0
// -----------------------------------------------------------------------------
// Stable ID: aa_0067bce0
// Callee of Named_netTcpConnection
// Address:   0x0067bce0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_netTcpConnection: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0067bce0, closesocket, ioctlsocket.
//  - Return sites: 1.

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

uint __fastcall Named_CalleeOf_Named_netTcpConnection_0067bce0(SOCKET *param_1)



{

  int iVar1;

  SOCKET *local_4;

  

  local_4 = param_1;

  iVar1 = ioctlsocket(*param_1,0x4004667f,(u_long *)&local_4);

  if (iVar1 == -1) {

    if (*param_1 != 0xffffffff) {

      closesocket(*param_1);

      *param_1 = 0xffffffff;

    }

    *param_1 = 0xffffffff;

  }

  return ~-(uint)(iVar1 != 0) & (uint)local_4;

}
