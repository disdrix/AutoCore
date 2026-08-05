// =============================================================================
// FUN_00826660
// -----------------------------------------------------------------------------
// Stable ID: aa_00826660
// Address:   0x00826660  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00826660 @ 0x00826660
// Stable ID: aa_00826660
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_0078ff90×2, FUN_00826660.
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

void __thiscall FUN_00826660(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  uint32_t /* width from decompiler */ unaff_retaddr;

  

  *(uint8_t *)(param_1 + 0x4ff) = 0;

  if (*(int *)(param_1 + 0x548) == 1) {

    DAT_00d1d8f6 = 1;

    DAT_00d1d8f7 = 0;

    if (DAT_00d1d8e0 != (int *)0x0) {

      (**(code **)(*DAT_00d1d8e0 + 4))(0);

      DAT_00d1d8e0[0x145] = 0;

      *(uint8_t *)(DAT_00d1d8e0 + 0x13f) = 0;

      FUN_0078ff90(unaff_retaddr,param_2);

      return;

    }

  }

  else if (*(int *)(param_1 + 0x548) == 2) {

    DAT_00d1d8f4 = 1;

    DAT_00d1d8f5 = 0;

    if (DAT_00d1d8dc != (int *)0x0) {

      (**(code **)(*DAT_00d1d8dc + 4))(0);

    }

  }

  FUN_0078ff90(param_2,param_3);

  return;

}
