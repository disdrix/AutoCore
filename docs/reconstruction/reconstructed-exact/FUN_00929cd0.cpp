// =============================================================================
// FUN_00929cd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00929cd0
// Address:   0x00929cd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00929cd0 @ 0x00929cd0
// Stable ID: aa_00929cd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×7, while×3, do×2, return×1.
//  - Notable callees: FUN_004bae00×2, CONCAT31, FUN_005134e0, FUN_00929cd0.
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

uint32_t /* width from decompiler */ FUN_00929cd0(int *param_1,float *param_2,uint32_t /* width from decompiler */ *param_3,float *param_4)



{

  char cVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  float fVar6;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  int local_14;

  

  local_14 = 0;

  do {

    iVar4 = local_14;

    local_18 = CONCAT31(local_18._1_3_,local_14 == 1);

    local_1c = 0;

    piVar2 = (int *)FUN_004bae00(local_18,&local_1c);

    while (piVar2 != (int *)0x0) {

      cVar1 = FUN_005134e0();

      if (((cVar1 == '\0') && (((uint)piVar2[0x5f] >> 3 & 1) == 0)) &&

         (cVar1 = (**(code **)(*piVar2 + 0x198))(), cVar1 == '\0')) {

        iVar4 = *(int *)(*(int *)(*param_1 + 0xe98) + 0x250);

        if (iVar4 != 0) {

          iVar4 = *(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4;

        }

        if ((piVar2[0x2b] != iVar4) && (iVar4 = 0, 0 < param_1[0x2b])) {

          piVar5 = param_1 + 0x2c;

          do {

            if ((0x7fffffff < (uint)piVar5[10]) &&

               (iVar3 = (**(code **)(*piVar2 + 0x28c))(), iVar3 == *piVar5)) {

              if ((((param_1[0x42] == -1) ||

                   (iVar4 = (**(code **)(*piVar2 + 0x27c))(), param_1[0x42] <= iVar4)) &&

                  ((param_1[0x43] == -1 ||

                   (iVar4 = (**(code **)(*piVar2 + 0x27c))(), iVar4 <= param_1[0x43])))) &&

                 ((iVar4 = (**(code **)(*piVar2 + 0x1d8))(), iVar4 == 0 ||

                  ((*(uint *)(iVar4 + 0x210) & *(uint *)(iVar4 + 0x214)) == 0xffffffff)))) {

                (**(code **)(*piVar2 + 0x144))();

                fVar6 = ((float)piVar2[0x22] - param_2[2]) * ((float)piVar2[0x22] - param_2[2]) +

                        ((float)piVar2[0x20] - *param_2) * ((float)piVar2[0x20] - *param_2) +

                        ((float)piVar2[0x21] - param_2[1]) * ((float)piVar2[0x21] - param_2[1]);

                if (fVar6 < *param_4) {

                  *param_4 = fVar6;

                  *param_3 = piVar2;

                }

              }

              break;

            }

            iVar4 = iVar4 + 1;

            piVar5 = piVar5 + 1;

          } while (iVar4 < param_1[0x2b]);

        }

      }

      piVar2 = (int *)FUN_004bae00(local_18,&local_1c);

      iVar4 = local_14;

    }

    local_14 = iVar4 + 1;

    if (1 < local_14) {

      return 1;

    }

  } while( true );

}
