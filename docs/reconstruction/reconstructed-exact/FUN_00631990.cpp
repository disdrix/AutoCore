// =============================================================================
// FUN_00631990
// -----------------------------------------------------------------------------
// Stable ID: aa_00631990
// Address:   0x00631990  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00631990 @ 0x00631990
// Stable ID: aa_00631990
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~198 non-empty decompiler lines.
//  - Control keywords: if×16, do×6, while×6, for×1, return×1.
//  - Notable callees: FUN_0062ccf0×3, FUN_005b3300, FUN_0062ed90, FUN_00631990.
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

void __thiscall FUN_00631990(int param_1,int *param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  uint uVar6;

  int *piVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ *puVar9;

  int iVar10;

  int iVar11;

  int iVar12;

  uint uVar13;

  int iStack_38;

  uint32_t /* width from decompiler */ uStack_30;

  uint local_2c;

  int local_28;

  int iStack_24;

  uint uStack_20;

  uint uStack_1c;

  int iStack_18;

  uint uStack_14;

  

  piVar7 = DAT_00b05060;

  iVar3 = param_2[1];

  uVar6 = *(uint *)(param_1 + 0x44);

  piVar2 = DAT_00b05060 + 3;

  uVar13 = (((int)uVar6 >> 5) + 8) * 4 + 0xfU & 0xfffffff0;

  local_2c = uVar6;

  local_28 = param_1;

  if (*piVar2 < (int)uVar13) {

    puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(*DAT_00b05060 + 0x24))(uVar13);

  }

  else {

    puVar4 = (uint32_t /* width from decompiler */ *)DAT_00b05060[2];

    DAT_00b05060[2] = (int)puVar4 + uVar13;

    piVar7[3] = *piVar2 - uVar13;

  }

  iVar10 = local_28;

  puVar9 = puVar4;

  if (-1 < (int)uVar6 >> 7) {

    iVar11 = ((int)uVar6 >> 7) + 1;

    puVar8 = puVar4;

    do {

      puVar9 = puVar8 + 4;

      iVar11 = iVar11 + -1;

      *puVar8 = 0;

      puVar8[1] = 0;

      puVar8[2] = 0;

      puVar8[3] = 0;

      puVar8 = puVar9;

    } while (iVar11 != 0);

  }

  iVar11 = 0;

  if (0 < iVar3) {

    do {

      uVar6 = **(uint **)(*param_2 + iVar11 * 4);

      puVar9 = (uint32_t /* width from decompiler */ *)(uVar6 & 0x1f);

      iVar11 = iVar11 + 1;

      puVar4[(int)uVar6 >> 5] = puVar4[(int)uVar6 >> 5] ^ 1 << (sbyte)puVar9;

    } while (iVar11 < iVar3);

  }

  FUN_0062ed90(puVar4,param_3,(uint)puVar9 & 0xffffff00);

  piVar2 = DAT_00b05060;

  if ((uVar13 == 0) ||

     ((puVar4 != (uint32_t /* width from decompiler */ *)DAT_00b05060[5] &&

      ((uint32_t /* width from decompiler */ *)DAT_00b05060[5] != (uint32_t /* width from decompiler */ *)0x0)))) {

    DAT_00b05060[2] = DAT_00b05060[2] - uVar13;

    piVar2[3] = piVar2[3] + uVar13;

  }

  else {

    (**(code **)(*DAT_00b05060 + 0x28))(puVar4,uVar13);

  }

  uVar6 = local_2c;

  iVar11 = 0;

  uStack_30 = 0;

  if (0 < iVar3) {

    do {

      *(uint32_t /* width from decompiler */ **)(*(int *)(iVar10 + 0x40) + 0x18 + **(int **)(*param_2 + iVar11 * 4) * 0x1c) =

           &uStack_30;

      iVar5 = iVar11 * 4;

      iVar11 = iVar11 + 1;

      **(uint32_t /* width from decompiler */ **)(*param_2 + iVar5) = 0;

    } while (iVar11 < iVar3);

  }

  piVar7 = DAT_00b05060;

  piVar2 = DAT_00b05060 + 3;

  uVar13 = local_2c * 4 + 0xf & 0xfffffff0;

  if (*piVar2 < (int)uVar13) {

    iVar11 = (**(code **)(*DAT_00b05060 + 0x24))(uVar13);

  }

  else {

    iVar11 = DAT_00b05060[2];

    DAT_00b05060[2] = iVar11 + uVar13;

    piVar7[3] = *piVar2 - uVar13;

  }

  uStack_1c = uVar6 | 0x80000000;

  iVar5 = uVar6 - 1;

  iVar12 = 0;

  uStack_14 = uVar6;

  uStack_20 = uVar6;

  if (-1 < iVar5) {

    iStack_38 = iVar5 * 0x1c;

    local_2c = 0;

    do {

      puVar4 = (uint32_t /* width from decompiler */ *)(iStack_38 + *(int *)(iVar10 + 0x40));

      if ((uint32_t /* width from decompiler */ *)puVar4[6] == &uStack_30) {

        *(uint32_t /* width from decompiler */ *)(iVar11 + iVar5 * 4) = 0xffffffff;

        iVar5 = iVar5 + -1;

        iStack_38 = iStack_38 + -0x1c;

      }

      else {

        puVar9 = (uint32_t /* width from decompiler */ *)(local_2c + *(int *)(iVar10 + 0x40));

        if ((uint32_t /* width from decompiler */ *)puVar9[6] == &uStack_30) {

          puVar8 = puVar9;

          for (iVar10 = 7; iVar10 != 0; iVar10 = iVar10 + -1) {

            *puVar8 = *puVar4;

            puVar4 = puVar4 + 1;

            puVar8 = puVar8 + 1;

          }

          *(int *)(iVar11 + iVar5 * 4) = iVar12;

          *(uint32_t /* width from decompiler */ *)(iVar11 + iVar12 * 4) = 0xffffffff;

          piVar2 = (int *)puVar9[6];

          if (((uint)piVar2 & 1) == 0) {

            iVar5 = iVar5 + -1;

            iStack_38 = iStack_38 + -0x1c;

            *piVar2 = iVar12;

          }

          else {

            iVar5 = iVar5 + -1;

            iStack_38 = iStack_38 + -0x1c;

            *(int *)(((uint)piVar2 & 0xfffffffe) + *(int *)(local_28 + 0x78)) = iVar12;

          }

        }

        else {

          *(int *)(iVar11 + iVar12 * 4) = iVar12;

        }

        iVar12 = iVar12 + 1;

        local_2c = local_2c + 0x1c;

        iVar10 = local_28;

      }

    } while (iVar12 <= iVar5);

  }

  local_2c = iVar5 + 1;

  puVar4 = (uint32_t /* width from decompiler */ *)(iVar10 + 0x40);

  uVar6 = *(uint *)(iVar10 + 0x48) & 0x7fffffff;

  iStack_24 = iVar11;

  iStack_18 = iVar11;

  if ((int)uVar6 < (int)local_2c) {

    iVar5 = uVar6 * 2;

    if (iVar5 <= (int)local_2c) {

      iVar5 = local_2c;

    }

    FUN_005b3300(puVar4,iVar5,0x1c);

  }

  *(uint *)(iVar10 + 0x44) = local_2c;

  FUN_0062ccf0(*puVar4,0,&iStack_24);

  FUN_0062ccf0(*puVar4,1,&iStack_24);

  FUN_0062ccf0(*puVar4,2,&iStack_24);

  if ((*(int *)(iVar10 + 0x70) != 0) && (local_2c = 0, 0 < *(int *)(iVar10 + 0x70))) {

    local_28 = 0;

    do {

      piVar7 = (int *)(*(int *)(iVar10 + 0x78) + local_28);

      iVar5 = *piVar7;

      iVar12 = *(int *)(iVar10 + 0x40);

      piVar2 = (int *)(iVar12 + 8 + iVar5 * 0x1c);

      *piVar2 = *piVar2 + iVar3 * -2;

      piVar2 = (int *)(iVar12 + 0xc + iVar5 * 0x1c);

      *piVar2 = *piVar2 + iVar3 * -2;

      iVar5 = 0;

      if (0 < piVar7[3]) {

        do {

          iVar12 = iVar5 * 4;

          iVar1 = iVar5 * 4;

          iVar5 = iVar5 + 1;

          *(uint32_t /* width from decompiler */ *)(piVar7[2] + iVar1) =

               *(uint32_t /* width from decompiler */ *)(iVar11 + *(int *)(piVar7[2] + iVar12) * 4);

        } while (iVar5 < piVar7[3]);

      }

      local_28 = local_28 + 0x14;

      local_2c = local_2c + 1;

    } while ((int)local_2c < *(int *)(iVar10 + 0x70));

  }

  piVar2 = DAT_00b05060;

  uVar6 = uStack_14 * 4 + 0xf & 0xfffffff0;

  if ((uVar6 == 0) || ((iVar11 != DAT_00b05060[5] && (DAT_00b05060[5] != 0)))) {

    DAT_00b05060[2] = DAT_00b05060[2] - uVar6;

    piVar2[3] = piVar2[3] + uVar6;

  }

  else {

    (**(code **)(*DAT_00b05060 + 0x28))(iVar11,uVar6);

  }

  if (-1 < (int)uStack_1c) {

    (**(code **)(*DAT_00b05060 + 0x14))(iVar11,uStack_1c * 4,0x12);

  }

  return;

}
