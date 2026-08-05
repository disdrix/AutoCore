// =============================================================================
// FUN_00996890
// -----------------------------------------------------------------------------
// Stable ID: aa_00996890
// Address:   0x00996890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00996890 @ 0x00996890
// Stable ID: aa_00996890
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~128 non-empty decompiler lines.
//  - Control keywords: if×7, goto×1, return×1.
//  - Notable callees: EnterCriticalSection, FUN_0044e560, FUN_0044e650, FUN_0044e8c0, FUN_0044e9e0, FUN_009695c0, FUN_00996890, LeaveCriticalSection.
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

uint8_t * __thiscall FUN_00996890(int param_1,int *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  char cVar1;

  char *pcVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint8_t *puVar4;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_a4 [12];

  uint32_t /* width from decompiler */ uStack_98;

  uint8_t *puStack_94;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbStack_90;

  int local_78;

  uint8_t *local_74 [2];

  LPCRITICAL_SECTION local_6c;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_68 [28];

  uint32_t /* width from decompiler */ uStack_4c;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_48 [28];

  uint8_t auStack_2c [4];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_28 [28];

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009afb10;

  pvStack_c = ExceptionList;

  local_6c = (LPCRITICAL_SECTION)(param_1 + 0x30);

  ExceptionList = &pvStack_c;

  if (*(char *)(param_1 + 0x48) != '\0') {

    pbStack_90 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                 0x9968c7;

    ExceptionList = &pvStack_c;

    EnterCriticalSection(local_6c);

  }

  local_4 = 0;

  local_74[0] = (uint8_t *)0x0;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_68);

  local_4._0_1_ = 1;

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 4) != (uint32_t /* width from decompiler */ *)0x0) {

    pbStack_90 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                 &param_2;

    puStack_94 = (uint8_t *)0x9968ff;

    param_2 = (int *)(**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 4))();

  }

  pcVar2 = (char *)*param_2;

  pbStack_90 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               0x996925;

  param_2 = (int *)pcVar2;

  FUN_0044e8c0();

  if (local_78 == *(int *)(param_1 + 0x10)) {

    if (pcVar2 == (char *)0x0) {

      pcVar2 = PTR_DAT_00afa2bc;

    }

    pbStack_90 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                 0x99694a;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               &uStack_4c,pcVar2);

    local_4._0_1_ = 2;

    pbStack_90 = DAT_00d1f1fc;

    puStack_94 = (uint8_t *)0x996967;

    cVar1 = FUN_009695c0();

    local_4._0_1_ = 1;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               &uStack_4c);

    puVar4 = local_74[0];

    if (cVar1 == '\0') goto LAB_00996a5f;

    local_74[0] = abStack_a4;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              (abStack_a4,local_68);

    local_74[0] = &stack0xffffff58;

    puVar3 = (uint32_t /* width from decompiler */ *)FUN_0044e9e0(auStack_2c);

    local_4._0_1_ = 3;

    uStack_4c = *puVar3;

    pbStack_90 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                 0x9969ca;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              (abStack_48,

               (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               (puVar3 + 1));

    pbStack_90 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                 local_74;

    local_4._0_1_ = 4;

    puStack_94 = (uint8_t *)0x9969e3;

    FUN_0044e650();

    local_4._0_1_ = 3;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_48);

    local_4._0_1_ = 1;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_28);

  }

  else {

    pbStack_90 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                 0x996a16;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

              (local_68,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                         *)(local_78 + 0xc));

  }

  pbStack_90 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               0x996a1d;

  local_74[0] = operator_new(0x58);

  local_4._0_1_ = 5;

  if (local_74[0] == (uint8_t *)0x0) {

    puVar4 = (uint8_t *)0x0;

  }

  else {

    pbStack_90 = local_68;

    uStack_98 = 0x996a51;

    puStack_94 = local_74[0];

    puVar4 = (uint8_t *)FUN_0044e560();

  }

LAB_00996a5f:

  local_4 = (uint)local_4._1_3_ << 8;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_68);

  if (*(char *)&local_6c[1].DebugInfo != '\0') {

    pbStack_90 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                 0x996a82;

    LeaveCriticalSection(local_6c);

  }

  ExceptionList = pvStack_c;

  return puVar4;

}
