// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, do×1, while×1.
//  - Notable callees: FUN_0076cec0, FUN_0096a630, FUN_0096cad0, FUN_0096e8e0, ReCreate, vog_LogMessage.
//  - Strings: "Failure on ReCreate() of effTextureImpl %s at <%x>".
//  - Return sites: 2.

// =============================================================================
// Named_effTextureFactory_0096e8e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0096e8e0
// Address:   0x0096e8e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "effTextureFactory"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int Named_effTextureFactory_0096e8e0(int param_1)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int *piVar4;

  int iVar5;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b09a1;

  local_c = ExceptionList;

  piVar4 = (int *)**(int **)(param_1 + 8);

  iVar5 = 0;

  ExceptionList = &local_c;

  if (piVar4 != *(int **)(param_1 + 8)) {

    do {

      iVar1 = piVar4[2];

      if (*(int *)(iVar1 + 0x30) == 0) {

        iVar5 = 0;

        if ((*(uint *)(iVar1 + 0x2c) & 0x3000) == 0) {

          iVar5 = FUN_0096cad0(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x24),*(uint32_t /* width from decompiler */ *)(iVar1 + 0x1c),

                               *(uint32_t /* width from decompiler */ *)(iVar1 + 0x20),*(uint32_t /* width from decompiler */ *)(iVar1 + 0x34),0,

                               *(uint32_t /* width from decompiler */ *)(iVar1 + 0xc));

        }

        else {

          (**(code **)(**(int **)(iVar1 + 0x4c) + 8))();

        }

        if (iVar5 < 0) {

          iVar2 = FUN_0096a630(abStack_28);

          uStack_4 = 0;

          if (*(uint *)(iVar2 + 0x18) < 0x10) {

            iVar2 = iVar2 + 4;

          }

          else {

            iVar2 = *(int *)(iVar2 + 4);

          }

          uVar3 = FUN_0076cec0(&param_1,"Failure on ReCreate() of effTextureImpl %s at <%x>",iVar2,

                               iVar1);

          vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTextureFactory.cpp"

                         ,0x159,5,uVar3);

          uStack_4 = 0xffffffff;

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_28);

          ExceptionList = local_c;

          return iVar5;

        }

      }

      piVar4 = (int *)*piVar4;

    } while (piVar4 != (int *)*(int *)(param_1 + 8));

  }

  ExceptionList = local_c;

  return iVar5;

}
