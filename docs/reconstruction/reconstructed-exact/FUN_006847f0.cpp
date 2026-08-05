// =============================================================================
// FUN_006847f0
// -----------------------------------------------------------------------------
// Stable ID: aa_006847f0
// Address:   0x006847f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006847f0 @ 0x006847f0
// Stable ID: aa_006847f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_006847f0, gethostbyname, inet_addr, ntohl.
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

u_long FUN_006847f0(char *param_1)



{

  u_long uVar1;

  hostent *phVar2;

  

  uVar1 = inet_addr(param_1);

  if (uVar1 == 0xffffffff) {

    phVar2 = gethostbyname(param_1);

    if ((phVar2 == (hostent *)0x0) || (phVar2->h_addrtype != 2)) {

      return 0xffffffff;

    }

    uVar1 = *(u_long *)*phVar2->h_addr_list;

  }

  uVar1 = ntohl(uVar1);

  return uVar1;

}
