// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxFont_00463c40
// -----------------------------------------------------------------------------
// Stable ID: aa_00463c40
// Callee of Named_CalleeOf_Named_gfxFont
// Address:   0x00463c40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxFont: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, do×1, while×1.
//  - Notable callees: FUN_00463c40, FUN_00766250.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxFont
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

void Named_CalleeOf_Named_CalleeOf_Named_gfxFont_00463c40(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint uVar1;

  bool bVar2;

  uint uVar3;

  int *piVar4;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *unaff_ESI;

  

  uVar1 = *(uint *)(param_1 + 0x20);

  uVar3 = FUN_00766250();

  uVar3 = (uVar3 ^ *(uint *)(unaff_ESI + 0x20) ^ *(uint *)(unaff_ESI + 0x1c)) & uVar1;

  if (*(uint *)(param_1 + 0x24) <= uVar3) {

    uVar3 = uVar3 + (-1 - (uVar1 >> 1));

  }

  piVar4 = *(int **)(*(int *)(param_1 + 0x14) + uVar3 * 4);

  if (piVar4 != *(int **)(*(int *)(param_1 + 0x14) + 4 + uVar3 * 4)) {

    do {

      bVar2 = std::operator<<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                          *)(piVar4 + 2),unaff_ESI);

      if ((!bVar2) &&

         ((bVar2 = std::operator==<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                             ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                               *)(piVar4 + 2),unaff_ESI), !bVar2 ||

          ((*(int *)(unaff_ESI + 0x1c) <= piVar4[9] &&

           ((piVar4[9] != *(int *)(unaff_ESI + 0x1c) || (*(int *)(unaff_ESI + 0x20) <= piVar4[10])))

           ))))) {

        bVar2 = std::operator<<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                          (unaff_ESI,

                           (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                            *)(piVar4 + 2));

        if ((!bVar2) &&

           ((bVar2 = std::operator==<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                               (unaff_ESI,

                                (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                                 *)(piVar4 + 2)), !bVar2 ||

            ((piVar4[9] <= *(int *)(unaff_ESI + 0x1c) &&

             ((*(int *)(unaff_ESI + 0x1c) != piVar4[9] || (piVar4[10] <= *(int *)(unaff_ESI + 0x20))

              ))))))) {

          *param_2 = piVar4;

          return;

        }

        *param_2 = *(uint32_t /* width from decompiler */ *)(param_1 + 8);

        return;

      }

      piVar4 = (int *)*piVar4;

    } while (piVar4 != (int *)*(int *)(*(int *)(param_1 + 0x14) + 4 + uVar3 * 4));

  }

  *param_2 = *(uint32_t /* width from decompiler */ *)(param_1 + 8);

  return;

}
