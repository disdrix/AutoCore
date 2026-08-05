// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_Uses_Client_GetMissionCom_0096d7a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0096d7a0
// Callee of Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable
// Address:   0x0096d7a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: CONCAT31, FUN_0044aeb0, FUN_0096d6d0, FUN_0096d7a0.
//  - Return sites: 2.

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

void __fastcall Named_CalleeOf_Named_CalleeOf_Mission_Uses_Client_GetMissionCom_0096d7a0(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ad99e;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_00aa0824;

  local_4 = 2;

  puVar3 = param_1;

  FUN_0096d6d0();

  local_4 = CONCAT31(local_4._1_3_,1);

  FUN_0044aeb0();

  if ((void *)param_1[0x1b] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x1b]);

  }

  param_1[0x1b] = 0;

  param_1[0x1c] = 0;

  param_1[0x1d] = 0;

  local_4 = 0xffffffff;

  piVar2 = (int *)param_1[0x19];

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))(puVar3);

    }

  }

  ExceptionList = local_c;

  return;

}
