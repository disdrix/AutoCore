// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0056add0
// -----------------------------------------------------------------------------
// Stable ID: aa_0056add0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli
// Address:   0x0056add0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_0056add0.
//  - Return sites: 1.

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

uint8_t __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0056add0(int param_1)



{

  short sVar1;

  uint8_t uVar2;

  short sVar3;

  short sVar4;

  

  sVar3 = 0;

  if (0 < *(short *)(param_1 + 0x130)) {

    sVar3 = *(short *)(param_1 + 0x130);

  }

  sVar1 = *(short *)(param_1 + 0x132);

  sVar4 = sVar3;

  if (sVar3 < sVar1) {

    sVar4 = sVar1;

  }

  uVar2 = sVar3 < sVar1;

  if (sVar4 < *(short *)(param_1 + 0x134)) {

    uVar2 = 2;

    sVar4 = *(short *)(param_1 + 0x134);

  }

  if (sVar4 < *(short *)(param_1 + 0x136)) {

    uVar2 = 3;

    sVar4 = *(short *)(param_1 + 0x136);

  }

  if (sVar4 < *(short *)(param_1 + 0x138)) {

    uVar2 = 4;

    sVar4 = *(short *)(param_1 + 0x138);

  }

  if (sVar4 < *(short *)(param_1 + 0x13a)) {

    uVar2 = 5;

  }

  return uVar2;

}
