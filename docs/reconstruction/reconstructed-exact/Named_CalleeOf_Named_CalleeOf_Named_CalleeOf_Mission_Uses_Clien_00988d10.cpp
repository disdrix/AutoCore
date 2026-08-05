// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_Uses_Clien_00988d10
// -----------------------------------------------------------------------------
// Stable ID: aa_00988d10
// Callee of Named_CalleeOf_Named_CalleeOf_Mission_Uses_Client_GetMissionCom
// Address:   0x00988d10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Mission_Uses_Client_GetMissionCom: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~95 non-empty decompiler lines.
//  - Control keywords: if×9, return×3, for×2.
//  - Notable callees: FUN_0044b8b0×2, FUN_0044c150, FUN_00743be0, FUN_00985b40, FUN_00988d10.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Mission_Uses_Client_GetMissionCom
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_Uses_Clien_00988d10(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint uVar6;

  uint uVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ *local_4;

  

  puVar3 = (uint32_t /* width from decompiler */ *)FUN_0044c150();

  if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    puVar3[1] = 0;

    puVar3[2] = 0;

    puVar3[3] = 0;

    *puVar3 = &PTR_FUN_00aa213c;

    puVar3[4] = 0;

    puVar3[5] = 2;

    puVar3[6] = 0;

    puVar3[7] = 0;

    puVar3[8] = 0;

    puVar3[9] = 0;

  }

  puVar3[7] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c);

  puVar3[8] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x20);

  puVar3[5] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x14);

  if (*(int *)(param_1 + 0x10) == 0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = param_2;

    return puVar3;

  }

  iVar4 = FUN_00985b40(DAT_00d1f648,puVar3,*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x10) + 8));

  if (iVar4 < 0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = param_2;

    return puVar3;

  }

  if (*(int *)(param_1 + 0x10) == 0) {

    puVar8 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    puVar8 = (uint32_t /* width from decompiler */ *)

             FUN_00743be0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),*(uint32_t /* width from decompiler */ *)(param_1 + 0x1c),0x810);

  }

  piVar1 = (int *)puVar3[4];

  if (piVar1 == (int *)0x0) {

    puVar5 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    piVar2 = (int *)*piVar1;

    local_4 = (uint32_t /* width from decompiler */ *)puVar3[7];

    if (piVar2 == (int *)0x0) {

      puVar5 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      iVar4 = (**(code **)(*piVar2 + 0x2c))

                        (piVar2,piVar1[4] * puVar3[6],piVar1[4] * (int)local_4,&local_4,0x800);

      if (iVar4 < 0) {

        puVar5 = (uint32_t /* width from decompiler */ *)0x0;

      }

      else {

        piVar1[3] = piVar1[3] + 1;

        puVar5 = local_4;

      }

    }

  }

  if ((puVar8 != (uint32_t /* width from decompiler */ *)0x0) && (puVar5 != (uint32_t /* width from decompiler */ *)0x0)) {

    uVar6 = *(int *)(param_1 + 0x1c) * *(int *)(param_1 + 0x14);

    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

      *puVar5 = *puVar8;

      puVar8 = puVar8 + 1;

      puVar5 = puVar5 + 1;

    }

    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

      *(uint8_t *)puVar5 = *(uint8_t *)puVar8;

      puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

      puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

    }

  }

  FUN_0044b8b0();

  FUN_0044b8b0();

  iVar4 = DAT_00d1f614;

  if (DAT_00d1f614 != 0) {

    *(int *)(DAT_00d1f614 + 0x390) =

         *(int *)(DAT_00d1f614 + 0x390) + *(int *)(param_1 + 0x1c) * *(int *)(param_1 + 0x14);

    piVar1 = (int *)(iVar4 + 0x348);

    *piVar1 = *piVar1 + *(int *)(param_1 + 0x1c);

    piVar1 = (int *)(iVar4 + 0x344);

    *piVar1 = *piVar1 + 1;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = param_2;

  return puVar3;

}
