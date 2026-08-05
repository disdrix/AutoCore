// =============================================================================
// Named_CalleeOf_Named_gfxDevice_00965ab0
// -----------------------------------------------------------------------------
// Stable ID: aa_00965ab0
// Callee of Named_gfxDevice
// Address:   0x00965ab0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxDevice: callee helper. Evidence string: "Max Weights Per Vertex: %d". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Max Weights Per Vertex: %d"
//   - "  TM: %s, RM: %s"
//   - "    "
//   - "(All)"
//   - "(ID=%d)"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~415 non-empty decompiler lines.
//  - Control keywords: if×32, do×3, while×3, return×2, for×1.
//  - Notable callees: FUN_00759730×7, FUN_00755ab0×6, FUN_0040aef0×3, sprintf×3, CONCAT13×2, CONCAT31×2, FUN_0040aeb0×2, FUN_0076c3c0×2.
//  - Strings: "Max Weights Per Vertex: %d"; "  TM: %s, RM: %s"; "    "; "(All)".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_gfxDevice
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

/* WARNING: Type propagation algorithm not settling */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void Named_CalleeOf_Named_gfxDevice_00965ab0(int param_1)



{

  float *pfVar1;

  int iVar2;

  float fVar3;

  int *piVar4;

  float fVar5;

  float *pfVar6;

  int iVar7;

  uint32_t /* width from decompiler */ **ppuVar8;

  int iVar9;

  int *piVar10;

  int *piVar11;

  float extraout_ECX;

  float extraout_ECX_00;

  float extraout_ECX_01;

  uint32_t /* width from decompiler */ *puVar12;

  uint32_t /* width from decompiler */ *puVar13;

  float fStack_190;

  uint32_t /* width from decompiler */ *******pppppppuStack_18c;

  float fStack_188;

  undefined *puStack_184;

  char *_Format;

  int iStack_15c;

  uint32_t /* width from decompiler */ *puStack_154;

  undefined **local_14c;

  int *local_148;

  uint32_t /* width from decompiler */ *local_144;

  float local_140;

  int *piStack_13c;

  uint32_t /* width from decompiler */ *local_138;

  int *piStack_134;

  uint32_t /* width from decompiler */ uStack_130;

  uint32_t /* width from decompiler */ local_12c;

  uint8_t uStack_128;

  uint8_t uStack_127;

  uint8_t uStack_126;

  uint8_t uStack_125;

  uint8_t uStack_124;

  uint8_t uStack_123;

  uint8_t uStack_122;

  uint8_t uStack_121;

  int iStack_120;

  undefined **ppuStack_11c;

  uint32_t /* width from decompiler */ *puStack_118;

  int iStack_114;

  uint32_t /* width from decompiler */ *puStack_110;

  int iStack_10c;

  int *piStack_108;

  uint8_t uStack_104;

  uint8_t uStack_103;

  uint8_t uStack_102;

  uint32_t /* width from decompiler */ *puStack_100;

  uint32_t /* width from decompiler */ *puStack_fc;

  int iStack_f8;

  int iStack_f4;

  int iStack_e8;

  int iStack_e4;

  int iStack_e0;

  uint32_t /* width from decompiler */ *******apppppppuStack_dc [5];

  uint uStack_c8;

  uint8_t *puStack_c4;

  int iStack_b8;

  int iStack_b4;

  int iStack_b0;

  int iStack_ac;

  uint32_t /* width from decompiler */ ******appppppuStack_a0 [34];

  void *pvStack_18;

  void *local_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0xffffffff;

  puStack_10 = &LAB_009b2edc;

  local_14 = ExceptionList;

  if (*(char *)(param_1 + 0x40) == '\0') {

    ExceptionList = &local_14;

    iVar7 = FUN_0076c3c0();

    local_140 = (float)(iVar7 - *(int *)(param_1 + 0x30));

    fVar3 = (float)(int)local_140;

    if ((int)local_140 < 0) {

      fVar3 = fVar3 + _DAT_00aaa5dc;

    }

    fVar3 = fVar3 * _DAT_00aaa9f4;

  }

  else {

    ExceptionList = &local_14;

    iVar7 = FUN_0076c3c0();

    local_140 = (float)(iVar7 - *(int *)(param_1 + 0x30));

    fVar3 = (float)(int)local_140;

    if ((int)local_140 < 0) {

      fVar3 = fVar3 + _DAT_00aaa5dc;

    }

    fVar3 = fVar3 * g_flHardKillInterpolate;

  }

  fVar5 = g_flOne;

  local_144 = (uint32_t /* width from decompiler */ *)(*(float *)(param_1 + 0x48) + fVar3);

  local_12c = (uint32_t /* width from decompiler */ *)g_flOne;

  local_138 = (uint32_t /* width from decompiler */ *)0x0;

  if (0.0 <= (float)local_144) {

    ppuVar8 = (uint32_t /* width from decompiler */ **)&local_12c;

    if ((float)local_144 <= g_flOne) {

      ppuVar8 = &local_144;

    }

  }

  else {

    ppuVar8 = &local_138;

  }

  puVar13 = *ppuVar8;

  *(uint32_t /* width from decompiler */ **)(param_1 + 0x48) = puVar13;

  if ((float)puVar13 != 0.0) {

    if ((*(char *)(param_1 + 0x41) != '\0') || ((float)puVar13 != fVar5)) {

      (**(code **)(**(int **)(param_1 + 0x34) + 8))();

      (**(code **)(**(int **)(param_1 + 0x34) + 4))();

      FUN_00758c80();

      iVar7 = *(int *)(param_1 + 0x34);

      iVar9 = *(int *)(iVar7 + 0x68) + 1;

      *(int *)(iVar7 + 0x68) = iVar9;

      *(float *)(iVar7 + 0x74) = (float)-iVar9;

      if (*(int *)(iVar7 + 0x70) < iVar9) {

        *(int *)(iVar7 + 0x70) = iVar9;

      }

      local_140 = *(float *)(param_1 + 0x48) * DAT_00aaa6f8;

      local_14c = (undefined **)(int)ROUND(local_140);

      puVar13 = *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0x3c) + 0x7c);

      pfVar1 = (float *)(param_1 + 0x3c);

      iStack_15c = (int)puVar13 / 2;

      local_138 = puVar13;

      if ((*(int *)(param_1 + 0x5c) == 0) ||

         (iVar7 = *(int *)(param_1 + 0x60) - *(int *)(param_1 + 0x5c), iVar7 / 0xc == 0)) {

        fStack_190 = (float)CONCAT31((int3)((uint)iVar7 >> 8),local_14c._0_1_);

        puStack_184 = (undefined *)0x0;

        fStack_188 = -NAN;

        pppppppuStack_18c = (uint32_t /* width from decompiler */ *******)0xaa3f88;

        local_148 = (int *)&fStack_190;

        FUN_0040aeb0(&fStack_190);

        FUN_00759730(*(uint32_t /* width from decompiler */ *)(param_1 + 0x34),&stack0xfffffea0,&stack0xfffffe9c);

        FUN_00755ab0();

      }

      else {

        uStack_130 = CONCAT13(local_14c._0_1_,0xeaeaea);

        uStack_125 = local_14c._0_1_;

        uStack_121 = local_14c._0_1_;

        uStack_122 = 0x8c;

        uStack_124 = 0x8c;

        uStack_126 = 0xeb;

        uStack_127 = 0x6e;

        uStack_128 = 200;

        local_12c = (uint32_t /* width from decompiler */ *)CONCAT13(local_14c._0_1_,0x800000);

        local_12c = (uint32_t /* width from decompiler */ *)CONCAT22(local_12c._2_2_,0x8000);

        local_12c = (uint32_t /* width from decompiler */ *)CONCAT31(local_12c._1_3_,0x80);

        uStack_123 = 0xff;

        fStack_190 = 1.380951e-38;

        FUN_004611e0();

        puStack_184 = (undefined *)0x0;

        fStack_188 = -NAN;

        pppppppuStack_18c = (uint32_t /* width from decompiler */ *******)0xaa3f68;

        fStack_190 = extraout_ECX;

        FUN_0040aeb0(&fStack_190);

        FUN_00759730(*(uint32_t /* width from decompiler */ *)(param_1 + 0x34),&stack0xfffffea0,&uStack_130);

        local_148 = *(int **)(param_1 + 0x60);

        for (piStack_13c = *(int **)(param_1 + 0x5c); piStack_13c != local_148;

            piStack_13c = piStack_13c + 3) {

          iStack_15c = (int)local_138 + iStack_15c + 5;

          fVar3 = *(float *)(*piStack_13c + 8);

          puStack_184 = (undefined *)0x0;

          fStack_188 = -NAN;

          pppppppuStack_18c = (uint32_t /* width from decompiler */ *******)0xaa3f60;

          local_144 = &fStack_190;

          fStack_190 = fVar3;

          FUN_0040aef0(&fStack_190);

          FUN_00759730(*(uint32_t /* width from decompiler */ *)(param_1 + 0x34),&stack0xfffffea0,&uStack_130);

          piVar10 = (int *)FUN_00755ab0();

          iVar7 = *piVar10;

          puStack_184 = (undefined *)0x0;

          fStack_188 = -NAN;

          if (*(int *)((int)fVar3 + 0x1cc) == 0) {

            piVar10 = &DAT_00d1ed24;

          }

          else {

            piVar10 = (int *)(*(int *)((int)fVar3 + 0x1cc) + 4);

          }

          pppppppuStack_18c = (uint32_t /* width from decompiler */ *******)*piVar10;

          if ((uint32_t /* width from decompiler */ *******)*piVar10 == (uint32_t /* width from decompiler */ *******)0x0) {

            pppppppuStack_18c = (uint32_t /* width from decompiler */ *******)PTR_DAT_00afa2bc;

          }

          local_144 = &fStack_190;

          fStack_190 = extraout_ECX_00;

          FUN_0040aef0(&fStack_190);

          FUN_00759730(*(uint32_t /* width from decompiler */ *)(param_1 + 0x34),&stack0xfffffea0,&stack0xfffffe9c);

          piVar10 = (int *)FUN_00755ab0();

          puVar13 = (uint32_t /* width from decompiler */ *)((int)puVar13 + *piVar10 + iVar7);

          if ((int)puStack_154 < (int)puVar13) {

            puStack_154 = puVar13;

          }

          if (0 < piStack_13c[2]) {

            iStack_15c = iStack_15c + (int)local_138;

            iVar7 = (int)local_138 * 2;

            sprintf((char *)appppppuStack_a0,"Max Weights Per Vertex: %d");

            puStack_184 = (undefined *)0x0;

            fStack_188 = -NAN;

            pppppppuStack_18c = appppppuStack_a0;

            local_144 = &fStack_190;

            fStack_190 = extraout_ECX_01;

            FUN_0040aef0(&fStack_190);

            FUN_00759730(*(uint32_t /* width from decompiler */ *)(param_1 + 0x34),&stack0xfffffea0,&stack0xfffffe9c);

            piVar10 = (int *)FUN_00755ab0();

            puVar13 = (uint32_t /* width from decompiler */ *)(iVar7 + *piVar10);

          }

          if ((int)puStack_154 < (int)puVar13) {

            puStack_154 = puVar13;

          }

          puStack_fc = (uint32_t /* width from decompiler */ *)FUN_007532a0();

          piStack_134 = (int *)((int)fVar3 + 0x40);

          local_14c = &PTR_s_Static_00afa374;

          do {

            ppuStack_11c = &PTR_s_Normal_00afa364;

            piVar10 = piStack_134;

            do {

              puVar12 = local_138;

              if ((*piVar10 != 0) &&

                 (local_144 = (uint32_t /* width from decompiler */ *)(piVar10[1] - *piVar10 >> 2),

                 local_144 != (uint32_t /* width from decompiler */ *)0x0)) {

                iStack_15c = iStack_15c + (int)local_138 * 2;

                puStack_184 = (undefined *)0x9661b9;

                sprintf((char *)appppppuStack_a0,"  TM: %s, RM: %s");

                puStack_184 = (undefined *)0x0;

                fStack_188 = -NAN;

                pppppppuStack_18c = appppppuStack_a0;

                local_144 = &fStack_190;

                piVar11 = (int *)*pfVar1;

                pfVar6 = &fStack_190;

                if ((piVar11 != (int *)0x0) &&

                   (piVar11[1] = piVar11[1] + 1, pfVar6 = &fStack_190, piVar11[1] == 1)) {

                  (**(code **)(*piVar11 + 4))();

                  pfVar6 = (float *)local_144;

                }

                local_144 = pfVar6;

                fStack_190 = *pfVar1;

                FUN_00759730(*(uint32_t /* width from decompiler */ *)(param_1 + 0x34),&stack0xfffffea0,&uStack_128);

                piVar11 = (int *)FUN_00755ab0();

                if ((int)puStack_154 < *piVar11 + (int)puVar12) {

                  puStack_154 = (uint32_t /* width from decompiler */ *)(*piVar11 + (int)puVar12);

                }

                std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

                basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                          ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                            *)&iStack_e0);

                piVar11 = piStack_13c;

                local_14 = (void *)0x0;

                if (*piVar10 == 0) {

                  local_140 = 0.0;

                }

                else {

                  local_140 = (float)(piVar10[1] - *piVar10 >> 2);

                }

                iStack_120 = 0;

                puVar13 = puVar12;

                if (0 < (int)local_140) {

                  do {

                    puVar12 = *(uint32_t /* width from decompiler */ **)(*piVar10 + iStack_120 * 4);

                    local_144 = puVar12;

                    std::

                    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

                    operator=((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                               *)&iStack_e0,"    ");

                    std::

                    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

                    operator+=((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                                *)&iStack_e0,(char *)*puVar12);

                    if ((int)puVar12[2] < 0) {

                      _Format = "(All)";

                    }

                    else {

                      _Format = "(ID=%d)";

                    }

                    sprintf((char *)appppppuStack_a0,_Format);

                    std::

                    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

                    operator+=((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                                *)&iStack_e0,(char *)appppppuStack_a0);

                    puStack_184 = (undefined *)0x0;

                    fStack_188 = -NAN;

                    pppppppuStack_18c = apppppppuStack_dc[0];

                    if (puStack_fc == puVar12) {

                      if (uStack_c8 < 0x10) {

                        pppppppuStack_18c = apppppppuStack_dc;

                      }

                      puStack_c4 = (uint8_t *)&fStack_190;

                      piVar4 = (int *)*pfVar1;

                      pfVar6 = &fStack_190;

                      if ((piVar4 != (int *)0x0) &&

                         (piVar4[1] = piVar4[1] + 1, pfVar6 = &fStack_190, piVar4[1] == 1)) {

                        (**(code **)(*piVar4 + 4))();

                        pfVar6 = (float *)puStack_c4;

                      }

                      puStack_c4 = (uint8_t *)pfVar6;

                      puVar12 = (uint32_t /* width from decompiler */ *)&uStack_124;

                    }

                    else {

                      if (uStack_c8 < 0x10) {

                        pppppppuStack_18c = apppppppuStack_dc;

                      }

                      puStack_c4 = (uint8_t *)&fStack_190;

                      piVar4 = (int *)*pfVar1;

                      pfVar6 = &fStack_190;

                      if ((piVar4 != (int *)0x0) &&

                         (piVar4[1] = piVar4[1] + 1, pfVar6 = &fStack_190, piVar4[1] == 1)) {

                        (**(code **)(*piVar4 + 4))();

                        pfVar6 = (float *)puStack_c4;

                      }

                      puStack_c4 = (uint8_t *)pfVar6;

                      puVar12 = &local_12c;

                    }

                    fStack_190 = *pfVar1;

                    FUN_00759730(*(uint32_t /* width from decompiler */ *)(param_1 + 0x34),&stack0xfffffea0,puVar12);

                    FUN_00755ab0();

                    piStack_108 = (int *)0x0;

                    uStack_104 = 0;

                    uStack_103 = 0;

                    uStack_102 = 0;

                    local_14._0_1_ = 1;

                    piVar4 = (int *)*piVar11;

                    if ((piVar4 != (int *)0x0) && (piVar4[1] = piVar4[1] + 1, piVar4[1] == 1)) {

                      (**(code **)(*piVar4 + 4))();

                    }

                    uStack_104 = (uint8_t)piVar11[1];

                    uStack_103 = *(uint8_t *)((int)piVar11 + 5);

                    uStack_102 = *(uint8_t *)((int)piVar11 + 6);

                    puStack_100 = local_144;

                    puVar12 = (uint32_t /* width from decompiler */ *)(iStack_f8 + (int)puVar13);

                    iStack_10c = iStack_f4 + iStack_15c;

                    puStack_118 = puVar13;

                    iStack_114 = iStack_15c;

                    puStack_110 = puVar12;

                    piStack_108 = piVar4;

                    FUN_00460f90();

                    local_14 = (void *)((uint)local_14._1_3_ << 8);

                    if (piStack_108 != (int *)0x0) {

                      piVar4 = piStack_108 + 1;

                      *piVar4 = *piVar4 + -1;

                      if (*piVar4 == 0) {

                        (**(code **)(*piStack_108 + 8))();

                      }

                    }

                    iStack_120 = iStack_120 + 1;

                    puVar13 = puVar12;

                  } while (iStack_120 < (int)local_140);

                }

                puVar13 = local_138;

                if ((int)puStack_154 < (int)puVar12) {

                  puStack_154 = puVar12;

                }

                local_14 = (void *)0xffffffff;

                std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

                ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                          ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                            *)&iStack_e0);

              }

              ppuStack_11c = ppuStack_11c + 1;

              piVar10 = piVar10 + 0x14;

            } while ((int)ppuStack_11c < 0xafa378);

            piStack_134 = piStack_134 + 4;

            local_14c = local_14c + 1;

          } while ((int)local_14c < 0xafa388);

        }

      }

      iVar7 = *(int *)(param_1 + 0x34);

      *(int *)(iVar7 + 0x68) = *(int *)(iVar7 + 0x68) + -1;

      iVar9 = *(int *)(iVar7 + 0x68);

      *(float *)(iVar7 + 0x74) = (float)-iVar9;

      if (*(int *)(iVar7 + 0x70) < iVar9) {

        *(int *)(iVar7 + 0x70) = iVar9;

      }

      (**(code **)(**(int **)(param_1 + 0x34) + 8))();

      local_140 = *(float *)(param_1 + 0x48) * DAT_00a27c24;

      iStack_b0 = DAT_00d1f024 + (int)local_14c;

      iStack_ac = (int)local_148 + DAT_00d1f028;

      iStack_b8 = DAT_00d1f024;

      iVar7 = uStack_130 / 2;

      iStack_b4 = DAT_00d1f028;

      iStack_e8 = DAT_00d1f024 + iVar7;

      iStack_e4 = DAT_00d1f028 + iVar7;

      iStack_e0 = iStack_b0 + -iVar7;

      apppppppuStack_dc[0] = (uint32_t /* width from decompiler */ *******)(iStack_ac + -iVar7);

      piStack_13c = (int *)(int)ROUND(local_140);

      puStack_184 = &DAT_00d1ec78;

      fStack_188 = (float)(int)apppppppuStack_dc[0];

      pppppppuStack_18c = (uint32_t /* width from decompiler */ *******)(float)iStack_e0;

      fStack_190 = (float)iStack_e4;

      FUN_00758460((float)iStack_e8);

      FUN_00757ff0();

      FUN_00759090();

      iVar7 = *(int *)(param_1 + 0x4c);

      iVar9 = *(int *)(param_1 + 0x50);

      if ((*(uint *)(param_1 + 0x54) & 1) != 0) {

        iVar7 = (*(int *)(*(int *)(param_1 + 0x38) + 0x80) - (int)local_14c) - iVar7;

      }

      if ((*(uint *)(param_1 + 0x54) & 2) != 0) {

        iVar9 = (*(int *)(*(int *)(param_1 + 0x38) + 0x84) - *(int *)(param_1 + 0x50)) -

                (int)local_148;

      }

      iVar2 = *(int *)(param_1 + 0x34);

      *(int *)(iVar2 + 0x78) = iVar7;

      *(int *)(iVar2 + 0x7c) = iVar9;

      *(uint8_t *)(param_1 + 0x41) = 0;

    }

    ExceptionList = local_14;

    return;

  }

  (**(code **)(**(int **)(param_1 + 0x34) + 4))();

  ExceptionList = pvStack_18;

  return;

}
