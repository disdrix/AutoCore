// =============================================================================
// FUN_00883d50
// -----------------------------------------------------------------------------
// Stable ID: aa_00883d50
// Address:   0x00883d50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00883d50 @ 0x00883d50
// Stable ID: aa_00883d50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~179 non-empty decompiler lines.
//  - Control keywords: if×17, goto×8, do×4, while×4, return×2.
//  - Notable callees: FUN_0051fb50×8, sprintf×8, FUN_00883d50.
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

void FUN_00883d50(char param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  byte bVar1;

  int in_EAX;

  byte *pbVar2;

  int iVar3;

  byte *pbVar4;

  bool bVar5;

  uint64_t uVar6;

  uint64_t uStack_a4;

  byte *pbStack_9c;

  uint32_t /* width from decompiler */ uStack_98;

  byte *pbStack_94;

  byte local_80 [128];

  

  if (param_1 == '\0') {

    pbStack_94 = (byte *)param_3;

    uStack_98 = param_2;

    pbStack_9c = (byte *)0x0;

    uStack_a4._4_4_ = 0x883f9b;

    uStack_a4 = FUN_0051fb50();

    sprintf((char *)local_80,"%i");

    pbStack_94 = (byte *)0x1;

    uStack_98 = 1;

    pbStack_9c = local_80;

    uStack_a4._4_4_ = 0x883fc9;

    (**(code **)(**(int **)(in_EAX + 0x568) + 0x1d8))();

    uStack_a4._4_4_ = param_3;

    uStack_a4._0_4_ = param_2;

    uVar6 = FUN_0051fb50(1);

    sprintf(&stack0xffffff74,"%i",(int)uVar6,(int)((ulonglong)uVar6 >> 0x20));

    uStack_a4._4_4_ = 1;

    uStack_a4._0_4_ = 1;

    (**(code **)(**(int **)(in_EAX + 0x56c) + 0x1d8))(&stack0xffffff74);

    uVar6 = FUN_0051fb50(2,param_2,param_3);

    sprintf((char *)&uStack_98,"%i",(int)uVar6,(int)((ulonglong)uVar6 >> 0x20));

    (**(code **)(**(int **)(in_EAX + 0x570) + 0x1d8))(&uStack_98,1,1);

    uVar6 = FUN_0051fb50(3,param_2,param_3);

    sprintf((char *)&uStack_a4,"%i",(int)uVar6,(int)((ulonglong)uVar6 >> 0x20));

    (**(code **)(**(int **)(in_EAX + 0x574) + 0x1d8))(&uStack_a4,1,1);

    (**(code **)(**(int **)(in_EAX + 0x568) + 0x34c))();

    (**(code **)(**(int **)(in_EAX + 0x56c) + 0x34c))();

    (**(code **)(**(int **)(in_EAX + 0x570) + 0x34c))();

    (**(code **)(**(int **)(in_EAX + 0x574) + 0x34c))();

    return;

  }

  pbStack_94 = (byte *)param_3;

  uStack_98 = param_2;

  pbStack_9c = (byte *)0x0;

  uStack_a4._4_4_ = 0x883d81;

  uStack_a4 = FUN_0051fb50();

  sprintf((char *)local_80,"%i");

  pbStack_94 = (byte *)0x883da4;

  pbVar2 = (byte *)(**(code **)(**(int **)(in_EAX + 0x558) + 0x1dc))();

  pbVar4 = local_80;

  do {

    bVar1 = *pbVar4;

    bVar5 = bVar1 < *pbVar2;

    if (bVar1 != *pbVar2) {

LAB_00883dd4:

      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);

      goto LAB_00883dd9;

    }

    if (bVar1 == 0) break;

    bVar1 = pbVar4[1];

    bVar5 = bVar1 < pbVar2[1];

    if (bVar1 != pbVar2[1]) goto LAB_00883dd4;

    pbVar4 = pbVar4 + 2;

    pbVar2 = pbVar2 + 2;

  } while (bVar1 != 0);

  iVar3 = 0;

