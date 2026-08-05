// =============================================================================
// FUN_00783d90
// -----------------------------------------------------------------------------
// Stable ID: aa_00783d90
// Address:   0x00783d90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00783d90 @ 0x00783d90
// Stable ID: aa_00783d90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00783d90, __WSAFDIsSet, select.
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

byte FUN_00783d90(void)



{

  int iVar1;

  SOCKET *unaff_ESI;

  timeval local_210;

  fd_set local_208;

  fd_set local_104;

  

  local_208.fd_array[0] = *unaff_ESI;

  local_104.fd_count = 1;

  local_208.fd_count = 1;

  local_210.tv_sec = 0;

  local_210.tv_usec = 0;

  local_104.fd_array[0] = local_208.fd_array[0];

  iVar1 = select(0,(fd_set *)0x0,&local_104,&local_208,&local_210);

  if (iVar1 != 0) {

    iVar1 = __WSAFDIsSet(*unaff_ESI,&local_208);

    return -(iVar1 != 0) & 3;

  }

  return 4;

}
