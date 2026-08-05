// =============================================================================
// FUN_007808b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007808b0
// Address:   0x007808b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007808b0 @ 0x007808b0
// Stable ID: aa_007808b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_007808b0.
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

void __fastcall FUN_007808b0(int param_1)



{

  int *piVar1;

  int iVar2;

  

  if (*(int *)(param_1 + 0x21c) != 0) {

    iVar2 = 0;

    do {

      if (*(int *)(iVar2 + *(int *)(param_1 + 0x21c)) != 0) {

        (**(code **)(**(int **)(iVar2 + *(int *)(param_1 + 0x21c)) + 0x10))(1);

        piVar1 = *(int **)(iVar2 + *(int *)(param_1 + 0x21c));

        if (piVar1 != (int *)0x0) {

          (**(code **)(*piVar1 + 4))(1);

        }

        *(uint32_t /* width from decompiler */ *)(iVar2 + *(int *)(param_1 + 0x21c)) = 0;

      }

      iVar2 = iVar2 + 4;

    } while (iVar2 < 0x1000);

  }

  return;

}
