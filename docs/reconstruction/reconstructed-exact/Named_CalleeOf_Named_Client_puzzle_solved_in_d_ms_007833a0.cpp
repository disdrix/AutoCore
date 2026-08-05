// =============================================================================
// Named_CalleeOf_Named_Client_puzzle_solved_in_d_ms_007833a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007833a0
// Callee of Named_Client_puzzle_solved_in_d_ms
// Address:   0x007833a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Client_puzzle_solved_in_d_ms: callee helper. Evidence string: "getRealMilliseconds". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "getRealMilliseconds"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×6, return×4.
//  - Notable callees: FUN_007803f0×2, swi×2, BitStream_readBits, BitStream_writeBits, FUN_00780060, FUN_007833a0, GetTickCount.
//  - Strings: "getRealMilliseconds".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_Client_puzzle_solved_in_d_ms
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



DWORD Named_CalleeOf_Named_Client_puzzle_solved_in_d_ms_007833a0(void)



{

  code *pcVar1;

  DWORD DVar2;

  DWORD local_4;

  

  if ((DAT_00d179e4 != 2) || (DAT_00d179e0 == '\0')) {

    DVar2 = GetTickCount();

    if ((DAT_00d179e4 == 1) && (DAT_00d179e0 != '\0')) {

      if ((_DAT_00d2066c & 2) == 0) {

        _DAT_00d2066c = _DAT_00d2066c | 2;

        _DAT_00d20654 = "getRealMilliseconds";

        _DAT_00d20658 = 0xffffffff;

        _DAT_00d2065c = DAT_00d17a00;

        DAT_00d17a00 = &DAT_00d20654;

      }

      FUN_007803f0(&DAT_00d20654);

      local_4 = DVar2;

      BitStream_writeBits(0x20,&local_4);

      FUN_00780060();

    }

    return DVar2;

  }

  if ((_DAT_00d2066c & 1) == 0) {

    _DAT_00d2066c = _DAT_00d2066c | 1;

    _DAT_00d20660 = "getRealMilliseconds";

    _DAT_00d20664 = 0xffffffff;

    _DAT_00d20668 = DAT_00d17a00;

    DAT_00d17a00 = &DAT_00d20660;

  }

  FUN_007803f0(&DAT_00d20660);

  DAT_00d179fc = DAT_00d179fc + 1;

  if ((DAT_00d179f8 != 0) && (DAT_00d179f8 <= DAT_00d179fc)) {

    pcVar1 = (code *)swi(3);

    DVar2 = (*pcVar1)();

    return DVar2;

  }

  BitStream_readBits(0x20,&local_4);

  if ((DAT_00afddd4 == '\0') && (DAT_00afddd0 < DAT_00d179e8)) {

    return local_4;

  }

  pcVar1 = (code *)swi(3);

  DVar2 = (*pcVar1)();

  return DVar2;

}
