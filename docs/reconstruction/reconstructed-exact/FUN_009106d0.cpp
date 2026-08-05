// =============================================================================
// FUN_009106d0
// -----------------------------------------------------------------------------
// Stable ID: aa_009106d0
// Address:   0x009106d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009106d0 @ 0x009106d0
// Stable ID: aa_009106d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~77 non-empty decompiler lines.
//  - Control keywords: if×7, return×2.
//  - Notable callees: FUN_0074e910, FUN_0074ecf0, FUN_0074ed90, FUN_0074ee40, FUN_009106d0, FUN_00989e00.
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

uint32_t /* width from decompiler */ __thiscall FUN_009106d0(int param_1,uint32_t /* width from decompiler */ param_2,float param_3,float param_4)



{

  int iVar1;

  int *piVar2;

  bool bVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  float10 fVar7;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b106d;

  pvStack_c = ExceptionList;

  iVar6 = param_1 * 0x10;

  ExceptionList = &pvStack_c;

  if (*(int *)(&DAT_00d09a54 + iVar6) != 0) {

    ExceptionList = &pvStack_c;

    (**(code **)(*(int *)(&DAT_00d09a4c)[param_1 * 4] + 0x10))(*(int *)(&DAT_00d09a54 + iVar6));

    pvVar4 = *(void **)(&DAT_00d09a54 + iVar6);

    if (pvVar4 != (void *)0x0) {

      FUN_0074ecf0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar4);

    }

    *(uint32_t /* width from decompiler */ *)(&DAT_00d09a54 + iVar6) = 0;

    pvVar4 = operator_new(0x78);

    uStack_4 = 0;

    if (pvVar4 == (void *)0x0) {

      uVar5 = 0;

    }

    else {

      uVar5 = FUN_0074ed90();

    }

    *(uint32_t /* width from decompiler */ *)(&DAT_00d09a54 + iVar6) = uVar5;

  }

  uStack_4 = 0xffffffff;

  iVar1 = *(int *)(&DAT_00d09a54 + iVar6);

  if (param_4 != g_flZero) {

    *(float *)(iVar1 + 0x3c) = param_4;

    *(float *)(iVar1 + 0x34) = *(float *)(iVar1 + 0x40) - *(float *)(iVar1 + 0x44) / param_4;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x50) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x68) = 0;

  }

  FUN_00989e00(&param_2,param_2);

  FUN_0074ee40(&param_2);

  bVar3 = param_4 == DAT_00aaa668;

  *(uint8_t *)(*(int *)(&DAT_00d09a54 + iVar6) + 0x4c) = param_3._0_1_;

  if (bVar3) {

    piVar2 = *(int **)(*(int *)(&DAT_00d09a54 + iVar6) + 4);

    if (((piVar2 == (int *)0x0) ||

        (param_3 = (float)(*(int *)(*(int *)(&DAT_00d09a54 + iVar6) + 8) - (int)piVar2 >> 2),

        param_3 == 0.0)) || (*piVar2 == 0)) {

      param_3 = 0.0;

    }

    else {

      fVar7 = (float10)(**(code **)(*(int *)*piVar2 + 4))();

      param_3 = (float)fVar7;

    }

    FUN_0074e910(param_3,0);

  }

  iVar1 = (&DAT_00d09a58)[param_1 * 4];

  if (iVar1 != 0) {

    piVar2 = *(int **)(&DAT_00d09a50 + iVar6);

    (**(code **)(*piVar2 + 8))();

    piVar2[4] = iVar1;

    (**(code **)(*(int *)(&DAT_00d09a4c)[param_1 * 4] + 4))

              (*(uint32_t /* width from decompiler */ *)(&DAT_00d09a50 + iVar6),0x3f800000);

    (**(code **)(*(int *)(&DAT_00d09a4c)[param_1 * 4] + 0xc))

              (*(uint32_t /* width from decompiler */ *)(&DAT_00d09a54 + iVar6));

    (**(code **)(*(int *)(&DAT_00d09a4c)[param_1 * 4] + 0x18))

              (*(uint32_t /* width from decompiler */ *)(&DAT_00d09a54 + iVar6),0,0x3f800000);

  }

  ExceptionList = pvStack_c;

  return 1;

}
