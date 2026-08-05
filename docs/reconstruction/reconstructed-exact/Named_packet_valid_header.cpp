// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_009738d0, fprintf, raise.
//  - Strings: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"; "src != NULL".
//  - Return sites: 2.

// =============================================================================
// Named_packet_valid_header
// -----------------------------------------------------------------------------
// Stable ID: aa_009738d0
// Address:   0x009738d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "packet_valid_header"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_packet_valid_header(uint param_1,uint param_2)



{

  ushort *unaff_ESI;

  

  if (unaff_ESI == (ushort *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "src != NULL",0x13,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\pk\\packet_valid_header.c");

    raise(0x16);

  }

  if (((*unaff_ESI < 0x103) && (param_1 == (byte)unaff_ESI[1])) &&

     (param_2 == *(byte *)((int)unaff_ESI + 3))) {

    return 0;

  }

  return 7;

}
