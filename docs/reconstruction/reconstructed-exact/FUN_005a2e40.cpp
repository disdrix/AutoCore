// =============================================================================
// FUN_005a2e40
// -----------------------------------------------------------------------------
// Stable ID: aa_005a2e40
// Address:   0x005a2e40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a2e40 @ 0x005a2e40
// Stable ID: aa_005a2e40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: while×3, if×2, return×1.
//  - Notable callees: FUN_005a2e40.
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

void FUN_005a2e40(int *param_1,int *param_2,int *param_3)



{

  char cVar1;

  int *piVar2;

  int *piVar3;

  

  while (param_1 != param_2) {

    *param_3 = *param_3 + 1;

    if (*(char *)((int)param_1 + 0x21) == '\0') {

      piVar2 = (int *)param_1[2];

      if (*(char *)((int)piVar2 + 0x21) == '\0') {

        cVar1 = *(char *)(*piVar2 + 0x21);

        param_1 = piVar2;

        piVar2 = (int *)*piVar2;

        while (cVar1 == '\0') {

          cVar1 = *(char *)(*piVar2 + 0x21);

          param_1 = piVar2;

          piVar2 = (int *)*piVar2;

        }

      }

      else {

        cVar1 = *(char *)(param_1[1] + 0x21);

        piVar3 = (int *)param_1[1];

        piVar2 = param_1;

        while ((param_1 = piVar3, cVar1 == '\0' && (piVar2 == (int *)param_1[2]))) {

          cVar1 = *(char *)(param_1[1] + 0x21);

          piVar3 = (int *)param_1[1];

          piVar2 = param_1;

        }

      }

    }

  }

  return;

}
