// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004935e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004935e0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO
// Address:   0x004935e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_004935e0, FUN_0055b530.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO
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

void __thiscall

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004935e0(int param_1,int *param_2,

            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_3)



{

  bool bVar1;

  int iVar2;

  

  iVar2 = FUN_0055b530(param_3);

  if (iVar2 != *(int *)(param_1 + 4)) {

    bVar1 = std::operator<<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                      (param_3,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                                *)(iVar2 + 0xc));

    if (!bVar1) {

      *param_2 = iVar2;

      return;

    }

  }

  *param_2 = *(int *)(param_1 + 4);

  return;

}
