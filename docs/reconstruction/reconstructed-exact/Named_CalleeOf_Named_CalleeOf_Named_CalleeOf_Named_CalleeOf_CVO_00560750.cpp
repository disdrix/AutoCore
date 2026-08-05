// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO_00560750
// -----------------------------------------------------------------------------
// Stable ID: aa_00560750
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_Set
// Address:   0x00560750  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_Set: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~151 non-empty decompiler lines.
//  - Control keywords: if×14, do×4, while×4, goto×1, return×1.
//  - Notable callees: FUN_005b3300×3, FUN_0055f520, FUN_00560750.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_Set
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO_00560750(int *param_1)



{

  uint uVar1;

  int *piVar2;

  int *in_EAX;

  int iVar3;

  int *piVar4;

  int iVar5;

  int *piVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int iVar8;

  uint32_t /* width from decompiler */ *puVar9;

  int local_28;

  int local_24;

  int local_20;

  int local_1c;

  int local_18;

  int local_14;

  int local_10;

  uint local_c;

  int local_8;

  int local_4;

  

  piVar2 = param_1;

  FUN_0055f520(in_EAX[1]);

  local_10 = in_EAX[1];

  if ((int)(local_c & 0x7fffffff) < local_10) {

    iVar3 = (local_c & 0x7fffffff) * 2;

    if (iVar3 <= local_10) {

      iVar3 = local_10;

    }

    FUN_005b3300(&local_14,iVar3,0x10);

  }

  if (0 < in_EAX[1]) {

    iVar3 = 0;

    iVar5 = 0;

    do {

      puVar9 = (uint32_t /* width from decompiler */ *)(*in_EAX + iVar3);

      puVar7 = (uint32_t /* width from decompiler */ *)(local_14 + iVar3);

      *puVar7 = *puVar9;

      puVar7[1] = puVar9[1];

      puVar7[2] = puVar9[2];

      iVar5 = iVar5 + 1;

      puVar7[3] = puVar9[3];

      iVar3 = iVar3 + 0x10;

    } while (iVar5 < in_EAX[1]);

  }

  iVar3 = in_EAX[1];

  iVar5 = param_1[1];

  if ((int)(in_EAX[2] & 0x7fffffffU) < iVar3 + iVar5) {

    FUN_005b3300();

  }

  iVar8 = 0;

  in_EAX[1] = iVar3 + iVar5;

  local_28 = 0;

  local_24 = 0;

  local_18 = 0;

  if (0 < local_10) {

    iVar3 = 0;

    local_20 = 0;

    local_1c = 0;

    do {

      if (param_1[1] <= iVar8) break;

      piVar4 = (int *)(local_20 + *param_1);

      uVar1 = *(uint *)(*(int *)(local_14 + local_1c) + 4);

      piVar6 = (int *)(local_14 + local_1c);

      if ((uVar1 < *(uint *)(*piVar4 + 4)) ||

         ((uVar1 == *(uint *)(*piVar4 + 4) && (*(uint *)(piVar6[1] + 4) < *(uint *)(piVar4[1] + 4)))

         )) {

        local_1c = local_1c + 0x10;

        piVar4 = (int *)(*in_EAX + iVar3);

        *piVar4 = *piVar6;

        piVar4[1] = piVar6[1];

        piVar4[2] = piVar6[2];

        piVar4[3] = piVar6[3];

        local_28 = local_28 + 1;

LAB_005608f1:

        local_24 = local_24 + 1;

        iVar3 = iVar3 + 0x10;

      }

      else {

        if ((*(int *)(*piVar6 + 4) != *(int *)(*piVar4 + 4)) ||

           (*(int *)(piVar6[1] + 4) != *(int *)(piVar4[1] + 4))) {

          local_20 = local_20 + 0x10;

          piVar6 = (int *)(*in_EAX + iVar3);

          *piVar6 = *piVar4;

          piVar6[1] = piVar4[1];

          piVar6[2] = piVar4[2];

          iVar8 = iVar8 + 1;

          piVar6[3] = piVar4[3];

          goto LAB_005608f1;

        }

        piVar6 = (int *)((int *)piVar4[2])[2];

        (**(code **)(*(int *)piVar4[2] + 0x14))();

        (**(code **)(*piVar6 + 0x10))();

        local_20 = local_20 + 0x10;

        iVar8 = iVar8 + 1;

        local_18 = local_18 + 1;

      }

    } while (local_28 < local_10);

  }

  iVar3 = (local_10 - local_18) + param_1[1];

  if ((int)(in_EAX[2] & 0x7fffffffU) < iVar3) {

    FUN_005b3300();

  }

  in_EAX[1] = iVar3;

  if (local_28 == local_10) {

    if (iVar8 < param_1[1]) {

      param_1 = (int *)(local_24 << 4);

      iVar3 = iVar8 << 4;

      do {

        puVar9 = (uint32_t /* width from decompiler */ *)(*in_EAX + (int)param_1);

        param_1 = (int *)((int)param_1 + 0x10);

        puVar7 = (uint32_t /* width from decompiler */ *)(*piVar2 + iVar3);

        *puVar9 = *puVar7;

        puVar9[1] = puVar7[1];

        puVar9[2] = puVar7[2];

        iVar8 = iVar8 + 1;

        puVar9[3] = puVar7[3];

        iVar3 = iVar3 + 0x10;

      } while (iVar8 < piVar2[1]);

    }

  }

  else if (local_28 < local_10) {

    local_24 = local_24 << 4;

    iVar3 = local_28 << 4;

    do {

      puVar9 = (uint32_t /* width from decompiler */ *)(local_14 + iVar3);

      puVar7 = (uint32_t /* width from decompiler */ *)(*in_EAX + local_24);

      *puVar7 = *puVar9;

      puVar7[1] = puVar9[1];

      puVar7[2] = puVar9[2];

      local_28 = local_28 + 1;

      puVar7[3] = puVar9[3];

      iVar3 = iVar3 + 0x10;

      local_24 = local_24 + 0x10;

    } while (local_28 < local_10);

  }

  piVar2 = DAT_00b05060;

  iVar3 = local_4 * 0x10;

  if ((iVar3 == 0) || ((local_8 != DAT_00b05060[5] && (DAT_00b05060[5] != 0)))) {

    DAT_00b05060[2] = DAT_00b05060[2] + local_4 * -0x10;

    piVar2[3] = piVar2[3] + iVar3;

  }

  else {

    (**(code **)(*DAT_00b05060 + 0x28))(local_8,iVar3);

  }

  if (-1 < (int)local_c) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_14,local_c << 4,0x12);

  }

  return;

}
