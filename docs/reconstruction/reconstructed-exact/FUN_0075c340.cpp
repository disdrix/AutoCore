// =============================================================================
// FUN_0075c340
// -----------------------------------------------------------------------------
// Stable ID: aa_0075c340
// Address:   0x0075c340  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE: Scaffold retained for path stability. Canonical refine 2026-07-29:
//   GfxView_UnprojectScreenToWorldRay_Inferred.cpp  (dual A/B + three-rep)
// Stable ID: aa_0075c340 — CF below still ≡ raw; prefer named clean for docs.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_009729d0×2, FUN_00972e50×2, FUN_0075b7f0, FUN_0075c340, FUN_0076f5f0, FUN_00972fa0.
//  - Return sites: 3.

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

void __thiscall FUN_0075c340(int param_1,int *param_2,uint32_t /* width from decompiler */ *param_3,float *param_4)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  float fVar3;

  float fVar4;

  float local_18;

  float local_14;

  float local_10;

  

  fVar3 = ((float)*param_2 / (float)*(int *)(param_1 + 0xdc)) * g_flLevelUpUiBase_Inferred - g_flOne

  ;

  fVar4 = ((float)param_2[1] / (float)*(int *)(param_1 + 0xe0)) * g_flLevelUpUiBase_Inferred -

          g_flOne;

  FUN_0075b7f0();

  local_18 = *(float *)(param_1 + 0xf8) * fVar3;

  local_14 = *(float *)(param_1 + 0xfc) * (0.0 - fVar4);

  local_10 = *(float *)(param_1 + 0xf0);

  puVar1 = (uint32_t /* width from decompiler */ *)FUN_00972fa0(&local_18);

  *param_3 = *puVar1;

  param_3[1] = puVar1[1];

  param_3[2] = puVar1[2];

  if (*(int *)(param_1 + 0xec) == 0) {

    *param_4 = local_18;

    param_4[1] = local_14;

    param_4[2] = local_10;

    FUN_0076f5f0(param_4,param_4);

    if ((*(byte *)(*(int *)(param_1 + 8) + 0xbc) & 1) != 0) {

      FUN_00972e50();

      FUN_009729d0(param_4);

      return;

    }

    FUN_009729d0(param_4);

  }

  else if (*(int *)(param_1 + 0xec) == 1) {

    iVar2 = *(int *)(param_1 + 8);

    if ((*(byte *)(iVar2 + 0xbc) & 1) != 0) {

      iVar2 = FUN_00972e50();

    }

    *param_4 = *(float *)(iVar2 + 0x20);

    param_4[1] = *(float *)(iVar2 + 0x24);

    param_4[2] = *(float *)(iVar2 + 0x28);

    return;

  }

  return;

}
