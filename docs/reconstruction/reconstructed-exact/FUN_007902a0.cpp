// =============================================================================
// FUN_007902a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007902a0
// Address:   0x007902a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007902a0 @ 0x007902a0
// Stable ID: aa_007902a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_007902a0.
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

void __thiscall FUN_007902a0(int param_1,char param_2)



{

  if (param_2 == '\0') {

    if (*(char *)(param_1 + 0x493) != '\0') {

      *(uint8_t *)(param_1 + 0x493) = 0;

      if (*(int *)(param_1 + 0x4b8) != 0) {

        *(uint8_t *)(*(int *)(param_1 + 0x4b8) + 200) = 0;

        (**(code **)(**(int **)(param_1 + 0x4b8) + 0x370))(0,0);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x4b8) = 0;

      }

    }

  }

  else if (*(char *)(param_1 + 0x493) == '\0') {

    *(uint8_t *)(param_1 + 0x493) = 1;

    return;

  }

  return;

}
