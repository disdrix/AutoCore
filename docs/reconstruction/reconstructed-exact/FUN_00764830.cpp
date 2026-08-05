// =============================================================================
// FUN_00764830
// -----------------------------------------------------------------------------
// Stable ID: aa_00764830
// Address:   0x00764830  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00764830 @ 0x00764830
// Stable ID: aa_00764830
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxBody.cpp"
//   - "Could not lock asset %s."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×6, return×3.
//  - Notable callees: FUN_0096a630×2, vog_LogMessage×2, FUN_007641c0, FUN_00764830, FUN_0076cec0, NDResourceCache_LookupOrCreate, NDResource_AcquireInnerObject, _atexit.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxBody.cpp"; "Could not lock asset %s.".
//  - Return sites: 3.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint __thiscall FUN_00764830(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  int *piVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_44 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_28 [28];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b1cc9;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  (**(code **)(*param_1 + 0x58))();

  if ((_DAT_00d1f884 & 1) == 0) {

    _DAT_00d1f884 = _DAT_00d1f884 | 1;

    _DAT_00d1f880 = &PTR_FUN_00a9db20;

    _atexit((_func_4879 *)&LAB_009c32f0);

  }

  piVar2 = (int *)NDResourceCache_LookupOrCreate(DAT_00d1f050,param_2,&DAT_00d1f880,0,0);

  if (piVar2 == (int *)0x0) {

    iVar3 = FUN_0096a630(abStack_44);

    uStack_4 = 0;

    if (*(uint *)(iVar3 + 0x18) < 0x10) {

      iVar3 = iVar3 + 4;

    }

    else {

      iVar3 = *(int *)(iVar3 + 4);

    }

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxBody.cpp",0xb0,2,iVar3);

    uStack_4 = 0xffffffff;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_44);

    ExceptionList = pvStack_c;

    return 0xffffffff;

  }

  cVar1 = (**(code **)(*piVar2 + 4))();

  iVar3 = NDResource_AcquireInnerObject();

  if (iVar3 != 0) {

    if (*(int *)(iVar3 + 4) != 0) {

      FUN_007641c0(*(int *)(iVar3 + 4));

    }

    param_1[0x23] = (int)piVar2;

    param_1[0x24] = iVar3;

    ExceptionList = pvStack_c;

    return (uint)(cVar1 != '\0');

  }

  iVar3 = FUN_0096a630(abStack_28);

  uStack_4 = 1;

  if (*(uint *)(iVar3 + 0x18) < 0x10) {

    iVar3 = iVar3 + 4;

  }

  else {

    iVar3 = *(int *)(iVar3 + 4);

  }

  uVar4 = FUN_0076cec0(&param_2,"Could not lock asset %s.",iVar3);

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxBody.cpp",0xb8,2,uVar4);

  uStack_4 = 0xffffffff;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_28);

  ExceptionList = pvStack_c;

  return 0xffffffff;

}
