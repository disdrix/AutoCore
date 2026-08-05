// =============================================================================
// FUN_00958290
// -----------------------------------------------------------------------------
// Stable ID: aa_00958290
// Address:   0x00958290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00958290 @ 0x00958290
// Stable ID: aa_00958290
// Embedded strings (evidence for future rename):
//   - "test_many_particles"
//   - "Dist 1 %0.2f(%f) Dist2 %0.2f(%f)"
//   - "test2"
//   - "title4"
//   - "test23"
//   - "title23"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~443 non-empty decompiler lines.
//  - Control keywords: if×28, goto×7, while×3, return×2, do×2, switch×1.
//  - Notable callees: CONCAT44×8, FUN_00402130×3, FUN_004c6710×3, FUN_00691630×3, FUN_007fe460×3, FUN_00802ff0×3, FUN_00803050×3, QueryPerformanceCounter×3.
//  - Strings: "test_many_particles"; "Dist 1 %0.2f(%f) Dist2 %0.2f(%f)"; "test2"; "title4".
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ __thiscall FUN_00958290(int param_1,uint32_t /* width from decompiler */ param_2,char *param_3)



{

  double dVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint8_t uVar5;

  char *pcVar6;

  uint32_t /* width from decompiler */ uVar7;

  void *pvVar8;

  uint8_t *puVar9;

  short sVar10;

  uint uVar11;

  uint16_t extraout_var;

  uint16_t extraout_var_00;

  uint16_t uVar12;

  int *piVar13;

  int iVar14;

  int iVar15;

  float10 fVar16;

  float10 fVar17;

  uint64_t uVar18;

  uint64_t uVar19;

  int iStack_4c4;

  LARGE_INTEGER LStack_4a0;

  DWORD DStack_498;

  uint32_t /* width from decompiler */ uStack_494;

  uint32_t /* width from decompiler */ *puStack_488;

  int iStack_484;

  int iStack_480;

  int iStack_47c;

  LARGE_INTEGER LStack_478;

  uint32_t /* width from decompiler */ uStack_470;

  uint32_t /* width from decompiler */ uStack_46c;

  LARGE_INTEGER LStack_468;

  uint32_t /* width from decompiler */ uStack_460;

  uint32_t /* width from decompiler */ uStack_45c;

  LARGE_INTEGER LStack_458;

  uint32_t /* width from decompiler */ uStack_450;

  uint32_t /* width from decompiler */ uStack_44c;

  uint32_t /* width from decompiler */ uStack_448;

  uint32_t /* width from decompiler */ uStack_444;

  uint8_t auStack_440 [24];

  char acStack_428 [1036];

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009bbaae;

  pvStack_1c = ExceptionList;

  iVar15 = 0;

  piVar13 = (int *)0x0;

  ExceptionList = &pvStack_1c;

  if (*(int *)(param_1 + 0xe98) != 0) {

    iVar14 = *(int *)(param_1 + 0xe98);

    ExceptionList = &pvStack_1c;

    if ((*(int *)(*(int *)(*(int *)(iVar14 + 4) + 4) + 0xa4 + iVar14) == 0) ||

       (ExceptionList = &pvStack_1c,

       piVar13 = (int *)(**(code **)(**(int **)(*(int *)(*(int *)(iVar14 + 4) + 4) + 0xa4 + iVar14)

                                    + 0x1c8))(), piVar13 == (int *)0x0)) {

      iVar14 = *(int *)(*(int *)(param_1 + 0xe98) + 0x250);

      if (((iVar14 == 0) ||

          ((*(char *)(*(int *)(param_1 + 0xe98) + 0x30c) == '\0' ||

           (piVar13 = (int *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar14 + 4) + 4) + 4 + iVar14)

                                         + 0x1c8))(), piVar13 == (int *)0x0)))) &&

         (piVar13 = (int *)(**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) +

                                                         4) + 4 + *(int *)(param_1 + 0xe98)) + 0x1c8

                                       ))(), piVar13 == (int *)0x0)) goto LAB_00958363;

    }

    if (piVar13[2] != 0) {

      iVar15 = (**(code **)(*(int *)(*(int *)(piVar13[1] + 4) + 4 + (int)piVar13) + 0x214))();

    }

  }

