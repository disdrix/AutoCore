// =============================================================================
// FUN_0092a980
// -----------------------------------------------------------------------------
// Stable ID: aa_0092a980
// Address:   0x0092a980  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0092a980 @ 0x0092a980
// Stable ID: aa_0092a980
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~96 non-empty decompiler lines.
//  - Control keywords: if×12, goto×4, while×4, do×3, return×1.
//  - Notable callees: FUN_004022a0×2, FUN_004294f0, FUN_005134e0, FUN_0092a980, LeaveCriticalSection.
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

uint32_t /* width from decompiler */ FUN_0092a980(float *param_1,uint32_t /* width from decompiler */ *param_2,float *param_3)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  int iVar4;

  int *unaff_EBX;

  float fVar5;

  uint *local_24;

  int *local_20;

  uint32_t /* width from decompiler */ local_1c;

  int local_18;

  uint local_14;

  

  local_18 = 0;

  if (0 < unaff_EBX[0x15]) {

    local_24 = (uint *)(unaff_EBX + 0x16);

    do {

      iVar3 = *(int *)(*(int *)(*unaff_EBX + 0xd30) + 0xf10);

      iVar3 = *(int *)(*(int *)(*(int *)(iVar3 + 0x10) + (*(uint *)(iVar3 + 8) & *local_24) * 4) + 4

                      );

      if (iVar3 == 0) {

LAB_0092a9db:

        iVar3 = 0;

      }

      else {

        do {

          if (*local_24 == *(uint *)(iVar3 + 0x10)) {

            if (iVar3 == 0) goto LAB_0092a9db;

            iVar3 = *(int *)(iVar3 + 8);

            goto LAB_0092a9e2;

          }

          iVar3 = *(int *)(iVar3 + 0xc);

        } while (iVar3 != 0);

        iVar3 = 0;

      }

LAB_0092a9e2:

      if (iVar3 != 0) {

        local_14 = *(uint *)(iVar3 + 0x38);

        iVar3 = *(int *)(*(int *)(*unaff_EBX + 0xd34) + 0x18);

        iVar3 = *(int *)(*(int *)(*(int *)(iVar3 + 0x10) + (*(uint *)(iVar3 + 8) & local_14) * 4) +

                        4);

        if (iVar3 == 0) {

LAB_0092aa24:

          iVar3 = 0;

        }

        else {

          do {

            if (local_14 == *(uint *)(iVar3 + 0x10)) {

              if (iVar3 == 0) goto LAB_0092aa24;

              iVar3 = *(int *)(iVar3 + 8);

              goto LAB_0092aa2b;

            }

            iVar3 = *(int *)(iVar3 + 0xc);

          } while (iVar3 != 0);

          iVar3 = 0;

        }

LAB_0092aa2b:

        if (iVar3 != 0) {

          local_1c = 0;

          local_20 = (int *)0x0;

          FUN_004294f0();

          iVar4 = FUN_004022a0(&local_1c,&local_20);

          piVar1 = local_20;

          while (local_20 = piVar1, iVar4 == 0) {

            if ((((((piVar1 != (int *)0x0) && (*(uint *)(piVar1[0x2a] + 0x34) == *local_24)) &&

                  (cVar2 = FUN_005134e0(), cVar2 == '\0')) && (((uint)piVar1[0x5f] >> 3 & 1) == 0))

                && (((unaff_EBX[0x42] == -1 ||

                     (iVar4 = (**(code **)(*piVar1 + 0x27c))(), unaff_EBX[0x42] <= iVar4)) &&

                    ((unaff_EBX[0x43] == -1 ||

                     (iVar4 = (**(code **)(*piVar1 + 0x27c))(), iVar4 <= unaff_EBX[0x43])))))) &&

               (((local_14 != 0x12 || (iVar4 = (**(code **)(*piVar1 + 0x1d8))(), iVar4 == 0)) ||

                ((*(uint *)(iVar4 + 0x210) & *(uint *)(iVar4 + 0x214)) == 0xffffffff)))) {

              (**(code **)(*piVar1 + 0x144))();

              fVar5 = ((float)piVar1[0x22] - param_1[2]) * ((float)piVar1[0x22] - param_1[2]) +

                      ((float)piVar1[0x20] - *param_1) * ((float)piVar1[0x20] - *param_1) +

                      ((float)piVar1[0x21] - param_1[1]) * ((float)piVar1[0x21] - param_1[1]);

              if (fVar5 < *param_3) {

                *param_3 = fVar5;

                *param_2 = piVar1;

              }

            }

            iVar4 = FUN_004022a0(&local_1c,&local_20);

            piVar1 = local_20;

          }

          if (*(char *)(iVar3 + 0x28) != '\0') {

            *(uint8_t *)(iVar3 + 0x28) = 0;

            LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 4));

          }

        }

      }

      local_24 = local_24 + 1;

      local_18 = local_18 + 1;

    } while (local_18 < unaff_EBX[0x15]);

  }

  return 1;

}
