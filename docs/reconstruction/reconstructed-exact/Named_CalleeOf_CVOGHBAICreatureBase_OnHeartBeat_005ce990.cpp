// =============================================================================
// Named_CalleeOf_CVOGHBAICreatureBase_OnHeartBeat_005ce990
// -----------------------------------------------------------------------------
// Stable ID: aa_005ce990
// Callee of CVOGHBAICreatureBase_OnHeartBeat
// Address:   0x005ce990  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGHBAICreatureBase_OnHeartBeat: creature/setup helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~77 non-empty decompiler lines.
//  - Control keywords: if×7, return×2.
//  - Notable callees: SQRT×3, CVOGReaction_TeleportTarget, CVOGWaypoint_UpdateState, FUN_004c55e0, FUN_004cd220, FUN_005ce990.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of CVOGHBAICreatureBase_OnHeartBeat
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_CVOGHBAICreatureBase_OnHeartBeat_005ce990(int param_1)



{

  uint uVar1;

  float *pfVar2;

  void *this;

  int iVar3;

  float10 fVar4;

  float10 fVar5;

  float fVar6;

  float fStack_38;

  float fStack_30;

  float fStack_2c;

  float fStack_28;

  float fStack_24;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  float fStack_14;

  

  iVar3 = *(int *)(*(int *)(param_1 + 100) + 0x250);

  if (iVar3 == 0) {

    iVar3 = *(int *)(*(int *)(param_1 + 100) + 0xf8);

  }

  else {

    iVar3 = *(int *)(iVar3 + 0xf8);

  }

  if ((iVar3 != 0) && (CVOGWaypoint_UpdateState(), *(char *)(iVar3 + 0x52) != '\0')) {

    if (*(int *)(param_1 + 0x68) != 0) {

      pfVar2 = (float *)(**(code **)(**(int **)(param_1 + 0x18) + 0x1a0))();

      uVar1 = g_dwClientTickMs;

      fStack_30 = *pfVar2;

      fStack_2c = pfVar2[1];

      fStack_28 = pfVar2[2];

      fStack_20 = *(float *)(iVar3 + 0x20) - fStack_30;

      fStack_1c = *(float *)(iVar3 + 0x24) - fStack_2c;

      fStack_18 = *(float *)(iVar3 + 0x28) - fStack_28;

      fVar6 = fStack_18 * fStack_18 + fStack_1c * fStack_1c + fStack_20 * fStack_20;

      fStack_24 = pfVar2[3];

      if (fVar6 == 0.0) {

        fStack_14 = 0.0;

      }

      else {

        fStack_14 = g_flOne / SQRT(fVar6);

      }

      fStack_20 = fStack_14 * fStack_20;

      fStack_1c = fStack_1c * fStack_14;

      fStack_18 = fStack_18 * fStack_14;

      fStack_14 = (*(float *)(iVar3 + 0x2c) - fStack_24) * fStack_14;

      fVar4 = (float10)FUN_004c55e0();

      iVar3 = uVar1 - *(int *)(param_1 + 0x68);

      fVar5 = (float10)iVar3;

      if (iVar3 < 0) {

        fVar5 = fVar5 + (float10)_DAT_00aaa5dc;

      }

      fStack_38 = (float)(fVar5 * (float10)g_flMsToSeconds_Inferred * fVar4 * (float10)DAT_00a0f298)

      ;

      if (SQRT(fVar6) < fStack_38) {

        fStack_38 = SQRT(fVar6);

      }

      fStack_2c = fStack_1c * fStack_38 + fStack_2c;

      fStack_30 = fStack_20 * fStack_38 + fStack_30;

      fStack_24 = fStack_14 * fStack_38 + fStack_24;

      fStack_28 = fStack_18 * fStack_38 + fStack_28;

      fVar4 = (float10)FUN_004cd220(fStack_30,fStack_28);

      if (fStack_2c < (float)(fVar4 + (float10)g_flOne)) {

        fStack_2c = (float)(fVar4 + (float10)g_flOne);

      }

      pfVar2 = &fStack_30;

      this = (void *)(**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 100) + 4) + 4) + 4 +

                                          *(int *)(param_1 + 100)) + 0x19c))();

      CVOGReaction_TeleportTarget(this,pfVar2);

    }

    *(uint *)(param_1 + 0x68) = g_dwClientTickMs;

    return 1;

  }

  return 0;

}
