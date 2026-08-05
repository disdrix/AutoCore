// =============================================================================
// FUN_00855810
// -----------------------------------------------------------------------------
// Stable ID: aa_00855810
// Address:   0x00855810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00855810 @ 0x00855810
// Stable ID: aa_00855810
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~294 non-empty decompiler lines.
//  - Control keywords: if×16, return×5, do×5, while×5, switch×1, goto×1.
//  - Notable callees: FUN_008555e0×4, FUN_004c03d0×3, __RTDynamicCast×3, free×2, FUN_00402d50, FUN_00403450, FUN_004bfd10, FUN_004c9aa0.
//  - Return sites: 5.

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

void __thiscall FUN_00855810(int *param_1,uint8_t param_2)



{

  char cVar1;

  uint8_t uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  void *pvVar5;

  uint32_t /* width from decompiler */ uVar6;

  int iVar7;

  char *pcVar8;

  char *pcVar9;

  int *unaff_ESI;

  uint32_t /* width from decompiler */ *puVar10;

  uint32_t /* width from decompiler */ *puVar11;

  uint32_t /* width from decompiler */ uVar12;

  uint32_t /* width from decompiler */ uVar13;

  uint32_t /* width from decompiler */ uVar14;

  uint32_t /* width from decompiler */ uVar15;

  int *piVar16;

  uint8_t *puVar17;

  uint32_t /* width from decompiler */ uVar18;

  uint32_t /* width from decompiler */ uStack_1cc;

  uint32_t /* width from decompiler */ uStack_1c8;

  uint32_t /* width from decompiler */ uStack_1c4;

  float fStack_1c0;

  uint32_t /* width from decompiler */ uStack_1bc;

  uint32_t /* width from decompiler */ uStack_1b8;

  uint32_t /* width from decompiler */ uStack_1b4;

  uint32_t /* width from decompiler */ uStack_1b0;

  uint32_t /* width from decompiler */ uStack_1ac;

  uint32_t /* width from decompiler */ uStack_1a8;

  uint32_t /* width from decompiler */ uStack_1a4;

  float fStack_1a0;

  uint32_t /* width from decompiler */ uStack_19c;

  uint32_t /* width from decompiler */ uStack_198;

  uint32_t /* width from decompiler */ uStack_194;

  uint32_t /* width from decompiler */ uStack_190;

  uint32_t /* width from decompiler */ uStack_18c;

  uint32_t /* width from decompiler */ uStack_188;

  uint32_t /* width from decompiler */ uStack_184;

  float fStack_180;

  uint32_t /* width from decompiler */ uStack_171;

  uint8_t auStack_16c [68];

  char *pcStack_128;

  char acStack_124 [128];

  uint8_t *puStack_a4;

  uint8_t auStack_a0 [120];

  void *pvStack_28;

  void *pvStack_24;

  void *pvStack_20;

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009b036d;

  pvStack_1c = ExceptionList;

  ExceptionList = &pvStack_1c;

  *(uint8_t *)(unaff_ESI + 0x144) = param_2;

  (**(code **)(*unaff_ESI + 0x4c))();

  iVar7 = unaff_ESI[0x145];

  if (iVar7 != 0) {

    iVar3 = (**(code **)(*unaff_ESI + 0x1a8))();

    *(uint8_t *)(iVar3 + 0x48) = 1;

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x44) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x40);

    FUN_0076c4d0();

    cVar1 = (**(code **)(**(int **)(iVar3 + 8) + 8))(iVar7);

    if (cVar1 != '\0') {

      FUN_00755db0(iVar7);

      FUN_00755e80(iVar7);

    }

    if ((uint32_t /* width from decompiler */ *)unaff_ESI[0x145] != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)unaff_ESI[0x145])(1);

    }

    unaff_ESI[0x145] = 0;

  }

  if ((int *)unaff_ESI[0x140] != (int *)0x0) {

    uVar4 = (**(code **)(*(int *)unaff_ESI[0x140] + 0x1cc))();

    FUN_004bfd10(uVar4);

    if ((uint32_t /* width from decompiler */ *)unaff_ESI[0x140] != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)unaff_ESI[0x140])(1);

    }

    unaff_ESI[0x140] = 0;

  }

  unaff_ESI[0xa6] = 0;

  *(uint8_t *)(unaff_ESI + 0x2f) = 0;

  unaff_ESI[0x142] = -1;

  unaff_ESI[0x143] = -1;

  if (param_1 == (int *)0x0) {

    if (unaff_ESI[0xa9] != 0) {

      *(uint8_t *)(unaff_ESI[0xa9] + 400) = 0;

    }

    (**(code **)(*unaff_ESI + 0x34c))();

    ExceptionList = pvStack_1c;

    return;

  }

  unaff_ESI[0x142] = param_1[0x58];

  unaff_ESI[0x143] = param_1[0x59];

  if (unaff_ESI[0xa9] != 0) {

    uVar2 = (**(code **)(*unaff_ESI + 0xd0))();

    *(uint8_t *)(unaff_ESI[0xa9] + 400) = uVar2;

  }

  switch(*(uint32_t /* width from decompiler */ *)(param_1[0x2a] + 0x38)) {

  case 0xe:

    iVar7 = __RTDynamicCast(param_1,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                            &CVOGVehicle::RTTI_Type_Descriptor,0);

    pvVar5 = operator_new(0x800);

    uStack_14 = 2;

    if (pvVar5 == (void *)0x0) {

      iVar3 = 0;

    }

    else {

      iVar3 = FUN_00501970(1);

    }

    uStack_14 = 0xffffffff;

    (**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3) + 8))

              (*(uint32_t /* width from decompiler */ *)

                (*(int *)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 0xac + iVar7) + 0x3c) + 4),

               DAT_00d1b644,1);

    if (*(char *)(iVar7 + 0x2ac) != '\0') {

      *(uint8_t *)(iVar3 + 0x2ac) = 1;

    }

    fStack_1c0 = g_flOne;

    unaff_ESI[0xa6] = 0;

    puVar17 = &LAB_00854d00;

    uVar13 = 0;

    unaff_ESI[0x140] = *(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3;

    uVar6 = 0;

    uStack_1cc = 0;

    uStack_1c8 = 0;

    uStack_1c4 = 0;

    uStack_1bc = 0;

    uStack_1b8 = 0;

    uStack_1b4 = 0;

    uStack_1b0 = 0;

    uVar18 = 0;

    uVar12 = 1;

    puVar10 = &uStack_1cc;

    puVar11 = &uStack_1bc;

    piVar16 = unaff_ESI;

    uVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3) + 0x1cc))

                      (puVar11,puVar10,1,0,0,0);

    FUN_004c03d0(uVar4,puVar11,puVar10,uVar12,uVar18,uVar6,uVar13,piVar16,puVar17);

    (**(code **)(*unaff_ESI + 0x2ac))();

    (**(code **)(*unaff_ESI + 0x48))();

    FUN_008555e0();

    ExceptionList = pvStack_28;

    return;

  default:

    iVar7 = *(int *)(param_1[0x2a] + 0x3c);

    pcStack_128 = acStack_124;

    uVar4 = (*(code *)PTR_FUN_00af8c9c)();

    FUN_00403450(iVar7 + 0x10,uVar4);

    iVar7 = 1 - (int)pcStack_128;

    pcVar8 = pcStack_128;

    do {

      cVar1 = *pcVar8;

      pcVar8[(int)&uStack_171 + iVar7] = cVar1;

      pcVar8 = pcVar8 + 1;

    } while (cVar1 != '\0');

    uStack_14 = 0xffffffff;

    if (pcStack_128 != acStack_124) {

      free(pcStack_128);

    }

    puVar10 = &uStack_171;

    do {

      pcVar8 = (char *)((int)puVar10 + 1);

      puVar10 = (uint32_t /* width from decompiler */ *)((int)puVar10 + 1);

    } while (*pcVar8 != '\0');

    break;

  case 0x12:

    iVar7 = __RTDynamicCast(param_1,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                            &CVOGCreature::RTTI_Type_Descriptor,0);

    pvVar5 = operator_new(0x690);

    uStack_14 = 1;

    if (pvVar5 == (void *)0x0) {

      iVar3 = 0;

    }

    else {

      iVar3 = FUN_004c9aa0(1);

    }

    uStack_14 = 0xffffffff;

    uVar15 = 1;

    uVar4 = *(uint32_t /* width from decompiler */ *)

             (*(int *)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 0xac + iVar7) + 0x3c) + 4);

    uVar12 = DAT_00d1b644;

    (**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3) + 8))(uVar4,DAT_00d1b644,1)

    ;

    fStack_1a0 = g_flOne;

    unaff_ESI[0xa6] = 0;

    puVar17 = &LAB_00854d00;

    uVar14 = 0;

    unaff_ESI[0x140] = *(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3;

    uStack_1ac = 0;

    uStack_1a8 = 0;

    uStack_1a4 = 0;

    uVar13 = 0;

    uVar6 = 0;

    piVar16 = unaff_ESI;

    uVar18 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3) + 0x1cc))

                       (&stack0xfffffe24,&uStack_1ac,1,0,0,0);

    FUN_004c03d0(uVar18,uVar6,uVar13,uVar14,piVar16,puVar17,uVar4,uVar12,uVar15);

    goto LAB_00855c2e;

  case 0x14:

    iVar7 = (**(code **)(*param_1 + 0x1dc))();

    iVar3 = 0;

    if (iVar7 != 0) {

      pvVar5 = operator_new(0xf30);

      uStack_14 = 0;

      if (pvVar5 != (void *)0x0) {

        iVar3 = FUN_00536920(1);

      }

      uStack_14 = 0xffffffff;

      uVar18 = 1;

      uVar4 = *(uint32_t /* width from decompiler */ *)

               (*(int *)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 0xac + iVar7) + 0x3c) + 4);

      uVar12 = DAT_00d1b644;

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3) + 8))

                (uVar4,DAT_00d1b644,1);

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0x6fc) = *(uint32_t /* width from decompiler */ *)(iVar7 + 0x6fc);

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0x700) = *(uint32_t /* width from decompiler */ *)(iVar7 + 0x700);

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0x6f8) = *(uint32_t /* width from decompiler */ *)(iVar7 + 0x6f8);

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0x708) = *(uint32_t /* width from decompiler */ *)(iVar7 + 0x708);

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0x70c) = *(uint32_t /* width from decompiler */ *)(iVar7 + 0x70c);

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0x704) = *(uint32_t /* width from decompiler */ *)(iVar7 + 0x704);

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0x714) = *(uint32_t /* width from decompiler */ *)(iVar7 + 0x714);

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0x710) = *(uint32_t /* width from decompiler */ *)(iVar7 + 0x710);

      iVar7 = 0;

      do {

        uVar6 = FUN_0051ffd0(iVar7);

        FUN_0051ffb0(iVar7,uVar6);

        fStack_180 = g_flOne;

        iVar7 = iVar7 + 1;

      } while (iVar7 < 6);

      unaff_ESI[0xa6] = 0;

      puVar17 = &LAB_00854d00;

      uVar15 = 0;

      unaff_ESI[0x140] = *(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3;

      uVar14 = 0;

      uStack_18c = 0;

      uStack_188 = 0;

      uStack_184 = 0;

      uStack_19c = 0;

      uStack_198 = 0;

      uStack_194 = 0;

      uStack_190 = 0;

      uVar13 = 0;

      piVar16 = unaff_ESI;

      uVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3) + 0x1cc))

                        (&uStack_19c,&uStack_18c,1,0,0,0);

      FUN_004c03d0(uVar6,uVar13,uVar14,uVar15,piVar16,puVar17,uVar4,uVar12,uVar18);

      unaff_ESI[0xa6] = *(int *)(iVar3 + 0x48);

    }

