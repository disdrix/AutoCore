// READABILITY (auto CF):
//  - Body size: ~228 non-empty decompiler lines.
//  - Control keywords: if×26, goto×3, return×3, do×2, while×2, for×1.
//  - Notable callees: FUN_0043e8f0×4, EnterCriticalSection×3, FUN_0043bcc0×3, FUN_0043e7f0×3, LeaveCriticalSection×3, FUN_00745f80×2, CONCAT31, FUN_00436ef0.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\assets\\assManager.cpp".
//  - Return sites: 3.

// =============================================================================
// Named_assManager_0075de80
// -----------------------------------------------------------------------------
// Stable ID: aa_0075de80
// Address:   0x0075de80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "assManager"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_assManager_0075de80(int param_1,int param_2,float param_3)



{

  LPCRITICAL_SECTION lpCriticalSection;

  PRTL_CRITICAL_SECTION_DEBUG p_Var1;

  char cVar2;

  uint32_t /* width from decompiler */ uVar3;

  DWORD *pDVar4;

  int iVar5;

  int *piVar6;

  _LIST_ENTRY *p_Var7;

  float10 fVar8;

  PRTL_CRITICAL_SECTION_DEBUG p_Stack_94;

  PRTL_CRITICAL_SECTION_DEBUG local_90;

  uint32_t /* width from decompiler */ *local_74;

  uint local_70;

  uint8_t *local_68;

  LPCRITICAL_SECTION ap_Stack_64 [6];

  DWORD DStack_4c;

  DWORD DStack_48;

  DWORD DStack_44;

  uint8_t auStack_40 [28];

  void *local_24;

  uint32_t /* width from decompiler */ *local_20;

  int local_1c;

  void *pvStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ local_c;

  

  puStack_10 = &LAB_009b0a03;

  pvStack_14 = ExceptionList;

  auStack_40._12_4_ = (_LIST_ENTRY *)0x0;

  auStack_40._16_4_ = (PRTL_CRITICAL_SECTION_DEBUG)0x0;

  auStack_40._20_4_ = 0;

  local_24 = (void *)0x0;

  local_20 = (uint32_t /* width from decompiler */ *)0x0;

  local_1c = 0;

  local_c = 1;

  ExceptionList = &pvStack_14;

  fVar8 = (float10)FUN_0076c330();

  do {

    piVar6 = (int *)**(int **)(param_1 + 8);

    local_70 = 0;

    if (piVar6 != *(int **)(param_1 + 8)) {

      do {

        local_74 = (uint32_t /* width from decompiler */ *)piVar6[3];

        if ((param_2 == 2) && (local_74 != (uint32_t /* width from decompiler */ *)0x0)) {

          if (param_3 <= (float)fVar8 - (float)local_74[7]) {

            if (*(char *)(local_74 + 0xe) != '\0') {

              local_90 = (PRTL_CRITICAL_SECTION_DEBUG)0x75df26;

              EnterCriticalSection((LPCRITICAL_SECTION)(local_74 + 8));

            }

            local_68 = (uint8_t *)local_74[4];

            if (*(char *)(local_74 + 0xe) != '\0') {

              local_90 = (PRTL_CRITICAL_SECTION_DEBUG)0x75df3a;

              LeaveCriticalSection((LPCRITICAL_SECTION)(local_74 + 8));

            }

            if (local_68 == (uint8_t *)0x0) {

              if (*(int *)(param_1 + 0x6c) != 0) {

                local_90 = (PRTL_CRITICAL_SECTION_DEBUG)piVar6[2];

                local_68 = (uint8_t *)&local_90;

                p_Stack_94 = (PRTL_CRITICAL_SECTION_DEBUG)0x75df67;

                FUN_0043e8f0();

                local_90 = (PRTL_CRITICAL_SECTION_DEBUG)0x75df76;

                FUN_0043e7f0();

              }

              p_Stack_94 = (PRTL_CRITICAL_SECTION_DEBUG)&local_68;

              local_90 = (PRTL_CRITICAL_SECTION_DEBUG)0xa9e8f0;

              uVar3 = FUN_0076cec0();

              vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\assets\\assManager.cpp",0x1bb,1,

                             uVar3);

              FUN_00745f80();

              local_90 = (PRTL_CRITICAL_SECTION_DEBUG)0x75dfbc;

              (**(code **)*local_74)();

              local_74 = (uint32_t /* width from decompiler */ *)0x0;

              piVar6[3] = 0;

            }

            goto LAB_0075dfc7;

          }

LAB_0075e1e8:

          piVar6 = (int *)*piVar6;

        }

        else {

LAB_0075dfc7:

          cVar2 = '\x01';

          if (piVar6[4] == 0) {

            cVar2 = '\0';

            if ((local_74 == (uint32_t /* width from decompiler */ *)0x0) && (cVar2 = '\0', *(int *)(param_1 + 0x6c) != 0)) {

              local_90 = (PRTL_CRITICAL_SECTION_DEBUG)(piVar6 + 2);

              p_Stack_94 = (PRTL_CRITICAL_SECTION_DEBUG)0x75dfeb;

              cVar2 = FUN_00971a20();

            }

          }

          if (param_2 == 1) {

            iVar5 = *(int *)(param_1 + 0x6c);

            if (iVar5 != 0) {

              local_68 = (uint8_t *)&local_90;

              local_90 = (PRTL_CRITICAL_SECTION_DEBUG)piVar6[2];

              p_Stack_94 = (PRTL_CRITICAL_SECTION_DEBUG)0x75e019;

              local_68 = (uint8_t *)FUN_0043e8f0();

              lpCriticalSection = (LPCRITICAL_SECTION)(iVar5 + 0xc0);

              ap_Stack_64[0] = lpCriticalSection;

              if (*(char *)(iVar5 + 0xd8) != '\0') {

                local_90 = (PRTL_CRITICAL_SECTION_DEBUG)0x75e03a;

                EnterCriticalSection(lpCriticalSection);

              }

              local_c._0_1_ = 2;

              local_90 = (PRTL_CRITICAL_SECTION_DEBUG)0x75e04b;

              FUN_0043e9e0();

              local_c = CONCAT31(local_c._1_3_,1);

              if (*(char *)(iVar5 + 0xd8) != '\0') {

                local_90 = (PRTL_CRITICAL_SECTION_DEBUG)0x75e05d;

                LeaveCriticalSection(lpCriticalSection);

              }

            }

            piVar6 = (int *)*piVar6;

            local_90 = (PRTL_CRITICAL_SECTION_DEBUG)ap_Stack_64;

            p_Stack_94 = (PRTL_CRITICAL_SECTION_DEBUG)0x75e070;

            FUN_0043bcc0();

            uVar3 = auStack_40._16_4_;

            if (((_LIST_ENTRY *)auStack_40._12_4_ == (_LIST_ENTRY *)0x0) ||

               ((uint)((int)(auStack_40._20_4_ - auStack_40._12_4_) >> 2) <=

                (uint)((int)(auStack_40._16_4_ - auStack_40._12_4_) >> 2))) {

              local_90 = (PRTL_CRITICAL_SECTION_DEBUG)0x1;

              p_Stack_94 = (PRTL_CRITICAL_SECTION_DEBUG)auStack_40._16_4_;

              FUN_0043bfb0();

            }

            else {

              local_90 = (PRTL_CRITICAL_SECTION_DEBUG)0x75e0a6;

              FUN_00436ef0();

              auStack_40._16_4_ = uVar3 + 4;

            }

            if ((local_24 == (void *)0x0) ||

               ((uint)(local_1c - (int)local_24 >> 2) <= (uint)((int)local_20 - (int)local_24 >> 2))

               ) {

              local_90 = (PRTL_CRITICAL_SECTION_DEBUG)0x75e108;

              FUN_00456960();

            }

            else {

              *local_20 = local_74;

              local_20 = local_20 + 1;

            }

          }

          else {

            if (cVar2 != '\0') goto LAB_0075e1e8;

            if (local_74 == (uint32_t /* width from decompiler */ *)0x0) {

              if (*(int *)(param_1 + 0x6c) != 0) {

                ap_Stack_64[0] = (LPCRITICAL_SECTION)&local_90;

                local_90 = (PRTL_CRITICAL_SECTION_DEBUG)piVar6[2];

                p_Stack_94 = (PRTL_CRITICAL_SECTION_DEBUG)0x75e136;

                FUN_0043e8f0();

                local_90 = (PRTL_CRITICAL_SECTION_DEBUG)0x75e145;

                FUN_0043e7f0();

              }

              piVar6 = (int *)*piVar6;

              local_90 = (PRTL_CRITICAL_SECTION_DEBUG)ap_Stack_64;

              p_Stack_94 = (PRTL_CRITICAL_SECTION_DEBUG)0x75e158;

              FUN_0043bcc0();

            }

            else {

              if (*(char *)(local_74 + 0xe) != '\0') {

                local_90 = (PRTL_CRITICAL_SECTION_DEBUG)0x75e16d;

                EnterCriticalSection((LPCRITICAL_SECTION)(local_74 + 8));

              }

              local_68 = (uint8_t *)local_74[4];

              if (*(char *)(local_74 + 0xe) != '\0') {

                local_90 = (PRTL_CRITICAL_SECTION_DEBUG)0x75e181;

                LeaveCriticalSection((LPCRITICAL_SECTION)(local_74 + 8));

              }

              if (local_68 != (uint8_t *)0x0) goto LAB_0075e1e8;

              if (*(int *)(param_1 + 0x6c) != 0) {

                local_90 = (PRTL_CRITICAL_SECTION_DEBUG)piVar6[2];

                ap_Stack_64[0] = (LPCRITICAL_SECTION)&local_90;

                p_Stack_94 = (PRTL_CRITICAL_SECTION_DEBUG)0x75e1aa;

                FUN_0043e8f0();

                local_90 = (PRTL_CRITICAL_SECTION_DEBUG)0x75e1b9;

                FUN_0043e7f0();

              }

              FUN_00745f80();

              local_90 = (PRTL_CRITICAL_SECTION_DEBUG)0x75e1ce;

              (**(code **)*local_74)();

              piVar6 = (int *)*piVar6;

              local_90 = (PRTL_CRITICAL_SECTION_DEBUG)ap_Stack_64;

              p_Stack_94 = (PRTL_CRITICAL_SECTION_DEBUG)0x75e1e1;

              FUN_0043bcc0();

              local_70 = local_70 + 1;

            }

          }

        }

      } while (piVar6 != *(uint32_t /* width from decompiler */ **)(param_1 + 8));

    }

    if ((param_2 == 2) || ((int)local_70 < 1)) {

      iVar5 = (int)local_24 - auStack_40._12_4_;

      p_Var7 = (_LIST_ENTRY *)auStack_40._12_4_;

      for (local_70 = 0;

          ((_LIST_ENTRY *)auStack_40._12_4_ != (_LIST_ENTRY *)0x0 &&

          (local_70 < (uint)((int)(auStack_40._16_4_ - auStack_40._12_4_) >> 2)));

          local_70 = local_70 + 1) {

        p_Var1 = *(PRTL_CRITICAL_SECTION_DEBUG *)(iVar5 + (int)p_Var7);

        local_90 = (PRTL_CRITICAL_SECTION_DEBUG)0x75e248;

        FUN_0044e8c0();

        if (local_68 == *(uint8_t **)(param_1 + 8)) {

          ap_Stack_64[0] = (LPCRITICAL_SECTION)&p_Stack_94;

          p_Stack_94 = (PRTL_CRITICAL_SECTION_DEBUG)p_Var7->Flink;

          local_90 = p_Var1;

          pDVar4 = (DWORD *)FUN_0043c6f0();

          DStack_4c = *pDVar4;

          DStack_48 = pDVar4[1];

          DStack_44 = pDVar4[2];

          local_90 = (PRTL_CRITICAL_SECTION_DEBUG)auStack_40;

          p_Stack_94 = (PRTL_CRITICAL_SECTION_DEBUG)0x75e28f;

          FUN_0043ba40();

        }

        p_Var7 = (_LIST_ENTRY *)&p_Var7->Blink;

      }

      if (local_24 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        local_90 = (PRTL_CRITICAL_SECTION_DEBUG)&UNK_0075e2ab;

        operator_delete(local_24);

      }

      if ((_LIST_ENTRY *)auStack_40._12_4_ != (_LIST_ENTRY *)0x0) {

                    /* WARNING: Subroutine does not return */

        local_90 = (PRTL_CRITICAL_SECTION_DEBUG)&UNK_0075e2b8;

        operator_delete((void *)auStack_40._12_4_);

      }

      ExceptionList = pvStack_14;

      return;

    }

  } while( true );

}
