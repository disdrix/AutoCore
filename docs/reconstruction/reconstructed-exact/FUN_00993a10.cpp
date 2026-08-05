// =============================================================================
// FUN_00993a10
// -----------------------------------------------------------------------------
// Stable ID: aa_00993a10
// Address:   0x00993a10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00993a10 @ 0x00993a10
// Stable ID: aa_00993a10
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxShadowVolume.cpp"
//   - "Failed removing Redundant verts"
//   - "Shadow contains no vertices"
//   - "Failure during Edge processing adding degen quads to shadow volume"
//   - "Shadow contains no faces"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×6, return×3.
//  - Notable callees: vog_LogMessage×3, FUN_00990c00, FUN_00991e60, FUN_00992e20, FUN_009935c0, FUN_00993a10.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxShadowVolume.cpp"; "Failed removing Redundant verts"; "Shadow contains no vertices"; "Shadow contains no faces".
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

int FUN_00993a10(uint32_t /* width from decompiler */ param_1,char param_2)



{

  int iVar1;

  int unaff_ESI;

  int unaff_EDI;

  uint32_t /* width from decompiler */ uVar2;

  char *pcVar3;

  

  if (param_2 == '\0') {

    iVar1 = FUN_00992e20();

  }

  else {

    iVar1 = FUN_009935c0();

  }

  if (iVar1 < 0) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxShadowVolume.cpp",0x3f7,3,

                   "Failed removing Redundant verts");

    return -1;

  }

  if ((*(int *)(unaff_EDI + 4) == 0) || (*(int *)(*(int *)(unaff_EDI + 4) + 0x18) < 3)) {

    pcVar3 = "Shadow contains no vertices";

    uVar2 = 0x3fb;

  }

  else {

    if ((*(int *)(unaff_ESI + 4) != 0) && (2 < *(int *)(*(int *)(unaff_ESI + 4) + 0x1c))) {

      if (param_2 == '\0') {

        iVar1 = FUN_00990c00();

      }

      else {

        iVar1 = FUN_00991e60();

      }

      if (iVar1 < 0) {

        vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxShadowVolume.cpp",0x408,3,

                       "Failure during Edge processing adding degen quads to shadow volume");

        iVar1 = -1;

      }

      return iVar1;

    }

    pcVar3 = "Shadow contains no faces";

    uVar2 = 0x401;

  }

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxShadowVolume.cpp",uVar2,1,pcVar3

                );

  return 1;

}
