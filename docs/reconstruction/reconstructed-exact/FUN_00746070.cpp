// =============================================================================
// FUN_00746070
// -----------------------------------------------------------------------------
// Stable ID: aa_00746070
// Address:   0x00746070  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00746070 @ 0x00746070
// Stable ID: aa_00746070
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\assets\\assBlock.cpp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~90 non-empty decompiler lines.
//  - Control keywords: if×9, return×1.
//  - Notable callees: FUN_0096a630×2, vog_LogMessage×2, EnterCriticalSection, FUN_00746070, FUN_0075d230, LeaveCriticalSection.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\assets\\assBlock.cpp".
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

void __fastcall FUN_00746070(int *param_1)



{

  int *piVar1;

  uint uVar2;

  uint uVar3;

  int iVar4;

  uint uVar5;

  int unaff_EBX;

  uint32_t /* width from decompiler */ unaff_EDI;

  LPCRITICAL_SECTION local_30;

  LPCRITICAL_SECTION local_2c [6];

  uint8_t uStack_14;

  void *pvStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ad85d;

  pvStack_c = ExceptionList;

  local_2c[0] = (LPCRITICAL_SECTION)(param_1 + 8);

  ExceptionList = &pvStack_c;

  if ((char)param_1[0xe] != '\0') {

    ExceptionList = &pvStack_c;

    EnterCriticalSection(local_2c[0]);

  }

  local_4 = 0;

  piVar1 = (int *)param_1[2];

  if (piVar1 == (int *)0x0) {

    piVar1 = (int *)(**(code **)(*(int *)param_1[3] + 4))();

  }

  else {

    param_1[2] = 0;

  }

  local_30 = (LPCRITICAL_SECTION)0x0;

  uVar2 = (**(code **)(*param_1 + 0x14))(&local_30);

  if (unaff_EBX == 0) {

    iVar4 = FUN_0096a630(local_2c);

    puStack_8._0_1_ = 2;

    if (*(uint *)(iVar4 + 0x18) < 0x10) {

      iVar4 = iVar4 + 4;

    }

    else {

      iVar4 = *(int *)(iVar4 + 4);

    }

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\assets\\assBlock.cpp",0x7b,2,iVar4);

    puStack_8 = (uint8_t *)((uint)puStack_8._1_3_ << 8);

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               local_2c);

    uVar5 = 0xffffffff;

  }

  else {

    uVar3 = (**(code **)(*piVar1 + 4))(unaff_EBX,param_1 + 1,param_1[5]);

    if ((uVar2 | uVar3) == 0xffffffff) {

      iVar4 = FUN_0096a630(&stack0xffffffc8);

      uStack_14 = 1;

      if (*(uint *)(iVar4 + 0x18) < 0x10) {

        iVar4 = iVar4 + 4;

      }

      else {

        iVar4 = *(int *)(iVar4 + 4);

      }

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\assets\\assBlock.cpp",0x72,2,iVar4);

      uStack_14 = 0;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                 &stack0xffffffc8);

    }

    uVar5 = (**(code **)(*param_1 + 0x18))(unaff_EDI);

    uVar5 = uVar2 | uVar3 | uVar5;

  }

  param_1[6] = uVar5;

  if ((int)uVar5 < 0) {

    if (piVar1 != (int *)0x0) {

      (**(code **)*piVar1)(1);

    }

    iVar4 = FUN_0075d230(2);

    param_1[2] = iVar4;

  }

  else {

    param_1[2] = (int)piVar1;

  }

  if (*(char *)&local_30[1].DebugInfo != '\0') {

    LeaveCriticalSection(local_30);

  }

  ExceptionList = pvStack_10;

  return;

}
