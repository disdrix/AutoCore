// =============================================================================
// FUN_00755890
// -----------------------------------------------------------------------------
// Stable ID: aa_00755890
// Address:   0x00755890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00755890 @ 0x00755890
// Stable ID: aa_00755890
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxFontImpl.cpp"
//   - "Out of range character passed to GetGlyphData. Returning dummy data."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_004434e0, FUN_00443930, FUN_00755100, FUN_00755890, _atexit, vog_LogMessage.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxFontImpl.cpp".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined * __thiscall FUN_00755890(int param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  undefined *puVar2;

  int unaff_EDI;

  

  uVar1 = param_2;

  if ((*(ushort *)(unaff_EDI + 0x88) <= (ushort)param_2) &&

     ((ushort)param_2 <= *(ushort *)(unaff_EDI + 0x8a))) {

    FUN_00443930();

    if (param_1 == *(int *)(unaff_EDI + 0x4c)) {

      FUN_004434e0(&param_2);

      puVar2 = (undefined *)FUN_00755100(uVar1);

      return puVar2;

    }

    return (undefined *)(param_1 + 0xc);

  }

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxFontImpl.cpp",0xed,3,

                 "Out of range character passed to GetGlyphData. Returning dummy data.");

  if ((_DAT_00d217ec & 1) == 0) {

    _DAT_00d217ec = _DAT_00d217ec | 1;

    _DAT_00d217c8 = 0;

    _atexit((_func_4879 *)&LAB_009c33b0);

  }

  _DAT_00d217c8 = 0;

  _DAT_00d217cc = 0;

  _DAT_00d217d0 = 0;

  _DAT_00d217d4 = 0;

  _DAT_00d217d8 = 0;

  _DAT_00d217dc = 0;

  _DAT_00d217e0 = 0;

  _DAT_00d217e4 = 0;

  _DAT_00d217e8 = 0;

  return &DAT_00d217c8;

}
