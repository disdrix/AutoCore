// =============================================================================
// FUN_008ecf40
// -----------------------------------------------------------------------------
// Stable ID: aa_008ecf40
// Address:   0x008ecf40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008ecf40 @ 0x008ecf40
// Stable ID: aa_008ecf40
// Embedded strings (evidence for future rename):
//   - "Highway\n"
//   - "Town\n"
//   - "%d%% %s"
//   - "\n(%d %s)"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~242 non-empty decompiler lines.
//  - Control keywords: if×19, return×6, goto×2.
//  - Notable callees: FUN_007a6de0×7, FUN_008eca80×3, CNDHash_LookupByKey×2, FUN_00402d50×2, FUN_007a69d0×2, free×2, sprintf×2, FUN_0053fff0.
//  - Strings: "Highway\n"; "Town\n"; "%d%% %s"; "\n(%d %s)".
//  - Return sites: 6.

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

void __fastcall FUN_008ecf40(int *param_1)



{

  int *piVar1;

  char cVar2;

  void *pvVar3;

  int iVar4;

  float *pfVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ uVar7;

  int iVar8;

  uint32_t /* width from decompiler */ uStack_1ac;

  int *piStack_1a8;

  uint8_t *puStack_1a4;

  uint8_t *puStack_1a0;

  uint8_t *puStack_19c;

  uint8_t *puStack_198;

  int iStack_194;

  int iStack_190;

  uint8_t **ppuStack_18c;

  float fStack_188;

  char **ppcStack_184;

  uint8_t *puStack_164;

  uint8_t *puStack_160;

  int iStack_15c;

  char *pcStack_150;

  uint key;

  uint8_t *puStack_140;

  uint8_t auStack_134 [16];

  uint8_t **ppuStack_124;

  uint8_t *puStack_120;

  uint8_t auStack_11c [260];

  uint32_t /* width from decompiler */ uStack_18;

  void *pvStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  puStack_140 = &stack0xfffffffc;

  uStack_c = 0xffffffff;

  puStack_10 = &LAB_009b0430;

  pvStack_14 = ExceptionList;

  ExceptionList = &pvStack_14;

  cVar2 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar2 == '\0') {

    ExceptionList = pvStack_14;

    return;

  }

  if (param_1[0x140] == 0) {

    ExceptionList = pvStack_14;

    return;

  }

  if (param_1[0x141] == 0) {

    ExceptionList = pvStack_14;

    return;

  }

  if (param_1[0x142] == 0) {

    ExceptionList = pvStack_14;

    return;

  }

  FUN_007a69d0();

  pcStack_150 = (char *)0x1;

  (**(code **)(*(int *)param_1[0x141] + 0x1d8))();

  (**(code **)(*(int *)param_1[0x141] + 0x34c))();

  iStack_15c = 1;

  puStack_160 = (uint8_t *)0x0;

  puStack_164 = (uint8_t *)0x8ecfdb;

  (**(code **)(*(int *)param_1[0x142] + 0x1d8))();

  puStack_164 = (uint8_t *)0x8ecfe9;

  (**(code **)(*(int *)param_1[0x142] + 0x34c))();

  key = param_1[0x13f];

  if (key == 0xffffffff) {

    ExceptionList = pvStack_14;

    return;

  }

  pcStack_150 = (char *)0x8ed004;

  pvVar3 = (void *)FUN_00541a80();

  pcStack_150 = (char *)0x8ed00b;

  pvVar3 = CNDHash_LookupByKey(pvVar3,key);

  if (pvVar3 != (void *)0x0) {

    pcStack_150 = (char *)0x8ed025;

    FUN_00402d50();

    uStack_c = 0;

    iVar4 = *(int *)param_1[0x141];

    pcStack_150 = (char *)0x1;

    iStack_15c = 0x8ed048;

    FUN_007a6de0();

    (**(code **)(iVar4 + 0x1d8))();

    uStack_18 = 0xffffffff;

    if (ppuStack_124 != &puStack_120) {

      iStack_15c = 0x8ed073;

      free(ppuStack_124);

    }

    if ((*(int *)((int)pvVar3 + 0xc) == -1) &&

       ((*(int *)((int)pvVar3 + 0x18) == 0 || (DAT_00d1b6d8 == 0)))) {

      iStack_15c = 1;

      puStack_160 = (uint8_t *)0x8ed1a4;

      (**(code **)(*(int *)param_1[0x141] + 0x15c))();

    }

    else {

      iVar4 = *(int *)param_1[0x141];

      FUN_00930ea0();

      iStack_15c = 1;

      puStack_160 = (uint8_t *)0x8ed0ca;

      (**(code **)(iVar4 + 0x15c))();

    }

    if ((DAT_00d1b6d8 != 0) && (5 < *(int *)(DAT_00d1b6d8 + 0x6b4))) {

      pcStack_150 = (char *)0x8ed0f7;

      (**(code **)(*(int *)param_1[0x142] + 0x250))();

      pcStack_150 = (char *)((int)pvVar3 + 0x1c);

      FUN_00402d50();

      puStack_10 = (uint8_t *)0x1;

      iVar4 = *(int *)param_1[0x142];

      pcStack_150 = (char *)0xffffffff;

      pcStack_150 = (char *)FUN_007a6de0();

      (**(code **)(iVar4 + 0x250))();

      pvStack_14 = (void *)0xffffffff;

      if (puStack_120 != auStack_11c) {

        free(puStack_120);

      }

      (**(code **)(*(int *)param_1[0x142] + 0x250))();

    }

    if (*(int *)((int)pvVar3 + 0x18) == 0) {

      if (*(int *)((int)pvVar3 + 0x10) == 0) goto LAB_008ed1d2;

      iVar4 = *(int *)param_1[0x142];

      pcStack_150 = "Highway\n";

    }

    else {

      iVar4 = *(int *)param_1[0x142];

      pcStack_150 = "Town\n";

    }

    FUN_007a6de0();

    pcStack_150 = (char *)0x8ed1d2;

    (**(code **)(iVar4 + 0x250))();

  }

