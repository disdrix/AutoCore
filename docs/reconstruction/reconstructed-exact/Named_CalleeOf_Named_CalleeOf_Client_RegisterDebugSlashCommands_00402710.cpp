// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RegisterDebugSlashCommands_00402710
// -----------------------------------------------------------------------------
// Stable ID: aa_00402710
// Callee of Named_CalleeOf_Client_RegisterDebugSlashCommands
// Address:   0x00402710  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RegisterDebugSlashCommands: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, while×1.
//  - Notable callees: FUN_00402f70×2, FUN_00402710, FUN_00404220.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RegisterDebugSlashCommands
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

void Named_CalleeOf_Named_CalleeOf_Client_RegisterDebugSlashCommands_00402710(int param_1)



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

  cVar1 = *(char *)((int)puVar5 + 0x131);

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  while (cVar1 == '\0') {

    bVar3 = std::operator<<char,struct_std::char_traits<char>,class_std::allocator<char>_>

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

    cVar1 = *(char *)((int)puVar6 + 0x131);

  }

  if (bVar3 != false) {

    if (puVar2 == (uint32_t /* width from decompiler */ *)**(int **)(param_1 + 4)) {

      puVar5 = (uint32_t /* width from decompiler */ *)FUN_00402f70(&param_1,1,in_EAX);

      *unaff_EBX = *puVar5;

      *(uint8_t *)(unaff_EBX + 1) = 1;

      return;

    }

    FUN_00404220();

  }

  bVar4 = std::operator<<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                    ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *

                     )(puVar2 + 3),in_EAX);

  if (bVar4) {

    puVar5 = (uint32_t /* width from decompiler */ *)FUN_00402f70(&param_1,bVar3,in_EAX);

    *unaff_EBX = *puVar5;

    *(uint8_t *)(unaff_EBX + 1) = 1;

    return;

  }

  *unaff_EBX = puVar2;

  *(uint8_t *)(unaff_EBX + 1) = 0;

  return;

}
