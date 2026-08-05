// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Received_Challenge_Response_007834d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007834d0
// Callee of Named_CalleeOf_Named_Received_Challenge_Response_8x
// Address:   0x007834d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Received_Challenge_Response_8x: callee helper. Evidence string: "getHighPrecisionMilliseconds". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "getHighPrecisionMilliseconds"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×7, return×3.
//  - Notable callees: FUN_007803f0×2, swi×2, BitStream_readBits, BitStream_writeBits, FUN_00780060, FUN_007834d0.
//  - Strings: "getHighPrecisionMilliseconds".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Received_Challenge_Response_8x
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



float10 Named_CalleeOf_Named_CalleeOf_Named_Received_Challenge_Response_007834d0(longlong param_1)



{

  code *pcVar1;

  float10 fVar2;

  double local_14;

  double local_c;

  

  if ((DAT_00d179e4 == 2) && (DAT_00d179e0 != '\0')) {

    if ((_DAT_00d20814 & 1) == 0) {

      _DAT_00d20814 = _DAT_00d20814 | 1;

      _DAT_00d20808 = "getHighPrecisionMilliseconds";

      _DAT_00d2080c = 0xffffffff;

      _DAT_00d20810 = DAT_00d17a00;

      DAT_00d17a00 = &DAT_00d20808;

    }

    FUN_007803f0(&DAT_00d20808);

    DAT_00d179fc = DAT_00d179fc + 1;

    if ((DAT_00d179f8 != 0) && (DAT_00d179f8 <= DAT_00d179fc)) {

      pcVar1 = (code *)swi(3);

      fVar2 = (float10)(*pcVar1)();

      return fVar2;

    }

    BitStream_readBits(0x40,&local_14);

    if ((DAT_00afddd4 != '\0') || (DAT_00d179e8 <= DAT_00afddd0)) {

      pcVar1 = (code *)swi(3);

      fVar2 = (float10)(*pcVar1)();

      return fVar2;

    }

  }

  else {

    local_14 = (double)param_1;

    if (DAT_00d1eaa0 != '\0') {

      local_14 = local_14 * _DAT_00d1ea98;

    }

    if ((DAT_00d179e4 == 1) && (DAT_00d179e0 != '\0')) {

      if ((_DAT_00d20814 & 2) == 0) {

        _DAT_00d20814 = _DAT_00d20814 | 2;

        _DAT_00d207fc = "getHighPrecisionMilliseconds";

        _DAT_00d20800 = 0xffffffff;

        _DAT_00d20804 = DAT_00d17a00;

        DAT_00d17a00 = &DAT_00d207fc;

      }

      FUN_007803f0(&DAT_00d207fc);

      local_c = local_14;

      BitStream_writeBits(0x40,&local_c);

      FUN_00780060();

    }

  }

  return (float10)local_14;

}