LAB_00958363:

  pcVar6 = strtok((char *)0x0,param_3);

  if (pcVar6 == (char *)0x0) {

    ExceptionList = pvStack_1c;

    return 1;

  }

  switch(*pcVar6) {

  case '1':

    if (iVar15 != 0) {

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar15 + 4) + 4) + 4 + iVar15) + 0x188))();

    }

    break;

  case '2':

    if (iVar15 != 0) {

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar15 + 4) + 4) + 4 + iVar15) + 0x188))();

    }

    break;

  case '3':

    if (iVar15 != 0) {

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar15 + 4) + 4) + 4 + iVar15) + 400))();

    }

    break;

  case '4':

    if (iVar15 != 0) {

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar15 + 4) + 4) + 4 + iVar15) + 400))();

    }

    break;

  case '5':

    if (iVar15 != 0) {

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar15 + 4) + 4) + 4 + iVar15) + 400))();

      FUN_004c6710();

    }

    break;

  case '6':

    if (iVar15 != 0) {

      FUN_004c6710();

    }

    break;

  case '7':

    if (iVar15 != 0) {

      FUN_004c6710();

    }

    break;

  case '8':

    iVar15 = *(int *)(param_1 + 0xe98);

    if (*(int *)(*(int *)(*(int *)(iVar15 + 4) + 4) + 0xa4 + iVar15) != 0) {

      uVar7 = (**(code **)(**(int **)(*(int *)(*(int *)(iVar15 + 4) + 4) + 0xa4 + iVar15) + 0x1d8))

                        ();

      FUN_004de760(*(uint32_t /* width from decompiler */ *)(param_1 + 0xe98),uVar7);

    }

    break;

  case '9':

    iVar15 = *(int *)(param_1 + 0xe98);

    if (*(int *)(*(int *)(*(int *)(iVar15 + 4) + 4) + 0xa4 + iVar15) != 0) {

      if (*(int *)(*(int *)(*(int *)(*(int *)(iVar15 + 4) + 4) + 0xa4 + iVar15) + 0x11c) == 0) {

        (**(code **)(**(int **)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) + 0xa4 +

                               *(int *)(param_1 + 0xe98)) + 0x160))();

        FUN_007a4480();

      }

      else {

        if (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) + 0xa4

                                      + *(int *)(param_1 + 0xe98)) + 0x11c) + 0x14) == 0) {

          uVar5 = 0;

        }

        else {

          uVar5 = (**(code **)(**(int **)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 +

                                                                                      0xe98) + 4) +

                                                                    4) + 0xa4 +

                                                           *(int *)(param_1 + 0xe98)) + 0x11c) +

                                         0x14) + 100))();

        }

        iVar15 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) + 0xa4 +

                                  *(int *)(param_1 + 0xe98)) + 0x11c);

        (**(code **)(**(int **)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) + 0xa4 +

                               *(int *)(param_1 + 0xe98)) + 0x160))

                  (*(uint32_t /* width from decompiler */ *)(iVar15 + 0x10),*(uint32_t /* width from decompiler */ *)(iVar15 + 0x18),

                   *(uint32_t /* width from decompiler */ *)(iVar15 + 0x1c),uVar5);

        FUN_007a4480();

      }

    }

    break;

  case 'a':

    FUN_00870680();

    break;

  case 'b':

    FUN_00870680();

    break;

  case 'e':

    goto LAB_009583df;

  case 'f':

    if ((piVar13 != (int *)0x0) && (piVar13[2] != 0)) {

      uStack_450 = 0;

      uStack_44c = DAT_00aaa668;

      uStack_448 = 0;

      uStack_444 = 0;

      FUN_004e9060();

      FUN_00404dc0();

    }

    break;

  case 'l':

    FUN_007fdfb0();

    break;

  case 'm':

    LStack_478.s.HighPart = 0;

    uStack_470 = 0;

    uStack_46c = 0;

    uStack_14 = 2;

    FUN_00402130();

    LStack_468.s.HighPart = 0;

    uStack_460 = 0;

    uStack_45c = 0;

    uStack_14._0_1_ = 3;

    FUN_00402130();

    LStack_4a0.s.HighPart = 0;

    DStack_498 = 0;

    uStack_494 = 0;

    uStack_14._0_1_ = 4;

    FUN_00402130();

    uStack_14._0_1_ = 3;

    FUN_00691630();

    uStack_14 = CONCAT31(uStack_14._1_3_,2);

    FUN_00691630();

    uStack_14 = 0xffffffff;

    FUN_00691630();

    break;

  case 'n':

    goto LAB_009583df;

  case 'p':

    pcVar6 = strtok((char *)0x0,param_3);

    iVar15 = atoi(pcVar6);

    pvVar8 = NDSpecialFX_LoadFromScriptName("test_many_particles",iVar15,0);

    if (pvVar8 != (void *)0x0) {

      iVar15 = *(int *)(*(int *)(param_1 + 0xe98) + 0x250);

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar15 + 4) + 4) + 4 + iVar15) + 0xf8))();

    }

    break;

  case 'r':

    iVar15 = *(int *)(*(int *)(param_1 + 0xe98) + 0x250);

    pvVar8 = CNDHash_LookupByKey(*(void **)(*(int *)(param_1 + 0xd30) + 0xf10),

                                 *(uint *)(*(int *)(*(int *)(*(int *)(iVar15 + 4) + 4) + 0xac +

                                                   iVar15) + 0x34));

    if (pvVar8 != (void *)0x0) {

      FUN_004eb0c0();

    }

    iVar15 = *(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 0x250) + 600);

    pvVar8 = CNDHash_LookupByKey(*(void **)(*(int *)(param_1 + 0xd30) + 0xf10),

                                 *(uint *)(*(int *)(*(int *)(*(int *)(iVar15 + 4) + 4) + 0xac +

                                                   iVar15) + 0x34));

    if (pvVar8 != (void *)0x0) {

      FUN_004eb0c0();

    }

    FUN_004f8fe0();

    Vehicle_ActivateEnterWorld();

    break;

  case 's':

    goto LAB_009583df;

  case 't':

    uVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) + 4 +

                                 *(int *)(param_1 + 0xe98)) + 0x1a4))();

    FUN_004e8a40(uVar7);

    QueryPerformanceFrequency(&LStack_4a0);

    QueryPerformanceCounter(&LStack_468);

    iVar15 = 100;

    do {

      iVar14 = *(int *)(param_1 + 0xe98);

      iVar2 = *(int *)(*(int *)(*(int *)(iVar14 + 0x250) + 0x260) + 4);

      uVar7 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0xdc);

      uVar3 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0xe8);

      iVar14 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar14 + 4) + 4) + 4 + iVar14) + 0x19c))();

      iStack_480 = *(int *)(iVar14 + 0x34);

      (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) + 4 +

                           *(int *)(param_1 + 0xe98)) + 0x1a0))

                (iStack_480,uVar3,piVar13,auStack_440,uVar7);

      fVar16 = (float10)FUN_004e9aa0();

      iVar15 = iVar15 + -1;

    } while (iVar15 != 0);

    QueryPerformanceCounter(&LStack_478);

    iVar15 = 100;

    do {

      iVar14 = *(int *)(param_1 + 0xe98);

      iVar2 = *(int *)(*(int *)(*(int *)(iVar14 + 0x250) + 0x260) + 4);

      iStack_480 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0xdc);

      uVar7 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0xe8);

      iVar14 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar14 + 4) + 4) + 4 + iVar14) + 0x19c))();

      (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) + 4 +

                           *(int *)(param_1 + 0xe98)) + 0x1a0))

                (*(uint32_t /* width from decompiler */ *)(iVar14 + 0x34),uVar7,piVar13,auStack_440,iStack_480);

      fVar17 = (float10)FUN_004e9aa0();

      puStack_488 = (uint32_t /* width from decompiler */ *)(float)fVar17;

      iVar15 = iVar15 + -1;

    } while (iVar15 != 0);

    QueryPerformanceCounter(&LStack_458);

    iStack_480 = LStack_458.s.LowPart - LStack_478._0_4_;

    iStack_47c = (LStack_458.s.HighPart - LStack_478._4_4_) -

                 (uint)(LStack_458.s.LowPart < LStack_478.s.LowPart);

    iStack_484 = (LStack_478.s.HighPart - LStack_468._4_4_) -

                 (uint)(LStack_478.s.LowPart < LStack_468.s.LowPart);

    dVar1 = (double)(float)puStack_488;

    puStack_488 = (uint32_t /* width from decompiler */ *)(LStack_478.s.LowPart - LStack_468._0_4_);

    sprintf(acStack_428,"Dist 1 %0.2f(%f) Dist2 %0.2f(%f)",(double)(float)fVar16,

            (double)CONCAT44(iStack_484,LStack_478.s.LowPart - LStack_468._0_4_) /

            (double)CONCAT44(LStack_4a0.s.HighPart,LStack_4a0.s.LowPart),dVar1,

            (double)CONCAT44(iStack_47c,iStack_480) /

            (double)CONCAT44(LStack_4a0.s.HighPart,LStack_4a0.s.LowPart));

    goto LAB_00958a7c;

  case 'u':

    goto LAB_009583df;

  case 'v':

    FUN_00803050(4,0,"test2","title4");

    FUN_00802ff0();

    FUN_00803050(6,0,"test23","title23");

    FUN_00802fa0();

    puStack_488 = operator_new__(s___AVCVOGDialog___00af8e58[0x11] * 4);

    *puStack_488 = 0x4f;

    puStack_488[1] = 0x144;

    piVar13 = operator_new__(0x10);

    pvVar8 = operator_new__(0x100);

    *piVar13 = (int)pvVar8;

    pvVar8 = operator_new__(0x100);

    piVar13[1] = (int)pvVar8;

    puVar4 = (uint32_t /* width from decompiler */ *)*piVar13;

    *puVar4 = DAT_00a28ca4;

    *(uint16_t *)(puVar4 + 1) = DAT_00a28ca8;

    *(uint8_t *)((int)puVar4 + 6) = DAT_00a28caa;

    puVar4 = (uint32_t /* width from decompiler */ *)piVar13[1];

    *puVar4 = DAT_00a28c9c;

    *(uint16_t *)(puVar4 + 1) = DAT_00a28ca0;

    *(uint8_t *)((int)puVar4 + 6) = DAT_00a28ca2;

    iVar15 = (int)s___AVCVOGDialog___00af8e58[0x11];

    puVar9 = operator_new__(iVar15 * 4);

    uStack_14 = 1;

    if (puVar9 == (uint8_t *)0x0) {

      puVar9 = (uint8_t *)0x0;

      uVar12 = extraout_var;

    }

    else {

      FUN_00404d80(puVar9,4,iVar15,&LAB_00404e30);

      uVar12 = extraout_var_00;

    }

    sVar10 = (short)s___AVCVOGDialog___00af8e58[0x11];

    uVar19 = CONCAT44(puVar9,puStack_488);

    puVar9[2] = 0xff;

    puVar9[1] = 0;

    *puVar9 = 0;

    puVar9[3] = 0xff;

    puVar9[6] = 0;

    puVar9[5] = 0x80;

    puVar9[4] = 0x36;

    puVar9[7] = 0xff;

    uVar18 = CONCAT44(piVar13,CONCAT22(uVar12,sVar10));

    goto LAB_00958fc6;

  case 'w':

