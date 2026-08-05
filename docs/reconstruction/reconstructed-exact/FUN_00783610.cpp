// =============================================================================
// FUN_00783610
// -----------------------------------------------------------------------------
// Stable ID: aa_00783610
// Address:   0x00783610  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00783610 @ 0x00783610
// Stable ID: aa_00783610
// Embedded strings (evidence for future rename):
//   - "getHighPrecisionTimerValue"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×7, return×4.
//  - Notable callees: FUN_007803f0×2, swi×2, BitStream_readBits, BitStream_writeBits, FUN_00780060, FUN_00783610, GetTickCount, QueryPerformanceCounter.
//  - Strings: "getHighPrecisionTimerValue".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



DWORD FUN_00783610(void)



{

  code *pcVar1;

  DWORD DVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  LARGE_INTEGER local_8;

  

  if ((DAT_00d179e4 != 2) || (DAT_00d179e0 == '\0')) {

    if (DAT_00d1eaa0 == '\0') {

      uVar3 = GetTickCount();

      uVar4 = 0;

    }

    else {

      QueryPerformanceCounter(&local_8);

      uVar3 = local_8.s.LowPart;

      uVar4 = local_8.s.HighPart;

    }

    if ((DAT_00d179e4 == 1) && (DAT_00d179e0 != '\0')) {

      if ((_DAT_00d20830 & 2) == 0) {

        _DAT_00d20830 = _DAT_00d20830 | 2;

        _DAT_00d20818 = "getHighPrecisionTimerValue";

        _DAT_00d2081c = 0xffffffff;

        _DAT_00d20820 = DAT_00d17a00;

        DAT_00d17a00 = &DAT_00d20818;

      }

      FUN_007803f0(&DAT_00d20818);

      local_8.s.LowPart = uVar3;

      local_8.s.HighPart = uVar4;

      BitStream_writeBits(0x40,&local_8);

      FUN_00780060();

    }

    return uVar3;

  }

  if ((_DAT_00d20830 & 1) == 0) {

    _DAT_00d20830 = _DAT_00d20830 | 1;

    _DAT_00d20824 = "getHighPrecisionTimerValue";

    _DAT_00d20828 = 0xffffffff;

    _DAT_00d2082c = DAT_00d17a00;

    DAT_00d17a00 = &DAT_00d20824;

  }

  FUN_007803f0(&DAT_00d20824);

  DAT_00d179fc = DAT_00d179fc + 1;

  if ((DAT_00d179f8 != 0) && (DAT_00d179f8 <= DAT_00d179fc)) {

    pcVar1 = (code *)swi(3);

    DVar2 = (*pcVar1)();

    return DVar2;

  }

  BitStream_readBits(0x40,&local_8);

  if ((DAT_00afddd4 == '\0') && (DAT_00afddd0 < DAT_00d179e8)) {

    return local_8.s.LowPart;

  }

  pcVar1 = (code *)swi(3);

  DVar2 = (*pcVar1)();

  return DVar2;

}
