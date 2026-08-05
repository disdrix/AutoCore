// =============================================================================
// FUN_004303c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004303c0
// Address:   0x004303c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004303c0 @ 0x004303c0
// Stable ID: aa_004303c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×10, return×7, goto×1.
//  - Notable callees: FUN_00430b60×6, FUN_00401d90×2, FUN_0042ac40, FUN_004303c0, FUN_004309c0, FUN_004313d0.
//  - Return sites: 7.

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

void __thiscall FUN_004303c0(int param_1,int *param_2)



{

  int *piVar1;

  bool bVar2;

  char cVar3;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *in_EAX;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  if (*(int *)(param_1 + 8) == 0) {

    FUN_00430b60(unaff_ESI,1,in_EAX);

    return;

  }

  piVar1 = *(int **)(param_1 + 4);

  if (param_2 == (int *)*piVar1) {

    bVar2 = std::operator<<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                      (in_EAX,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                               *)(param_2 + 3));

    if (bVar2) {

LAB_00430408:

      FUN_00430b60(unaff_ESI,1,in_EAX);

      return;

    }

  }

  else if (param_2 == piVar1) {

    bVar2 = std::operator<<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                      ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        *)(piVar1[2] + 0xc),in_EAX);

    if (bVar2) {

      FUN_00430b60(unaff_ESI,0,in_EAX);

      return;

    }

  }

  else {

    bVar2 = std::operator<<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                      (in_EAX,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                               *)(param_2 + 3));

    if (bVar2) {

      FUN_004313d0();

      cVar3 = FUN_00401d90(param_2 + 3,in_EAX);

      if (cVar3 != '\0') {

        if (*(char *)(param_2[2] + 0x2d) != '\0') {

          FUN_00430b60(unaff_ESI,0,in_EAX);

          return;

        }

        goto LAB_00430408;

      }

    }

    bVar2 = std::operator<<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                      ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        *)(param_2 + 3),in_EAX);

    if ((bVar2) &&

       ((FUN_0042ac40(), param_2 == *(int **)(param_1 + 4) ||

        (cVar3 = FUN_00401d90(in_EAX,param_2 + 3), cVar3 != '\0')))) {

      if (*(char *)(param_2[2] + 0x2d) == '\0') {

        FUN_00430b60(unaff_ESI,1,in_EAX);

        return;

      }

      FUN_00430b60(unaff_ESI,0,in_EAX);

      return;

    }

  }

  puVar4 = (uint32_t /* width from decompiler */ *)FUN_004309c0(param_1);

  *unaff_ESI = *puVar4;

  return;

}
