// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_QuickBar_Ac_00403c60
// -----------------------------------------------------------------------------
// Stable ID: aa_00403c60
// Callee of Named_CalleeOf_Named_CalleeOf_Client_QuickBar_ActivateSlot
// Address:   0x00403c60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_QuickBar_ActivateSlot: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: while×1, if×1, return×1.
//  - Notable callees: FUN_00403c60.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_QuickBar_ActivateSlot
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

uint32_t /* width from decompiler */ *

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_QuickBar_Ac_00403c60(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  bool bVar3;

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  

  puVar5 = (uint32_t /* width from decompiler */ *)(*(uint32_t /* width from decompiler */ **)(in_EAX + 4))[1];

  cVar1 = *(char *)((int)puVar5 + 0x131);

  puVar2 = *(uint32_t /* width from decompiler */ **)(in_EAX + 4);

  while (cVar1 == '\0') {

    bVar3 = std::operator<<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                      ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        *)(puVar5 + 3),param_1);

    if (bVar3) {

      puVar4 = (uint32_t /* width from decompiler */ *)puVar5[2];

      puVar5 = puVar2;

    }

    else {

      puVar4 = (uint32_t /* width from decompiler */ *)*puVar5;

    }

    puVar2 = puVar5;

    puVar5 = puVar4;

    cVar1 = *(char *)((int)puVar4 + 0x131);

  }

  return puVar2;

}
