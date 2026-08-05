// =============================================================================
// FUN_00625b00
// -----------------------------------------------------------------------------
// Stable ID: aa_00625b00
// Address:   0x00625b00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00625b00 @ 0x00625b00
// Stable ID: aa_00625b00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×6, return×5.
//  - Notable callees: FUN_00627ec0×2, CVOGHBBase_GetRemainingSeconds, FUN_00625b00.
//  - Return sites: 5.

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

uint32_t /* width from decompiler */ __thiscall FUN_00625b00(int param_1,uint32_t /* width from decompiler */ param_2,int param_3,CVOGHBBase *param_4)



{

  int iVar1;

  int iVar2;

  float fVar3;

  

  if ((param_4 == (CVOGHBBase *)0x0) || (*(int *)(param_3 + 0x5fc) != param_4[0x27].nPeriodMs)) {

    return 0;

  }

  iVar1 = FUN_00627ec0();

  iVar2 = FUN_00627ec0();

  if (iVar1 < iVar2) {

    return 2;

  }

  if (iVar2 == iVar1) {

    fVar3 = CVOGHBBase_GetRemainingSeconds(param_4);

    iVar1 = *(int *)(param_3 + 0x18);

    if (iVar1 == 0) {

      iVar1 = 1;

    }

    if (fVar3 < (float)(*(int *)(param_3 + 0x1c) * iVar1) * g_flMsToSeconds_Inferred) {

      return 2;

    }

    if (((*(ushort *)(param_1 + 0x6d0) != 0) && (*(float *)(param_3 + 0x164) != g_flZero)) &&

       ((float)*(ushort *)(param_1 + 0x6d0) < *(float *)(param_3 + 0x164))) {

      return 2;

    }

  }

  return 1;

}
