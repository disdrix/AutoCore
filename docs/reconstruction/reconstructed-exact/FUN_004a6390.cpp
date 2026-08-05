// =============================================================================
// FUN_004a6390
// -----------------------------------------------------------------------------
// Stable ID: aa_004a6390
// Address:   0x004a6390  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004a6390 @ 0x004a6390
// Stable ID: aa_004a6390
// Embedded strings (evidence for future rename):
//   - "LoadMasterFromXML"
//   - "NDSpecialFX"
//   - "VOG_DEBUG_STOP"
//   - "Read duplicate event entry (%d) for FX file: %s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~170 non-empty decompiler lines.
//  - Control keywords: if×11, while×7, do×5, return×4, for×4, goto×1.
//  - Notable callees: FUN_004b99c0×2, FUN_0076cef0×2, FUN_00798990×2, FUN_007a4480×2, FUN_004a4fa0, FUN_004a6390, FUN_004a6a40, FUN_004a7580.
//  - Strings: "LoadMasterFromXML"; "NDSpecialFX"; "VOG_DEBUG_STOP"; "Read duplicate event entry (%d) for FX file: %s".
//  - Return sites: 4.

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

uint32_t /* width from decompiler */ __thiscall FUN_004a6390(int *param_1,char *param_2)



{

  char cVar1;

  int *piVar2;

  int *piVar3;

  char *pcVar4;

  int *piVar5;

  void *pvVar6;

  int iVar7;

  uint uVar8;

  char *pcVar9;

  char *pcVar10;

  uint32_t /* width from decompiler */ local_13c;

  uint32_t /* width from decompiler */ local_138;

  void *local_134;

  uint8_t local_130 [4];

  char local_12c;

  char cStack_129;

  char local_128 [2];

  uint32_t /* width from decompiler */ uStack_126;

  char cStack_122;

  char cStack_121;

  char local_120 [268];

  void *local_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ local_c;

  

  local_c = 0xffffffff;

  puStack_10 = &LAB_009a1159;

  local_14 = ExceptionList;

  ExceptionList = &local_14;

  FUN_0076cf00("LoadMasterFromXML");

  local_c = 0;

  if (DAT_00b035fc != 0) {

    *(uint8_t *)((int)param_1 + 6) = 1;

    piVar5 = (int *)**(int **)(*param_1 + 4);

    if (piVar5 != *(int **)(*param_1 + 4)) {

      do {

        FUN_004b85d0();

        pvVar6 = (void *)piVar5[4];

        if (pvVar6 != (void *)0x0) {

          FUN_004b99c0();

                    /* WARNING: Subroutine does not return */

          operator_delete(pvVar6);

        }

        if (*(char *)((int)piVar5 + 0x15) == '\0') {

          piVar2 = (int *)piVar5[2];

          if (*(char *)((int)piVar2 + 0x15) == '\0') {

            cVar1 = *(char *)(*piVar2 + 0x15);

            piVar5 = piVar2;

            piVar2 = (int *)*piVar2;

            while (cVar1 == '\0') {

              cVar1 = *(char *)(*piVar2 + 0x15);

              piVar5 = piVar2;

              piVar2 = (int *)*piVar2;

            }

          }

          else {

            cVar1 = *(char *)(piVar5[1] + 0x15);

            piVar3 = (int *)piVar5[1];

            piVar2 = piVar5;

            while ((piVar5 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar5[2]))) {

              cVar1 = *(char *)(piVar5[1] + 0x15);

              piVar3 = (int *)piVar5[1];

              piVar2 = piVar5;

            }

          }

        }

      } while (piVar5 != *(int **)(*param_1 + 4));

    }

    iVar7 = *param_1;

    FUN_004a6a40(*(uint32_t /* width from decompiler */ *)(*(int *)(iVar7 + 4) + 4));

    *(int *)(*(int *)(iVar7 + 4) + 4) = *(int *)(iVar7 + 4);

    *(uint32_t /* width from decompiler */ *)(iVar7 + 8) = 0;

    *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(iVar7 + 4) = *(uint32_t /* width from decompiler */ *)(iVar7 + 4);

    *(int *)(*(int *)(iVar7 + 4) + 8) = *(int *)(iVar7 + 4);

    pcVar4 = local_128 + 2;

    for (iVar7 = 0x42; iVar7 != 0; iVar7 = iVar7 + -1) {

      pcVar4[0] = '\0';

      pcVar4[1] = '\0';

      pcVar4[2] = '\0';

      pcVar4[3] = '\0';

      pcVar4 = pcVar4 + 4;

    }

    pcVar4[0] = '\0';

    pcVar4[1] = '\0';

    uStack_126._2_1_ = s____scripts__00a96040[4];

    uStack_126._3_1_ = s____scripts__00a96040[5];

    cStack_122 = s____scripts__00a96040[6];

    cStack_121 = s____scripts__00a96040[7];

    local_120[0] = s____scripts__00a96040[8];

    local_120[1] = s____scripts__00a96040[9];

    local_120[2] = s____scripts__00a96040[10];

    local_120[3] = s____scripts__00a96040[0xb];

    local_128[0] = s____scripts__00a96040[0];

    local_128[1] = s____scripts__00a96040[1];

    uStack_126._0_1_ = s____scripts__00a96040[2];

    uStack_126._1_1_ = s____scripts__00a96040[3];

    pcVar4 = param_2;

    do {

      cVar1 = *pcVar4;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

    pcVar10 = &cStack_129;

    do {

      pcVar9 = pcVar10 + 1;

      pcVar10 = pcVar10 + 1;

    } while (*pcVar9 != '\0');

    pcVar9 = param_2;

    for (uVar8 = (uint)((int)pcVar4 - (int)param_2) >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar10 = *(uint32_t /* width from decompiler */ *)pcVar9;

      pcVar9 = pcVar9 + 4;

      pcVar10 = pcVar10 + 4;

    }

    for (uVar8 = (int)pcVar4 - (int)param_2 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {

      *pcVar10 = *pcVar9;

      pcVar9 = pcVar9 + 1;

      pcVar10 = pcVar10 + 1;

    }

    pcVar4 = &cStack_129;

    do {

      pcVar10 = pcVar4;

      pcVar4 = pcVar10 + 1;

    } while (pcVar10[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar10 + 1) = DAT_009ca184;

    *(uint32_t /* width from decompiler */ *)(pcVar10 + 5) = DAT_009ca188;

    pcVar10[9] = DAT_009ca18c;

    iVar7 = NDXml_OpenTaggedDocument(local_128,"NDSpecialFX");

    if (iVar7 == 0) {

      iVar7 = 0;

      if (0 < *(int *)(DAT_00b035fc + 0xc)) {

        do {

          piVar5 = (int *)FUN_00799900(iVar7);

          if (piVar5 == (int *)0x0) {

            FUN_007a4480(0,"VOG_DEBUG_STOP");

            FUN_00798990();

            goto LAB_004a6640;

          }

          pvVar6 = (void *)FUN_004a4fa0(piVar5,&local_13c,param_1 + 1,param_2);

          if (pvVar6 != (void *)0x0) {

            if (*(int *)((int)pvVar6 + 0x58) != -1) {

              *(uint8_t *)((int)param_1 + 5) = 1;

            }

            *(uint8_t *)((int)pvVar6 + 10) = 1;

            local_138 = local_13c;

            local_134 = pvVar6;

            FUN_004a7580(local_130,&local_138);

            if (local_12c == '\0') {

              FUN_007a4480(0,"Read duplicate event entry (%d) for FX file: %s",local_13c,param_2);

              FUN_004b99c0();

                    /* WARNING: Subroutine does not return */

              operator_delete(pvVar6);

            }

          }

          (**(code **)(*piVar5 + 8))(piVar5);

          iVar7 = iVar7 + 1;

        } while (iVar7 < *(int *)(DAT_00b035fc + 0xc));

      }

      FUN_00798990();

      local_c = 0xffffffff;

      FUN_0076cef0();

      ExceptionList = local_14;

      return 1;

    }

  }

LAB_004a6640:

  local_c = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = local_14;

  return 0;

}
