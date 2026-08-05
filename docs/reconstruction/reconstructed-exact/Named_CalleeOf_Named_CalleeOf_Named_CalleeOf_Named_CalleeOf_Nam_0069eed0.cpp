// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0069eed0
// -----------------------------------------------------------------------------
// Stable ID: aa_0069eed0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0069eed0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_0069ea40, FUN_0069ead0, FUN_0069eed0.
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0069eed0(int param_1,uint param_2)



{

  uint uVar1;

  int iVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009aaf38;

  local_c = ExceptionList;

  iVar2 = *(int *)(param_1 + 4);

  local_4 = 0;

  if (iVar2 == 0) {

    uVar1 = 0;

  }

  else {

    uVar1 = (*(int *)(param_1 + 8) - iVar2) / 0x54;

  }

  if (uVar1 < param_2) {

    if (iVar2 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_1 + 8) - iVar2) / 0x54;

    }

    ExceptionList = &local_c;

    FUN_0069ead0(*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_2 - iVar2,&stack0x00000008);

  }

  else {

    ExceptionList = &local_c;

    if (iVar2 != 0) {

      ExceptionList = &local_c;

      if (param_2 < (uint)((*(int *)(param_1 + 8) - iVar2) / 0x54)) {

        ExceptionList = &local_c;

        FUN_0069ea40(&param_2,param_2 * 0x54 + iVar2,*(int *)(param_1 + 8));

      }

    }

  }

  local_4 = 0xffffffff;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

             &stack0x0000001c);

  ExceptionList = local_c;

  return;

}
