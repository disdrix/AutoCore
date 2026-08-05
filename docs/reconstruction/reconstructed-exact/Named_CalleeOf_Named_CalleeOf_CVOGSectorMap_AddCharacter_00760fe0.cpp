// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_AddCharacter_00760fe0
// -----------------------------------------------------------------------------
// Stable ID: aa_00760fe0
// Callee of Named_CalleeOf_CVOGSectorMap_AddCharacter
// Address:   0x00760fe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGSectorMap_AddCharacter: character create/apply helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×8, return×2, while×1, for×1.
//  - Notable callees: FUN_00760830, FUN_00760fe0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGSectorMap_AddCharacter
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

void __thiscall Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_AddCharacter_00760fe0(int param_1,uint param_2,float param_3)



{

  float fVar1;

  float fVar2;

  int iVar3;

  int iVar4;

  uint uVar5;

  int iVar6;

  int iVar7;

  

  iVar6 = *(int *)(param_1 + 0xc);

  if (param_2 == 0xffffffff) {

    if (iVar6 == 0) {

      uVar5 = 0xffffffff;

    }

    else {

      uVar5 = (*(int *)(param_1 + 0x10) - iVar6) / 0x28 - 1;

    }

  }

  else {

    uVar5 = param_2;

    if ((iVar6 == 0) || ((uint)((*(int *)(param_1 + 0x10) - iVar6) / 0x28) <= param_2)) {

      FUN_00760830(param_2 + 1);

    }

  }

  iVar6 = uVar5 * 0x28;

  iVar4 = *(int *)(param_1 + 0xc) + iVar6;

  *(float *)(iVar4 + 0x24) = param_3;

  iVar7 = iVar6;

  param_2 = uVar5;

  while( true ) {

    iVar3 = 0;

    if (*(int *)(param_1 + 0xc) != 0) {

      iVar3 = (*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc)) / 0x28;

    }

    if (iVar3 - 1U <= param_2) break;

    iVar3 = *(int *)(param_1 + 0xc);

    fVar1 = *(float *)(iVar3 + 0x24 + iVar7);

    fVar2 = *(float *)(iVar3 + 0x4c + iVar7);

    *(float *)(iVar3 + iVar7 + 0x48) = fVar1;

    if (fVar1 <= fVar2) break;

    param_2 = param_2 + 1;

    *(float *)(iVar3 + iVar7 + 0x4c) = fVar1;

    iVar7 = iVar7 + 0x28;

  }

  if (param_3 < *(float *)(iVar4 + 0x20)) {

    *(float *)(iVar4 + 0x20) = param_3;

    for (; uVar5 != 0; uVar5 = uVar5 - 1) {

      fVar1 = *(float *)(*(int *)(param_1 + 0xc) + 0x20 + iVar6);

      iVar7 = *(int *)(param_1 + 0xc) + iVar6;

      *(float *)(iVar7 + -4) = fVar1;

      if (*(float *)(iVar7 + -8) <= fVar1) {

        return;

      }

      iVar6 = iVar6 + -0x28;

      *(float *)(iVar7 + -8) = fVar1;

    }

  }

  return;

}
