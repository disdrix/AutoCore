// =============================================================================
// Named_CalleeOf_Named_Sending_Challenge_Response_8x_00424d10
// -----------------------------------------------------------------------------
// Stable ID: aa_00424d10
// Callee of Named_Sending_Challenge_Response_8x (+5 other named callers)
// Address:   0x00424d10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Sending_Challenge_Response_8x: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_Sending_Challenge_Response_8x (+5 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×1, while×1, return×1.
//  - Notable callees: FUN_00424d10, free.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Sending_Challenge_Response_8x (+5 other named callers)
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

void __fastcall Named_CalleeOf_Named_Sending_Challenge_Response_8x_00424d10(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  *param_1 = &PTR_LAB_009d7b00;

  if (*(char *)(param_1 + 5) != '\0') {

    free((void *)param_1[3]);

  }

  *param_1 = &PTR_LAB_00a9b1dc;

  puVar2 = (uint32_t /* width from decompiler */ *)param_1[1];

  while (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)puVar2[2];

    *puVar2 = 0;

    puVar2[1] = 0;

    puVar2[2] = 0;

    puVar2 = puVar1;

  }

  return;

}
