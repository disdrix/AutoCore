// =============================================================================
// FUN_00786470
// -----------------------------------------------------------------------------
// Stable ID: aa_00786470
// Address:   0x00786470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00786470 @ 0x00786470
// Stable ID: aa_00786470
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~80 non-empty decompiler lines.
//  - Control keywords: if×4, goto×1, return×1.
//  - Notable callees: CONCAT31, FUN_004309c0, FUN_00430ce0, FUN_004406e0, FUN_00786280, FUN_00786470.
//  - Return sites: 1.

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

void * __thiscall FUN_00786470(int param_1,char *param_2)



{

  bool bVar1;

  void **ppvVar2;

  void *pvVar3;

  void *local_90 [2];

  void *local_88;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_84 [28];

  void *local_68;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_64 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_48 [28];

  void *local_2c;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ace2c;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_64,param_2);

  local_4 = 0;

  local_88 = (void *)FUN_00430ce0(local_64);

  if (local_88 != *(void **)(param_1 + 0x20)) {

    bVar1 = std::operator<<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                      (local_64,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                                 *)((int)local_88 + 0xc));

    if (!bVar1) {

      ppvVar2 = &local_88;

      goto LAB_007864ed;

    }

  }

  local_90[0] = *(void **)(param_1 + 0x20);

  ppvVar2 = local_90;

LAB_007864ed:

  pvVar3 = *ppvVar2;

  local_4 = 0xffffffff;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_64);

  if (pvVar3 == *(void **)(param_1 + 0x20)) {

    local_90[0] = operator_new(0x5c);

    local_4 = 1;

    if (local_90[0] == (void *)0x0) {

      pvVar3 = (void *)0x0;

    }

    else {

      pvVar3 = (void *)FUN_00786280(local_90[0],param_2);

    }

    local_4 = 0xffffffff;

    local_90[0] = pvVar3;

    FUN_004406e0();

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28,param_2);

    local_4 = 2;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_84,local_28);

    local_4._0_1_ = 3;

    local_68 = pvVar3;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_48,local_84);

    local_2c = local_68;

    local_4._0_1_ = 4;

    FUN_004309c0(param_1 + 0x1c);

    local_4._0_1_ = 3;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_48);

    local_4 = CONCAT31(local_4._1_3_,2);

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_84);

    local_4 = 0xffffffff;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

  }

  else {

    pvVar3 = *(void **)((int)pvVar3 + 0x28);

  }

  ExceptionList = local_c;

  return pvVar3;

}
