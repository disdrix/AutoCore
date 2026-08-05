// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×2, for×2, return×1.
//  - Notable callees: FUN_00974320, fprintf, raise.
//  - Strings: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"; "out != NULL".
//  - Return sites: 1.

// =============================================================================
// Named_zeromem_00974320
// -----------------------------------------------------------------------------
// Stable ID: aa_00974320
// Address:   0x00974320  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "zeromem"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_zeromem_00974320(void)



{

  uint32_t /* width from decompiler */ *in_EAX;

  uint uVar1;

  uint unaff_ESI;

  

  if (in_EAX == (uint32_t /* width from decompiler */ *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "out != NULL",0x1a,"C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\misc\\zeromem.c"

           );

    raise(0x16);

  }

  if (unaff_ESI != 0) {

    for (uVar1 = unaff_ESI >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {

      *in_EAX = 0;

      in_EAX = in_EAX + 1;

    }

    for (uVar1 = unaff_ESI & 3; uVar1 != 0; uVar1 = uVar1 - 1) {

      *(uint8_t *)in_EAX = 0;

      in_EAX = (uint32_t /* width from decompiler */ *)((int)in_EAX + 1);

    }

  }

  return;

}
