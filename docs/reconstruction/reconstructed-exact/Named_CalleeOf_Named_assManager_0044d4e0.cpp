// =============================================================================
// Named_CalleeOf_Named_assManager_0044d4e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0044d4e0
// Callee of Named_assManager
// Address:   0x0044d4e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_assManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, for×1, return×1.
//  - Notable callees: FUN_0044d4e0.
//  - Return sites: 1.

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

void Named_CalleeOf_Named_assManager_0044d4e0(int param_1,int *param_2,int param_3)



{

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar1;

  int iVar2;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar3;

  

  pbVar1 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)

            (param_1 + 8);

  pbVar3 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

           (param_3 + 0x1c);

  if (pbVar3 != pbVar1) {

    iVar2 = param_3 - (int)pbVar3;

    do {

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

                (pbVar3 + iVar2,pbVar3);

      pbVar3 = pbVar3 + 0x1c;

    } while (pbVar3 != pbVar1);

  }

  pbVar1 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)

            (param_1 + 8);

  for (pbVar3 = pbVar1 + -0x1c; pbVar3 != pbVar1; pbVar3 = pbVar3 + 0x1c) {

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(pbVar3);

  }

  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x1c;

  *param_2 = param_3;

  return;

}
