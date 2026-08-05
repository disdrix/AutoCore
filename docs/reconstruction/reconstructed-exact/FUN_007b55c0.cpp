// =============================================================================
// FUN_007b55c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007b55c0
// Address:   0x007b55c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007b55c0 @ 0x007b55c0
// Stable ID: aa_007b55c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~234 non-empty decompiler lines.
//  - Control keywords: if×14, while×2, do×1, switch×1, return×1.
//  - Notable callees: FUN_00424060×4, CONCAT31×3, FUN_00797530×3, DeleteCriticalSection×2, FUN_00423f40×2, FUN_00424380×2, FUN_00427d20×2, FUN_007972f0×2.
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

/* WARNING: Removing unreachable block (ram,0x007b58a6) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int __fastcall FUN_007b55c0(int *param_1)



{

  char *pcVar1;

  int iVar2;

  char cVar3;

  undefined *puVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  char *pcVar7;

  char *unaff_EBP;

  int iVar8;

  float fVar9;

  undefined *puStack_d0;

  undefined ***pppuStack_cc;

  uint8_t local_80 [4];

  uint32_t /* width from decompiler */ uStack_7c;

  uint32_t /* width from decompiler */ uStack_78;

  uint32_t /* width from decompiler */ uStack_74;

  uint32_t /* width from decompiler */ uStack_70;

  undefined **ppuStack_6c;

  _RTL_CRITICAL_SECTION _Stack_68;

  uint32_t /* width from decompiler */ uStack_50;

  uint32_t /* width from decompiler */ uStack_4c;

  uint32_t /* width from decompiler */ uStack_48;

  uint8_t uStack_44;

  undefined **ppuStack_40;

  _RTL_CRITICAL_SECTION _Stack_3c;

  uint32_t /* width from decompiler */ uStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint8_t uStack_18;

  void *pvStack_14;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b323c;

  pvStack_c = ExceptionList;

  iVar8 = 0;

  ExceptionList = &pvStack_c;

  (**(code **)(*param_1 + 0x140))();

  if (param_1[0x83] == 0) {

    if (param_1[0x9d] != 0) {

      uStack_7c = 0;

      uStack_78 = 0;

      uStack_74 = 0;

      uStack_70 = 0;

      pppuStack_cc = (undefined ***)0x0;

      pvStack_c = (void *)0x3;

      puStack_d0 = (undefined *)param_1[0x85];

      FUN_0040aeb0(&puStack_d0);

      FUN_0099cae0();

      pppuStack_cc = (undefined ***)0x7b5ab4;

      puVar4 = operator_new(0xd0);

      pvStack_c._0_1_ = 4;

      if (puVar4 != (undefined *)0x0) {

        pppuStack_cc = (undefined ***)local_80;

        puStack_d0 = puVar4;

        iVar8 = FUN_007972f0();

      }

      pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,3);

      fVar9 = *(float *)(iVar8 + 0xa8) + *(float *)(iVar8 + 0xa4);

      *(uint8_t *)(iVar8 + 0xb6) = *(uint8_t *)((int)param_1 + 0xd9);

      if (fVar9 != 0.0) {

        *(float *)(iVar8 + 0xa4) = fVar9;

        *(uint32_t /* width from decompiler */ *)(iVar8 + 0xa8) = 0;

        pppuStack_cc = (undefined ***)0x7b5b27;

        FUN_00797530();

      }

      FUN_00797440();

      pcVar7 = (char *)param_1[0x9d];

      pcVar1 = pcVar7 + 1;

      do {

        cVar3 = *pcVar7;

        pcVar7 = pcVar7 + 1;

      } while (cVar3 != '\0');

      if ((uint)param_1[0x46] < (uint)((int)pcVar7 - (int)pcVar1)) {

        puStack_d0 = (undefined *)0x7b5b64;

        pppuStack_cc = (undefined ***)iVar8;

        FUN_007b5010();

      }

      pppuStack_cc = (undefined ***)0x7b5b6a;

      FUN_007979c0();

      pvStack_c = (void *)0xffffffff;

      FUN_00424770();

    }

  }

  else {

    ppuStack_40 = &PTR_FUN_00a9646c;

    uStack_20 = 0;

    uStack_24 = 0;

    uStack_1c = 0;

    uStack_18 = 0;

    pppuStack_cc = (undefined ***)0x7b56b3;

    InitializeCriticalSection(&_Stack_3c);

    ppuStack_40 = &PTR_FUN_00a96484;

    pvStack_c = (void *)0x0;

    ppuStack_6c = &PTR_FUN_00a96478;

    uStack_4c = 0;

    uStack_50 = 0;

    uStack_48 = 0;

    uStack_44 = 0;

    pppuStack_cc = (undefined ***)0x7b56eb;

    InitializeCriticalSection(&_Stack_68);

    ppuStack_6c = &PTR_FUN_00a96490;

    pvStack_c._0_1_ = 1;

    iVar2 = param_1[0xa4];

    pppuStack_cc = (undefined ***)0x7b5721;

    puVar4 = operator_new(0xd0);

    pvStack_c._0_1_ = 2;

    if (puVar4 == (undefined *)0x0) {

      iVar8 = 0;

    }

    else {

      pppuStack_cc = (undefined ***)0x0;

      puStack_d0 = puVar4;

      iVar8 = FUN_007972f0();

    }

    pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,1);

    fVar9 = *(float *)(iVar8 + 0xa4) + *(float *)(iVar8 + 0xa8);

    *(uint8_t *)(iVar8 + 0xb6) = *(uint8_t *)((int)param_1 + 0xd9);

    if (fVar9 != 0.0) {

      *(float *)(iVar8 + 0xa4) = fVar9;

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0xa8) = 0;

      pppuStack_cc = (undefined ***)0x7b5793;

      FUN_00797530();

    }

    FUN_00797440();

    FUN_004294f0();

    pppuStack_cc = (undefined ***)0x7b57b9;

    iVar5 = FUN_00423f40();

    while (iVar5 == 0) {

      switch(_DAT_00000000) {

      case 1:

        if ((pcRam00000004 != (char *)0x0) && (*pcRam00000004 != '\0')) {

          puStack_d0 = &UNK_007b58dc;

          pppuStack_cc = (undefined ***)iVar8;

          FUN_007b5010();

        }

        break;

      case 2:

        pppuStack_cc = &ppuStack_40;

        puStack_d0 = &UNK_007b57ee;

        FUN_00424380();

        pppuStack_cc = (undefined ***)&UNK_007b57fd;

        (**(code **)(*param_1 + 0x1b0))();

        break;

      case 3:

        pppuStack_cc = (undefined ***)&UNK_007b583b;

        puVar6 = operator_new(4);

        if (puVar6 != (uint32_t /* width from decompiler */ *)0x0) {

          *puVar6 = unaff_EBP;

        }

        pppuStack_cc = &ppuStack_6c;

        puStack_d0 = &UNK_007b5857;

        FUN_00424380();

        unaff_EBP = pcRam00000004;

        break;

      case 6:

        pppuStack_cc = (undefined ***)0x0;

        puStack_d0 = &UNK_007b5815;

        cVar3 = FUN_00427d20();

        if (cVar3 != '\0') {

          FUN_00424260();

        }

        break;

      case 7:

        pppuStack_cc = (undefined ***)0x0;

        puStack_d0 = &UNK_007b5892;

        FUN_00427d20();

        break;

      case 10:

        break;

      case 0xb:

        if (pcRam00000004 != (char *)0x0) {

          pppuStack_cc = (undefined ***)&UNK_007b5900;

          FUN_00797a60();

        }

        break;

      case 0xc:

        if (((pcRam00000004 != (char *)0x0) &&

            (pcVar1 = *(char **)(pcRam00000004 + 0x1c), pcVar1 != (char *)0x0)) && (*pcVar1 != '\0')

           ) {

          pppuStack_cc = *(undefined ****)(pcRam00000004 + 0x14);

          puStack_d0 = *(undefined **)(pcRam00000004 + 0x10);

          func_0x007987d0(pcVar1,*(uint32_t /* width from decompiler */ *)(pcRam00000004 + 0x20),param_1[0xa4],

                          CONCAT31((int3)((uint)*(uint32_t /* width from decompiler */ *)(pcRam00000004 + 0xc) >> 8),

                                   *pcRam00000004),*(uint32_t /* width from decompiler */ *)(pcRam00000004 + 8),

                          *(uint32_t /* width from decompiler */ *)(pcRam00000004 + 0xc));

        }

        break;

      case 0xd:

        if (pcRam00000004 != (char *)0x0) {

          pppuStack_cc = *(undefined ****)(pcRam00000004 + 0x10);

          puStack_d0 = *(undefined **)(pcRam00000004 + 0xc);

          func_0x00797240(*(uint32_t /* width from decompiler */ *)(pcRam00000004 + 8));

        }

        break;

      case 0xe:

        func_0x00797200();

      }

      pppuStack_cc = (undefined ***)0x7b5987;

      iVar5 = FUN_00423f40();

    }

    if ((char)param_1[0x84] != '\0') {

      *(uint8_t *)(param_1 + 0x84) = 0;

      pppuStack_cc = (undefined ***)0x7b59a7;

      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x7b));

    }

    *(float *)(iVar8 + 0xa4) = *(float *)(iVar8 + 0xa4) + *(float *)(iVar8 + 0xa8);

    *(uint32_t /* width from decompiler */ *)(iVar8 + 0xa8) = 0;

    pppuStack_cc = (undefined ***)0x7b59d1;

    FUN_00797530();

    *(int *)(iVar8 + 4) =

         *(int *)(iVar8 + 4) + (int)(*(float *)(iVar8 + 0xac) * g_flDisplayRateScaleOneThird);

    param_1[0xa4] = iVar2;

    ppuStack_6c = &PTR_FUN_00a96490;

    FUN_00424060();

    ppuStack_6c = &PTR_FUN_00a96478;

    FUN_00424060();

    pppuStack_cc = (undefined ***)0x7b5a21;

    DeleteCriticalSection(&_Stack_68);

    ppuStack_40 = &PTR_FUN_00a96484;

    FUN_00424060();

    ppuStack_40 = &PTR_FUN_00a9646c;

    FUN_00424060();

    pppuStack_cc = (undefined ***)0x7b5a59;

    DeleteCriticalSection(&_Stack_3c);

  }

  ExceptionList = pvStack_14;

  return iVar8;

}
