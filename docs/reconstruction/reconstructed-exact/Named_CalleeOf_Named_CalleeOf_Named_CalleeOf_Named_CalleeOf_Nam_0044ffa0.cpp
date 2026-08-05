// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0044ffa0
// -----------------------------------------------------------------------------
// Stable ID: aa_0044ffa0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_anmAnimEvent
// Address:   0x0044ffa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_anmAnimEvent: event/reaction helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_0044fdd0, FUN_0044fe70, FUN_0044ffa0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_anmAnimEvent
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

int Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0044ffa0(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint uVar4;

  uint uVar5;

  

  FUN_0044fdd0();

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = *(uint32_t /* width from decompiler */ *)(param_2 + 4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = *(uint32_t /* width from decompiler */ *)(param_2 + 8);

  if (*(int *)(param_2 + 0x10) == 0) {

    uVar5 = 0;

  }

  else {

    uVar5 = *(int *)(param_2 + 0x14) - *(int *)(param_2 + 0x10) >> 2;

  }

  FUN_0044fe70(0);

  uVar4 = 0;

  if (uVar5 != 0) {

    do {

      iVar2 = *(int *)(param_1 + 0x10);

      iVar1 = uVar4 * 4;

      uVar3 = (**(code **)(**(int **)(*(int *)(param_2 + 0x10) + iVar1) + 0xc))();

      uVar4 = uVar4 + 1;

      *(uint32_t /* width from decompiler */ *)(iVar2 + iVar1) = uVar3;

    } while (uVar4 < uVar5);

  }

  return param_1;

}
