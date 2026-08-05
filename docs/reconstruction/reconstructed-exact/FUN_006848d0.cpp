// =============================================================================
// FUN_006848d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006848d0
// Address:   0x006848d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006848d0 @ 0x006848d0
// Stable ID: aa_006848d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×7, return×4.
//  - Notable callees: __WSAFDIsSet×2, FUN_006848d0, select.
//  - Return sites: 4.

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

uint FUN_006848d0(SOCKET param_1,int param_2,uint param_3)



{

  fd_set *writefds;

  int iVar1;

  fd_set *readfds;

  uint uVar2;

  timeval *timeout;

  bool bVar3;

  timeval local_210;

  fd_set local_208;

  fd_set local_104;

  

  if (param_1 == 0xffffffff) {

    return 0xfffffffc;

  }

  if (param_3 == 0) {

    return 0;

  }

  timeout = (timeval *)0x0;

  if (param_2 != -1) {

    local_210.tv_sec = param_2 / 1000;

    timeout = &local_210;

    local_210.tv_usec = (param_2 % 1000) * 1000;

  }

  readfds = (fd_set *)0x0;

  bVar3 = (param_3 & 1) != 0;

  if (bVar3) {

    local_208.fd_array[0] = param_1;

    readfds = &local_208;

  }

  local_208.fd_count = (u_int)bVar3;

  writefds = (fd_set *)0x0;

  bVar3 = (param_3 & 2) != 0;

  if (bVar3) {

    local_104.fd_array[0] = param_1;

    writefds = &local_104;

  }

  local_104.fd_count = (u_int)bVar3;

  iVar1 = select(param_1 + 1,readfds,writefds,(fd_set *)0x0,timeout);

  if (iVar1 == -1) {

    return 0xfffffffc;

  }

  iVar1 = __WSAFDIsSet(param_1,&local_208);

  uVar2 = (uint)(iVar1 != 0);

  iVar1 = __WSAFDIsSet(param_1,&local_104);

  if (iVar1 != 0) {

    uVar2 = uVar2 | 2;

  }

  return uVar2;

}
