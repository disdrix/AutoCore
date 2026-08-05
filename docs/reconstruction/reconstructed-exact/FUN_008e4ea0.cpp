// =============================================================================
// FUN_008e4ea0
// -----------------------------------------------------------------------------
// Stable ID: aa_008e4ea0
// Address:   0x008e4ea0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008e4ea0 @ 0x008e4ea0
// Stable ID: aa_008e4ea0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~82 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: ABS×7, FUN_0040cf90×2, FUN_0078bc30, FUN_008e4ea0, __RTDynamicCast.
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

void FUN_008e4ea0(void)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  void *pvVar5;

  uint32_t /* width from decompiler */ uVar6;

  int unaff_ESI;

  uint32_t /* width from decompiler */ uVar7;

  float *pfVar8;

  float fStack_24;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  float fStack_14;

  float fStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009ad2db;

  local_c = ExceptionList;

  if (((*(int *)(unaff_ESI + 0x7cc) != 0) && (iVar4 = *(int *)(unaff_ESI + 0x520), iVar4 != 0)) &&

     (*(int *)(iVar4 + 0x298) != 0)) {

    ExceptionList = &local_c;

    iVar4 = (**(code **)(**(int **)(iVar4 + 0x298) + 0x48))();

    fStack_24 = *(float *)(iVar4 + 0x20);

    fStack_20 = *(float *)(iVar4 + 0x24);

    fStack_1c = *(float *)(iVar4 + 0x28);

    iVar4 = (**(code **)(**(int **)(*(int *)(unaff_ESI + 0x520) + 0x298) + 0x48))();

    fVar2 = *(float *)(iVar4 + 0x14);

    fVar3 = *(float *)(iVar4 + 0x18);

    fVar1 = *(float *)(iVar4 + 0x1c);

    iVar4 = (**(code **)(**(int **)(*(int *)(unaff_ESI + 0x520) + 0x298) + 0x48))();

    pfVar8 = &fStack_18;

    fStack_18 = (ABS(fStack_24) - ABS(fVar2)) * DAT_00aaa6cc;

    uVar7 = 3;

    fStack_14 = (ABS(fStack_20) - ABS(fVar3)) * DAT_00aaa6cc;

    fStack_10 = (ABS(fStack_1c) - ABS(fVar1)) * DAT_00a0f298;

    (**(code **)(**(int **)(*(int *)(unaff_ESI + 0x520) + 0x298) + 0x10))

              (3,pfVar8,ABS(*(float *)(iVar4 + 0xc)));

    FUN_0040cf90(uVar7);

    fStack_24 = 0.0;

    fStack_20 = (float)pfVar8 * DAT_00aaa87c;

    iVar4 = (**(code **)(**(int **)(unaff_ESI + 0x520) + 0x1a0))();

    if (iVar4 != 0) {

      iVar4 = (**(code **)(**(int **)(unaff_ESI + 0x520) + 0x1a0))();

      if (0.0 - *(float *)(iVar4 + 0xf0) < fStack_20 + (float)pfVar8) {

        iVar4 = (**(code **)(**(int **)(unaff_ESI + 0x520) + 0x1a0))();

        fStack_20 = ((0.0 - *(float *)(iVar4 + 0xf0)) - (float)pfVar8) - g_flMultiKillCountBlend;

      }

    }

    uVar7 = (**(code **)(**(int **)(unaff_ESI + 0x520) + 0x17c))

                      (0,&CNDUIUpdateWidget::RTTI_Type_Descriptor,

                       &CNDUIWidgetRotate::RTTI_Type_Descriptor,0);

    iVar4 = __RTDynamicCast(uVar7);

    if (iVar4 == 0) {

      uVar7 = 0;

    }

    else {

      uVar7 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x14);

    }

    fStack_1c = 0.0;

    fStack_18 = g_flOne;

    fStack_14 = 0.0;

    pvVar5 = operator_new(0x24);

    puStack_8 = (uint8_t *)0x0;

    if (pvVar5 == (void *)0x0) {

      uVar6 = 0;

    }

    else {

      uVar6 = FUN_0078bc30(0x3d4ccccd);

    }

    puStack_8 = (uint8_t *)0xffffffff;

    (**(code **)(**(int **)(unaff_ESI + 0x520) + 0x178))(uVar6,1,uVar7,pvVar5);

    (**(code **)(**(int **)(unaff_ESI + 0x520) + 0x1a0))();

    FUN_0040cf90(&fStack_24);

  }

  ExceptionList = local_c;

  return;

}
