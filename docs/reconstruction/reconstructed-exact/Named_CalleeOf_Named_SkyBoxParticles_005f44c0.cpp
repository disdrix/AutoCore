// =============================================================================
// Named_CalleeOf_Named_SkyBoxParticles_005f44c0
// -----------------------------------------------------------------------------
// Stable ID: aa_005f44c0
// Callee of Named_SkyBoxParticles
// Address:   0x005f44c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_SkyBoxParticles: callee helper. Evidence string: "**GameUtils::createRagDoll() error. %d bones not found in model <%s>.". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "**GameUtils::createRagDoll() error. %d bones not found in model <%s>."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~351 non-empty decompiler lines.
//  - Control keywords: if×22, while×4, return×3, do×3, goto×3, for×1.
//  - Notable callees: FUN_005f5220×6, CONCAT31×5, block×5, FUN_005b3300×4, FUN_005f5190×3, FUN_007a4480×3, find×3, FUN_005d43e0×2.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_SkyBoxParticles
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

/* WARNING: Removing unreachable block (ram,0x005f4b94) */

/* WARNING: Removing unreachable block (ram,0x005f4bbf) */

/* WARNING: Removing unreachable block (ram,0x005f4ba3) */

/* WARNING: Removing unreachable block (ram,0x005f4b62) */

/* WARNING: Removing unreachable block (ram,0x005f4d45) */



uint32_t /* width from decompiler */ Named_CalleeOf_Named_SkyBoxParticles_005f44c0(int param_1,int param_2,int param_3)



