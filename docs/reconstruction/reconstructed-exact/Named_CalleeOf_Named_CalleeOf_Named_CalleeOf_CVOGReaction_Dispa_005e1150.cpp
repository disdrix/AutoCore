// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispa_005e1150
// -----------------------------------------------------------------------------
// Stable ID: aa_005e1150
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch
// Address:   0x005e1150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×8, return×3, do×2, while×2.
//  - Notable callees: CVOGReaction_RandomUnitScalar, FUN_004ce940, FUN_005097b0, FUN_005e0cd0, FUN_005e1150, FUN_007a41f0, memmove.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch
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

uint32_t /* width from decompiler */

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispa_005e1150(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,int param_5

            ,char param_6)



{

  bool bVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  int *_Dst;

  int *piVar5;

  uint8_t local_1c [4];

  int *local_18;

  int *local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a748a;

  local_c = ExceptionList;

  local_18 = (int *)0x0;

  local_14 = (int *)0x0;

  local_10 = 0;

  local_4 = 0;

  ExceptionList = &local_c;

  FUN_005e0cd0(param_1,param_2,param_3,param_4,local_1c,0xffffffff);

  if (local_18 == (int *)0x0) {

    ExceptionList = local_c;

    return 0xffffffff;

  }

  piVar5 = local_18;

  if ((int)local_14 - (int)local_18 >> 2 != 0) {

    piVar4 = local_14;

    _Dst = local_18;

    if (local_18 != local_14) {

      do {

        bVar1 = false;

        if (param_5 != 0) {

          piVar3 = *(int **)(param_5 + 4);

          if (piVar3 != *(int **)(param_5 + 8)) {

            bVar1 = false;

            do {

              if (*_Dst == *piVar3) {

                bVar1 = true;

              }

              piVar3 = piVar3 + 1;

              piVar5 = local_18;

            } while (piVar3 != *(int **)(param_5 + 8));

          }

        }

        if ((((param_6 != '\0') && (iVar2 = FUN_004ce940(), iVar2 != 0)) &&

            ((piVar3 = (int *)FUN_005097b0(*_Dst), piVar3 == (int *)0x0 || (*piVar3 == -1)))) ||

           (bVar1)) {

          memmove(_Dst,_Dst + 1,((int)piVar4 - (int)(_Dst + 1) >> 2) * 4);

          piVar4 = piVar4 + -1;

          local_14 = piVar4;

        }

        else {

          _Dst = _Dst + 1;

        }

      } while (_Dst != piVar4);

    }

    if ((int)piVar4 - (int)piVar5 >> 2 != 0) {

      CVOGReaction_RandomUnitScalar();

      FUN_007a41f0();

                    /* WARNING: Subroutine does not return */

      operator_delete(piVar5);

    }

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(piVar5);

}