LAB_008ed1d2:

  iVar8 = 0;

  pcStack_150 = (char *)0x1;

  (**(code **)(*(int *)param_1[0x140] + 0x120))();

  iStack_15c = 1;

  puStack_160 = auStack_134;

  puStack_164 = (uint8_t *)0x8ed206;

  (**(code **)(*(int *)param_1[0x141] + 0x120))();

  puStack_164 = &stack0xfffffeb8;

  (**(code **)(*(int *)param_1[0x141] + 0x110))();

  iVar4 = (**(code **)(*(int *)param_1[0x141] + 0x134))();

  pcStack_150 = (char *)((float)DAT_00d1e81c * *(float *)(iVar4 + 4) * DAT_00aaa678);

  pfVar5 = (float *)(**(code **)(*(int *)param_1[0x141] + 0x134))();

  iStack_15c = (int)((float)DAT_00d1e818 * *pfVar5 * DAT_00aaa67c);

  (**(code **)(*(int *)param_1[0x141] + 300))();

  (**(code **)(*(int *)param_1[0x141] + 0x13c))();

  pvVar3 = CNDHash_LookupByKey(*(void **)(DAT_00d1b6d8 + 0x534),param_1[0x13f]);

  if (pvVar3 == (void *)0x0) {

    iVar4 = *(int *)param_1[0x142];

    FUN_007a69d0();

  }

  else {

    cVar2 = *(char *)((int)pvVar3 + 4);

    if (cVar2 == '\0') {

      puStack_160 = (uint8_t *)0xff999999;

      (**(code **)(*(int *)param_1[0x141] + 0x15c))();

      iVar4 = *(int *)param_1[0x142];

    }

    else {

      if (cVar2 != '\x01') {

        if (cVar2 == '\x02') {

          FUN_0053fff0();

          iVar4 = FUN_008eca80();

          if ((DAT_00d1b6d8 != 0) && (FUN_008eca80(), DAT_00d1b6d8 != 0)) {

            iVar8 = FUN_008eca80();

          }

          if (iVar4 == 0) {

            puStack_160 = (uint8_t *)0x64;

          }

          else {

            puStack_160 = (uint8_t *)((iVar8 * 100) / iVar4);

          }

          FUN_007a6de0();

          ppcStack_184 = (char **)0x8ed41d;

          sprintf((char *)&puStack_140,"%d%% %s");

          (**(code **)(*(int *)param_1[0x142] + 0x250))();

          if ((iVar4 != 0) && (iVar8 != iVar4)) {

            FUN_007a6de0();

            ppcStack_184 = (char **)0x8ed46b;

            sprintf((char *)&puStack_140,"\n(%d %s)");

            (**(code **)(*(int *)param_1[0x142] + 0x250))();

          }

        }

        goto LAB_008ed481;

      }

      iVar4 = *(int *)param_1[0x142];

    }

  }

  FUN_007a6de0();

  (**(code **)(iVar4 + 0x250))();

