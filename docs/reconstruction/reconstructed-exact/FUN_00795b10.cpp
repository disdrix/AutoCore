// =============================================================================
// FUN_00795b10
// -----------------------------------------------------------------------------
// Stable ID: aa_00795b10
// Address:   0x00795b10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00795b10 @ 0x00795b10
// Stable ID: aa_00795b10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~135 non-empty decompiler lines.
//  - Control keywords: if×10, while×5, do×3, return×2.
//  - Notable callees: FUN_0041c7e0×5, FUN_00423f40×4, FUN_00424060×2, FUN_00424260×2, FUN_004294f0×2, DeleteCriticalSection, FUN_00424380, FUN_00427d20.
//  - Return sites: 2.

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

/* WARNING: Removing unreachable block (ram,0x00795d92) */



void FUN_00795b10(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,int param_4,

                 undefined **param_5,PRTL_CRITICAL_SECTION_DEBUG param_6,LONG param_7,LONG param_8)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  uint32_t /* width from decompiler */ *puVar4;

  void *pvVar5;

  char *pcVar6;

  int *unaff_EBX;

  uint uVar7;

  char *pcVar8;

  uint32_t /* width from decompiler */ *puVar9;

  int *unaff_retaddr;

  undefined **ppuStack_58;

  PRTL_CRITICAL_SECTION_DEBUG p_Stack_54;

  LONG LStack_50;

  LONG LStack_4c;

  void *pvStack_2c;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b3201;

  pvStack_c = ExceptionList;

  LStack_4c = 0x795b32;

  ExceptionList = &pvStack_c;

  FUN_007944a0();

  uVar7 = unaff_EBX[0x124];

  unaff_EBX[0x124] = uVar7 + 1;

  LStack_4c = param_8;

  LStack_50 = param_7;

  p_Stack_54 = param_6;

  ppuStack_58 = param_5;

  (**(code **)(*unaff_EBX + 0x25c))(param_1,param_2,param_3);

  FUN_00427d20(unaff_EBX[0x83] + -1,&stack0x00000000);

  FUN_00424260();

  if ((int)uVar7 < param_4) {

    if (uVar7 == 0) {

      FUN_00424380(unaff_EBX + 0x7a,unaff_retaddr);

    }

    else {

      ppuStack_58 = &PTR_FUN_00a964ac;

      InitializeCriticalSection((LPCRITICAL_SECTION)&p_Stack_54);

      ppuStack_58 = &PTR_FUN_00a964b8;

      FUN_0041c7e0(&ppuStack_58,unaff_retaddr);

      uStack_4 = 0;

      FUN_004294f0();

      iVar2 = FUN_00423f40(&stack0x00000000);

      while (iVar2 == 0) {

        if (unaff_retaddr != (int *)0x0) {

          if (uVar7 == 0) {

            FUN_0041c7e0(&ppuStack_58,unaff_retaddr);

          }

          else if (((*unaff_retaddr == 1) &&

                   (pcVar8 = (char *)unaff_retaddr[1], pcVar8 != (char *)0x0)) && (*pcVar8 != '\0'))

          {

            pcVar3 = pcVar8;

            do {

              cVar1 = *pcVar3;

              pcVar3 = pcVar3 + 1;

            } while (cVar1 != '\0');

            if (uVar7 < (uint)((int)pcVar3 - (int)(pcVar8 + 1))) {

              puVar4 = operator_new(8);

              puVar9 = (uint32_t /* width from decompiler */ *)0x0;

              if (puVar4 != (uint32_t /* width from decompiler */ *)0x0) {

                *puVar4 = 0;

                puVar4[1] = 0;

                puVar9 = puVar4;

              }

              pcVar8 = pcVar8 + uVar7;

              *puVar9 = 1;

              pcVar3 = pcVar8;

              do {

                cVar1 = *pcVar3;

                pcVar3 = pcVar3 + 1;

              } while (cVar1 != '\0');

              pvVar5 = operator_new__((uint)(pcVar3 + (1 - (int)(pcVar8 + 1))));

              puVar9[1] = pvVar5;

              pcVar6 = pcVar8;

              do {

                cVar1 = *pcVar6;

                pcVar6[(int)pvVar5 - (int)pcVar8] = cVar1;

                pcVar6 = pcVar6 + 1;

              } while (cVar1 != '\0');

              FUN_0041c7e0(&ppuStack_58,puVar9);

              unaff_EBX[0x4a] = (int)(pcVar3 + (unaff_EBX[0x4a] - (int)(pcVar8 + 1)));

              *pcVar8 = '\0';

              uVar7 = 0;

            }

            else {

              uVar7 = uVar7 - ((int)pcVar3 - (int)(pcVar8 + 1));

            }

          }

          else if ((*unaff_retaddr == 0xc) && (unaff_retaddr[1] != 0)) {

            uVar7 = uVar7 - 1;

          }

        }

        iVar2 = FUN_00423f40(&stack0x00000000);

      }

      if ((char)unaff_EBX[0x84] != '\0') {

        *(uint8_t *)(unaff_EBX + 0x84) = 0;

        LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_EBX + 0x7b));

      }

      uStack_4 = 0;

      FUN_004294f0();

      iVar2 = FUN_00423f40(&stack0x00000000);

      while (iVar2 == 0) {

        FUN_00424260();

        FUN_0041c7e0(unaff_EBX + 0x7a,unaff_retaddr);

        iVar2 = FUN_00423f40(&stack0x00000000);

      }

      FUN_00427f10();

      ppuStack_58 = &PTR_FUN_00a964b8;

      FUN_00424060();

      ppuStack_58 = &PTR_FUN_00a964ac;

      FUN_00424060();

      DeleteCriticalSection((LPCRITICAL_SECTION)&p_Stack_54);

    }

  }

  else {

    FUN_0041c7e0(unaff_EBX + 0x7a,unaff_retaddr);

  }

  FUN_007950e0(unaff_EBX,unaff_EBX[0x124]);

  pvVar5 = (void *)unaff_EBX[0xa3];

  if (pvVar5 == (void *)0x0) {

    unaff_EBX[0xa3] = 0;

    ExceptionList = pvStack_2c;

    return;

  }

  FUN_00797d70(pvVar5);

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar5);

}
