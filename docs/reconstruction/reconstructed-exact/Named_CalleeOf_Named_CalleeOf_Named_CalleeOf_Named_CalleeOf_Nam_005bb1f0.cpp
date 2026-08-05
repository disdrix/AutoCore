// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005bb1f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005bb1f0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli
// Address:   0x005bb1f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_005bb1f0, FUN_005c2030, FUN_005c2de0, FUN_005c36f0, FUN_0076e240, FUN_0099b8b0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005bb1f0(int param_1,float *param_2,uint32_t /* width from decompiler */ param_3)



{

  float *pfVar1;

  float *pfVar2;

  float fVar3;

  char cVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  uint8_t local_28 [12];

  float local_1c;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  local_1c = *(float *)(param_1 + 0x838);

  pfVar1 = (float *)(param_1 + 0x838);

  local_18 = *(float *)(param_1 + 0x83c);

  local_14 = *(float *)(param_1 + 0x840);

  if ((*(byte *)(*(int *)(param_1 + 0x10) + 0x1e4) & 8) != 0) {

    FUN_005c36f0(pfVar1,param_1 + 0x880,*(int *)(param_1 + 0x10),param_1 + 0x9b4,param_3,

                 param_1 + 0x88c,param_1 + 0x8a4,param_1 + 0x898,*param_2);

  }

  if ((*(byte *)(*(int *)(param_1 + 0x10) + 0x1e4) & 0x10) != 0) {

    FUN_005c2de0(pfVar1,*(int *)(param_1 + 0x10),param_1 + 0x990,param_3,param_1 + 0x88c,

                 param_1 + 0x8a4,param_1 + 0x898,*param_2);

  }

  fVar5 = g_flOne;

  if ((*(byte *)(*(int *)(param_1 + 0x10) + 0x1e4) & 0x40) != 0) {

    pfVar2 = (float *)(param_1 + 0x844);

    FUN_0076e240(local_28,pfVar2,(float *)(param_1 + 0x850));

    FUN_0099b8b0(pfVar2,local_28);

    cVar4 = FUN_005c2030(*(uint32_t /* width from decompiler */ *)(param_1 + 4),pfVar1,&local_10,

                         *(uint32_t /* width from decompiler */ *)(param_1 + 0x10),param_1 + 0x9f0,param_3,param_1 + 0x88c,

                         param_1 + 0x8a4,param_1 + 0x898,*param_2);

    fVar3 = g_flLevelUpUiBase_Inferred;

    fVar5 = g_flOne;

    if ((cVar4 != '\0') && ((*(byte *)(param_1 + 0x989) & 8) == 0)) {

      *(uint8_t *)(param_1 + 0x7f9) = 1;

      return;

    }

    fVar6 = (local_8 * local_c - local_4 * local_10) * g_flLevelUpUiBase_Inferred;

    fVar7 = g_flOne - (local_10 * local_10 + local_c * local_c) * g_flLevelUpUiBase_Inferred;

    *pfVar2 = (local_8 * local_10 + local_4 * local_c) * g_flLevelUpUiBase_Inferred;

    *(float *)(param_1 + 0x848) = fVar6;

    *(float *)(param_1 + 0x850) = fVar5 - (local_8 * local_8 + local_c * local_c) * fVar3;

    *(float *)(param_1 + 0x84c) = fVar7;

    *(float *)(param_1 + 0x854) = (local_4 * local_8 + local_c * local_10) * fVar3;

    *(float *)(param_1 + 0x858) = (local_8 * local_10 - local_4 * local_c) * fVar3;

  }

  if ((*(char *)(param_1 + 0x7fd) != '\0') && (*(char *)(param_1 + 0x7fe) == '\0')) {

    fVar3 = *param_2;

    *pfVar1 = *pfVar1 + *(float *)(param_1 + 0x8b0) * fVar3;

    *(float *)(param_1 + 0x83c) = *(float *)(param_1 + 0x83c) + *(float *)(param_1 + 0x8b4) * fVar3;

    *(float *)(param_1 + 0x840) = *(float *)(param_1 + 0x840) + *(float *)(param_1 + 0x8b8) * fVar3;

  }

  fVar5 = fVar5 / *param_2;

  *(float *)(param_1 + 0x85c) = (*pfVar1 - local_1c) * fVar5;

  *(float *)(param_1 + 0x860) = (*(float *)(param_1 + 0x83c) - local_18) * fVar5;

  *(float *)(param_1 + 0x864) = (*(float *)(param_1 + 0x840) - local_14) * fVar5;

  return;

}
