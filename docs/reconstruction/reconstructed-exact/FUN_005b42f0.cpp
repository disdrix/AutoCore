// =============================================================================
// FUN_005b42f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005b42f0
// Address:   0x005b42f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b42f0 @ 0x005b42f0
// Stable ID: aa_005b42f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_005b42f0, FUN_005b45a0.
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

void __thiscall FUN_005b42f0(int param_1,int *param_2)



{

  int *piVar1;

  int unaff_EDI;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0;

  (**(code **)(*param_2 + 0x14))(&local_4,4);

  (**(code **)(*param_2 + 0x14))(param_1 + 0x20,0x10);

  if (unaff_EDI != 0) {

    FUN_005b45a0(unaff_EDI);

    piVar1 = (int *)**(int **)(param_1 + 0x14);

    if (piVar1 != *(int **)(param_1 + 0x14)) {

      do {

        (**(code **)(*param_2 + 0x14))(piVar1 + 8,0x10);

        piVar1 = (int *)*piVar1;

      } while (piVar1 != (int *)*(int *)(param_1 + 0x14));

    }

  }

  return;

}