LAB_00883dd9:

  if (iVar3 != 0) {

    pbStack_94 = local_80;

    uStack_98 = 0x883df0;

    (**(code **)(**(int **)(in_EAX + 0x558) + 0x3ac))();

  }

  pbStack_94 = (byte *)param_3;

  uStack_98 = param_2;

  pbStack_9c = (byte *)0x1;

  uStack_a4._4_4_ = 0x883df9;

  uStack_a4 = FUN_0051fb50();

  sprintf((char *)local_80,"%i");

  pbStack_94 = (byte *)0x883e1c;

  pbVar2 = (byte *)(**(code **)(**(int **)(in_EAX + 0x55c) + 0x1dc))();

  pbVar4 = local_80;

  do {

    bVar1 = *pbVar4;

    bVar5 = bVar1 < *pbVar2;

    if (bVar1 != *pbVar2) {

LAB_00883e46:

      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);

      goto LAB_00883e4b;

    }

    if (bVar1 == 0) break;

    bVar1 = pbVar4[1];

    bVar5 = bVar1 < pbVar2[1];

    if (bVar1 != pbVar2[1]) goto LAB_00883e46;

    pbVar4 = pbVar4 + 2;

    pbVar2 = pbVar2 + 2;

  } while (bVar1 != 0);

  iVar3 = 0;

LAB_00883e4b:

  if (iVar3 != 0) {

    pbStack_94 = local_80;

    uStack_98 = 0x883e62;

    (**(code **)(**(int **)(in_EAX + 0x55c) + 0x3ac))();

  }

  pbStack_94 = (byte *)param_3;

  uStack_98 = param_2;

  pbStack_9c = (byte *)0x2;

  uStack_a4._4_4_ = 0x883e6b;

  uStack_a4 = FUN_0051fb50();

  sprintf((char *)local_80,"%i");

  pbStack_94 = (byte *)0x883e8e;

  pbVar2 = (byte *)(**(code **)(**(int **)(in_EAX + 0x560) + 0x1dc))();

  pbVar4 = local_80;

  do {

    bVar1 = *pbVar4;

    bVar5 = bVar1 < *pbVar2;

    if (bVar1 != *pbVar2) {

LAB_00883eb8:

      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);

      goto LAB_00883ebd;

    }

    if (bVar1 == 0) break;

    bVar1 = pbVar4[1];

    bVar5 = bVar1 < pbVar2[1];

    if (bVar1 != pbVar2[1]) goto LAB_00883eb8;

    pbVar4 = pbVar4 + 2;

    pbVar2 = pbVar2 + 2;

  } while (bVar1 != 0);

  iVar3 = 0;

LAB_00883ebd:

  if (iVar3 != 0) {

    pbStack_94 = local_80;

    uStack_98 = 0x883ed4;

    (**(code **)(**(int **)(in_EAX + 0x560) + 0x3ac))();

  }

  pbStack_94 = (byte *)param_3;

  uStack_98 = param_2;

  pbStack_9c = (byte *)0x3;

  uStack_a4._4_4_ = 0x883edd;

  uStack_a4 = FUN_0051fb50();

  sprintf((char *)local_80,"%i");

  pbStack_94 = (byte *)0x883f00;

  pbVar2 = (byte *)(**(code **)(**(int **)(in_EAX + 0x564) + 0x1dc))();

  pbVar4 = local_80;

  do {

    bVar1 = *pbVar4;

    bVar5 = bVar1 < *pbVar2;

    if (bVar1 != *pbVar2) {

LAB_00883f2a:

      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);

      goto LAB_00883f2f;

    }

    if (bVar1 == 0) break;

    bVar1 = pbVar4[1];

    bVar5 = bVar1 < pbVar2[1];

    if (bVar1 != pbVar2[1]) goto LAB_00883f2a;

    pbVar4 = pbVar4 + 2;

    pbVar2 = pbVar2 + 2;

  } while (bVar1 != 0);

  iVar3 = 0;

LAB_00883f2f:

  if (iVar3 != 0) {

    pbStack_94 = local_80;

    uStack_98 = 0x883f46;

    (**(code **)(**(int **)(in_EAX + 0x564) + 0x3ac))();

  }

  pbStack_94 = (byte *)0x883f54;

  (**(code **)(**(int **)(in_EAX + 0x558) + 0x34c))();

  pbStack_94 = (byte *)0x883f62;

  (**(code **)(**(int **)(in_EAX + 0x55c) + 0x34c))();

  pbStack_94 = (byte *)0x883f70;

  (**(code **)(**(int **)(in_EAX + 0x560) + 0x34c))();

  pbStack_94 = (byte *)0x883f7e;

  (**(code **)(**(int **)(in_EAX + 0x564) + 0x34c))();

  return;

}
