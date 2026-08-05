// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004cc220
// -----------------------------------------------------------------------------
// Stable ID: aa_004cc220
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x004cc220  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×12, return×8, goto×1.
//  - Notable callees: FUN_004cbb60×7, FUN_00401480×5, FUN_004cb270, FUN_004cb4f0, FUN_004cbee0, FUN_004cc220.
//  - Return sites: 8.

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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004cc220(int param_1,uint32_t /* width from decompiler */ *param_2,int *param_3,uint *param_4)



{

  int *piVar1;

  int iVar2;

  char cVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint8_t local_8 [8];

  

  if (*(int *)(param_1 + 8) == 0) {

    FUN_004cbb60(param_2,1,*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_4);

    return param_2;

  }

  piVar1 = *(int **)(param_1 + 4);

  if (param_3 == (int *)*piVar1) {

    if (((int)param_4[1] <= param_3[5]) &&

       (((int)param_4[1] < param_3[5] || (*param_4 < (uint)param_3[4])))) {

      FUN_004cbb60(param_2,1,param_3,param_4);

      return param_2;

    }

  }

  else if (param_3 == piVar1) {

    iVar2 = piVar1[2];

    cVar3 = FUN_00401480(iVar2 + 0x10,param_4);

    if (cVar3 != '\0') {

      FUN_004cbb60(param_2,0,iVar2,param_4);

      return param_2;

    }

  }

  else {

    cVar3 = FUN_00401480(param_4,param_3 + 4);

    if (cVar3 != '\0') {

      FUN_004cb4f0();

      cVar3 = FUN_00401480(param_3 + 4,param_4);

      if (cVar3 != '\0') {

        if (*(char *)(param_3[2] + 0x29) != '\0') {

          FUN_004cbb60(param_2,0,param_3,param_4);

          return param_2;

        }

        FUN_004cbb60(param_2,1,param_3,param_4);

        return param_2;

      }

    }

    cVar3 = FUN_00401480(param_3 + 4,param_4);

    if (cVar3 != '\0') {

      FUN_004cb270();

      if (param_3 != *(int **)(param_1 + 4)) {

        cVar3 = FUN_00401480(param_4,param_3 + 4);

        if (cVar3 == '\0') goto LAB_004cc3a6;

      }

      if (*(char *)(param_3[2] + 0x29) != '\0') {

        FUN_004cbb60(param_2,0,param_3,param_4);

        return param_2;

      }

      FUN_004cbb60(param_2,1,param_3,param_4);

      return param_2;

    }

  }

LAB_004cc3a6:

  puVar4 = (uint32_t /* width from decompiler */ *)FUN_004cbee0(local_8,param_4);

  *param_2 = *puVar4;

  return param_2;

}
