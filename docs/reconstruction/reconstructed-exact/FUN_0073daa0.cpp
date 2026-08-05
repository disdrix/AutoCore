// =============================================================================
// FUN_0073daa0
// -----------------------------------------------------------------------------
// Stable ID: aa_0073daa0
// Address:   0x0073daa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073daa0 @ 0x0073daa0
// Stable ID: aa_0073daa0
// Embedded strings (evidence for future rename):
//   - "Effects (%d) still allocated at shutdown!"
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effEffectFactory.cpp"
//   - "\t%d Instances of effect :%s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, for×1, while×1, return×1.
//  - Notable callees: FUN_0076cec0×2, vog_LogMessage×2, Effects, FUN_0073daa0, FUN_0096a630.
//  - Strings: "Effects (%d) still allocated at shutdown!"; "\t%d Instances of effect :%s".
//  - Return sites: 1.

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

void FUN_0073daa0(int param_1)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  bool bVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  int iVar7;

  int *piVar8;

  int *piVar9;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &DAT_009ad726;

  local_c = ExceptionList;

  iVar7 = *(int *)(param_1 + 4);

  if (((iVar7 != 0) && (iVar1 = *(int *)(param_1 + 8), (iVar1 - iVar7) / 0x14 != 0)) &&

     (bVar4 = false, iVar7 != iVar1)) {

    piVar8 = (int *)(iVar7 + 0xc);

    ExceptionList = &local_c;

    do {

      piVar2 = (int *)*piVar8;

      for (piVar9 = (int *)piVar8[-1]; piVar9 != piVar2; piVar9 = piVar9 + 1) {

        iVar3 = *piVar9;

        if (0 < *(int *)(iVar3 + 4)) {

          if (!bVar4) {

            if (*(int *)(param_1 + 4) == 0) {

              iVar5 = 0;

            }

            else {

              iVar5 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x14;

            }

            uVar6 = FUN_0076cec0(&param_1,"Effects (%d) still allocated at shutdown!",iVar5);

            vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effEffectFactory.cpp"

                           ,0xb0,2,uVar6);

            bVar4 = true;

          }

          iVar5 = FUN_0096a630(local_28);

          local_4 = 0;

          if (*(uint *)(iVar5 + 0x18) < 0x10) {

            iVar5 = iVar5 + 4;

          }

          else {

            iVar5 = *(int *)(iVar5 + 4);

          }

          uVar6 = FUN_0076cec0(&param_1,"\t%d Instances of effect :%s",*(uint32_t /* width from decompiler */ *)(iVar3 + 4),

                               iVar5);

          vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effEffectFactory.cpp"

                         ,0xb4,1,uVar6);

          local_4 = 0xffffffff;

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

        }

      }

      iVar7 = iVar7 + 0x14;

      piVar8 = piVar8 + 5;

    } while (iVar7 != iVar1);

  }

  ExceptionList = local_c;

  return;

}
