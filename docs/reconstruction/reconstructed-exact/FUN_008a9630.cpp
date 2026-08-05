// =============================================================================
// FUN_008a9630
// -----------------------------------------------------------------------------
// Stable ID: aa_008a9630
// Address:   0x008a9630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008a9630 @ 0x008a9630
// Stable ID: aa_008a9630
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~129 non-empty decompiler lines.
//  - Control keywords: if×12, while×2, do×1, return×1.
//  - Notable callees: FUN_004113b0×2, CONCAT22, FUN_00410d60, FUN_00411500, FUN_004294f0, FUN_00755ab0, FUN_00756c90, FUN_007b5dd0.
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

void __thiscall FUN_008a9630(int *param_1,char param_2)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  int *piVar4;

  void *pvVar5;

  uint32_t /* width from decompiler */ uVar6;

  int iVar7;

  int unaff_ESI;

  ushort in_FPUControlWord;

  double dVar8;

  int iStack_4c;

  uint32_t /* width from decompiler */ uStack_48;

  uint8_t auStack_44 [4];

  int aiStack_40 [2];

  uint uStack_38;

  int iStack_34;

  uint8_t local_30 [16];

  uint32_t /* width from decompiler */ uStack_20;

  void *local_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0xffffffff;

  puStack_10 = &LAB_009b39ba;

  local_14 = ExceptionList;

  if (((param_1[0x19c] != 0) && (param_1[0x1a0] != 0)) && (param_1[0x1a1] != 0)) {

    iVar7 = 0;

    ExceptionList = &local_14;

    if (((param_1[0x1a2] != 0) &&

        (ExceptionList = &local_14, iVar1 = (**(code **)(*(int *)param_1[0x1a2] + 0x1dc))(),

        iVar1 != 0)) && (((int *)param_1[0x1a2])[0xa4] != 0)) {

      (**(code **)(*(int *)param_1[0x1a2] + 0x1dc))();

      piVar2 = (int *)FUN_00755ab0();

      iVar7 = *piVar2;

      (**(code **)(*(int *)param_1[0x1a2] + 0x120))(local_30,1);

    }

    aiStack_40[0] = (**(code **)(*(int *)param_1[0x1a1] + 0x140))(local_30);

    (**(code **)(*(int *)param_1[0x19c] + 0x140))(&uStack_48,1);

    piVar2 = (int *)(**(code **)(*(int *)param_1[0x1a0] + 0x140))(aiStack_40,1);

    dVar8 = ceil((double)((float)aiStack_40[0] / ((float)*piVar2 * (float)param_1[0x14c])));

    uStack_48 = CONCAT22(uStack_48._2_2_,in_FPUControlWord);

    uStack_38 = (uint)(in_FPUControlWord | 0xc00);

    aiStack_40[0] = (int)ROUND(dVar8);

    if (param_1[0x1a2] != 0) {

      if (aiStack_40[0] == 0) {

        if (param_1[0x1a1] == 0) {

          iVar1 = 0;

        }

        else {

          piVar2 = (int *)(**(code **)(*(int *)param_1[0x1a1] + 0x140))(local_30);

          iVar1 = *piVar2;

        }

        if (param_1[0x19c] == 0) {

          iVar3 = 0;

        }

        else {

          piVar2 = (int *)(**(code **)(*(int *)param_1[0x19c] + 0x140))(&uStack_38);

          iVar3 = *piVar2;

        }

        iStack_34 = param_1[400];

        uStack_38 = ((((int)((float)iVar3 * (float)param_1[0x14b]) +

                      (int)((float)iVar1 * (float)param_1[0x14d])) - param_1[399]) - iVar7) / 2 + -3

                    + param_1[399];

        (**(code **)(*(int *)param_1[0x1a2] + 0x110))();

      }

      else {

        (**(code **)(*(int *)param_1[0x1a2] + 0x114))();

      }

      if (param_1[0x1a5] != 0) {

        iVar7 = (**(code **)(*(int *)param_1[0x1a5] + 0x120))(local_30,1);

        iVar7 = *(int *)(iVar7 + 4);

        (**(code **)(*(int *)param_1[0x1a2] + 0x120))(&stack0xffffffac,1,0);

        iStack_4c = iVar7;

        (**(code **)(*(int *)param_1[0x1a5] + 0x110))(&stack0xffffffb0);

        (**(code **)(*(int *)param_1[0x1a5] + 0x140))(&iStack_4c,1);

        (**(code **)(*(int *)param_1[0x1a5] + 300))(&stack0xffffffa4);

      }

    }

    if ((param_2 != '\0') || (param_1[0x19a] != aiStack_40[0])) {

      FUN_004294f0();

      uStack_38 = 0;

      iVar7 = FUN_004113b0(param_1 + 0x191);

      while (iVar7 == 0) {

        (**(code **)(*param_1 + 0xbc))();

        iVar7 = FUN_004113b0(param_1 + 0x191);

      }

      if ((char)param_1[0x19b] != '\0') {

        *(uint8_t *)(param_1 + 0x19b) = 0;

        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x192));

      }

      FUN_00410d60();

      piVar2 = (int *)(**(code **)(*(int *)param_1[0x19c] + 0x140))(local_30);

      piVar4 = (int *)(**(code **)(*(int *)param_1[0x19c] + 0x120))(aiStack_40,1,0);

      iStack_4c = (int)((float)*piVar2 * (float)param_1[0x14b]) + *piVar4;

      if (0 < unaff_ESI) {

        do {

          pvVar5 = operator_new(0x488);

          piVar2 = (int *)0x0;

          uStack_20 = 0;

          if (pvVar5 != (void *)0x0) {

            piVar2 = (int *)FUN_007b5dd0(pvVar5,0);

          }

          uStack_20 = 0xffffffff;

          (**(code **)(*param_1 + 0xa8))(piVar2);

          (**(code **)(*piVar2 + 0x38))(param_1[0x1a0]);

          FUN_00756c90();

          iVar7 = (**(code **)(*piVar2 + 0x120))(auStack_44,1,0);

          iVar7 = *(int *)(iVar7 + 4);

          (**(code **)(*piVar2 + 0x118))(&stack0xffffffa8);

          iVar1 = *piVar2;

          uVar6 = (**(code **)(*param_1 + 0xd0))();

          (**(code **)(iVar1 + 0xcc))(uVar6);

          FUN_00411500(param_1 + 0x191,piVar2);

          piVar2 = (int *)(**(code **)(*piVar2 + 0x140))(&stack0xffffffb0,1);

          iStack_4c = iStack_4c + (int)((float)*piVar2 * (float)param_1[0x14c]);

        } while (iVar7 != 1);

      }

      if (param_1[0x1a1] != 0) {

        iVar7 = (**(code **)(*(int *)param_1[0x1a1] + 0x120))(&iStack_34,1,0);

        iStack_4c = *(int *)(iVar7 + 4);

        (**(code **)(*(int *)param_1[0x1a1] + 0x118))(&stack0xffffffb0);

      }

      (**(code **)(*param_1 + 0x34c))();

    }

  }

  ExceptionList = local_14;

  return;

}
