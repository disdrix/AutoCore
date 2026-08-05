// READABILITY (auto CF):
//  - Body size: ~151 non-empty decompiler lines.
//  - Control keywords: if×15, return×2, goto×2, do×1, for×1, while×1.
//  - Notable callees: CONCAT31×2, EnterCriticalSection×2, FUN_0043e510×2, LeaveCriticalSection×2, _stricmp×2, FUN_0040d9c0, FUN_0043c5f0, FUN_0043d670.
//  - Strings: "geo"; "xml"; "PRELOAD: unable to preload asset %s"; "C:\\vog\\1_code\\palantir\\palantir\\assets\\assPreloader.cpp".
//  - Return sites: 2.

// =============================================================================
// Named_assPreloader
// -----------------------------------------------------------------------------
// Stable ID: aa_00972140
// Address:   0x00972140  (autoassault.exe, image base 0x400000)
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

void Named_assPreloader(int param_1)



{

  LPCRITICAL_SECTION p_Var1;

  char cVar2;

  int *piVar3;

  uint uVar4;

  int iVar5;

  char *pcVar6;

  int iVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ uVar9;

  int iVar10;

  uint uVar11;

  char *local_60 [2];

  LPCRITICAL_SECTION p_Stack_58;

  char *pcStack_54;

  int iStack_50;

  uint8_t auStack_4c [4];

  void *pvStack_48;

  uint32_t /* width from decompiler */ uStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  uint8_t local_3c [4];

  int local_38;

  uint local_34;

  uint local_30;

  int local_2c;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  iVar5 = param_1;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b264e;

  local_c = ExceptionList;

  local_60[0] = (char *)0x0;

  ExceptionList = &local_c;

  cVar2 = FUN_0043e510();

  do {

    if (cVar2 == '\0') {

      ExceptionList = local_c;

      return;

    }

    FUN_00970fc0();

    iVar7 = *(int *)(iVar5 + 0xe0);

    piVar3 = (int *)FUN_0044a860();

    iVar10 = param_1;

    if (*piVar3 == iVar7) {

      local_38 = 0;

      local_34 = 0;

      local_30 = 0;

      local_2c = 0;

      local_4 = 0;

      FUN_0043c5f0(local_3c);

      for (uVar11 = local_30; uVar11 != local_30 + local_2c; uVar11 = uVar11 + 1) {

        uVar4 = uVar11 >> 2;

        iVar5 = uVar4 * -4;

        if (local_34 <= uVar4) {

          uVar4 = uVar4 - local_34;

        }

        iVar5 = (**(code **)(**(int **)(*(int *)(local_38 + uVar4 * 4) + (uVar11 + iVar5) * 4) + 0xc

                            ))(local_60);

        if (iVar5 != 0) {

          pcVar6 = local_60[0];

          if (local_60[0] == (char *)0x0) {

            pcVar6 = PTR_DAT_00afa2bc;

          }

          pcVar6 = strrchr(pcVar6,0x2e);

          if (pcVar6 != (char *)0x0) {

            iVar7 = _stricmp(pcVar6 + 1,"geo");

            if (iVar7 == 0) {

              uVar9 = 0;

            }

            else {

              iVar7 = _stricmp(pcVar6 + 1,"xml");

              iVar10 = param_1;

              if (iVar7 != 0) goto LAB_009722f3;

              uVar9 = 3;

            }

            pvStack_48 = (void *)0x0;

            uStack_44 = 0;

            uStack_40 = 0;

            uVar4 = uVar11 >> 2;

            iVar7 = uVar4 * -4;

            local_4 = CONCAT31(local_4._1_3_,1);

            if (local_34 <= uVar4) {

              uVar4 = uVar4 - local_34;

            }

            FUN_00971b80(auStack_4c,iVar5,uVar9,

                         *(uint32_t /* width from decompiler */ *)

                          (*(int *)(*(int *)(local_38 + uVar4 * 4) + (uVar11 + iVar7) * 4) + 4));

            FUN_00971280(param_1,auStack_4c);

            if (pvStack_48 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

              operator_delete(pvStack_48);

            }

            pvStack_48 = (void *)0x0;

            uStack_44 = 0;

            uStack_40 = 0;

            iVar10 = param_1;

          }

LAB_009722f3:

          p_Var1 = (LPCRITICAL_SECTION)(iVar10 + 0x60);

          pcStack_54 = local_60[0];

          p_Stack_58 = p_Var1;

          iStack_50 = iVar5;

          if (*(char *)(iVar10 + 0x78) != '\0') {

            EnterCriticalSection(p_Var1);

          }

          local_4._0_1_ = 2;

          FUN_0043e970(&pcStack_54);

          local_4 = (uint)local_4._1_3_ << 8;

          if (*(char *)(iVar10 + 0x78) != '\0') {

            LeaveCriticalSection(p_Var1);

          }

          puVar8 = (uint32_t /* width from decompiler */ *)FUN_0043d700();

          *puVar8 = 1;

          goto LAB_009723dd;

        }

      }

      iVar5 = FUN_0096a630(abStack_28);

      local_4._0_1_ = 3;

      if (*(uint *)(iVar5 + 0x18) < 0x10) {

        iVar5 = iVar5 + 4;

      }

      else {

        iVar5 = *(int *)(iVar5 + 4);

      }

      uVar9 = FUN_0076cec0(&param_1,"PRELOAD: unable to preload asset %s",iVar5);

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\assets\\assPreloader.cpp",0x212,2,uVar9);

      local_4 = (uint)local_4._1_3_ << 8;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_28);

      p_Var1 = (LPCRITICAL_SECTION)(iVar10 + 0x90);

      p_Stack_58 = p_Var1;

      if (*(char *)(iVar10 + 0xa8) != '\0') {

        EnterCriticalSection(p_Var1);

      }

      local_4 = CONCAT31(local_4._1_3_,4);

      FUN_0043d670(local_60);

      if (*(char *)(iVar10 + 0xa8) != '\0') {

        LeaveCriticalSection(p_Var1);

      }

LAB_009723dd:

      Sleep(0);

      local_4 = 0xffffffff;

      FUN_0040d9c0();

      iVar5 = param_1;

    }

    cVar2 = FUN_0043e510();

  } while( true );

}
