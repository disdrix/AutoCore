// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_Uses_Client_GetMissionCom_00968110
// -----------------------------------------------------------------------------
// Stable ID: aa_00968110
// Callee of Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable
// Address:   0x00968110  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: return×3, if×2, for×1.
//  - Notable callees: FUN_00456570, FUN_00968110.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable
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

void Named_CalleeOf_Named_CalleeOf_Mission_Uses_Client_GetMissionCom_00968110(int param_1)



{

  int iVar1;

  void *pvVar2;

  void *pvVar3;

  uint uVar4;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  pvVar3 = ExceptionList;

  puStack_8 = &LAB_009b0873;

  local_c = ExceptionList;

  local_4 = 0;

  for (uVar4 = 0;

      (iVar1 = *(int *)(param_1 + 0x10), iVar1 != 0 &&

      (uVar4 < (uint)(*(int *)(param_1 + 0x14) - iVar1 >> 2))); uVar4 = uVar4 + 1) {

    pvVar2 = *(void **)(iVar1 + uVar4 * 4);

    if (pvVar2 != (void *)0x0) {

      ExceptionList = &local_c;

      FUN_00456570(pvVar2);

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar2);

    }

  }

  ExceptionList = &local_c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  if (*(void **)(param_1 + 0x10) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x10));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

  ExceptionList = pvVar3;

  return;

}
