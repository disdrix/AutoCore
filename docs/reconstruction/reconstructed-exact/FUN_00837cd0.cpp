// =============================================================================
// FUN_00837cd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00837cd0
// Address:   0x00837cd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00837cd0 @ 0x00837cd0
// Stable ID: aa_00837cd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×11, return×1.
//  - Notable callees: FUN_00837cd0.
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

void __fastcall FUN_00837cd0(uint32_t /* width from decompiler */ param_1,int param_2)



{

  uint8_t *in_EAX;

  

  if (param_2 != 0) {

    if ((*(byte *)(param_2 + 0x624) & 1) != 0) {

      *in_EAX = 1;

    }

    if ((*(byte *)(param_2 + 0x624) & 2) != 0) {

      in_EAX[1] = 1;

    }

    if ((*(byte *)(param_2 + 0x624) & 8) != 0) {

      in_EAX[2] = 1;

    }

    if ((*(byte *)(param_2 + 0x624) & 0x10) != 0) {

      in_EAX[3] = 1;

    }

    if ((*(byte *)(param_2 + 0x625) & 1) != 0) {

      in_EAX[4] = 1;

    }

    if ((*(byte *)(param_2 + 0x625) & 2) != 0) {

      in_EAX[5] = 1;

    }

    if ((*(byte *)(param_2 + 0x625) & 0x10) != 0) {

      in_EAX[6] = 1;

    }

    if ((*(byte *)(param_2 + 0x625) & 0x20) != 0) {

      in_EAX[7] = 1;

    }

    if ((*(byte *)(param_2 + 0x625) & 0x40) != 0) {

      in_EAX[8] = 1;

    }

    if ((*(byte *)(param_2 + 0x625) & 0x80) != 0) {

      in_EAX[9] = 1;

    }

  }

  return;

}
