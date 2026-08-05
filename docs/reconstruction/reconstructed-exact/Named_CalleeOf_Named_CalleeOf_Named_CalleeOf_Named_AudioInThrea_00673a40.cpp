// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_AudioInThrea_00673a40
// -----------------------------------------------------------------------------
// Stable ID: aa_00673a40
// Callee of Named_CalleeOf_Named_CalleeOf_Named_AudioInThread
// Address:   0x00673a40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_AudioInThread: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_00673510, FUN_00673a40.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_AudioInThread
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_AudioInThrea_00673a40(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *pvVar2;

  uint uVar3;

  uint uVar4;

  

  if (((*(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x10) & 3U) == 0) &&

     (*(uint *)(param_1 + 8) <= *(int *)(param_1 + 0x10) + 4U >> 2)) {

    FUN_00673510(1);

  }

  uVar4 = *(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x10);

  uVar3 = uVar4 >> 2;

  if (*(uint *)(param_1 + 8) <= uVar3) {

    uVar3 = uVar3 - *(uint *)(param_1 + 8);

  }

  if (*(int *)(*(int *)(param_1 + 4) + uVar3 * 4) == 0) {

    pvVar2 = operator_new(0x10);

    *(void **)(*(int *)(param_1 + 4) + uVar3 * 4) = pvVar2;

  }

  puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + uVar3 * 4) + (uVar4 & 3) * 4);

  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    *puVar1 = *param_2;

  }

  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;

  return;

}
