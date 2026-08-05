// =============================================================================
// FUN_00837710
// -----------------------------------------------------------------------------
// Stable ID: aa_00837710
// Address:   0x00837710  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00837710 @ 0x00837710
// Stable ID: aa_00837710
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×7, do×1, while×1, return×1.
//  - Notable callees: FUN_00835240, FUN_00836410, FUN_00837710.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00837710(char param_1)



{

  int iVar1;

  int iVar2;

  float *pfVar3;

  float *pfVar4;

  uint32_t /* width from decompiler */ unaff_EBX;

  int *piVar5;

  float fVar6;

  float fStack_18;

  

  pfVar3 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 +

                                         DAT_00d1b6d8) + 0x1a0))();

  piVar5 = *(int **)(DAT_00d1b644 + 0xe720);

  if (piVar5 != *(int **)(DAT_00d1b644 + 0xe724)) {

    do {

      iVar2 = *piVar5;

      if ((iVar2 != 0) &&

         (iVar1 = *(int *)(*(int *)(iVar2 + 4) + 4) + iVar2,

         *(int *)(*(int *)(*(int *)(iVar1 + 0xac) + 0x3c) + 0x4e0) == 1)) {

        if (param_1 == '\0') {

          FUN_00835240(0);

        }

        else if (DAT_00af9338 != '\0') {

          if (*(int *)(iVar2 + 8) == 0) {

            pfVar4 = (float *)(iVar1 + 0x84);

          }

          else {

            pfVar4 = (float *)(*(int *)(*(int *)(iVar2 + 8) + 0x3c) + 0xb0);

          }

          fVar6 = (*pfVar4 - *pfVar3) * (*pfVar4 - *pfVar3) +

                  (pfVar4[2] - pfVar3[2]) * (pfVar4[2] - pfVar3[2]) +

                  (pfVar4[1] - pfVar3[1]) * (pfVar4[1] - pfVar3[1]);

          if (fVar6 <= _DAT_00aaabb0) {

            if (DAT_00aaabac <= fVar6) {

              fStack_18 = g_flOne - (fVar6 - DAT_00aaabac) * _DAT_00aaaba8;

            }

            else {

              fStack_18 = g_flOne;

            }

            FUN_00836410(unaff_EBX,1,0,0,fStack_18);

          }

        }

      }

      piVar5 = piVar5 + 1;

    } while (piVar5 != *(int **)(DAT_00d1b644 + 0xe724));

  }

  return;

}
