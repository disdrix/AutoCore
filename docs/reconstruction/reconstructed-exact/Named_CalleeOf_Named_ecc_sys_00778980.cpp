// =============================================================================
// Named_CalleeOf_Named_ecc_sys_00778980
// -----------------------------------------------------------------------------
// Stable ID: aa_00778980
// Callee of Named_ecc_sys
// Address:   0x00778980  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_ecc_sys: callee helper. Evidence string: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"
//   - "key != NULL"
//   - "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\pk\\ecc\\ecc.c"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00772250, FUN_00778980, fprintf, raise.
//  - Strings: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"; "key != NULL"; "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\pk\\ecc\\ecc.c".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_ecc_sys
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

void Named_CalleeOf_Named_ecc_sys_00778980(void)



{

  int in_EAX;

  

  if (in_EAX == 0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "key != NULL",0x37b,"C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\pk\\ecc\\ecc.c"

           );

    raise(0x16);

  }

  FUN_00772250(in_EAX + 8,in_EAX + 0x18,in_EAX + 0x28,in_EAX + 0x38,0);

  return;

}
