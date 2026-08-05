// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00685f40
// -----------------------------------------------------------------------------
// Stable ID: aa_00685f40
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00685f40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~77 non-empty decompiler lines.
//  - Control keywords: if×7, do×3, while×3, goto×1, return×1.
//  - Notable callees: FUN_00685f40.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00685f40(int param_1,

            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_2)



{

  int *piVar1;

  char cVar2;

  uint uVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int *piVar7;

  char *pcVar8;

  int iVar9;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_428 [28];

  char local_40c [1024];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a9cfc;

  local_c = ExceptionList;

  uVar3 = *(uint *)(param_1 + 0x18);

  piVar1 = (int *)(param_1 + 4);

  piVar7 = piVar1;

  if (0xf < uVar3) {

    piVar7 = (int *)*piVar1;

  }

  pcVar8 = local_40c;

  do {

    cVar2 = *(char *)piVar7;

    piVar7 = (int *)((int)piVar7 + 1);

    *pcVar8 = cVar2;

    pcVar8 = pcVar8 + 1;

  } while (cVar2 != '\0');

  iVar4 = *(int *)(param_1 + 0x14);

  iVar9 = iVar4;

  do {

    iVar5 = iVar9;

    iVar9 = iVar5 + -1;

    if (iVar9 < 0) goto LAB_00685feb;

    piVar7 = piVar1;

    if (0xf < uVar3) {

      piVar7 = (int *)*piVar1;

    }

    if (*(char *)((int)piVar7 + iVar9) == '/') break;

    piVar7 = piVar1;

    if (0xf < uVar3) {

      piVar7 = (int *)*piVar1;

    }

  } while (*(char *)((int)piVar7 + iVar9) != '\\');

  iVar9 = 0;

  if (iVar5 < iVar4) {

    iVar9 = iVar4 - iVar5;

    iVar6 = iVar5;

    do {

      piVar7 = piVar1;

      if (0xf < uVar3) {

        piVar7 = (int *)*piVar1;

      }

      local_40c[iVar6 - iVar5] = *(char *)(iVar6 + (int)piVar7);

      iVar6 = iVar6 + 1;

    } while (iVar6 < iVar4);

  }

  local_40c[iVar9] = '\0';

LAB_00685feb:

  ExceptionList = &local_c;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_428,local_40c);

  local_4 = 0;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(param_2,local_428);

  local_4 = 0xffffffff;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_428);

  ExceptionList = local_c;

  return param_2;

}
