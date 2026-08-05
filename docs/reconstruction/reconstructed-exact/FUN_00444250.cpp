// =============================================================================
// FUN_00444250
// -----------------------------------------------------------------------------
// Stable ID: aa_00444250
// Address:   0x00444250  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00444250 @ 0x00444250
// Stable ID: aa_00444250
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×4, for×1, return×1.
//  - Notable callees: FUN_00444250, FUN_004442c0.
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

void FUN_00444250(int *param_1,int *param_2)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int *in_EAX;

  

  for (; in_EAX != param_1; in_EAX = in_EAX + 5) {

    iVar2 = *param_2;

    if (iVar2 != 0) {

      *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + 1;

      if (*(int *)(iVar2 + 8) == 1) {

        (**(code **)(*(int *)(iVar2 + 4) + 4))();

      }

    }

    iVar3 = *in_EAX;

    if (iVar3 != 0) {

      piVar1 = (int *)(iVar3 + 8);

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*(int *)(iVar3 + 4) + 8))();

      }

    }

    *in_EAX = iVar2;

    FUN_004442c0();

  }

  return;

}
