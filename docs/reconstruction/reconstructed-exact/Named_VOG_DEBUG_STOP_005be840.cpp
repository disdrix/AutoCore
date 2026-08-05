// READABILITY (auto CF):
//  - Body size: ~113 non-empty decompiler lines.
//  - Control keywords: if×10, return×4, for×2.
//  - Notable callees: FUN_007464e0×2, FUN_00414c20, FUN_004ac660, FUN_005be840, FUN_00746520, FUN_007478c0, FUN_0074b8f0, FUN_007a4480.
//  - Strings: "VOG_DEBUG_STOP".
//  - Return sites: 4.

// =============================================================================
// Named_VOG_DEBUG_STOP_005be840
// -----------------------------------------------------------------------------
// Stable ID: aa_005be840
// Address:   0x005be840  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_VOG_DEBUG_STOP_005be840(int *param_1,int param_2,int param_3,int param_4)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  int *piVar5;

  int iVar6;

  int *piVar7;

  int unaff_retaddr;

  float fStack_28;

  void *pvStack_24;

  float fStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  void *pvStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a6c60;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  param_1[0x34] = param_2;

  param_1[0x35] = param_3;

  if ((*(int *)(param_4 + 900) <= param_2) || (*(int *)(param_4 + 0x388) <= param_3)) {

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  piVar5 = param_1 + 0x36;

  for (iVar6 = 0x6000; iVar6 != 0; iVar6 = iVar6 + -1) {

    *piVar5 = 0;

    piVar5 = piVar5 + 1;

  }

  FUN_004ac660(param_1 + 0x36,param_2,param_3);

  iVar3 = (**(code **)(**(int **)(param_4 + 0x390) + 0xc))();

  iVar6 = *param_1;

  param_1[0x19] = iVar3;

  uVar4 = (**(code **)(**(int **)(param_4 + 0x390) + 100))();

  (**(code **)(iVar6 + 0x34))(uVar4);

  piVar5 = *(int **)(param_4 + 0x394);

  piVar7 = (int *)*piVar5;

  if ((piVar7 != (int *)0x0) && (piVar7[1] = piVar7[1] + 1, piVar7[1] == 1)) {

    (**(code **)(*piVar7 + 4))();

  }

  piVar2 = (int *)param_1[8];

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  param_1[8] = (int)piVar7;

  *(char *)(param_1 + 9) = (char)piVar5[1];

  *(uint8_t *)((int)param_1 + 0x25) = *(uint8_t *)((int)piVar5 + 5);

  *(uint8_t *)((int)param_1 + 0x26) = *(uint8_t *)((int)piVar5 + 6);

  FUN_0096fdf0();

  param_1[0x2f] = param_1[0x2f] | 1;

  pvStack_24 = (void *)0x0;

  fStack_20 = 0.0;

  uStack_1c = 0;

  puStack_8 = (uint8_t *)0x0;

  uStack_18 = 0;

  uStack_14 = 0;

  FUN_007478c0(0x4d2);

  puStack_8 = (uint8_t *)0x1;

  iVar6 = FUN_00414c20(0x600,&fStack_28,0x20,0);

  puStack_8 = (uint8_t *)0xffffffff;

  uStack_18 = 0;

  uStack_14 = 0;

  if (pvStack_24 == (void *)0x0) {

    if (-1 < iVar6) {

      iVar6 = param_1[5];

      if ((*(int *)(iVar6 + 0x10) != 0) &&

         (piVar5 = (int *)FUN_00746520(*(uint32_t /* width from decompiler */ *)(iVar6 + 0x14),*(uint32_t /* width from decompiler */ *)(iVar6 + 0x18),0

                                      ), piVar5 != (int *)0x0)) {

        piVar7 = param_1 + 0x36;

        for (iVar6 = 0x6000; iVar6 != 0; iVar6 = iVar6 + -1) {

          *piVar5 = *piVar7;

          piVar7 = piVar7 + 1;

          piVar5 = piVar5 + 1;

        }

        if (*(int *)(param_1[5] + 0x10) != 0) {

          FUN_007464e0();

        }

        param_1[0x2a] = 0x200;

        param_1[0x2b] = 4;

        (**(code **)(*param_1 + 0x20))(*(uint32_t /* width from decompiler */ *)(param_4 + 0x390));

        param_1[0x2f] = param_1[0x2f] & 0xfffffffe;

        fStack_20 = *(float *)(param_4 + 0x18) * DAT_00a0f6d0;

        fStack_28 = (float)unaff_retaddr * fStack_20;

        pvStack_24 = (void *)0x0;

        fStack_20 = (float)param_2 * fStack_20;

        if ((*(byte *)(param_1 + 0x2f) & 1) != 0) {

          (**(code **)(*param_1 + 0x5c))();

        }

        FUN_0074b8f0(&fStack_28,&stack0xffffffcc);

        ExceptionList = pvStack_10;

        return;

      }

      if (*(int *)(param_1[5] + 0x10) != 0) {

        FUN_007464e0();

        ExceptionList = pvStack_10;

        return;

      }

    }

    ExceptionList = pvStack_10;

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(pvStack_24);

}
