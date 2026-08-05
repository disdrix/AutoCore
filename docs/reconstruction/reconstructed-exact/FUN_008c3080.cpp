// =============================================================================
// FUN_008c3080
// -----------------------------------------------------------------------------
// Stable ID: aa_008c3080
// Address:   0x008c3080  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008c3080 @ 0x008c3080
// Stable ID: aa_008c3080
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: Client_SendSectorPacket, FUN_00572ed0, FUN_00860700, FUN_008c3080.
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

uint32_t /* width from decompiler */ FUN_008c3080(void)



{

  char cVar1;

  int unaff_EDI;

  uint32_t /* width from decompiler */ local_8;

  uint8_t local_4;

  uint8_t local_3;

  uint8_t local_2;

  

  if (((DAT_00d1a8f6 == '\0') && (*(int *)(unaff_EDI + 0x580) != 0)) &&

     (*(int *)(*(int *)(unaff_EDI + 0x580) + 0x56c) != 0)) {

    cVar1 = FUN_00572ed0(*(uint8_t *)(unaff_EDI + 0x520));

    if (cVar1 != '\0') {

      *(undefined *)(*(int *)(unaff_EDI + 0x580) + 0x564) =

           (&DAT_00d17768)[*(int *)(unaff_EDI + 0x50c) * 4];

      FUN_00860700();

      local_2 = *(uint8_t *)(unaff_EDI + 0x520);

      local_4 = *(uint8_t *)(unaff_EDI + 0x50c);

      local_8 = 0x204a;

      local_3 = 1;

      Client_SendSectorPacket(&DAT_00d1a840,8,&local_8);

      return 1;

    }

  }

  return 0;

}
