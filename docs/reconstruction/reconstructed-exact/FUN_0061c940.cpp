// =============================================================================
// FUN_0061c940
// -----------------------------------------------------------------------------
// Stable ID: aa_0061c940
// Address:   0x0061c940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0061c940 @ 0x0061c940
// Stable ID: aa_0061c940
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: if×8, do×1, while×1, return×1.
//  - Notable callees: FUN_00574760×3, CVOGHBBase_Start×2, CVOGHBList_Enqueue×2, FUN_00650f50×2, FUN_005787a0, FUN_0061c940, __RTDynamicCast.
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

uint32_t /* width from decompiler */ __thiscall FUN_0061c940(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  int iVar2;

  void *pvVar3;

  CVOGHBBase *pCVar4;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a87bb;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  iVar1 = __RTDynamicCast(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),0,

                          &CVOGClonedObjectBase::RTTI_Type_Descriptor,

                          &CVOGCharacter::RTTI_Type_Descriptor,0);

  if (*(int *)(iVar1 + 0xcb0) == 0) {

    if (*(float *)(param_1 + 0x104) != g_flZero) {

      pvVar3 = operator_new(0x6d0);

      local_4 = 1;

      if (pvVar3 == (void *)0x0) {

        pCVar4 = (CVOGHBBase *)0x0;

      }

      else {

        pCVar4 = (CVOGHBBase *)

                 FUN_00650f50(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),param_1 + 0x24,

                              *(uint32_t /* width from decompiler */ *)(param_1 + 0x688),*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),

                              param_1 + 0x690,*(uint32_t /* width from decompiler */ *)(param_1 + 0x6a8));

      }

      local_4 = 0xffffffff;

      if (pCVar4->pOwnerObject == (void *)0x0) {

        (**(code **)pCVar4->pVTable)(1);

      }

      else {

        CVOGHBList_Enqueue(*(void **)(*(int *)(param_1 + 0x688) + 0xe4ec),pCVar4);

        CVOGHBBase_Start(pCVar4);

      }

    }

  }

  else {

    iVar1 = 0;

    do {

      iVar2 = FUN_00574760(iVar1);

      if (iVar2 != 0) {

        FUN_00574760(iVar1);

        pvVar3 = operator_new(0x6d0);

        local_4 = 0;

        if (pvVar3 == (void *)0x0) {

          pCVar4 = (CVOGHBBase *)0x0;

        }

        else {

          iVar2 = FUN_00574760(iVar1);

          if (iVar2 != 0) {

            iVar2 = *(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2;

          }

          pCVar4 = (CVOGHBBase *)

                   FUN_00650f50(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),param_1 + 0x24,

                                *(uint32_t /* width from decompiler */ *)(param_1 + 0x688),iVar2,param_1 + 0x690,

                                *(uint32_t /* width from decompiler */ *)(param_1 + 0x6a8));

        }

        local_4 = 0xffffffff;

        if (pCVar4->pOwnerObject == (void *)0x0) {

          (**(code **)pCVar4->pVTable)(1);

        }

        else {

          CVOGHBList_Enqueue(*(void **)(*(int *)(param_1 + 0x688) + 0xe4ec),pCVar4);

          CVOGHBBase_Start(pCVar4);

        }

      }

      iVar1 = iVar1 + 1;

    } while (iVar1 < 4);

  }

  FUN_005787a0(param_2);

  ExceptionList = local_c;

  return param_2;

}
