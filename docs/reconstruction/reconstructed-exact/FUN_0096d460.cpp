// =============================================================================
// FUN_0096d460
// -----------------------------------------------------------------------------
// Stable ID: aa_0096d460
// Address:   0x0096d460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096d460 @ 0x0096d460
// Stable ID: aa_0096d460
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, while×1.
//  - Notable callees: FUN_0096d460.
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

uint32_t /* width from decompiler */ __thiscall FUN_0096d460(int param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  

  piVar2 = *(int **)(param_1 + 0x6c);

  while( true ) {

    if (piVar2 == *(int **)(param_1 + 0x70)) {

      return 0;

    }

    iVar1 = *(int *)(*piVar2 + 4);

    if (iVar1 == 0) {

      iVar1 = -1;

    }

    else {

      iVar1 = *(int *)(iVar1 + 8);

    }

    if (iVar1 == param_2) break;

    piVar2 = piVar2 + 1;

  }

  return *(uint32_t /* width from decompiler */ *)(*piVar2 + 8);

}
