// =============================================================================
// FUN_00845030
// -----------------------------------------------------------------------------
// Stable ID: aa_00845030
// Address:   0x00845030  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00845030 @ 0x00845030
// Stable ID: aa_00845030
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~120 non-empty decompiler lines.
//  - Control keywords: if×20, return×18, do×1, while×1.
//  - Notable callees: CVOGReaction_ResolveSkillTargets×7, CONCAT22×2, FUN_00845030, Map_LowerBoundFindByCharKey, SkillSet_GetEntryCount, __RTDynamicCast.
//  - Return sites: 18.

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

uint32_t /* width from decompiler */ * __thiscall FUN_00845030(int param_1,int param_2)



{

  void *pvVar1;

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ extraout_EDX;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ extraout_EDX_00;

  char *unaff_EDI;

  uint uVar6;

  bool bVar7;

  uint8_t local_9;

  int local_8;

  int local_4;

  

  local_8 = 0;

  if ((in_EAX == 0) || (param_2 < 0)) {

    return (uint32_t /* width from decompiler */ *)0x0;

  }

  uVar5 = CONCAT22((short)((uint)unaff_EDI >> 0x10),*(uint16_t *)(in_EAX + 0x5f6));

  if (param_1 == 0) {

    if ((*(void **)(in_EAX + 0x150) != (void *)0x0) &&

       (puVar2 = CVOGReaction_ResolveSkillTargets(*(void **)(in_EAX + 0x150),uVar5),

       puVar2 != (uint32_t /* width from decompiler */ *)0x0)) {

      if (((puVar2[0x185] & 0x100) == 0) && (local_8 = 1, param_2 == 0)) {

        return puVar2;

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(puVar2);

    }

    if ((*(void **)(in_EAX + 0x154) != (void *)0x0) &&

       (puVar2 = CVOGReaction_ResolveSkillTargets(*(void **)(in_EAX + 0x154),uVar5),

       puVar2 != (uint32_t /* width from decompiler */ *)0x0)) {

      if (((puVar2[0x185] & 0x100) == 0) && (param_2 == 0)) {

        return puVar2;

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(puVar2);

    }

    if ((*(void **)(in_EAX + 0x158) != (void *)0x0) &&

       (puVar2 = CVOGReaction_ResolveSkillTargets(*(void **)(in_EAX + 0x158),uVar5),

       puVar2 != (uint32_t /* width from decompiler */ *)0x0)) {

      if (((puVar2[0x185] & 0x100) == 0) && (param_2 == 0)) {

        return puVar2;

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(puVar2);

    }

    if ((*(void **)(in_EAX + 0x15c) != (void *)0x0) &&

       (puVar2 = CVOGReaction_ResolveSkillTargets(*(void **)(in_EAX + 0x15c),uVar5),

       puVar2 != (uint32_t /* width from decompiler */ *)0x0)) {

      if (((puVar2[0x185] & 0x100) == 0) && (param_2 == 0)) {

        return puVar2;

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(puVar2);

    }

  }

  else {

    pvVar1 = *(void **)(*(int *)(param_1 + 0x3c) + 0x3bc);

    if ((pvVar1 != (void *)0xffffffff) &&

       (puVar2 = CVOGReaction_ResolveSkillTargets(pvVar1,uVar5), puVar2 != (uint32_t /* width from decompiler */ *)0x0)) {

      if (((puVar2[0x185] & 0x100) == 0) && (local_8 = 1, param_2 == 0)) {

        return puVar2;

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(puVar2);

    }

    pvVar1 = *(void **)(*(int *)(param_1 + 0x3c) + 0x3c0);

    if ((pvVar1 != (void *)0xffffffff) &&

       (puVar2 = CVOGReaction_ResolveSkillTargets(pvVar1,uVar5), puVar2 != (uint32_t /* width from decompiler */ *)0x0)) {

      if (((puVar2[0x185] & 0x100) == 0) && (local_8 = 1, param_2 == 0)) {

        return puVar2;

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(puVar2);

    }

    pvVar1 = *(void **)(*(int *)(param_1 + 0x3c) + 0x3c4);

    if ((pvVar1 != (void *)0xffffffff) &&

       (puVar2 = CVOGReaction_ResolveSkillTargets(pvVar1,uVar5), puVar2 != (uint32_t /* width from decompiler */ *)0x0)) {

      if (((puVar2[0x185] & 0x100) == 0) && (local_8 = 1, param_2 == 0)) {

        return puVar2;

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(puVar2);

    }

    iVar3 = __RTDynamicCast(*(uint32_t /* width from decompiler */ *)(param_1 + 0x3c),0,

                            &nsCloneStructs::SCloneBaseObject::RTTI_Type_Descriptor,

                            &nsCloneStructs::SCloneBaseCreature::RTTI_Type_Descriptor,0);

    if (iVar3 != 0) {

      local_9 = 2;

      Map_LowerBoundFindByCharKey((void *)(iVar3 + 0x51c),&local_4,&local_9,unaff_EDI);

      if ((local_4 != *(int *)(iVar3 + 0x520)) &&

         (uVar4 = SkillSet_GetEntryCount((void *)(local_4 + 0x10)), uVar4 != 0)) {

        iVar3 = 0;

        uVar6 = 0;

        uVar5 = extraout_EDX;

        do {

          puVar2 = CVOGReaction_ResolveSkillTargets

                             (*(void **)(iVar3 + *(int *)(local_4 + 0x14)),

                              CONCAT22((short)((uint)uVar5 >> 0x10),

                                       *(uint16_t *)(iVar3 + 8 + *(int *)(local_4 + 0x14))));

          if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

            if (((*(byte *)((int)puVar2 + 0x615) & 1) == 0) &&

               (bVar7 = local_8 == param_2, local_8 = local_8 + 1, bVar7)) {

              return puVar2;

            }

                    /* WARNING: Subroutine does not return */

            operator_delete(puVar2);

          }

          uVar6 = uVar6 + 1;

          iVar3 = iVar3 + 0x18;

          uVar5 = extraout_EDX_00;

        } while (uVar6 < uVar4);

      }

    }

  }

  return (uint32_t /* width from decompiler */ *)0x0;

}
