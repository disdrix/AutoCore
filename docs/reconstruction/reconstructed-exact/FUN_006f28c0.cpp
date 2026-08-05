// =============================================================================
// FUN_006f28c0
// -----------------------------------------------------------------------------
// Stable ID: aa_006f28c0
// Address:   0x006f28c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f28c0 @ 0x006f28c0
// Stable ID: aa_006f28c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×12, return×9.
//  - Notable callees: FUN_006f28c0.
//  - Return sites: 9.

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

uint32_t /* width from decompiler */ FUN_006f28c0(float *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  

  if (*param_1 <= g_flMultiKillCountBlend) {

    if (param_1[1] <= g_flMultiKillCountBlend) {

      uVar1 = 2;

    }

    else {

      uVar1 = 1;

      if (g_flMultiKillCountBlend < param_1[2]) {

        return 3;

      }

      if (param_1[2] < DAT_00aaa6d4) {

        return 4;

      }

    }

  }

  else {

    uVar1 = 0;

    if (param_1[2] <= g_flMultiKillCountBlend) {

      if (DAT_00aaa6d4 <= param_1[2]) {

        if (g_flMultiKillCountBlend < param_1[1]) {

          return 7;

        }

        if (param_1[1] < DAT_00aaa6d4) {

          return 8;

        }

      }

      else {

        uVar1 = 6;

        if (g_flMultiKillCountBlend < param_1[1]) {

          return 10;

        }

        if (param_1[1] < DAT_00aaa6d4) {

          return 0xc;

        }

      }

    }

    else {

      uVar1 = 5;

      if (g_flMultiKillCountBlend < param_1[1]) {

        return 9;

      }

      if (param_1[1] < DAT_00aaa6d4) {

        return 0xb;

      }

    }

  }

  return uVar1;

}
