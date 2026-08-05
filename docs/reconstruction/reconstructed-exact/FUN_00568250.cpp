// =============================================================================
// FUN_00568250
// -----------------------------------------------------------------------------
// Stable ID: aa_00568250
// Address:   0x00568250  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00568250 @ 0x00568250
// Stable ID: aa_00568250
// Embedded strings (evidence for future rename):
//   - "%S %s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~90 non-empty decompiler lines.
//  - Control keywords: if×9, return×1.
//  - Notable callees: CONCAT22×3, FUN_004c2ef0, FUN_004c2f10, FUN_004c3700, FUN_004c4070, FUN_004c41c0, FUN_00516720, FUN_00568250.
//  - Strings: "%S %s".
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

void FUN_00568250(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  short sVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  void *pvVar4;

  int iVar5;

  uint16_t extraout_var;

  uint16_t extraout_var_00;

  uint16_t extraout_var_01;

  int *piVar6;

  

  if (param_2 != 0) {

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x128) = *param_1;

    if (99 < *(short *)((int)param_1 + 0x12)) {

      *(uint8_t *)(param_2 + 0x30b) = 1;

    }

    iVar5 = *(int *)(param_2 + 0x250);

    piVar6 = (int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2);

    if (iVar5 != 0) {

      piVar6 = (int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5);

    }

    sVar1 = SUB42((float)param_1[1] - g_flOne,0);

    (**(code **)(*piVar6 + 0x29c))();

    if (*(int *)(piVar6[0x2a] + 0x38) != 0xe) {

      iVar5 = *piVar6;

      iVar2 = (**(code **)(iVar5 + 0x244))();

      (**(code **)(iVar5 + 0x248))((int)((float)iVar2 * (float)param_1[1]));

    }

    iVar5 = *piVar6;

    uVar3 = (**(code **)(iVar5 + 0x244))();

    (**(code **)(iVar5 + 0x240))(uVar3);

    if ((0 < *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xac + param_2) + 0x3c

                              ) + 0x3bc)) &&

       (iVar5 = *(int *)(*(int *)(param_2 + 4) + 4),

       pvVar4 = (void *)(**(code **)(*(int *)(iVar5 + param_2 + 4) + 0x234))

                                  (*(uint32_t /* width from decompiler */ *)

                                    (*(int *)(*(int *)(iVar5 + 0xac + param_2) + 0x3c) + 0x3bc)),

       pvVar4 != (void *)0x0)) {

      Skill_SetRankAndReevaluate

                (pvVar4,(void *)CONCAT22(extraout_var,

                                         *(short *)((int)pvVar4 + 0x5f6) + *(short *)(param_1 + 4)),

                 sVar1);

    }

    if ((0 < *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xac + param_2) + 0x3c

                              ) + 0x3c0)) &&

       (iVar5 = *(int *)(*(int *)(param_2 + 4) + 4),

       pvVar4 = (void *)(**(code **)(*(int *)(iVar5 + param_2 + 4) + 0x234))

                                  (*(uint32_t /* width from decompiler */ *)

                                    (*(int *)(*(int *)(iVar5 + 0xac + param_2) + 0x3c) + 0x3c0)),

       pvVar4 != (void *)0x0)) {

      Skill_SetRankAndReevaluate

                (pvVar4,(void *)CONCAT22(extraout_var_00,

                                         *(short *)((int)pvVar4 + 0x5f6) + *(short *)(param_1 + 4)),

                 sVar1);

    }

    if ((0 < *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xac + param_2) + 0x3c

                              ) + 0x3c4)) &&

       (iVar5 = *(int *)(*(int *)(param_2 + 4) + 4),

       pvVar4 = (void *)(**(code **)(*(int *)(iVar5 + param_2 + 4) + 0x234))

                                  (*(uint32_t /* width from decompiler */ *)

                                    (*(int *)(*(int *)(iVar5 + 0xac + param_2) + 0x3c) + 0x3c4)),

       pvVar4 != (void *)0x0)) {

      Skill_SetRankAndReevaluate

                (pvVar4,(void *)CONCAT22(extraout_var_01,

                                         *(short *)((int)pvVar4 + 0x5f6) + *(short *)(param_1 + 4)),

                 sVar1);

    }

    sVar1 = FUN_004c4070();

    FUN_004c2ef0(sVar1 + *(short *)(param_1 + 3));

    sVar1 = FUN_004c41c0();

    FUN_004c2f10(sVar1 + *(short *)((int)param_1 + 0xe));

    *(uint8_t *)(param_2 + 0x100) = *(uint8_t *)(param_1 + 5);

    iVar5 = *(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2);

    if (*(char *)(param_2 + 0x30b) == '\0') {

      iVar5 = (**(code **)(iVar5 + 0x27c))();

      iVar5 = iVar5 + *(short *)((int)param_1 + 0x12);

    }

    else {

      iVar5 = (**(code **)(iVar5 + 0x27c))();

      iVar5 = iVar5 + -100 + (int)*(short *)((int)param_1 + 0x12);

    }

    FUN_004c3700(iVar5);

    if (*(char *)(param_2 + 0x30b) != '\0') {

      uVar3 = (**(code **)(*piVar6 + 0x15c))();

      _snprintf(&stack0xffffff94,100,"%S %s",(int)param_1 + 0x16,uVar3);

      FUN_00516720(&stack0xffffff94);

    }

  }

  return;

}
