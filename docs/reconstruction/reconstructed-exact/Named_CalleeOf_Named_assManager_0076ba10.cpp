// =============================================================================
// Named_CalleeOf_Named_assManager_0076ba10
// -----------------------------------------------------------------------------
// Stable ID: aa_0076ba10
// Callee of Named_assManager
// Address:   0x0076ba10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_assManager: callee helper. Evidence string: "Delete file failed for: %s %d\n". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Delete file failed for: %s %d\n"
//   - "Delete directory failed for: %s %d\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~105 non-empty decompiler lines.
//  - Control keywords: if×10, return×2, for×2, do×1, goto×1, while×1.
//  - Notable callees: FUN_00416490×2, FUN_0076ba10×2, _errno×2, _rmdir×2, CONCAT31, FUN_00431ae0, FUN_0076adc0, FUN_0076b080.
//  - Strings: "Delete file failed for: %s %d\n"; "Delete directory failed for: %s %d\n".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_assManager
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

bool Named_CalleeOf_Named_assManager_0076ba10(char *param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int ****ppppiVar4;

  int *piVar5;

  int ****ppppiVar6;

  char *_Format;

  uint8_t local_70 [4];

  int ***local_6c;

  int ***local_68;

  uint32_t /* width from decompiler */ local_64;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_60 [4];

  int ***local_5c [5];

  uint local_48;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_44 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009adcab;

  local_c = ExceptionList;

  if ((char)param_2 == '\0') {

    ExceptionList = &local_c;

    iVar2 = _rmdir(param_1);

    ExceptionList = local_c;

    return iVar2 == 0;

  }

  local_6c = (int ***)0x0;

  local_68 = (int ***)0x0;

  local_64 = 0;

  local_4 = 0;

  ExceptionList = &local_c;

  FUN_0076b3f0(param_1,local_70);

  if (local_6c != local_68) {

    ppppiVar6 = (int ****)(local_6c + 1);

    do {

      uVar3 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

              basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        (local_28,param_1);

      local_4._0_1_ = 1;

      uVar3 = FUN_00416490(local_44,uVar3,&DAT_00a2eb5c);

      local_4._0_1_ = 2;

      ppppiVar4 = ppppiVar6;

      if ((int ***)0xf < ppppiVar6[5]) {

        ppppiVar4 = (int ****)*ppppiVar6;

      }

      FUN_00416490(local_60,uVar3,ppppiVar4);

      local_4._0_1_ = 5;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44);

      local_4 = CONCAT31(local_4._1_3_,4);

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

      ppppiVar4 = (int ****)local_5c[0];

      if (local_48 < 0x10) {

        ppppiVar4 = local_5c;

      }

      cVar1 = FUN_0076adc0(ppppiVar4);

      if (cVar1 == '\0') {

        cVar1 = FUN_0076b080(param_2);

        if (cVar1 == '\0') {

          ppppiVar4 = ppppiVar6;

          if ((int ***)0xf < ppppiVar6[5]) {

            ppppiVar4 = (int ****)*ppppiVar6;

          }

          piVar5 = _errno();

          iVar2 = *piVar5;

          _Format = "Delete file failed for: %s %d\n";

          goto LAB_0076bba3;

        }

      }

      else {

        ppppiVar4 = (int ****)local_5c[0];

        if (local_48 < 0x10) {

          ppppiVar4 = local_5c;

        }

        cVar1 = Named_CalleeOf_Named_assManager_0076ba10(ppppiVar4,param_2);

        if (cVar1 == '\0') {

          ppppiVar4 = (int ****)local_5c[0];

          if (local_48 < 0x10) {

            ppppiVar4 = local_5c;

          }

          piVar5 = _errno();

          iVar2 = *piVar5;

          _Format = "Delete directory failed for: %s %d\n";

LAB_0076bba3:

          printf(_Format,ppppiVar4,iVar2);

        }

      }

      local_4 = local_4 & 0xffffff00;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_60);

      ppppiVar4 = ppppiVar6 + 6;

      ppppiVar6 = ppppiVar6 + 7;

    } while (ppppiVar4 != (int ****)local_68);

  }

  iVar2 = _rmdir(param_1);

  local_4 = 0xffffffff;

  FUN_00431ae0();

  ExceptionList = local_c;

  return iVar2 == 0;

}
