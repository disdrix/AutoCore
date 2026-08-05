// =============================================================================
// FUN_0061fa40
// -----------------------------------------------------------------------------
// Stable ID: aa_0061fa40
// Address:   0x0061fa40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0061fa40 @ 0x0061fa40
// Stable ID: aa_0061fa40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, return×1, goto×1, while×1.
//  - Notable callees: CVOGHBBase_SetPeriodAndCounter, CVOGHBBase_Start, CVOGHBList_Enqueue, FUN_00618180, FUN_0061fa40, Object_ResolveFromTFID.
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

int FUN_0061fa40(uint32_t /* width from decompiler */ param_1,int param_2,int param_3,int param_4,uint32_t /* width from decompiler */ param_5,

                uint32_t /* width from decompiler */ param_6)



{

  float fVar1;

  TFID_16 *pTfid;

  void *pvVar2;

  CVOGHBBase *pAction;

  int nPeriodSentinel;

  char local_12;

  char local_11;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a889b;

  local_c = ExceptionList;

  local_11 = '\0';

  local_12 = '\0';

  ExceptionList = &local_c;

LAB_0061fa70:

  do {

    pTfid = (TFID_16 *)(local_12 * 0x10 + param_4);

    if (((pTfid->dwCoidLo == 0xffffffff) && (pTfid->dwCoidHi == 0xffffffff)) &&

       (pTfid->bGlobal == 0)) {

      ExceptionList = local_c;

      return (int)local_11;

    }

    pvVar2 = Object_ResolveFromTFID(pTfid);

    if (pvVar2 != (void *)0x0) {

      local_11 = local_11 + '\x01';

      pAction = operator_new(0x6e0);

      local_4 = 0;

      if (pAction == (CVOGHBBase *)0x0) {

        pAction = (CVOGHBBase *)0x0;

      }

      else {

        nPeriodSentinel = *(int *)(param_2 + 0x18);

        if (nPeriodSentinel == 0) {

          nPeriodSentinel = 1;

        }

        fVar1 = *(float *)(param_2 + 0x164);

        FUN_00618180(param_1,param_2,param_3,pvVar2,param_5,param_6,0,0x3f800000);

        pAction[0x2b].pOwnerObject = (void *)(int)fVar1;

        pAction->pVTable = &PTR_FUN_009d14bc;

        pAction[0x2b].nUnusedOrFlags = nPeriodSentinel;

        CVOGHBBase_SetPeriodAndCounter(pAction,nPeriodSentinel,true);

      }

      local_4 = 0xffffffff;

      if (pAction->pOwnerObject != (void *)0x0) {

        CVOGHBList_Enqueue(*(void **)(param_3 + 0xe4ec),pAction);

        CVOGHBBase_Start(pAction);

        local_12 = local_12 + '\x01';

        goto LAB_0061fa70;

      }

      (**(code **)pAction->pVTable)(1);

    }

    local_12 = local_12 + '\x01';

  } while( true );

}