LAB_008ed481:

  iVar4 = *(int *)param_1[0x142];

  FUN_007a6de0();

  (**(code **)(iVar4 + 0x224))();

  piVar1 = (int *)param_1[0x141];

  ppcStack_184 = &pcStack_150;

  fStack_188 = 1.3116964e-38;

  (**(code **)(*piVar1 + 0x120))();

  fStack_188 = 1.4013e-45;

  ppuStack_18c = &puStack_164;

  iStack_190 = 0x8ed4d5;

  (**(code **)(*piVar1 + 0x140))();

  iStack_190 = 0;

  iStack_194 = 1;

  puStack_198 = &stack0xfffffe84;

  puStack_19c = (uint8_t *)0x8ed4f6;

  (**(code **)(*(int *)param_1[0x142] + 0x120))();

  puStack_19c = &stack0xfffffe80;

  puStack_1a0 = (uint8_t *)0x8ed513;

  (**(code **)(*(int *)param_1[0x142] + 0x110))();

  puStack_1a0 = &stack0xfffffe8c;

  puStack_1a4 = (uint8_t *)0x8ed526;

  iVar4 = (**(code **)(*(int *)param_1[0x142] + 0x134))();

  puStack_1a4 = &stack0xfffffe80;

  fStack_188 = (float)DAT_00d1e81c * *(float *)(iVar4 + 4) * DAT_00aaa678;

  piStack_1a8 = (int *)0x8ed558;

  pfVar5 = (float *)(**(code **)(*(int *)param_1[0x142] + 0x134))();

  iStack_190 = (int)(float)ppuStack_18c;

  iStack_194 = (int)((float)DAT_00d1e818 * *pfVar5 * DAT_00aaa67c);

  piStack_1a8 = &iStack_194;

  uStack_1ac = 0x8ed595;

  (**(code **)(*(int *)param_1[0x142] + 300))();

  uStack_1ac = 0x8ed5a3;

  (**(code **)(*(int *)param_1[0x142] + 0x13c))();

  piVar1 = (int *)param_1[0x142];

  uStack_1ac = 0;

  iVar8 = (**(code **)(*piVar1 + 0x120))(&stack0xfffffe80,1);

  iVar4 = (**(code **)(*piVar1 + 0x140))(&iStack_194,1);

  iVar4 = *(int *)(iVar4 + 4);

  iVar8 = *(int *)(iVar8 + 4);

  puVar6 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x140] + 0x140))(&uStack_1ac,1);

  uStack_1ac = *puVar6;

  piStack_1a8 = (int *)(iVar8 + 2 + iVar4);

  (**(code **)(*(int *)param_1[0x140] + 300))(&uStack_1ac);

  iVar4 = *param_1;

  uVar7 = (**(code **)(*(int *)param_1[0x140] + 0x140))(&puStack_1a0,1);

  (**(code **)(iVar4 + 0x130))(uVar7);

  ExceptionList = pvStack_14;

  return;

}
