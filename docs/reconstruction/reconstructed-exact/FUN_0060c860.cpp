// =============================================================================
// FUN_0060c860
// -----------------------------------------------------------------------------
// Stable ID: aa_0060c860
// Address:   0x0060c860  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0060c860 @ 0x0060c860
// Stable ID: aa_0060c860
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×6, return×3.
//  - Notable callees: CONCAT22, CVOGHBBase_Start, CVOGHBList_Enqueue, FUN_0060c860, FUN_006507c0.
//  - Return sites: 3.

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

uint __thiscall FUN_0060c860(int param_1,int param_2,int param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint uVar3;

  void *pvVar4;

  CVOGHBBase *pAction;

  void *local_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &DAT_009a8365;

  local_c = ExceptionList;

  uVar3 = *(uint *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xa8 + param_2);

  if ((*(char *)(uVar3 + 0x7e) != '\0') && (*(int *)(param_1 + 0x40) == *(int *)(uVar3 + 0xfc))) {

    ExceptionList = &local_c;

    puVar1 = CVOGReaction_ResolveSkillTargets

                       (*(void **)(param_1 + 0x10),

                        CONCAT22((short)(uVar3 >> 0x10),*(uint16_t *)(param_1 + 0x14)));

    uVar3 = 0;

    if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

      if (*(char *)(param_1 + 0x20) != '\0') {

        iVar2 = *(int *)(*(int *)(param_2 + 4) + 4) + param_2 + 4;

        iVar2 = CVOGReaction_CastSkillOnTarget

                          (puVar1,iVar2,iVar2,1,0,&DAT_00d02a90,0,0xffffffff,0,0);

        if (iVar2 != 0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(puVar1);

        }

      }

      *(float *)(param_3 + 4 + (uint)*(byte *)(param_1 + 8) * 4) = g_flOne;

      if (((g_flZero < *(float *)(param_1 + 0x1c)) || (*(char *)(param_1 + 0x18) != '\0')) &&

         (puVar1[0x53] != -1)) {

        pvVar4 = operator_new(0x78);

        local_4 = 0;

        if (pvVar4 == (void *)0x0) {

          pAction = (CVOGHBBase *)0x0;

        }

        else {

          pAction = (CVOGHBBase *)FUN_006507c0(param_2,param_1);

        }

        local_4 = 0xffffffff;

        CVOGHBList_Enqueue(*(void **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xa8 + param_2)

                                     + 0xe4ec),pAction);

        CVOGHBBase_Start(pAction);

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(puVar1);

    }

  }

  ExceptionList = local_c;

  return uVar3 & 0xffffff00;

}
