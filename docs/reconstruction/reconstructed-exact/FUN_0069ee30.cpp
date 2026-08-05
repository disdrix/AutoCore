// =============================================================================
// FUN_0069ee30
// -----------------------------------------------------------------------------
// Stable ID: aa_0069ee30
// Address:   0x0069ee30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0069ee30 @ 0x0069ee30
// Stable ID: aa_0069ee30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1, for×1.
//  - Notable callees: FUN_0069ee30.
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

void __fastcall FUN_0069ee30(int param_1)



{

  int iVar1;

  int iVar2;

  

  operator_delete__(*(void **)(param_1 + 0x40));

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = 0;

  if (*(int *)(param_1 + 0x38) != 0) {

    iVar2 = 0;

    if (0 < *(int *)(param_1 + 0x30)) {

      do {

        operator_delete__(*(void **)(*(int *)(param_1 + 0x38) + iVar2 * 4));

        iVar2 = iVar2 + 1;

      } while (iVar2 < *(int *)(param_1 + 0x30));

    }

    operator_delete__(*(void **)(param_1 + 0x38));

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0;

  }

  operator_delete__(*(void **)(param_1 + 0x3c));

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

  iVar2 = *(int *)(param_1 + 0x10);

  if (iVar2 != 0) {

    iVar1 = *(int *)(param_1 + 0x14);

    for (; iVar2 != iVar1; iVar2 = iVar2 + 0x54) {

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                 (iVar2 + 0x14));

    }

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x10));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

  return;

}
