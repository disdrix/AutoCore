// =============================================================================
// Named_CalleeOf_Named_ecc_sys_00778910
// -----------------------------------------------------------------------------
// Stable ID: aa_00778910
// Callee of Named_ecc_sys
// Address:   0x00778910  (autoassault.exe, image base 0x400000)
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
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_00778910, fprintf, raise.
//  - Strings: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"; "key != NULL"; "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\pk\\ecc\\ecc.c".
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_ecc_sys_00778910(void)



{

  int iVar1;

  int in_EAX;

  int *piVar2;

  int iVar3;

  

  if (in_EAX == 0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "key != NULL",0x49f,"C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\pk\\ecc\\ecc.c"

           );

    raise(0x16);

  }

  iVar1 = *(int *)(in_EAX + 4);

  iVar3 = 0;

  piVar2 = &DAT_00a23878;

  do {

    piVar2 = piVar2 + 7;

    iVar3 = iVar3 + 1;

  } while (*piVar2 != 0);

  if ((-1 < iVar1) && (iVar1 < iVar3)) {

    return (&DAT_00a23878)[iVar1 * 7];

  }

  return 0x7fffffff;

}
