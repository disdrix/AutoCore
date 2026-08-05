// =============================================================================
// FUN_006226a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006226a0
// Address:   0x006226a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006226a0 @ 0x006226a0
// Stable ID: aa_006226a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, return×1, goto×1, while×1.
//  - Notable callees: CONCAT31, CVOGHBBase_Start, CVOGHBList_Enqueue, FUN_005788d0, FUN_006226a0.
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

FUN_006226a0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,int param_3,int param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6)



{

  int *piVar1;

  int iVar2;

  CVOGHBBase *pAction;

  char local_d;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a897b;

  local_c = ExceptionList;

  local_d = '\0';

  ExceptionList = &local_c;

LAB_006226d0:

  do {

    piVar1 = (int *)(local_d * 0x10 + param_4);

    if (((*piVar1 == -1) && (piVar1[1] == -1)) && ((char)piVar1[2] == '\0')) {

      ExceptionList = local_c;

      return 1;

    }

    iVar2 = CVOGReaction_ResolveObjectTarget

                      (CONCAT31((int3)((uint)piVar1 >> 8),(char)piVar1[2]),*piVar1,piVar1[1]);

    if (iVar2 != 0) {

      pAction = operator_new(0x6c0);

      local_4 = 0;

      if (pAction == (CVOGHBBase *)0x0) {

        pAction = (CVOGHBBase *)0x0;

      }

      else {

        FUN_005788d0(param_1,param_2,param_3,iVar2,param_5,param_6);

        pAction->pVTable = &PTR_FUN_009d16e4;

      }

      local_4 = 0xffffffff;

      if (pAction->pOwnerObject != (void *)0x0) {

        CVOGHBList_Enqueue(*(void **)(param_3 + 0xe4ec),pAction);

        CVOGHBBase_Start(pAction);

        local_d = local_d + '\x01';

        goto LAB_006226d0;

      }

      (**(code **)pAction->pVTable)(1);

    }

    local_d = local_d + '\x01';

  } while( true );

}
