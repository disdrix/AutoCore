// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: vog_LogMessage×2, FUN_0076cec0, FUN_0096a630, FUN_0096ea60, FUN_0096f3e0.
//  - Strings: ",

                   0xd9,2,"; "Failed to create instance of texture: <%s>".
//  - Return sites: 2.

// =============================================================================
// Named_effTextureFactory_0096f3e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0096f3e0
// Address:   0x0096f3e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "effTextureFactory"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_effTextureFactory_0096f3e0(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b133b;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  iVar2 = FUN_0096ea60(param_2,&param_3,param_3);

  if (iVar2 == 0) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTextureFactory.cpp",

                   0xd9,2,"Failed to Default Texture!");

    iVar3 = FUN_0096a630(local_28);

    if (*(uint *)(iVar3 + 0x18) < 0x10) {

      iVar3 = iVar3 + 4;

    }

    else {

      iVar3 = *(int *)(iVar3 + 4);

    }

    local_4 = iVar2;

    uVar4 = FUN_0076cec0(&param_3,"Failed to create instance of texture: <%s>",iVar3);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTexture.cpp",0x3d,2,

                   uVar4);

    local_4 = 0xffffffff;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

    ExceptionList = local_c;

    return 0xffffffff;

  }

  *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + 1;

  if (*(int *)(iVar2 + 8) == 1) {

    (**(code **)(*(int *)(iVar2 + 4) + 4))();

  }

  iVar3 = *param_1;

  if (iVar3 != 0) {

    piVar1 = (int *)(iVar3 + 8);

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*(int *)(iVar3 + 4) + 8))();

    }

  }

  *param_1 = iVar2;

  ExceptionList = local_c;

  return param_3;

}
