// =============================================================================
// FUN_00602b00
// -----------------------------------------------------------------------------
// Stable ID: aa_00602b00
// Address:   0x00602b00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00602b00 @ 0x00602b00
// Stable ID: aa_00602b00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~91 non-empty decompiler lines.
//  - Control keywords: if×13, for×2, do×2, while×2, goto×2, return×1.
//  - Notable callees: FUN_00602760, FUN_00602b00.
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

void FUN_00602b00(uint32_t /* width from decompiler */ *param_1,int *param_2,int *param_3)



{

  int iVar1;

  int *piVar2;

  int *piVar3;

  int *piVar4;

  int *piVar5;

  int *piVar6;

  

  piVar4 = param_2 + (((int)param_3 - (int)param_2 >> 2) - ((int)param_3 - (int)param_2 >> 0x1f) >>

                     1);

  FUN_00602760(param_2,piVar4,param_3 + -1);

  piVar5 = piVar4 + 1;

  for (; param_2 < piVar4; piVar4 = piVar4 + -1) {

    if ((piVar4[-1] < *piVar4) || (*piVar4 < piVar4[-1])) break;

  }

  piVar6 = piVar5;

  piVar2 = piVar4;

  if (piVar5 < param_3) {

    do {

      piVar6 = piVar5;

      if ((*piVar5 < *piVar4) || (*piVar4 < *piVar5)) break;

      piVar5 = piVar5 + 1;

      piVar6 = piVar5;

    } while (piVar5 < param_3);

  }

joined_r0x00602b65:

  do {

    piVar3 = piVar4;

    if (param_3 <= piVar5) {

joined_r0x00602b8d:

      for (; param_2 < piVar4; piVar4 = piVar4 + -1) {

        piVar3 = piVar3 + -1;

        if (*piVar2 <= *piVar3) {

          if (*piVar2 < *piVar3) break;

          iVar1 = piVar2[-1];

          piVar2 = piVar2 + -1;

          *piVar2 = *piVar3;

          *piVar3 = iVar1;

        }

      }

      if (piVar4 == param_2) {

        if (piVar5 == param_3) {

          param_1[1] = piVar6;

          *param_1 = piVar2;

          return;

        }

        if (piVar6 != piVar5) {

          iVar1 = *piVar2;

          *piVar2 = *piVar6;

          *piVar6 = iVar1;

        }

        iVar1 = *piVar2;

        *piVar2 = *piVar5;

        *piVar5 = iVar1;

        piVar5 = piVar5 + 1;

        piVar6 = piVar6 + 1;

        piVar2 = piVar2 + 1;

      }

      else {

        piVar4 = piVar4 + -1;

        if (piVar5 == param_3) {

          piVar2 = piVar2 + -1;

          if (piVar4 != piVar2) {

            iVar1 = *piVar4;

            *piVar4 = *piVar2;

            *piVar2 = iVar1;

          }

          iVar1 = *piVar2;

          *piVar2 = piVar6[-1];

          piVar6[-1] = iVar1;

          piVar6 = piVar6 + -1;

        }

        else {

          iVar1 = *piVar5;

          *piVar5 = *piVar4;

          piVar5 = piVar5 + 1;

          *piVar4 = iVar1;

        }

      }

      goto joined_r0x00602b65;

    }

    if (*piVar5 <= *piVar2) {

      if (*piVar5 < *piVar2) goto joined_r0x00602b8d;

      iVar1 = *piVar6;

      *piVar6 = *piVar5;

      piVar6 = piVar6 + 1;

      *piVar5 = iVar1;

    }

    piVar5 = piVar5 + 1;

  } while( true );

}
