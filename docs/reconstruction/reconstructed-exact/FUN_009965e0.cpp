// =============================================================================
// FUN_009965e0
// -----------------------------------------------------------------------------
// Stable ID: aa_009965e0
// Address:   0x009965e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009965e0 @ 0x009965e0
// Stable ID: aa_009965e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~170 non-empty decompiler lines.
//  - Control keywords: if×14, goto×2, return×1.
//  - Notable callees: CONCAT31, CloseHandle, EnterCriticalSection, FUN_0044e650, FUN_0044e8c0, FUN_0044e9e0, FUN_00766750, FUN_00766840.
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

int * __thiscall FUN_009965e0(int param_1,int *param_2)



{

  bool bVar1;

  char cVar2;

  char *pcVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  int iVar6;

  void *pvVar7;

  BOOL BVar8;

  int *piVar9;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_ac [12];

  uint32_t /* width from decompiler */ uStack_a0;

  uint32_t /* width from decompiler */ ***pppuStack_9c;

  LPCRITICAL_SECTION *pp_Stack_98;

  uint8_t *apuStack_78 [2];

  LPCRITICAL_SECTION local_70;

  undefined **ppuStack_6c;

  uint32_t /* width from decompiler */ uStack_68;

  HANDLE pvStack_64;

  uint32_t /* width from decompiler */ uStack_60;

  uint32_t /* width from decompiler */ uStack_5c;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_4c [4];

  uint32_t /* width from decompiler */ ***apppuStack_48 [5];

  uint uStack_34;

  uint8_t auStack_30 [4];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_2c [16];

  int iStack_1c;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009afad1;

  pvStack_c = ExceptionList;

  local_70 = (LPCRITICAL_SECTION)0x0;

  ExceptionList = &pvStack_c;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_4c);

  local_4 = 0;

  bVar1 = true;

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 4) != (uint32_t /* width from decompiler */ *)0x0) {

    pp_Stack_98 = &local_70;

    pppuStack_9c = (uint32_t /* width from decompiler */ ****)0x996632;

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 4))();

  }

  local_70 = (LPCRITICAL_SECTION)(param_1 + 0x30);

  if (*(char *)(param_1 + 0x48) != '\0') {

    pp_Stack_98 = (LPCRITICAL_SECTION *)0x996654;

    EnterCriticalSection(local_70);

  }

  local_4._0_1_ = 1;

  pp_Stack_98 = (LPCRITICAL_SECTION *)0x99666d;

  FUN_0044e8c0();

  if (apuStack_78[0] == *(uint8_t **)(param_1 + 0x10)) {

    pcVar3 = (char *)*param_2;

    if ((char *)*param_2 == (char *)0x0) {

      pcVar3 = PTR_DAT_00afa2bc;

    }

    pp_Stack_98 = (LPCRITICAL_SECTION *)0x996699;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               &ppuStack_6c,pcVar3);

    local_4._0_1_ = 2;

    pp_Stack_98 = (LPCRITICAL_SECTION *)DAT_00d1f1fc;

    pppuStack_9c = (uint32_t /* width from decompiler */ ****)0x9966b5;

    cVar2 = FUN_009695c0();

    local_4._0_1_ = 1;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               &ppuStack_6c);

    if (cVar2 == '\0') {

      bVar1 = false;

    }

    else {

      apuStack_78[0] = abStack_ac;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                (abStack_ac,local_4c);

      apuStack_78[0] = &stack0xffffff50;

      puVar4 = (uint32_t /* width from decompiler */ *)FUN_0044e9e0(auStack_30);

      local_4._0_1_ = 3;

      ppuStack_6c = (undefined **)*puVar4;

      pp_Stack_98 = (LPCRITICAL_SECTION *)0x99671b;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                 &uStack_68,

                 (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                 (puVar4 + 1));

      pp_Stack_98 = (LPCRITICAL_SECTION *)apuStack_78;

      local_4._0_1_ = 4;

      pppuStack_9c = (uint32_t /* width from decompiler */ ****)0x996734;

      FUN_0044e650();

      local_4._0_1_ = 3;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                 &uStack_68);

      local_4._0_1_ = 1;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_2c);

    }

  }

  else {

    pp_Stack_98 = (LPCRITICAL_SECTION *)0x99676e;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

              (local_4c,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                         *)(apuStack_78[0] + 0xc));

  }

  if (*(char *)&local_70[1].DebugInfo != '\0') {

    pp_Stack_98 = (LPCRITICAL_SECTION *)0x99677f;

    LeaveCriticalSection(local_70);

  }

  piVar9 = (int *)0x0;

  if (!bVar1) goto LAB_0099685d;

  ppuStack_6c = &PTR_FUN_00a9d84c;

  uStack_68 = 0;

  pvStack_64 = (HANDLE)0xffffffff;

  uStack_60 = 0;

  uStack_5c = 0;

  local_4 = CONCAT31(local_4._1_3_,5);

  pppuStack_9c = apppuStack_48[0];

  if (uStack_34 < 0x10) {

    pppuStack_9c = apppuStack_48;

  }

  pp_Stack_98 = (LPCRITICAL_SECTION *)0x1;

  uStack_a0 = 0x9967cf;

  iVar5 = FUN_007669d0();

  if (-1 < iVar5) {

    if (uStack_34 < 0x10) {

      apppuStack_48[0] = apppuStack_48;

    }

    pppuStack_9c = (uint32_t /* width from decompiler */ ***)0x9967ed;

    pp_Stack_98 = (LPCRITICAL_SECTION *)apppuStack_48[0];

    iVar6 = stat();

    iVar5 = -1;

    if (iVar6 == 0) {

      iVar5 = iStack_1c;

    }

    pp_Stack_98 = (LPCRITICAL_SECTION *)0x996801;

    pvVar7 = operator_new(0x18);

    if (pvVar7 != (void *)0x0) {

      pp_Stack_98 = (LPCRITICAL_SECTION *)0x996810;

      piVar9 = (int *)FUN_0076c0b0();

    }

    pp_Stack_98 = (LPCRITICAL_SECTION *)piVar9[1];

    pppuStack_9c = (uint32_t /* width from decompiler */ ****)0x996820;

    FUN_00766840();

    piVar9[3] = iVar5;

    (**(code **)(*piVar9 + 8))();

    cVar2 = (*(code *)ppuStack_6c[8])();

    if (cVar2 != '\0') {

      pp_Stack_98 = (LPCRITICAL_SECTION *)0x996844;

      BVar8 = CloseHandle(pvStack_64);

      if (BVar8 == 0) goto LAB_0099684c;

    }

    pvStack_64 = (HANDLE)0xffffffff;

  }

LAB_0099684c:

  local_4 = local_4 & 0xffffff00;

  FUN_00766750();

LAB_0099685d:

  local_4 = 0xffffffff;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_4c);

  ExceptionList = pvStack_c;

  return piVar9;

}