{

  int iVar1;

  short sVar2;

  bool bVar3;

  uint uVar4;

  float *pfVar5;

  uint uVar6;

  char *pcVar7;

  int iVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ *puVar10;

  int *piVar11;

  void *pvVar12;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this;

  int iVar13;

  uint32_t /* width from decompiler */ *puVar14;

  uint uVar15;

  uint uVar16;

  uint uVar17;

  char cVar18;

  uint uStack_184;

  void *pvStack_180;

  uint uStack_17c;

  int local_178;

  uint local_174;

  uint uStack_168;

  uint local_164;

  uint32_t /* width from decompiler */ local_144 [2];

  int iStack_13c;

  uint8_t auStack_138 [8];

  uint local_130;

  uint local_12c;

  int iStack_128;

  uint local_11c;

  uint local_118;

  int aiStack_114 [3];

  uint local_108;

  uint local_104;

  int iStack_100;

  uint local_f4;

  uint local_f0;

  uint uStack_ec;

  uint32_t /* width from decompiler */ uStack_e8;

  int iStack_e0;

  void *pvStack_dc;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_d8 [32];

  uint32_t /* width from decompiler */ uStack_b8;

  uint32_t /* width from decompiler */ uStack_b4;

  uint32_t /* width from decompiler */ uStack_b0;

  uint32_t /* width from decompiler */ uStack_ac;

  uint8_t auStack_88 [48];

  uint32_t /* width from decompiler */ uStack_58;

  uint32_t /* width from decompiler */ uStack_54;

  uint32_t /* width from decompiler */ uStack_50;

  uint32_t /* width from decompiler */ uStack_4c;

  void *pvStack_48;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_44 [4];

  int iStack_40;

  uint8_t uStack_38;

  uint8_t uStack_30;

  uint8_t uStack_24;

  void *local_1c;

  uint8_t *puStack_18;

  int local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009a7aa4;

  local_1c = ExceptionList;

  iVar13 = *(int *)(*(int *)(param_3 + 0x14) + 0x2c);

  if (iVar13 == 0) {

    local_164 = 0;

  }

  else {

    local_164 = *(uint *)(iVar13 + 0xe4a4);

  }

  if ((((*(int *)(param_3 + 0x914) == 0) || (local_164 == 0)) || (param_1 == 0)) || (param_2 == 0))

  {

    ExceptionList = &local_1c;

    FUN_007a4480(0,

                 "**GameUtils::createRagDoll() error. Passed Params invalid Body(0x%X), World(0x%X), buffer(0x%X), bufSize(%d) passed in was NULL."

                 ,*(int *)(param_3 + 0x914));

    ExceptionList = local_1c;

    return 0;

  }

  ExceptionList = &local_1c;

  FUN_006483f0();

  local_14 = 0;

  FUN_00649a50();

  local_14._0_1_ = 1;

  FUN_00649d80();

  FUN_006499c0();

  local_144[0] = 0;

  local_14._0_1_ = 2;

  uVar4 = FUN_005f4380(param_1,param_2);

  iVar13 = *(int *)(*(int *)(param_3 + 0x914) + 0xa4);

  if (iVar13 == 0) {

    local_174 = 0;

LAB_005f45ed:

    if (uVar4 < 0x21) {

      FUN_005d4370();

      local_14._0_1_ = 3;

      if ((int)(local_104 & 0x7fffffff) < (int)uVar4) {

        FUN_005b3300();

      }

      local_108 = uVar4;

      FUN_005f5190();

      local_14._0_1_ = 4;

      if ((int)(local_12c & 0x7fffffff) < (int)local_174) {

        FUN_005b3300();

      }

      local_130 = local_174;

      FUN_005f5190();

      local_14._0_1_ = 5;

      if ((int)(local_f0 & 0x7fffffff) < (int)local_174) {

        FUN_005b3300();

      }

      local_f4 = local_174;

      FUN_005f5190();

      local_14 = CONCAT31(local_14._1_3_,6);

      if ((int)(local_118 & 0x7fffffff) < (int)uVar4) {

        FUN_005b3300();

      }

      local_11c = uVar4;

      operator_new__(uVar4 * 4);

      local_178 = (**(code **)*DAT_00b05060)();

      local_1c._0_1_ = 7;

      if (local_178 == 0) {

        local_178 = 0;

      }

      else {

        FUN_00404d80(local_178,0x20,uVar4);

      }

      local_1c = (void *)CONCAT31(local_1c._1_3_,6);

      uStack_184 = 0;

      (**(code **)(**(int **)(param_3 + 0x914) + 0x34))();

      uStack_168 = 0;

      uVar15 = uVar4;

      if (uStack_17c != 0) {

        pfVar5 = (float *)(local_178 + 0x1c);

        do {

          iVar13 = *(int *)(*(int *)(*(int *)(param_3 + 0x914) + 0xa4) + uStack_168 * 4);

          pcVar7 = *(char **)(*(int *)(iVar13 + 0xf4) + 8);

          if (pcVar7 == (char *)0x0) {

            pcVar7 = PTR_DAT_00afa2bc;

          }

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                    (abStack_d8,pcVar7);

          local_1c = (void *)CONCAT31(local_1c._1_3_,8);

          uVar6 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                  ::find(abStack_d8," ",0);

          if (uVar6 != *(uint *)npos_exref) {

            do {

              cVar18 = '_';

              uVar17 = 1;

              uVar16 = 1;

              uVar6 = std::

                      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

                      find(abStack_d8," ",0);

              std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

              replace(abStack_d8,uVar6,uVar16,uVar17,cVar18);

              uVar6 = std::

                      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

                      find(abStack_d8," ",0);

            } while (uVar6 != *(uint *)npos_exref);

          }

          pcVar7 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                   ::c_str(abStack_d8);

          iVar8 = FUN_006482d0(pcVar7);

          if (iVar8 == 0) {

            *(uint32_t /* width from decompiler */ *)((int)pvStack_180 + uStack_184 * 4) = 0;

            *(uint *)(aiStack_114[0] + uStack_184 * 4) = uStack_168;

            *(short *)(iStack_13c + uStack_168 * 2) = (short)uStack_184;

            uRam00000028 = 0x10009;

            FUN_00560e90(0);

            if ((uVar4 == 0) || (iVar8 = FUN_005f5120(), iVar8 == -1)) {

              pfVar5[-7] = DAT_00bc5630;

              pfVar5[-6] = DAT_00bc5634;

              pfVar5[-5] = DAT_00bc5638;

              pfVar5[-4] = DAT_00bc563c;

              *pfVar5 = 0.0;

              pfVar5[-1] = 0.0;

              pfVar5[-2] = 0.0;

              pfVar5[-3] = 0.0;

              *pfVar5 = g_flOne;

            }

            else {

              iVar1 = iVar8 * 0x50 + 0x10 + *(int *)(uVar4 + 8);

              pfVar5[-7] = *(float *)(iVar8 * 0x50 + 0x40 + *(int *)(uVar4 + 8));

              pfVar5[-6] = *(float *)(iVar1 + 0x34);

              pfVar5[-5] = *(float *)(iVar1 + 0x38);

              pfVar5[-4] = *(float *)(iVar1 + 0x3c);

              FUN_00567d20();

            }

            iVar13 = *(int *)(iVar13 + 0x148);

            bVar3 = false;

            while (iVar13 != -1) {

              if (bVar3) {

                if (iVar13 != -1) goto LAB_005f49b1;

                break;

              }

              sVar2 = *(short *)(iStack_13c + iVar13 * 2);

              if (sVar2 == -1) {

                iVar13 = *(int *)(*(int *)(*(int *)(*(int *)(param_3 + 0x914) + 0xa4) + iVar13 * 4)

                                 + 0x148);

              }

              else {

                *(short *)(iStack_128 + uStack_184 * 2) = sVar2;

              }

              bVar3 = sVar2 != -1;

            }

            *(uint16_t *)(iStack_128 + uStack_184 * 2) = 0xffff;

LAB_005f49b1:

            if (*(short *)(iStack_13c + uStack_168 * 2) == 0) {

              (**(code **)(**(int **)(param_3 + 0x914) + 0xc))();

              FUN_00412d20();

              uVar9 = FUN_00424bd0();

              puVar10 = (uint32_t /* width from decompiler */ *)FUN_00412d40(auStack_88,uVar9);

              puVar14 = (uint32_t /* width from decompiler */ *)(param_3 + 0x60);

              for (iVar13 = 0x10; iVar13 != 0; iVar13 = iVar13 + -1) {

                *puVar14 = *puVar10;

                puVar10 = puVar10 + 1;

                puVar14 = puVar14 + 1;

              }

            }

            uStack_184 = uStack_184 + 1;

            pfVar5 = pfVar5 + 8;

            uVar15 = local_164;

          }

          else {

            *(uint16_t *)(iStack_13c + uStack_168 * 2) = 0xffff;

          }

          *(short *)(iStack_100 + uStack_168 * 2) =

               (short)*(uint32_t /* width from decompiler */ *)

                       (*(int *)(*(int *)(*(int *)(param_3 + 0x914) + 0xa4) + uStack_168 * 4) +

                       0x148);

          local_1c = (void *)CONCAT31(local_1c._1_3_,6);

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_d8);

          uStack_168 = uStack_168 + 1;

        } while (uStack_168 < uStack_17c);

      }

      if ((uVar15 <= uStack_184) && (uStack_168 != 0)) {

        uVar4 = 0;

        if (uStack_184 != 0) {

          do {

            iVar13 = *(int *)(*(int *)(*(int *)(param_3 + 0x914) + 0xa4) +

                             *(int *)(aiStack_114[0] + uVar4 * 4) * 4);

            FUN_004e9530(&uStack_b8);

            FUN_004e96e0(abStack_d8,iVar13 + 0xb0);

            FUN_005eadb0();

            uStack_58 = uStack_b8;

            uStack_54 = uStack_b4;

            uStack_50 = uStack_b0;

            uStack_4c = uStack_ac;

            FUN_005f50a0();

            piVar11 = (int *)(*(int *)((int)pvStack_180 + uVar4 * 4) + 0xc);

            if ((piVar11 != (int *)0x0) && (iVar13 = *piVar11, iVar13 != 0)) {

              *(uint32_t /* width from decompiler */ *)(iVar13 + 8) = 2;

            }

            uVar4 = uVar4 + 1;

          } while (uVar4 < uStack_184);

        }

        pvVar12 = operator_new__(0);

        uStack_e8 = 0;

        uStack_ec = local_164;

        iStack_e0 = local_178;

        pvStack_dc = pvVar12;

        iVar13 = (**(code **)(*DAT_00b05060 + 0x10))(0x2c);

        *(uint16_t *)(iVar13 + 4) = 0x2c;

        uStack_24 = 10;

        uVar9 = FUN_00648c30(&local_f4);

        uStack_24 = 6;

        *(uint32_t /* width from decompiler */ *)(param_3 + 0x50) = uVar9;

        operator_delete__(pvVar12);

        operator_delete__((void *)0x0);

        (**(code **)(*DAT_00b05060 + 4))(pvStack_180);

        iVar13 = (**(code **)(*DAT_00b05060 + 0x10))(0x14,0xb);

        *(uint16_t *)(iVar13 + 4) = 0x14;

        uStack_30 = 0xb;

        uVar9 = FUN_005f5490(aiStack_114);

        *(uint32_t /* width from decompiler */ *)(param_3 + 0x54) = uVar9;

        uStack_30 = 6;

        iVar13 = (**(code **)(*DAT_00b05060 + 0x10))(0x14,0xb);

        *(uint16_t *)(iVar13 + 4) = 0x14;

        uStack_38 = 0xc;

        uVar9 = FUN_005f5490(local_144);

        *(uint32_t /* width from decompiler */ *)(param_3 + 0x58) = uVar9;

        uStack_38 = 6;

        iVar13 = (**(code **)(*DAT_00b05060 + 0x10))(0x14,0xb);

        *(uint16_t *)(iVar13 + 4) = 0x14;

        iStack_40._0_1_ = 0xd;

        uVar9 = FUN_00648500(auStack_138);

        *(uint32_t /* width from decompiler */ *)(param_3 + 0x5c) = uVar9;

        iStack_40._0_1_ = 5;

        FUN_005f5220();

        iStack_40._0_1_ = 4;

        FUN_005f5220();

        iStack_40._0_1_ = 3;

        FUN_005f5220();

        iStack_40._0_1_ = 2;

        FUN_005d43e0();

        iStack_40 = (uint)iStack_40._1_3_ << 8;

        FUN_00646310();

        iStack_40 = 0xffffffff;

        FUN_00648330();

        ExceptionList = pvStack_48;

        return 1;

      }

      this = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

             FUN_0096a630();

      local_1c._0_1_ = 9;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::c_str(this)

      ;

      FUN_007a4480(0,"**GameUtils::createRagDoll() error. %d bones not found in model <%s>.",

                   uVar15 - uStack_184);

      local_1c = (void *)CONCAT31(local_1c._1_3_,6);

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_44);

      operator_delete__(pvStack_180);

      (**(code **)(*DAT_00b05060 + 4))();

      local_14._0_1_ = 5;

      FUN_005f5220();

      local_14._0_1_ = 4;

      FUN_005f5220();

      local_14._0_1_ = 3;

      FUN_005f5220();

      local_14._0_1_ = 2;

      FUN_005d43e0();

      goto LAB_005f4e66;

    }

  }

  else {

    local_174 = *(int *)(*(int *)(param_3 + 0x914) + 0xa8) - iVar13 >> 2;

    if (local_174 < 0x41) goto LAB_005f45ed;

  }

  FUN_007a4480(0);

LAB_005f4e66:

  FUN_00691630();

  local_14 = (uint)local_14._1_3_ << 8;

  FUN_00646310();

  local_14 = 0xffffffff;

  FUN_00648330();

  ExceptionList = local_1c;

  return 0;

}
