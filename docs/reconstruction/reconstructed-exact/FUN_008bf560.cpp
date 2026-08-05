// =============================================================================
// FUN_008bf560
// -----------------------------------------------------------------------------
// Stable ID: aa_008bf560
// Address:   0x008bf560  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008bf560 @ 0x008bf560
// Stable ID: aa_008bf560
// Embedded strings (evidence for future rename):
//   - "i_d_inv_loot_queue_sb.xml"
//   - "i_d_inv_loot_queue_2d_wnd_item_name.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~266 non-empty decompiler lines.
//  - Control keywords: if×8, do×1, while×1, return×1.
//  - Notable callees: FUN_007b5dd0×4, FUN_0079c860×2, FUN_0078f890, FUN_00792600, FUN_008bee80, FUN_008bf560.
//  - Strings: "i_d_inv_loot_queue_sb.xml"; "i_d_inv_loot_queue_2d_wnd_item_name.xml".
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

void __fastcall FUN_008bf560(int *param_1)



{

  int iVar1;

  void *pvVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ uStack_194;

  uint32_t /* width from decompiler */ *puStack_190;

  uint32_t /* width from decompiler */ uStack_18c;

  uint32_t /* width from decompiler */ uStack_188;

  uint8_t **ppuStack_184;

  int *piStack_180;

  uint32_t /* width from decompiler */ uStack_17c;

  int iStack_178;

  uint32_t /* width from decompiler */ *puStack_174;

  uint32_t /* width from decompiler */ uStack_170;

  uint32_t /* width from decompiler */ uStack_16c;

  char ***pppcStack_168;

  uint8_t *puStack_164;

  uint32_t /* width from decompiler */ uStack_160;

  uint32_t /* width from decompiler */ uStack_15c;

  uint8_t *puStack_158;

  uint32_t /* width from decompiler */ uStack_154;

  uint32_t /* width from decompiler */ uStack_150;

  char **ppcStack_14c;

  uint8_t *puStack_148;

  int iStack_144;

  uint32_t /* width from decompiler */ uStack_140;

  uint8_t *puStack_13c;

  uint32_t /* width from decompiler */ uStack_138;

  uint32_t /* width from decompiler */ uStack_134;

  uint8_t *puStack_130;

  uint32_t /* width from decompiler */ uStack_12c;

  uint32_t /* width from decompiler */ uStack_128;

  int iStack_124;

  char *pcStack_120;

  uint32_t /* width from decompiler */ uStack_d8;

  char *pcStack_d4;

  int iVar6;

  uint8_t auStack_b0 [4];

  uint8_t auStack_ac [80];

  uint32_t /* width from decompiler */ uStack_5c;

  uint32_t /* width from decompiler */ uStack_54;

  uint32_t /* width from decompiler */ uStack_4c;

  uint32_t /* width from decompiler */ uStack_40;

  uint32_t /* width from decompiler */ uStack_34;

  void *pvStack_30;

  uint32_t /* width from decompiler */ uStack_28;

  void *pvStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0xffffffff;

  puStack_10 = &LAB_009b9da1;

  pvStack_14 = ExceptionList;

  ExceptionList = &pvStack_14;

  FUN_00792600();

  iVar1 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar1;

  param_1[0x1d] = (int)(float)-iVar1;

  if (param_1[0x1c] < iVar1) {

    param_1[0x1c] = iVar1;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pcStack_d4 = (char *)0x8bf5c1;

  pvVar2 = operator_new(0x954);

  puStack_10 = (uint8_t *)0x0;

  if (pvVar2 == (void *)0x0) {

    iVar1 = 0;

  }

  else {

    iVar1 = FUN_0078f890();

  }

  puStack_10 = (uint8_t *)0xffffffff;

  param_1[0x14e] = iVar1;

  pcStack_d4 = (char *)0x8bf5fe;

  (**(code **)(*param_1 + 0xa8))();

  pcStack_d4 = "i_d_inv_loot_queue_sb.xml";

  uStack_d8 = 0x8bf60e;

  (**(code **)(*(int *)param_1[0x14e] + 0x28))();

  *(uint8_t *)(param_1[0x14e] + 0xc4) = 1;

  *(uint8_t *)(param_1[0x14e] + 0xc5) = 0;

  uStack_d8 = 0x9c41;

  (**(code **)(*(int *)param_1[0x14e] + 0x74))();

  (**(code **)(*(int *)param_1[0x14e] + 0x43c))();

  (**(code **)(*(int *)param_1[0x14e] + 0x468))();

  (**(code **)(*(int *)param_1[0x14e] + 0x454))();

  iVar1 = 0x9c49;

  piVar5 = param_1 + 0x15c;

  do {

    iVar6 = iVar1;

    pcStack_d4 = operator_new(0x4cc);

    uStack_28 = 1;

    iVar3 = 0;

    if (pcStack_d4 != (char *)0x0) {

      iVar3 = FUN_0079c860();

    }

    uStack_28 = 0xffffffff;

    piVar5[-0xc] = iVar3;

    (**(code **)(*param_1 + 0xa8))();

    (**(code **)(*(int *)piVar5[-0xc] + 0x28))();

    (**(code **)(*(int *)piVar5[-0xc] + 0x74))();

    pvVar2 = operator_new(0x4cc);

    uStack_34 = 2;

    iVar3 = 0;

    if (pvVar2 != (void *)0x0) {

      iVar3 = FUN_0079c860();

    }

    uStack_34 = 0xffffffff;

    piVar5[-9] = iVar3;

    (**(code **)(*param_1 + 0xa8))();

    (**(code **)(*(int *)piVar5[-9] + 0x28))();

    (**(code **)(*(int *)piVar5[-9] + 0x74))();

    pvVar2 = operator_new(0x488);

    uStack_40 = 3;

    if (pvVar2 == (void *)0x0) {

      iVar3 = 0;

    }

    else {

      iVar3 = FUN_007b5dd0();

    }

    uStack_40 = 0xffffffff;

    *piVar5 = iVar3;

    (**(code **)(*param_1 + 0xa8))();

    (**(code **)(*(int *)*piVar5 + 0x28))();

    (**(code **)(*(int *)*piVar5 + 0x74))();

    *(uint8_t *)(*piVar5 + 0xc4) = 1;

    *(uint8_t *)(*piVar5 + 0xc5) = 0;

    pvVar2 = operator_new(0x488);

    uStack_4c = 4;

    if (pvVar2 == (void *)0x0) {

      iVar3 = 0;

    }

    else {

      iVar3 = FUN_007b5dd0();

    }

    uStack_4c = 0xffffffff;

    piVar5[-6] = iVar3;

    (**(code **)(*param_1 + 0xa8))();

    (**(code **)(*(int *)piVar5[-6] + 0x28))();

    *(uint8_t *)(piVar5[-6] + 0xc4) = 1;

    *(uint8_t *)(piVar5[-6] + 0xc5) = 0;

    pvVar2 = operator_new(0x488);

    uStack_54 = 5;

    if (pvVar2 == (void *)0x0) {

      iVar3 = 0;

    }

    else {

      iVar3 = FUN_007b5dd0();

    }

    uStack_54 = 0xffffffff;

    piVar5[-3] = iVar3;

    (**(code **)(*param_1 + 0xa8))();

    (**(code **)(*(int *)piVar5[-3] + 0x28))();

    *(uint8_t *)(piVar5[-3] + 0xc4) = 1;

    *(uint8_t *)(piVar5[-3] + 0xc5) = 0;

    (**(code **)(*(int *)*piVar5 + 0x94))();

    pcStack_120 = (char *)0x8bf87b;

    pcStack_120 = operator_new(0x488);

    uStack_5c = 6;

    if (pcStack_120 == (char *)0x0) {

      iVar3 = 0;

    }

    else {

      iStack_124 = 0x8bf899;

      iVar3 = FUN_007b5dd0();

    }

    uStack_5c = 0xffffffff;

    piVar5[3] = iVar3;

    pcStack_120 = (char *)0x8bf8b3;

    (**(code **)(*param_1 + 0xa8))();

    pcStack_120 = "i_d_inv_loot_queue_2d_wnd_item_name.xml";

    iStack_124 = 0x8bf8c0;

    (**(code **)(*(int *)piVar5[3] + 0x28))();

    uStack_128 = 0x8bf8c9;

    iStack_124 = iVar1;

    (**(code **)(*(int *)piVar5[3] + 0x74))();

    *(uint8_t *)(piVar5[3] + 0xc4) = 1;

    *(uint8_t *)(piVar5[3] + 0xc5) = 0;

    uStack_128 = 1;

    uStack_12c = 0x8bf8ea;

    (**(code **)(*(int *)piVar5[3] + 0x1c4))();

    uStack_12c = 0;

    puStack_130 = &stack0xffffff38;

    uStack_134 = 0x8bf8fc;

    iVar3 = (**(code **)(*(int *)piVar5[-6] + 0x140))();

    uStack_134 = 0;

    uStack_138 = 1;

    puStack_13c = auStack_b0;

    iVar3 = (int)((float)*(int *)(iVar3 + 4) * (float)DAT_00d1e81c * DAT_00aaa678) *

            (iVar1 + -0x9c49);

    uStack_140 = 0x8bf939;

    (**(code **)(*(int *)piVar5[-6] + 0x120))();

    uStack_140 = 0;

    iStack_144 = 1;

    puStack_148 = &stack0xffffff0c;

    ppcStack_14c = (char **)0x8bf952;

    puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)piVar5[-6] + 0x120))();

    pcStack_120 = (char *)*puVar4;

    ppcStack_14c = &pcStack_120;

    uStack_150 = 0x8bf96c;

    (**(code **)(*(int *)piVar5[-6] + 0x110))();

    uStack_150 = 0;

    uStack_154 = 1;

    puStack_158 = auStack_ac;

    uStack_15c = 0x8bf982;

    iVar1 = (**(code **)(*(int *)*piVar5 + 0x120))();

    iVar1 = *(int *)(iVar1 + 4);

    uStack_15c = 0;

    uStack_160 = 1;

    puStack_164 = &stack0xffffff18;

    pppcStack_168 = (char ***)0x8bf99a;

    puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)*piVar5 + 0x120))();

    ppcStack_14c = (char **)*puVar4;

    pppcStack_168 = &ppcStack_14c;

    uStack_16c = 0x8bf9b3;

    puStack_148 = (uint8_t *)(iVar1 + iVar3);

    (**(code **)(*(int *)*piVar5 + 0x110))();

    uStack_16c = 0;

    uStack_170 = 1;

    puStack_174 = &uStack_d8;

    iStack_178 = 0x8bf9ca;

    iVar1 = (**(code **)(*(int *)piVar5[-9] + 0x120))();

    iVar1 = *(int *)(iVar1 + 4);

    iStack_178 = 0;

    uStack_17c = 1;

    piStack_180 = &iStack_124;

    ppuStack_184 = (uint8_t **)0x8bf9e3;

    puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)piVar5[-9] + 0x120))();

    puStack_148 = (uint8_t *)*puVar4;

    ppuStack_184 = &puStack_148;

    uStack_188 = 0x8bf9fd;

    iStack_144 = iVar1 + iVar3;

    (**(code **)(*(int *)piVar5[-9] + 0x110))();

    uStack_188 = 0;

    uStack_18c = 1;

    puStack_190 = &uStack_12c;

    uStack_194 = 0x8bfa11;

    iVar1 = (**(code **)(*(int *)piVar5[-0xc] + 0x120))();

    iVar1 = *(int *)(iVar1 + 4);

    uStack_194 = 0;

    puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)piVar5[-0xc] + 0x120))(&uStack_128,1);

    uStack_17c = *puVar4;

    iStack_178 = iVar1 + iVar3;

    (**(code **)(*(int *)piVar5[-0xc] + 0x110))(&uStack_17c);

    iVar1 = (**(code **)(*(int *)piVar5[3] + 0x120))(&uStack_128,1,0);

    iVar1 = *(int *)(iVar1 + 4);

    puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)piVar5[3] + 0x120))(&iStack_124,1,0);

    uStack_188 = *puVar4;

    ppuStack_184 = (uint8_t **)(iVar1 + iVar3);

    (**(code **)(*(int *)piVar5[3] + 0x110))(&uStack_188);

    iVar1 = (**(code **)(*(int *)piVar5[-3] + 0x120))(&iStack_124,1,0);

    iVar1 = *(int *)(iVar1 + 4);

    puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)piVar5[-3] + 0x120))(&pcStack_120,1,0);

    uStack_194 = *puVar4;

    puStack_190 = (uint32_t /* width from decompiler */ *)(iVar1 + iVar3);

    (**(code **)(*(int *)piVar5[-3] + 0x110))(&uStack_194);

    iVar1 = iVar6 + 1;

    piVar5 = piVar5 + 1;

  } while (iVar6 + -0x9c48 < 3);

  param_1[0x127] = 40000;

  FUN_008bee80();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pvStack_30;

  return;

}
