// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCreature_Setup_00583f10
// -----------------------------------------------------------------------------
// Stable ID: aa_00583f10
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGCreature_SetupGraphics
// Address:   0x00583f10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGCreature_SetupGraphics: creature/setup helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, return×1.
//  - Notable callees: FUN_004b7030×2, FUN_00583f10.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGCreature_SetupGraphics
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

int __thiscall

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCreature_Setup_00583f10(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5

            )



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4) + param_1;

  iVar2 = *(int *)(iVar1 + 0x128);

  if (iVar2 != *(int *)(iVar1 + 300)) {

    do {

      FUN_004b7030(param_2,param_3,param_4,param_5);

      iVar2 = iVar2 + 4;

    } while (iVar2 != *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 300 + param_1));

  }

  iVar2 = *(int *)(*(int *)(param_1 + 4) + 4);

  iVar3 = *(int *)(iVar2 + 0x13c + param_1);

  iVar1 = iVar2 + param_1;

  if (iVar3 != *(int *)(iVar2 + 0x140 + param_1)) {

    do {

      iVar1 = FUN_004b7030(param_2,param_3,param_4,param_5);

      iVar3 = iVar3 + 4;

    } while (iVar3 != *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x140 + param_1));

  }

  return iVar1;

}