LAB_009583df:

    if ((piVar13 != (int *)0x0) && (piVar13[2] != 0)) {

      (**(code **)(*piVar13 + 0x40))();

      FUN_00404cb0();

    }

    break;

  case 'x':

    iVar15 = *(int *)(*(int *)(param_1 + 0xe04) + 0xe4e8);

    uVar11 = 0;

    iStack_4c4 = 0;

    iVar14 = 0;

    while ((*(int *)(iVar15 + 0x2c) != 0 &&

           (uVar11 < (uint)(*(int *)(iVar15 + 0x30) - *(int *)(iVar15 + 0x2c) >> 2)))) {

      if (*(int *)(*(int *)(*(int *)(*(int *)(iVar15 + 0x2c) + uVar11 * 4) + 0xa8) + 0x38) == 0xe) {

        iStack_4c4 = iStack_4c4 + 1;

        uVar11 = uVar11 + 1;

      }

      else {

        if (*(int *)(*(int *)(*(int *)(*(int *)(iVar15 + 0x2c) + uVar11 * 4) + 0xa8) + 0x38) == 0x12

           ) {

          iVar14 = iVar14 + 1;

        }

        uVar11 = uVar11 + 1;

      }

    }

    if (*(int *)(iVar15 + 0x2c) == 0) {

      iVar15 = 0;

    }

    else {

      iVar15 = *(int *)(iVar15 + 0x30) - *(int *)(iVar15 + 0x2c) >> 2;

    }

    sprintf(acStack_428,"%-30s enemies:%d creatures:%d vehicles: %d","Living report:",iVar15,iVar14,

            iStack_4c4);

