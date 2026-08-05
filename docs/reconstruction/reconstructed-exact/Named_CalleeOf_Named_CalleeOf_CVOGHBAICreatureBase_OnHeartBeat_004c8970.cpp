// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGHBAICreatureBase_OnHeartBeat_004c8970
// -----------------------------------------------------------------------------
// Stable ID: aa_004c8970
// Callee of Named_CalleeOf_CVOGHBAICreatureBase_OnHeartBeat
// Address:   0x004c8970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGHBAICreatureBase_OnHeartBeat: creature/setup helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×6, return×4.
//  - Notable callees: FUN_004c8970, FUN_004cb4b0, TFID_EqualsObjectId.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGHBAICreatureBase_OnHeartBeat
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_CVOGHBAICreatureBase_OnHeartBeat_004c8970(int param_1,uint param_2,int param_3,char param_4)



{

  int *piVar1;

  int iVar2;

  int local_8;

  int local_4;

  

  local_8 = FUN_004cb4b0(&param_2);

  if (((local_8 == *(int *)(param_1 + 0x158)) || (param_3 < *(int *)(local_8 + 0x14))) ||

     ((param_3 <= *(int *)(local_8 + 0x14) && (param_2 < *(uint *)(local_8 + 0x10))))) {

    local_4 = *(int *)(param_1 + 0x158);

    piVar1 = &local_4;

  }

  else {

    piVar1 = &local_8;

  }

  if (*piVar1 == *(int *)(param_1 + 0x158)) {

    piVar1 = *(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa4 + param_1);

    if (piVar1 != (int *)0x0) {

      if (((piVar1[0x58] == param_2) && (piVar1[0x59] == param_3)) &&

         ((char)piVar1[0x5a] == param_4)) {

        return 1;

      }

      iVar2 = (**(code **)(*piVar1 + 0x214))();

      if (iVar2 != 0) {

        iVar2 = (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa4 + param_1) +

                            0x214))();

        iVar2 = TFID_EqualsObjectId((void *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0x164 + iVar2),

                                    &param_2);

        if ((char)iVar2 != '\0') {

          return 1;

        }

      }

    }

    return 0;

  }

  return *(uint32_t /* width from decompiler */ *)(*piVar1 + 0x20);

}
