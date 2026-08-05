// =============================================================================
// FUN_005cc560
// -----------------------------------------------------------------------------
// Stable ID: aa_005cc560
// Address:   0x005cc560  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005cc560 @ 0x005cc560
// Stable ID: aa_005cc560
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_005cc560.
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

void __fastcall FUN_005cc560(int param_1)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  

  piVar1 = *(int **)(param_1 + 0x18);

  if ((piVar1 != (int *)0x0) && (piVar1[0x29] != 0)) {

    iVar2 = piVar1[0x29];

    iVar3 = (**(code **)(*piVar1 + 0x214))();

    if (iVar3 != 0) {

      if (*(int *)(iVar3 + 0x250) == 0) {

        piVar1 = (int *)(iVar2 + 0x18);

        *piVar1 = *piVar1 + -1;

      }

      else {

        piVar1 = (int *)(iVar2 + 0x1c);

        *piVar1 = *piVar1 + -1;

      }

    }

  }

  return;

}
