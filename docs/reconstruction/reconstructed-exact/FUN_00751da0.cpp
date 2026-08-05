// =============================================================================
// FUN_00751da0
// -----------------------------------------------------------------------------
// Stable ID: aa_00751da0
// Address:   0x00751da0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00751da0 @ 0x00751da0
// Stable ID: aa_00751da0
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effDeviceEffect.cpp"
//   - "Something bad happened loading the effect we just compiled successfully"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~160 non-empty decompiler lines.
//  - Control keywords: if×18, return×6, goto×1.
//  - Notable callees: FUN_00766750×3, FUN_00751ac0×2, FUN_007669d0×2, FUN_0076bff0×2, vog_LogMessage×2, CONCAT31, FUN_0074fa20, FUN_0074ff30.
//  - Strings: ",

                   0x328,3,"; ",

                   0x332,2,

                   ".
//  - Return sites: 6.

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

uint32_t /* width from decompiler */ __thiscall FUN_00751da0(int param_1,int param_2,undefined **param_3,int *param_4)



{

  char *pcVar1;

  uint32_t /* width from decompiler */ uVar2;

  char *pcVar3;

  int iVar4;

  uint32_t /* width from decompiler */ ****ppppuVar5;

  undefined **local_78;

  uint32_t /* width from decompiler */ local_74;

  uint32_t /* width from decompiler */ local_70;

  uint32_t /* width from decompiler */ local_6c;

  uint32_t /* width from decompiler */ local_68;

  undefined **local_64;

  void *local_60;

  uint32_t /* width from decompiler */ local_5c;

  uint32_t /* width from decompiler */ local_58;

  char local_50;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_4c [4];

  uint32_t /* width from decompiler */ ***local_48 [5];

  uint local_34;

  uint8_t local_30 [6];

  uint local_2a;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  pcVar1 = (char *)param_3;

  iVar4 = DAT_00d1f058;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b30dc;

  local_c = ExceptionList;

  if (*(char *)(DAT_00d1f058 + 0xd0) == '\0') {

    ExceptionList = &local_c;

    uVar2 = FUN_0074fa20(param_2,param_1);

    ExceptionList = local_c;

    return uVar2;

  }

  ExceptionList = &local_c;

  FUN_00965600(&param_3,param_3);

  if (*(uint *)(iVar4 + 0xcc) < 0x10) {

    pcVar3 = (char *)(iVar4 + 0xb8);

  }

  else {

    pcVar3 = *(char **)(iVar4 + 0xb8);

  }

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_4c,pcVar3);

  local_4 = 0;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator+=

            (local_4c,"/");

  pcVar3 = (char *)param_3;

  if (param_3 == (undefined **)0x0) {

    pcVar3 = PTR_DAT_00afa2bc;

  }

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator+=

            (local_4c,pcVar3);

  if (*(char *)(iVar4 + 0xd1) != '\0') {

    param_3 = &PTR_LAB_00a9fa84;

    param_4 = (int *)0x0;

    if (local_34 < 0x10) {

      local_48[0] = local_48;

    }

    iVar4 = D3DXCreateEffectFromFileA

                      (*DAT_00d1f044,local_48[0],*(uint32_t /* width from decompiler */ *)(param_1 + 4),&param_3,0,

                       *(uint32_t /* width from decompiler */ *)(DAT_00d1f05c + 0x140),param_2 + 0xc,&param_4);

    if (param_4 != (int *)0x0) {

      (**(code **)(*param_4 + 8))(param_4);

    }

    param_4 = (int *)0x0;

    local_4 = 0xffffffff;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_4c);

    if (-1 < iVar4) {

      ExceptionList = local_c;

      return 0;

    }

    ExceptionList = local_c;

    return 0xffffffff;

  }

  local_78 = &PTR_FUN_00a9d84c;

  local_74 = 0;

  local_70 = 0xffffffff;

  local_6c = 0;

  local_68 = 0;

  local_4._0_1_ = 1;

  ppppuVar5 = (uint32_t /* width from decompiler */ ****)local_48[0];

  if (local_34 < 0x10) {

    ppppuVar5 = local_48;

  }

  iVar4 = stat(ppppuVar5,local_30);

  if (iVar4 == 0) {

    param_3 = (undefined **)(CONCAT31(param_3._1_3_,(char)(local_2a >> 0xf)) & 0xffffff01);

    if ((local_2a >> 0xf & 1) != 0) {

      ppppuVar5 = (uint32_t /* width from decompiler */ ****)local_48[0];

      if (local_34 < 0x10) {

        ppppuVar5 = local_48;

      }

      iVar4 = FUN_007669d0(ppppuVar5,1,0x8000000);

      if (-1 < iVar4) {

        iVar4 = FUN_00751ac0(param_2,pcVar1,&local_78,param_1);

        if (-1 < iVar4) goto LAB_0075212d;

        FUN_00766690();

      }

    }

  }

  FUN_0076c0b0(0x400);

  local_4._0_1_ = 2;

  iVar4 = FUN_0074ff30(pcVar1,&local_64,param_1);

  if (iVar4 < 0) {

    local_64 = &PTR_FUN_00a9d184;

    if (local_50 != '\0') {

      free(local_60);

    }

    local_64 = &PTR_LAB_00a9d774;

    local_4 = (uint)local_4._1_3_ << 8;

    FUN_00766750();

    local_4 = 0xffffffff;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_4c);

    ExceptionList = local_c;

    return 0xffffffff;

  }

  local_5c = 0;

  iVar4 = FUN_00751ac0(param_2,pcVar1,&local_64,param_1);

  if (iVar4 < 0) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effDeviceEffect.cpp",

                   0x328,3,"Something bad happened loading the effect we just compiled successfully"

                  );

    FUN_0076bff0();

    local_4 = (uint)local_4._1_3_ << 8;

    FUN_00766750();

    local_4 = 0xffffffff;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_4c);

    ExceptionList = local_c;

    return 0xffffffff;

  }

  if (local_34 < 0x10) {

    local_48[0] = local_48;

  }

  iVar4 = FUN_007669d0(local_48[0],6,0x8000000);

  if (iVar4 < 0) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effDeviceEffect.cpp",

                   0x332,2,

                   "The precompiled effect directory and/or some files are read only. This will impact application performance."

                  );

  }

  else {

    local_5c = 0;

    FUN_00766600(local_60,local_58);

  }

  FUN_0076bff0();

LAB_0075212d:

  local_4 = (uint)local_4._1_3_ << 8;

  FUN_00766750();

  local_4 = 0xffffffff;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_4c);

  ExceptionList = local_c;

  return 0;

}
