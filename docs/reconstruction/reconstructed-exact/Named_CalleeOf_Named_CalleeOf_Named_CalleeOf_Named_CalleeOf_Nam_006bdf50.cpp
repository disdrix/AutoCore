// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006bdf50
// -----------------------------------------------------------------------------
// Stable ID: aa_006bdf50
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x006bdf50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~190 non-empty decompiler lines.
//  - Control keywords: if×14, do×2, while×2, return×1.
//  - Notable callees: FUN_006bdb00×2, FUN_006bdc00×2, FUN_005b3300, FUN_006bdf50.
//  - Return sites: 1.

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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006bdf50(int param_1,uint16_t *param_2,int *param_3,int param_4)



{

  int *piVar1;

  uint16_t *puVar2;

  uint16_t *puVar3;

  ushort uVar4;

  uint16_t uVar5;

  uint16_t *puVar6;

  int iVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  int iVar10;

  int iVar11;

  int *piVar12;

  int *piVar13;

  uint uVar14;

  int iVar15;

  uint16_t uVar16;

  int iVar17;

  uint8_t auStackY_100 [152];

  uint32_t /* width from decompiler */ local_48;

  uint16_t local_40;

  int local_38;

  int local_28 [2];

  int local_20;

  int local_1c;

  int local_18;

  int local_14 [2];

  int iStack_c;

  int iStack_8;

  int iStack_4;

  

  iVar10 = param_4;

  iVar7 = param_1;

  *(uint32_t /* width from decompiler */ *)(param_4 + 8) = 0;

  FUN_006bdc00(*(uint32_t /* width from decompiler */ *)(param_1 + 8));

  FUN_006bdb00(param_1,1,param_4,local_14);

  FUN_006bdc00(*(uint32_t /* width from decompiler */ *)((int)param_2 + 8));

  FUN_006bdb00(param_2,auStackY_100,param_4,local_28);

  iVar11 = param_3[1] * 3 + *(int *)(param_4 + 8);

  piVar1 = (int *)(param_4 + 4);

  if ((int)(*(uint *)(param_4 + 0xc) & 0x7fffffff) < iVar11) {

    FUN_005b3300(piVar1,iVar11,8);

  }

  param_1 = 0;

  if (0 < param_3[1]) {

    param_4 = 0;

    do {

      piVar12 = (int *)(*param_3 + param_4);

      puVar6 = (uint16_t *)*piVar12;

      *(uint16_t *)(piVar12 + 2) = *puVar6;

      *(uint16_t *)(piVar12 + 3) =

           *(uint16_t *)(*(int *)(iVar7 + 4) + (uint)(ushort)puVar6[2] * 8);

      *(uint16_t *)((int)piVar12 + 0xe) = *(uint16_t *)piVar12[1];

      uVar4 = ((uint16_t *)piVar12[1])[1];

      uVar14 = (uint)*(ushort *)(local_14[0] + ((int)puVar6 - *(int *)(iVar7 + 4) >> 3) * 2);

      if (uVar14 == 0xffff) {

        iVar11 = 0;

      }

      else {

        iVar11 = *piVar1 + uVar14 * 8;

      }

      *piVar12 = iVar11;

      uVar14 = (uint)*(ushort *)(local_28[0] + ((int)((uint)uVar4 << 3) >> 3) * 2);

      if (uVar14 == 0xffff) {

        iVar11 = 0;

      }

      else {

        iVar11 = *piVar1 + uVar14 * 8;

      }

      piVar12[1] = iVar11;

      param_4 = param_4 + 0x10;

      param_1 = param_1 + 1;

    } while (param_1 < param_3[1]);

  }

  iVar7 = *piVar1;

  iVar11 = *(int *)(iVar10 + 8);

  param_2 = (uint16_t *)0x0;

  local_38 = param_3[1];

  local_48 = 0xffff;

  local_48._0_2_ = 0xffff;

  uVar16 = (uint16_t)local_48;

  if (-1 < local_38 + -1) {

    iVar15 = (local_38 + -1) * 0x10;

    piVar12 = (int *)*param_3;

    do {

      piVar13 = (int *)(*param_3 + iVar15);

      uVar8 = *(uint32_t /* width from decompiler */ *)(iVar10 + 8);

      iVar17 = *(int *)(iVar10 + 8);

      *(int *)(iVar10 + 8) = iVar17 + 1;

      puVar6 = (uint16_t *)(*piVar1 + iVar17 * 8);

      uVar9 = *(uint32_t /* width from decompiler */ *)(iVar10 + 8);

      iVar17 = *(int *)(iVar10 + 8);

      *(int *)(iVar10 + 8) = iVar17 + 1;

      puVar3 = (uint16_t *)(*piVar1 + iVar17 * 8);

      iVar17 = *piVar13;

      local_40 = (uint16_t)uVar9;

      param_1._0_2_ = (uint16_t)uVar8;

      if (iVar17 == *piVar12) {

        iVar17 = piVar13[1];

        if (*(short *)(iVar17 + 6) == 2) {

          uVar5 = *(uint16_t *)(iVar17 + 2);

          uVar14 = (uint)*(ushort *)(iVar17 + 2);

          iVar17 = iVar7;

        }

        else {

          uVar5 = (uint16_t)*(uint32_t /* width from decompiler */ *)(iVar10 + 8);

          uVar14 = *(uint *)(iVar10 + 8);

          *(uint *)(iVar10 + 8) = uVar14 + 1;

          iVar17 = *piVar1;

        }

        puVar2 = (uint16_t *)(iVar17 + uVar14 * 8);

        *puVar6 = *(uint16_t *)piVar13[1];

        puVar6[2] = local_40;

        puVar6[1] = (uint16_t)local_48;

        if (param_2 != (uint16_t *)0x0) {

          param_2[1] = (uint16_t)param_1;

        }

        *puVar2 = *(uint16_t *)((int)piVar13 + 0xe);

        puVar2[2] = (uint16_t)param_1;

        puVar2[1] = (short)(piVar13[1] - iVar7 >> 3);

        *(uint16_t *)(piVar13[1] + 2) = uVar5;

        uVar16 = (uint16_t)piVar13[2];

        param_1._0_2_ = uVar5;

      }

      else {

        if (*(short *)(iVar17 + 6) == 2) {

          uVar16 = *(uint16_t *)(iVar17 + 2);

          uVar14 = (uint)*(ushort *)(iVar17 + 2);

          iVar17 = iVar7;

        }

        else {

          uVar16 = (uint16_t)*(uint32_t /* width from decompiler */ *)(iVar10 + 8);

          uVar14 = *(uint *)(iVar10 + 8);

          *(uint *)(iVar10 + 8) = uVar14 + 1;

          iVar17 = *piVar1;

        }

        puVar2 = (uint16_t *)(iVar17 + uVar14 * 8);

        *puVar6 = *(uint16_t *)((int)piVar13 + 0xe);

        puVar6[2] = uVar16;

        puVar6[1] = (uint16_t)local_48;

        if (param_2 != (uint16_t *)0x0) {

          param_2[1] = (uint16_t)param_1;

        }

        *puVar2 = (short)piVar13[3];

        puVar2[2] = local_40;

        puVar2[1] = (short)(*piVar13 - iVar7 >> 3);

        *(uint16_t *)(*piVar13 + 2) = uVar16;

        uVar16 = *(uint16_t *)*piVar13;

      }

      *puVar3 = uVar16;

      puVar3[2] = (uint16_t)param_1;

      iVar15 = iVar15 + -0x10;

      local_38 = local_38 + -1;

      piVar12 = piVar13;

      param_2 = puVar3;

      local_48 = uVar9;

      uVar16 = local_40;

    } while (local_38 != 0);

  }

  local_48._0_2_ = uVar16;

  param_2[1] = (short)iVar11;

  *(uint16_t *)(iVar7 + 2 + iVar11 * 8) = (uint16_t)local_48;

  piVar1 = DAT_00b05060;

  uVar14 = local_18 * 2 + 0xfU & 0xfffffff0;

  if ((uVar14 == 0) || ((local_1c != DAT_00b05060[5] && (DAT_00b05060[5] != 0)))) {

    piVar12 = DAT_00b05060 + 3;

    DAT_00b05060[2] = DAT_00b05060[2] - uVar14;

    piVar1[3] = *piVar12 + uVar14;

  }

  else {

    (**(code **)(*DAT_00b05060 + 0x28))(local_1c,uVar14);

  }

  if (-1 < local_20) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_28[0],local_20 << 1,0x12);

  }

  piVar1 = DAT_00b05060;

  uVar14 = iStack_4 * 2 + 0xfU & 0xfffffff0;

  if ((uVar14 == 0) || ((iStack_8 != DAT_00b05060[5] && (DAT_00b05060[5] != 0)))) {

    piVar12 = DAT_00b05060 + 3;

    DAT_00b05060[2] = DAT_00b05060[2] - uVar14;

    piVar1[3] = *piVar12 + uVar14;

  }

  else {

    (**(code **)(*DAT_00b05060 + 0x28))(iStack_8,uVar14);

  }

  if (-1 < iStack_c) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_14[0],iStack_c << 1,0x12);

  }

  return;

}
