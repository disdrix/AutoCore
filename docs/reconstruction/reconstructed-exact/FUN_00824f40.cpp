// =============================================================================
// FUN_00824f40
// -----------------------------------------------------------------------------
// Stable ID: aa_00824f40
// Address:   0x00824f40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00824f40 @ 0x00824f40
// Stable ID: aa_00824f40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00824f40.
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

void __thiscall FUN_00824f40(int param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  

  if (*(int *)(param_1 + 0x54c) != 0) {

    cVar1 = (**(code **)(**(int **)(param_1 + 0x54c) + 0x3b8))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(param_1 + 0x54c) + 0x3c8))(param_2,1);

      (**(code **)(**(int **)(param_1 + 0x54c) + 0x3b4))(param_2);

      (**(code **)(**(int **)(param_1 + 0x54c) + 0x34c))();

      return;

    }

    (**(code **)(**(int **)(param_1 + 0x54c) + 0x3b4))(param_2);

    (**(code **)(**(int **)(param_1 + 0x54c) + 0x3c8))(param_2,1);

    (**(code **)(**(int **)(param_1 + 0x54c) + 0x34c))();

  }

  return;

}
