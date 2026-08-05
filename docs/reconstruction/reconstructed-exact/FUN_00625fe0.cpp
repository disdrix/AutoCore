// =============================================================================
// FUN_00625fe0
// -----------------------------------------------------------------------------
// Stable ID: aa_00625fe0
// Address:   0x00625fe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00625fe0 @ 0x00625fe0
// Stable ID: aa_00625fe0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, do×1, goto×1, while×1.
//  - Notable callees: CONCAT31, CVOGHBBase_Start, CVOGHBList_Enqueue, FUN_004e2600, FUN_00618180, FUN_00625fe0.
//  - Return sites: 2.

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

FUN_00625fe0(uint32_t /* width from decompiler */ param_1,int param_2,int param_3,int param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  void *pvVar3;

  CVOGHBBase *pAction;

  char local_21;

  float local_20;

  int local_1c;

  uint32_t /* width from decompiler */ local_18;

  int local_14;

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a8acb;

  local_c = ExceptionList;

  local_20 = 0.0;

  local_1c = 0;

  local_18 = 0;

  local_14 = 0;

  local_10 = (int)*(float *)(param_2 + 0x160);

  ExceptionList = &local_c;

  FUN_004e2600(&LAB_00625dc0,&local_20,0);

  if ((local_1c != 0) && (local_1c <= local_14)) {

    ExceptionList = local_c;

    return 0;

  }

  local_21 = '\0';

LAB_00626073:

  do {

    puVar1 = (uint32_t /* width from decompiler */ *)(local_21 * 0x10 + param_4);

    if (((*(int *)(local_21 * 0x10 + param_4) == -1) && (puVar1[1] == -1)) &&

       (*(char *)(puVar1 + 2) == '\0')) {

      ExceptionList = local_c;

      return 1;

    }

    iVar2 = CVOGReaction_ResolveObjectTarget

                      (CONCAT31((int3)((uint)puVar1 >> 8),*(uint8_t *)(puVar1 + 2)),*puVar1,

                       puVar1[1]);

    if (iVar2 != 0) {

      pvVar3 = operator_new(0x6d0);

      local_4 = 0;

      if (pvVar3 == (void *)0x0) {

        pAction = (CVOGHBBase *)0x0;

      }

      else {

        pAction = (CVOGHBBase *)

                  FUN_00618180(param_1,param_2,param_3,iVar2,param_5,param_6,0,local_20 + g_flOne);

      }

      local_4 = 0xffffffff;

      if (pAction->pOwnerObject != (void *)0x0) {

        CVOGHBList_Enqueue(*(void **)(param_3 + 0xe4ec),pAction);

        CVOGHBBase_Start(pAction);

        local_21 = local_21 + '\x01';

        goto LAB_00626073;

      }

      (**(code **)pAction->pVTable)(1);

    }

    local_21 = local_21 + '\x01';

  } while( true );

}
