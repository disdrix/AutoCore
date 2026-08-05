// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_004ec040
// -----------------------------------------------------------------------------
// Stable ID: aa_004ec040
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x004ec040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~170 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, for×1, do×1, while×1.
//  - Notable callees: CONCAT22, CONCAT31, FUN_004b4e70, FUN_004b55e0, FUN_004cf860, FUN_004eb4a0, FUN_004ebee0, FUN_004ec040.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int * __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_004ec040(int param_1,uint32_t /* width from decompiler */ param_2,float *param_3,float *param_4)



{

  int *piVar1;

  float *pfVar2;

  uint uVar3;

  int iVar4;

  float *pfVar5;

  uint uVar6;

  float *pfVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  int *piStack_13c;

  int *local_138;

  float local_134;

  float local_130;

  float local_12c;

  float local_128;

  float local_124 [4];

  float local_114;

  float local_110;

  float local_10c;

  float local_108;

  float local_104;

  float *local_100;

  uint32_t /* width from decompiler */ local_fc;

  uint32_t /* width from decompiler */ local_f8;

  uint32_t /* width from decompiler */ local_f4;

  uint32_t /* width from decompiler */ local_f0;

  uint32_t /* width from decompiler */ local_ec;

  uint32_t /* width from decompiler */ local_e8;

  float local_e0;

  uint32_t /* width from decompiler */ local_dc;

  uint32_t /* width from decompiler */ local_d8;

  uint32_t /* width from decompiler */ local_d4;

  uint32_t /* width from decompiler */ local_d0;

  float local_cc;

  uint32_t /* width from decompiler */ local_c8;

  uint32_t /* width from decompiler */ local_c4;

  uint32_t /* width from decompiler */ local_c0;

  uint32_t /* width from decompiler */ local_bc;

  float local_b8;

  uint32_t /* width from decompiler */ local_b4;

  uint32_t /* width from decompiler */ local_b0;

  uint32_t /* width from decompiler */ local_ac;

  uint32_t /* width from decompiler */ local_a8;

  uint32_t /* width from decompiler */ local_a4;

  uint32_t /* width from decompiler */ local_a0;

  float local_88 [24];

  uint8_t local_28;

  void *local_1c;

  uint8_t *puStack_18;

  uint local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009a27ec;

  local_1c = ExceptionList;

  if ((*(int *)(param_1 + 0xf0) != 0) && (*(int *)(param_1 + 0x90) != 0)) {

    ExceptionList = &local_1c;

    FUN_004f3370(1);

    local_14 = 0;

    FUN_004f3120(*(uint32_t /* width from decompiler */ *)(param_1 + 0x90));

    local_134 = 0.0;

    local_28 = 1;

    local_f0 = 0;

    local_ec = 0;

    local_e8 = 0x80000000;

    local_f8 = 0;

    local_fc = 0;

    local_f4 = 0;

    local_d4 = 0;

    local_d8 = 0;

    local_dc = 0;

    local_c4 = 0;

    local_c8 = 0;

    local_d0 = 0;

    local_b4 = 0;

    local_bc = 0;

    local_c0 = 0;

    local_e0 = g_flOne;

    local_cc = g_flOne;

    local_b8 = g_flOne;

    local_a4 = 0;

    local_a8 = 0;

    local_ac = 0;

    local_b0 = 0;

    local_a0 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xf0);

    local_100 = local_88;

    iVar4 = *(int *)(*(int *)(param_1 + 0x90) + 0x30);

    local_14 = CONCAT31(local_14._1_3_,1);

    if (iVar4 != 0) {

      local_134 = *(float *)(iVar4 + 0x3c);

    }

    FUN_004eb4a0(&local_100,param_2,0x3f800000,0x3f800000,local_134);

    pfVar2 = local_100;

    local_138 = (int *)0x0;

    if ((_DAT_00b03e88 & 1) == 0) {

      _DAT_00b03e88 = _DAT_00b03e88 | 1;

    }

    _DAT_00b03e7c = param_4[1];

    _DAT_00b03e80 = param_4[2];

    _DAT_00b03e78 = *param_4;

    _DAT_00b03e84 = param_4[3];

    local_128 = _DAT_00b03e7c * _DAT_00b03e7c * g_flLevelUpUiBase_Inferred;

    local_12c = _DAT_00b03e80 * _DAT_00b03e80 * g_flLevelUpUiBase_Inferred;

    local_134 = _DAT_00b03e78 * _DAT_00b03e7c * g_flLevelUpUiBase_Inferred;

    fVar9 = _DAT_00b03e80 * _DAT_00b03e84 * g_flLevelUpUiBase_Inferred;

    local_124[0] = (g_flOne - local_128) - local_12c;

    local_124[1] = local_134 - fVar9;

    fVar12 = _DAT_00b03e7c * _DAT_00b03e84 * g_flLevelUpUiBase_Inferred;

    fVar11 = _DAT_00b03e78 * _DAT_00b03e80 * g_flLevelUpUiBase_Inferred;

    local_124[2] = fVar12 + fVar11;

    local_124[3] = fVar9 + local_134;

    fVar8 = _DAT_00b03e78 * _DAT_00b03e84 * g_flLevelUpUiBase_Inferred;

    fVar10 = g_flOne - _DAT_00b03e78 * _DAT_00b03e78 * g_flLevelUpUiBase_Inferred;

    fVar9 = _DAT_00b03e7c * _DAT_00b03e80 * g_flLevelUpUiBase_Inferred;

    local_114 = fVar10 - local_12c;

    local_110 = fVar9 - fVar8;

    local_10c = fVar11 - fVar12;

    local_108 = fVar8 + fVar9;

    local_104 = fVar10 - local_128;

    if ((_DAT_00b03e74 & 1) == 0) {

      _DAT_00b03e74 = _DAT_00b03e74 | 1;

    }

    fVar9 = param_3[2];

    fVar8 = param_3[1];

    _DAT_00b03e68 = *param_3;

    pfVar5 = local_124;

    pfVar7 = local_100;

    for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {

      *pfVar7 = *pfVar5;

      pfVar5 = pfVar5 + 1;

      pfVar7 = pfVar7 + 1;

    }

    _DAT_00b03e6c = fVar8;

    _DAT_00b03e70 = fVar9;

    local_130 = _DAT_00b03e84;

    local_100[9] = _DAT_00b03e68;

    pfVar2[10] = fVar8;

    pfVar2[0xb] = fVar9;

    FUN_004cf860(&local_138,local_100);

    if (local_138 != (int *)0x0) {

      uVar6 = 0;

      iVar4 = (**(code **)(*local_138 + 0x4c))();

      if (iVar4 != 0) {

        do {

          iVar4 = (**(code **)(*local_138 + 0x50))();

          (**(code **)(**(int **)(iVar4 + uVar6 * 4) + 8))

                    (CONCAT22((short)((uint)*(int *)(param_1 + 0x90) >> 0x10),

                              *(uint16_t *)(*(int *)(param_1 + 0x90) + 0x3c)));

          uVar6 = uVar6 + 1;

          uVar3 = (**(code **)(*piStack_13c + 0x4c))();

        } while (uVar6 < uVar3);

      }

    }

    local_a0 = 0;

    local_100 = (float *)0x0;

    FUN_004b4e70();

    piVar1 = local_138;

    local_14 = local_14 & 0xffffff00;

    FUN_004ebee0();

    local_14 = 0xffffffff;

    FUN_004b55e0();

    ExceptionList = local_1c;

    return piVar1;

  }

  return (int *)0x0;

}
