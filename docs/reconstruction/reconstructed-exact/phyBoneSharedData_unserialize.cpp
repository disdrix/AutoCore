// =============================================================================
// phyBoneSharedData_unserialize
// -----------------------------------------------------------------------------
// Purpose:  Read BDAT ("TADB"=0x42444154): bone-name string + hkQsTransform
//           (quat4 + trans3 [+ scale3 in v2]). Nested inside PBON, not GBOD sibling.
//
// Address:  0x00997540  (autoassault.exe, image base 0x400000)
// Stable:   aa_00997540
// System:   physics / phy (asset I/O)
// Source:   palantir/physics/phyBoneSharedData.cpp
//
// Apply: v' = translation + rotation * (scale * v)
// Trailing 4x4 via FUN_0043edb0 is near-identity BIND, not the transform.
// =============================================================================

uint32_t /* width from decompiler */ __thiscall phyBoneSharedData_unserialize(int param_1,int param_2)



{

  float fVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  int *piVar6;

  uint8_t local_44 [4];

  uint8_t local_40 [12];

  char local_34;

  int local_30;

  int local_2c;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [4];

  uint32_t /* width from decompiler */ **local_24 [5];

  uint local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  iVar2 = param_2;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1862;

  local_c = ExceptionList;

  param_2 = 0;

  ExceptionList = &local_c;

  stoChunkReader_EnterChunkScope(param_1);

  local_4 = 0;

  if (local_30 != 0x42444154) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\physics\\phyBoneSharedData.cpp",0x2c,3,

                   "Invalid TAG unserializing phyBoneMaster");

    local_4 = 0xffffffff;

    if (local_34 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return 0xffffffff;

  }

  if (local_2c == 1) {

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

    local_4 = CONCAT31(local_4._1_3_,1);

    if (*(int *)(param_1 + 0x4044) == 0) {

      FUN_00436f10();

    }

    else {

      FUN_0076a200();

    }

    if (local_10 < 0x10) {

      local_24[0] = local_24;

    }

    puVar4 = (uint32_t /* width from decompiler */ *)FUN_00989e00(local_40,local_24[0]);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 8) = *puVar4;

    stoChunkReader_readF32Array(param_1);

    stoChunkReader_readF32Array(param_1);

    FUN_0043edb0();

    iVar5 = FUN_0076a900();

    if (iVar5 != 0) {

      piVar6 = (int *)FUN_00467690(iVar5);

      *(int **)(iVar2 + 0x80) = piVar6;

      if (piVar6 != (int *)0x0) {

        param_2 = (**(code **)(*piVar6 + 0x10))(param_1);

      }

    }

    fVar1 = g_flOne;

    *(float *)(iVar2 + 0x28) = g_flOne;

    *(float *)(iVar2 + 0x2c) = fVar1;

    *(float *)(iVar2 + 0x30) = fVar1;

  }

  else {

    if (local_2c != 2) {

      uVar3 = FUN_0076cec0(&param_2,"Invalid chunk version (%i) unserializing phyBoneSharedData",

                           local_2c);

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\physics\\phyBoneSharedData.cpp",0x5b,3,

                     uVar3);

      local_4 = 0xffffffff;

      if (local_34 != '\0') {

        FUN_00769e40();

      }

      ExceptionList = local_c;

      return 0xffffffff;

    }

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

    local_4 = CONCAT31(local_4._1_3_,2);

    if (*(int *)(param_1 + 0x4044) == 0) {

      FUN_00436f10();

    }

    else {

      FUN_0076a200();

    }

    if (local_10 < 0x10) {

      local_24[0] = local_24;

    }

    puVar4 = (uint32_t /* width from decompiler */ *)FUN_00989e00(local_44,local_24[0]);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 8) = *puVar4;

    stoChunkReader_readF32Array(param_1);

    stoChunkReader_readF32Array(param_1);

    stoChunkReader_readF32Array(param_1);

    FUN_0043edb0();

    iVar5 = FUN_0076a900();

    if (iVar5 != 0) {

      piVar6 = (int *)FUN_00467690(iVar5);

      *(int **)(iVar2 + 0x80) = piVar6;

      if (piVar6 != (int *)0x0) {

        param_2 = (**(code **)(*piVar6 + 0x10))(param_1);

      }

    }

  }

  local_4 = local_4 & 0xffffff00;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

  local_4 = 0xffffffff;

  if (local_34 != '\0') {

    FUN_00769e40();

  }

  ExceptionList = local_c;

  return param_2;

}
