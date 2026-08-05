// READABILITY (auto CF):
//  - Body size: ~209 non-empty decompiler lines.
//  - Control keywords: if×20, do×1, switch×1, goto×1, while×1, return×1.
//  - Notable callees: stoChunkWriter_EndChunk×10, FUN_0096f780×8, FUN_00439870×5, FUN_0043ee60×4, vog_LogMessage×3, FUN_00436030×2, FUN_0096a6f0×2, stoChunkWriter_BeginChunk×2.
//  - Strings: "Phase"; ",

                           0x277,3,"; ",

                           0x2c8,3,"; ",

                         uVar8,3,".
//  - Return sites: 1.

// =============================================================================
// Named_effEffect_0096f890
// -----------------------------------------------------------------------------
// Stable ID: aa_0096f890
// Address:   0x0096f890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "effEffect"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_effEffect_0096f890(uint32_t /* width from decompiler */ *param_1,int *param_2)



{

  int iVar1;

  undefined *puVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ uVar4;

  void *pvVar5;

  int iVar6;

  int *piVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ local_c4;

  int local_c0;

  uint32_t /* width from decompiler */ *local_bc;

  uint8_t auStack_b8 [8];

  int iStack_b0;

  uint32_t /* width from decompiler */ uStack_ac;

  int iStack_a4;

  int iStack_a0;

  byte bStack_94;

  uint8_t auStack_8c [4];

  uint8_t auStack_88 [4];

  uint8_t auStack_84 [4];

  uint32_t /* width from decompiler */ uStack_80;

  uint32_t /* width from decompiler */ uStack_7c;

  uint32_t /* width from decompiler */ uStack_78;

  float fStack_74;

  uint32_t /* width from decompiler */ *local_64;

  uint8_t auStack_60 [68];

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009afdb3;

  pvStack_1c = ExceptionList;

  ExceptionList = &pvStack_1c;

  local_64 = param_1;

  stoChunkWriter_BeginChunk(0x45464354,3);

  local_14 = 0;

  local_c0 = *(int *)(*param_2 + 8);

  piVar7 = (int *)(*(int *)(local_c0 + 0x1cc) + 4);

  if (*(int *)(local_c0 + 0x1cc) == 0) {

    piVar7 = &DAT_00d1ed24;

  }

  if (DAT_00d1a560 == (code *)0x0) {

    local_bc = param_1;

    stoChunkWriter_BeginChunk(DAT_00d1ed20,1);

    local_14 = CONCAT31(local_14._1_3_,1);

    puVar2 = (undefined *)*piVar7;

    if ((undefined *)*piVar7 == (undefined *)0x0) {

      puVar2 = PTR_DAT_00afa2bc;

    }

    if (param_1[7] == 0) {

      uVar3 = FUN_00436f80(param_1,puVar2);

      param_1[1] = param_1[1] | uVar3;

    }

    else {

      uVar3 = FUN_00767160(&DAT_00a9d6f8,puVar2);

      param_1[1] = param_1[1] | uVar3;

      uVar3 = (**(code **)(*(int *)*param_1 + 0x18))(&DAT_00a97b84,2);

      param_1[8] = 0;

      param_1[1] = uVar3 | param_1[1];

    }

    local_14 = local_14 & 0xffffff00;

    stoChunkWriter_EndChunk();

  }

  else {

    local_c4 = 0;

    iVar1 = (*DAT_00d1a560)(piVar7,&local_c4);

    if (-1 < iVar1) {

      FUN_0096a6f0(param_1,0);

    }

  }

  uVar8 = *(uint32_t /* width from decompiler */ *)(*param_2 + 0x1c);

  local_c4._2_2_ = (short)((uint)uVar8 >> 0x10);

  if ((((short)uVar8 != -1) || (local_c4._2_2_ != -1)) &&

     ((uVar4 = *(uint32_t /* width from decompiler */ *)(*(int *)(*param_2 + 8) + 0x24), (short)uVar8 != (short)uVar4 ||

      (local_c4._2_2_ != (short)((uint)uVar4 >> 0x10))))) {

    local_c4 = uVar4;

    if (*(int *)(local_c0 + 0xc) == 0) {

      uVar4 = 0;

    }

    else {

      uVar4 = (**(code **)(**(int **)(local_c0 + 0xc) + 0x24))(*(int **)(local_c0 + 0xc),0,"Phase");

    }

    FUN_0074f130(uVar4);

    FUN_0096f780();

    FUN_00746210(&uStack_80,uVar8);

    local_14._0_1_ = 2;

    FUN_00439920();

    stoChunkWriter_EndChunk();

    local_14 = (uint)local_14._1_3_ << 8;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               &uStack_80);

  }

  local_bc = *(uint32_t /* width from decompiler */ **)(*(int *)(*param_2 + 8) + 0x18);

  local_c4 = 0;

  if (0 < (int)local_bc) {

    do {

      iVar1 = local_c4;

      if (*(int *)(local_c0 + 0xc) != 0) {

        (**(code **)(**(int **)(local_c0 + 0xc) + 0x10))

                  (*(int **)(local_c0 + 0xc),

                   *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(*param_2 + 8) + 0x10) + local_c4 * 8),

                   auStack_b8);

      }

      if ((bStack_94 & 1) == 0) {

        switch(uStack_ac) {

        case 1:

          if (iStack_b0 != 0) {

            vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effEffect.cpp",

                           0x277,3,"Unimplemented code reached");

          }

          FUN_0043ee60(iVar1,auStack_88);

          FUN_0096f780();

          FUN_00439870();

          stoChunkWriter_EndChunk();

          break;

        case 2:

          if (iStack_b0 != 0) {

            vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effEffect.cpp",

                           0x2c8,3,"Unimplemented code reached");

          }

          FUN_0043ee60(iVar1,auStack_8c);

          FUN_0096f780();

          FUN_00439870();

          stoChunkWriter_EndChunk();

          break;

        case 3:

          if (iStack_b0 == 0) {

            if (iStack_a0 == 0) {

              FUN_0043ee60(iVar1,auStack_84);

              FUN_0096f780();

              FUN_00439870();

              FUN_0043b500(auStack_84);

              stoChunkWriter_EndChunk();

            }

            else {

              pvVar5 = operator_new__(iStack_a0 * 4);

              FUN_00752460(local_c4,pvVar5,iStack_a0);

              FUN_0096f780();

              FUN_00439870();

              FUN_00436030();

              stoChunkWriter_EndChunk();

              operator_delete__(pvVar5);

              iVar1 = local_c4;

            }

          }

          else if (iStack_b0 == 1) {

            if (iStack_a4 == 4) {

              uStack_80 = 0;

              uStack_7c = 0;

              uStack_78 = 0;

              fStack_74 = g_flOne;

              FUN_00753060(iVar1);

              FUN_0096f780();

              FUN_00439870();

              FUN_00436030();

              stoChunkWriter_EndChunk();

            }

          }

          else {

            if ((iStack_b0 != 2) && (iStack_b0 != 3)) {

              uVar8 = 0x2c0;

              goto LAB_0096fd8e;

            }

            FUN_0043ee60(iVar1,auStack_60);

            FUN_0096f780();

            FUN_00439810();

            FUN_0043edf0();

            stoChunkWriter_EndChunk();

          }

          break;

        default:

          uVar8 = 0x2f1;

