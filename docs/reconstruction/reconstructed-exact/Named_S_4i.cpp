// =============================================================================
// Named_S_4i
// -----------------------------------------------------------------------------
// Stable ID: aa_008f2a00
// Address:   0x008f2a00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_S_4i @ 0x008f2a00
// Stable ID: aa_008f2a00
// Embedded strings (evidence for future rename):
//   - "%.2i/%.2i/%.4i"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~196 non-empty decompiler lines.
//  - Control keywords: if×21, while×3, return×2, do×2, goto×1, for×1.
//  - Notable callees: CNDHash_LookupByKey×2, sprintf×2, Client_LookupObjectByTfid_Inferred, FUN_00402d50, FUN_0040deb0, FUN_004c21e0, FUN_004f1e20, FUN_0051fa10.
//  - Strings: "%.2i/%.2i/%.4i".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "%.2i/%.2i/%.4i"
 * Domain alias of FUN_008f2a00 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_S_4i(int *param_1)



{

  uint *puVar1;

  int *piVar2;

  char cVar3;

  int iVar4;

  char *pcVar5;

  void *pvVar6;

  uint32_t /* width from decompiler */ uVar7;

  char *pcVar8;

  tm *ptVar9;

  uint32_t /* width from decompiler */ *puVar10;

  uint16_t *puVar11;

  int *unaff_EDI;

  int *piVar12;

  uint key;

  int iStack_234;

  uint8_t auStack_230 [4];

  void *pvStack_22c;

  uint32_t /* width from decompiler */ uStack_228;

  uint32_t /* width from decompiler */ uStack_224;

  uint32_t /* width from decompiler */ uStack_220;

  char acStack_21c [252];

  char acStack_120 [2];

  uint32_t /* width from decompiler */ auStack_11e [32];

  uint8_t *puStack_9c;

  uint8_t auStack_98 [132];

  void *pvStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0xffffffff;

  puStack_10 = &LAB_009ad2fb;

  pvStack_14 = ExceptionList;

  ExceptionList = &pvStack_14;

  cVar3 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar3 != '\0') {

    if (param_1[0x14a] != 0) {

      if (DAT_00d1da30 == (int *)0x0) {

        (**(code **)(*(int *)param_1[0x14a] + 0x1d8))(0,1,1);

      }

      else {

        (**(code **)(*(int *)param_1[0x14a] + 0x1d8))(DAT_00d1da30 + 1);

      }

      (**(code **)(*(int *)param_1[0x14a] + 0x34c))();

    }

    FUN_008f2870();

    piVar2 = DAT_00d1da30;

    if (((DAT_00d1da30 != (int *)0x0) && (*DAT_00d1da30 != -1)) && (DAT_00d1b6d8 != 0)) {

      iStack_234 = 0;

      piVar12 = DAT_00d1da30;

      while( true ) {

        if (piVar12[0x79] == 0) {

          iVar4 = 0;

        }

        else {

          iVar4 = piVar12[0x7a] - piVar12[0x79] >> 2;

        }

        if (iVar4 <= iStack_234) break;

        iVar4 = FUN_0040deb0(auStack_230);

        puVar1 = *(uint **)(*(int *)(iVar4 + 4) + iStack_234 * 4);

        uStack_c = 0xffffffff;

        if (pvStack_22c != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(pvStack_22c);

        }

        pvStack_22c = (void *)0x0;

        uStack_228 = 0;

        uStack_224 = 0;

        if (param_1[0x159] != 0) {

          (**(code **)(*(int *)param_1[0x159] + 0x444))(puVar1 + 2,*puVar1,puVar1[1],0);

          (**(code **)(*(int *)param_1[0x159] + 0x464))

                    (*puVar1,puVar1[1],1,&DAT_00d1e464 + puVar1[9] * 4);

        }

        if (param_1[0x15a] != 0) {

          pcVar5 = (char *)FUN_004c21e0(puVar1[9]);

          if ((pcVar5 == (char *)0x0) || (*pcVar5 == '\0')) {

            (**(code **)(*(int *)param_1[0x15a] + 0x444))(&DAT_00a2a000,*puVar1,puVar1[1],1);

          }

          else {

            (**(code **)(*(int *)param_1[0x15a] + 0x444))(pcVar5,*puVar1,puVar1[1],1);

            piVar12 = unaff_EDI;

          }

          (**(code **)(*(int *)param_1[0x15a] + 0x464))

                    (*puVar1,puVar1[1],1,&DAT_00d1e464 + puVar1[9] * 4);

        }

        if (param_1[0x15b] != 0) {

          if (((char)puVar1[0xd] == '\0') ||

             (pvVar6 = Client_LookupObjectByTfid_Inferred(1,*puVar1,puVar1[1]),

             pvVar6 == (void *)0x0)) {

            uVar7 = FUN_0052c8b0(puVar1[8]);

          }

          else {

            uVar7 = (**(code **)(*(int *)(*(int *)(*(int *)((int)pvVar6 + 4) + 4) + 4 + (int)pvVar6)

                                + 0x27c))();

          }

          sprintf((char *)&uStack_220,"%i",uVar7);

          (**(code **)(*(int *)param_1[0x15b] + 0x444))(&uStack_220,*puVar1,puVar1[1],1);

          (**(code **)(*(int *)param_1[0x15b] + 0x464))

                    (*puVar1,puVar1[1],1,&DAT_00d1e464 + puVar1[9] * 4);

        }

        if (param_1[0x15c] != 0) {

          pvVar6 = CNDHash_LookupByKey(*(void **)(DAT_00d1b570 + 0xf10),puVar1[0xc]);

          if (pvVar6 == (void *)0x0) {

LAB_008f2ce8:

            uStack_220._0_2_ = 0x3f;

          }

          else {

            FUN_004f1e20(0,1);

            if (*(int *)((int)pvVar6 + 0x3c) == 0) goto LAB_008f2ce8;

            pcVar8 = (char *)FUN_0051fa10(*(uint8_t *)(*(int *)((int)pvVar6 + 0x3c) + 0x531),

                                          *(uint8_t *)

                                           (*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) +

                                                                      4) + 0xac + DAT_00d1b6d8) +

                                                    0x3c) + 0x532));

            pcVar5 = (char *)&uStack_220;

            do {

              cVar3 = *pcVar8;

              *pcVar5 = cVar3;

              pcVar8 = pcVar8 + 1;

              pcVar5 = pcVar5 + 1;

            } while (cVar3 != '\0');

          }

          (**(code **)(*(int *)param_1[0x15c] + 0x444))(&uStack_220,*puVar1,puVar1[1],1);

          (**(code **)(*(int *)param_1[0x15c] + 0x464))

                    (*puVar1,puVar1[1],1,&DAT_00d1e464 + puVar1[9] * 4);

          piVar12 = piVar2;

        }

        if (param_1[0x15d] != 0) {

          acStack_120[0] = '\0';

          acStack_120[1] = '\0';

          puVar10 = auStack_11e;

          for (iVar4 = 0x1f; iVar4 != 0; iVar4 = iVar4 + -1) {

            *puVar10 = 0;

            puVar10 = puVar10 + 1;

          }

          *(uint16_t *)puVar10 = 0;

          _time64((__time64_t *)(puVar1 + 0xe));

          ptVar9 = _localtime64((__time64_t *)(puVar1 + 0xe));

          sprintf(acStack_120,"%.2i/%.2i/%.4i",ptVar9->tm_mon + 1,ptVar9->tm_mday,

                  ptVar9->tm_year + 0x76c);

          (**(code **)(*(int *)param_1[0x15d] + 0x444))(acStack_120,*puVar1,puVar1[1],1);

          (**(code **)(*(int *)param_1[0x15d] + 0x464))

                    (*puVar1,puVar1[1],1,&DAT_00d1e464 + puVar1[9] * 4);

          piVar12 = piVar2;

        }

        if (param_1[0x15e] != 0) {

          key = puVar1[7];

          pvVar6 = (void *)FUN_00541a80();

          pvVar6 = CNDHash_LookupByKey(pvVar6,key);

          if (pvVar6 == (void *)0x0) {

            uStack_220._0_1_ = s_Unknown_00a37c4c[0];

            uStack_220._1_1_ = s_Unknown_00a37c4c[1];

            uStack_220._2_1_ = s_Unknown_00a37c4c[2];

            uStack_220._3_1_ = s_Unknown_00a37c4c[3];

            acStack_21c[0] = s_Unknown_00a37c4c[4];

            acStack_21c[1] = s_Unknown_00a37c4c[5];

            acStack_21c[2] = s_Unknown_00a37c4c[6];

            acStack_21c[3] = s_Unknown_00a37c4c[7];

          }

          else {

            puVar10 = (uint32_t /* width from decompiler */ *)FUN_00402d50((int)pvVar6 + 0xb4);

            pcVar8 = (char *)*puVar10;

            pcVar5 = (char *)&uStack_220;

            do {

              cVar3 = *pcVar8;

              *pcVar5 = cVar3;

              pcVar8 = pcVar8 + 1;

              pcVar5 = pcVar5 + 1;

            } while (cVar3 != '\0');

            uStack_c = 0xffffffff;

            if (puStack_9c != auStack_98) {

              free(puStack_9c);

            }

          }

          (**(code **)(*(int *)param_1[0x15e] + 0x444))(&uStack_220,*puVar1,puVar1[1],1);

          (**(code **)(*(int *)param_1[0x15e] + 0x464))

                    (*puVar1,puVar1[1],1,&DAT_00d1e464 + puVar1[9] * 4);

        }

        if (param_1[0x15f] != 0) {

          puVar11 = (uint16_t *)&DAT_00a37480;

          if ((char)puVar1[0xd] == '\0') {

            puVar11 = &DAT_00a3747c;

          }

          (**(code **)(*(int *)param_1[0x15f] + 0x444))(puVar11,*puVar1,puVar1[1],1);

          (**(code **)(*(int *)param_1[0x15f] + 0x464))

                    (*puVar1,puVar1[1],1,&DAT_00d1e464 + puVar1[9] * 4);

          piVar12 = piVar2;

        }

        iStack_234 = iStack_234 + 1;

      }

    }

    FUN_007fbd30();

  }

  ExceptionList = pvStack_14;

  return;

}
