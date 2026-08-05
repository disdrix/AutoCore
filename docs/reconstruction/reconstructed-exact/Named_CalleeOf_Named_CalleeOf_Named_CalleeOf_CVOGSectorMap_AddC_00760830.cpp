// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_AddC_00760830
// -----------------------------------------------------------------------------
// Stable ID: aa_00760830
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_AddCharacter
// Address:   0x00760830  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_AddCharacter: character create/apply helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×5, for×1, return×1.
//  - Notable callees: FUN_0043af10, FUN_00760830.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_AddCharacter
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_AddC_00760830(uint param_1)



{

  int iVar1;

  float fVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int unaff_EBX;

  uint uVar5;

  float fVar6;

  

  uVar3 = param_1;

  uVar5 = 0;

  if (*(int *)(unaff_EBX + 0xc) != 0) {

    uVar5 = (*(int *)(unaff_EBX + 0x10) - *(int *)(unaff_EBX + 0xc)) / 0x28;

  }

  if (param_1 != uVar5) {

    if (*(int *)(unaff_EBX + 0xc) == 0) {

      uVar5 = 0;

    }

    else {

      uVar5 = (*(int *)(unaff_EBX + 0x10) - *(int *)(unaff_EBX + 0xc)) / 0x28;

    }

    FUN_0043af10(param_1);

    fVar2 = g_flLevelUpUiBase_Inferred;

    for (; uVar5 < uVar3; uVar5 = uVar5 + 1) {

      iVar1 = *(int *)(unaff_EBX + 0xc) + uVar5 * 0x28;

      if (uVar5 == 0) {

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x20) = 0;

        fVar6 = *(float *)(unaff_EBX + 0x1c) * fVar2;

      }

      else {

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x20) = *(uint32_t /* width from decompiler */ *)(iVar1 + -4);

        fVar6 = *(float *)(unaff_EBX + 0x1c) * fVar2 + *(float *)(iVar1 + -4);

      }

      *(float *)(iVar1 + 0x24) = fVar6;

    }

    param_1 = uVar3 - 1;

    puVar4 = (uint32_t /* width from decompiler */ *)(unaff_EBX + 0x18);

    if (param_1 <= *(uint *)(unaff_EBX + 0x18)) {

      puVar4 = &param_1;

    }

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x18) = *puVar4;

  }

  return;

}
