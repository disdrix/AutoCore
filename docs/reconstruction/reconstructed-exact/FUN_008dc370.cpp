// =============================================================================
// FUN_008dc370
// -----------------------------------------------------------------------------
// Stable ID: aa_008dc370
// Address:   0x008dc370  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008dc370 @ 0x008dc370
// Stable ID: aa_008dc370
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: FUN_008db1e0×2, FUN_008db370×2, FUN_008db6d0×2, FUN_008db890×2, FUN_007916e0, FUN_008db100, FUN_008db2d0, FUN_008db480.
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

void __thiscall FUN_008dc370(int param_1,uint32_t /* width from decompiler */ param_2)



{

  FUN_007916e0(param_2);

  if ((char)param_2 != '\0') {

    FUN_008db100();

    FUN_008db480();

    if (*(char *)(param_1 + 0x518) == '\0') {

      if (*(int *)(param_1 + 0x5a0) != 0) {

        (**(code **)(**(int **)(param_1 + 0x5a0) + 4))(0);

      }

      if (*(int *)(param_1 + 0x5a8) != 0) {

        (**(code **)(**(int **)(param_1 + 0x5a8) + 4))(0);

      }

      if (*(int *)(param_1 + 0x5ac) != 0) {

        (**(code **)(**(int **)(param_1 + 0x5ac) + 4))(0);

      }

      if (*(int *)(param_1 + 0x52c) != 0) {

        FUN_008db370(0);

        FUN_008db890();

        FUN_008db1e0();

        FUN_008db6d0();

        return;

      }

    }

    else {

      FUN_008db370(0);

    }

    FUN_008db2d0(0);

    FUN_008db890();

    FUN_008db1e0();

    FUN_008db6d0();

  }

  return;

}
