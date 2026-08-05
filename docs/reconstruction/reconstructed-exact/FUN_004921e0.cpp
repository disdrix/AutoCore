// =============================================================================
// FUN_004921e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004921e0
// Address:   0x004921e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004921e0 @ 0x004921e0
// Stable ID: aa_004921e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, goto×1.
//  - Notable callees: FUN_004921e0, FUN_0055b530, FUN_0074b580.
//  - Return sites: 2.

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

void __thiscall FUN_004921e0(int param_1,char *param_2)



{

  int iVar1;

  void *pvVar2;

  bool bVar3;

  int *piVar4;

  int local_2c;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a097f;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28,param_2);

  local_4 = 0;

  param_2 = (char *)FUN_0055b530(local_28);

  if (param_2 != (char *)*(int *)(param_1 + 400)) {

    bVar3 = std::operator<<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                      (local_28,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                                 *)((int)param_2 + 0xc));

    if (!bVar3) {

      piVar4 = (int *)&param_2;

      goto LAB_00492256;

    }

  }

  local_2c = *(int *)(param_1 + 400);

  piVar4 = &local_2c;

LAB_00492256:

  iVar1 = *piVar4;

  local_4 = 0xffffffff;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

  if ((iVar1 != *(int *)(param_1 + 400)) &&

     (pvVar2 = *(void **)(iVar1 + 0x28), *(int *)((int)pvVar2 + 0x128) < 1)) {

    if (*(uint32_t /* width from decompiler */ **)((int)pvVar2 + 0x124) != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)**(uint32_t /* width from decompiler */ **)((int)pvVar2 + 0x124))(1);

    }

    *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 0x124) = 0;

    if (*(void **)((int)pvVar2 + 0x114) != (void *)0x0) {

      operator_delete__(*(void **)((int)pvVar2 + 0x114));

    }

    *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 0x114) = 0;

    FUN_0074b580();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar2);

  }

  ExceptionList = local_c;

  return;

}
