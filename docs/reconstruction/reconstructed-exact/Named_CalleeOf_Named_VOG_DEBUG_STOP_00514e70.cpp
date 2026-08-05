// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_00514e70
// -----------------------------------------------------------------------------
// Stable ID: aa_00514e70
// Callee of Named_VOG_DEBUG_STOP (+2 other named callers)
// Address:   0x00514e70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOG_DEBUG_STOP (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: CVOGHBBase_Start, CVOGHBList_Enqueue, FUN_00514e20, FUN_00514e70, FUN_005538a0, FUN_006061e0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP (+2 other named callers)
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

void __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_00514e70(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  void *pvVar2;

  CVOGHBBase *pAction;

  uint8_t auStack_54 [16];

  int iStack_44;

  int iStack_40;

  int iStack_3c;

  int iStack_38;

  byte abStack_34 [4];

  byte abStack_30 [4];

  byte abStack_2c [4];

  byte abStack_28 [8];

  void *pvStack_20;

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009a3550;

  pvStack_1c = ExceptionList;

  ExceptionList = &pvStack_1c;

  iVar1 = (**(code **)(*param_1 + 0x234))(param_2);

  if ((iVar1 != 0) && ((*(byte *)(iVar1 + 0x615) & 1) != 0)) {

    FUN_00514e20(param_2,param_1[0x58],param_1[0x59],param_1[0x5a],param_1[0x5b],0);

    iStack_44 = param_1[0x58];

    iStack_40 = param_1[0x59];

    iStack_3c = param_1[0x5a];

    iStack_38 = param_1[0x5b];

    abStack_34[0] = g_abTfidInvalid_9CDF88[0];

    abStack_34[1] = g_abTfidInvalid_9CDF88[1];

    abStack_34[2] = g_abTfidInvalid_9CDF88[2];

    abStack_34[3] = g_abTfidInvalid_9CDF88[3];

    pAction = (CVOGHBBase *)0x0;

    abStack_30[0] = g_abTfidInvalid_9CDF88[4];

    abStack_30[1] = g_abTfidInvalid_9CDF88[5];

    abStack_30[2] = g_abTfidInvalid_9CDF88[6];

    abStack_30[3] = g_abTfidInvalid_9CDF88[7];

    abStack_2c[0] = g_abTfidInvalid_9CDF88[8];

    abStack_2c[1] = g_abTfidInvalid_9CDF88[9];

    abStack_2c[2] = g_abTfidInvalid_9CDF88[10];

    abStack_2c[3] = g_abTfidInvalid_9CDF88[0xb];

    abStack_28[0] = g_abTfidInvalid_9CDF88[0xc];

    abStack_28[1] = g_abTfidInvalid_9CDF88[0xd];

    abStack_28[2] = g_abTfidInvalid_9CDF88[0xe];

    abStack_28[3] = g_abTfidInvalid_9CDF88[0xf];

    if ((0 < *(short *)(iVar1 + 0x14)) &&

       ((param_1[0x29] != 0 && (*(int *)(param_1[0x29] + 0xe4ec) != 0)))) {

      pvVar2 = operator_new(0x674);

      puStack_18 = (uint8_t *)0x0;

      if (pvVar2 != (void *)0x0) {

        pAction = (CVOGHBBase *)

                  FUN_006061e0((int)*(short *)(iVar1 + 0x14),param_1,iVar1,param_1[0x29],&iStack_44,

                               auStack_54,0,0);

      }

      puStack_18 = (uint8_t *)0xffffffff;

      CVOGHBList_Enqueue(*(void **)(param_1[0x29] + 0xe4ec),pAction);

      CVOGHBBase_Start(pAction);

      ExceptionList = pvStack_20;

      return;

    }

    if (param_1[0x29] != 0) {

      FUN_005538a0(param_1,param_1[0x29],&iStack_44,auStack_54,0);

    }

  }

  ExceptionList = pvStack_20;

  return;

}
