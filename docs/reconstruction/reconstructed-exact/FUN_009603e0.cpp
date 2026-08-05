// =============================================================================
// FUN_009603e0
// -----------------------------------------------------------------------------
// Stable ID: aa_009603e0
// Address:   0x009603e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009603e0 @ 0x009603e0
// Stable ID: aa_009603e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~556 non-empty decompiler lines.
//  - Control keywords: if×53, while×15, return×14, do×13, for×4, switch×1, goto×1.
//  - Notable callees: CONCAT31×11, FUN_0046d4e0×5, FUN_00437050×4, FUN_00768760×4, FUN_0095dae0×4, FUN_0095f990×4, FUN_00436f10×3, FUN_00439a00×3.
//  - Return sites: 14.

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

uint FUN_009603e0(int param_1,int param_2,uint8_t **param_3)



{

  int iVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint uVar4;

  int *piVar5;

  uint8_t *puVar6;

  int iVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ *puVar9;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbStack_b4;

  uint8_t **ppuStack_b0;

  uint8_t *puStack_94;

  uint8_t *puStack_90;

  uint uStack_8c;

  uint8_t *puStack_88;

  uint8_t *puStack_84;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_80 [4];

  uint32_t /* width from decompiler */ *puStack_7c;

  uint32_t /* width from decompiler */ *puStack_78;

  uint32_t /* width from decompiler */ uStack_74;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_64 [4];

  uint32_t /* width from decompiler */ *puStack_60;

  uint32_t /* width from decompiler */ *puStack_5c;

  uint32_t /* width from decompiler */ uStack_58;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_48 [4];

  void *pvStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  char local_24;

  int local_20;

  uint32_t /* width from decompiler */ local_1c;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b3d52;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkReader_EnterChunkScope();

  local_4 = 0;

  if (local_20 == 0x534b4e4d) {

    local_4._1_3_ = 0;

    switch(local_1c) {

    case 1:

      uStack_8c = 0;

      puStack_7c = (void *)0x0;

      puStack_78 = (uint32_t /* width from decompiler */ *)0x0;

      uStack_74 = 0;

      local_4._0_1_ = 1;

      ppuStack_b0 = (uint8_t **)0x96047e;

      FUN_0095dae0();

      puStack_60 = (void *)0x0;

      puStack_5c = (uint32_t /* width from decompiler */ *)0x0;

      uStack_58 = 0;

      local_4 = CONCAT31(local_4._1_3_,2);

      FUN_0046a830();

      FUN_00439a00();

      FUN_0046d4e0();

      if (0 < (int)puStack_94) {

        puStack_90 = puStack_94;

        do {

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_48);

          local_4 = CONCAT31(local_4._1_3_,3);

          if (*(int *)(param_1 + 0x4044) == 0) {

            FUN_00436f10();

          }

          else {

            FUN_0076a200();

          }

          ppuStack_b0 = (uint8_t **)0x960529;

          FUN_00989e00();

          FUN_0044cb20();

          local_4 = CONCAT31(local_4._1_3_,2);

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_48);

          puStack_90 = puStack_90 + -1;

        } while (puStack_90 != (uint8_t *)0x0);

      }

      FUN_00437b60();

      puVar6 = param_3[1];

      if (puVar6 == (uint8_t *)0x0) {

        uVar4 = 0;

      }

      else {

        uVar4 = (int)param_3[2] - (int)puVar6 >> 2;

      }

      if ((*(int *)(param_2 + 4) != 0) &&

         (uVar4 < (uint)(*(int *)(param_2 + 8) - *(int *)(param_2 + 4) >> 2))) {

        if (puVar6 == (uint8_t *)0x0) {

          uVar4 = 0;

        }

        else {

          uVar4 = (int)param_3[2] - (int)puVar6 >> 2;

        }

        FUN_00456780();

        while ((*(int *)(param_2 + 4) != 0 &&

               (uVar4 < (uint)(*(int *)(param_2 + 8) - *(int *)(param_2 + 4) >> 2)))) {

          puVar3 = (uint32_t /* width from decompiler */ *)FUN_0043f780();

          if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) {

            *(uint32_t /* width from decompiler */ *)(param_3[1] + uVar4 * 4) = 0;

            uVar4 = uVar4 + 1;

          }

          else {

            puVar8 = &DAT_00afdf70;

            puVar9 = puVar3;

            for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {

              *puVar9 = *puVar8;

              puVar8 = puVar8 + 1;

              puVar9 = puVar9 + 1;

            }

            *(uint32_t /* width from decompiler */ **)(param_3[1] + uVar4 * 4) = puVar3;

            uVar4 = uVar4 + 1;

          }

        }

      }

      ppuStack_b0 = (uint8_t **)&uStack_8c;

      pbStack_b4 = abStack_64;

      FUN_0095f990();

      puVar3 = puStack_60;

      if (puStack_60 == (void *)0x0) {

        if (puStack_7c == (void *)0x0) {

          local_4 = 0xffffffff;

          if (local_24 != '\0') {

            FUN_00769e40();

          }

          ExceptionList = local_c;

          return 0;

        }

                    /* WARNING: Subroutine does not return */

        operator_delete(puStack_7c);

      }

      FUN_00426f20();

                    /* WARNING: Subroutine does not return */

      ppuStack_b0 = (uint8_t **)&UNK_00960662;

      operator_delete(puVar3);

    case 2:

      puStack_94 = (uint8_t *)0x0;

      pvStack_44 = (void *)0x0;

      uStack_40 = 0;

      uStack_3c = 0;

      local_4._0_1_ = 4;

      ppuStack_b0 = (uint8_t **)0x9606ca;

      uVar4 = FUN_0095dae0();

      uVar2 = FUN_00439a00();

      puVar6 = puStack_90;

      uVar4 = uVar4 | uVar2;

      puStack_7c = (uint32_t /* width from decompiler */ *)0x0;

      puStack_78 = (uint32_t /* width from decompiler */ *)0x0;

      uStack_74 = 0;

      local_4 = CONCAT31(local_4._1_3_,5);

      FUN_0046a8d0();

      if ((1 < (int)puVar6) && (0 < (int)puVar6)) {

        puStack_88 = puVar6;

        do {

          if (*(int *)(param_1 + 0x4044) == 0) {

            puStack_84 = (uint8_t *)FUN_00437050();

          }

          else {

            puStack_84 = (uint8_t *)FUN_00768760();

          }

          ppuStack_b0 = (uint8_t **)0x960746;

          FUN_00410420();

          uVar2 = FUN_0046b3c0();

          uVar4 = uVar4 | uVar2 | (uint)puStack_84;

          puStack_88 = puStack_88 + -1;

        } while (puStack_88 != (uint8_t *)0x0);

      }

      if (*(int *)(param_1 + 0x4044) == 0) {

        uStack_8c = FUN_00437050();

      }

      else {

        uStack_8c = FUN_00768760();

      }

      puVar6 = puStack_88;

      uStack_8c = uVar4 | uStack_8c;

      FUN_0046d4e0();

      if (0 < (int)puVar6) {

        do {

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_64);

          local_4 = CONCAT31(local_4._1_3_,6);

          if (*(int *)(param_1 + 0x4044) == 0) {

            FUN_00436f10();

          }

          else {

            FUN_0076a200();

          }

          ppuStack_b0 = (uint8_t **)0x9607f7;

          FUN_00989e00();

          FUN_0044cb20();

          local_4 = CONCAT31(local_4._1_3_,5);

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_64);

          puVar6 = puVar6 + -1;

        } while (puVar6 != (uint8_t *)0x0);

      }

      puVar6 = param_3[1];

      if (puVar6 == (uint8_t *)0x0) {

        uVar4 = 0;

      }

      else {

        uVar4 = (int)param_3[2] - (int)puVar6 >> 2;

      }

      if ((*(int *)(param_2 + 4) != 0) &&

         (uVar4 < (uint)(*(int *)(param_2 + 8) - *(int *)(param_2 + 4) >> 2))) {

        if (puVar6 == (uint8_t *)0x0) {

          uVar4 = 0;

        }

        else {

          uVar4 = (int)param_3[2] - (int)puVar6 >> 2;

        }

        FUN_00456780();

        while ((*(int *)(param_2 + 4) != 0 &&

               (uVar4 < (uint)(*(int *)(param_2 + 8) - *(int *)(param_2 + 4) >> 2)))) {

          puVar3 = (uint32_t /* width from decompiler */ *)FUN_0043f780();

          if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) {

            *(uint32_t /* width from decompiler */ *)(param_3[1] + uVar4 * 4) = 0;

            uVar4 = uVar4 + 1;

          }

          else {

            puVar8 = &DAT_00afdf70;

            puVar9 = puVar3;

            for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {

              *puVar9 = *puVar8;

              puVar8 = puVar8 + 1;

              puVar9 = puVar9 + 1;

            }

            *(uint32_t /* width from decompiler */ **)(param_3[1] + uVar4 * 4) = puVar3;

            uVar4 = uVar4 + 1;

          }

        }

      }

      puVar6 = puStack_90;

      puStack_60 = (uint32_t /* width from decompiler */ *)0x0;

      puStack_5c = (uint32_t /* width from decompiler */ *)0x0;

      uStack_58 = 0;

      local_4 = CONCAT31(local_4._1_3_,7);

      puStack_88 = (uint8_t *)&pbStack_b4;

      ppuStack_b0 = (uint8_t **)0x0;

      FUN_0046a970(puStack_90);

      if (puVar6 == (uint8_t *)0x1) {

        FUN_00437b60();

      }

      else if (0 < (int)puVar6) {

        puStack_84 = (uint8_t *)((int)puStack_60 - (int)puStack_7c);

        piVar5 = puStack_7c + 1;

        puStack_88 = puVar6;

        puVar3 = puStack_60;

        do {

          if (*piVar5 == 0) {

            puStack_90 = (uint8_t *)0x0;

          }

          else {

            puStack_90 = (uint8_t *)(piVar5[1] - *piVar5 >> 2);

          }

          puVar6 = puStack_90;

          FUN_0046d4e0();

          iVar7 = 0;

          if (0 < (int)puVar6) {

            do {

              iVar1 = *(int *)(puStack_84 + (int)piVar5);

              if ((iVar1 == 0) || ((uint)(puVar3[3] - iVar1 >> 2) <= (uint)(puVar3[2] - iVar1 >> 2))

                 ) {

                ppuStack_b0 = (uint8_t **)puVar3[2];

                pbStack_b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                              *)&LAB_009609c9;

                FUN_00463e30();

              }

              else {

                iVar1 = puVar3[2];

                FUN_00436ef0();

                puVar3[2] = iVar1 + 4;

              }

              iVar7 = iVar7 + 1;

            } while (iVar7 < (int)puStack_90);

          }

          piVar5 = piVar5 + 4;

          puVar3 = puVar3 + 4;

          puStack_88 = puStack_88 + -1;

        } while (puStack_88 != (uint8_t *)0x0);

      }

      ppuStack_b0 = &puStack_94;

      pbStack_b4 = abStack_64;

      uVar4 = FUN_0095f990();

      uStack_8c = uStack_8c | uVar4;

      if (puStack_60 != (uint32_t /* width from decompiler */ *)0x0) {

        if (puStack_60 != puStack_5c) {

          puVar3 = puStack_60 + 1;

          do {

            if ((void *)*puVar3 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

              operator_delete((void *)*puVar3);

            }

            *puVar3 = 0;

            puVar3[1] = 0;

            puVar3[2] = 0;

            puVar8 = puVar3 + 3;

            puVar3 = puVar3 + 4;

          } while (puVar8 != puStack_5c);

        }

                    /* WARNING: Subroutine does not return */

        operator_delete(puStack_60);

      }

      if (puStack_7c != (uint32_t /* width from decompiler */ *)0x0) {

        if (puStack_7c != puStack_78) {

          puVar3 = puStack_7c + 1;

          do {

            if ((void *)*puVar3 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

              operator_delete((void *)*puVar3);

            }

            *puVar3 = 0;

            puVar3[1] = 0;

            puVar3[2] = 0;

            puVar8 = puVar3 + 3;

            puVar3 = puVar3 + 4;

          } while (puVar8 != puStack_78);

        }

                    /* WARNING: Subroutine does not return */

        operator_delete(puStack_7c);

      }

      if (pvStack_44 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvStack_44);

      }

      break;

    case 3:

      puStack_84 = (uint8_t *)0x0;

      pvStack_44 = (void *)0x0;

      uStack_40 = 0;

      uStack_3c = 0;

      local_4._0_1_ = 8;

      ppuStack_b0 = (uint8_t **)0x960ad1;

      uVar4 = FUN_0095dae0();

      uStack_8c = FUN_00439a00();

      puVar6 = puStack_90;

      uStack_8c = uVar4 | uStack_8c;

      puStack_60 = (uint32_t /* width from decompiler */ *)0x0;

      puStack_5c = (uint32_t /* width from decompiler */ *)0x0;

      uStack_58 = 0;

      local_4 = CONCAT31(local_4._1_3_,9);

      FUN_0046a8d0();

      if (0 < (int)puVar6) {

        puStack_88 = puVar6;

        do {

          if (*(int *)(param_1 + 0x4044) == 0) {

            uVar4 = FUN_00437050();

          }

          else {

            uVar4 = FUN_00768760();

          }

          ppuStack_b0 = (uint8_t **)0x960b4a;

          FUN_00410420();

          uVar2 = FUN_0046b3c0();

          uStack_8c = uStack_8c | uVar2 | uVar4;

          puStack_88 = puStack_88 + -1;

        } while (puStack_88 != (uint8_t *)0x0);

      }

      if (*(int *)(param_1 + 0x4044) == 0) {

        uVar4 = FUN_00437050();

      }

      else {

        uVar4 = FUN_00768760();

      }

      uStack_8c = uStack_8c | uVar4;

      FUN_0046d4e0();

      puVar6 = puStack_94;

      if (0 < (int)puStack_94) {

        do {

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_80);

          local_4 = CONCAT31(local_4._1_3_,10);

          if (*(int *)(param_1 + 0x4044) == 0) {

            FUN_00436f10();

          }

          else {

            FUN_0076a200();

          }

          ppuStack_b0 = (uint8_t **)0x960c04;

          FUN_00989e00();

          FUN_0044cb20();

          local_4 = CONCAT31(local_4._1_3_,9);

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_80);

          puVar6 = puVar6 + -1;

        } while (puVar6 != (uint8_t *)0x0);

      }

      puVar6 = puStack_90;

      puStack_7c = (uint32_t /* width from decompiler */ *)0x0;

      puStack_78 = (uint32_t /* width from decompiler */ *)0x0;

      uStack_74 = 0;

      local_4 = CONCAT31(local_4._1_3_,0xb);

      puStack_94 = (uint8_t *)&pbStack_b4;

      ppuStack_b0 = (uint8_t **)0x0;

      FUN_0046a970(puStack_90);

      if (0 < (int)puVar6) {

        puStack_88 = (uint8_t *)((int)puStack_7c - (int)puStack_60);

        piVar5 = puStack_60 + 1;

        puStack_94 = puVar6;

        puVar3 = puStack_7c;

        do {

          if (*piVar5 == 0) {

            puStack_90 = (uint8_t *)0x0;

          }

          else {

            puStack_90 = (uint8_t *)(piVar5[1] - *piVar5 >> 2);

          }

          puVar6 = puStack_90;

          FUN_0046d4e0();

          iVar7 = 0;

          if (0 < (int)puVar6) {

            do {

              iVar1 = *(int *)(puStack_88 + (int)piVar5);

              if ((iVar1 == 0) || ((uint)(puVar3[3] - iVar1 >> 2) <= (uint)(puVar3[2] - iVar1 >> 2))

                 ) {

                ppuStack_b0 = (uint8_t **)puVar3[2];

                pbStack_b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                              *)&LAB_00960d19;

                FUN_00463e30();

              }

              else {

                iVar1 = puVar3[2];

                FUN_00436ef0();

                puVar3[2] = iVar1 + 4;

              }

              iVar7 = iVar7 + 1;

            } while (iVar7 < (int)puStack_90);

          }

          piVar5 = piVar5 + 4;

          puVar3 = puVar3 + 4;

          puStack_94 = puStack_94 + -1;

        } while (puStack_94 != (uint8_t *)0x0);

      }

      puVar6 = param_3[1];

      uVar4 = 0;

      if (puVar6 == (uint8_t *)0x0) {

        uVar2 = 0;

      }

      else {

        uVar2 = (int)param_3[2] - (int)puVar6 >> 2;

      }

      if ((*(int *)(param_2 + 4) != 0) &&

         (uVar2 < (uint)(*(int *)(param_2 + 8) - *(int *)(param_2 + 4) >> 2))) {

        if (puVar6 != (uint8_t *)0x0) {

          uVar4 = (int)param_3[2] - (int)puVar6 >> 2;

        }

        FUN_00456780();

        for (; (*(int *)(param_2 + 4) != 0 &&

               (uVar4 < (uint)(*(int *)(param_2 + 8) - *(int *)(param_2 + 4) >> 2)));

            uVar4 = uVar4 + 1) {

          puVar3 = (uint32_t /* width from decompiler */ *)FUN_0043f780();

          if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) {

            puVar3 = (uint32_t /* width from decompiler */ *)0x0;

          }

          else {

            puVar8 = &DAT_00afdf70;

            puVar9 = puVar3;

            for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {

              *puVar9 = *puVar8;

              puVar8 = puVar8 + 1;

              puVar9 = puVar9 + 1;

            }

          }

          *(uint32_t /* width from decompiler */ **)(param_3[1] + uVar4 * 4) = puVar3;

        }

      }

      ppuStack_b0 = &puStack_84;

      pbStack_b4 = abStack_80;

      uVar4 = FUN_0095f990();

      uStack_8c = uStack_8c | uVar4;

      if (puStack_7c != (uint32_t /* width from decompiler */ *)0x0) {

        if (puStack_7c != puStack_78) {

          puVar3 = puStack_7c + 1;

          do {

            if ((void *)*puVar3 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

              operator_delete((void *)*puVar3);

            }

            *puVar3 = 0;

            puVar3[1] = 0;

            puVar3[2] = 0;

            puVar8 = puVar3 + 3;

            puVar3 = puVar3 + 4;

          } while (puVar8 != puStack_78);

        }

                    /* WARNING: Subroutine does not return */

        operator_delete(puStack_7c);

      }

      if (puStack_60 != (uint32_t /* width from decompiler */ *)0x0) {

        if (puStack_60 != puStack_5c) {

          puVar3 = puStack_60 + 1;

          do {

            if ((void *)*puVar3 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

              operator_delete((void *)*puVar3);

            }

            *puVar3 = 0;

            puVar3[1] = 0;

            puVar3[2] = 0;

            puVar8 = puVar3 + 3;

            puVar3 = puVar3 + 4;

          } while (puVar8 != puStack_5c);

        }

                    /* WARNING: Subroutine does not return */

        operator_delete(puStack_60);

      }

      if (pvStack_44 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvStack_44);

      }

      break;

    case 4:

      puStack_94 = (uint8_t *)0x0;

      pvStack_44 = (void *)0x0;

      uStack_40 = 0;

      uStack_3c = 0;

      puStack_7c = (uint32_t /* width from decompiler */ *)0x0;

      puStack_78 = (uint32_t /* width from decompiler */ *)0x0;

      uStack_74 = 0;

      local_4 = 0xd;

      ppuStack_b0 = (uint8_t **)0x960ebb;

      uVar4 = FUN_0095dae0();

      ppuStack_b0 = param_3;

      pbStack_b4 = abStack_48;

      uStack_8c = FUN_0095f990(abStack_80,&puStack_94);

      uStack_8c = uVar4 | uStack_8c;

      FUN_0046a860();

      FUN_00405ef0();

      break;

    default:

      ppuStack_b0 = (uint8_t **)0x4b8;

      goto LAB_00960f26;

    }

    local_4 = 0xffffffff;

    if (local_24 != '\0') {

      FUN_00769e40();

    }

  }

  else {

    ppuStack_b0 = (uint8_t **)0x3ea;

LAB_00960f26:

    pbStack_b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                 0xaa6bf0;

    vog_LogMessage();

    local_4 = 0xffffffff;

    if (local_24 != '\0') {

      FUN_00769e40();

    }

    uStack_8c = 0xffffffff;

  }

  ExceptionList = local_c;

  return uStack_8c;

}
