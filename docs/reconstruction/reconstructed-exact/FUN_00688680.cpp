// =============================================================================
// FUN_00688680
// -----------------------------------------------------------------------------
// Stable ID: aa_00688680
// Address:   0x00688680  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00688680 @ 0x00688680
// Stable ID: aa_00688680
// Embedded strings (evidence for future rename):
//   - "Compute() called more than once for single tree model (ignored)"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~125 non-empty decompiler lines.
//  - Control keywords: if×11, for×4, return×2.
//  - Notable callees: FUN_0056f570×2, FUN_00688b04×2, FUN_0068bcd0×2, FUN_0068bda0×2, FUN_0068e2c0×2, CONCAT31, Compute, FUN_00685db0.
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

void __thiscall FUN_00688680(int *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ param_3,char param_4)



{

  float *pfVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ local_8c [17];

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  int *local_18;

  uint8_t *local_14;

  void *pvStack_10;

  uint8_t *puStack_c;

  int local_8;

  

  puStack_c = &LAB_009aa035;

  pvStack_10 = ExceptionList;

  local_14 = &stack0xffffff4c;

  local_8 = 0;

  local_18 = param_1;

  if (*(char *)((int)param_1 + 0x45) == '\0') {

    DAT_00d08ec8 = param_1[0x16];

    ExceptionList = &pvStack_10;

    local_14 = &stack0xffffff4c;

    FUN_00697210(param_3);

    FUN_006992b0(param_1[9]);

    FUN_00696920(param_1[0x17],param_1[3]);

    *(uint16_t *)(param_1 + 0x18) = *(uint16_t *)(param_1[0x17] + 0x18);

    iVar3 = *(int *)(*param_1 + 0x94);

    iVar2 = 0;

    if (iVar3 != 0) {

      iVar2 = (*(int *)(*param_1 + 0x98) - iVar3) / 0x54;

    }

    FUN_0069e730(iVar2);

    if (*(int *)(param_1[3] + 0x38) == 1) {

      FUN_00687370();

    }

    FUN_00699870(*param_1 + 0xe8);

    iVar3 = *param_1;

    FUN_0068f9b0(*(uint32_t /* width from decompiler */ *)(iVar3 + 0xb4),*(uint32_t /* width from decompiler */ *)(iVar3 + 200),iVar3 + 0x84);

    if (param_1[0x13] != 0) {

      for (iVar3 = 0; iVar3 < *(int *)param_1[0x13]; iVar3 = iVar3 + 1) {

        FUN_0068e950(iVar3,iVar3 * 0x20 + ((int *)param_1[0x13])[1]);

      }

      for (iVar3 = 0; iVar3 < *(int *)(param_1[0x13] + 0x10); iVar3 = iVar3 + 1) {

        FUN_006908e0(param_1[0x17],iVar3,iVar3 * 0x20 + *(int *)(param_1[0x13] + 0x14),DAT_00d08e55)

        ;

      }

    }

    if (param_4 != '\0') {

      FUN_0068e2c0();

      FUN_0068e2c0();

    }

    if (param_2 != (uint32_t /* width from decompiler */ *)0x0) {

      FUN_0069f400();

      puVar4 = local_8c;

      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {

        *puVar4 = *param_2;

        param_2 = param_2 + 1;

        puVar4 = puVar4 + 1;

      }

      FUN_0068bda0(local_8c);

      FUN_0068edc0(local_8c);

      FUN_0068bda0(local_8c);

      if (param_1[0x15] != 0) {

        FUN_00688580(local_8c);

      }

    }

    FUN_0069fa50();

    local_8 = CONCAT31(local_8._1_3_,1);

    FUN_0068bcd0(&local_48);

    FUN_0068fb10(&local_48);

    FUN_0068bcd0(&local_48);

    puVar4 = (uint32_t /* width from decompiler */ *)param_1[0x10];

    *puVar4 = local_48;

    puVar4[1] = local_44;

    puVar4[2] = local_40;

    iVar3 = param_1[0x10];

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = local_30;

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x10) = local_2c;

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x14) = local_28;

    pfVar1 = (float *)param_1[0x10];

    _param_4 = (float)(((int)((*pfVar1 - g_flZero) * (*pfVar1 - g_flZero) +

                             (pfVar1[2] - g_flZero) * (pfVar1[2] - g_flZero)) >> 1) + 0x1fc00000);

    if (_param_4 <=

        (float)(((int)((*pfVar1 - g_flZero) * (*pfVar1 - g_flZero) +

                      (pfVar1[5] - g_flZero) * (pfVar1[5] - g_flZero)) >> 1) + 0x1fc00000)) {

      _param_4 = (float)(((int)((*pfVar1 - g_flZero) * (*pfVar1 - g_flZero) +

                               (pfVar1[5] - g_flZero) * (pfVar1[5] - g_flZero)) >> 1) + 0x1fc00000);

    }

    if (_param_4 <=

        (float)(((int)((pfVar1[3] - g_flZero) * (pfVar1[3] - g_flZero) +

                      (pfVar1[2] - g_flZero) * (pfVar1[2] - g_flZero)) >> 1) + 0x1fc00000)) {

      _param_4 = (float)(((int)((pfVar1[2] - g_flZero) * (pfVar1[2] - g_flZero) +

                               (pfVar1[3] - g_flZero) * (pfVar1[3] - g_flZero)) >> 1) + 0x1fc00000);

    }

    if (_param_4 <=

        (float)(((int)((pfVar1[5] - g_flZero) * (pfVar1[5] - g_flZero) +

                      (pfVar1[3] - g_flZero) * (pfVar1[3] - g_flZero)) >> 1) + 0x1fc00000)) {

      _param_4 = (float)(((int)((pfVar1[5] - g_flZero) * (pfVar1[5] - g_flZero) +

                               (pfVar1[3] - g_flZero) * (pfVar1[3] - g_flZero)) >> 1) + 0x1fc00000);

    }

    pfVar1[6] = _param_4 + _param_4;

    if (param_1[0x14] != 0) {

      FUN_00687940();

    }

    FUN_00685db0();

    *(uint8_t *)((int)param_1 + 0x45) = 1;

    local_8._0_1_ = 2;

    FUN_0056f570();

    local_8 = (uint)local_8._1_3_ << 8;

    FUN_0056f570();

    FUN_00688b04();

    return;

  }

  ExceptionList = &pvStack_10;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

             &DAT_00d08e78,"Compute() called more than once for single tree model (ignored)");

  FUN_00688b04();

  return;

}
