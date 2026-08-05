// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_004cef70
// -----------------------------------------------------------------------------
// Stable ID: aa_004cef70
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x004cef70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×7, return×1.
//  - Notable callees: FUN_004c3120, FUN_004c3140, FUN_004c4dd0, FUN_004cef70.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
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

float10 Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_004cef70(int *param_1,int *param_2)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  float10 fVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uStack_8;

  

  piVar1 = param_1;

  iVar2 = (**(code **)(*param_1 + 0x27c))();

  uStack_8 = 0;

  if (param_2 != (int *)0x0) {

    iVar3 = (**(code **)(*param_2 + 0x1d4))();

    if (iVar3 != 0) {

      uStack_8 = 1;

    }

  }

  (**(code **)(*param_1 + 0x1d4))();

  iVar3 = (**(code **)(*param_1 + 0x214))();

  if (iVar3 == 0) {

    param_1 = (int *)((float)iVar2 * g_flMsToSeconds_Inferred * DAT_00a0f704 +

                     g_flKillSpreeBonusPerStack);

  }

  else {

    (**(code **)(*param_1 + 0x214))();

    fVar4 = (float10)FUN_004c4dd0();

    param_1 = (int *)(float)fVar4;

  }

  iVar2 = (**(code **)(*piVar1 + 0x214))();

  if (iVar2 != 0) {

    uVar5 = 1;

    (**(code **)(*piVar1 + 0x214))(1);

    fVar4 = (float10)FUN_004c3140(uVar5);

    param_1 = (int *)(float)(fVar4 + (float10)(float)param_1);

  }

  if (param_2 != (int *)0x0) {

    iVar2 = (**(code **)(*param_2 + 0x214))();

    if (iVar2 != 0) {

      (**(code **)(*param_2 + 0x214))(uStack_8);

      fVar4 = (float10)FUN_004c3120(uStack_8);

      param_1 = (int *)(float)((float10)(float)param_1 - fVar4);

    }

  }

  if ((float)param_1 < 0.0) {

    param_1 = (int *)g_flKillSpreeBonusPerStack;

  }

  return (float10)(float)param_1;

}
