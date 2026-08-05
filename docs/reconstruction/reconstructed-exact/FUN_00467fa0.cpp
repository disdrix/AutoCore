// =============================================================================
// FUN_00467fa0
// -----------------------------------------------------------------------------
// Stable ID: aa_00467fa0
// Address:   0x00467fa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00467fa0 @ 0x00467fa0
// Stable ID: aa_00467fa0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×4, while×3, do×2, return×1.
//  - Notable callees: FUN_00468970×2, FUN_00467fa0.
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

void FUN_00467fa0(int *param_1,int *param_2,int param_3)



{

  float *pfVar1;

  float fVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  int *piVar6;

  int *piVar7;

  

  piVar5 = param_1;

  if (param_1 != param_2) {

    while (piVar5 = piVar5 + 1, piVar5 != param_2) {

      iVar3 = *param_1;

      iVar4 = *piVar5;

      fVar2 = *(float *)(iVar3 + param_3 * 4);

      pfVar1 = (float *)(iVar4 + param_3 * 4);

      if ((*pfVar1 <= fVar2 && fVar2 != *pfVar1) ||

         ((piVar6 = piVar5, *(float *)(iVar4 + param_3 * 4) == *(float *)(iVar3 + param_3 * 4) &&

          (fVar2 = *(float *)(iVar3 + 0xc + param_3 * 4),

          pfVar1 = (float *)(iVar4 + 0xc + param_3 * 4), *pfVar1 <= fVar2 && fVar2 != *pfVar1)))) {

        if ((param_1 != piVar5) && (piVar5 != piVar5 + 1)) {

          FUN_00468970(param_1,piVar5,piVar5 + 1);

        }

      }

      else {

        do {

          do {

            piVar7 = piVar6;

            iVar3 = piVar7[-1];

            fVar2 = *(float *)(iVar3 + param_3 * 4);

            pfVar1 = (float *)(iVar4 + param_3 * 4);

            piVar6 = piVar7 + -1;

          } while (*pfVar1 <= fVar2 && fVar2 != *pfVar1);

        } while ((*(float *)(iVar4 + param_3 * 4) == *(float *)(iVar3 + param_3 * 4)) &&

                (fVar2 = *(float *)(iVar3 + 0xc + param_3 * 4),

                pfVar1 = (float *)(iVar4 + 0xc + param_3 * 4), *pfVar1 <= fVar2 && fVar2 != *pfVar1)

                );

        if ((piVar7 != piVar5) && (piVar5 != piVar5 + 1)) {

          FUN_00468970(piVar7,piVar5,piVar5 + 1);

        }

      }

    }

  }

  return;

}