LAB_00958a7c:

    if (DAT_00d1b8dc != 0) {

      FUN_008f8200();

    }

    break;

  case 'y':

    (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) + 4 +

                         *(int *)(param_1 + 0xe98)) + 0x19c))();

    FUN_007fdab0();

    FUN_007fe2c0();

    FUN_00802f30(4,0);

    FUN_00802f00(5,0);

    FUN_00802f00(6,0);

    FUN_00802ed0(7,0);

    FUN_00802ea0(8,0);

    break;

  case 'z':

    LStack_4a0.s.LowPart = DAT_00aaaca8;

    LStack_4a0.s.HighPart = 0;

    DStack_498 = DAT_00aaaca8;

    uStack_494 = 0;

    FUN_007fe460();

    LStack_4a0.s.LowPart = DAT_00aaaca8;

    LStack_4a0.s.HighPart = 0;

    DStack_498 = DAT_00aaaab4;

    uStack_494 = 0;

    FUN_007fe460();

    LStack_4a0.s.LowPart = DAT_00aaaca8;

    LStack_4a0.s.HighPart = 0;

    DStack_498 = DAT_00aaacd0;

    uStack_494 = 0;

    FUN_007fe460();

    iVar15 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) + 4 +

                                  *(int *)(param_1 + 0xe98)) + 0x19c))();

    if (iVar15 != 0) {

      iVar15 = *(int *)(*(int *)(iVar15 + 4) + 4) + 4 + iVar15;

    }

    FUN_007fe310(param_1,3,0,2,0xffffff00,iVar15);

    FUN_00803050(4,0,"test1","title2");

    FUN_00802ff0();

    FUN_00802ff0();

    FUN_00802fa0();

    puStack_488 = operator_new__(s___AVCVOGDialog___00af8e58[0x12] * 4);

    *puStack_488 = 0x36;

    puStack_488[1] = 0x15e;

    piVar13 = operator_new__(0x10);

    pvVar8 = operator_new__(0x100);

    *piVar13 = (int)pvVar8;

    pvVar8 = operator_new__(0x100);

    puVar4 = (uint32_t /* width from decompiler */ *)*piVar13;

    piVar13[1] = (int)pvVar8;

    *puVar4 = DAT_00a28ca4;

    *(uint16_t *)(puVar4 + 1) = DAT_00a28ca8;

    *(uint8_t *)((int)puVar4 + 6) = DAT_00a28caa;

    puVar4 = (uint32_t /* width from decompiler */ *)piVar13[1];

    *puVar4 = DAT_00a28c9c;

    *(uint16_t *)(puVar4 + 1) = DAT_00a28ca0;

    *(uint8_t *)((int)puVar4 + 6) = DAT_00a28ca2;

    iVar15 = (int)s___AVCVOGDialog___00af8e58[0x12];

    puVar9 = operator_new__(iVar15 * 4);

    uStack_14 = 0;

    if (puVar9 == (uint8_t *)0x0) {

      puVar9 = (uint8_t *)0x0;

    }

    else {

      FUN_00404d80(puVar9,4,iVar15,&LAB_00404e30);

    }

    puVar9[2] = 0xff;

    puVar9[1] = 0;

    *puVar9 = 0;

    puVar9[3] = 0xff;

    puVar9[6] = 0;

    puVar9[5] = 0x80;

    puVar9[4] = 0x36;

    puVar9[7] = 0xff;

    uVar19 = CONCAT44(puVar9,puStack_488);

    uVar18 = CONCAT44(piVar13,CONCAT22((short)((uint)puVar9 >> 0x10),

                                       (short)s___AVCVOGDialog___00af8e58[0x12]));

LAB_00958fc6:

    uStack_14 = 0xffffffff;

    FUN_00802f60(8,0,uVar18,uVar19);

  }

  ExceptionList = pvStack_1c;

  return 1;

}
