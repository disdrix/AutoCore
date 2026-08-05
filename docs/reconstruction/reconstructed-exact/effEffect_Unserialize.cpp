// =============================================================================
// effEffect_Unserialize
// -----------------------------------------------------------------------------
// Stable ID: aa_00970260
// Address:   0x00970260  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

/* effEffect::Unserialize  [owns string "Invalid TAG unserializing effEffect" @ 00a9ec1c]
   Reads an EFCT (file bytes "TCFE") chunk, version 3: body = ISTR ("RTSI") string chunk with the
   .fx effect name (e.g. NDHumanCar.fx, PalDiffMapNorSpecGlossMap.fx) + N PARM ("MRAP") parameter
   chunks.
   PARM v2 body = name\0 + u32 valueType + value:  1=bool(u32), 2=int(u32), 3=float array {u32 count
   + floats; count 16 = 4x4 matrix e.g. TexCoordTransform0}, 4=inline string\0, 5=string as nested
   ISTR chunk (texture names).
   Shader sources ship in effects.glm. Vehicle tint (NDVehicleTint.sha): diffuse.rgb =
   lerp(diffuse.rgb, tint.r*MatColorPrimary + tint.b*MatColorSecondary, tint.a), tint atlas =
   <diffuse-stem>_NN_tint.dds. */

uint32_t /* width from decompiler */ effEffect_Unserialize(uint32_t /* width from decompiler */ *param_1,int param_2)

