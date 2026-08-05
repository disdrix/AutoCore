// =============================================================================
// FUN_00712910
// -----------------------------------------------------------------------------
// Stable ID: aa_00712910
// Address:   0x00712910  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00712910 @ 0x00712910
// Stable ID: aa_00712910
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, goto×1.
//  - Notable callees: FUN_00712910.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00712910(float param_1,float param_2,short param_3,int param_4)



{

  float fVar1;

  

  if (*(char *)(param_4 + 0x13) != '\0') {

    fVar1 = param_2 - _DAT_00a0f6fc;

    if (param_2 - _DAT_00a0f6fc < (float)(int)param_3 - _DAT_00a0f6f8) {

      fVar1 = (float)(int)param_3 - _DAT_00a0f6f8;

    }

    if (fVar1 <= param_1) {

      *(short *)(param_4 + 0xe) = *(short *)(param_4 + 0xe) + 1;

      if (1 < *(short *)(param_4 + 0xe)) {

        *(uint8_t *)(param_4 + 0x14) = 1;

        *(uint16_t *)(param_4 + 0xe) = 1;

        return;

      }

      goto LAB_00712979;

    }

  }

  *(uint16_t *)(param_4 + 0xe) = 0;

LAB_00712979:

  *(uint8_t *)(param_4 + 0x14) = 0;

  return;

}
