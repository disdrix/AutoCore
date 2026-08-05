// =============================================================================
// FUN_0084d220
// -----------------------------------------------------------------------------
// Stable ID: aa_0084d220
// Address:   0x0084d220  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0084d220 @ 0x0084d220
// Stable ID: aa_0084d220
// Embedded strings (evidence for future rename):
//   - "Requires Minimum Level of"
//   - "%s %d\n"
//   - "Requires: "
//   - "%d %s"
//   - "This discipline needs to be unlocked by a skill trainer!\n"
//   - "Current Rank:"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~195 non-empty decompiler lines.
//  - Control keywords: if×29, return×2.
//  - Notable callees: FUN_007a6de0×13, FUN_0052ada0×11, FUN_0052b040×10, sprintf×7, FUN_00402d50×5, free×5, FUN_0052ad60, FUN_0052b140.
//  - Strings: "Requires Minimum Level of"; "%s %d\n"; "Requires: "; "%d %s".
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

void __thiscall FUN_0084d220(uint32_t /* width from decompiler */ *param_1,char param_2)



{

  short sVar1;

  uint uVar2;

  char cVar3;

  char cVar4;

  int *_Memory;

  int iVar5;

  int iVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ *puVar9;

  int unaff_EBX;

  int *unaff_EDI;

  int aiStack_58c [32];

  char acStack_50c [8];

  char acStack_504 [248];

  uint32_t /* width from decompiler */ auStack_40c [10];

  uint8_t auStack_3e2 [474];

  uint8_t auStack_208 [508];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009abc41;

  local_c = ExceptionList;

  if (((unaff_EDI != (int *)0x0) && (param_1 != (uint32_t /* width from decompiler */ *)0x0)) && (DAT_00d1b6d8 != 0)) {

    ExceptionList = &local_c;

    FUN_007a69d0();

    (**(code **)(*unaff_EDI + 0x268))();

    cVar3 = FUN_0052b140(*param_1);

    _Memory = (int *)FUN_0052ada0(*param_1);

    iVar5 = FUN_0052ad60(*param_1);

    if ((param_2 != '\0') || (cVar3 == '\0')) {

      sVar1 = *(short *)((int)param_1 + 0x26);

      if ((0 < sVar1) &&

         ((param_2 != '\0' ||

          (iVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8

                                        ) + 0x27c))(), iVar6 < sVar1)))) {

        iVar6 = (int)sVar1;

        uVar7 = FUN_007a6de0("Requires Minimum Level of",0xffffffff);

        sprintf(acStack_504,"%s %d\n",uVar7,iVar6);

        (**(code **)(*unaff_EDI + 0x22c))(acStack_504,DAT_00afdb24);

      }

      uVar2 = param_1[2];

      cVar4 = uVar2 < 0x80000000;

      if (-1 < (int)param_1[3]) {

        cVar4 = cVar4 + '\x01';

      }

      if (-1 < (int)param_1[4]) {

        cVar4 = cVar4 + '\x01';

      }

      if (-1 < (int)param_1[5]) {

        cVar4 = cVar4 + '\x01';

      }

      if (-1 < (int)param_1[6]) {

        cVar4 = cVar4 + '\x01';

      }

      if (((((cVar4 != '\0') &&

            (((uVar2 == 0xffffffff || (cVar4 = FUN_0052b040(uVar2,auStack_208), cVar4 == '\0')) ||

             (iVar6 = FUN_0052ada0(param_1[2]), iVar6 < *(short *)(param_1 + 7))))) &&

           (((param_1[3] == -1 || (cVar4 = FUN_0052b040(param_1[3],auStack_208), cVar4 == '\0')) ||

            (iVar6 = FUN_0052ada0(param_1[3]), iVar6 < *(short *)((int)param_1 + 0x1e))))) &&

          (((param_1[4] == -1 || (cVar4 = FUN_0052b040(param_1[4],auStack_208), cVar4 == '\0')) ||

           (iVar6 = FUN_0052ada0(param_1[4]), iVar6 < *(short *)(param_1 + 8))))) &&

         ((((param_1[5] == -1 || (cVar4 = FUN_0052b040(param_1[5],auStack_208), cVar4 == '\0')) ||

           (iVar6 = FUN_0052ada0(param_1[5]), iVar6 < *(short *)((int)param_1 + 0x22))) &&

          (((param_1[6] == -1 || (cVar4 = FUN_0052b040(param_1[6],auStack_208), cVar4 == '\0')) ||

           (iVar6 = FUN_0052ada0(param_1[6]), iVar6 < *(short *)(param_1 + 9))))))) {

        aiStack_58c[0] = *unaff_EDI;

        uVar7 = DAT_00afdb24;

        uVar8 = FUN_007a6de0("Requires: ",0xffffffff);

        (**(code **)(aiStack_58c[0] + 0x22c))(uVar8,uVar7);

        if ((-1 < (int)param_1[2]) && (cVar4 = FUN_0052b040(param_1[2],auStack_40c), cVar4 != '\0'))

        {

          unaff_EBX = unaff_EBX + -1;

          if (((char)uStack_4 != '\0') ||

             (iVar6 = FUN_0052ada0(auStack_40c[0]), iVar6 < *(short *)(param_1 + 7))) {

            puVar9 = (uint32_t /* width from decompiler */ *)FUN_00402d50(auStack_3e2);

            local_c = (void *)0x0;

            uVar7 = FUN_007a6de0(*puVar9,0xffffffff);

            sprintf(acStack_50c,"%d %s",(int)*(short *)(param_1 + 7),uVar7);

            local_c = (void *)0xffffffff;

            if (_Memory != aiStack_58c) {

              free(_Memory);

            }

            (**(code **)(*unaff_EDI + 0x22c))(acStack_50c,DAT_00afdb24);

            if (0 < unaff_EBX) {

              iVar6 = *unaff_EDI;

              uVar7 = DAT_00afdb24;

              uVar8 = FUN_007a6de0(&DAT_00a692b8,0xffffffff);

              (**(code **)(iVar6 + 0x22c))(uVar8,uVar7);

            }

          }

        }

        if ((-1 < (int)param_1[3]) && (cVar4 = FUN_0052b040(param_1[3],auStack_40c), cVar4 != '\0'))

        {

          unaff_EBX = unaff_EBX + -1;

          if (((char)uStack_4 != '\0') ||

             (iVar6 = FUN_0052ada0(auStack_40c[0]), iVar6 < *(short *)((int)param_1 + 0x1e))) {

            puVar9 = (uint32_t /* width from decompiler */ *)FUN_00402d50(auStack_3e2);

            local_c = (void *)0x1;

            uVar7 = FUN_007a6de0(*puVar9,0xffffffff);

            sprintf(acStack_50c,"%d %s",(int)*(short *)((int)param_1 + 0x1e),uVar7);

            local_c = (void *)0xffffffff;

            if (_Memory != aiStack_58c) {

              free(_Memory);

            }

            (**(code **)(*unaff_EDI + 0x22c))(acStack_50c,DAT_00afdb24);

            if (0 < unaff_EBX) {

              iVar6 = *unaff_EDI;

              uVar7 = DAT_00afdb24;

              uVar8 = FUN_007a6de0(&DAT_00a692b8,0xffffffff);

              (**(code **)(iVar6 + 0x22c))(uVar8,uVar7);

            }

          }

        }

        if ((-1 < (int)param_1[4]) && (cVar4 = FUN_0052b040(param_1[4],auStack_40c), cVar4 != '\0'))

        {

          unaff_EBX = unaff_EBX + -1;

          if (((char)uStack_4 != '\0') ||

             (iVar6 = FUN_0052ada0(auStack_40c[0]), iVar6 < *(short *)(param_1 + 8))) {

            puVar9 = (uint32_t /* width from decompiler */ *)FUN_00402d50(auStack_3e2);

            local_c = (void *)0x2;

            uVar7 = FUN_007a6de0(*puVar9,0xffffffff);

            sprintf(acStack_50c,"%d %s",(int)*(short *)(param_1 + 8),uVar7);

            local_c = (void *)0xffffffff;

            if (_Memory != aiStack_58c) {

              free(_Memory);

            }

            (**(code **)(*unaff_EDI + 0x22c))(acStack_50c,DAT_00afdb24);

            if (0 < unaff_EBX) {

              iVar6 = *unaff_EDI;

              uVar7 = DAT_00afdb24;

              uVar8 = FUN_007a6de0(&DAT_00a692b8,0xffffffff);

              (**(code **)(iVar6 + 0x22c))(uVar8,uVar7);

            }

          }

        }

        if ((-1 < (int)param_1[5]) && (cVar4 = FUN_0052b040(param_1[5],auStack_40c), cVar4 != '\0'))

        {

          if (((char)uStack_4 != '\0') ||

             (iVar6 = FUN_0052ada0(auStack_40c[0]), iVar6 < *(short *)((int)param_1 + 0x22))) {

            puVar9 = (uint32_t /* width from decompiler */ *)FUN_00402d50(auStack_3e2);

            local_c = (void *)0x3;

            uVar7 = FUN_007a6de0(*puVar9,0xffffffff);

            sprintf(acStack_50c,"%d %s",(int)*(short *)((int)param_1 + 0x22),uVar7);

            local_c = (void *)0xffffffff;

            if (_Memory != aiStack_58c) {

              free(_Memory);

            }

            (**(code **)(*unaff_EDI + 0x22c))(acStack_50c,DAT_00afdb24);

            if (unaff_EBX != 1 && -1 < unaff_EBX + -1) {

              iVar6 = *unaff_EDI;

              uVar7 = DAT_00afdb24;

              uVar8 = FUN_007a6de0(&DAT_00a692b8,0xffffffff);

              (**(code **)(iVar6 + 0x22c))(uVar8,uVar7);

            }

          }

        }

        if (((-1 < (int)param_1[6]) && (cVar4 = FUN_0052b040(param_1[6],auStack_40c), cVar4 != '\0')

            ) && (((char)uStack_4 != '\0' ||

                  (iVar6 = FUN_0052ada0(auStack_40c[0]), iVar6 < *(short *)(param_1 + 9))))) {

          puVar9 = (uint32_t /* width from decompiler */ *)FUN_00402d50(auStack_3e2);

          local_c = (void *)0x4;

          uVar7 = FUN_007a6de0(*puVar9,0xffffffff);

          sprintf(acStack_50c,"%d %s",(int)*(short *)(param_1 + 9),uVar7);

          local_c = (void *)0xffffffff;

          if (_Memory != aiStack_58c) {

            free(_Memory);

          }

          (**(code **)(*unaff_EDI + 0x22c))(acStack_50c,DAT_00afdb24);

        }

        (**(code **)(*unaff_EDI + 0x250))(&DAT_00a15104);

      }

      if (cVar3 == '\0') {

        ExceptionList = local_c;

        return;

      }

    }

    if (iVar5 == 0) {

      iVar6 = *unaff_EDI;

      uVar7 = DAT_00afdb28;

      uVar8 = FUN_007a6de0("This discipline needs to be unlocked by a skill trainer!\n",0xffffffff);

      (**(code **)(iVar6 + 0x22c))(uVar8,uVar7);

    }

    if ((cVar3 != '\0') && (0 < iVar5)) {

      uVar7 = FUN_007a6de0("Current Rank:",0xffffffff);

      sprintf(acStack_504,"%s  %d / %d\n",uVar7,_Memory,iVar5);

      (**(code **)(*unaff_EDI + 0x22c))(acStack_504,DAT_00afdb2c);

    }

  }

  ExceptionList = local_c;

  return;

}
