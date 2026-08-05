// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00973a80, fprintf, raise.
//  - Strings: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"; "dst != NULL".
//  - Return sites: 1.

// =============================================================================
// Named_packet_store_header
// -----------------------------------------------------------------------------
// Stable ID: aa_00973a80
// Address:   0x00973a80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "packet_store_header"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_packet_store_header(uint8_t param_1,uint8_t param_2)



{

  uint8_t *unaff_ESI;

  

  if (unaff_ESI == (uint8_t *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "dst != NULL",0x11,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\pk\\packet_store_header.c");

    raise(0x16);

  }

  *unaff_ESI = 2;

  unaff_ESI[1] = 1;

  unaff_ESI[2] = param_1;

  unaff_ESI[3] = param_2;

  return;

}
