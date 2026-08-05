// =============================================================================
// FUN_009615c0
// -----------------------------------------------------------------------------
// Stable ID: aa_009615c0
// Address:   0x009615c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009615c0 @ 0x009615c0
// Stable ID: aa_009615c0
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxBodyMassageMachine.cpp"
//   - "Invalid TAG unserializing gfxBodyMaster"
//   - "Legacy unserializer being used"
//   - "Cannot open the skeleton file: %s"
//   - "Unimplemented code reached"
//   - "cannot locate the skeleton file: %s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~502 non-empty decompiler lines.
//  - Control keywords: if×43, goto×9, while×8, return×7, do×3, switch×1, for×1.
//  - Notable callees: FUN_00405ef0×10, FUN_00439a00×8, FUN_00769e40×8, vog_LogMessage×8, FUN_0076a900×5, FUN_0095d850×5, FUN_009603e0×5, FUN_009614b0×5.
//  - Strings: ",0x38,3

                   ,"; ",0x45,2

                   ,"; "Cannot open the skeleton file: %s"; "

                             ,0x86,3,".
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

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

/* WARNING: Type propagation algorithm not settling */



uint FUN_009615c0(int *param_1,int param_2)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *******pppppppuVar2;

  uint8_t uVar3;

  char cVar4;

  int iVar5;

  int iVar6;

  uint uVar7;

  char *pcVar8;

  uint uVar9;

  uint uVar10;

  uint32_t /* width from decompiler */ *******pppppppuVar11;

  char *pcVar12;

  bool bVar13;

  uint32_t /* width from decompiler */ uVar14;

  char *pcVar15;

  uint local_40ec;

  int local_40e8;

  uint8_t local_40e4 [4];

  int local_40e0;

  int local_40dc;

  int local_40d8;

  int local_40d4;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_40d0 [4];

  uint32_t /* width from decompiler */ *******local_40cc;

  uint32_t /* width from decompiler */ *******local_40c8;

  int local_40c4;

  uint local_40b8;

  int local_40b4;

  undefined **local_40b0;

  uint32_t /* width from decompiler */ local_40ac;

  int local_40a8;

  uint32_t /* width from decompiler */ local_40a4;

  uint32_t /* width from decompiler */ local_40a0;

  int *local_409c;

  int local_4098;

  int local_4094;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_4090 [4];

  uint32_t /* width from decompiler */ *******local_408c;

  char local_4088;

  uint local_4078;

  uint32_t /* width from decompiler */ uStack_10;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b3ea2;

  local_c = ExceptionList;

  uStack_10 = 0x9615df;

  ExceptionList = &local_c;

  FUN_0044c270(0,0);

  FUN_0044c270(0,0);

  iVar5 = stoChunkReader_OpenChunk();

  if (iVar5 < 0) {

    ExceptionList = local_c;

    return 0xffffffff;

  }

  uVar9 = (*(int *)(param_2 + 0x4040) + *(int *)(param_2 + 0x403c)) - 1;

  if (*(uint *)(param_2 + 0x4038) <= uVar9) {

    uVar9 = uVar9 - *(uint *)(param_2 + 0x4038);

  }

  uVar10 = (*(int *)(param_2 + 0x4040) + *(int *)(param_2 + 0x403c)) - 1;

  if (*(uint *)(param_2 + 0x4038) <= uVar10) {

    uVar10 = uVar10 - *(uint *)(param_2 + 0x4038);

  }

  if (**(int **)(*(int *)(param_2 + 0x4034) + uVar9 * 4) != 0x424d4153) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxBodyMassageMachine.cpp",0x38,3

                   ,"Invalid TAG unserializing gfxBodyMaster");

    ExceptionList = local_c;

    return 0xffffffff;

  }

  switch(*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_2 + 0x4034) + uVar10 * 4) + 8)) {

  case 0:

    break;

  case 1:

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxBodyMassageMachine.cpp",0x45,2

                   ,"Legacy unserializer being used");

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_4090);

    local_4 = 0;

    iVar5 = FUN_00439a20(param_2);

    if (-1 < iVar5) {

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_40d0);

      local_4._0_1_ = 1;

      cVar4 = FUN_009695c0(DAT_00d1f1fc,local_40d0);

      if (cVar4 != '\0') {

        local_40b0 = &PTR_FUN_00a9d84c;

        local_40ac = 0;

        local_40a8 = 0xffffffff;

        local_40a4 = 0;

        local_40a0 = 0;

        local_4._0_1_ = 2;

        pppppppuVar11 = local_40cc;

        if (local_40b8 < 0x10) {

          pppppppuVar11 = &local_40cc;

        }

        iVar5 = FUN_007669d0(pppppppuVar11,1,0);

        if (iVar5 < 0) {

          if (local_4078 < 0x10) {

            local_408c = &local_408c;

          }

          uVar14 = FUN_0076cec0(&local_4098,"Cannot open the skeleton file: %s",local_408c);

          vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxBodyMassageMachine.cpp",

                         0x5d,2,uVar14);

          local_4._0_1_ = 1;

          FUN_00766750();

          local_4 = (uint)local_4._1_3_ << 8;

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_40d0);

          local_4 = 0xffffffff;

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_4090);

          ExceptionList = local_c;

          return 0xffffffff;

        }

        FUN_0076a150(&local_40b0);

        local_4._0_1_ = 3;

        iVar5 = FUN_0095e280(param_1 + 0x26);

        local_4._0_1_ = 2;

        uVar3 = (uint8_t)local_4;

        local_4._0_1_ = 2;

        if (iVar5 < 0) {

          FUN_0043d4a0();

          local_4._0_1_ = 1;

          FUN_00766750();

          local_4 = (uint)local_4._1_3_ << 8;

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_40d0);

          local_4 = 0xffffffff;

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_4090);

          ExceptionList = local_c;

          return 0xffffffff;

        }

        local_4._0_1_ = uVar3;

        FUN_0043d4a0();

        local_4._0_1_ = 1;

        FUN_00766750();

        local_4._0_1_ = 0;

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_40d0);

        uVar9 = FUN_00439a00();

        local_40ac = 0;

        local_40a8 = 0;

        local_40a4 = 0;

        local_4._0_1_ = 4;

        while (local_40ec = local_40ec + -1, -1 < (int)local_40ec) {

          iVar5 = FUN_0076a900();

          if (iVar5 == 0x47454f4d) {

            uVar10 = FUN_009614b0();

          }

          else {

            if (iVar5 != 0x534b4e4d) {

              vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxBodyMassageMachine.cpp"

                             ,0x86,3,"Unimplemented code reached");

              FUN_00405ef0();

              goto LAB_00961a10;

            }

            local_40e0 = 0;

            local_40dc = 0;

            local_40d8 = 0;

            local_40cc = (uint32_t /* width from decompiler */ *******)0x0;

            local_40c8 = (uint32_t /* width from decompiler */ *******)0x0;

            local_40c4 = 0;

            local_4._0_1_ = 6;

            uVar10 = FUN_009603e0(param_2,local_40e4,local_40d0);

            FUN_0095d850(param_1 + 0x26);

            FUN_00405ef0();

            local_4._0_1_ = 4;

            FUN_00405ef0();

          }

          uVar9 = uVar9 | uVar10;

        }

        FUN_0095d740();

        (**(code **)(*param_1 + 0x34))();

        FUN_0095da90();

        uVar10 = FUN_00769e40();

        local_40ec = uVar9 | uVar10;

        FUN_00405ef0();

        local_4 = 0xffffffff;

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_4090);

        goto LAB_00962135;

      }

      if (local_4078 < 0x10) {

        local_408c = &local_408c;

      }

      uVar14 = FUN_0076cec0(&local_4098,"cannot locate the skeleton file: %s",local_408c);

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxBodyMassageMachine.cpp",0x65

                     ,2,uVar14);

      local_4 = (uint)local_4._1_3_ << 8;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_40d0);

    }

