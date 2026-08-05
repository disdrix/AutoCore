// =============================================================================
// FUN_00620190
// -----------------------------------------------------------------------------
// Stable ID: aa_00620190
// Address:   0x00620190  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00620190 @ 0x00620190
// Stable ID: aa_00620190
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×5, for×1, do×1, while×1, return×1.
//  - Notable callees: CONCAT31, CVOGHBBase_Start, CVOGHBList_Enqueue, FUN_00618180, FUN_00620190.
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

FUN_00620190(uint32_t /* width from decompiler */ param_1,int param_2,int param_3,int *param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6)



{

  int *piVar1;

  int iVar2;

  void *pvVar3;

  CVOGHBBase *pAction;

  int iVar4;

  char local_15;

  float local_14;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a88cb;

  local_c = ExceptionList;

  iVar4 = 0;

  for (piVar1 = param_4; ((*piVar1 != -1 || (piVar1[1] != -1)) || ((char)piVar1[2] != '\0'));

      piVar1 = piVar1 + 4) {

    iVar4 = iVar4 + 1;

  }

  local_14 = (float)iVar4;

  if (*(float *)(param_2 + 0x160) != g_flZero) {

    local_14 = g_flOne / local_14;

  }

  local_15 = '\0';

  if (0 < iVar4) {

    iVar2 = 0;

    ExceptionList = &local_c;

    do {

      piVar1 = param_4 + iVar2 * 4;

      iVar2 = CVOGReaction_ResolveObjectTarget

                        (CONCAT31((int3)((uint)piVar1 >> 8),(char)piVar1[2]),*piVar1,piVar1[1]);

      if (iVar2 != 0) {

        pvVar3 = operator_new(0x6d0);

        local_4 = 0;

        if (pvVar3 == (void *)0x0) {

          pAction = (CVOGHBBase *)0x0;

        }

        else {

          pAction = (CVOGHBBase *)

                    FUN_00618180(param_1,param_2,param_3,iVar2,param_5,param_6,0,local_14);

        }

        local_4 = 0xffffffff;

        if (pAction->pOwnerObject == (void *)0x0) {

          (**(code **)pAction->pVTable)(1);

        }

        else {

          CVOGHBList_Enqueue(*(void **)(param_3 + 0xe4ec),pAction);

          CVOGHBBase_Start(pAction);

        }

      }

      local_15 = local_15 + '\x01';

      iVar2 = (int)local_15;

    } while (iVar2 < iVar4);

  }

  ExceptionList = local_c;

  return 1;

}
