// =============================================================================
// FUN_00769fd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00769fd0
// Address:   0x00769fd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00769fd0 @ 0x00769fd0
// Stable ID: aa_00769fd0
// Embedded strings (evidence for future rename):
//   - "CHNK"
//   - "header read in for stoChunkFileReader was invalid, expected \'CHNK\', got \'%s\' "
//   - "C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp"
//   - "Invalid mode in chunk file header"
//   - "Unimplemented code reached"
//   - "Invalid endian specifier in chunk file header"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×10, return×6, for×1.
//  - Notable callees: vog_LogMessage×6, stoChunkFileReader::ReadHeader×2, FUN_00435f30, FUN_00769fd0, FUN_0076cec0, strncmp.
//  - Strings: "CHNK"; "C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp"; "Invalid mode in chunk file header"; "Unimplemented code reached".
//  - Return sites: 6.

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

void FUN_00769fd0(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int unaff_EDI;

  char local_8 [4];

  char local_4;

  char local_3;

  

  iVar1 = FUN_00435f30(local_8,8);

  if (-1 < iVar1) {

    iVar1 = strncmp(local_8,"CHNK",4);

    if (iVar1 != 0) {

      if (-1 < *(int *)(unaff_EDI + 0x28)) {

        iVar1 = *(int *)(unaff_EDI + 0x1c);

        if ((iVar1 < 1) && (0 < *(int *)(unaff_EDI + 0x20) + iVar1)) {

          *(int *)(unaff_EDI + 0x18) = -iVar1;

        }

        else {

          *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x1c) = 0;

          *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x20) = 0;

          *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x18) = 0;

        }

      }

      uVar2 = FUN_0076cec0(local_8,

                           "header read in for stoChunkFileReader was invalid, expected \'CHNK\', got \'%s\' "

                           ,local_8);

      vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp",0x1a4,3,uVar2);

      return;

    }

    if (local_4 == 'B') {

      *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x4044) = 0;

    }

    else {

      if (local_4 != 'T') {

        vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp",0x1ae,3,

                       "Invalid mode in chunk file header");

        return;

      }

      *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x4044) = 1;

    }

    if (local_3 == 'B') {

      vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp",0x1bf,3,

                     "Unimplemented code reached");

    }

    else if (local_3 != 'L') {

      vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp",0x1b9,3,

                     "Invalid endian specifier in chunk file header");

      return;

    }

    *(uint8_t *)(unaff_EDI + 0x4048) = 1;

    return;

  }

  if (-1 < *(int *)(unaff_EDI + 0x28)) {

    iVar1 = *(int *)(unaff_EDI + 0x1c);

    if ((iVar1 < 1) && (0 < *(int *)(unaff_EDI + 0x20) + iVar1)) {

      *(int *)(unaff_EDI + 0x18) = -iVar1;

      vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp",0x19c,3,

                     "Unabled to read header in stoChunkFileReader::ReadHeader()");

      return;

    }

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x1c) = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x20) = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x18) = 0;

  }

  vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp",0x19c,3,

                 "Unabled to read header in stoChunkFileReader::ReadHeader()");

  return;

}