LAB_00961a10:

    local_4 = 0xffffffff;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_4090);

    break;

  case 2:

    uVar9 = FUN_0095e280(param_1 + 0x26);

    uVar10 = FUN_00439a00();

    uVar9 = uVar9 | uVar10;

    while (local_40ec = local_40ec + -1, -1 < (int)local_40ec) {

      iVar5 = FUN_0076a900();

      if (iVar5 == 0x47454f4d) {

        uVar10 = FUN_009614b0();

      }

      else {

        if (iVar5 != 0x534b4e4d) {

          pcVar15 = "Unimplemented code reached";

          uVar14 = 0xae;

          goto LAB_009621d7;

        }

        local_40e0 = 0;

        local_40dc = 0;

        local_40d8 = 0;

        local_40cc = (uint32_t /* width from decompiler */ *******)0x0;

        local_40c8 = (uint32_t /* width from decompiler */ *******)0x0;

        local_40c4 = 0;

        local_4 = 8;

        uVar10 = FUN_009603e0(param_2,local_40e4,local_40d0);

        FUN_0095d850(param_1 + 0x26);

        FUN_00405ef0();

        local_4 = 0xffffffff;

        FUN_00405ef0();

      }

      uVar9 = uVar9 | uVar10;

    }

    goto LAB_00961b0a;

  case 3:

    uVar9 = FUN_00439a00();

    iVar5 = 0;

    pppppppuVar11 = (uint32_t /* width from decompiler */ *******)0x0;

    local_40cc = (uint32_t /* width from decompiler */ *******)0x0;

    local_40c8 = (uint32_t /* width from decompiler */ *******)0x0;

    local_40c4 = 0;

    local_40e0 = 0;

    local_40dc = 0;

    local_40d8 = 0;

    local_4 = 10;

    while (local_40e8 = local_40e8 + -1, -1 < local_40e8) {

      iVar6 = FUN_0076a900();

      if (iVar6 == 0x47454f4d) {

        uVar10 = FUN_009614b0();

      }

      else {

        if (iVar6 != 0x534b4e4d) {

          vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxBodyMassageMachine.cpp",

                         0xd5,3,"Unimplemented code reached");

          goto LAB_00961cd7;

        }

        if (local_40cc == (uint32_t /* width from decompiler */ *******)0x0) {

          iVar6 = 0;

        }

        else {

          iVar6 = (int)pppppppuVar11 - (int)local_40cc >> 4;

        }

        FUN_0046a830(iVar6 + 1);

        if (local_40e0 == 0) {

          iVar5 = 0;

        }

        else {

          iVar5 = iVar5 - local_40e0 >> 4;

        }

        FUN_0046a8a0(iVar5 + 1);

        pppppppuVar11 = local_40c8;

        iVar5 = local_40dc;

        uVar10 = FUN_009603e0(param_2,local_40c8 + -4,local_40dc + -0x10);

      }

      uVar9 = uVar9 | uVar10;

    }

    uVar10 = FUN_00769e40();

    uVar7 = FUN_0095e3e0(param_2,param_1);

    local_40ec = uVar9 | uVar10 | uVar7;

    pppppppuVar2 = local_40cc;

    if (-1 < (int)local_40ec) {

      for (; pppppppuVar2 != pppppppuVar11; pppppppuVar2 = pppppppuVar2 + 4) {

        FUN_0095d850(param_1 + 0x26);

      }

      FUN_0095d740();

      (**(code **)(*param_1 + 0x34))();

      FUN_0095da90();

      FUN_0046a860();

      local_4 = 0xffffffff;

      FUN_0046a860();

      goto LAB_00962135;

    }

