// =============================================================================
// FUN_0092c080
// -----------------------------------------------------------------------------
// Stable ID: aa_0092c080
// Address:   0x0092c080  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0092c080 @ 0x0092c080
// Stable ID: aa_0092c080
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~209 non-empty decompiler lines.
//  - Control keywords: if×29, return×7, goto×4, while×3, do×1.
//  - Notable callees: CNDHash_LookupByKey×4, FUN_0092b020×3, FUN_004022a0×2, FUN_004024b0, FUN_0040c700, FUN_004294f0, FUN_0059da60, FUN_00929c00.
//  - Return sites: 7.

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

uint32_t /* width from decompiler */ FUN_0092c080(void)



{

  int *piVar1;

  bool bVar2;

  bool bVar3;

  char cVar4;

  byte bVar5;

  int *in_EAX;

  float *pfVar6;

  int iVar7;

  void *pvVar8;

  RACE_ID_INFERRED RVar9;

  int iVar10;

  int *piVar11;

  uint32_t /* width from decompiler */ *local_40;

  int *local_3c;

  uint32_t /* width from decompiler */ *local_38;

  int local_34;

  float fStack_30;

  float fStack_2c;

  float fStack_28;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  

  FUN_0092a3d0();

  iVar10 = DAT_00aaa6fc;

  in_EAX[6] = -1;

  in_EAX[8] = -1;

  in_EAX[9] = -1;

  in_EAX[0x15] = 0;

  in_EAX[0x20] = 0;

  in_EAX[0x2b] = 0;

  in_EAX[10] = 0;

  *(uint8_t *)(in_EAX + 0x40) = 0;

  *(uint8_t *)((int)in_EAX + 0x101) = 0;

  *(uint8_t *)((int)in_EAX + 0x102) = 0;

  in_EAX[0x41] = iVar10;

  in_EAX[0x42] = -1;

  in_EAX[0x43] = -1;

  iVar10 = *(int *)(*in_EAX + 0xe98);

  if ((((iVar10 != 0) && (*(char *)(iVar10 + 0x4f1) == '\0')) && (*(int *)(*in_EAX + 0xd34) != 0))

     && (*(int *)(iVar10 + 0x250) != 0)) {

    *(uint8_t *)((int)in_EAX + 7) = 0;

    *(uint8_t *)((int)in_EAX + 9) = 0;

    if ((in_EAX[4] != 0) || (cVar4 = FUN_0092b020(), local_40 = DAT_00aaaafc, cVar4 != '\0')) {

      iVar10 = *in_EAX;

      pvVar8 = CNDHash_LookupByKey(*(void **)(*(int *)(iVar10 + 0xe98) + 0x548),in_EAX[4]);

      if (pvVar8 == (void *)0x0) {

        in_EAX[4] = 0;

        cVar4 = FUN_0092b020();

        if (cVar4 == '\0') {

          return 0;

        }

        iVar10 = *in_EAX;

        pvVar8 = CNDHash_LookupByKey(*(void **)(*(int *)(iVar10 + 0xe98) + 0x548),in_EAX[4]);

        if (pvVar8 == (void *)0x0) {

          return 0;

        }

      }

      *(uint8_t *)((int)in_EAX + 0xb) = 0;

      bVar3 = false;

      local_3c = CNDHash_LookupByKey(*(void **)(*(int *)(iVar10 + 0xe98) + 0x55c),

                                     *(uint *)((int)pvVar8 + 0x10));

      piVar11 = (int *)0x0;

      iVar10 = FUN_004024b0();

      if (iVar10 != 0) {

        if (local_3c != (int *)0x0) {

          local_38 = *(uint32_t /* width from decompiler */ **)((int)pvVar8 + 0x158);

          local_34 = -1;

          bVar2 = false;

          if (local_38 != *(uint32_t /* width from decompiler */ **)((int)pvVar8 + 0x15c)) {

            do {

              piVar11 = (int *)*local_38;

              iVar10 = (**(code **)(*piVar11 + 0x50))();

              if (iVar10 == 6) {

                cVar4 = (**(code **)(*piVar11 + 8))(*(uint32_t /* width from decompiler */ *)(*in_EAX + 0xe98),local_3c);

                if (cVar4 == '\0') {

                  bVar3 = true;

                }

              }

              else {

                cVar4 = (**(code **)(*piVar11 + 8))(*(uint32_t /* width from decompiler */ *)(*in_EAX + 0xe98),local_3c);

                if (cVar4 == '\0') {

                  bVar5 = (**(code **)(*piVar11 + 0x24))();

                  *(byte *)((int)in_EAX + 0xb) = *(byte *)((int)in_EAX + 0xb) | bVar5;

                  bVar3 = true;

                  if (((iVar10 == 1) || (iVar10 == 2)) || (iVar10 == 0xc)) {

                    if ((local_34 != -1) && (local_34 != iVar10)) goto LAB_0092c459;

                    bVar2 = true;

                    local_34 = iVar10;

                  }

                  else if (bVar2) goto LAB_0092c459;

                  piVar1 = in_EAX + 6;

                  cVar4 = (**(code **)(*piVar11 + 0x5c))(piVar1,local_3c);

                  if (cVar4 != '\0') {

                    if (*piVar1 == -1) {

                      *piVar1 = *(int *)((int)pvVar8 + 0x120);

                    }

                    if (!bVar2) goto LAB_0092c459;

                  }

                }

              }

              local_38 = local_38 + 1;

            } while (local_38 != *(uint32_t /* width from decompiler */ **)((int)pvVar8 + 0x15c));

            if (bVar3) goto LAB_0092c459;

          }

        }

        if (*(int *)((int)pvVar8 + 0x138) == 0) {

          FUN_0092b020();

          return 0;

        }

        if ((piVar11 == (int *)0x0) || (iVar10 = (**(code **)(*piVar11 + 0x50))(), iVar10 != 3)) {

          local_34 = in_EAX[6];

          piVar11 = in_EAX + 0x16;

          FUN_0059da60(piVar11,&local_34);

          if ((*piVar11 == -1) &&

             (pvVar8 = CNDHash_LookupByKey(*(void **)(*(int *)(*in_EAX + 0xe98) + 0x530),

                                           *(uint *)((int)pvVar8 + 0xc)), pvVar8 != (void *)0x0)) {

            *piVar11 = *(int *)((int)pvVar8 + 0x20);

            in_EAX[6] = *(int *)((int)pvVar8 + 0x24);

            in_EAX[0x15] = 1;

            *(uint8_t *)((int)in_EAX + 7) = 1;

          }

          else {

            in_EAX[6] = local_34;

            in_EAX[0x15] = 1;

            *(uint8_t *)((int)in_EAX + 7) = 1;

          }

        }

        else {

          bVar5 = (**(code **)(*piVar11 + 0x24))();

          *(byte *)((int)in_EAX + 0xb) = *(byte *)((int)in_EAX + 0xb) | bVar5;

          (**(code **)(*piVar11 + 0x5c))(in_EAX + 6,local_3c);

          if (in_EAX[6] == -1) {

            in_EAX[6] = *(int *)((int)pvVar8 + 0x120);

          }

        }

      }

LAB_0092c459:

      local_34 = in_EAX[6];

      if ((local_34 != -1) && (local_34 != *(int *)(*(int *)(*in_EAX + 0xe04) + 0xfc))) {

        FUN_00929c00();

        iVar10 = *(int *)(*in_EAX + 0xe04);

        piVar11 = *(int **)(iVar10 + 0xe798);

        if (piVar11 != *(int **)(iVar10 + 0xe79c)) {

          while ((piVar11[7] != local_34 ||

                 ((piVar11[8] != -1 &&

                  (RVar9 = Object_GetRootRaceId

                                     ((void *)(*(int *)(*(int *)(*(int *)(*in_EAX + 0xe98) + 4) + 4)

                                               + 4 + *(int *)(*in_EAX + 0xe98))),

                  piVar11[8] != RVar9))))) {

            piVar11 = piVar11 + 0x10;

            if (piVar11 == *(int **)(iVar10 + 0xe79c)) {

              return 1;

            }

          }

          in_EAX[8] = *piVar11;

          in_EAX[9] = piVar11[1];

        }

      }

      return 1;

    }

    local_34 = 0;

    local_3c = (int *)0x0;

    iVar10 = 0;

    pfVar6 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(*in_EAX + 0xe98) + 4) + 4) +

                                            4 + *(int *)(*in_EAX + 0xe98)) + 0x1a0))();

    fStack_20 = *pfVar6;

    fStack_1c = pfVar6[1];

    fStack_18 = pfVar6[2];

    FUN_004294f0();

    iVar7 = FUN_004022a0(&local_34,&local_3c);

    piVar11 = local_3c;

    while (local_3c = piVar11, iVar7 == 0) {

      iVar7 = (**(code **)(*piVar11 + 0x1d8))();

      if ((((iVar7 != 0) &&

           (iVar7 = (**(code **)(*piVar11 + 0x1d8))(),

           *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 0xac + iVar7) + 0x3c) +

                   0x4e0) == 1)) && (piVar11[0x47] != 0)) &&

         (((iVar7 = *(int *)(piVar11[0x47] + 0x10), iVar7 == 6 || (iVar7 == 3)) || (iVar7 == 7)))) {

        fStack_28 = (float)piVar11[0x22] - fStack_18;

        fStack_2c = (float)piVar11[0x21] - fStack_1c;

        fStack_30 = (float)piVar11[0x20] - fStack_20;

        local_38 = (uint32_t /* width from decompiler */ *)

                   SQRT(fStack_30 * fStack_30 + fStack_2c * fStack_2c + fStack_28 * fStack_28);

        if ((float)local_38 < (float)local_40) {

          iVar10 = (**(code **)(*piVar11 + 0x1d8))();

          if (iVar10 == 0) {

            iVar10 = 0;

          }

          else {

            iVar10 = *(int *)(*(int *)(iVar10 + 4) + 4) + 4 + iVar10;

          }

          local_40 = local_38;

        }

      }

      iVar7 = FUN_004022a0(&local_34,&local_3c);

      piVar11 = local_3c;

    }

    FUN_0040c700();

    if (iVar10 != 0) {

      *(uint8_t *)((int)in_EAX + 9) = 1;

      in_EAX[8] = *(int *)(iVar10 + 0x160);

      in_EAX[9] = *(int *)(iVar10 + 0x164);

      return 1;

    }

  }

  return 0;

}