LAB_0096fd8e:

          vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effEffect.cpp",

                         uVar8,3,"Unimplemented code reached");

          break;

        case 5:

          if ((((-1 < iVar1) &&

               (iVar6 = (uint)*(ushort *)(*(int *)(*(int *)(*param_2 + 8) + 0x10) + 4 + iVar1 * 8) +

                        *(int *)(*param_2 + 0xc), iVar6 != 0)) &&

              (iVar6 = *(int *)(iVar6 + 4), iVar6 != 0)) &&

             (((*(uint *)(iVar6 + 0x2c) >> 0xd & 1) != 0 ||

              ((*(uint *)(iVar6 + 0x2c) >> 0xc & 1) != 0)))) {

            if (*(int *)(iVar6 + 0x4c) == 0) {

              piVar7 = &DAT_00d1ed24;

            }

            else {

              piVar7 = (int *)(*(int *)(iVar6 + 0x4c) + 4);

            }

            if (*piVar7 != DAT_00d1ed24) {

              FUN_0096f780();

              FUN_0096a6f0(param_1,1);

              stoChunkWriter_EndChunk();

            }

          }

        }

      }

      local_c4 = iVar1 + 1;

    } while (local_c4 < (int)local_bc);

  }

  local_14 = 0xffffffff;

  stoChunkWriter_EndChunk();

  ExceptionList = pvStack_1c;

  return 0;

}
