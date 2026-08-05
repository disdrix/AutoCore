// =============================================================================
// FUN_008d4910
// -----------------------------------------------------------------------------
// Stable ID: aa_008d4910
// Address:   0x008d4910  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008d4910 @ 0x008d4910
// Stable ID: aa_008d4910
// Embedded strings (evidence for future rename):
//   - "You already have too many characters on this server to create another one!"
//   - "That combination of race/class is unavailable in this version!"
//   - "You Need To Choose A Name First!"
//   - "You haven\'t chosen a vehicle name, yet!  Do you wish to continue with a default name?"
//   - "Your Vehicle Name Is Invalid!  Please Choose Another!"
//   - "Your Character Name Is Invalid!  Please Choose Another!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~567 non-empty decompiler lines.
//  - Control keywords: if×51, goto×17, return×12, do×7, while×7, switch×2.
//  - Notable callees: FUN_00410050×26, FUN_008d1890×14, FUN_008d1b40×10, FUN_008cfa00×7, FUN_004faaf0×4, FUN_004fd970×4, FUN_0079d430×4, FUN_008d2650×3.
//  - Strings: "You Need To Choose A Name First!"; "Your Vehicle Name Is Invalid!  Please Choose Another!"; "Your Character Name Is Invalid!  Please Choose Another!".
//  - Return sites: 12.

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



uint32_t /* width from decompiler */ __thiscall FUN_008d4910(int *param_1,int param_2,int param_3)



