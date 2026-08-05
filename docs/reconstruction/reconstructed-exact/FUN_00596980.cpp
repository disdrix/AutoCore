// =============================================================================
// FUN_00596980
// -----------------------------------------------------------------------------
// Stable ID: aa_00596980
// Address:   0x00596980  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00596980 @ 0x00596980
// Stable ID: aa_00596980
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00596980.
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

void FUN_00596980(uint32_t /* width from decompiler */ *param_1,int param_2,uint32_t /* width from decompiler */ *param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  

  if (param_2 != 0) {

    puVar1 = param_1 + 5;

    do {

      if (param_1 != (uint32_t /* width from decompiler */ *)0x0) {

        *param_1 = *param_3;

        puVar1[-4] = param_3[1];

        puVar1[-3] = param_3[2];

        puVar1[-2] = param_3[3];

        puVar1[-1] = param_3[4];

        *puVar1 = param_3[5];

        puVar1[1] = param_3[6];

        puVar1[2] = param_3[7];

        puVar1[3] = param_3[8];

        puVar1[4] = param_3[9];

      }

      param_1 = param_1 + 10;

      puVar1 = puVar1 + 10;

      param_2 = param_2 + -1;

    } while (param_2 != 0);

  }

  return;

}
