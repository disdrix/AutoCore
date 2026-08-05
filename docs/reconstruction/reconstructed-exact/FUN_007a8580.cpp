// =============================================================================
// FUN_007a8580
// -----------------------------------------------------------------------------
// Stable ID: aa_007a8580
// Address:   0x007a8580  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a8580 @ 0x007a8580
// Stable ID: aa_007a8580
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_007a8580.
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

void __fastcall FUN_007a8580(int *param_1)



{

  if (param_1[0xa6] != 0) {

    if ((uint32_t /* width from decompiler */ *)param_1[0xad] != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0xad])(0);

    }

    (**(code **)(*param_1 + 0x4c))();

    (**(code **)(*param_1 + 0x288))(&DAT_00a1419b);

    if ((char)param_1[0x2f] != '\0') {

      if ((uint32_t /* width from decompiler */ *)param_1[0xa6] != (uint32_t /* width from decompiler */ *)0x0) {

        (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0xa6])(1);

      }

      param_1[0xa6] = 0;

      *(uint8_t *)(param_1 + 0x2f) = 0;

    }

  }

  param_1[0xa6] = 0;

  return;

}
