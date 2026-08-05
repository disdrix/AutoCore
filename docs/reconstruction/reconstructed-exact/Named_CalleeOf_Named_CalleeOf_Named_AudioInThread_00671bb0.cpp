// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_AudioInThread_00671bb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00671bb0
// Callee of Named_CalleeOf_Named_AudioInThread
// Address:   0x00671bb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_AudioInThread: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: for×2, if×1, return×1.
//  - Notable callees: FUN_00671bb0, FUN_006802d0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_AudioInThread
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_AudioInThread_00671bb0(uint32_t /* width from decompiler */ *param_1,uint param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint uVar3;

  

  puVar1 = operator_new(8);

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *puVar1 = 0;

    puVar1[1] = 0;

  }

  puVar2 = operator_new__(param_2);

  puVar1[1] = puVar2;

  uVar3 = param_2 >> 2;

  *(char *)puVar1 = (char)param_2;

  for (; uVar3 != 0; uVar3 = uVar3 - 1) {

    *puVar2 = *param_1;

    param_1 = param_1 + 1;

    puVar2 = puVar2 + 1;

  }

  for (param_2 = param_2 & 3; param_2 != 0; param_2 = param_2 - 1) {

    *(uint8_t *)puVar2 = *(uint8_t *)param_1;

    param_1 = (uint32_t /* width from decompiler */ *)((int)param_1 + 1);

    puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar2 + 1);

  }

  FUN_006802d0(4,puVar1);

  return 0;

}
