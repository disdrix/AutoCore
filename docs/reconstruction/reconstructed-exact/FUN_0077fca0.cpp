// =============================================================================
// FUN_0077fca0
// -----------------------------------------------------------------------------
// Stable ID: aa_0077fca0
// Address:   0x0077fca0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0077fca0 @ 0x0077fca0
// Stable ID: aa_0077fca0
// Embedded strings (evidence for future rename):
//   - "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"
//   - "md != NULL"
//   - "c:\\vog\\1_code\\torquenetworklibrary\\libtomcrypt\\hashes\\sha2\\sha224.c"
//   - "out != NULL"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, return×1.
//  - Notable callees: fprintf×2, raise×2, FUN_0077f960, FUN_0077fca0.
//  - Strings: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"; "md != NULL"; "out != NULL".
//  - Return sites: 1.

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

void FUN_0077fca0(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ local_20 [8];

  

  if (param_1 == 0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "md != NULL",0x43,

            "c:\\vog\\1_code\\torquenetworklibrary\\libtomcrypt\\hashes\\sha2\\sha224.c");

    raise(0x16);

  }

  if (param_2 == (uint32_t /* width from decompiler */ *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "out != NULL",0x44,

            "c:\\vog\\1_code\\torquenetworklibrary\\libtomcrypt\\hashes\\sha2\\sha224.c");

    raise(0x16);

  }

  FUN_0077f960(param_1,local_20);

  puVar2 = local_20;

  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {

    *param_2 = *puVar2;

    puVar2 = puVar2 + 1;

    param_2 = param_2 + 1;

  }

  return;

}
