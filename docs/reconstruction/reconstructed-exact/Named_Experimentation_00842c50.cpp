// READABILITY (auto CF):
//  - Body size: ~398 non-empty decompiler lines.
//  - Control keywords: if×13, goto×4, return×3, switch×3, for×2.
//  - Notable callees: FUN_007a6de0×3, sprintf×2, FUN_007a69d0, FUN_00842c50, WARNING, one.
//  - Strings: "Experimentation"; "Reverse Engineering"; "Memorization"; "Tinkering".
//  - Return sites: 3.

// =============================================================================
// Named_Experimentation_00842c50
// -----------------------------------------------------------------------------
// Stable ID: aa_00842c50
// Address:   0x00842c50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Experimentation"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING (jumptable): Unable to track spacebase fully for stack */



void __fastcall Named_Experimentation_00842c50(int *param_1)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  float *pfVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int **ppiVar8;

  int *piVar9;

  uint uVar10;

  uint32_t /* width from decompiler */ uStack_1fc;

  uint32_t /* width from decompiler */ *puStack_1f8;

  int iStack_1f4;

  uint32_t /* width from decompiler */ uStack_1f0;

  uint32_t /* width from decompiler */ **ppuStack_1ec;

  uint32_t /* width from decompiler */ uStack_1e8;

  uint32_t /* width from decompiler */ *puStack_1e4;

  uint32_t /* width from decompiler */ uStack_1e0;

  uint32_t /* width from decompiler */ uStack_1dc;

  uint8_t *puStack_1d8;

  uint32_t /* width from decompiler */ *puStack_1d4;

  uint32_t /* width from decompiler */ uStack_1d0;

  uint32_t /* width from decompiler */ **ppuStack_1cc;

  uint32_t /* width from decompiler */ uStack_1b8;

  int *piStack_1b4;

  uint32_t /* width from decompiler */ *puStack_1b0;

  uint32_t /* width from decompiler */ uStack_1ac;

  uint32_t /* width from decompiler */ uStack_1a8;

  uint32_t /* width from decompiler */ *puStack_1a4;

  uint32_t /* width from decompiler */ uStack_1a0;

  uint *puStack_19c;

  uint32_t /* width from decompiler */ uStack_198;

  uint32_t /* width from decompiler */ uStack_194;

  uint32_t /* width from decompiler */ uStack_190;

  uint32_t /* width from decompiler */ uStack_18c;

  int iStack_188;

  uint32_t /* width from decompiler */ uStack_184;

  uint32_t /* width from decompiler */ uStack_180;

  uint auStack_170 [2];

  int **ppiStack_168;

  int *piStack_164;

  uint32_t /* width from decompiler */ uStack_160;

  uint8_t ***pppuStack_15c;

  uint32_t /* width from decompiler */ uStack_158;

  uint32_t /* width from decompiler */ uStack_154;

  float *pfStack_150;

  int aiStack_14c [3];

  char *pcStack_140;

  int *piStack_13c;

  uint32_t /* width from decompiler */ *puStack_138;

  uint8_t **ppuStack_134;

  uint8_t **ppuStack_130;

  uint32_t /* width from decompiler */ uStack_12c;

  uint32_t /* width from decompiler */ *puStack_128;

  float fStack_124;

  int iStack_120;

  uint8_t **ppuStack_11c;

  int iStack_118;

  uint32_t /* width from decompiler */ uStack_114;

  uint32_t /* width from decompiler */ uStack_110;

  uint32_t /* width from decompiler */ uStack_10c;

  uint8_t *puStack_108;

  char *pcStack_104;

  uint8_t *puStack_100;

  uint8_t **ppuStack_fc;

  uint8_t *puStack_f8;

  uint32_t /* width from decompiler */ uStack_f4;

  uint8_t *puStack_e8;

  uint8_t local_e0 [24];

  uint32_t /* width from decompiler */ uStack_c8;

  uint32_t /* width from decompiler */ uStack_c4;

  int local_b8;

  uint32_t /* width from decompiler */ local_b0;

  uint8_t local_88;

  

  puStack_e8 = &stack0xfffffffc;

  if (DAT_00d1b6d8 == 0) {

    return;

  }

  if (param_1[0x147] == 0) {

    return;

  }

  uStack_f4 = 0x842c81;

  local_b0 = FUN_007a69d0();

  local_88 = 0;

  local_b8 = (int)*(short *)(DAT_00d1b6d8 + 0x580);

  uVar10 = 0;

  switch(param_1[0x144]) {

  case 0:

    uVar10 = (uint)*(byte *)(DAT_00d1b6d8 + 0x599);

    break;

  case 1:

    uVar10 = (uint)*(byte *)(DAT_00d1b6d8 + 0x598);

    break;

  case 2:

    uVar10 = (uint)*(byte *)(DAT_00d1b6d8 + 0x59a);

    break;

  case 3:

    uVar10 = (uint)*(byte *)(DAT_00d1b6d8 + 0x59b);

  }

  uStack_f4 = 1;

  puStack_f8 = local_e0;

  ppuStack_fc = (uint8_t **)0x842ce8;

  puVar2 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x147] + 0x140))();

  uStack_c8 = *puVar2;

  uStack_c4 = puVar2[1];

  switch(param_1[0x144]) {

  case 0:

    ppuStack_fc = (uint8_t **)0x1;

    puStack_100 = (uint8_t *)0x1;

    pcStack_104 = "Experimentation";

    puStack_108 = (uint8_t *)0x842d1e;

    (**(code **)(*(int *)param_1[0x147] + 0x1d8))();

    break;

  case 1:

    pcStack_104 = "Reverse Engineering";

    goto LAB_00842d4d;

  case 2:

    ppuStack_fc = (uint8_t **)0x1;

    puStack_100 = (uint8_t *)0x1;

    pcStack_104 = "Memorization";

    puStack_108 = (uint8_t *)0x842d42;

    (**(code **)(*(int *)param_1[0x147] + 0x1d8))();

    break;

  case 3:

    pcStack_104 = "Tinkering";

LAB_00842d4d:

    ppuStack_fc = (uint8_t **)0x1;

    puStack_100 = (uint8_t *)0x1;

    puStack_108 = (uint8_t *)0x842d5b;

    (**(code **)(*(int *)param_1[0x147] + 0x1d8))();

  }

  ppuStack_fc = &puStack_e8;

  puStack_100 = (uint8_t *)0x842d6e;

  iVar3 = (**(code **)(*(int *)param_1[0x147] + 0x134))();

  puStack_e8 = (uint8_t *)(int)((float)DAT_00d1e81c * *(float *)(iVar3 + 4) * DAT_00aaa678);

  puStack_100 = &stack0xffffff14;

  pcStack_104 = (char *)0x842dba;

  (**(code **)(*(int *)param_1[0x147] + 300))();

  pcStack_104 = (char *)0x842dc8;

  (**(code **)(*(int *)param_1[0x147] + 0x13c))();

  pcStack_104 = (char *)0x1;

  puStack_108 = &stack0xffffff10;

  uStack_10c = 0x842ddd;

  (**(code **)(*(int *)param_1[0x147] + 0x140))();

  if (uVar10 == 0) {

    uStack_10c = 0xffbbbbbb;

    uStack_110 = 1;

    uStack_114 = 0x842e04;

    (**(code **)(*(int *)param_1[0x147] + 0x160))();

  }

  else {

    uStack_10c = 0xffffffff;

    uStack_110 = 1;

    uStack_114 = 0x842df3;

    (**(code **)(*(int *)param_1[0x147] + 0x160))();

  }

  uStack_114 = 0;

  iStack_118 = 1;

  ppuStack_11c = &puStack_100;

  iStack_120 = 0x842e1b;

  puVar2 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x14a] + 0x120))();

  uStack_f4 = *puVar2;

  piVar9 = (int *)param_1[0x147];

  iStack_120 = 0;

  fStack_124 = 1.4013e-45;

  puStack_128 = &uStack_10c;

  uStack_12c = 0x842e41;

  uStack_110 = (**(code **)(*piVar9 + 0x120))();

  uStack_12c = 1;

  ppuStack_130 = &puStack_108;

  ppuStack_134 = (uint8_t **)0x842e56;

  iVar3 = (**(code **)(*piVar9 + 0x140))();

  pcStack_104 = (char *)(*(int *)(iStack_118 + 4) + *(int *)(iVar3 + 4) + param_1[0x143]);

  ppuStack_134 = &puStack_108;

  puStack_138 = (uint32_t /* width from decompiler */ *)0x842e7d;

  (**(code **)(*(int *)param_1[0x14a] + 0x118))();

  switch(param_1[0x144]) {

  case 0:

    puStack_138 = (uint32_t /* width from decompiler */ *)0x1;

    piStack_13c = (int *)0x1;

    pcStack_140 = 

    "Allows you to add enhancements to items during crafting.  When you go to a crafting station and select a broken item to craft, having skill in experimentation will allow you to add additional commodities to attempt to create extra enhancements on the item.  The higher your Experimentation skill, the more slots will become available and the higher chance of success you will have.\n\nNote: Adding additional commodities when crafting will reduce your overall chance at successfully crafting the item.  A failed attempt to craft an item will destroy the broken item you were using."

    ;

    aiStack_14c[2] = 0x842ea6;

    (**(code **)(*(int *)param_1[0x14a] + 0x1d8))();

    break;

  case 1:

    pcStack_140 = 

    "Allows you to convert regular items into broken items which can then be used for crafting and experimentation.\n\nTo use this ability, click on the Reverse Engineer Mode button at the bottom of the Research Window and then click on an item in your inventory.  Certain items cannot be reverse engineered.  Failing on an attempt will destroy the item, so exercise caution!"

    ;

    goto LAB_00842ed5;

  case 2:

    puStack_138 = (uint32_t /* width from decompiler */ *)0x1;

    piStack_13c = (int *)0x1;

    pcStack_140 = 

    "Affects your chance to permanently memorize a crafted item.  Every time an item is successfully crafted, you have a chance to memorize the broken item.  You can then craft with that memorized item as though it were a broken item in your inventory, except that it doesn\'t disappear afterward.  Click the Memory tab at the bottom of the Research Window to view your currently memorized items.\n\nNote: You can only have a limited number of items memorized at a time, so you will be prompted to replace one (or cancel) if you memorize an item when you have already reached the limit."

    ;

    aiStack_14c[2] = 0x842eca;

    (**(code **)(*(int *)param_1[0x14a] + 0x1d8))();

    break;

  case 3:

    pcStack_140 = 

    "Affects your ability to open up locked gadget slots on items.  Gadgets are items that can add various improvements/modifications to equippable items when added to them.  A gadget can only be added to an item if that item has an Open Gadget Slot.  Many items are found with Locked Gadget Slots.  To open a Locked Gadget Slot, you will first need a Tinkering Kit.  Right-click on the Tinkering Kit and then left-click on the item whose slot you wish to open.\n\nNote: If you fail to tinker an item, it will only destroy the tinkering kit.  Having a higher Tinkering skill will improve your chance of successfully tinkering, but the level of the tinkering kit and the item being tinkered also factor into the situation."

    ;

LAB_00842ed5:

    puStack_138 = (uint32_t /* width from decompiler */ *)0x1;

    piStack_13c = (int *)0x1;

    aiStack_14c[2] = 0x842ee3;

    (**(code **)(*(int *)param_1[0x14a] + 0x1d8))();

  }

  puStack_138 = &uStack_114;

  piStack_13c = (int *)0x842ef6;

  pfVar4 = (float *)(**(code **)(*(int *)param_1[0x14a] + 0x134))();

  puStack_128 = (uint32_t /* width from decompiler */ *)((float)DAT_00d1e818 * *pfVar4 * DAT_00aaa67c);

  fStack_124 = (float)DAT_00d1e81c * pfVar4[1] * DAT_00aaa678;

  iStack_120 = (int)(float)puStack_128;

  ppuStack_11c = (uint8_t **)(int)fStack_124;

  piStack_13c = &iStack_120;

  pcStack_140 = (char *)0x842f62;

  (**(code **)(*(int *)param_1[0x14a] + 300))();

  pcStack_140 = (char *)0x842f70;

  (**(code **)(*(int *)param_1[0x14a] + 0x13c))();

  if (uVar10 == 0) {

    pcStack_140 = (char *)0xffbbbbbb;

    aiStack_14c[2] = 1;

    aiStack_14c[1] = 0x842f9a;

    (**(code **)(*(int *)param_1[0x14a] + 0x160))();

  }

  else {

    pcStack_140 = (char *)0xffcccce0;

    aiStack_14c[2] = 1;

    aiStack_14c[1] = 0x842f89;

    (**(code **)(*(int *)param_1[0x14a] + 0x160))();

  }

  aiStack_14c[1] = 0;

  aiStack_14c[0] = 1;

  pfStack_150 = &fStack_124;

  uStack_154 = 0x842fb1;

  puStack_128 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x148] + 0x120))();

  puStack_128 = (uint32_t /* width from decompiler */ *)*puStack_128;

  piVar9 = (int *)param_1[0x14a];

  uStack_154 = 0;

  uStack_158 = 1;

  pppuStack_15c = &ppuStack_130;

  uStack_160 = 0x842fd0;

  aiStack_14c[2] = (**(code **)(*piVar9 + 0x120))();

  uStack_160 = 1;

  piStack_164 = aiStack_14c;

  ppiStack_168 = (int **)0x842fe5;

  iVar3 = (**(code **)(*piVar9 + 0x140))();

  puStack_138 = (uint32_t /* width from decompiler */ *)(*(int *)(aiStack_14c[0] + 4) + *(int *)(iVar3 + 4) + param_1[0x143]);

  ppiStack_168 = &piStack_13c;

  auStack_170[1] = 0x84300c;

  (**(code **)(*(int *)param_1[0x148] + 0x118))();

  auStack_170[1] = 10;

  auStack_170[0] = uVar10;

  FUN_007a6de0();

  uStack_180 = 0x843030;

  sprintf((char *)&puStack_100,"%s: %d/%d");

  auStack_170[1] = 1;

  auStack_170[0] = 1;

  (**(code **)(*(int *)param_1[0x148] + 0x1d8))();

  piVar9 = (int *)param_1[0x148];

  if (uVar10 != 0) {

    if (10 < uVar10) {

      uStack_180 = 0x843068;

      (**(code **)(*piVar9 + 0x160))();

      goto LAB_00843090;

    }

    if (uVar10 != 10) {

      uStack_180 = 0x84307f;

      (**(code **)(*piVar9 + 0x160))();

      goto LAB_00843090;

    }

  }

  uStack_180 = 0x843090;

  (**(code **)(*piVar9 + 0x160))();

