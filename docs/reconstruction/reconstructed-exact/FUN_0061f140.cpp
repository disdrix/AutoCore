// =============================================================================
// FUN_0061f140
// -----------------------------------------------------------------------------
// Stable ID: aa_0061f140
// Address:   0x0061f140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0061f140 @ 0x0061f140
// Stable ID: aa_0061f140
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×7, return×1.
//  - Notable callees: FUN_004d0e90×3, CVOGHBBase_Start, CVOGHBList_Enqueue, CVOGReaction_ResolveObjectTarget, FUN_00618180, FUN_0061f140.
//  - Return sites: 1.

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

uint32_t /* width from decompiler */

FUN_0061f140(int *param_1,int param_2,int param_3,uint32_t /* width from decompiler */ *param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6)



{

  int iVar1;

  void *pvVar2;

  CVOGHBBase *pAction;

  void *local_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009a885b;

  local_1c = ExceptionList;

  ExceptionList = &local_1c;

  iVar1 = CVOGReaction_ResolveObjectTarget(*(uint8_t *)(param_4 + 2),*param_4,param_4[1]);

  if (iVar1 != 0) {

    pvVar2 = operator_new(0x6d0);

    local_14 = 0;

    if (pvVar2 == (void *)0x0) {

      pAction = (CVOGHBBase *)0x0;

    }

    else {

      pAction = (CVOGHBBase *)

                FUN_00618180(param_1,param_2,param_3,iVar1,param_5,param_6,0,0x3f800000);

    }

    local_14 = 0xffffffff;

    if (pAction->pOwnerObject == (void *)0x0) {

      (**(code **)pAction->pVTable)(1);

    }

    else {

      CVOGHBList_Enqueue(*(void **)(param_3 + 0xe4ec),pAction);

      CVOGHBBase_Start(pAction);

      if (*(char *)(param_3 + 0x7e) != '\0') {

        if (*(int *)(param_1[0x2a] + 0x38) != 0x14) {

          (**(code **)(*param_1 + 600))(DAT_009e2dd8,DAT_009e2ddc,DAT_009e2de0,DAT_009e2de4);

        }

        if ((int)*(float *)(param_2 + 0x160) == 1) {

          param_1[0x33] = 0;

          FUN_004d0e90(param_1);

        }

        else if ((int)*(float *)(param_2 + 0x160) == 2) {

          param_1[0x33] = 1;

          FUN_004d0e90(param_1);

        }

        else {

          param_1[0x33] = 2;

          FUN_004d0e90(param_1);

        }

      }

    }

  }

  ExceptionList = local_1c;

  return 1;

}
