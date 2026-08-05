// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO_005b7250
// -----------------------------------------------------------------------------
// Stable ID: aa_005b7250
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCreature_Setup
// Address:   0x005b7250  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCreature_Setup: creature/setup helper. Evidence string: "SpeedTreeRT Error: %s\n". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "SpeedTreeRT Error: %s\n"
//   - "\nFatal Error, cannot compute tree [%s]\n\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~195 non-empty decompiler lines.
//  - Control keywords: if×13, return×2.
//  - Notable callees: FUN_005b7770×3, CONCAT31×2, FUN_00404ba0×2, FUN_00416490×2, FUN_005b4600×2, FUN_005b71a0×2, FUN_00685ca0×2, FUN_0096ef70×2.
//  - Strings: "SpeedTreeRT Error: %s\n"; "\nFatal Error, cannot compute tree [%s]\n\n".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCreature_Setup
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint8_t __thiscall

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO_005b7250(int param_1,uint32_t /* width from decompiler */ param_2,int param_3,uint32_t /* width from decompiler */ param_4,float param_5,

            float param_6)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  int *piVar3;

  void *pvVar4;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar5;

  char *pcVar6;

  float fVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint8_t local_c1;

  void *local_c0;

  uint32_t /* width from decompiler */ local_bc [2];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_b4 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_98 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_7c [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_60 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_44 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a6a98;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *(int *)(param_1 + 0x174) = param_3;

  if (param_3 == 0) {

    local_c1 = 0;

  }

  else {

    local_c1 = 0;

    if (*(int *)(param_1 + 0x30) == 0) {

      local_c0 = operator_new(0x9c);

      local_4 = 0;

      if (local_c0 == (void *)0x0) {

        uVar2 = 0;

      }

      else {

        uVar2 = FUN_0068a690();

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = uVar2;

    }

    local_4 = 0xffffffff;

    FUN_00685ed0(1);

    if (*(int *)(*(int *)(param_1 + 0x174) + 0x128) < 1) {

      FUN_007b6a20(param_2);

      piVar3 = (int *)FUN_007b7420(param_2);

      if (piVar3 == (int *)0x0) {

        local_c1 = 0;

      }

      else {

        local_bc[0] = 0;

        uVar2 = (**(code **)(*piVar3 + 0x34))(local_bc);

        cVar1 = FUN_0068b360(uVar2,local_c0);

        (**(code **)*piVar3)(1);

        if (cVar1 == '\0') {

          uVar2 = FUN_00685ca0();

          pcVar6 = "SpeedTreeRT Error: %s\n";

        }

        else {

          FUN_00686d30(0x3f800000,0xbf800000,0xbf800000);

          FUN_00686ec0(0,4);

          FUN_00686530(0);

          FUN_00686640(0);

          FUN_00686760(0);

          FUN_00686ad0(0);

          FUN_006869c0(0);

          FUN_00686c00(0);

          FUN_006868b0(1);

          if ((0.0 <= param_5) && (0.0 <= param_6)) {

            FUN_006863a0(param_5,param_6);

          }

          cVar1 = FUN_00688680(0,param_4,1);

          if (cVar1 != '\0') {

            FUN_00687320(param_1 + 0x8c);

            FUN_006868a0(1);

            FUN_00685c70(1);

            uVar2 = FUN_00686870();

            FUN_005b7770(uVar2);

            uVar2 = FUN_00686890();

            FUN_005b7770(uVar2);

            uVar2 = FUN_00686880();

            FUN_005b7770(uVar2);

            fVar7 = *(float *)(param_1 + 0xa0) - *(float *)(param_1 + 0x94);

            FUN_00685c80(fVar7,fVar7 * DAT_00aaa688);

            pvVar4 = operator_new(0x1c);

            local_4 = 1;

            if (pvVar4 == (void *)0x0) {

              uVar2 = 0;

            }

            else {

              uVar2 = FUN_00685ac0();

            }

            local_4 = 0xffffffff;

            *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = uVar2;

            FUN_00689d90(uVar2);

            if (*(int *)(param_1 + 0x170) == 0) {

              pvVar4 = operator_new(4);

              local_4 = 2;

              if (pvVar4 == (void *)0x0) {

                uVar2 = 0;

              }

              else {

                uVar2 = FUN_0096ef70();

              }

              *(uint32_t /* width from decompiler */ *)(param_1 + 0x170) = uVar2;

              local_4 = 0xffffffff;

              std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

              basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        (abStack_b4,(char *)**(uint32_t /* width from decompiler */ **)(param_1 + 0x34));

              local_4 = 3;

              uVar2 = FUN_005b4600(abStack_7c);

              local_4._0_1_ = 4;

              pbVar5 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        *)FUN_00416490(abStack_44,uVar2,&DAT_00a2c53c);

              uVar8 = 0;

              local_4._0_1_ = 5;

              pcVar6 = std::

                       basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                       ::c_str(pbVar5);

              uVar2 = FUN_00404ba0(pcVar6);

              FUN_0096f3e0(uVar2,uVar8);

              local_4._0_1_ = 4;

              std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

              ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        (abStack_44);

              local_4 = CONCAT31(local_4._1_3_,3);

              std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

              ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        (abStack_7c);

              local_4 = 0xffffffff;

              std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

              ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        (abStack_b4);

            }

            if (*(int *)(param_1 + 0x24) == 0) {

              pvVar4 = operator_new(4);

              local_4 = 6;

              if (pvVar4 == (void *)0x0) {

                uVar2 = 0;

              }

              else {

                uVar2 = FUN_0096ef70();

              }

              *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = uVar2;

              local_4 = 0xffffffff;

              std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

              basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        (abStack_98,*(char **)(*(int *)(param_1 + 0x34) + 0x14));

              local_4 = 7;

              uVar2 = FUN_005b4600(abStack_28);

              local_4._0_1_ = 8;

              pbVar5 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        *)FUN_00416490(abStack_60,uVar2,&DAT_00a2c53c);

              uVar8 = 0;

              local_4._0_1_ = 9;

              pcVar6 = std::

                       basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                       ::c_str(pbVar5);

              uVar2 = FUN_00404ba0(pcVar6);

              FUN_0096f3e0(uVar2,uVar8);

              local_4._0_1_ = 8;

              std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

              ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        (abStack_60);

              local_4 = CONCAT31(local_4._1_3_,7);

              std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

              ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        (abStack_28);

              local_4 = 0xffffffff;

              std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

              ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        (abStack_98);

            }

            FUN_005b71a0(0);

            ExceptionList = local_c;

            return 1;

          }

          uVar2 = FUN_00685ca0();

          pcVar6 = "\nFatal Error, cannot compute tree [%s]\n\n";

        }

        FUN_007a4480(1,pcVar6,uVar2);

      }

    }

    else {

      FUN_005b71a0(1);

      local_c1 = 1;

    }

  }

  ExceptionList = local_c;

  return local_c1;

}
