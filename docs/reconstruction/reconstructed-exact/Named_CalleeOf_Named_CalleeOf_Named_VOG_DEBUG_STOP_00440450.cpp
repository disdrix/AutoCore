// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_00440450
// -----------------------------------------------------------------------------
// Stable ID: aa_00440450
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x00440450  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×9, goto×3, return×2.
//  - Notable callees: CONCAT31, FUN_00440450, FUN_00440770, FUN_00440920, FUN_00440d60, FUN_00441610.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

int __thiscall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_00440450(uint *param_1,int param_2)



{

  uint uVar1;

  uint uVar2;

  int iVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ local_5c;

  uint32_t /* width from decompiler */ local_58;

  int *local_54;

  uint8_t local_50;

  uint8_t local_4f;

  uint8_t local_4e;

  void *local_48;

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ local_40;

  uint8_t local_3c [48];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009be95a;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  iVar3 = FUN_00441610();

  if (iVar3 != *(int *)(param_2 + 4)) {

    uVar1 = *param_1;

    uVar2 = *(uint *)(iVar3 + 0xc);

    if (*(uint *)(uVar2 + 8) <= *(uint *)(uVar1 + 8)) {

      if (*(uint *)(uVar1 + 8) != *(uint *)(uVar2 + 8)) goto LAB_00440547;

      if (uVar2 <= uVar1) {

        if (uVar1 != uVar2) goto LAB_00440547;

        if ((*(uint *)(iVar3 + 0x14) <= param_1[2]) &&

           ((param_1[2] != *(uint *)(iVar3 + 0x14) || (*(int *)(iVar3 + 0x18) <= (int)param_1[3]))))

        goto LAB_00440547;

      }

    }

  }

  local_5c = 0;

  local_58 = 0;

  local_54 = (int *)0x0;

  local_50 = 0;

  local_4f = 0;

  local_4e = 0;

  local_48 = (void *)0x0;

  local_44 = 0;

  local_40 = 0;

  local_4 = 1;

  FUN_00440d60(local_3c,&local_5c);

  local_4._0_1_ = 2;

  piVar4 = (int *)FUN_00440920(param_2,iVar3);

  iVar3 = *piVar4;

  local_4 = CONCAT31(local_4._1_3_,1);

  FUN_00440770(local_3c);

  local_4 = 0xffffffff;

  if (local_48 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_48);

  }

  if (local_54 != (int *)0x0) {

    piVar4 = local_54 + 1;

    *piVar4 = *piVar4 + -1;

    if (*piVar4 == 0) {

      (**(code **)(*local_54 + 8))();

    }

  }

LAB_00440547:

  ExceptionList = local_c;

  return iVar3 + 0x1c;

}
