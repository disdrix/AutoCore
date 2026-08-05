// READABILITY (auto CF):
//  - Body size: ~91 non-empty decompiler lines.
//  - Control keywords: if×9, return×3, do×2, while×2, for×1.
//  - Notable callees: FUN_0076cec0×2, vog_LogMessage×2, Effects, FUN_0073dc40, FUN_0096a630.
//  - Strings: "Effects (%d) still allocated at shutdown!"; "\t%d Instances of effect :%s".
//  - Return sites: 3.

// =============================================================================
// Named_effEffectFactory
// -----------------------------------------------------------------------------
// Stable ID: aa_0073dc40
// Address:   0x0073dc40  (autoassault.exe, image base 0x400000)
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

void Named_effEffectFactory(int param_1)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  bool bVar5;

  uint32_t /* width from decompiler */ uVar6;

  int iVar7;

  int *piVar8;

  int *piVar9;

  uint32_t /* width from decompiler */ *puVar10;

  int iVar11;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar4 = param_1;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ad739;

  local_c = ExceptionList;

  iVar11 = *(int *)(param_1 + 4);

  if ((iVar11 != 0) && (iVar1 = *(int *)(param_1 + 8), (iVar1 - iVar11) / 0x14 != 0)) {

    bVar5 = false;

    ExceptionList = &local_c;

    if (iVar11 != iVar1) {

      piVar8 = (int *)(iVar11 + 0xc);

      ExceptionList = &local_c;

      do {

        piVar2 = (int *)*piVar8;

        for (piVar9 = (int *)piVar8[-1]; piVar9 != piVar2; piVar9 = piVar9 + 1) {

          iVar3 = *piVar9;

          if (0 < *(int *)(iVar3 + 4)) {

            if (!bVar5) {

              iVar7 = 0;

              if (*(int *)(iVar4 + 4) != 0) {

                iVar7 = (*(int *)(iVar4 + 8) - *(int *)(iVar4 + 4)) / 0x14;

              }

              uVar6 = FUN_0076cec0(&param_1,"Effects (%d) still allocated at shutdown!",iVar7);

              vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effEffectFactory.cpp"

                             ,0x89,2,uVar6);

              bVar5 = true;

            }

            iVar7 = FUN_0096a630(local_28);

            local_4 = 0;

            if (*(uint *)(iVar7 + 0x18) < 0x10) {

              iVar7 = iVar7 + 4;

            }

            else {

              iVar7 = *(int *)(iVar7 + 4);

            }

            uVar6 = FUN_0076cec0(&param_1,"\t%d Instances of effect :%s",*(uint32_t /* width from decompiler */ *)(iVar3 + 4),

                                 iVar7);

            vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effEffectFactory.cpp"

                           ,0x8d,1,uVar6);

            local_4 = 0xffffffff;

            std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

            ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

          }

        }

        iVar11 = iVar11 + 0x14;

        piVar8 = piVar8 + 5;

      } while (iVar11 != iVar1);

    }

    iVar11 = *(int *)(iVar4 + 4);

    if (iVar11 != 0) {

      iVar4 = *(int *)(iVar4 + 8);

      if (iVar11 != iVar4) {

        puVar10 = (uint32_t /* width from decompiler */ *)(iVar11 + 8);

        do {

          if ((void *)*puVar10 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

            operator_delete((void *)*puVar10);

          }

          *puVar10 = 0;

          puVar10[1] = 0;

          puVar10[2] = 0;

          iVar11 = iVar11 + 0x14;

          puVar10 = puVar10 + 5;

        } while (iVar11 != iVar4);

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)(param_1 + 4));

    }

    *(uint32_t /* width from decompiler */ *)(iVar4 + 4) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 8) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

  }

  ExceptionList = local_c;

  return;

}
