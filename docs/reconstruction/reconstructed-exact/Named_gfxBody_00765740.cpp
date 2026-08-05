// READABILITY (auto CF):
//  - Body size: ~534 non-empty decompiler lines.
//  - Control keywords: if×46, do×9, while×9, goto×5, for×3, return×2.
//  - Notable callees: FUN_00437050×12, FUN_00768760×10, FUN_00436f10×5, FUN_00456780×5, FUN_0076a200×5, FUN_00437b00×4, FUN_007689e0×4, FUN_00435df0×2.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxBody.cpp"; "Pj\x03h\x17\x02".
//  - Return sites: 2.

// =============================================================================
// Named_gfxBody_00765740
// -----------------------------------------------------------------------------
// Stable ID: aa_00765740
// Address:   0x00765740  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxBody"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint Named_gfxBody_00765740(int param_1,undefined **param_2)



{

  int iVar1;

  undefined *puVar2;

  undefined **ppuVar3;

  uint uVar4;

  uint uVar5;

  int iVar6;

  uint uVar7;

  int *piVar8;

  uint8_t *puVar9;

  uint32_t /* width from decompiler */ *puVar10;

  uint32_t /* width from decompiler */ *puVar11;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_a4 [24];

  uint32_t /* width from decompiler */ uStack_8c;

  char *local_88;

  uint32_t /* width from decompiler */ uStack_84;

  uint32_t /* width from decompiler */ uStack_80;

  char *pcStack_7c;

  uint32_t /* width from decompiler */ *local_78;

  undefined **local_74;

  undefined **local_70;

  uint local_5c;

  int local_50;

  uint32_t /* width from decompiler */ *local_4c;

  uint8_t *local_48;

  int *local_44;

  char local_34;

  int local_30;

  int local_2c;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  ppuVar3 = param_2;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b31c4;

  local_c = ExceptionList;

  local_70 = param_2;

  local_74 = (undefined **)0x76576a;

  ExceptionList = &local_c;

  stoChunkReader_EnterChunkScope();

  local_4 = 0;

  if (local_30 != 0x47424f44) {

    local_70 = (undefined **)0xa9dc40;

    local_74 = (undefined **)0x3;

    local_78 = (uint32_t /* width from decompiler */ *)0x143;

    pcStack_7c = "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxBody.cpp";

    uStack_80 = 0x765792;

    vog_LogMessage();

LAB_007657d9:

    local_4 = 0xffffffff;

    if (local_34 != '\0') {

      local_70 = (undefined **)0x7657f1;

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return 0xffffffff;

  }

  if (local_2c == 1) {

    local_4c = (uint32_t /* width from decompiler */ *)(param_1 + 4);

    local_70 = (undefined **)0x765d12;

    uVar4 = FUN_0074ce60();

    local_70 = ppuVar3;

    local_74 = (undefined **)0x765d1d;

    uVar5 = FUN_004372a0();

    if (ppuVar3[0x1011] == (undefined *)0x0) {

      local_70 = (undefined **)&param_2;

      local_74 = (undefined **)0x765d38;

      local_5c = FUN_00437050();

    }

    else {

      local_70 = (undefined **)&param_2;

      local_74 = (undefined **)0x765d46;

      local_5c = FUN_007689e0();

    }

    iVar6 = param_1;

    local_5c = uVar4 | uVar5 | local_5c;

    local_44 = &uStack_80;

    local_78 = (uint32_t /* width from decompiler */ *)0x0;

    local_74 = (undefined **)0x0;

    local_70 = (undefined **)0x0;

    uStack_84 = 0x765d71;

    FUN_00437f70();

    param_2 = *(undefined ***)(iVar6 + 0x80);

    local_48 = *(uint8_t **)(iVar6 + 0x84);

    if (param_2 != (undefined **)local_48) {

      do {

        if (ppuVar3[0x1011] == (undefined *)0x0) {

          local_70 = param_2;

          local_74 = (undefined **)0x765da5;

          uVar4 = FUN_00437050();

        }

        else {

          local_70 = param_2;

          local_74 = (undefined **)0x765db3;

          uVar4 = FUN_00768760();

        }

        if (ppuVar3[0x1011] == (undefined *)0x0) {

          local_70 = (undefined **)&local_50;

          local_74 = (undefined **)0x765dcc;

          uVar5 = FUN_00437050();

        }

        else {

          local_70 = (undefined **)&local_50;

          local_74 = (undefined **)0x765dda;

          uVar5 = FUN_007689e0();

        }

        local_5c = local_5c | uVar4 | uVar5;

        local_44 = (int *)abStack_a4;

        FUN_004382c0(abStack_a4);

        iVar6 = (int)param_2;

        FUN_00437e40();

        puVar9 = *(uint8_t **)(iVar6 + 8);

        local_44 = *(int **)(iVar6 + 0xc);

        if ((int *)puVar9 != local_44) {

          do {

            if (ppuVar3[0x1011] == (undefined *)0x0) {

              local_70 = (undefined **)0x765e33;

              uVar4 = FUN_00436f10();

            }

            else {

              local_70 = (undefined **)0x765e40;

              uVar4 = FUN_0076a200();

            }

            if (ppuVar3[0x1011] == (undefined *)0x0) {

              local_70 = (undefined **)0x765e5d;

              uVar5 = FUN_00436f10();

            }

            else {

              local_70 = (undefined **)0x765e6a;

              uVar5 = FUN_0076a200();

            }

            local_5c = local_5c | uVar4 | uVar5;

            puVar9 = puVar9 + 0x38;

            iVar6 = (int)param_2;

          } while ((int *)puVar9 != local_44);

        }

        param_2 = (undefined **)(iVar6 + 0x14);

      } while (param_2 != (undefined **)local_48);

    }

    iVar6 = param_1;

    local_70 = ppuVar3;

    local_74 = (undefined **)(param_1 + 0x98);

    local_78 = (uint32_t /* width from decompiler */ *)0x765eaa;

    uVar4 = FUN_0096b930();

    if (ppuVar3[0x1011] == (undefined *)0x0) {

      local_70 = (undefined **)&param_2;

      local_74 = (undefined **)0x765ec3;

      uVar5 = FUN_00437050();

    }

    else {

      local_70 = (undefined **)&param_2;

      local_74 = (undefined **)0x765ed1;

      uVar5 = FUN_00768760();

    }

    local_44 = (int *)&local_74;

    local_70 = (undefined **)0x0;

    local_74 = &PTR_FUN_00a9da78;

    local_78 = (uint32_t /* width from decompiler */ *)0x765efa;

    FUN_00438040();

    iVar1 = *(int *)(iVar6 + 0x130);

    for (iVar6 = *(int *)(iVar6 + 300); iVar6 != iVar1; iVar6 = iVar6 + 8) {

      local_70 = ppuVar3;

      local_74 = (undefined **)0x765f16;

      FUN_004373b0();

    }

    if (ppuVar3[0x1011] == (undefined *)0x0) {

      local_70 = (undefined **)&param_2;

      local_74 = (undefined **)0x765f32;

      uVar7 = FUN_00437050();

    }

    else {

      local_70 = (undefined **)&param_2;

      local_74 = (undefined **)0x765f40;

      uVar7 = FUN_00768760();

    }

    iVar6 = param_1;

    local_70 = (undefined **)0x0;

    uVar7 = local_5c | uVar4 | uVar5 | uVar7;

    local_74 = (undefined **)0x765f5b;

    FUN_00456780();

    puVar10 = *(uint32_t /* width from decompiler */ **)(iVar6 + 0xc0);

    local_44 = *(int **)(iVar6 + 0xc4);

    if (puVar10 != local_44) {

      do {

        local_74 = (undefined **)0x765f78;

        local_70 = (undefined **)puVar10;

        uVar4 = FUN_00437b00();

        uVar7 = uVar7 | uVar4;

        local_70 = (undefined **)0x765f84;

        (**(code **)(*(int *)*puVar10 + 100))();

        puVar10 = puVar10 + 1;

      } while (puVar10 != local_44);

    }

    if (ppuVar3[0x1011] == (undefined *)0x0) {

      local_70 = (undefined **)&param_2;

      local_74 = (undefined **)0x765fa2;

      local_5c = FUN_00437050();

    }

    else {

      local_70 = (undefined **)&param_2;

      local_74 = (undefined **)0x765fb0;

      local_5c = FUN_00768760();

    }

    iVar6 = param_1;

    local_5c = uVar7 | local_5c;

    local_70 = (undefined **)0x0;

    local_74 = (undefined **)0x765fcb;

    FUN_00456780();

    piVar8 = *(int **)(iVar6 + 0xd0);

    param_2 = *(undefined ***)(iVar6 + 0xd4);

    if ((undefined **)piVar8 != param_2) {

      do {

        local_74 = (undefined **)0x765fe8;

        local_70 = (undefined **)piVar8;

        uVar4 = FUN_00437b00();

        local_5c = local_5c | uVar4;

        *(uint *)(*piVar8 + 0xbc) = *(uint *)(*piVar8 + 0xbc) | 0x40;

        piVar8 = piVar8 + 1;

      } while ((undefined **)piVar8 != param_2);

    }

  }

  else {

    if (local_2c != 2) {

      if (local_2c != 3) {

        local_70 = (undefined **)local_2c;

        local_78 = &param_1;

        local_74 = (undefined **)0xa9dc0c;

        pcStack_7c = "Pj\x03h\x17\x02";

        pcStack_7c = (char *)FUN_0076cec0();

        uStack_80 = 3;

        uStack_84 = 0x217;

        local_88 = "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxBody.cpp";

        uStack_8c = 0x7657d6;

        vog_LogMessage();

        goto LAB_007657d9;

      }

      if (ppuVar3[0x1011] == (undefined *)0x0) {

        local_70 = (undefined **)&param_2;

        local_74 = (undefined **)0x76581e;

        FUN_00437050();

      }

      else {

        local_70 = (undefined **)&param_2;

        local_74 = (undefined **)0x76582c;

        FUN_00768760();

      }

      if (ppuVar3[0x1011] == (undefined *)0x0) {

        local_70 = (undefined **)&param_2;

        local_74 = (undefined **)0x765841;

        FUN_00437050();

      }

      else {

        local_70 = (undefined **)&param_2;

        local_74 = (undefined **)0x76584f;

        FUN_00768760();

      }

      local_70 = (undefined **)0x765859;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

      local_4._0_1_ = 1;

      if (0 < (int)param_2) {

        do {

          if (ppuVar3[0x1011] == (undefined *)0x0) {

            local_70 = (undefined **)0x765885;

            FUN_00436f10();

          }

          else {

            local_70 = (undefined **)0x765892;

            FUN_0076a200();

          }

          param_2 = (undefined **)((int)param_2 + -1);

        } while (param_2 != (undefined **)0x0);

      }

      local_4 = (uint)local_4._1_3_ << 8;

      local_70 = (undefined **)0x7658a8;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

    }

    local_4c = (uint32_t /* width from decompiler */ *)(param_1 + 4);

    local_70 = (undefined **)0x7658ba;

    uVar4 = FUN_0074ce60();

    local_70 = ppuVar3;

    local_74 = (undefined **)0x7658c5;

    uVar5 = FUN_004372a0();

    if (ppuVar3[0x1011] == (undefined *)0x0) {

      local_70 = (undefined **)&param_2;

      local_74 = (undefined **)0x7658e0;

      local_5c = FUN_00437050();

    }

    else {

      local_70 = (undefined **)&param_2;

      local_74 = (undefined **)0x7658ee;

      local_5c = FUN_007689e0();

    }

    iVar6 = param_1;

    local_5c = uVar4 | uVar5 | local_5c;

    local_44 = &uStack_80;

    local_78 = (uint32_t /* width from decompiler */ *)0x0;

    local_74 = (undefined **)0x0;

    local_70 = (undefined **)0x0;

    uStack_84 = 0x765919;

    FUN_00437f70();

    param_2 = *(undefined ***)(iVar6 + 0x80);

    local_44 = *(int **)(iVar6 + 0x84);

    if (param_2 != (undefined **)local_44) {

      do {

        if (ppuVar3[0x1011] == (undefined *)0x0) {

          if ((int)ppuVar3[8] < (int)(ppuVar3[6] + 4)) {

            local_70 = (undefined **)(ppuVar3[7] + (int)ppuVar3[6]);

            local_74 = (undefined **)0x765959;

            iVar6 = FUN_00435df0();

            if ((iVar6 < 0) || ((int)ppuVar3[8] < 4)) {

              uVar4 = 0xffffffff;

              goto LAB_00765989;

            }

          }

          *param_2 = (undefined *)*(int *)((int)ppuVar3 + (int)(ppuVar3[6] + 0x2c));

          ppuVar3[6] = ppuVar3[6] + 4;

          uVar4 = 0;

        }

        else {

          local_70 = param_2;

          local_74 = (undefined **)0x765989;

          uVar4 = FUN_00768760();

        }

LAB_00765989:

        if (ppuVar3[0x1011] == (undefined *)0x0) {

          if ((int)ppuVar3[8] < (int)(ppuVar3[6] + 4)) {

            local_70 = (undefined **)(ppuVar3[7] + (int)ppuVar3[6]);

            local_74 = (undefined **)0x7659b1;

            iVar6 = FUN_00435df0();

            if ((iVar6 < 0) || ((int)ppuVar3[8] < 4)) {

              uVar5 = 0xffffffff;

              goto LAB_007659e1;

            }

          }

          local_50 = *(int *)((int)ppuVar3 + (int)(ppuVar3[6] + 0x2c));

          ppuVar3[6] = ppuVar3[6] + 4;

          uVar5 = 0;

        }

        else {

          local_70 = (undefined **)&local_50;

          local_74 = (undefined **)0x7659e1;

          uVar5 = FUN_007689e0();

        }

LAB_007659e1:

        local_5c = local_5c | uVar4 | uVar5;

        local_48 = abStack_a4;

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_a4);

        local_4._0_1_ = 2;

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                   &local_88);

        piVar8 = (int *)param_2;

        local_4 = (uint)local_4._1_3_ << 8;

        FUN_00437e40();

        iVar6 = piVar8[2];

        local_48 = (uint8_t *)piVar8[3];

        if ((uint8_t *)iVar6 != local_48) {

          do {

            if (ppuVar3[0x1011] == (undefined *)0x0) {

              local_70 = (undefined **)0x765a53;

              uVar4 = FUN_00436f10();

            }

            else {

              local_70 = (undefined **)0x765a60;

              uVar4 = FUN_0076a200();

            }

            if (ppuVar3[0x1011] == (undefined *)0x0) {

              local_70 = (undefined **)0x765a7d;

              uVar5 = FUN_00436f10();

            }

            else {

              local_70 = (undefined **)0x765a8a;

              uVar5 = FUN_0076a200();

            }

            local_5c = local_5c | uVar4 | uVar5;

            iVar6 = iVar6 + 0x38;

            piVar8 = (int *)param_2;

          } while ((uint8_t *)iVar6 != local_48);

        }

        param_2 = (undefined **)(piVar8 + 5);

      } while (param_2 != (undefined **)local_44);

    }

    iVar6 = param_1;

    local_70 = ppuVar3;

    local_74 = (undefined **)(param_1 + 0x98);

    local_78 = (uint32_t /* width from decompiler */ *)0x765aca;

    uVar4 = FUN_0096b930();

    if (ppuVar3[0x1011] == (undefined *)0x0) {

      local_70 = (undefined **)&param_2;

      local_74 = (undefined **)0x765ae3;

      uVar5 = FUN_00437050();

    }

    else {

      local_70 = (undefined **)&param_2;

      local_74 = (undefined **)0x765af1;

      uVar5 = FUN_00768760();

    }

    local_44 = (int *)&local_74;

    local_70 = (undefined **)0x0;

    local_74 = &PTR_FUN_00a9da78;

    local_78 = (uint32_t /* width from decompiler */ *)0x765b1a;

    FUN_00438040();

    iVar1 = *(int *)(iVar6 + 0x130);

    for (iVar6 = *(int *)(iVar6 + 300); iVar6 != iVar1; iVar6 = iVar6 + 8) {

      local_70 = ppuVar3;

      local_74 = (undefined **)0x765b36;

      FUN_004373b0();

    }

    if (ppuVar3[0x1011] == (undefined *)0x0) {

      local_70 = (undefined **)&param_2;

      local_74 = (undefined **)0x765b52;

      uVar7 = FUN_00437050();

    }

    else {

      local_70 = (undefined **)&param_2;

      local_74 = (undefined **)0x765b60;

      uVar7 = FUN_00768760();

    }

    iVar6 = param_1;

    local_5c = local_5c | uVar4 | uVar5 | uVar7;

    local_70 = (undefined **)0x0;

    local_74 = (undefined **)0x765b79;

    FUN_00456780();

    local_44 = *(int **)(iVar6 + 0xc4);

    puVar10 = *(uint32_t /* width from decompiler */ **)(iVar6 + 0xc0);

    if (puVar10 != local_44) {

      do {

        local_74 = (undefined **)0x765b98;

        local_70 = (undefined **)puVar10;

        uVar4 = FUN_00437b00();

        local_5c = local_5c | uVar4;

        if ((int)local_5c < 0) goto LAB_00766015;

        local_70 = (undefined **)0x765bac;

        (**(code **)(*(int *)*puVar10 + 100))();

        puVar10 = puVar10 + 1;

      } while (puVar10 != local_44);

    }

    if (ppuVar3[0x1011] == (undefined *)0x0) {

      local_70 = (undefined **)&param_2;

      local_74 = (undefined **)0x765bca;

      uVar4 = FUN_00437050();

    }

    else {

      local_70 = (undefined **)&param_2;

      local_74 = (undefined **)0x765bd8;

      uVar4 = FUN_00768760();

    }

    local_5c = local_5c | uVar4;

    local_70 = (undefined **)0x0;

    local_74 = (undefined **)0x765bed;

    FUN_00456780();

    param_2 = *(undefined ***)(iVar6 + 0xd4);

    piVar8 = *(int **)(iVar6 + 0xd0);

    puVar2 = *ppuVar3;

    local_78 = (uint32_t /* width from decompiler */ *)0x0;

    local_44 = (int *)CONCAT31(local_44._1_3_,DAT_00afa2d8 == '\0');

    local_74 = (undefined **)ppuVar3[2];

    if (puVar2 != (undefined *)0x0) {

      local_78 = (uint32_t /* width from decompiler */ *)((uint)puVar2 & 0x1f);

      local_74 = local_74 + ((uint)puVar2 >> 5);

    }

    local_70 = (undefined **)local_44;

    pcStack_7c = (char *)0x765c36;

    FUN_004363b0();

    if ((undefined **)piVar8 != param_2) {

      do {

        local_74 = (undefined **)0x765c48;

        local_70 = (undefined **)piVar8;

        uVar4 = FUN_00437b00();

        local_5c = local_5c | uVar4;

        if ((int)local_5c < 0) goto LAB_00766015;

        *(uint *)(*piVar8 + 0xbc) = *(uint *)(*piVar8 + 0xbc) | 0x40;

        if ((DAT_00afa2d8 == '\0') && ((uint32_t /* width from decompiler */ *)*piVar8 != (uint32_t /* width from decompiler */ *)0x0)) {

          local_70 = (undefined **)0x1;

          local_74 = (undefined **)0x765c73;

          (*(code *)**(uint32_t /* width from decompiler */ **)*piVar8)();

        }

        piVar8 = piVar8 + 1;

      } while ((undefined **)piVar8 != param_2);

    }

    if (DAT_00afa2d8 == '\0') {

      local_70 = (undefined **)0x0;

      local_74 = (undefined **)0x765c94;

      FUN_00456780();

    }

    local_70 = (undefined **)0x765c9b;

    FUN_00767570();

    if (ppuVar3[0x1011] == (undefined *)0x0) {

      local_70 = (undefined **)0x765caf;

      uVar4 = FUN_00437000();

    }

    else {

      local_70 = (undefined **)&param_2;

      local_74 = (undefined **)0x765cbd;

      uVar4 = FUN_00769660();

    }

    local_5c = local_5c | uVar4;

    if ((char)param_2 != '\0') {

      local_70 = (undefined **)0x765cd3;

      piVar8 = (int *)FUN_00437c90();

      *(int **)(iVar6 + 0x94) = piVar8;

      if (piVar8 != (int *)0x0) {

        local_70 = (undefined **)iVar6;

        local_74 = (undefined **)0x765ce9;

        (**(code **)(*piVar8 + 0x10))();

        local_74 = ppuVar3;

        local_78 = (uint32_t /* width from decompiler */ *)0x765cf7;

        uVar4 = (**(code **)(**(int **)(iVar6 + 0x94) + 4))();

        local_5c = local_5c | uVar4;

      }

    }

  }

  puVar10 = local_4c;

  puVar11 = (uint32_t /* width from decompiler */ *)(param_1 + 0x34);

  for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {

    *puVar11 = *puVar10;

    puVar10 = puVar10 + 1;

    puVar11 = puVar11 + 1;

  }

LAB_00766015:

  local_4 = 0xffffffff;

  if (local_34 != '\0') {

    local_70 = (undefined **)0x76602d;

    FUN_00769e40();

  }

  ExceptionList = local_c;

  return local_5c;

}
