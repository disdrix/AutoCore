// =============================================================================
// FUN_00712b90
// -----------------------------------------------------------------------------
// Stable ID: aa_00712b90
// Address:   0x00712b90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00712b90 @ 0x00712b90
// Stable ID: aa_00712b90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_00712b90, ftol.
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

short FUN_00712b90(float param_1,short param_2,uint32_t /* width from decompiler */ param_3,int param_4)



{

  short sVar1;

  short sVar2;

  

  if (0xfe < param_2) {

    param_2 = 0xff;

  }

  if (*(char *)(param_4 + 0x14) == '\x01') {

    *(uint16_t *)(param_4 + 0x10) = 0;

    if (*(char *)(param_4 + 0x15) == '\0') {

      if ((float)(int)param_2 <= param_1) {

        *(uint8_t *)(param_4 + 0x15) = 1;

        return 1;

      }

    }

  }

  else {

    *(short *)(param_4 + 0x10) = *(short *)(param_4 + 0x10) + 1;

    sVar1 = *(short *)(param_4 + 0x10);

    sVar2 = ftol();

    if ((sVar2 < sVar1) && (*(uint8_t *)(param_4 + 0x15) = 0, 0x7fbc < sVar1)) {

      *(uint16_t *)(param_4 + 0x10) = 0x7fbc;

    }

  }

  return (short)*(char *)(param_4 + 0x15);

}
