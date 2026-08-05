// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00973ad0, fprintf, raise.
//  - Strings: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"; "ctr != NULL".
//  - Return sites: 2.

// =============================================================================
// Named_ctr_done_00973ad0
// -----------------------------------------------------------------------------
// Stable ID: aa_00973ad0
// Address:   0x00973ad0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "ctr_done"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_ctr_done_00973ad0(void)



{

  int iVar1;

  int *in_EAX;

  

  if (in_EAX == (int *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "ctr != NULL",0x1b,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\modes\\ctr\\ctr_done.c");

    raise(0x16);

  }

  iVar1 = *in_EAX;

  if (((-1 < iVar1) && (iVar1 < 0x20)) && ((&DAT_00d17a30)[iVar1 * 0x13] != 0)) {

    (**(code **)(&DAT_00d17a58 + iVar1 * 0x4c))(in_EAX + 0x44);

    return 0;

  }

  return 10;

}
