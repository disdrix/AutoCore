// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_00456f10, FUN_0073d9b0, FUN_0076cec0, FUN_0096a630, vog_LogMessage.
//  - Strings: "Impls still exist of effect :%s\n".
//  - Return sites: 1.

// =============================================================================
// Named_effEffectFactory_0073d9b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0073d9b0
// Address:   0x0073d9b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "effEffectFactory"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_effEffectFactory_0073d9b0(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *piVar4;

  int unaff_EDI;

  uint8_t local_2c [4];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ad713;

  local_c = ExceptionList;

  piVar4 = *(int **)(unaff_EDI + 4);

  ExceptionList = &local_c;

  if (piVar4 != *(int **)(unaff_EDI + 8)) {

    do {

      if (*piVar4 == param_1) {

        if ((piVar4[2] != 0) && (piVar4[3] - piVar4[2] >> 2 != 0)) {

          iVar1 = FUN_0096a630(local_28);

          local_4 = 0;

          if (*(uint *)(iVar1 + 0x18) < 0x10) {

            iVar1 = iVar1 + 4;

          }

          else {

            iVar1 = *(int *)(iVar1 + 4);

          }

          uVar2 = FUN_0076cec0(&param_1,"Impls still exist of effect :%s\n",iVar1);

          vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effEffectFactory.cpp"

                         ,0xdd,1,uVar2);

          local_4 = 0xffffffff;

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

        }

        puVar3 = (uint32_t /* width from decompiler */ *)FUN_00456f10(unaff_EDI,local_2c,piVar4);

        piVar4 = (int *)*puVar3;

      }

      else {

        piVar4 = piVar4 + 5;

      }

    } while (piVar4 != *(int **)(unaff_EDI + 8));

  }

  ExceptionList = local_c;

  return;

}