{

  byte bVar1;

  char cVar2;

  byte bVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ uVar5;

  int *piVar6;

  char *pcVar7;

  int iVar8;

  int iVar9;

  char *pcVar10;

  float10 fVar11;

  char *pcStack_30;

  uint8_t *puStack_2c;

  int *piStack_28;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b2bd7;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  cVar2 = (**(code **)(*param_1 + 0x3d8))();

  if ((cVar2 == '\0') || (cVar2 = (**(code **)(*param_1 + 0xd0))(), cVar2 == '\0')) {

    ExceptionList = pvStack_c;

    return 0;

  }

  if ((param_3 == 0x9c56) && (param_2 == 0x1a)) {

    if (param_1[0x151] != 0) {

      fVar11 = (float10)(**(code **)(*(int *)param_1[0x1d7] + 0x458))();

      param_1[0x16c] = (int)(((float)fVar11 - DAT_00a0f298) * _DAT_00aaab74);

      piStack_28 = (int *)0x8d49c9;

      (**(code **)(*(int *)(*(int *)(*(int *)(param_1[0x151] + 4) + 4) + 4 + param_1[0x151]) + 0xb8)

      )();

      FUN_008d3e20();

    }

    goto LAB_008d50a3;

  }

  if (param_2 != 8) goto LAB_008d50a3;

  switch(param_3) {

  case 0x9c57:

    piStack_28 = (int *)0x8d4ac9;

    FUN_008d2650();

    break;

  case 0x9c58:

    piStack_28 = (int *)0x8d4abc;

    FUN_008d2650();

    break;

  case 0x9c59:

    FUN_00410050(&pcStack_30);

    uStack_4 = 0xffffffff;

    FUN_008d1b40(1,0,0xffffffff);

    FUN_00410050(&pcStack_30);

    uStack_4 = 0xffffffff;

    FUN_008d1890(0,0);

    break;

  case 0x9c5a:

    FUN_00410050(&pcStack_30);

    uStack_4 = 0xffffffff;

    FUN_008d1b40(1,0,1);

    FUN_00410050(&pcStack_30);

    uStack_4 = 0xffffffff;

    FUN_008d1890(0,0);

    break;

  case 0x9c5b:

    FUN_00410050(&pcStack_30);

    uStack_4 = 0xffffffff;

    FUN_008d1890(0,0xffffffff);

    FUN_00410050(&pcStack_30);

    goto LAB_008d4ea8;

  case 0x9c5c:

    FUN_00410050(&pcStack_30);

    uStack_4 = 0xffffffff;

    FUN_008d1890(0,1);

    FUN_00410050(&pcStack_30);

LAB_008d4ea8:

    uStack_4 = 0xffffffff;

    FUN_008d1890(-(param_1[0x169] != 1) & 3,0);

    break;

  case 0x9c5d:

    FUN_00410050(&pcStack_30);

    uStack_4 = 0xffffffff;

    FUN_008d1b40(7,1,0xffffffff);

    FUN_00410050(&pcStack_30);

    uStack_4 = 0xffffffff;

    FUN_008d1890(1,0);

    break;

  case 0x9c5e:

    FUN_00410050(&pcStack_30);

    uStack_4 = 0xffffffff;

    FUN_008d1b40(7,1,1);

    FUN_00410050(&pcStack_30);

    uStack_4 = 0xffffffff;

    FUN_008d1890(1,0);

    break;

  case 0x9c5f:

    FUN_00410050(&pcStack_30);

    uStack_4 = 0xffffffff;

    FUN_008d1b40(3,2,0xffffffff);

    FUN_00410050(&pcStack_30);

    uStack_4 = 0xffffffff;

    FUN_008d1890(2,0);

    break;

  case 0x9c60:

    FUN_00410050(&pcStack_30);

    uStack_4 = 0xffffffff;

    FUN_008d1b40(3,2,1);

    FUN_00410050(&pcStack_30);

    uStack_4 = 0xffffffff;

    FUN_008d1890(2,0);

    break;

  case 0x9c61:

    FUN_00410050(&pcStack_30);

    uStack_4 = 0xffffffff;

    FUN_008d1b40(4,3,0xffffffff);

    FUN_00410050(&pcStack_30);

    goto LAB_008d4cff;

  case 0x9c62:

    FUN_00410050(&pcStack_30);

    uStack_4 = 0xffffffff;

    FUN_008d1b40(4,3,1);

    FUN_00410050(&pcStack_30);

LAB_008d4cff:

    uStack_4 = 0xffffffff;

    FUN_008d1890(-(param_1[0x169] != 1) & 3,0);

    break;

  case 0x9c63:

    FUN_00410050(&pcStack_30);

    uStack_4 = 0xffffffff;

    FUN_008d1890(4,0xffffffff);

    break;

  case 0x9c64:

    FUN_00410050(&pcStack_30);

    uStack_4 = 0xffffffff;

    FUN_008d1890(4,1);

    break;

  case 0x9c65:

    FUN_00410050(&pcStack_30);

    uStack_4 = 0xffffffff;

    FUN_008d1b40(8,5,0xffffffff);

    FUN_00410050(&pcStack_30);

    uStack_4 = 0xffffffff;

    FUN_008d1890(5,0);

    break;

  case 0x9c66:

    FUN_00410050(&pcStack_30);

    uStack_4 = 0xffffffff;

    FUN_008d1b40(8,5,1);

    FUN_00410050(&pcStack_30);

    uStack_4 = 0xffffffff;

    FUN_008d1890(5,0);

    break;

  case 0x9c67:

    if (param_1[0x152] != 0) {

      if ((int)(*(byte *)(param_1[0x152] + 0x288) - 1) < 0) {

        FUN_004fcb50();

        piStack_28 = (int *)0x8d4fa5;

        FUN_004fd970();

        piStack_28 = (int *)0x8d4fab;

        FUN_008cfa00();

      }

      else {

        piStack_28 = (int *)0x8d4fb8;

        FUN_004fd970();

        piStack_28 = (int *)0x8d4fbe;

        FUN_008cfa00();

      }

    }

    break;

  case 0x9c68:

    if (param_1[0x152] != 0) {

      bVar1 = *(byte *)(param_1[0x152] + 0x288);

      bVar3 = FUN_004fcb50();

      if (bVar1 < bVar3) {

        piStack_28 = (int *)0x8d4f6f;

        FUN_004fd970();

        piStack_28 = (int *)0x8d4f75;

        FUN_008cfa00();

      }

      else {

        piStack_28 = (int *)0x8d4f55;

        FUN_004fd970();

        piStack_28 = (int *)0x8d4f5b;

        FUN_008cfa00();

      }

    }

    break;

  case 0x9c69:

    if (param_1[0x152] == 0) break;

    if (*(int *)(param_1[0x152] + 0x1a8) + -1 < 1) {

      piStack_28 = (int *)0x8d5050;

      FUN_004faaf0();

    }

    else {

      piStack_28 = (int *)0x8d503f;

      FUN_004faaf0();

    }

    goto LAB_008d5096;

  case 0x9c6a:

    if (param_1[0x152] != 0) {

      if (*(int *)(param_1[0x152] + 0x1a8) + 1 < DAT_00b042b8) {

        piStack_28 = (int *)0x8d5017;

        FUN_004faaf0();

      }

      else {

        piStack_28 = (int *)0x8d5020;

        FUN_004faaf0();

      }

      goto LAB_008d5096;

    }

    break;

  case 0x9c6b:

    iVar9 = param_1[0x152];

    goto joined_r0x008d505a;

  case 0x9c6c:

    iVar9 = param_1[0x152];

joined_r0x008d505a:

    if (iVar9 != 0) {

      piStack_28 = (int *)&LAB_008d5096;

      FUN_004fab40();

LAB_008d5096:

      piStack_28 = (int *)0x8d50a3;

      FUN_004fcd80();

    }

    break;

  case 0x9c6d:

    param_1[0x164] = param_1[0x164] + -1;

    piStack_28 = (int *)0x8d4fcf;

    FUN_008d37d0();

    piStack_28 = (int *)0x8d4fd5;

    FUN_008cfa00();

    break;

  case 0x9c6e:

    param_1[0x164] = param_1[0x164] + 1;

    piStack_28 = (int *)0x8d4fe7;

    FUN_008d37d0();

    piStack_28 = (int *)0x8d4fed;

    FUN_008cfa00();

    break;

  case 0x9c6f:

    puStack_2c = (uint8_t *)0x8d4a62;

    piStack_28 = param_1;

    FUN_008d2f40();

    break;

  case 0x9c70:

    puStack_2c = (uint8_t *)0x8d4a75;

    piStack_28 = param_1;

    FUN_008d2f40();

    break;

  case 0x9c71:

    puStack_2c = (uint8_t *)0x8d4a88;

    piStack_28 = param_1;

    FUN_008d2f40();

    break;

  case 0x9c72:

    puStack_2c = (uint8_t *)0x8d4a9b;

    piStack_28 = param_1;

    FUN_008d1700();

    break;

  case 0x9c73:

    puStack_2c = (uint8_t *)0x8d4aae;

    piStack_28 = param_1;

    FUN_008d1700();

    break;

  case 0x9c75:

    *(uint8_t *)((int)param_1 + 0x5bd) = 0;

    if (param_1[0x15a] != 0) {

      FUN_008d3a70();

    }

    break;

  case 0x9c76:

    *(uint8_t *)((int)param_1 + 0x5be) = 0;

    if (param_1[0x15a] != 1) {

      FUN_008d3c90();

    }

    break;

  case 0x9c77:

    *(uint8_t *)((int)param_1 + 0x5bf) = 0;

    if (param_1[0x15a] != 2) {

      FUN_008d3b30();

    }

  }

LAB_008d50a3:

  switch(param_3) {

  case 40000:

    if (param_2 != 8) break;

    if (param_1[0x151] == 0) {

      ExceptionList = pvStack_c;

      return 1;

    }

    iVar9 = 0;

    piVar6 = &DAT_00d1b6dc;

    do {

      if (*piVar6 != 0) {

        iVar9 = iVar9 + 1;

      }

      piVar6 = piVar6 + 1;

    } while ((int)piVar6 < 0xd1b70c);

    if (0xb < iVar9) {

      pcStack_30 = "You already have too many characters on this server to create another one!";

      goto LAB_008d56f1;

    }

    if ((&DAT_00d09a20)[param_1[0x16a] * 4 + param_1[0x16b]] == '\0') {

      pcStack_30 = "That combination of race/class is unavailable in this version!";

      goto LAB_008d56f1;

    }

    if ((((int *)param_1[0x1ad] == (int *)0x0) ||

        (iVar9 = (**(code **)(*(int *)param_1[0x1ad] + 0x1dc))(), iVar9 == 0)) ||

       (pcVar7 = (char *)(**(code **)(*(int *)param_1[0x1ad] + 0x1dc))(), *pcVar7 == '\0')) {

      pcStack_30 = "You Need To Choose A Name First!";

      goto LAB_008d56f1;

    }

    pcVar7 = (char *)(**(code **)(*(int *)param_1[0x1ad] + 0x1dc))();

    if (pcVar7 != (char *)0x0) {

      cVar2 = *pcVar7;

      if (cVar2 != '\0') {

        iVar9 = 0;

        do {

          piStack_28 = (int *)0x8d536e;

          iVar8 = isalnum((int)cVar2);

          if (((iVar8 == 0) && (*pcVar7 != '_')) || (0x10 < iVar9)) goto LAB_008d546f;

          cVar2 = pcVar7[1];

          pcVar7 = pcVar7 + 1;

          iVar9 = iVar9 + 1;

        } while (cVar2 != '\0');

      }

      if (DAT_00d1d8cc == 0) {

LAB_008d53e9:

        if (((int *)param_1[0x1ae] == (int *)0x0) ||

           (iVar9 = (**(code **)(*(int *)param_1[0x1ae] + 0x1dc))(), iVar9 == 0)) {

LAB_008d5451:

          if (*(char *)((int)param_1 + 0x5c2) == '\0') {

            puStack_2c = (uint8_t *)0xffffffff;

            pcStack_30 = 

            "You haven\'t viewed any of the vehicle options yet!  Please select the Vehicle View button to edit your vehicle and give it a name!"

            ;

LAB_008d5736:

            piStack_28 = (int *)0x1;

            FUN_007fdfb0(&DAT_00d1a840);

            if ((int *)param_1[0x1e7] != (int *)0x0) {

              piStack_28 = (int *)0x1;

              puStack_2c = &LAB_008d5756;

              (**(code **)(*(int *)param_1[0x1e7] + 0x3c8))();

            }

            if (param_1[0x15a] != 2) {

              FUN_008d3b30();

            }

            ExceptionList = pvStack_c;

            return 1;

          }

          _DAT_00d1b684 = *(uint32_t /* width from decompiler */ *)(param_1[0x151] + 0x6f8);

          _DAT_00d1b68c = *(uint32_t /* width from decompiler */ *)(param_1[0x151] + 0x700);

          _DAT_00d1b690 = *(uint32_t /* width from decompiler */ *)(param_1[0x151] + 0x708);

          _DAT_00d1b694 = *(uint32_t /* width from decompiler */ *)(param_1[0x151] + 0x70c);

          _DAT_00d1b698 = *(uint32_t /* width from decompiler */ *)(param_1[0x151] + 0x704);

          _DAT_00d1b69c = *(uint32_t /* width from decompiler */ *)(param_1[0x151] + 0x710);

          _DAT_00d1b6a0 = *(uint32_t /* width from decompiler */ *)(param_1[0x151] + 0x714);

          DAT_00d1b6a9 = (uint8_t)param_1[0x16b];

          DAT_00d1b6a8 = (uint8_t)param_1[0x16a];

          DAT_00d1b6aa = param_1[0x169] == 1;

          iVar9 = 0;

          do {

            piStack_28 = (int *)0x8d5530;

            uVar5 = FUN_0051ffd0();

            (&DAT_00d1b6ac)[iVar9] = uVar5;

            iVar9 = iVar9 + 1;

          } while (iVar9 < 6);

          pcVar7 = (char *)(**(code **)(*(int *)param_1[0x1ad] + 0x1dc))();

          pcVar10 = &DAT_00d1b650;

          do {

            cVar2 = *pcVar7;

            *pcVar10 = cVar2;

            pcVar7 = pcVar7 + 1;

            pcVar10 = pcVar10 + 1;

          } while (cVar2 != '\0');

          if ((((int *)param_1[0x1ae] == (int *)0x0) ||

              (iVar9 = (**(code **)(*(int *)param_1[0x1ae] + 0x1dc))(), iVar9 == 0)) ||

             (pcVar7 = (char *)(**(code **)(*(int *)param_1[0x1ae] + 0x1dc))(), *pcVar7 == '\0')) {

            iVar9 = param_1[0x152];

            if (iVar9 == 0) {

              DAT_00d1b661 = 0;

            }

            else {

              pcVar7 = (char *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar9 + 4) + 4) + 4 + iVar9)

                                           + 0x15c))();

              pcVar10 = &DAT_00d1b661;

              do {

                cVar2 = *pcVar7;

                *pcVar10 = cVar2;

                pcVar7 = pcVar7 + 1;

                pcVar10 = pcVar10 + 1;

              } while (cVar2 != '\0');

            }

          }

          else {

            pcVar7 = (char *)(**(code **)(*(int *)param_1[0x1ae] + 0x1dc))();

            pcVar10 = &DAT_00d1b661;

            do {

              cVar2 = *pcVar7;

              *pcVar10 = cVar2;

              pcVar7 = pcVar7 + 1;

              pcVar10 = pcVar10 + 1;

            } while (cVar2 != '\0');

          }

          _DAT_00d1b6c4 = *(uint32_t /* width from decompiler */ *)(param_1[0x152] + 0x1a8);

          _DAT_00d1b6c8 = *(uint32_t /* width from decompiler */ *)(param_1[0x152] + 0x1ac);

          DAT_00d1b6cc = *(uint8_t *)(param_1[0x152] + 0x288);

          _DAT_00d1b6d0 =

               *(float *)(*(int *)(*(int *)(param_1[0x151] + 4) + 4) + 0xbc + param_1[0x151]) -

               DAT_00aaaa1c;

          _DAT_00d1b6d4 =

               *(uint32_t /* width from decompiler */ *)

                (*(int *)(*(int *)(*(int *)(*(int *)(param_1[0x152] + 600) + 4) + 4) + 0xac +

                         *(int *)(param_1[0x152] + 600)) + 0x34);

          if ((((int *)param_1[0x1ae] == (int *)0x0) ||

              (iVar9 = (**(code **)(*(int *)param_1[0x1ae] + 0x1dc))(), iVar9 == 0)) ||

             (pcVar7 = (char *)(**(code **)(*(int *)param_1[0x1ae] + 0x1dc))(), *pcVar7 == '\0')) {

            puStack_2c = (uint8_t *)0x4e23;

            pcStack_30 = 

            "You haven\'t chosen a vehicle name, yet!  Do you wish to continue with a default name?"

            ;

            goto LAB_008d5736;

          }

          if (DAT_00d1d8cc == 0) {

LAB_008d5717:

            FUN_00937710();

            ExceptionList = pvStack_c;

            return 1;

          }

          (**(code **)(*(int *)param_1[0x1ae] + 0x1dc))();

          piStack_28 = (int *)DAT_00d1d8cc;

          puStack_2c = (uint8_t *)0x8d56c0;

          cVar2 = FUN_0079d430();

          if (cVar2 == '\0') {

            (**(code **)(*(int *)param_1[0x1ae] + 0x1dc))();

            piStack_28 = DAT_00d1d8c8;

            puStack_2c = (uint8_t *)0x8d56e2;

            cVar2 = FUN_0079d430();

            if (cVar2 == '\0') goto LAB_008d5717;

          }

        }

        else {

          pcVar7 = (char *)(**(code **)(*(int *)param_1[0x1ae] + 0x1dc))();

          if (pcVar7 != (char *)0x0) {

            cVar2 = *pcVar7;

            if (cVar2 != '\0') {

              iVar9 = 0;

              do {

                piStack_28 = (int *)0x8d5426;

                iVar8 = isalnum((int)cVar2);

                if ((((iVar8 == 0) && (*pcVar7 != '_')) && (*pcVar7 != ' ')) || (0x20 < iVar9))

                goto LAB_008d56e6;

                cVar2 = pcVar7[1];

                pcVar7 = pcVar7 + 1;

                iVar9 = iVar9 + 1;

              } while (cVar2 != '\0');

            }

            goto LAB_008d5451;

          }

        }

