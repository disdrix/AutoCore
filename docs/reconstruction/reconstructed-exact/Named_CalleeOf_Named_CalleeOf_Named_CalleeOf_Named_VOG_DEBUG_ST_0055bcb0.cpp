// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_0055bcb0
// -----------------------------------------------------------------------------
// Stable ID: aa_0055bcb0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x0055bcb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, while×1.
//  - Notable callees: FUN_0055b7f0×2, FUN_00493380, FUN_0055bcb0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
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

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_0055bcb0(int param_1,uint32_t /* width from decompiler */ *param_2,

            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_3)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar3;

  bool bVar4;

  bool bVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  

  pbVar3 = param_3;

  puVar6 = (uint32_t /* width from decompiler */ *)(*(uint32_t /* width from decompiler */ **)(param_1 + 4))[1];

  bVar4 = true;

  cVar1 = *(char *)((int)puVar6 + 0x2d);

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  while (cVar1 == '\0') {

    bVar4 = std::operator<<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                      (pbVar3,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                               *)(puVar6 + 3));

    if (bVar4) {

      puVar7 = (uint32_t /* width from decompiler */ *)*puVar6;

    }

    else {

      puVar7 = (uint32_t /* width from decompiler */ *)puVar6[2];

    }

    puVar2 = puVar6;

    puVar6 = puVar7;

    cVar1 = *(char *)((int)puVar7 + 0x2d);

  }

  param_3 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)puVar2;

  if (bVar4 != false) {

    if (puVar2 == (uint32_t /* width from decompiler */ *)**(int **)(param_1 + 4)) {

      puVar6 = (uint32_t /* width from decompiler */ *)FUN_0055b7f0(&param_3,1,puVar2,pbVar3);

      *param_2 = *puVar6;

      *(uint8_t *)(param_2 + 1) = 1;

      return;

    }

    FUN_00493380();

  }

  puVar6 = (uint32_t /* width from decompiler */ *)param_3;

  bVar5 = std::operator<<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                    ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *

                     )((int)param_3 + 0xc),pbVar3);

  if (bVar5) {

    puVar6 = (uint32_t /* width from decompiler */ *)FUN_0055b7f0(&param_3,bVar4,puVar2,pbVar3);

    *param_2 = *puVar6;

    *(uint8_t *)(param_2 + 1) = 1;

    return;

  }

  *param_2 = puVar6;

  *(uint8_t *)(param_2 + 1) = 0;

  return;

}
