// =============================================================================
// FUN_0099edb0
// -----------------------------------------------------------------------------
// Stable ID: aa_0099edb0
// Address:   0x0099edb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0099edb0 @ 0x0099edb0
// Stable ID: aa_0099edb0
// Embedded strings (evidence for future rename):
//   - "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"
//   - "N != NULL"
//   - "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\misc\\mpi\\is_prime.c"
//   - "result != NULL"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, for×1, do×1, while×1.
//  - Notable callees: fprintf×2, raise×2, FUN_00770330, FUN_007775d0, FUN_0099edb0.
//  - Strings: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"; "N != NULL"; "result != NULL".
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ FUN_0099edb0(int param_1)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  int *unaff_EBX;

  

  if (unaff_EBX == (int *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "N != NULL",0x18,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\misc\\mpi\\is_prime.c");

    raise(0x16);

  }

  if (param_1 == 0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "result != NULL",0x19,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\misc\\mpi\\is_prime.c");

    raise(0x16);

  }

  if (*unaff_EBX != 0) {

    for (uVar1 = *(uint *)(unaff_EBX[3] + -4 + *unaff_EBX * 4); uVar1 != 0; uVar1 = uVar1 >> 1) {

    }

  }

  FUN_00770330(param_1);

  iVar2 = FUN_007775d0();

  if (iVar2 != 0) {

    iVar3 = 0;

    do {

      if (iVar2 == (&DAT_00a240d0)[iVar3 * 2]) {

        return *(uint32_t /* width from decompiler */ *)(&UNK_00a240d4 + iVar3 * 8);

      }

      iVar3 = iVar3 + 1;

    } while (iVar3 < 3);

    return 1;

  }

  return 0;

}
