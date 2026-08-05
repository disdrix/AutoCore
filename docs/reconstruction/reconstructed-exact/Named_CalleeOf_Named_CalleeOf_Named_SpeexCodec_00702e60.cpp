// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_SpeexCodec_00702e60
// -----------------------------------------------------------------------------
// Stable ID: aa_00702e60
// Callee of Named_CalleeOf_Named_SpeexCodec
// Address:   0x00702e60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_SpeexCodec: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×1, while×1, return×1.
//  - Notable callees: FUN_00702bb0×2, FUN_00702e60.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_SpeexCodec
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

void Named_CalleeOf_Named_CalleeOf_Named_SpeexCodec_00702e60(int param_1)



{

  int iVar1;

  

  if (*(int *)(param_1 + 0xc) < 7) {

    FUN_00702bb0(param_1,0,1);

    iVar1 = *(int *)(param_1 + 0xc);

    while (iVar1 < 7) {

      FUN_00702bb0(param_1,1,1);

      iVar1 = *(int *)(param_1 + 0xc);

    }

  }

  return;

}
