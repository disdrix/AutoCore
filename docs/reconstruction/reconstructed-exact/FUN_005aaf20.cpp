// =============================================================================
// FUN_005aaf20
// -----------------------------------------------------------------------------
// Stable ID: aa_005aaf20
// Address:   0x005aaf20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005aaf20 @ 0x005aaf20
// Stable ID: aa_005aaf20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~127 non-empty decompiler lines.
//  - Control keywords: if×9, return×3, while×3, do×1.
//  - Notable callees: clear×2, FUN_005a9e20, FUN_005aaf20, FUN_005ac1d0, FUN_005ac820.
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

uint32_t /* width from decompiler */ __thiscall

FUN_005aaf20(int param_1,wchar_t *param_2,uint32_t /* width from decompiler */ *param_3,int param_4,wchar_t *param_5)



{

  char cVar1;

  int *piVar2;

  int *piVar3;

  bool bVar4;

  void **ppvVar5;

  int *piVar6;

  void *local_54;

  void *local_50 [2];

  basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

  local_48 [28];

  basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

  local_2c [28];

  int *local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a64e1;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::

  basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

            (local_48,param_2);

  local_4 = 0;

  local_54 = (void *)FUN_005ac1d0(local_48);

  if ((local_54 == *(void **)(param_1 + 0x510c)) ||

     (bVar4 = std::

              operator<<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                        (local_48,(basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                                   *)((int)local_54 + 0xc)), bVar4)) {

    local_50[0] = *(void **)(param_1 + 0x510c);

    ppvVar5 = local_50;

  }

  else {

    ppvVar5 = &local_54;

  }

  piVar6 = *ppvVar5;

  local_4 = 0xffffffff;

  std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::

  ~basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>(local_48);

  if (piVar6 != *(int **)(param_1 + 0x510c)) {

    do {

      bVar4 = std::

              operator!=<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                        ((basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                          *)(piVar6 + 3),param_2);

      if (bVar4) break;

      if (*(int *)piVar6[10] == param_4) {

        std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::

        operator=((basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                   *)(piVar6[10] + 4),(wchar_t *)*param_3);

        if (param_5 != (wchar_t *)0x0) {

          std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

          ::operator=((basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                       *)(piVar6[10] + 0x20),param_5);

          ExceptionList = local_c;

          return 1;

        }

        std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::

        clear((basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

               *)(piVar6[10] + 0x20));

        ExceptionList = local_c;

        return 1;

      }

      if (*(char *)((int)piVar6 + 0x2d) == '\0') {

        piVar2 = (int *)piVar6[2];

        if (*(char *)((int)piVar2 + 0x2d) == '\0') {

          cVar1 = *(char *)(*piVar2 + 0x2d);

          piVar6 = piVar2;

          piVar2 = (int *)*piVar2;

          while (cVar1 == '\0') {

            cVar1 = *(char *)(*piVar2 + 0x2d);

            piVar6 = piVar2;

            piVar2 = (int *)*piVar2;

          }

        }

        else {

          cVar1 = *(char *)(piVar6[1] + 0x2d);

          piVar3 = (int *)piVar6[1];

          piVar2 = piVar6;

          while ((piVar6 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {

            cVar1 = *(char *)(piVar6[1] + 0x2d);

            piVar3 = (int *)piVar6[1];

            piVar2 = piVar6;

          }

        }

      }

    } while (piVar6 != *(int **)(param_1 + 0x510c));

  }

  local_50[0] = operator_new(0x3c);

  local_4 = 1;

  if (local_50[0] == (void *)0x0) {

    piVar6 = (int *)0x0;

  }

  else {

    piVar6 = (int *)FUN_005a9e20();

  }

  *piVar6 = param_4;

  local_4 = 0xffffffff;

  std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::

  operator=((basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_> *

            )(piVar6 + 1),(wchar_t *)*param_3);

  if (param_5 == (wchar_t *)0x0) {

    std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::

    clear((basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_> *)

          (piVar6 + 8));

  }

  else {

    std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::

    operator=((basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

               *)(piVar6 + 8),param_5);

  }

  std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::

  basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

            (local_2c,param_2);

  local_4 = 2;

  local_10 = piVar6;

  FUN_005ac820(local_50,local_2c);

  local_4 = 0xffffffff;

  std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::

  ~basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>(local_2c);

  ExceptionList = local_c;

  return 1;

}