LAB_008d56e6:

        pcStack_30 = "Your Vehicle Name Is Invalid!  Please Choose Another!";

        goto LAB_008d56f1;

      }

      (**(code **)(*(int *)param_1[0x1ad] + 0x1dc))();

      piStack_28 = (int *)DAT_00d1d8cc;

      puStack_2c = (uint8_t *)0x8d53bb;

      cVar2 = FUN_0079d430();

      if (cVar2 == '\0') {

        (**(code **)(*(int *)param_1[0x1ad] + 0x1dc))();

        piStack_28 = DAT_00d1d8c8;

        puStack_2c = (uint8_t *)0x8d53e1;

        cVar2 = FUN_0079d430();

        if (cVar2 == '\0') goto LAB_008d53e9;

      }

    }

LAB_008d546f:

    pcStack_30 = "Your Character Name Is Invalid!  Please Choose Another!";

LAB_008d56f1:

    piStack_28 = (int *)0x1;

    puStack_2c = (uint8_t *)0xffffffff;

    FUN_007fdfb0(&DAT_00d1a840);

    ExceptionList = pvStack_c;

    return 1;

  case 0x9c41:

    if (param_2 == 8) {

      piStack_28 = (int *)0x8d528c;

      FUN_009133a0();

      ExceptionList = pvStack_c;

      return 1;

    }

    break;

  case 0x9c45:

    if (param_2 == 8) {

      if (param_1[0x15a] == 2) {

        FUN_008d4550();

      }

      else {

        if ((param_1[0x151] == 0) || (*(int *)(param_1[0x151] + 0x48) == 0)) break;

        FUN_00524ad0();

        FUN_008d1c70();

        uVar4 = FUN_00401c30();

        if (1 < uVar4) {

          CVOGReaction_RandomUnitScalar();

          FUN_00424830();

          FUN_00401c30();

          piStack_28 = (int *)0x8d51a5;

          FUN_008d2650();

          FUN_008d19f0();

        }

        FUN_008d2b10();

      }

      piStack_28 = (int *)0x8d51b7;

      FUN_008cfa00();

    }

    break;

  case 0x9c48:

    if (param_2 == 0x1a) {

      piStack_28 = (int *)0x8d50e6;

      FUN_008cf850();

      ExceptionList = pvStack_c;

      return 1;

    }

    break;

  case 0x9c49:

    if (param_2 == 0x1a) {

      piStack_28 = (int *)0x8d5120;

      FUN_008cf850();

      ExceptionList = pvStack_c;

      return 1;

    }

    break;

  case 0x9c4b:

  case 0x9c4c:

    if (param_2 == 8) {

      FUN_008d2a70();

      ExceptionList = pvStack_c;

      return 1;

    }

    break;

  case 0x9c4e:

  case 0x9c4f:

  case 0x9c50:

    if (param_2 == 8) {

      FUN_008d4690();

      ExceptionList = pvStack_c;

      return 1;

    }

    break;

  case 0x9c52:

  case 0x9c53:

  case 0x9c54:

  case 0x9c55:

    if (param_2 == 8) {

      FUN_008d2a90();

      ExceptionList = pvStack_c;

      return 1;

    }

  }

  piStack_28 = (int *)param_2;

  puStack_2c = (uint8_t *)0x8d51c8;

  uVar5 = FUN_008d7350();

  ExceptionList = pvStack_c;

  return uVar5;

}
