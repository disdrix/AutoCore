// =============================================================================
// Named_CalleeOf_Named_effDeviceEffect_00965600
// -----------------------------------------------------------------------------
// Stable ID: aa_00965600
// Callee of Named_effDeviceEffect (+1 other named callers)
// Address:   0x00965600  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_effDeviceEffect: callee helper. Evidence string: ".fxc". Supports parent flow (not a free-standing entry point). Named_effDeviceEffect (+1 other named callers).
// Embedded strings (evidence):
//   - ".fxc"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, do×1, while×1.
//  - Notable callees: FUN_00989e00×2, CONCAT31, FUN_00965600.
//  - Strings: ".fxc".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_effDeviceEffect (+1 other named callers)
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_effDeviceEffect_00965600(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  char *pcVar1;

  char cVar2;

  char *pcVar3;

  uint uVar4;

  char *pcVar5;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_44 [4];

  uint32_t /* width from decompiler */ **local_40 [5];

  uint local_2c;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [4];

  uint32_t /* width from decompiler */ **local_24 [5];

  uint local_10;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009af9be;

  local_c = ExceptionList;

  pcVar5 = (char *)*param_2;

  pcVar3 = pcVar5;

  if (pcVar5 == (char *)0x0) {

    pcVar3 = PTR_DAT_00afa2bc;

  }

  pcVar1 = pcVar3 + 1;

  do {

    cVar2 = *pcVar3;

    pcVar3 = pcVar3 + 1;

  } while (cVar2 != '\0');

  param_2 = (uint32_t /* width from decompiler */ *)((int)pcVar3 - (int)pcVar1);

  if (param_2 == (uint32_t /* width from decompiler */ *)0x0) {

    *param_1 = DAT_00d1ed24;

    return param_1;

  }

  if (pcVar5 == (char *)0x0) {

    pcVar5 = PTR_DAT_00afa2bc;

  }

  ExceptionList = &local_c;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44,pcVar5);

  local_4 = 0;

  param_2 = (uint32_t /* width from decompiler */ *)CONCAT31(param_2._1_3_,0x2e);

  uVar4 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::rfind

                    (local_44,(char *)&param_2,*(uint *)npos_exref,1);

  if (uVar4 == *(uint *)npos_exref) {

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator+=

              (local_44,".fxc");

    if (local_2c < 0x10) {

      local_40[0] = local_40;

    }

    FUN_00989e00(param_1,local_40[0]);

  }

  else {

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::substr

              (local_44,(uint)local_28,0);

    local_4._0_1_ = 1;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator+=

              (local_28,".fxc");

    if (local_10 < 0x10) {

      local_24[0] = local_24;

    }

    FUN_00989e00(param_1,local_24[0]);

    local_4 = (uint)local_4._1_3_ << 8;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

  }

  local_4 = 0xffffffff;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44);

  ExceptionList = local_c;

  return param_1;

}
