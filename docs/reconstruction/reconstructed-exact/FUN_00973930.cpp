// =============================================================================
// FUN_00973930
// -----------------------------------------------------------------------------
// Stable ID: aa_00973930
// Address:   0x00973930  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00973930 @ 0x00973930
// Stable ID: aa_00973930
// Embedded strings (evidence for future rename):
//   - "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"
//   - "in != NULL"
//   - "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\hashes\\helper\\hash_memory.c"
//   - "out != NULL"
//   - "outlen != NULL"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×8, return×4.
//  - Notable callees: fprintf×3, raise×3, FUN_00973930, free, malloc.
//  - Strings: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"; "in != NULL"; "out != NULL"; "outlen != NULL".
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

int FUN_00973930(int param_1,uint32_t /* width from decompiler */ param_2,int param_3,uint *param_4)



{

  int iVar1;

  int in_EAX;

  void *_Memory;

  int iVar2;

  

  if (param_1 == 0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "in != NULL",0x20,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\hashes\\helper\\hash_memory.c");

    raise(0x16);

  }

  if (param_3 == 0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "out != NULL",0x21,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\hashes\\helper\\hash_memory.c");

    raise(0x16);

  }

  if (param_4 == (uint *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "outlen != NULL",0x22,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\hashes\\helper\\hash_memory.c");

    raise(0x16);

  }

  if (((in_EAX < 0) || (0x1f < in_EAX)) ||

     (iVar1 = in_EAX * 100, (&DAT_00d183b0)[in_EAX * 0x19] == 0)) {

    return 0xb;

  }

  if (*param_4 < *(uint *)(&DAT_00d183b8 + iVar1)) {

    return 6;

  }

  _Memory = malloc(0x110);

  if (_Memory == (void *)0x0) {

    return 0xd;

  }

  iVar2 = (**(code **)(&DAT_00d18404 + iVar1))(_Memory);

  if (iVar2 == 0) {

    iVar2 = (**(code **)(&DAT_00d18408 + iVar1))(_Memory,param_1,param_2);

    if (iVar2 == 0) {

      iVar2 = (**(code **)(&DAT_00d1840c + iVar1))(_Memory,param_3);

      *param_4 = *(uint *)(&DAT_00d183b8 + iVar1);

    }

  }

  free(_Memory);

  return iVar2;

}
