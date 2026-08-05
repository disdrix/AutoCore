// =============================================================================
// FUN_004ca150
// -----------------------------------------------------------------------------
// Stable ID: aa_004ca150
// Address:   0x004ca150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004ca150 @ 0x004ca150
// Stable ID: aa_004ca150
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~175 non-empty decompiler lines.
//  - Control keywords: if×15, goto×2, return×1.
//  - Notable callees: Object_ResolveFromTFID×3, FUN_0040aff0×2, FUN_0074e700×2, CVOGHBBase_Start, CVOGHBList_Enqueue, FUN_004024d0, FUN_00404a20, FUN_00404c90.
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

uint32_t /* width from decompiler */ __thiscall FUN_004ca150(int param_1,int param_2)



{

  byte *pbVar1;

  uint uVar2;

  char cVar3;

  int *piVar4;

  TFID_16 *pTVar5;

  int iVar6;

  void *pA;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ uVar8;

  CVOGHBBase *pAction;

  int iVar9;

  float10 fVar10;

  uint8_t *puVar11;

  uint32_t /* width from decompiler */ *puVar12;

  uint32_t /* width from decompiler */ uVar13;

  uint32_t /* width from decompiler */ uStack_6c;

  void *pvStack_68;

  uint32_t /* width from decompiler */ uStack_64;

  uint32_t /* width from decompiler */ uStack_60;

  uint32_t /* width from decompiler */ uStack_5c;

  uint32_t /* width from decompiler */ uStack_58;

  uint32_t /* width from decompiler */ uStack_54;

  TFID_16 TStack_50;

  uint8_t auStack_40 [4];

  uint8_t auStack_3c [12];

  uint8_t auStack_30 [12];

  uint32_t /* width from decompiler */ local_24;

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009a1da8;

  pvStack_1c = ExceptionList;

  iVar9 = *(int *)(param_1 + -0x448);

  ExceptionList = &pvStack_1c;

  if ((((-1 < iVar9) && (ExceptionList = &pvStack_1c, iVar9 < 0x13)) &&

      (ExceptionList = &pvStack_1c, *(int *)(param_1 + -0x494 + iVar9 * 4) != 0)) &&

     ((ExceptionList = &pvStack_1c, *(int *)(param_1 + -0x49c) != 0 &&

      (ExceptionList = &pvStack_1c, *(int *)(param_1 + -0x494 + iVar9 * 4) != 0)))) {

    ExceptionList = &pvStack_1c;

    FUN_0074e700(1,0);

  }

  if (((*(int *)(param_1 + -0x224) != -1) && (*(int *)(param_1 + -0x49c) != 0)) &&

     (*(int *)(param_1 + -0x494 + *(int *)(param_1 + -0x224) * 4) != 0)) {

    FUN_0074e700(1,0);

  }

  if (*(char *)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x458 + param_1) + 0x7e) !=

      '\0') {

    iVar9 = param_1 + -0x500;

    FUN_004c81f0();

    cVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x4fc + param_1) +

                        0x198))();

    if ((((cVar3 == '\0') && (param_2 != 0)) && (param_2 != 1)) &&

       ((*(short *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + 0xac + iVar9) +

                            0x3c) + 0x3f4) == 1 ||

        (*(short *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + 0xac + iVar9) +

                            0x3c) + 0x3f4) == 2)))) {

      iVar6 = *(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x4fc + param_1;

      TStack_50.dwCoidLo = *(uint *)(iVar6 + 0x40);

      TStack_50.dwCoidHi = *(uint *)(iVar6 + 0x44);

      TStack_50._8_4_ = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x48);

      TStack_50._12_4_ = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x4c);

      piVar4 = Object_ResolveFromTFID(&TStack_50);

      if (piVar4 == (int *)0x0) {

        if (*(int *)(param_1 + -0x2b0) == 0) goto LAB_004ca65b;

        pTVar5 = (TFID_16 *)FUN_00415cb0(auStack_30);

        piVar4 = Object_ResolveFromTFID(pTVar5);

        if (piVar4 == (int *)0x0) goto LAB_004ca65b;

      }

      iVar6 = (**(code **)(*piVar4 + 0x1d8))();

      if (iVar6 != 0) {

        puVar12 = &DAT_009cb8c0;

        puVar11 = auStack_40;

        (**(code **)(*piVar4 + 0x1d8))(puVar11);

        pA = (void *)FUN_0040aff0(puVar11);

        iVar6 = TFID_NotEquals(pA,puVar12);

        if ((char)iVar6 != '\0') {

          uStack_6c = *(uint32_t /* width from decompiler */ *)

                       (*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x458 + param_1) +

                       0xe4e8);

          puVar11 = auStack_40;

          (**(code **)(*piVar4 + 0x1d8))(puVar11);

          pTVar5 = (TFID_16 *)FUN_0040aff0(puVar11);

          piVar4 = Object_ResolveFromTFID(pTVar5);

        }

      }

      if ((piVar4 != (int *)0x0) && (iVar6 = (**(code **)(*piVar4 + 0x210))(0), iVar6 != 0)) {

        if (*(short *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + 0xac + iVar9) +

                               0x3c) + 0x3f4) == 1) {

          uStack_6c = DAT_00b037a4;

        }

        else {

          uStack_6c = DAT_00b037a0;

        }

        pvStack_68 = operator_new(0x690);

        puVar12 = (uint32_t /* width from decompiler */ *)0x0;

        uStack_14 = 0;

        if (pvStack_68 != (void *)0x0) {

          puVar12 = (uint32_t /* width from decompiler */ *)FUN_004c9aa0(1);

        }

        uStack_14 = 0xffffffff;

        (**(code **)(*(int *)(*(int *)(puVar12[1] + 4) + 4 + (int)puVar12) + 8))

                  (uStack_6c,

                   *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x458 + param_1),1);

        pbVar1 = (byte *)(*(int *)(puVar12[1] + 4) + 0x181 + (int)puVar12);

        *pbVar1 = *pbVar1 | 1;

        puVar7 = (uint32_t /* width from decompiler */ *)FUN_00404c90();

        uStack_6c = *puVar7;

        pvStack_68 = (void *)puVar7[1];

        uStack_64 = puVar7[2];

        uStack_60 = puVar7[3];

        fVar10 = (float10)FUN_004cd220(uStack_6c,uStack_64);

        pvStack_68 = (void *)(float)fVar10;

        uStack_5c = DAT_00b037c0;

        uStack_58 = DAT_00b037c4;

        uStack_54 = DAT_00b037c8;

        TStack_50.dwCoidLo = DAT_00b037cc;

        FUN_005a5970(auStack_3c,uStack_6c,uStack_64);

        uVar8 = FUN_00404a20(&TStack_50.dwCoidHi);

        FUN_004e8ad0(uVar8);

        FUN_004e9060(auStack_3c,&TStack_50.dwCoidHi,&uStack_5c);

        (**(code **)*puVar12)

                  (*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x458 + param_1),

                   &uStack_6c,&uStack_5c,0);

        iVar9 = *(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x458 + param_1);

        uVar2 = *(uint *)(iVar9 + 0xe6d8);

        iVar6 = *(int *)(iVar9 + 0xe6dc);

        *(uint *)(iVar9 + 0xe6d8) = uVar2 + 1;

        *(uint *)(iVar9 + 0xe6dc) = iVar6 + (uint)(0xfffffffe < uVar2);

        FUN_00512160(uVar2,iVar6,0);

        uVar8 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x4fc + param_1) +

                            0x27c))();

        FUN_004c3700(uVar8);

        (**(code **)(*(int *)(*(int *)(puVar12[1] + 4) + 4 + (int)puVar12) + 0x2a4))

                  (*(uint32_t /* width from decompiler */ *)

                    (*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x458 + param_1) + 0xe4e8)

                  );

        pvStack_68 = operator_new(0x24);

        uStack_14 = 1;

        if (pvStack_68 == (void *)0x0) {

          pAction = (CVOGHBBase *)0x0;

        }

        else {

          pAction = (CVOGHBBase *)FUN_005d8360(*(int *)(puVar12[1] + 4) + 4 + (int)puVar12,90000);

        }

        uStack_14 = 0xffffffff;

        CVOGHBList_Enqueue(*(void **)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x458 +

                                              param_1) + 0xe4ec),pAction);

        CVOGHBBase_Start(pAction);

        FUN_004024d0(*(int *)(puVar12[1] + 4) + 4 + (int)puVar12);

      }

    }

  }

LAB_004ca65b:

  local_24 = *(uint32_t /* width from decompiler */ *)(param_1 + -0x2cc);

  if (((*(uint *)(param_1 + -0x2d8) & *(uint *)(param_1 + -0x2d4)) != 0xffffffff) ||

     ((char)*(uint32_t /* width from decompiler */ *)(param_1 + -0x2d0) != '\0')) {

    local_24 = *(uint32_t /* width from decompiler */ *)(param_1 + -0x2cc);

    iVar9 = FUN_004bb040(*(uint32_t /* width from decompiler */ *)(param_1 + -0x2d0),*(uint *)(param_1 + -0x2d8),

                         *(uint32_t /* width from decompiler */ *)(param_1 + -0x2d4));

    if (iVar9 != 0) {

      FUN_004c99e0(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x39c + param_1);

    }

  }

  uVar13 = 0;

  uVar8 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x4fc + param_1) + 0x1c8

                      ))(0);

  FUN_004e2600(&LAB_004c3bc0,uVar8,uVar13);

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x304) = 0;

  FUN_005d4b30(param_2);

  ExceptionList = pvStack_1c;

  return 1;

}
