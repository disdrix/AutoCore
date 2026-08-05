// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006a08a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006a08a0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x006a08a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~70 non-empty decompiler lines.
//  - Control keywords: if×12, return×8, goto×1.
//  - Notable callees: FUN_006a02e0×7, FUN_00401d90×2, FUN_0069fb50, FUN_0069fd00, FUN_006a07c0, FUN_006a08a0.
//  - Return sites: 8.

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

uint32_t /* width from decompiler */ * __thiscall

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006a08a0(int param_1,uint32_t /* width from decompiler */ *param_2,int *param_3,

            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_4)



{

  int *piVar1;

  bool bVar2;

  char cVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint8_t local_8 [8];

  

  if (*(int *)(param_1 + 8) == 0) {

    FUN_006a02e0(param_2,1,*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_4);

    return param_2;

  }

  piVar1 = *(int **)(param_1 + 4);

  if (param_3 == (int *)*piVar1) {

    bVar2 = std::operator<<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                      (param_4,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                                *)(param_3 + 3));

    if (bVar2) {

      FUN_006a02e0(param_2,1,param_3,param_4);

      return param_2;

    }

  }

  else if (param_3 == piVar1) {

    bVar2 = std::operator<<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                      ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        *)(piVar1[2] + 0xc),param_4);

    if (bVar2) {

      FUN_006a02e0(param_2,0,*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 4) + 8),param_4);

      return param_2;

    }

  }

  else {

    bVar2 = std::operator<<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                      (param_4,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                                *)(param_3 + 3));

    if (bVar2) {

      FUN_0069fb50();

      cVar3 = FUN_00401d90(param_3 + 3,param_4);

      if (cVar3 != '\0') {

        if (*(char *)(param_3[2] + 0x2d) != '\0') {

          FUN_006a02e0(param_2,0,param_3,param_4);

          return param_2;

        }

        FUN_006a02e0(param_2,1,param_3,param_4);

        return param_2;

      }

    }

    bVar2 = std::operator<<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                      ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        *)(param_3 + 3),param_4);

    if (bVar2) {

      FUN_0069fd00();

      if (param_3 != *(int **)(param_1 + 4)) {

        cVar3 = FUN_00401d90(param_4,param_3 + 3);

        if (cVar3 == '\0') goto LAB_006a0a34;

      }

      if (*(char *)(param_3[2] + 0x2d) != '\0') {

        FUN_006a02e0(param_2,0,param_3,param_4);

        return param_2;

      }

      FUN_006a02e0(param_2,1,param_3,param_4);

      return param_2;

    }

  }

LAB_006a0a34:

  puVar4 = (uint32_t /* width from decompiler */ *)FUN_006a07c0(local_8,param_4);

  *param_2 = *puVar4;

  return param_2;

}