LAB_00961cd7:

    FUN_0046a860();

    FUN_0046a860();

    break;

  case 4:

    uVar9 = FUN_0095e3e0(param_2,param_1);

    uVar10 = FUN_00439a00();

    uVar9 = uVar9 | uVar10;

    while (local_40e8 = local_40e8 + -1, -1 < local_40e8) {

      iVar5 = FUN_0076a900();

      if (iVar5 == 0x47454f4d) {

        uVar10 = FUN_009614b0();

      }

      else if (iVar5 == 0x4d52464d) {

        uVar10 = FUN_0095f880();

      }

      else {

        if (iVar5 != 0x534b4e4d) {

          pcVar15 = "Unimplemented code reached";

          uVar14 = 0x117;

          goto LAB_009621d7;

        }

        local_40e0 = 0;

        local_40dc = 0;

        local_40d8 = 0;

        local_40cc = (uint32_t /* width from decompiler */ *******)0x0;

        local_40c8 = (uint32_t /* width from decompiler */ *******)0x0;

        local_40c4 = 0;

        local_4 = 0xc;

        uVar10 = FUN_009603e0(param_2,local_40e4,local_40d0);

        FUN_0095d850(param_1 + 0x26);

        FUN_00405ef0();

        local_4 = 0xffffffff;

        FUN_00405ef0();

      }

      uVar9 = uVar9 | uVar10;

    }

