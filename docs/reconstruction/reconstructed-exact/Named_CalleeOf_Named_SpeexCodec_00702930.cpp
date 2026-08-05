// =============================================================================
// Named_CalleeOf_Named_SpeexCodec_00702930
// -----------------------------------------------------------------------------
// Stable ID: aa_00702930
// Callee of Named_SpeexCodec
// Address:   0x00702930  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_SpeexCodec: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_00702930.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_SpeexCodec
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

void Named_CalleeOf_Named_SpeexCodec_00702930(int *param_1)



{

  int iVar1;

  

  iVar1 = 0;

  if (0 < param_1[6]) {

    do {

      *(uint8_t *)(iVar1 + *param_1) = 0;

      iVar1 = iVar1 + 1;

    } while (iVar1 < param_1[6]);

  }

  param_1[1] = 0;

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[5] = 0;

  return;

}
