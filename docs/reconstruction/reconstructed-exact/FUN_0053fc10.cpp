// =============================================================================
// FUN_0053fc10
// -----------------------------------------------------------------------------
// Stable ID: aa_0053fc10
// Address:   0x0053fc10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0053fc10 @ 0x0053fc10
// Stable ID: aa_0053fc10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_0053fc10.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ __fastcall FUN_0053fc10(int param_1)



{

  bool bVar1;

  int iVar2;

  

  if ((*(int *)(param_1 + 8) != 0) &&

     (iVar2 = (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x3c) + 0x18))(), iVar2 == 6)) {

    return 0;

  }

  iVar2 = *(int *)(param_1 + 8);

  if (iVar2 != 0) {

    if ((*(char *)(iVar2 + 0x40) == '\0') || (*(int *)(iVar2 + 8) == 0)) {

      bVar1 = true;

    }

    else {

      bVar1 = false;

    }

    if (bVar1) {

      return 1;

    }

  }

  return 0;

}
