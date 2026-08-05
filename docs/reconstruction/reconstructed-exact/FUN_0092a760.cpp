// =============================================================================
// FUN_0092a760
// -----------------------------------------------------------------------------
// Stable ID: aa_0092a760
// Address:   0x0092a760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0092a760 @ 0x0092a760
// Stable ID: aa_0092a760
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~88 non-empty decompiler lines.
//  - Control keywords: if×9, while×3, do×2, goto×2, return×1.
//  - Notable callees: FUN_004022a0×2, FUN_004294f0, FUN_005134e0, FUN_0092a760, LeaveCriticalSection.
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

uint8_t FUN_0092a760(float *param_1,uint32_t /* width from decompiler */ *param_2,float *param_3)



{

  int *piVar1;

  char cVar2;

  uint8_t uVar3;

  int iVar4;

  uint uVar5;

  int iVar6;

  int *unaff_EDI;

  float fVar7;

  uint8_t local_25;

  uint *local_24;

  int *local_20;

  uint32_t /* width from decompiler */ local_1c;

  int local_18;

  uint local_14;

  

  local_25 = 1;

  local_18 = 0;

  uVar3 = 1;

  if (0 < unaff_EDI[0x2b]) {

    local_24 = (uint *)(unaff_EDI + 0x36);

    do {

      local_14 = *local_24;

      if (local_14 == 0xffffffff) {

        local_25 = 0;

      }

      else {

        iVar6 = *(int *)(*(int *)(*unaff_EDI + 0xd34) + 0x18);

        iVar6 = *(int *)(*(int *)(*(int *)(iVar6 + 0x10) + (*(uint *)(iVar6 + 8) & local_14) * 4) +

                        4);

        if (iVar6 == 0) {

LAB_0092a7da:

          iVar6 = 0;

        }

        else {

          do {

            if (local_14 == *(uint *)(iVar6 + 0x10)) {

              if (iVar6 == 0) goto LAB_0092a7da;

              iVar6 = *(int *)(iVar6 + 8);

              goto LAB_0092a7e1;

            }

            iVar6 = *(int *)(iVar6 + 0xc);

          } while (iVar6 != 0);

          iVar6 = 0;

        }

LAB_0092a7e1:

        if (iVar6 != 0) {

          local_1c = 0;

          local_20 = (int *)0x0;

          FUN_004294f0();

          iVar4 = FUN_004022a0(&local_1c,&local_20);

          piVar1 = local_20;

          while (local_20 = piVar1, iVar4 == 0) {

            if ((((((piVar1 != (int *)0x0) &&

                   (uVar5 = (**(code **)(*piVar1 + 0x28c))(), uVar5 == local_24[-10])) &&

                  (cVar2 = FUN_005134e0(), cVar2 == '\0')) && (((uint)piVar1[0x5f] >> 3 & 1) == 0))

                && ((((local_14 != 0x12 || (iVar4 = (**(code **)(*piVar1 + 0x1d8))(), iVar4 == 0))

                     || (iVar4 = (**(code **)(*piVar1 + 0x1d8))(),

                        (*(uint *)(iVar4 + 0x210) & *(uint *)(iVar4 + 0x214)) == 0xffffffff)) &&

                    ((unaff_EDI[0x42] == -1 ||

                     (iVar4 = (**(code **)(*piVar1 + 0x27c))(), unaff_EDI[0x42] <= iVar4)))))) &&

               ((unaff_EDI[0x43] == -1 ||

                (iVar4 = (**(code **)(*piVar1 + 0x27c))(), iVar4 <= unaff_EDI[0x43])))) {

              (**(code **)(*piVar1 + 0x144))();

              fVar7 = ((float)piVar1[0x22] - param_1[2]) * ((float)piVar1[0x22] - param_1[2]) +

                      ((float)piVar1[0x20] - *param_1) * ((float)piVar1[0x20] - *param_1) +

                      ((float)piVar1[0x21] - param_1[1]) * ((float)piVar1[0x21] - param_1[1]);

              if (fVar7 < *param_3) {

                *param_3 = fVar7;

                *param_2 = piVar1;

              }

            }

            iVar4 = FUN_004022a0(&local_1c,&local_20);

            piVar1 = local_20;

          }

          if (*(char *)(iVar6 + 0x28) != '\0') {

            *(uint8_t *)(iVar6 + 0x28) = 0;

            LeaveCriticalSection((LPCRITICAL_SECTION)(iVar6 + 4));

          }

        }

      }

      local_24 = local_24 + 1;

      local_18 = local_18 + 1;

      uVar3 = local_25;

    } while (local_18 < unaff_EDI[0x2b]);

  }

  return uVar3;

}
