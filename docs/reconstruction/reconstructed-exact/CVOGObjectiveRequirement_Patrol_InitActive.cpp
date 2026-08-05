// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: CVOGHBBase_Start, CVOGHBList_Enqueue, CVOGObjectiveRequirement_Patrol_InitActive, FUN_004de760, FUN_00650d30.
//  - Return sites: 1.

// =============================================================================
// CVOGObjectiveRequirement_Patrol_InitActive
// -----------------------------------------------------------------------------
// Stable ID: aa_0060e3d0
// Address:   0x0060e3d0  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

void __thiscall CVOGObjectiveRequirement_Patrol_InitActive(int param_1,int param_2)



{

  void *pvVar1;

  CVOGHBBase *pAction;

  void *local_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &DAT_009a83eb;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_004de760(param_2,0);

  if ((*(char *)(param_1 + 0x18) != '\0') &&

     (*(char *)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xa8 + param_2) + 0x7e) != '\0')) {

    pvVar1 = operator_new(0x40);

    local_4 = 0;

    if (pvVar1 == (void *)0x0) {

      pAction = (CVOGHBBase *)0x0;

    }

    else {

      pAction = (CVOGHBBase *)FUN_00650d30(param_2,param_1);

    }

    local_4 = 0xffffffff;

    CVOGHBList_Enqueue(*(void **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xa8 + param_2) +

                                 0xe4ec),pAction);

    CVOGHBBase_Start(pAction);

  }

  ExceptionList = local_c;

  return;

}
