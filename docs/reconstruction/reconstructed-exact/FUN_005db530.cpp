// =============================================================================
// FUN_005db530
// -----------------------------------------------------------------------------
// Stable ID: aa_005db530
// Address:   0x005db530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005db530 @ 0x005db530
// Stable ID: aa_005db530
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00518150×2, FUN_005db530.
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

void __thiscall FUN_005db530(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  int *piVar2;

  

  piVar2 = *(int **)(param_1 + -0x58);

  if (piVar2 != *(int **)(param_1 + -0x54)) {

    do {

      if ((*piVar2 != 0) && (piVar2[1] != 0)) {

        iVar1 = FUN_00518150(param_2,*piVar2);

        *piVar2 = iVar1;

        iVar1 = FUN_00518150(param_2,piVar2[1]);

        piVar2[1] = iVar1;

      }

      piVar2 = piVar2 + 3;

    } while (piVar2 != *(int **)(param_1 + -0x54));

  }

  return;

}
