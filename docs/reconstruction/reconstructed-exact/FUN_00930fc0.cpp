// =============================================================================
// FUN_00930fc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00930fc0
// Address:   0x00930fc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00930fc0 @ 0x00930fc0
// Stable ID: aa_00930fc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~153 non-empty decompiler lines.
//  - Control keywords: if×17, goto×11, return×1.
//  - Notable callees: FUN_00930f40×6, CONCAT13, CONCAT21, CONCAT22, CONCAT31, FUN_0040aff0, FUN_0040b1b0, FUN_005749d0.
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

void __thiscall FUN_00930fc0(int *param_1,int param_2,uint32_t /* width from decompiler */ *param_3,char param_4,char param_5)



{

  short sVar1;

  char cVar2;

  int iVar3;

  int *piVar4;

  RACE_ID_INFERRED RVar5;

  uint32_t /* width from decompiler */ uVar6;

  void *pA;

  uint32_t /* width from decompiler */ *puVar7;

  uint8_t *puVar8;

  void *pB;

  uint8_t local_cc [20];

  float local_b8;

  float local_b4;

  float local_b0;

  uint32_t /* width from decompiler */ local_8c;

  int local_88;

  int *local_80;

  int local_68;

  int local_60;

  uint32_t /* width from decompiler */ local_5c;

  int local_54;

  int *local_50;

  int local_4c;

  int *local_48;

  int local_2c;

  char local_25;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  puStack_c = &LAB_009ac684;

  local_10 = ExceptionList;

  local_14 = &stack0xffffff28;

  local_8 = 0;

  ExceptionList = &local_10;

  puVar8 = &stack0xffffff28;

  if (param_1 == (int *)0x0) goto LAB_00931393;

  ExceptionList = &local_10;

  iVar3 = (**(code **)(*param_1 + 0x210))(0);

  if ((iVar3 != 0) &&

     (local_68 = (**(code **)(*param_1 + 0x210))(0), 0 < *(int *)(local_68 + 0x6b4))) {

    local_1c = 0xffc364eb;

    local_18 = local_1c;

    goto code_r0x0093139e;

  }

  iVar3 = *(int *)(param_2 + 0xe98);

  if (iVar3 == 0) {

    puVar7 = (uint32_t /* width from decompiler */ *)FUN_00930f40();

    local_18 = *puVar7;

    goto code_r0x0093139e;

  }

  if (param_1 != (int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3)) {

    local_48 = *(int **)(iVar3 + 0x250);

    piVar4 = local_48;

    if (local_48 != (int *)0x0) {

      piVar4 = (int *)(*(int *)(local_48[1] + 4) + 4 + (int)local_48);

    }

    if ((param_1 != piVar4) &&

       ((local_25 = *(char *)(iVar3 + 0x6b9), local_25 == '\0' ||

        (local_80 = *(int **)(*(int *)(*(int *)(*(int *)(param_2 + 0xe98) + 4) + 4) + 0xa4 +

                             *(int *)(param_2 + 0xe98)), param_1 != local_80)))) {

      if ((param_4 != '\0') ||

         (local_50 = *(int **)(*(int *)(*(int *)(*(int *)(param_2 + 0xe98) + 4) + 4) + 0xa4 +

                              *(int *)(param_2 + 0xe98)), puVar8 = local_14, param_1 != local_50)) {

        RVar5 = Object_GetRootRaceId(param_1);

        if ((0x7fffffff < RVar5) && (cVar2 = FUN_00837e80(), cVar2 == '\0')) {

          puVar7 = (uint32_t /* width from decompiler */ *)FUN_00930f40();

          local_18 = *puVar7;

          goto code_r0x0093139e;

        }

        iVar3 = (**(code **)(*param_1 + 0x210))(0);

        if ((iVar3 != 0) && (local_88 = *(int *)(*(int *)(param_2 + 0xe98) + 0xcb0), local_88 != 0))

        {

          local_60 = local_88;

          uVar6 = (**(code **)(*param_1 + 0x210))(0);

          cVar2 = FUN_005749d0(uVar6);

          puVar8 = local_14;

          if (cVar2 != '\0') goto LAB_00931393;

        }

        iVar3 = (**(code **)(*param_1 + 0x1d8))();

        if (iVar3 != 0) {

          (**(code **)(*param_1 + 0x1d8))();

          cVar2 = FUN_0040b1b0();

          if (cVar2 != '\0') {

            local_18 = 0xffebebeb;

            goto code_r0x0093139e;

          }

        }

        iVar3 = (**(code **)(*param_1 + 0x214))();

        if (iVar3 != 0) {

          pB = (void *)(*(int *)(*(int *)(*(int *)(param_2 + 0xe98) + 4) + 4) + 0x164 +

                       *(int *)(param_2 + 0xe98));

          puVar8 = local_cc;

          (**(code **)(*param_1 + 0x214))(puVar8);

          pA = (void *)FUN_0040aff0(puVar8);

          iVar3 = TFID_EqualsObjectId(pA,pB);

          if ((char)iVar3 != '\0') {

            local_18 = 0xdfcaff0b;

            goto code_r0x0093139e;

          }

        }

        cVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_2 + 0xe98) + 4) + 4) + 4 +

                                     *(int *)(param_2 + 0xe98)) + 0x298))(param_1);

        if (cVar2 == '\0') {

          puVar7 = (uint32_t /* width from decompiler */ *)FUN_00930f40();

          local_18 = *puVar7;

          goto code_r0x0093139e;

        }

        if (param_5 == '\x01') {

          puVar7 = (uint32_t /* width from decompiler */ *)FUN_00930f40();

          local_18 = *puVar7;

          goto code_r0x0093139e;

        }

        local_2c = 0;

        local_4c = (**(code **)(*param_1 + 0x214))();

        if (local_4c != 0) {

          local_54 = *(int *)(*(int *)(*(int *)(*(int *)(local_4c + 4) + 4) + 0xac + local_4c) +

                             0x3c);

          sVar1 = *(short *)(local_54 + 0x4fa);

          local_5c = CONCAT22((short)((uint)param_1 >> 0x10),sVar1);

          piVar4 = (int *)(*(int *)(*(int *)(local_4c + 4) + 4) + 4 + local_4c);

          iVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_2 + 0xe98) + 4) + 4) + 4 +

                                       *(int *)(param_2 + 0xe98)) + 0x27c))();

          local_2c = (**(code **)(*piVar4 + 0x27c))();

          local_2c = (sVar1 - iVar3) + local_2c;

          FUN_0092d580();

          local_18 = CONCAT13(0xff,(int3)CONCAT31(CONCAT21((short)(int)(local_b8 * DAT_00aaa6f8),

                                                           (char)(int)(local_b4 * DAT_00aaa6f8)),

                                                  (char)(int)(local_b0 * DAT_00aaa6f8)));

          goto code_r0x0093139e;

        }

        local_4c = 0;

        puVar8 = local_14;

      }

LAB_00931393:

      local_14 = puVar8;

      puVar7 = (uint32_t /* width from decompiler */ *)FUN_00930f40();

      local_18 = *puVar7;

      goto code_r0x0093139e;

    }

  }

  local_8c = *(uint32_t /* width from decompiler */ *)(iVar3 + 0xcb0);

  puVar7 = (uint32_t /* width from decompiler */ *)FUN_00930f40();

  local_18 = *puVar7;

code_r0x0093139e:

  *param_3 = local_18;

  ExceptionList = local_10;

  return;

}
