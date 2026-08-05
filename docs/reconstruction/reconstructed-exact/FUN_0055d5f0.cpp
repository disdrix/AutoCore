// =============================================================================
// FUN_0055d5f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0055d5f0
// Address:   0x0055d5f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0055d5f0 @ 0x0055d5f0
// Stable ID: aa_0055d5f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_007567b0×2, FUN_0055d5f0.
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

void __thiscall FUN_0055d5f0(int param_1,char param_2)



{

  int *piVar1;

  

  if (*(char *)(param_1 + 0x20) != param_2) {

    piVar1 = *(int **)(DAT_00d1f058 + 0x2c);

    if (param_2 != '\0') {

      (**(code **)(**(int **)(param_1 + 0x10) + 0xc))(piVar1[0x28]);

      (**(code **)(*piVar1 + 0x10))();

      FUN_007567b0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xc),0);

      *(char *)(param_1 + 0x20) = param_2;

      return;

    }

    (**(code **)(*piVar1 + 0xc))(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x10) + 0xa0));

    (**(code **)(**(int **)(param_1 + 0x10) + 0x10))();

    FUN_007567b0(0,0);

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x10) + 0xc0) = 3;

    *(uint8_t *)(param_1 + 0x20) = 0;

  }

  return;

}