LAB_00855c2e:

    (**(code **)(*unaff_ESI + 0x2ac))();

    (**(code **)(*unaff_ESI + 0x48))();

    FUN_008555e0();

    ExceptionList = pvStack_1c;

    return;

  case 0x22:

    iVar7 = __RTDynamicCast(param_1,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                            &CVOGContinentObject::RTTI_Type_Descriptor,0);

    if (*(int *)(iVar7 + 8) == 0) {

      (**(code **)(*unaff_ESI + 0x40))(0,0);

      FUN_008555e0();

      ExceptionList = pvStack_24;

      return;

    }

    puVar10 = (uint32_t /* width from decompiler */ *)FUN_00402d50(*(int *)(param_1[0x2a] + 0x3c) + 0x10);

    pcVar9 = (char *)*puVar10;

    pcVar8 = (char *)((int)&uStack_171 + 1);

    do {

      cVar1 = *pcVar9;

      *pcVar8 = cVar1;

      pcVar9 = pcVar9 + 1;

      pcVar8 = pcVar8 + 1;

    } while (cVar1 != '\0');

    uStack_14 = 0xffffffff;

    if (puStack_a4 != auStack_a0) {

      free(puStack_a4);

    }

    puVar10 = &uStack_171;

    do {

      pcVar8 = (char *)((int)puVar10 + 1);

      puVar10 = (uint32_t /* width from decompiler */ *)((int)puVar10 + 1);

    } while (*pcVar8 != '\0');

  }

  *puVar10 = DAT_00a28904;

  iVar7 = *unaff_ESI;

  *(uint8_t *)(puVar10 + 1) = DAT_00a28908;

  (**(code **)(iVar7 + 0x3c))((int)&uStack_171 + 1);

  FUN_008555e0();

  ExceptionList = pvStack_20;

  return;

}
