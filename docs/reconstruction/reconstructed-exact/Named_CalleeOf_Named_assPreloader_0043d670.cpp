// =============================================================================
// Named_CalleeOf_Named_assPreloader_0043d670
// -----------------------------------------------------------------------------
// Stable ID: aa_0043d670
// Callee of Named_assPreloader (+2 other named callers)
// Address:   0x0043d670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_assPreloader: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_assPreloader (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0043d420, FUN_0043d670, FUN_0043d990.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_assPreloader (+2 other named callers)
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

void __thiscall Named_CalleeOf_Named_assPreloader_0043d670(int param_1,uint32_t /* width from decompiler */ param_2)



{

  void *pvVar1;

  uint uVar2;

  uint uVar3;

  

  if (((*(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x10) & 3U) == 0) &&

     (*(uint *)(param_1 + 8) <= *(int *)(param_1 + 0x10) + 4U >> 2)) {

    FUN_0043d990(1);

  }

  uVar3 = *(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x10);

  uVar2 = uVar3 >> 2;

  if (*(uint *)(param_1 + 8) <= uVar2) {

    uVar2 = uVar2 - *(uint *)(param_1 + 8);

  }

  if (*(int *)(*(int *)(param_1 + 4) + uVar2 * 4) == 0) {

    pvVar1 = operator_new(0x10);

    *(void **)(*(int *)(param_1 + 4) + uVar2 * 4) = pvVar1;

  }

  FUN_0043d420(*(int *)(*(int *)(param_1 + 4) + uVar2 * 4) + (uVar3 & 3) * 4,param_2);

  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;

  return;

}
