// =============================================================================
// Named_CalleeOf_Mission_You_do_not_have_permission_to_do_that_004c25b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004c25b0
// Callee of Mission_You_do_not_have_permission_to_do_that
// Address:   0x004c25b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_You_do_not_have_permission_to_do_that: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×4, return×4, while×1.
//  - Notable callees: FUN_004c22a0×2, FUN_004c25b0, memmove.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Mission_You_do_not_have_permission_to_do_that
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

uint32_t /* width from decompiler */ __thiscall

Named_CalleeOf_Mission_You_do_not_have_permission_to_do_that_004c25b0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,int param_4,int param_5)



{

  int iVar1;

  int iVar2;

  int *_Dst;

  

  iVar1 = FUN_004c22a0(param_2,param_3);

  iVar2 = FUN_004c22a0(param_4,param_5);

  if (((iVar1 != 0) && (iVar2 != 0)) &&

     ((*(int *)(iVar2 + 0x24) < *(int *)(iVar1 + 0x24) || (iVar1 == iVar2)))) {

    _Dst = *(int **)(param_1 + 0x1e4);

    if (_Dst != *(int **)(param_1 + 0x1e8)) {

      while ((*(int *)*_Dst != param_4 || (((int *)*_Dst)[1] != param_5))) {

        _Dst = _Dst + 1;

        if (_Dst == *(int **)(param_1 + 0x1e8)) {

          return 0;

        }

      }

      if ((void *)*_Dst == (void *)0x0) {

        *_Dst = 0;

        memmove(_Dst,_Dst + 1,(*(int *)(param_1 + 0x1e8) - (int)(_Dst + 1) >> 2) * 4);

        *(int *)(param_1 + 0x1e8) = *(int *)(param_1 + 0x1e8) + -4;

        return 1;

      }

                    /* WARNING: Subroutine does not return */

      operator_delete((void *)*_Dst);

    }

  }

  return 0;

}
