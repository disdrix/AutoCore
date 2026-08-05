// =============================================================================
// FUN_0089fe70
// -----------------------------------------------------------------------------
// Stable ID: aa_0089fe70
// Address:   0x0089fe70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0089fe70 @ 0x0089fe70
// Stable ID: aa_0089fe70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_0089fe70, sprintf.
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

void __fastcall FUN_0089fe70(int param_1)



{

  int *piVar1;

  int iVar2;

  char acStack_c [12];

  

  piVar1 = (int *)(param_1 + 0x63c);

  iVar2 = 10;

  do {

    if (*piVar1 != 0) {

      (**(code **)(*(int *)*piVar1 + 0x444))();

    }

    piVar1 = piVar1 + 1;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  if (*(int *)(param_1 + 0x628) != 0) {

    if (*(int *)(param_1 + 0x50c) == 9) {

      iVar2 = 0;

    }

    else {

      iVar2 = *(int *)(param_1 + 0x50c) + 1;

    }

    sprintf(acStack_c,"%d",iVar2);

    (**(code **)(**(int **)(param_1 + 0x628) + 0x1d8))(acStack_c,1,1);

  }

  return;

}