{
  bool bVar1;
  uint32_t /* width from decompiler */ *puVar2;
  int iVar3;
  void *pvVar4;
  char *****pppppcVar5;
  uint32_t /* width from decompiler */ *****pppppuVar6;
  uint32_t /* width from decompiler */ uVar7;
  char *pcVar8;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_140 [4];
  char ****local_13c [5];
  uint local_128;
  uint32_t /* width from decompiler */ local_124;
  uint32_t /* width from decompiler */ local_120;
  int local_11c;
  uint32_t /* width from decompiler */ local_118;
  int local_114;
  char local_108;
  int local_104;
  uint local_100;
  uint8_t local_fc [4];
  int local_f8;
  uint8_t local_f4 [4];
  uint32_t /* width from decompiler */ local_f0;
  uint32_t /* width from decompiler */ local_ec;
  uint32_t /* width from decompiler */ local_e8;
  float local_e4;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_e0 [4];
  uint32_t /* width from decompiler */ ****local_dc [5];
  uint local_c8;
  char local_bc;
  int local_b4;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_a8 [4];
  uint32_t /* width from decompiler */ ****local_a4 [5];
  uint local_90;
  int local_84;
  int local_74;
  uint8_t local_60 [68];
  void *local_1c;
  uint8_t *puStack_18;
  uint local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_009b261b;
  local_1c = ExceptionList;
  ExceptionList = &local_1c;
  stoChunkReader_EnterChunkScope(param_2);
  local_14 = 0;
  if (local_104 == 0x45464354) {
    if (local_100 == 1) {
      pcVar8 = "DX8 geo files are not supported, please re-export";
      uVar7 = 0x30f;
    }
    else {
      if ((1 < local_100) && (local_100 < 4)) {
        local_120 = 0;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_140);
        local_14 = CONCAT31(local_14._1_3_,1);
        if (local_100 == 2) {
          FUN_00439a20(param_2);
          pppppcVar5 = (char *****)local_13c[0];
          if (local_128 < 0x10) {
            pppppcVar5 = local_13c;
          }
          puVar2 = (uint32_t /* width from decompiler */ *)FUN_00404ba0(pppppcVar5);
          if (&local_120 != puVar2) {
            local_120 = *puVar2;
          }
        }
        else {
          FUN_0096a7f0(&local_120,param_2);
        }
        iVar3 = FUN_009701d0(&local_120);
        if (-1 < iVar3) {
          iVar3 = FUN_0076a900();
          do {
            if (iVar3 != 0x5041524d) {
              FUN_00752a80();
              FUN_0096f740();
              local_14 = local_14 & 0xffffff00;
              std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
              ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        (local_140);
              local_14 = 0xffffffff;
              if (local_108 != '\0') {
                FUN_00769e40();
              }
              ExceptionList = local_1c;
              return 0;
            }
            stoChunkReader_EnterChunkScope(param_2);
            local_14 = CONCAT31(local_14._1_3_,2);
            if (*(int *)(param_2 + 0x4044) == 0) {
              FUN_00436f10();
            }
            else {
              FUN_0076a200();
            }
            if (*(int *)(param_2 + 0x4044) == 0) {
              FUN_00437050(&local_118);
            }
            else {
              FUN_00768760(&local_118);
            }
            switch(local_118) {
            case 1:
              FUN_00439a00();
              FUN_0043eea0(&local_11c);
              bVar1 = std::
                      operator==<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                                (local_140,"AlphaTestEnable");
              if ((bVar1) && (local_11c != 0)) {
                FUN_0096ff50("Alpha_Test");
                *(uint8_t *)(param_1 + 1) = 1;
              }
              break;
            case 2:
              FUN_00439a00();
              FUN_0043eea0(local_f4);
              break;
            case 3:
              pppppcVar5 = (char *****)local_13c[0];
              if (local_128 < 0x10) {
                pppppcVar5 = local_13c;
              }
              FUN_00752370(&local_f8,pppppcVar5);
              iVar3 = local_f8;
              if (-1 < local_f8) {
                FUN_00439a00();
                FUN_00752a30(*param_1,iVar3);
                if (local_84 == 0) {
                  if (local_74 == 0) {
                    FUN_0043b570();
                    FUN_0043eea0(local_fc);
                  }
                  else {
                    pvVar4 = operator_new__(local_114 * 4);
                    stoChunkReader_readF32Array(param_2);
                    FUN_0043eea0(pvVar4);
                    operator_delete__(pvVar4);
                  }
                }
                else if (local_84 == 1) {
                  if (local_114 < 5) {
                    local_f0 = 0;
                    local_ec = 0;
                    local_e8 = 0;
                    local_e4 = g_flOne;
                    stoChunkReader_readF32Array(param_2);
                    pppppcVar5 = (char *****)local_13c[0];
                    if (local_128 < 0x10) {
                      pppppcVar5 = local_13c;
                    }
                    FUN_009700f0(pppppcVar5,&local_f0);
                  }
                  else {
LAB_00970586:
                    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effEffect.cpp"
                                   ,0x374,3,"Unimplemented code reached");
                  }
                }
                else {
                  if ((local_84 != 2) && (local_84 != 3)) goto LAB_00970586;
                  FUN_0043edb0();
                  FUN_0043eea0(local_60);
                }
              }
              break;
            case 4:
              std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
              basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_e0)
              ;
              local_14 = CONCAT31(local_14._1_3_,4);
              FUN_00439a20(param_2);
              pppppcVar5 = (char *****)local_13c[0];
              if (local_128 < 0x10) {
                pppppcVar5 = local_13c;
              }
              pcVar8 = strstr((char *)pppppcVar5,"Phase");
              if (pcVar8 == (char *)0x0) {
                pppppuVar6 = (uint32_t /* width from decompiler */ *****)local_dc[0];
                if (local_c8 < 0x10) {
                  pppppuVar6 = local_dc;
                }
                FUN_0043eea0(pppppuVar6);
              }
              else {
                pppppuVar6 = (uint32_t /* width from decompiler */ *****)local_dc[0];
                if (local_c8 < 0x10) {
                  pppppuVar6 = local_dc;
                }
                FUN_007522a0(pppppuVar6);
              }
              local_14 = CONCAT31(local_14._1_3_,2);
              std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
              ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        (local_e0);
              break;
            case 5:
              local_124 = 0;
              if (local_b4 == 2) {
                FUN_0096a7f0(&local_124,param_2);
              }
              else {
                std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
                basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                          (local_a8);
                local_14._0_1_ = 3;
                FUN_00439a20(param_2);
                pppppuVar6 = (uint32_t /* width from decompiler */ *****)local_a4[0];
                if (local_90 < 0x10) {
                  pppppuVar6 = local_a4;
                }
                puVar2 = (uint32_t /* width from decompiler */ *)FUN_00404ba0(pppppuVar6);
                if (&local_124 != puVar2) {
                  local_124 = *puVar2;
                }
                local_14 = CONCAT31(local_14._1_3_,2);
                std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
                ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                          (local_a8);
              }
              iVar3 = FUN_0043ed30(&local_124);
              if (iVar3 < 0) {
                local_14._0_1_ = 1;
                if (local_bc != '\0') {
                  FUN_00769e40();
                }
                local_14 = (uint)local_14._1_3_ << 8;
                std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
                ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                          (local_140);
                goto LAB_0097081e;
              }
            }
            local_14 = CONCAT31(local_14._1_3_,1);
            if (local_bc != '\0') {
              FUN_00769e40();
            }
            iVar3 = FUN_0076a900();
          } while( true );
        }
        local_14 = local_14 & 0xffffff00;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_140);
        goto LAB_0097081e;
      }
      pcVar8 = "Invalid chunk version unserializing effEffect";
      uVar7 = 0x3ac;
    }
  }
  else {
    pcVar8 = "Invalid TAG unserializing effEffect";
    uVar7 = 0x308;
  }
  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effEffect.cpp",uVar7,3,
                 pcVar8);
LAB_0097081e:
  local_14 = 0xffffffff;
  if (local_108 != '\0') {
    FUN_00769e40();
  }
  ExceptionList = local_1c;
  return 0xffffffff;
}
