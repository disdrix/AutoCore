// =============================================================================
// FUN_0058c7a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0058c7a0
// Address:   0x0058c7a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0058c7a0 @ 0x0058c7a0
// Stable ID: aa_0058c7a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, while×3, do×1.
//  - Notable callees: FUN_0058c7a0.
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

void FUN_0058c7a0(int param_1,int param_2,int param_3,int param_4)



{

  char cVar1;

  int *piVar2;

  int *piVar3;

  int *piVar4;

  int *piVar5;

  

  piVar4 = (int *)**(int **)(param_2 + 4);

  if (piVar4 != *(int **)(param_2 + 4)) {

    piVar5 = (int *)(param_4 * 0x10 + param_1);

    do {

      *piVar5 = piVar4[6];

      piVar5[1] = piVar4[7];

      piVar5[2] = piVar4[8];

      param_4 = param_4 + 1;

      piVar5[3] = piVar4[9];

      if (param_4 == 99) {

        return;

      }

      if ((param_3 != 0) && (param_3 = param_3 + -1, param_3 < 1)) {

        return;

      }

      if (*(char *)((int)piVar4 + 0x29) == '\0') {

        piVar2 = (int *)piVar4[2];

        if (*(char *)((int)piVar2 + 0x29) == '\0') {

          cVar1 = *(char *)(*piVar2 + 0x29);

          piVar4 = piVar2;

          piVar2 = (int *)*piVar2;

          while (cVar1 == '\0') {

            cVar1 = *(char *)(*piVar2 + 0x29);

            piVar4 = piVar2;

            piVar2 = (int *)*piVar2;

          }

        }

        else {

          cVar1 = *(char *)(piVar4[1] + 0x29);

          piVar3 = (int *)piVar4[1];

          piVar2 = piVar4;

          while ((piVar4 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar4[2]))) {

            cVar1 = *(char *)(piVar4[1] + 0x29);

            piVar3 = (int *)piVar4[1];

            piVar2 = piVar4;

          }

        }

      }

      piVar5 = piVar5 + 4;

    } while (piVar4 != *(int **)(param_2 + 4));

  }

  return;

}