LAB_00843090:

  uStack_180 = 1;

  uStack_184 = 0x8430a0;

  (**(code **)(*(int *)param_1[0x148] + 0xcc))();

  uStack_184 = 1;

  iStack_188 = 1;

  uStack_18c = 0;

  uStack_190 = 0x8430b4;

  (**(code **)(*(int *)param_1[0x149] + 0x1d8))();

  uStack_190 = 1;

  uStack_194 = 0x8430c4;

  (**(code **)(*(int *)param_1[0x149] + 0xcc))();

  uStack_194 = 0;

  uStack_198 = 1;

  puStack_19c = auStack_170;

  uStack_1a0 = 0x8430db;

  (**(code **)(*(int *)param_1[0x148] + 0x120))();

  uStack_1a0 = 1;

  puStack_1a4 = &uStack_18c;

  uStack_1a8 = 0x8430f2;

  (**(code **)(*(int *)param_1[0x148] + 0x140))();

  uStack_1a8 = 0;

  uStack_1ac = 1;

  puStack_1b0 = &uStack_184;

  piStack_1b4 = (int *)0x843117;

  iVar3 = (**(code **)(*(int *)param_1[0x148] + 0x120))();

  uStack_184 = *(uint32_t /* width from decompiler */ *)(iVar3 + 4);

  piStack_1b4 = &iStack_188;

  uStack_1b8 = 0x843131;

  (**(code **)(*(int *)param_1[0x149] + 0x118))();

  if (uVar10 < 10) {

    uStack_1b8 = 0xffffffff;

    uStack_1b8 = FUN_007a6de0();

    FUN_007a6de0();

    ppuStack_1cc = (uint32_t /* width from decompiler */ **)0x843166;

    sprintf((char *)aiStack_14c,"%s: %d %s");

    uStack_1b8 = 1;

    (**(code **)(*(int *)param_1[0x149] + 0x1d8))();

    if (iStack_188 < 1) {

      ppuStack_1cc = (uint32_t /* width from decompiler */ **)0x8431ad;

      (**(code **)(*(int *)param_1[0x149] + 0x160))();

    }

    else {

      ppuStack_1cc = (uint32_t /* width from decompiler */ **)0x84319c;

      (**(code **)(*(int *)param_1[0x149] + 0x160))();

    }

  }

  uStack_1b8 = 0x8431b7;

  (**(code **)(*param_1 + 0x448))();

  piVar9 = (int *)param_1[0x14c];

  uStack_1b8 = 1;

  iVar3 = (**(code **)(*(int *)param_1[0x14b] + 0x140))();

  iVar5 = (**(code **)(*piVar9 + 0x140))();

  if (*(int *)(iVar5 + 4) < *(int *)(iVar3 + 4)) {

    ppuStack_1cc = &puStack_1a4;

    uStack_1d0 = 0x843202;

    (**(code **)(*(int *)param_1[0x14b] + 0x140))();

    uStack_1d0 = 1;

    puStack_1d4 = &uStack_194;

    puStack_1d8 = (uint8_t *)0x84321a;

    (**(code **)(*(int *)param_1[0x14c] + 0x140))();

    piVar9 = (int *)param_1[0x14c];

  }

  else {

    ppuStack_1cc = &puStack_1a4;

    uStack_1d0 = 0x84323b;

    (**(code **)(*(int *)param_1[0x14c] + 0x140))();

    uStack_1d0 = 1;

    puStack_1d4 = &uStack_194;

    puStack_1d8 = (uint8_t *)0x843253;

    (**(code **)(*(int *)param_1[0x14b] + 0x140))();

    piVar9 = (int *)param_1[0x14b];

  }

  puStack_1d8 = &stack0xfffffe3c;

  uStack_1dc = 0x84326d;

  (**(code **)(*piVar9 + 8))();

  piVar9 = (int *)param_1[0x14c];

  piVar1 = (int *)param_1[0x14b];

  uStack_1dc = 0;

  uStack_1e0 = 1;

  puStack_1e4 = &uStack_1b8;

  uStack_1e8 = 0x84328e;

  uStack_1ac = (**(code **)(*piVar9 + 0x120))();

  uStack_1e8 = 1;

  ppuStack_1ec = &puStack_1d4;

  uStack_1f0 = 0x8432a3;

  iVar5 = (**(code **)(*piVar9 + 0x140))();

  iVar3 = piStack_1b4[1];

  iVar5 = *(int *)(iVar5 + 4);

  uStack_1f0 = 0;

  iStack_1f4 = 1;

  puStack_1f8 = &uStack_1ac;

  uStack_1fc = 0x8432c0;

  iVar6 = (**(code **)(*piVar1 + 0x120))();

  uStack_1fc = 1;

  iVar7 = (**(code **)(*piVar1 + 0x140))(&uStack_1e0);

  if (iVar3 + iVar5 < *(int *)(iVar6 + 4) + *(int *)(iVar7 + 4)) {

    piVar9 = (int *)param_1[0x14b];

    iVar3 = (**(code **)(*piVar9 + 0x120))(&puStack_1b0);

    ppiVar8 = &piStack_1b4;

  }

  else {

    piVar9 = (int *)param_1[0x14c];

    iVar3 = (**(code **)(*piVar9 + 0x120))(&uStack_1a0,1,0);

    ppiVar8 = (int **)&stack0xfffffe3c;

  }

  iVar5 = (**(code **)(*piVar9 + 0x140))(ppiVar8,1);

  iVar3 = *(int *)(iVar3 + 4);

  iVar5 = *(int *)(iVar5 + 4);

  puVar2 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x146] + 0x140))(&ppuStack_1cc,1);

  ppuStack_1ec = (uint32_t /* width from decompiler */ **)*puVar2;

  uStack_1e8 = puVar2[1];

  iVar6 = (**(code **)(*(int *)param_1[0x147] + 0x120))(&puStack_1d4,1,0);

  iStack_1f4 = *(int *)(iVar6 + 4) + iVar3 + iVar5;

  (**(code **)(*(int *)param_1[0x146] + 8))(&puStack_1f8);

  (**(code **)(*param_1 + 8))(&uStack_1fc);

  return;

}
