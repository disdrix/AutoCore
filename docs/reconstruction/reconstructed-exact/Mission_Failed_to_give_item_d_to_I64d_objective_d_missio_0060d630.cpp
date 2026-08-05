// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×12, return×6.
//  - Notable callees: CVOGReaction_RemoveInventoryItem×2, FUN_005310a0×2, FUN_007a4480×2, S×2, CVOGReaction_GiveMission, FUN_004d0e90, FUN_0060d630.
//  - Return sites: 6.

// =============================================================================
// Mission_Failed_to_give_item_d_to_I64d_objective_d_missio_0060d630
// -----------------------------------------------------------------------------
// Stable ID: aa_0060d630
// Address:   0x0060d630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Failed to give item %d to %I64d, objective %d mission: %S(%d)"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Mission_Failed_to_give_item_d_to_I64d_objective_d_missio_0060d630(int *param_1,int param_2,int param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  char cVar3;

  int unaff_EBX;

  

  if (*(char *)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xa8 + param_2) + 0x7e) == '\0') {

    return 0;

  }

  cVar3 = (**(code **)(*param_1 + 8))(param_2,param_3);

  if (cVar3 != '\0') {

    return 0;

  }

  if (*(int *)(param_2 + 0x250) == 0) {

    return 0;

  }

  if (*(int *)(*(int *)(param_2 + 0x250) + 0x2b0) != 0) {

    if ((param_1[10] != -1) && (cVar3 = FUN_005310a0(param_1[10],1), cVar3 == '\0')) {

      puVar1 = *(uint32_t /* width from decompiler */ **)(param_1[1] + 0x14c);

      iVar2 = *(int *)(*(int *)(param_2 + 4) + 4);

      FUN_007a4480(1,"Failed to give item %d to %I64d, objective %d mission: %S(%d)",param_1[10],

                   *(uint32_t /* width from decompiler */ *)(iVar2 + 0x164 + param_2),*(uint32_t /* width from decompiler */ *)(iVar2 + 0x168 + param_2)

                   ,*(uint32_t /* width from decompiler */ *)(param_1[1] + 0x10),puVar1 + 1,*puVar1);

    }

    *(float *)(param_3 + 4 + (uint)*(byte *)(param_1 + 2) * 4) =

         *(float *)(param_3 + 4 + (uint)*(byte *)(param_1 + 2) * 4) + g_flOne;

    cVar3 = (**(code **)(*param_1 + 8))(param_2,param_3);

    if (((char)param_1[7] != '\0') && ((cVar3 != '\0' || (*(char *)((int)param_1 + 0x25) == '\0'))))

    {

      if (*(char *)((int)param_1 + 0x1d) == '\0') {

        CVOGReaction_RemoveInventoryItem(*(uint32_t /* width from decompiler */ *)(*(int *)(unaff_EBX + 0xa8) + 0x34),1);

      }

      else {

        *(uint *)(unaff_EBX + 0xcc) = (*(char *)((int)param_1 + 0x26) != '\0') + 1;

        FUN_004d0e90(unaff_EBX);

      }

    }

    if ((char)param_1[0xc] != '\0') {

      if ((cVar3 == '\0') && (*(char *)((int)param_1 + 0x32) != '\0')) {

        return 1;

      }

      CVOGReaction_RemoveInventoryItem(param_1[0xb],1);

    }

    if (cVar3 != '\0') {

      if (param_1[0x13] != -1) {

        CVOGReaction_GiveMission(param_1[0x13]);

      }

      if ((param_1[0x12] != -1) && (cVar3 = FUN_005310a0(param_1[0x12],1), cVar3 == '\0')) {

        puVar1 = *(uint32_t /* width from decompiler */ **)(param_1[1] + 0x14c);

        iVar2 = *(int *)(*(int *)(param_2 + 4) + 4);

        FUN_007a4480(1,"Failed to give item %d to %I64d, objective %d mission: %S(%d)",param_1[0x12]

                     ,*(uint32_t /* width from decompiler */ *)(iVar2 + 0x164 + param_2),

                     *(uint32_t /* width from decompiler */ *)(iVar2 + 0x168 + param_2),*(uint32_t /* width from decompiler */ *)(param_1[1] + 0x10),

                     puVar1 + 1,*puVar1);

      }

    }

    return 1;

  }

  return 0;

}
