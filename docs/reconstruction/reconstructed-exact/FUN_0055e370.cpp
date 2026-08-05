// =============================================================================
// FUN_0055e370
// -----------------------------------------------------------------------------
// Stable ID: aa_0055e370
// Address:   0x0055e370  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0055e370 @ 0x0055e370
// Stable ID: aa_0055e370
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_0055e370.
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

void __thiscall FUN_0055e370(int param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  

  iVar1 = 0;

  if (0 < *(int *)(param_1 + 0x88)) {

    piVar2 = *(int **)(param_1 + 0x84);

    do {

      if (*piVar2 == param_2) {

        *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x84) + iVar1 * 4) = 0;

        return;

      }

      iVar1 = iVar1 + 1;

      piVar2 = piVar2 + 1;

    } while (iVar1 < *(int *)(param_1 + 0x88));

  }

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x84) + -4) = 0;

  return;

}
