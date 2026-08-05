// =============================================================================
// FUN_00854d20
// -----------------------------------------------------------------------------
// Stable ID: aa_00854d20
// Address:   0x00854d20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00854d20 @ 0x00854d20
// Stable ID: aa_00854d20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~103 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, while×1, return×1.
//  - Notable callees: FUN_004bfd10, FUN_004c03d0, FUN_004c3700, FUN_0051fae0, FUN_0051ffb0, FUN_00536920, FUN_00854d20.
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

void __fastcall FUN_00854d20(uint32_t /* width from decompiler */ *param_1,int *param_2)



{

  float fVar1;

  uint8_t uVar2;

  uint32_t /* width from decompiler */ uVar3;

  void *pvVar4;

  int iVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint8_t *puVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint32_t /* width from decompiler */ uVar11;

  uint32_t /* width from decompiler */ uVar12;

  int *piVar13;

  uint8_t *puVar14;

  uint32_t /* width from decompiler */ uStack_3c;

  uint32_t /* width from decompiler */ uStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  float fStack_30;

  void *pvStack_28;

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009abc56;

  pvStack_1c = ExceptionList;

  ExceptionList = &pvStack_1c;

  (**(code **)(*param_2 + 0x4c))();

  if ((int *)param_2[0x140] != (int *)0x0) {

    uVar3 = (**(code **)(*(int *)param_2[0x140] + 0x1cc))();

    FUN_004bfd10(uVar3);

    if ((uint32_t /* width from decompiler */ *)param_2[0x140] != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)param_2[0x140])(1);

    }

    param_2[0x140] = 0;

  }

  param_2[0x142] = param_1[2];

  iVar6 = 0;

  param_2[0x143] = param_1[3];

  if (param_2[0xa9] != 0) {

    uVar2 = (**(code **)(*param_2 + 0xd0))();

    fVar1 = g_flMsToSeconds_Inferred;

    *(uint8_t *)(param_2[0xa9] + 400) = uVar2;

    iVar5 = param_2[0xa9];

    *(float *)(iVar5 + 0xf0) = fVar1;

    *(uint8_t *)(iVar5 + 0x48) = 1;

    *(uint8_t *)(iVar5 + 0xcc) = 1;

  }

  param_2[0xa6] = 0;

  pvVar4 = operator_new(0xf30);

  uStack_14 = 0;

  if (pvVar4 != (void *)0x0) {

    iVar6 = FUN_00536920(1);

  }

  uStack_14 = 0xffffffff;

  if (iVar6 == 0) {

    iVar5 = 0;

  }

  else {

    iVar5 = *(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6;

  }

  param_2[0x140] = iVar5;

  (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 8))

            (*param_1,DAT_00d1b644,1);

  *(uint32_t /* width from decompiler */ *)(iVar6 + 0x6fc) = param_1[5];

  *(uint32_t /* width from decompiler */ *)(iVar6 + 0x700) = param_1[6];

  *(uint32_t /* width from decompiler */ *)(iVar6 + 0x6f8) = param_1[4];

  *(uint32_t /* width from decompiler */ *)(iVar6 + 0x708) = param_1[7];

  *(uint32_t /* width from decompiler */ *)(iVar6 + 0x70c) = param_1[8];

  *(uint32_t /* width from decompiler */ *)(iVar6 + 0x704) = param_1[9];

  *(uint32_t /* width from decompiler */ *)(iVar6 + 0x714) = param_1[10];

  *(uint32_t /* width from decompiler */ *)(iVar6 + 0x710) = param_1[0xb];

  FUN_004c3700(param_1[0xc]);

  FUN_0051fae0(param_1 + 0x13);

  iVar5 = 0;

  param_1 = param_1 + 0xd;

  do {

    FUN_0051ffb0(iVar5,*param_1);

    iVar5 = iVar5 + 1;

    param_1 = param_1 + 1;

  } while (iVar5 < 6);

  puVar14 = &LAB_00854ce0;

  uVar12 = 0;

  uVar11 = 0;

  uStack_3c = 0;

  uStack_38 = 0;

  uStack_34 = 0;

  fStack_30 = g_flOne;

  uVar10 = 0;

  uVar9 = 0;

  puVar8 = &stack0xffffffb4;

  puVar7 = &uStack_3c;

  piVar13 = param_2;

  uVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0x1cc))

                    (puVar7,puVar8,0,0,0,0,param_2,&LAB_00854ce0);

  FUN_004c03d0(uVar3,puVar7,puVar8,uVar9,uVar10,uVar11,uVar12,piVar13,puVar14);

  if (param_2[0xa9] != 0) {

    *(uint32_t /* width from decompiler */ *)(param_2[0xa9] + 0x184) = 0;

  }

  ExceptionList = pvStack_28;

  return;

}
