// =============================================================================
// Named_CalleeOf_Named_gfxBodyMassageMachine_009695c0
// -----------------------------------------------------------------------------
// Stable ID: aa_009695c0
// Callee of Named_gfxBodyMassageMachine
// Address:   0x009695c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxBodyMassageMachine: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, for×1, do×1, while×1.
//  - Notable callees: FUN_0044d470, FUN_009695c0, _access, _fullpath, strncat, strncpy.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_gfxBodyMassageMachine
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

uint32_t /* width from decompiler */

Named_CalleeOf_Named_gfxBodyMassageMachine_009695c0(int param_1,

            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_2)



{

  char cVar1;

  char *_Source;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *_Source_00;

  int iVar2;

  int iVar3;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *unaff_EBX;

  uint32_t /* width from decompiler */ *puVar4;

  char local_318 [2];

  uint32_t /* width from decompiler */ local_316 [129];

  uint8_t local_111;

  char local_110 [268];

  

  cVar1 = FUN_0044d470();

  if (cVar1 != '\0') {

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

              (param_2,unaff_EBX);

    return 1;

  }

  local_318[0] = '\0';

  local_318[1] = '\0';

  puVar4 = local_316;

  for (iVar3 = 0x81; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  }

  *(uint16_t *)puVar4 = 0;

  iVar3 = *(int *)(param_1 + 4);

  if (iVar3 != *(int *)(param_1 + 8)) {

    do {

      if (*(uint *)(iVar3 + 0x18) < 0x10) {

        _Source = (char *)(iVar3 + 4);

      }

      else {

        _Source = *(char **)(iVar3 + 4);

      }

      strncpy(local_318,_Source,0x104);

      if (*(uint *)(unaff_EBX + 0x18) < 0x10) {

        _Source_00 = unaff_EBX + 4;

      }

      else {

        _Source_00 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                       **)(unaff_EBX + 4);

      }

      strncat(local_318,(char *)_Source_00,0x104);

      local_111 = 0;

      iVar2 = _access(local_318,0);

      if (iVar2 == 0) {

        _fullpath(local_110,local_318,0x104);

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

                  (param_2,local_110);

        return 1;

      }

      iVar3 = iVar3 + 0x1c;

    } while (iVar3 != *(int *)(param_1 + 8));

  }

  return 0;

}
