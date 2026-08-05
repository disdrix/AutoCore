// =============================================================================
// FUN_00618180
// -----------------------------------------------------------------------------
// Stable ID: aa_00618180
// Address:   0x00618180  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00618180 @ 0x00618180
// Stable ID: aa_00618180
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: CVOGHBBase_GetRemainingSeconds, FUN_005788d0, FUN_00618180.
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

CVOGHBBase * __thiscall

FUN_00618180(CVOGHBBase *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            int param_5,uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7,uint8_t param_8,int param_9)



{

  int iVar1;

  float fVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a8708;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_005788d0(param_2,param_3,param_4,param_5,param_6,param_7);

  iVar1 = param_1[1].nUnusedOrFlags;

  local_4 = 0;

  param_1->pVTable = &PTR_FUN_009e1f2c;

  *(uint8_t *)&param_1[0x2b].nPeriodMs = param_8;

  param_1[0x2b].nPeriodSentinel = param_9;

  param_1[0x2b].nPeriodCounter = 0;

  if (((((char)iVar1 != '\0') && (param_5 != 0)) && (*(int *)(param_5 + 0xa4) != 0)) &&

     (*(char *)(*(int *)(param_5 + 0xa4) + 0xf6) != '\0')) {

    fVar2 = CVOGHBBase_GetRemainingSeconds(param_1);

    if (DAT_00a0f694 < fVar2) {

      if (1 < param_1->nPeriodSentinel) {

        CVOGHBBase_SetPeriodAndCounter

                  (param_1,(int)(30000 / (ulonglong)(uint)param_1->nPeriodMs),true);

        ExceptionList = local_c;

        return param_1;

      }

      param_1->nPeriodMs = 30000;

    }

  }

  ExceptionList = local_c;

  return param_1;

}
