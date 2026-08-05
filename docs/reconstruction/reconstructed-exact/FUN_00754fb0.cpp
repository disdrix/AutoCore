// =============================================================================
// FUN_00754fb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00754fb0
// Address:   0x00754fb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00754fb0 @ 0x00754fb0
// Stable ID: aa_00754fb0
// Embedded strings (evidence for future rename):
//   - "Adding glyph page(%dx%d) %i for %s"
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxFontImpl.cpp"
//   - "Failed to create texture for glyph cache"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×4, for×2, return×1.
//  - Notable callees: vog_LogMessage×2, FUN_004367f0, FUN_00443750, FUN_00754fb0, FUN_0076cec0, FUN_0096f0e0, page.
//  - Strings: "Adding glyph page(%dx%d) %i for %s"; "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxFontImpl.cpp"; "Failed to create texture for glyph cache".
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

int FUN_00754fb0(void)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  int iVar3;

  int unaff_EDI;

  uint8_t local_4 [4];

  

  if (*(uint *)(unaff_EDI + 0x30) < 0x10) {

    iVar2 = unaff_EDI + 0x1c;

  }

  else {

    iVar2 = *(int *)(unaff_EDI + 0x1c);

  }

  iVar3 = 0;

  if (*(int *)(unaff_EDI + 0x94) != 0) {

    iVar3 = (*(int *)(unaff_EDI + 0x98) - *(int *)(unaff_EDI + 0x94)) / 0x14;

  }

  uVar1 = FUN_0076cec0(local_4,"Adding glyph page(%dx%d) %i for %s",

                       *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x38),*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x3c),iVar3,

                       iVar2);

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxFontImpl.cpp",0x1ce,1,uVar1);

  iVar2 = 0;

  if (*(int *)(unaff_EDI + 0x94) != 0) {

    iVar2 = (*(int *)(unaff_EDI + 0x98) - *(int *)(unaff_EDI + 0x94)) / 0x14;

  }

  FUN_00443750(iVar2 + 1);

  iVar2 = *(int *)(unaff_EDI + 0x98);

  iVar3 = FUN_0096f0e0(0x1a,unaff_EDI + 0x38,1,1,1,0);

  if (iVar3 < 0) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxFontImpl.cpp",0x1d6,3,

                   "Failed to create texture for glyph cache");

  }

  FUN_004367f0(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x40),0);

  return iVar2 + -0x14;

}
