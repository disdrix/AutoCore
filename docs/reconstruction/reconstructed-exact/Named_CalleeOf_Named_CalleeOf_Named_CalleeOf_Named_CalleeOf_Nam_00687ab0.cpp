// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00687ab0
// -----------------------------------------------------------------------------
// Stable ID: aa_00687ab0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00687ab0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: do×2, if×2, while×2, for×2, return×1.
//  - Notable callees: FUN_00699ee0×2, FUN_00687ab0, FUN_00699f00.
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00687ab0(int param_1)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  char *pcVar4;

  uint uVar5;

  char *pcVar6;

  char *pcVar7;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a9f79;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  iVar2 = FUN_00699ee0();

  do {

    if (iVar2 == 0x4a3a) {

      iVar2 = FUN_00699f00(local_28);

      local_4 = 0;

      if (*(uint *)(iVar2 + 0x18) < 0x10) {

        pcVar6 = (char *)(iVar2 + 4);

      }

      else {

        pcVar6 = *(char **)(iVar2 + 4);

      }

      pcVar3 = pcVar6;

      do {

        cVar1 = *pcVar3;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

      pcVar3 = pcVar3 + (1 - (int)(pcVar6 + 1));

      pcVar4 = operator_new__((uint)pcVar3);

      pcVar7 = pcVar4;

      for (uVar5 = (uint)pcVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)pcVar6;

        pcVar6 = pcVar6 + 4;

        pcVar7 = pcVar7 + 4;

      }

      for (uVar5 = (uint)pcVar3 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

        *pcVar7 = *pcVar6;

        pcVar6 = pcVar6 + 1;

        pcVar7 = pcVar7 + 1;

      }

      *(char **)(param_1 + 100) = pcVar4;

      local_4 = 0xffffffff;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

    }

    iVar2 = FUN_00699ee0();

  } while (iVar2 != 0x4a39);

  ExceptionList = local_c;

  return;

}
