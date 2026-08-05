// =============================================================================
// FUN_0044d9f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0044d9f0
// Address:   0x0044d9f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0044d9f0 @ 0x0044d9f0
// Stable ID: aa_0044d9f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, while×1.
//  - Notable callees: FUN_00430b60×2, FUN_004313d0, FUN_0044d9f0.
//  - Return sites: 3.

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

void FUN_0044d9f0(int param_1)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  bool bVar3;

  bool bVar4;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *in_EAX;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *unaff_EBX;

  uint32_t /* width from decompiler */ *puVar6;

  

  puVar5 = (uint32_t /* width from decompiler */ *)(*(uint32_t /* width from decompiler */ **)(param_1 + 4))[1];

  bVar3 = true;

  cVar1 = *(char *)((int)puVar5 + 0x2d);

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  while (cVar1 == '\0') {

    bVar3 = std::operator><char,struct_std::char_traits<char>,class_std::allocator<char>_>

                      (in_EAX,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                               *)(puVar5 + 3));

    if (bVar3) {

      puVar6 = (uint32_t /* width from decompiler */ *)*puVar5;

    }

    else {

      puVar6 = (uint32_t /* width from decompiler */ *)puVar5[2];

    }

    puVar2 = puVar5;

    puVar5 = puVar6;

    cVar1 = *(char *)((int)puVar6 + 0x2d);

  }

  if (bVar3 != false) {

    if (puVar2 == (uint32_t /* width from decompiler */ *)**(int **)(param_1 + 4)) {

      puVar5 = (uint32_t /* width from decompiler */ *)FUN_00430b60(&param_1,1,in_EAX);

      *unaff_EBX = *puVar5;

      *(uint8_t *)(unaff_EBX + 1) = 1;

      return;

    }

    FUN_004313d0();

  }

  bVar4 = std::operator><char,struct_std::char_traits<char>,class_std::allocator<char>_>

                    ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *

                     )(puVar2 + 3),in_EAX);

  if (bVar4) {

    puVar5 = (uint32_t /* width from decompiler */ *)FUN_00430b60(&param_1,bVar3,in_EAX);

    *unaff_EBX = *puVar5;

    *(uint8_t *)(unaff_EBX + 1) = 1;

    return;

  }

  *unaff_EBX = puVar2;

  *(uint8_t *)(unaff_EBX + 1) = 0;

  return;

}
