// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SERVER_GOT_G_00628f10
// -----------------------------------------------------------------------------
// Stable ID: aa_00628f10
// Callee of Named_CalleeOf_Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x (+1 other named callers)
// Address:   0x00628f10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×3, do×2, while×2, goto×1, return×1.
//  - Notable callees: FUN_00628f10.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x (+1 other named callers)
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SERVER_GOT_G_00628f10(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  

  iVar3 = 0;

  if (0 < *(int *)(param_1 + 0x50)) {

    piVar4 = *(int **)(param_1 + 0x4c);

    do {

      if (*piVar4 == param_2) goto LAB_00628f33;

      iVar3 = iVar3 + 1;

      piVar4 = piVar4 + 1;

    } while (iVar3 < *(int *)(param_1 + 0x50));

  }

  iVar3 = -1;

LAB_00628f33:

  *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + -1;

  if (iVar3 < *(int *)(param_1 + 0x50)) {

    do {

      iVar2 = iVar3 * 4;

      iVar1 = iVar3 * 4;

      iVar3 = iVar3 + 1;

      *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x4c) + iVar1) =

           *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x4c) + 4 + iVar2);

    } while (iVar3 < *(int *)(param_1 + 0x50));

  }

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x10) = 0;

  *(uint8_t *)(param_1 + 0x28) = 1;

  return;

}
