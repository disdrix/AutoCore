// =============================================================================
// FUN_0067bbb0
// -----------------------------------------------------------------------------
// Stable ID: aa_0067bbb0
// Address:   0x0067bbb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0067bbb0 @ 0x0067bbb0
// Stable ID: aa_0067bbb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×7, return×4.
//  - Notable callees: __WSAFDIsSet×2, FUN_0067bbb0, select.
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

uint __thiscall FUN_0067bbb0(SOCKET *param_1,int param_2,uint param_3)



{

  SOCKET SVar1;

  int iVar2;

  uint uVar3;

  int local_210;

  int local_20c;

  fd_set local_208;

  fd_set local_104;

  

  SVar1 = *param_1;

  if (SVar1 == 0xffffffff) {

    return 0xfffffffc;

  }

  if (param_3 == 0) {

    return 0;

  }

  if (param_2 != -1) {

    local_210 = param_2 / 1000;

    local_20c = (param_2 % 1000) * 1000;

  }

  uVar3 = param_3 & 1;

  if (uVar3 != 0) {

    local_208.fd_array[0] = SVar1;

  }

  local_208.fd_count = (u_int)(uVar3 != 0);

  param_3 = param_3 & 2;

  if (param_3 != 0) {

    local_104.fd_array[0] = SVar1;

  }

  local_104.fd_count = (u_int)(param_3 != 0);

  iVar2 = select(0,(fd_set *)(-(uint)(uVar3 != 0) & (uint)&local_208),

                 (fd_set *)(-(uint)(param_3 != 0) & (uint)&local_104),(fd_set *)0x0,

                 (timeval *)(-(uint)(param_2 != -1) & (uint)&local_210));

  if (iVar2 == -1) {

    return 0xfffffffc;

  }

  iVar2 = __WSAFDIsSet(*param_1,&local_208);

  uVar3 = (uint)(iVar2 != 0);

  iVar2 = __WSAFDIsSet(*param_1,&local_104);

  if (iVar2 != 0) {

    uVar3 = uVar3 | 2;

  }

  return uVar3;

}
