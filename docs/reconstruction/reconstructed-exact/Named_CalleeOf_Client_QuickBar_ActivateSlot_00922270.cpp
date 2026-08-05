// =============================================================================
// Named_CalleeOf_Client_QuickBar_ActivateSlot_00922270
// -----------------------------------------------------------------------------
// Stable ID: aa_00922270
// Callee of Client_QuickBar_ActivateSlot (+1 other named callers)
// Address:   0x00922270  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_QuickBar_ActivateSlot: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_QuickBar_ActivateSlot (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, return×1, goto×1, while×1.
//  - Notable callees: Client_CastSkillFromQuickBarSlot, Client_MaybeShowFirstTimeTip, FUN_004f50d0, FUN_004f5290, FUN_0089ff80, FUN_00922270, Skill_GetCategoryCooldownRemaining.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_QuickBar_ActivateSlot (+1 other named callers)
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

void Named_CalleeOf_Client_QuickBar_ActivateSlot_00922270(void)



{

  int iVar1;

  char cVar2;

  uint uVar3;

  int iVar4;

  int iVar5;

  uint32_t /* width from decompiler */ unaff_EDI;

  float10 extraout_ST0;

  

  uVar3 = 0;

  iVar4 = 0;

  iVar5 = DAT_00d1b6d8;

  do {

    if ((*(int *)(iVar5 + 0x550) == 0) ||

       ((uint)((*(int *)(iVar5 + 0x554) - *(int *)(iVar5 + 0x550)) / 0xc) <= uVar3)) {

      if (((iVar5 != 0) &&

          ((*(byte *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0xb8 + iVar5) & 0xd2) == 0)) &&

         ((g_pSectorNetConnection_INFERRED != (void *)0x0 &&

          ((cVar2 = (**(code **)(*(int *)g_pSectorNetConnection_INFERRED + 8))(), cVar2 != '\0' &&

           (*(int *)(DAT_00d1b6d8 + 0x250) != 0)))))) {

        Client_MaybeShowFirstTimeTip(0x12);

        cVar2 = FUN_004f5290();

        if (cVar2 != '\0') {

          FUN_004f50d0();

LAB_00922371:

          if ((((*(char *)(DAT_00d1b6d8 + 0x6b8) != '\0') ||

               (*(char *)(DAT_00d1b6d8 + 0x6b9) != '\0')) && (DAT_00d1b8f0 != (int *)0x0)) &&

             (cVar2 = (**(code **)(*DAT_00d1b8f0 + 0x3d8))(), cVar2 != '\0')) {

            FUN_0089ff80();

          }

        }

      }

      return;

    }

    iVar1 = *(int *)(*(int *)(iVar5 + 0x550) + iVar4);

    if ((*(char *)(*(int *)(iVar5 + 0x550) + iVar4 + 8) != '\0') &&

       ((((*(byte *)(iVar1 + 0x615) & 1) == 0 && (*(char *)(iVar1 + 0x628) == '\0')) &&

        (Skill_GetCategoryCooldownRemaining(*(float10 **)(iVar1 + 0x5e8),1,(char)unaff_EDI),

        iVar5 = DAT_00d1b6d8, (float10)g_flZero == extraout_ST0)))) {

      Client_CastSkillFromQuickBarSlot(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x5fc));

      goto LAB_00922371;

    }

    uVar3 = uVar3 + 1;

    iVar4 = iVar4 + 0xc;

  } while( true );

}
