// =============================================================================
// FUN_0061e2a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0061e2a0
// Address:   0x0061e2a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0061e2a0 @ 0x0061e2a0
// Stable ID: aa_0061e2a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, return×1, goto×1, while×1.
//  - Notable callees: CONCAT22, CONCAT31, CVOGHBBase_Start, CVOGHBList_Enqueue, FUN_00589b80, FUN_0058ab60, FUN_00618180, FUN_0061e2a0.
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

FUN_0061e2a0(uint32_t /* width from decompiler */ param_1,int param_2,int param_3,int param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6)



{

  char cVar1;

  void *pvVar2;

  int iVar3;

  CVOGHBBase *pAction;

  int *piVar4;

  char local_11;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a883b;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  pvVar2 = (void *)FUN_0058ab60(param_6);

  local_11 = '\0';

LAB_0061e2e0:

  do {

    piVar4 = (int *)(param_4 + local_11 * 0x10);

    if (((*piVar4 == -1) && (piVar4[1] == -1)) && ((char)piVar4[2] == '\0')) {

      if (pvVar2 != (void *)0x0) {

        operator_delete__(pvVar2);

      }

      ExceptionList = local_c;

      return 1;

    }

    cVar1 = FUN_00589b80(*(uint32_t /* width from decompiler */ *)(param_2 + 0xe4),

                         CONCAT22(local_11 >> 7,*(uint16_t *)((int)pvVar2 + local_11 * 2)));

    if (cVar1 == '\0') {

      iVar3 = CVOGReaction_ResolveObjectTarget

                        (CONCAT31((int3)((uint)piVar4[1] >> 8),(char)piVar4[2]),*piVar4,piVar4[1]);

      if (iVar3 != 0) {

        pAction = operator_new(0x6e0);

        local_4 = 0;

        if (pAction == (CVOGHBBase *)0x0) {

          pAction = (CVOGHBBase *)0x0;

        }

        else {

          FUN_00618180(param_1,param_2,param_3,iVar3,param_5,param_6,0,0x3f800000);

          pAction->pVTable = &PTR_FUN_009d135c;

          pAction[0x2b].pOwnerObject = (void *)0x0;

        }

        local_4 = 0xffffffff;

        if (pAction->pOwnerObject != (void *)0x0) {

          CVOGHBList_Enqueue(*(void **)(param_3 + 0xe4ec),pAction);

          CVOGHBBase_Start(pAction);

          local_11 = local_11 + '\x01';

          goto LAB_0061e2e0;

        }

        (**(code **)pAction->pVTable)(1);

      }

    }

    local_11 = local_11 + '\x01';

  } while( true );

}
