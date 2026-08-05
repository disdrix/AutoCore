// =============================================================================
// FUN_006992b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006992b0
// Address:   0x006992b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006992b0 @ 0x006992b0
// Stable ID: aa_006992b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~122 non-empty decompiler lines.
//  - Control keywords: if×7, return×2, while×1, for×1.
//  - Notable callees: FUN_006a1c00×2, FUN_0068b7d0, FUN_0068e710, FUN_00697f60, FUN_00698be0, FUN_00698f40, FUN_006992b0, FUN_0069c490.
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

void __thiscall FUN_006992b0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  float *pfVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  int *piVar4;

  int iVar5;

  uint uVar6;

  float10 fVar7;

  int *local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aace6;

  local_c = ExceptionList;

  DAT_00af55a4 = *(char *)(param_1 + 0xcc) == '\0';

  ExceptionList = &local_c;

  local_40 = operator_new(0x40);

  piVar4 = (int *)0x0;

  local_4 = 0;

  if (local_40 == (int *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_0069c490(0);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x58) = uVar2;

  local_4 = 0xffffffff;

  if (*(char *)(param_1 + 0xcc) == '\0') {

    iVar5 = *(int *)(param_1 + 0xb4);

    local_40 = operator_new__(iVar5 * 0x10 + 4);

    local_4 = 1;

    if (local_40 != (int *)0x0) {

      piVar4 = local_40 + 1;

      *local_40 = iVar5;

      _eh_vector_constructor_iterator_(piVar4,0x10,iVar5,FUN_004565f0,FUN_00691630);

    }

    *(int **)(param_1 + 200) = piVar4;

  }

  local_4 = 0xffffffff;

  DAT_00af55a8 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4);

  if (DAT_00d08ef0 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(DAT_00d08ef0);

  }

  DAT_00d08ebc = param_1 + 0x84;

  DAT_00d08ef0 = (void *)0x0;

  DAT_00d08ef4 = (uint32_t /* width from decompiler */ *)0x0;

  DAT_00d08ef8 = 0;

  uVar6 = 0;

  while ((iVar5 = *(int *)(param_1 + 100), iVar5 != 0 &&

         (uVar6 < (uint)(*(int *)(param_1 + 0x68) - iVar5 >> 2)))) {

    local_40 = *(int **)(iVar5 + uVar6 * 4);

    if ((DAT_00d08ef0 == (void *)0x0) ||

       ((uint)(DAT_00d08ef8 - (int)DAT_00d08ef0 >> 2) <=

        (uint)((int)DAT_00d08ef4 - (int)DAT_00d08ef0 >> 2))) {

      FUN_00697f60(DAT_00d08ef4,1,&local_40);

      uVar6 = uVar6 + 1;

    }

    else {

      *DAT_00d08ef4 = local_40;

      DAT_00d08ef4 = DAT_00d08ef4 + 1;

      uVar6 = uVar6 + 1;

    }

  }

  FUN_006a1c00(*(uint32_t /* width from decompiler */ *)(param_1 + 0x48));

  fVar7 = (float10)FUN_006a1be0(*(float *)(param_1 + 0x4c) - *(float *)(param_1 + 0x50),

                                *(float *)(param_1 + 0x50) + *(float *)(param_1 + 0x4c));

  local_40 = (int *)(float)fVar7;

  srand(*(uint *)(param_1 + 0x54));

  if (g_flZero < *(float *)(param_1 + 0x4c)) {

    iVar5 = 0;

    for (uVar6 = 0;

        (*(int *)(param_1 + 0x94) != 0 &&

        (uVar6 < (uint)((*(int *)(param_1 + 0x98) - *(int *)(param_1 + 0x94)) / 0x54)));

        uVar6 = uVar6 + 1) {

      pfVar1 = (float *)(*(int *)(param_1 + 0x94) + 0x3c + iVar5);

      iVar3 = *(int *)(param_1 + 0x94) + iVar5;

      iVar5 = iVar5 + 0x54;

      *(float *)(iVar3 + 0x48) = *pfVar1 * *(float *)(param_1 + 0x4c);

      *(float *)(iVar3 + 0x4c) = *(float *)(iVar3 + 0x40) * *(float *)(param_1 + 0x4c);

    }

  }

  FUN_006a1c00(*(uint32_t /* width from decompiler */ *)(param_1 + 0x48));

  FUN_0068e710(*(uint16_t *)(param_1 + 0x70));

  FUN_0068b7d0(0);

  DAT_00d08ec4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x48);

  local_3c = 0;

  local_38 = 0;

  local_34 = 0x3f800000;

  local_30 = 0x3f800000;

  local_2c = 0;

  local_28 = 0;

  local_24 = 0;

  local_20 = 0x3f800000;

  local_1c = 0;

  local_18 = 0;

  local_14 = 0;

  local_10 = 0x3f800000;

  FUN_0069cc30(*(uint32_t /* width from decompiler */ *)(param_1 + 0x48),local_40,0,param_1 + 4,0,&local_30,&local_3c,

               *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c),param_1 + 0x74,0x3f800000,

               *(uint32_t /* width from decompiler */ *)(param_1 + 0x48),0xbf800000);

  FUN_00698be0();

  if (*(char *)(param_1 + 0xcc) == '\0') {

    FUN_00698f40(param_2);

  }

  ExceptionList = local_c;

  return;

}
