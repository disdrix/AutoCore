// READABILITY (auto CF):
//  - Body size: ~101 non-empty decompiler lines.
//  - Control keywords: if×10, do×1, for×1, goto×1, while×1, return×1.
//  - Notable callees: EnterCriticalSection×2, LeaveCriticalSection×2, CONCAT31, FUN_0040d9c0, FUN_0043c5f0, FUN_0043d670, FUN_0043d700, FUN_0043e970.
//  - Strings: "PRELOAD: unable to preload child asset %s"; "C:\\vog\\1_code\\palantir\\palantir\\assets\\assPreloader.cpp".
//  - Return sites: 1.

// =============================================================================
// Named_assPreloader_00971280
// -----------------------------------------------------------------------------
// Stable ID: aa_00971280
// Address:   0x00971280  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "assPreloader"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_assPreloader_00971280(int param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  uint uVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint uVar8;

  uint32_t /* width from decompiler */ uStack_44;

  int iStack_40;

  uint8_t local_3c [4];

  int local_38;

  uint local_34;

  uint local_30;

  int local_2c;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009afdde;

  local_c = ExceptionList;

  puVar7 = *(uint32_t /* width from decompiler */ **)(param_2 + 4);

  iVar4 = param_2;

  ExceptionList = &local_c;

  if (puVar7 != *(uint32_t /* width from decompiler */ **)(param_2 + 8)) {

    do {

      FUN_00970fc0();

      iVar1 = *(int *)(param_1 + 0xe0);

      piVar2 = (int *)FUN_0044a860();

      if (*piVar2 == iVar1) {

        local_38 = 0;

        local_34 = 0;

        local_30 = 0;

        local_2c = 0;

        local_4 = 0;

        FUN_0043c5f0(local_3c);

        for (uVar8 = local_30; uVar8 != local_30 + local_2c; uVar8 = uVar8 + 1) {

          uVar3 = uVar8 >> 2;

          iVar4 = uVar3 * -4;

          if (local_34 <= uVar3) {

            uVar3 = uVar3 - local_34;

          }

          iVar4 = (**(code **)(**(int **)(*(int *)(local_38 + uVar3 * 4) + (uVar8 + iVar4) * 4) +

                              0xc))(puVar7);

          if (iVar4 != 0) {

            uStack_44 = 0;

            if (&uStack_44 != puVar7) {

              uStack_44 = *puVar7;

            }

            iStack_40 = iVar4;

            if (*(char *)(param_1 + 0x78) != '\0') {

              EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x60));

            }

            local_4._0_1_ = 1;

            FUN_0043e970(&uStack_44);

            local_4 = (uint)local_4._1_3_ << 8;

            if (*(char *)(param_1 + 0x78) != '\0') {

              LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x60));

            }

            puVar5 = (uint32_t /* width from decompiler */ *)FUN_0043d700();

            *puVar5 = 1;

            goto LAB_00971434;

          }

        }

        iVar4 = FUN_0096a630(abStack_28);

        local_4._0_1_ = 2;

        if (*(uint *)(iVar4 + 0x18) < 0x10) {

          iVar4 = iVar4 + 4;

        }

        else {

          iVar4 = *(int *)(iVar4 + 4);

        }

        uVar6 = FUN_0076cec0(&param_2,"PRELOAD: unable to preload child asset %s",iVar4);

        vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\assets\\assPreloader.cpp",0x241,2,uVar6

                      );

        local_4 = (uint)local_4._1_3_ << 8;

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_28);

        if (*(char *)(param_1 + 0xa8) != '\0') {

          EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x90));

        }

        local_4 = CONCAT31(local_4._1_3_,3);

        FUN_0043d670(puVar7);

        if (*(char *)(param_1 + 0xa8) != '\0') {

          LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x90));

        }

LAB_00971434:

        Sleep(0);

        local_4 = 0xffffffff;

        FUN_0040d9c0();

        iVar4 = param_2;

      }

      puVar7 = puVar7 + 1;

    } while (puVar7 != *(uint32_t /* width from decompiler */ **)(iVar4 + 8));

  }

  ExceptionList = local_c;

  return;

}
