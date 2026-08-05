// =============================================================================
// Named_CalleeOf_CVOGCombat_OnDeathAwardKillXp_00508e70
// -----------------------------------------------------------------------------
// Stable ID: aa_00508e70
// Callee of CVOGCombat_OnDeathAwardKillXp
// Address:   0x00508e70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGCombat_OnDeathAwardKillXp: combat/reward helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×8, return×2.
//  - Notable callees: CVOGReaction_RandomUnitScalar×2, FUN_00508dc0, FUN_00508e70, ROUND, __allrem.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of CVOGCombat_OnDeathAwardKillXp
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

longlong Named_CalleeOf_CVOGCombat_OnDeathAwardKillXp_00508e70(int param_1,float param_2)



{

  ushort uVar1;

  uint16_t uVar2;

  longlong lVar3;

  int iVar4;

  int iVar5;

  float fVar6;

  longlong lVar7;

  

  iVar4 = FUN_00508dc0(param_2);

  if (iVar4 != 0) {

    param_2 = *(float *)(iVar4 + 0x38);

    fVar6 = 0.0;

    if (0.0 < param_2) {

      if (*(float *)(param_1 + 0xc60) <= g_flOne) {

        fVar6 = *(float *)(param_1 + 0xc60);

      }

      param_2 = fVar6 + param_2;

    }

    iVar5 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar5 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0xc) = 0;

    }

    uVar1 = *(ushort *)(*(int *)(iVar5 + 8) + *(int *)(iVar5 + 0xc) * 2);

    *(int *)(iVar5 + 0xc) = *(int *)(iVar5 + 0xc) + 1;

    if ((float)uVar1 * DAT_00aaa638 <= param_2) {

      iVar5 = *(int *)(iVar4 + 0x40) - *(int *)(iVar4 + 0x3c);

      lVar3 = (longlong)*(int *)(iVar4 + 0x3c);

      if ((-1 < iVar5 >> 0x1f) && ((iVar5 < 0 || (iVar5 != 0)))) {

        iVar4 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar4 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

        }

        uVar2 = *(uint16_t *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

        *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

        lVar7 = __allrem(uVar2,0,iVar5,iVar5 >> 0x1f);

        lVar3 = lVar7 + lVar3;

      }

      if (g_flOne < *(float *)(param_1 + 0xc64) || g_flOne == *(float *)(param_1 + 0xc64)) {

        fVar6 = *(float *)(param_1 + 0xc64);

      }

      else {

        fVar6 = (float)lVar3 * *(float *)(param_1 + 0xc64);

      }

      param_2 = (float)(int)ROUND(fVar6);

      return lVar3 + (int)param_2;

    }

  }

  return 0;

}
