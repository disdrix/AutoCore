// =============================================================================
// Named_CalleeOf_Named_assId_00436f10
// -----------------------------------------------------------------------------
// Stable ID: aa_00436f10
// Callee of Named_assId (+7 other named callers)
// Address:   0x00436f10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_assId: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_assId (+7 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×5, return×4, do×1, while×1.
//  - Notable callees: FUN_00435df0, FUN_00436f10.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_assId (+7 other named callers)
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_assId_00436f10(void)



{

  char cVar1;

  int iVar2;

  int unaff_ESI;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *unaff_EDI;

  

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::resize

            (unaff_EDI,0);

  if (*(int *)(unaff_ESI + 4) + *(int *)(unaff_ESI + 8) < *(int *)(unaff_ESI + 0x14)) {

    do {

      if (*(int *)(unaff_ESI + 0xc) < *(int *)(unaff_ESI + 4) + 1) {

        iVar2 = FUN_00435df0(*(int *)(unaff_ESI + 8) + *(int *)(unaff_ESI + 4));

        if (iVar2 < 0) {

          return 0xffffffff;

        }

        if (*(int *)(unaff_ESI + 0xc) < 1) {

          return 0xffffffff;

        }

      }

      cVar1 = *(char *)(*(int *)(unaff_ESI + 4) + 0x18 + unaff_ESI);

      *(int *)(unaff_ESI + 4) = *(int *)(unaff_ESI + 4) + 1;

      if (cVar1 == '\0') {

        return 0;

      }

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator+=

                (unaff_EDI,cVar1);

    } while (*(int *)(unaff_ESI + 4) + *(int *)(unaff_ESI + 8) < *(int *)(unaff_ESI + 0x14));

  }

  return 0xffffffff;

}