LAB_00961b0a:

    FUN_0095d740();

    (**(code **)(*param_1 + 0x34))();

    FUN_0095da90();

    uVar10 = FUN_00769e40();

    local_40ec = uVar9 | uVar10;

LAB_00962135:

    if (((*(char *)(DAT_00d1f048 + 0xe) != '\0') && (*(char *)(DAT_00d1f044 + 0x776) != '\0')) &&

       (iVar5 = FUN_0046a650(), iVar5 == 0)) {

      FUN_00765650(param_1);

    }

    FUN_0044c270(0,0);

    FUN_0044c270(0,0);

    ExceptionList = local_c;

    return local_40ec;

  case 5:

    uVar9 = FUN_0095e280(param_1 + 0x26);

    local_409c = (int *)0x0;

    local_4 = 0xd;

    uVar10 = FUN_004372a0(param_2);

    stoChunkReader_EnterChunkScope(param_2);

    local_4._0_1_ = 0xe;

    if ((local_40d8 == 0x55534552) && (local_40d4 == 0)) {

      uVar7 = FUN_00439a00();

      iVar5 = local_40b4;

      local_40ec = uVar9 | uVar10 | uVar7;

      FUN_0046a6a0();

      if (0 < iVar5) {

        do {

          local_40b4 = iVar5;

          local_40a8 = 0;

          local_40a4 = 0;

          local_40a0 = 0;

          local_4._0_1_ = 0xf;

          local_40e8 = -1;

          stoChunkReader_EnterChunkScope(param_2);

          local_4._0_1_ = 0x10;

          if (local_40c4 == 0x42445441) {

            uVar9 = FUN_00439a00();

            uVar10 = FUN_00439a00();

            iVar5 = local_4098;

            local_40ec = local_40ec | uVar9 | uVar10;

            FUN_00437ad0(local_4098);

            if (0 < iVar5) {

              pcVar15 = (char *)(local_40a8 + 0x20);

              local_4094 = iVar5;

              do {

                stoChunkReader_EnterChunkScope(param_2);

                local_4 = CONCAT31(local_4._1_3_,0x11);

                uVar9 = FUN_00439a20(param_2);

                uVar10 = FUN_00439a20(param_2);

                local_40ec = local_40ec | uVar9 | uVar10;

                if (*(uint *)(pcVar15 + -8) < 0x10) {

                  pcVar8 = pcVar15 + -0x1c;

                }

                else {

                  pcVar8 = *(char **)(pcVar15 + -0x1c);

                }

                iVar5 = 3;

                bVar13 = true;

                pcVar12 = "cp";

                do {

                  if (iVar5 == 0) break;

                  iVar5 = iVar5 + -1;

                  bVar13 = *pcVar8 == *pcVar12;

                  pcVar8 = pcVar8 + 1;

                  pcVar12 = pcVar12 + 1;

                } while (bVar13);

                if (bVar13) {

                  pcVar8 = pcVar15;

                  if (0xf < *(uint *)(pcVar15 + 0x14)) {

                    pcVar8 = *(char **)pcVar15;

                  }

                  local_40e8 = atoi(pcVar8);

                }

                local_4._0_1_ = 0x10;

                if (local_4088 != '\0') {

                  FUN_00769e40();

                }

                pcVar15 = pcVar15 + 0x38;

                local_4094 = local_4094 + -1;

              } while (local_4094 != 0);

              if (local_40e8 != -1) {

                FUN_0046a620();

                FUN_0046a670();

                goto LAB_00961fc9;

              }

            }

            FUN_0046a7b0();

          }

LAB_00961fc9:

          local_4._0_1_ = 0xf;

          if ((char)local_40c8 != '\0') {

            FUN_00769e40();

          }

          local_4._0_1_ = 0xe;

          FUN_00437f20();

          iVar5 = local_40b4 + -1;

        } while (local_40b4 + -1 != 0);

        local_40b4 = 0;

      }

    }

    else {

      local_40ec = 0xffffffff;

    }

    local_4 = CONCAT31(local_4._1_3_,0xd);

    if ((char)local_40dc != '\0') {

      FUN_00769e40();

    }

    FUN_00439a00();

    while (local_40e8 = local_40e8 + -1, -1 < local_40e8) {

      iVar5 = FUN_0076a900();

      if (iVar5 == 0x47454f4d) {

        uVar9 = FUN_009614b0();

      }

      else if (iVar5 == 0x4d52464d) {

        uVar9 = FUN_0095f880();

      }

      else {

        if (iVar5 != 0x534b4e4d) {

          vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxBodyMassageMachine.cpp",

                         0x17c,3,"Unimplemented code reached");

          local_4 = 0xffffffff;

          if (local_409c != (int *)0x0) {

            piVar1 = local_409c + 1;

            *piVar1 = *piVar1 + -1;

            if (*piVar1 == 0) {

              (**(code **)(*local_409c + 8))();

            }

          }

          ExceptionList = local_c;

          return 0xffffffff;

        }

        local_40e0 = 0;

        local_40dc = 0;

        local_40d8 = 0;

        local_40cc = (uint32_t /* width from decompiler */ *******)0x0;

        local_40c8 = (uint32_t /* width from decompiler */ *******)0x0;

        local_40c4 = 0;

        local_4._0_1_ = 0x13;

        uVar9 = FUN_009603e0(param_2,local_40e4,local_40d0);

        FUN_0095d850(param_1 + 0x26);

        FUN_00405ef0();

        local_4 = CONCAT31(local_4._1_3_,0xd);

        FUN_00405ef0();

      }

      local_40ec = local_40ec | uVar9;

    }

    FUN_0095d740();

    (**(code **)(*param_1 + 0x34))();

    FUN_0095da90();

    uVar9 = FUN_00769e40();

    local_40ec = local_40ec | uVar9;

    local_4 = 0xffffffff;

    if (local_409c != (int *)0x0) {

      piVar1 = local_409c + 1;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*local_409c + 8))();

      }

    }

    goto LAB_00962135;

  default:

    FUN_00769e40();

    pcVar15 = "Invalid chunk version unserializing gfxBodyMaster";

    uVar14 = 0x18a;

LAB_009621d7:

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxBodyMassageMachine.cpp",uVar14

                   ,3,pcVar15);

  }

  ExceptionList = local_c;

  return 0xffffffff;

}
