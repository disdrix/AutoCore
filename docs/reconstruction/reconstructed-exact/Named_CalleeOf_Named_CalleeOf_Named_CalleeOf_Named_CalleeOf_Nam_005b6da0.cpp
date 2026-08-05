// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005b6da0
// -----------------------------------------------------------------------------
// Stable ID: aa_005b6da0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x005b6da0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper. Evidence string: "NDTreeBillboard.fx". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "NDTreeBillboard.fx"
//   - "DiffuseTexture"
//   - "AlphaRefValue"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~191 non-empty decompiler lines.
//  - Control keywords: if×13, return×2, for×1.
//  - Notable callees: FUN_00687150×2, FUN_00414bc0, FUN_00414c20, FUN_005b6da0, FUN_00687130, FUN_00687320, FUN_0068a4d0, FUN_007464e0.
//  - Strings: "NDTreeBillboard.fx"; "DiffuseTexture"; "AlphaRefValue".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005b6da0(int param_1)



{

  int *piVar1;

  uint *puVar2;

  int iVar3;

  int *piVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ uVar6;

  float *pfVar7;

  uint32_t /* width from decompiler */ *puVar8;

  int iVar9;

  float *pfVar10;

  float10 fVar11;

  int *local_9c;

  uint8_t local_98;

  uint8_t uStack_97;

  uint8_t uStack_96;

  float fStack_94;

  float fStack_90;

  float fStack_8c;

  float fStack_88;

  float fStack_84;

  float fStack_80;

  float afStack_7c [4];

  uint32_t /* width from decompiler */ uStack_6c;

  float fStack_68;

  float fStack_64;

  uint32_t /* width from decompiler */ uStack_60;

  uint32_t /* width from decompiler */ uStack_5c;

  uint32_t /* width from decompiler */ uStack_58;

  float fStack_54;

  uint32_t /* width from decompiler */ uStack_50;

  uint32_t /* width from decompiler */ uStack_4c;

  uint32_t /* width from decompiler */ uStack_48;

  uint32_t /* width from decompiler */ uStack_44;

  float fStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  uint32_t /* width from decompiler */ uStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  uint8_t auStack_2c [8];

  void *pvStack_24;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  void *pvStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a6a09;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  fVar11 = (float10)FUN_00687130();

  local_9c = (int *)(float)fVar11;

  FUN_00687150(0);

  FUN_0068a4d0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x50),8,0xffffffff,0xffffffff,0xffffffff);

  FUN_00687150(local_9c);

  FUN_0096f530();

  local_4 = 0;

  FUN_00989e00(&local_9c,"NDTreeBillboard.fx");

  FUN_009701d0(&local_9c);

  FUN_00970140("DiffuseTexture",**(uint32_t /* width from decompiler */ **)(param_1 + 0x24));

  piVar5 = operator_new(0xdc);

  local_4._0_1_ = 1;

  local_9c = piVar5;

  if (piVar5 == (int *)0x0) {

    piVar5 = (int *)0x0;

  }

  else {

    FUN_00748960();

    *piVar5 = (int)&PTR_FUN_009d9924;

    piVar5[1] = (int)&PTR_LAB_009d9914;

    piVar5[0x34] = -1;

    piVar5[0x35] = -1;

    piVar5[0x36] = -1;

    *(uint8_t *)(piVar5 + 0x33) = 0;

    piVar5[0x31] = 0;

    piVar5[0x32] = 0;

  }

  *(int **)(param_1 + 0x18) = piVar5;

  local_4 = (uint)local_4._1_3_ << 8;

  uVar6 = (**(code **)(**(int **)(param_1 + 8) + 0xc))();

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x18) + 100) = uVar6;

  iVar3 = **(int **)(param_1 + 0x18);

  uVar6 = (**(code **)(**(int **)(param_1 + 8) + 100))();

  (**(code **)(iVar3 + 0x34))(uVar6);

  piVar5 = local_9c;

  iVar3 = *(int *)(param_1 + 0x18);

  if ((local_9c != (int *)0x0) && (local_9c[1] = local_9c[1] + 1, local_9c[1] == 1)) {

    (**(code **)(*local_9c + 4))();

  }

  piVar4 = *(int **)(iVar3 + 0x20);

  if (piVar4 != (int *)0x0) {

    piVar1 = piVar4 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar4 + 8))();

    }

  }

  *(int **)(iVar3 + 0x20) = piVar5;

  *(uint8_t *)(iVar3 + 0x24) = local_98;

  *(uint8_t *)(iVar3 + 0x25) = uStack_97;

  *(uint8_t *)(iVar3 + 0x26) = uStack_96;

  iVar3 = *(int *)(param_1 + 0x18);

  *(uint *)(iVar3 + 0xbc) = *(uint *)(iVar3 + 0xbc) | 1;

  if (*(int *)(*(int *)(param_1 + 0x174) + 0x128) == 0) {

    FUN_00687320(&fStack_94);

    afStack_7c[1] = fStack_84 - fStack_90;

    fStack_68 = fStack_80 - fStack_8c;

    if (fStack_80 - fStack_8c < fStack_88 - fStack_94) {

      fStack_68 = fStack_88 - fStack_94;

    }

    fStack_68 = fStack_68 * DAT_00a0f298;

    puVar8 = *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0x50) + 0xf4);

    afStack_7c[3] = (float)*puVar8;

    afStack_7c[0] = 0.0 - fStack_68;

    afStack_7c[2] = 0.0;

    uStack_5c = puVar8[2];

    uStack_60 = 0;

    uStack_48 = puVar8[4];

    uStack_50 = 0;

    uStack_4c = 0;

    uStack_3c = 0;

    uStack_38 = 0;

    uStack_34 = puVar8[6];

    uStack_6c = puVar8[1];

    uStack_58 = puVar8[3];

    uStack_44 = puVar8[5];

    uStack_30 = puVar8[7];

    fStack_64 = afStack_7c[1];

    fStack_54 = fStack_68;

    fStack_40 = afStack_7c[0];

    uVar6 = FUN_00414bc0(0x102);

    puStack_8._0_1_ = 2;

    FUN_00414c20(4,uVar6,0x22,0);

    puStack_8 = (uint8_t *)((uint)puStack_8._1_3_ << 8);

    uStack_18 = 0;

    uStack_14 = 0;

    if (pvStack_24 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(pvStack_24);

    }

    iVar9 = *(int *)(iVar3 + 0x14);

    if ((*(int *)(iVar9 + 0x10) != 0) &&

       (pfVar7 = (float *)FUN_00746520(*(uint32_t /* width from decompiler */ *)(iVar9 + 0x14),*(uint32_t /* width from decompiler */ *)(iVar9 + 0x18),0

                                      ), pfVar7 != (float *)0x0)) {

      pfVar10 = afStack_7c;

      for (iVar9 = 0x14; iVar9 != 0; iVar9 = iVar9 + -1) {

        *pfVar7 = *pfVar10;

        pfVar10 = pfVar10 + 1;

        pfVar7 = pfVar7 + 1;

      }

    }

    if (*(int *)(*(int *)(iVar3 + 0x14) + 0x10) != 0) {

      FUN_007464e0();

    }

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x174) + 0x118) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x14);

  }

  else {

    piVar5 = *(int **)(*(int *)(param_1 + 0x174) + 0x118);

    if ((piVar5 != (int *)0x0) && (piVar5[1] = piVar5[1] + 1, piVar5[1] == 1)) {

      (**(code **)(*piVar5 + 4))();

    }

    piVar4 = *(int **)(iVar3 + 0x14);

    if (piVar4 != (int *)0x0) {

      piVar1 = piVar4 + 1;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar4 + 8))();

      }

    }

    *(int **)(iVar3 + 0x14) = piVar5;

  }

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x18) + 0xac) = 6;

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x18) + 0xa8) = 2;

  FUN_0096f740();

  puVar2 = (uint *)(*(int *)(param_1 + 0x18) + 0xbc);

  *puVar2 = *puVar2 & 0xfffffffe;

  FUN_007647c0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18));

  if (*(int *)(*(int *)(param_1 + 0x18) + 0x20) == 0) {

    puVar8 = (uint32_t /* width from decompiler */ *)&stack0xffffff60;

  }

  else {

    puVar8 = (uint32_t /* width from decompiler */ *)FUN_00752370(auStack_2c,"AlphaRefValue");

  }

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x18) + 0xd8) = *puVar8;

  puStack_8 = (uint8_t *)0xffffffff;

  FUN_0096f510();

  ExceptionList = pvStack_10;

  return;

}
