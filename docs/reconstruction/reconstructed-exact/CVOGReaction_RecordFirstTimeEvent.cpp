// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: CONCAT31, CVOGHBBase_Start, CVOGHBList_Enqueue, CVOGReaction_RecordFirstTimeEvent, FUN_0060b380, FUN_0060b410.
//  - Return sites: 2.

// =============================================================================
// CVOGReaction_RecordFirstTimeEvent
// -----------------------------------------------------------------------------
// Stable ID: aa_00522bc0
// Address:   0x00522bc0  (autoassault.exe, image base 0x400000)
// System:    unknown
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

uint __thiscall CVOGReaction_RecordFirstTimeEvent(int param_1,int param_2)



{

  uint uVar1;

  void *pvVar2;

  CVOGHBBase *pAction;

  void *local_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &DAT_009a380c;

  local_c = ExceptionList;

  uVar1 = *(uint *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);

  if ((*(char *)(uVar1 + 0x7e) != '\0') && (*(char *)(param_1 + 0xc7c) == '\0')) {

    ExceptionList = &local_c;

    if (*(int *)(param_1 + 0xca0) != 0) {

      ExceptionList = &local_c;

      FUN_0060b410(1);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0xca0) = 0;

    }

    *(bool *)(param_1 + 0xc7d) = *(float *)(param_2 + 0x260) != g_flZero;

    pvVar2 = operator_new(0x2c);

    local_4 = 0;

    if (pvVar2 == (void *)0x0) {

      pAction = (CVOGHBBase *)0x0;

    }

    else {

      pAction = (CVOGHBBase *)FUN_0060b380(param_2,param_1,*(uint32_t /* width from decompiler */ *)(param_2 + 0x25c));

    }

    *(CVOGHBBase **)(param_1 + 0xca0) = pAction;

    local_4 = 0xffffffff;

    CVOGHBList_Enqueue(*(void **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) +

                                 0xe4ec),pAction);

    CVOGHBBase_Start(*(CVOGHBBase **)(param_1 + 0xca0));

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc98) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c0);

    *(int *)(param_1 + 0xc9c) = param_2;

    *(uint8_t *)(param_1 + 0xc7c) = 1;

    ExceptionList = local_c;

    return CONCAT31((int3)((uint)*(uint32_t /* width from decompiler */ *)(param_1 + 0x6c0) >> 8),1);

  }

  return uVar1 & 0xffffff00;

}
